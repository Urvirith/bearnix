#ifndef USART_H_
#define USART_H_

/* Register Pointer Structure */
typedef struct {
    volatile uint32_t DR;               // USART Data Register
    volatile uint32_t RSRECR;           // USART Receive Status / Error Clear Register
    volatile uint32_t RESERVED0[4];     // RESERVED
    volatile uint32_t FR;               // USART Flag register
    volatile uint32_t ILPR;             // USART Unused Register
    volatile uint32_t IBRD;             // USART Integer Baud Rate Divisor Register
    volatile uint32_t FBRD;             // USART Fractional Baud Rate Divisor Register
    volatile uint32_t LCRH;             // USART Line Control Register
    volatile uint32_t CR;               // USART Control Register
    volatile uint32_t IFLS;             // USART Interrupt FIFO Level Select Register
    volatile uint32_t IMSC;             // USART Interrupt Mask Set Clear Register
    volatile uint32_t RIS;              // USART Raw Interrupt Status Register
    volatile uint32_t MIS;              // USART Masked Interrupt Status Register
    volatile uint32_t ICR;              // USART Masked Interrupt Clear Register
    volatile uint32_t DMACR;            // USART DMA Control Register
    //volatile uint32_t RESERVED1[13];    // RESERVED
    //volatile uint32_t ITCR;             // USART Test Control Register
    //volatile uint32_t ITIP;             // USART Test Input Register
    //volatile uint32_t ITOP;             // USART Test Output Register
    //volatile uint32_t TDR;              // USART Test Data Register
} USART_TypeDef;

#endif /* USART_H_ */