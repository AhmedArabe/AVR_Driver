/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: MCAL                 *************************/
/**************    SWC: USART                  *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/

#ifndef MCAL_USART_USART_INTERFACE_H_
#define MCAL_USART_USART_INTERFACE_H_


void USART_voidInit(void);

void USART_voidSend(u8 Copy_u8Data);

void USART_voidRecive(u8* );

void USART_voidSend_MSG( u8* Copy_Pu8Massage);


void USART_voidRecive_MSG(char* buffer);





#endif /* MCAL_USART_USART_INTERFACE_H_ */
