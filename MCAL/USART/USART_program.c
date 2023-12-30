/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: MCAL                 *************************/
/**************    SWC: USART                  *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "USART_interface.h"
#include "USART_config.h"
#include "USART_Register.h"

void USART_voidInit(void)
{
	// One-stopBit , No parity , 8 data , No interrupt , asynchronous , 9600
	u8 Local_UCSRC_VAR = 0b10000000 ;

	SET_BIT(USART_UCSRB_REG ,UCSRB_RXEN_BIT);
	SET_BIT(USART_UCSRB_REG ,UCSRB_TXEN_BIT);


	//SET_BIT(Local_UCSRC_VAR ,UCSRC_URSEL_BIT);  // register select

	CLR_BIT(Local_UCSRC_VAR ,UCSRC_UMSEL_BIT);	//asynchronous
	CLR_BIT(Local_UCSRC_VAR ,UCSRC_UMP0_BIT);	//disable parity
	CLR_BIT(Local_UCSRC_VAR ,UCSRC_UMP1_BIT);	//disable parity

	CLR_BIT(Local_UCSRC_VAR ,UCSRC_USBS_BIT);	//one stop bit

	// 8 BIT DATA
	SET_BIT(Local_UCSRC_VAR , UCSRC_USCSZ0_BIT);
	SET_BIT(Local_UCSRC_VAR , UCSRC_USCSZ1_BIT);
	CLR_BIT(USART_UCSRB_REG, UCSRB_UCSZ2_BIT);

	CLR_BIT(Local_UCSRC_VAR ,UCSRC_UCPOL_BIT );

	USART_UCSRC_REG  = Local_UCSRC_VAR;


	// BAUDE RATE
	USART_UBRRL_REG = (u8) 51;

}

void USART_voidSend(u8 Copy_u8Data)
{
	while(GET_BIT(USART_UCSRA_REG , UCSRA_UDRE_BIT) ==0 ) ;

	USART_UDR_REG = Copy_u8Data ;

}

void USART_voidSend_MSG( u8* Copy_Pu8Massage)
{

	u8 Local_u8Iterator =0;

	while(Copy_Pu8Massage [Local_u8Iterator] != '\0')
	{

		USART_voidSend(Copy_Pu8Massage [Local_u8Iterator]);
		Local_u8Iterator++;

	}
}
void USART_voidRecive(u8* Copy_Pu8ReciveData)
{

	while(GET_BIT(USART_UCSRA_REG , UCSRA_RXC_BIT) == 0 );

	if(Copy_Pu8ReciveData != NULL)
	{
		* Copy_Pu8ReciveData = USART_UDR_REG ;
	}
}

void USART_voidRecive_MSG(u8* buffer)
{
	u8 i = 0;
	do
	{
		USART_voidRecive(&buffer[i]);
		i++;
	}while(buffer[i-1]!='\r');

}



