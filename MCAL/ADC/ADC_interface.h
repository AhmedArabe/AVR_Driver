/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: MCAL                 *************************/
/**************    SWC:ADC                     *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/


#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

void ADC_voidInit(void);

u16 ADC_u16StartConversionSynchronous(u8 copy_u8Channel);

u16 ADC_u16StartConversionAsynchronous(u8 copy_u8Channel,  void (*Copy_pvCallBackFunction)(void));

u16 ADC_GetVolt (void);


#endif
