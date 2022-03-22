#ifndef GPIO_H_
#define GPIO_H_

/* Register Pointer Structure */
typedef struct {
    volatile uint32_t MODER;            // Mode Register
    volatile uint32_t OTYPER;           // Output Type Register
    volatile uint32_t OSPEEDR;          // Output Speed Register
    volatile uint32_t PUPDR;            // Pull up Pull Down Register
    volatile uint32_t IDR;              // Input Data Register
    volatile uint32_t ODR;              // Output Data Register
    volatile uint32_t BSRR;             // Bit Set Reset Register
    volatile uint32_t LCKR;             // Configuration Lock Register
    volatile uint32_t AFRL;             // Alternate Function Low Register
    volatile uint32_t AFRH;             // Alternate Function High Register
    volatile uint32_t BRR;              // Bit Reset Register
} GPIO_TypeDef;



#endif /* GPIO_H_ */