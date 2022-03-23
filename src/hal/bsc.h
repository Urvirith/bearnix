#ifndef BSC_H_
#define BSC_H_

/* Register Pointer Structure */
typedef struct {
    volatile uint32_t CR;               // BSC Control Register
    volatile uint32_t SR;               // BSC Status Register
    volatile uint32_t DLEN;             // BSC Data Length Register
    volatile uint32_t AR;               // BSC Slave Address Register
    volatile uint32_t FIFO;             // BSC Data Fifo Register
    volatile uint32_t DIV;              // BSC Clock Divider Register
    volatile uint32_t DEL;              // BSC Data Delay Register
    volatile uint32_t CLKT;             // BSC Clock Stretch Timeout Register
} BSC_TypeDef;

#endif /* BSC_H_ */