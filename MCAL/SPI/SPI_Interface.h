/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: MCAL                 *************************/
/**************    SWC:SPI                     *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H


/*DEFINING SPI TECHNIQUES*/
 #define SPI_INTERRUPT		 1
 #define SPI_POLLING  		 0

/*	DEFINING SPI MODES*/
#define SPI_MASTER 			 1
#define SPI_SLAVE  			 0

/* 	DEFINING DATA ORDER OPTIONS */
#define LSB 				 1
#define MSB					 0

/*DEFINING CLOCK POLARITY OPTIONS*/
#define LE_RISING 			 0
#define LE_FALLING 			 1

/*DEFINING CLOCK PHASE OPTIONS */
#define LE_SAMPLE			 0
#define LE_SETUP  			 1

/*DEFINING DATA TRANSFER SPEED OPTIONS*/
#define NORMAL_SPEED 		0
#define DOUBLE_SPEED 		1

typedef enum
{
	CLK_4 ,
	CLK_16,
	CLK_64,
	CLK_128
}CLOCK_t;


void SPI_voidInit(CLOCK_t clock);

u8 SPI_u8TransmitReceive(u8 copy_u8Data);


#endif /* COTS_MCAL__SPI_SPI_INTERFACE_H_ */
