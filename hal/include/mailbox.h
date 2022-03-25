#ifndef MAILBOX_H_
#define MAILBOX_H_

#include "common.h"

/* Register Pointer Structure */
typedef struct {
    volatile u32 READ;                  // MAILBOX Read Register
    volatile u32 RESERVED0[3];          // RESERVED
    volatile u32 POLL;                  // MAILBOX Poll Register
    volatile u32 SENDER;                // MAILBOX Sender Register
    volatile u32 STATUS;                // MAILBOX Status Register
    volatile u32 CONFIG;                // MAILBOX Config Register
    volatile u32 WRITE;                 // MAILBOX Write Register
} MAILBOX_TypeDef;

#endif /* MAILBOX_H_ */