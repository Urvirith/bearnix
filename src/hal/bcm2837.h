#ifndef BCM2837_H_
#define BCM2837_H_

#define MMIO_BASE                   ((uint32_t)0x3F000000)

#define MAILBOX0_BASE               ((uint32_t)0x3F00B880)

#define GPIO_BASE                   ((uint32_t)0x3F200000)

#define BSC0_BASE                   ((uint32_t)0x3F205000)
#define BSC1_BASE                   ((uint32_t)0x3F804000)
#define BSC2_BASE                   ((uint32_t)0x3F805000)

#define PCM_BASE                    ((uint32_t)0x3F203000)

#define SPI0_BASE                   ((uint32_t)0x3F204000)

#define TIMER_BASE                  ((uint32_t)0x3E003000)

#define USART0_BASE                 ((uint32_t)0x3F201000)
#define USART2_BASE                 ((uint32_t)0x3F201400)
#define USART3_BASE                 ((uint32_t)0x3F201600)
#define USART4_BASE                 ((uint32_t)0x3F201800)
#define USART5_BASE                 ((uint32_t)0x3F201A00)

#define USB_BASE                    ((uint32_t)0x7E980000)

#endif /* BCM2837_H_ */