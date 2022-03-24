#include "hal/common.h"
#include "hal/bcm2837.h"
#include "hal/gpio.h"
#include "hal/mailbox.h"
#include "hal/usart.h"

#define GPIO						((GPIO_TypeDef *) GPIO_BASE)
#define MAILBOX0					((MAILBOX_TypeDef *) MAILBOX0_BASE)
#define USART0						((USART_TypeDef *) USART0_BASE)

// Loop <delay> times in a way that the compiler won't optimize away
static inline void delay(u32 count) {
	for (u32 i = 0; i < count; i++) {
		asm volatile("nop");
	}
}

/* Write to a pointer with raw value, ensure mask >= value 
   If passing a stuct pointer ie. GPIOB->ODR, you can pass by reference &GPIO->ODR */
static inline void set_ptr_vol_raw_u32(volatile u32 *ptr, u32 value) {
    *ptr = value;
}

/* Get a pointer value 
   If passing a stuct pointer ie. GPIOB->ODR, you can pass by reference &GPIO->ODR */
u32 get_ptr_vol_raw_u32(volatile u32 *ptr) {
    return *ptr; 
}

// A Mailbox message with set clock rate of PL011 to 3MHz tag
volatile unsigned int  __attribute__((aligned(16))) mbox[9] = {
    9*4, 0, 0x38002, 12, 8, 2, 3000000, 0 ,0
};
 
void uart_init(int raspi)
{ 
	// Disable UART0.
	set_ptr_vol_raw_u32(&USART0->CR, 0x00000000);
	// Setup the GPIO pin 14 && 15.
 
	// Disable pull up/down for all GPIO pins & delay for 150 cycles.
	set_ptr_vol_raw_u32(&GPIO->GPPUD, 0x00000000);
	delay(150);
 
	// Disable pull up/down for pin 14,15 & delay for 150 cycles.
	set_ptr_vol_raw_u32(&GPIO->GPPUDCLK0, (1 << 14) | (1 << 15));
	delay(150);
 
	// Write 0 to GPPUDCLK0 to make it take effect.
	set_ptr_vol_raw_u32(&GPIO->GPPUDCLK0, 0x00000000);
 
	// Clear pending interrupts.
	set_ptr_vol_raw_u32(&USART0->ICR, 0x7FF);
 
	// Set integer & fractional part of baud rate.
	// Divider = UART_CLOCK/(16 * Baud)
	// Fraction part register = (Fractional part * 64) + 0.5
	// Baud = 115200.
 
	// For Raspi3 and 4 the UART_CLOCK is system-clock dependent by default.
	// Set it to 3Mhz so that we can consistently set the baud rate
	if (raspi >= 3) {
		// UART_CLOCK = 30000000;
		unsigned int r = (((u32)(&mbox) & ~0xF) | 8);
		// wait until we can talk to the VC
		while ( get_ptr_vol_raw_u32(&MAILBOX0->STATUS) & 0x80000000 ) { }
		// send our message to property channel and wait for the response

		set_ptr_vol_raw_u32(&MAILBOX0->WRITE, r);
		while ( (get_ptr_vol_raw_u32(&MAILBOX0->STATUS) & 0x40000000) || get_ptr_vol_raw_u32(&MAILBOX0->READ) != r ) { }
	}
 
	// Divider = 3000000 / (16 * 115200) = 1.627 = ~1.
	set_ptr_vol_raw_u32(&USART0->IBRD, 1);
	// Fractional part register = (.627 * 64) + 0.5 = 40.6 = ~40.
	set_ptr_vol_raw_u32(&USART0->FBRD, 40);
 
	// Enable FIFO & 8 bit data transmission (1 stop bit, no parity).
	set_ptr_vol_raw_u32(&USART0->LCRH, (1 << 4) | (1 << 5) | (1 << 6));
 
	// Mask all interrupts.
	set_ptr_vol_raw_u32(&USART0->IMSC, (1 << 1) | (1 << 4) | (1 << 5) | (1 << 6) |  (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10));
 
	// Enable UART0, receive & transfer part of UART.
	set_ptr_vol_raw_u32(&USART0->CR, (1 << 0) | (1 << 8) | (1 << 9));
}
 
void uart_putc(u8 c)
{
	// Wait for UART to become ready to transmit.
	while ( get_ptr_vol_raw_u32(&USART0->FR) & (1 << 5) ) { }
	set_ptr_vol_raw_u32(&USART0->DR, c);
}
 
u8 uart_getc()
{
    // Wait for UART to have received something.
    while ( get_ptr_vol_raw_u32(&USART0->FR) & (1 << 4) ) { }
    return get_ptr_vol_raw_u32(&USART0->DR);
}
 
void uart_puts(const char* str)
{
	for (u8 i = 0; str[i] != '\0'; i ++)
		uart_putc((u8)str[i]);
}
 
void kernel_main(u64 dtb_ptr32, u64 x1, u64 x2, u64 x3)
{
	// initialize UART for Raspi3
	uart_init(3);
	uart_puts("Hello, Ms. Bear!\r\n");
 
	while (1)
		uart_putc(uart_getc());
}
