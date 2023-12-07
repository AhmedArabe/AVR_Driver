/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: MCAL                 *************************/
/**************    SWC: USART                  *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/

#ifndef MCAL_USART_USART_PRIVATE_H_
#define MCAL_USART_USART_PRIVATE_H_



#define USART_UDR_REG			*((volatile  u8*)0x2C)

#define USART_UCSRA_REG			*((volatile  u8*)0x2B)
#define UCSRA_RXC_BIT			7
#define UCSRA_TXC_BIT			6
#define UCSRA_UDRE_BIT			5
#define UCSRA_FE_BIT			4
#define UCSRA_DOR_BIT			3
#define UCSRA_PE_BIT			2


#define USART_UCSRB_REG			*((volatile  u8*)0x2A)

#define UCSRB_RXCIE_BIT			7
#define UCSRB_TXCIE_BIT			6
#define UCSRB_UDRIE_BIT			5
#define UCSRB_RXEN_BIT			4
#define UCSRB_TXEN_BIT			3
#define UCSRB_UCSZ2_BIT			2
#define UCSRB_RXB8_BIT			1
#define UCSRB_TXB8_BIT			0


#define USART_UCSRC_REG			*((volatile  u8*)0x40)
#define UCSRC_URSEL_BIT			7
#define UCSRC_UMSEL_BIT			6
#define UCSRC_UMP1_BIT			5
#define UCSRC_UMP0_BIT			4
#define UCSRC_USBS_BIT			3
#define UCSRC_USCSZ1_BIT		2
#define UCSRC_USCSZ0_BIT		1
#define UCSRC_UCPOL_BIT			0



#define USART_UBRRL_REG			*((volatile  u8*)0x29)

#define USART_UBRRH_REG			*((volatile  u8*)0x40)
#define UBRRH_URSEL_BIT			7



#endif /* MCAL_USART_USART_PRIVATE_H_ */
