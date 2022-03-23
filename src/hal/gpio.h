#ifndef GPIO_H_
#define GPIO_H_

/* Register Pointer Structure */
typedef struct {
    volatile uint32_t GPFSEL0;          // GPIO Function Select 0
    volatile uint32_t GPFSEL1;          // GPIO Function Select 1
    volatile uint32_t GPFSEL2;          // GPIO Function Select 2
    volatile uint32_t GPFSEL3;          // GPIO Function Select 3
    volatile uint32_t GPFSEL4;          // GPIO Function Select 4
    volatile uint32_t GPFSEL5;          // GPIO Function Select 5
    volatile uint32_t RESERVED0;        // RESERVED
    volatile uint32_t GPSET0;           // GPIO Pin Output Set
    volatile uint32_t GPSET1;           // GPIO Pin Output Set
    volatile uint32_t RESERVED1;        // RESERVED
    volatile uint32_t GPCLR0;           // GPIO Pin Output Clr
    volatile uint32_t GPCLR1;           // GPIO Pin Output Clr
    volatile uint32_t RESERVED2;        // RESERVED
    volatile uint32_t GPLEV0;           // GPIO Pin Level
    volatile uint32_t GPLEV1;           // GPIO Pin Level
    volatile uint32_t RESERVED3;        // RESERVED
    volatile uint32_t GPEDS0;           // GPIO Event Detect Status
    volatile uint32_t GPEDS1;           // GPIO Event Detect Status
    volatile uint32_t RESERVED4;        // RESERVED
    volatile uint32_t GPREN0;           // GPIO Pin Rising Edge Detect Enable
    volatile uint32_t GPREN1;           // GPIO Pin Rising Edge Detect Enable
    volatile uint32_t RESERVED5;        // RESERVED
    volatile uint32_t GPFEN0;           // GPIO Pin Falling Edge Detect Enable
    volatile uint32_t GPFEN1;           // GPIO Pin Falling Edge Detect Enable
    volatile uint32_t RESERVED6;        // RESERVED
    volatile uint32_t GPHEN0;           // GPIO Pin High Detect Enable
    volatile uint32_t GPHEN1;           // GPIO Pin High Detect Enable
    volatile uint32_t RESERVED7;        // RESERVED
    volatile uint32_t GPLEN0;           // GPIO Pin Low Detect Enable
    volatile uint32_t GPLEN1;           // GPIO Pin Low Detect Enable
    volatile uint32_t RESERVED8;        // RESERVED
    volatile uint32_t GPAREN0;          // GPIO Pin Async Rising Edge Detect Enable
    volatile uint32_t GPAREN1;          // GPIO Pin Async Rising Edge Detect Enable
    volatile uint32_t RESERVED9;        // RESERVED
    volatile uint32_t GPAFEN0;          // GPIO Pin Async Falling Edge Detect Enable
    volatile uint32_t GPAFEN1;          // GPIO Pin Async Falling Edge Detect Enable
    volatile uint32_t RESERVED9;        // RESERVED
    volatile uint32_t GPPUD;            // GPIO Pin Pull-Up/Pull-Down Enable
    volatile uint32_t GPPUDCLK0;        // GPIO Pin Pull-Up/Pull-Down Clock Enable
    volatile uint32_t GPPUDCLK1;        // GPIO Pin Pull-Up/Pull-Down Clock Enable
} GPIO_TypeDef;

#endif /* GPIO_H_ */