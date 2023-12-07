/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: MCAL                 *************************/
/**************    SWC:ADC                     *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_Register.h"
#include "ADC_Private.h"
#include "ADC_Config.h"



void ADC_voidInit(void)
{

	/* Set voltage reference */
#if ADC_REFERENCE_VOLT ==AREF

	CLR_BIT(ADMUX,ADMUX_REFS1);
	CLR_BIT(ADMUX,ADMUX_REFS0);

#elif ADC_REFERENCE_VOLT ==AVCC
	CLR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);

#elif ADC_REFERENCE_VOLT == Internal_2.56v
	SET_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);
#else
#error "choose the correct option"

#endif


 /*	Set Resolution */
#if  Resolution == Eight_bits
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif Resolution == Ten_bits
	CLR_BIT(ADMUX,ADMUX_ADLAR);

#else
#error "choose the correct option"
#endif


	 /* Set Prescaller factor */
#if Prescaler_Factor == factor_2
	ADCSRA &=0b11111000;
	ADCSRA |= factor_2 ;

#elif Prescaler_Factor == factor_4
	ADCSRA &=0b11111000;
	ADCSRA |= factor_4 ;
#elif Prescaler_Factor == factor_8
	ADCSRA &=0b11111000;
	ADCSRA |= factor_8 ;
#elif Prescaler_Factor == factor_16
	ADCSRA &=0b11111000;
	ADCSRA |= factor_16 ;
#elif Prescaler_Factor == factor_32
	ADCSRA &=0b11111000;
	ADCSRA |= factor_32 ;
#elif Prescaler_Factor == factor_64
	ADCSRA &=0b11111000;
	ADCSRA |= factor_64 ;
#elif Prescaler_Factor == factor_128
	ADCSRA &=0b11111000;
	ADCSRA |=  (factor_128 &(0x07)) ;
#else
#error "choose the correct option"
#endif

	/* check ADC_Status enabled or disabled */
#if ADC_Status == Enabled
	SET_BIT(ADCSRA,ADCSRA_ADEN);
#elif ADC_Status == Disabled
	CLR_BIT(ADCSRA,ADCSRA_ADEN);
#else
#error "choose the correct option"
#endif


// ADC Polling
CLR_BIT(ADCSRA, ADCSRA_ADIE);


}


u16 ADC_u8GetChannelReading(u8 copy_u8Channel)
{


	/*clear the mux bits in ADMUX Register*/
	ADMUX &=0b11100000;

	/*set required channel into the Mux bits */
	ADMUX|= (copy_u8Channel & 0x1f);

#if Conversion_Mode == Single_Conversion

	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*Polling (busy waiting) until the conversion complete flag is set*/
	while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0);

	/*Clear conversion complete flag */
	SET_BIT(ADCSRA,ADCSRA_ADIF);

#elif Conversion_Mode == Auto_Trigger

	/*SET Trigger Source*/
	SFIOR&=0x00;     // clear register
	SFIOR = free_running_mode;

	/*start Conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);

#else
#error "choose the correct option"
#endif


#if  Resolution == Eight_bits
	/*return reading*/
		return ADCH;
#elif Resolution == Ten_bits

		return ADC ;
#else
#error "choose the correct option"
#endif


}

u16 ADC_GetVolt(u8 copy_u8Channel)
{
	u32 digital =ADC_u8GetChannelReading(copy_u8Channel);

	u16 volt=(u16)(((u32)digital*5000UL)/256UL);;
	return volt;
}
