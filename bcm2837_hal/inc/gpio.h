#ifndef GPIO_H_
#define GPIO_H_

#include "common.h"

/* Register Pointer Structure */
typedef struct {
    volatile u32 GPFSEL0;               // GPIO Function Select 0
    volatile u32 GPFSEL1;               // GPIO Function Select 1
    volatile u32 GPFSEL2;               // GPIO Function Select 2
    volatile u32 GPFSEL3;               // GPIO Function Select 3
    volatile u32 GPFSEL4;               // GPIO Function Select 4
    volatile u32 GPFSEL5;               // GPIO Function Select 5
    volatile u32 RESERVED0;             // RESERVED
    volatile u32 GPSET0;                // GPIO Pin Output Set
    volatile u32 GPSET1;                // GPIO Pin Output Set
    volatile u32 RESERVED1;             // RESERVED
    volatile u32 GPCLR0;                // GPIO Pin Output Clr
    volatile u32 GPCLR1;                // GPIO Pin Output Clr
    volatile u32 RESERVED2;             // RESERVED
    volatile u32 GPLEV0;                // GPIO Pin Level
    volatile u32 GPLEV1;                // GPIO Pin Level
    volatile u32 RESERVED3;             // RESERVED
    volatile u32 GPEDS0;                // GPIO Event Detect Status
    volatile u32 GPEDS1;                // GPIO Event Detect Status
    volatile u32 RESERVED4;             // RESERVED
    volatile u32 GPREN0;                // GPIO Pin Rising Edge Detect Enable
    volatile u32 GPREN1;                // GPIO Pin Rising Edge Detect Enable
    volatile u32 RESERVED5;             // RESERVED
    volatile u32 GPFEN0;                // GPIO Pin Falling Edge Detect Enable
    volatile u32 GPFEN1;                // GPIO Pin Falling Edge Detect Enable
    volatile u32 RESERVED6;             // RESERVED
    volatile u32 GPHEN0;                // GPIO Pin High Detect Enable
    volatile u32 GPHEN1;                // GPIO Pin High Detect Enable
    volatile u32 RESERVED7;             // RESERVED
    volatile u32 GPLEN0;                // GPIO Pin Low Detect Enable
    volatile u32 GPLEN1;                // GPIO Pin Low Detect Enable
    volatile u32 RESERVED8;             // RESERVED
    volatile u32 GPAREN0;               // GPIO Pin Async Rising Edge Detect Enable
    volatile u32 GPAREN1;               // GPIO Pin Async Rising Edge Detect Enable
    volatile u32 RESERVED9;             // RESERVED
    volatile u32 GPAFEN0;               // GPIO Pin Async Falling Edge Detect Enable
    volatile u32 GPAFEN1;               // GPIO Pin Async Falling Edge Detect Enable
    volatile u32 RESERVED10;            // RESERVED
    volatile u32 GPPUD;                 // GPIO Pin Pull-Up/Pull-Down Enable
    volatile u32 GPPUDCLK0;             // GPIO Pin Pull-Up/Pull-Down Clock Enable
    volatile u32 GPPUDCLK1;             // GPIO Pin Pull-Up/Pull-Down Clock Enable
} GPIO_TypeDef;

#endif /* GPIO_H_ */