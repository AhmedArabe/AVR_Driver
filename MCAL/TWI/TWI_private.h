/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: MCAL                 *************************/
/**************    SWC:TWI	                   *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/

#ifndef TWI_PRIVATE_H
#define TWI_PRIVATE_H

#define TWBR            *((volatile u8 *)0x20)      // TWI Bit Rate Register

#define TWSR            *((volatile u8 *)0x21)      // TWI Status Register
#define TWSR_TWPS0      0                           // TWI Prescaler Bit 0
#define TWSR_TWPS1      1                           // TWI Prescaler Bit 1

#define TWAR            *((volatile u8 *)0x22)      // TWI Status Register
#define TWAR_TWGCE      0                           // TWI General Call Recognation Bit


#define TWDR            *((volatile u8 *)0x23)      // TWI Data Register

#define TWCR            *((volatile u8 *)0x56)      // TWI Control Register
#define TWCR_TWIE       0                           // TWI Interrupt Enabel Bit
#define TWCR_TWEN       2                           // TWI Enabel Bit
#define TWCR_TWWC       3                           // TWI Write Collision Flag Bit
#define TWCR_TWSTO      4                           // TWI Stop Condition Bit
#define TWCR_TWSTA      5                           // TWI Start Condition Bit
#define TWCR_TWEA       6                           // TWI Enabel Acknowlegment Bit
#define TWCR_TWINT      7                           // TWI Interrupt Flag


#define START_CONDITION_ACK             0x08
#define REPEATED_START_CONDITION_ACK    0x10

#endif
