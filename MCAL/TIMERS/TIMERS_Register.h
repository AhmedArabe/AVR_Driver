/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: MCAL                 *************************/
/**************    SWC:TIMERS                  *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/


#ifndef TIMERS_REGISTER_H_
#define TIMERS_REGISTER_H_


/************************************************************************************************/
/* Timer 0 Registers */
#define TCNT0_REG   (*(volatile u8*)0x52)
#define TCCR0_REG   (*(volatile u8*)0x53)
#define TWCR_REG    (*(volatile u8*)0x56)
#define SPMCR_REG   (*(volatile u8*)0x57)
#define TIFR_REG    (*(volatile u8*)0x58)
#define TIMSK_REG   (*(volatile u8*)0x59)
#define OCR0_REG    (*(volatile u8*)0x5C)

/* TCCR0 Bits */
#define TCCR0_FOC0    7
#define TCCR0_WGM00   6
#define TCCR0_COM01   5
#define TCCR0_COM00   4
#define TCCR0_WGM01   3
#define TCCR0_CS02    2
#define TCCR0_CS01    1
#define TCCR0_CS00    0


/* TIMSK Bits */
#define TIMSK_OCIE2   7
#define TIMSK_TOIE2   6
#define TIMSK_TICIE1  5
#define TIMSK_OCIE1A  4
#define TIMSK_OCIE1B  3
#define TIMSK_TOIE1   2
#define TIMSK_OCIE0   1
#define TIMSK_TOIE0   0

/****************************************************************************************************/

/*TIMER 1 Registers*/


#define ICR1_REG      (*(volatile u16*)0x46)
#define ICR1L_REG     (*(volatile u8 *)0x46)
#define ICR1H_REG     (*(volatile u8 *)0x47)
#define OCR1B_REG     (*(volatile u16*)0x48)
#define OCR1BL_REG    (*(volatile u8 *)0x48)
#define OCR1BH_REG    (*(volatile u8 *)0x49)
#define OCR1A_REG     (*(volatile u16*)0x4A)
#define OCR1AL_REG    (*(volatile u8 *)0x4A)
#define OCR1AH_REG    (*(volatile u8 *)0x4B)
#define TCNT1_REG     (*(volatile u16*)0x4C)
#define TCNT1L_REG    (*(volatile u8 *)0x4C)
#define TCNT1H_REG    (*(volatile u8 *)0x4D)
#define TCCR1B_REG    (*(volatile u8 *)0x4E)
#define TCCR1A_REG    (*(volatile u8 *)0x4F)
#define SFIOR_REG     (*(volatile u8 *)0x50)
#define OSCCAL_REG    (*(volatile u8 *)0x51)
/******************************************************************************/
/* Timer 2 Registrs*/

#define OCR2_REG     (*(volatile u8*)0x43)
#define TCNT2_REG    (*(volatile u8*)0x44)
#define TCCR2_REG    (*(volatile u8*)0x45)
#define WDTCR_REG    (*(volatile u8*)0x41)



/* TCCR2 Bits */
#define TCCR2_FOC2    7
#define TCCR2_WGM20   6
#define TCCR2_COM21   5
#define TCCR2_COM20   4
#define TCCR2_WGM21   3
#define TCCR2_CS22    2
#define TCCR2_CS21    1
#define TCCR2_CS20    0

/* ASSR Bits */
/* bits 7-4 reserved */
#define AS2     3
#define ASSR_TCN2UB  2
#define ASSR_OCR2UB  1
#define ASSR_TCR2UB  0

/* TCCR1A Bits*/
#define TCCR1A_COM1A1  7
#define TCCR1A_COM1A0  6
#define TCCR1A_COM1B1  5
#define TCCR1A_COM1B0  4
#define TCCR1A_FOC1A   3
#define TCCR1A_FOC1B   2
#define TCCR1A_WGM11   1
#define TCCR1A_WGM10   0

/* TCCR1B Bits*/
#define TCCR1B_ICNC1   7
#define TCCR1B_ICES1   6
/* bit 5 reserved */
#define TCCR1B_WGM13   4
#define TCCR1B_WGM12   3
#define TCCR1B_CS12    2
#define TCCR1B_CS11    1
#define TCCR1B_CS10    0

/* WDTCR Bits */
/* bits 7-5 reserved */
#define WDTCR_WDTOE   4
#define WDTCR_WDE     3
#define WDTCR_WDP2    2
#define WDTCR_WDP1    1
#define WDTCR_WDP0    0





#endif /* TIMERS_REGISTER_H_ */
