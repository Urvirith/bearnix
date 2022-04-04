#ifndef BSC_H_
#define BSC_H_

#include "common.h"

/* Register Pointer Structure */
typedef struct {
    volatile u32 CR;                    // BSC Control Register
    volatile u32 SR;                    // BSC Status Register
    volatile u32 DLEN;                  // BSC Data Length Register
    volatile u32 AR;                    // BSC Slave Address Register
    volatile u32 FIFO;                  // BSC Data Fifo Register
    volatile u32 DIV;                   // BSC Clock Divider Register
    volatile u32 DEL;                   // BSC Data Delay Register
    volatile u32 CLKT;                  // BSC Clock Stretch Timeout Register
} BSC_TypeDef;

#endif /* BSC_H_ */