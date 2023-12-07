/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: MCAL                 *************************/
/**************    SWC:ADC                     *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/


#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H


/* choose reference volt
	 * options : 1- AREF
	 * 			 2- AVCC
	 * 			 3- Internal_2.56v
	 * 			 */
#define ADC_REFERENCE_VOLT		AVCC





/* choose left_Adjust options
 * 	1- 8_bits
 * 	2- 10_bits
 * 	*/
#define Resolution 		Eight_bits




/*choose prescaler Factor
 * Options : 1- factor_2
 * 			 2- factor_4
 * 			 3- factor_8
 * 			 4- factor_16
 * 			 5- factor_32
 * 			 6- factor_64
 * 			 7- factor_128
 * 			 */
#define Prescaler_Factor	factor_128




/*choose to enable or disable ADC prepheral
 * Options : 1- Enabled
 * 			 2- Disabled
 * 			  */
#define ADC_Status 	Enabled



/*choose mode
 * Options : 1- Single_Conversion
 * 			 2- Auto_Trigger */
#define Conversion_Mode 	Single_Conversion




/*choose trigger source
 * 1- free running mode
 * 2- Analog Comparator
 * 3- EXTI
 * 4- Timer0_Compare
 * 5- Timer0_Overflow
 * 6- TimerCompareB
 * 7- Timer1_Overflow
 * 8- Timer1_Capture
 *
 *
 *  */

#define Trigger		free_running_mode


#endif
