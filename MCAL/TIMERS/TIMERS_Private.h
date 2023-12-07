/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: MCAL                 *************************/
/**************    SWC:TIMERS                  *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/


#ifndef TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_H_


/*********************************************************************************/
/* Interrupt vectors */


/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect		__vector_4
/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect			__vector_5
/* Timer/Counter1 Capture Event */
#define TIMER1_ICU_vect			__vector_6
/* Timer/Counter1 Compare Match A */
#define TIMER1_OCA_vect			__vector_7
/* Timer/Counter1 Compare Match B */
#define TIMER1_OCB_vect			__vector_8
/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect			__vector_9
/* Timer/Counter0 Compare Match */
#define TIMER0_OC_vect			__vector_10
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect			__vector_11



#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)





#endif /* TIMERS_PRIVATE_H_ */
