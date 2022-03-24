#ifndef MAILBOX_H_
#define MAILBOX_H_

/* Register Pointer Structure */
typedef struct {
    volatile uint32_t READ;             // MAILBOX Read Register
    volatile uint32_t RESERVED0[3];     // RESERVED
    volatile uint32_t POLL;             // MAILBOX Poll Register
    volatile uint32_t SENDER;           // MAILBOX Sender Register
    volatile uint32_t STATUS;           // MAILBOX Status Register
    volatile uint32_t CONFIG;           // MAILBOX Config Register
    volatile uint32_t WRITE;            // MAILBOX Write Register
} MAILBOX_TypeDef;

#endif /* MAILBOX_H_ */