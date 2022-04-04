#ifndef MAIN_H_
#define MAIN_H_

#include "common.h"
#include "pointer.h"
#include "bcm2837.h"
#include "gpio.h"
#include "mailbox.h"
#include "usart.h"


typedef struct sys_task {
    u64 id;         // Task ID
    u64 addr;       // Task Address
    u64 spos;       // Task Previous Stack Position
    u64 tcbloc;     // TCB Location
} SysTask_TypeDef;

#endif