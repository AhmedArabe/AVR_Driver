/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: MCAL                 *************************/
/**************    SWC:SPI                     *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/*
 * SELECTING SPI TECHNIQUE
 * 		1- SPI_INTERRUPT
 * 		2- SPI_POLLING
 */
#define SPI_TECHNIQUE 		SPI_POLLING


/*
 * SELECTING SPI MODE
 * 		1- SPI_MASTER  (if the  device is the master)
 * 		2- SPI_SLAVE   (if the  device is the slave)
 */
#define SPI_MODE 			SPI_MASTER



/*
 * SELECTING DATA ORDER MODE
 * 		1- LSB Least significant bit is transmitted first
 *		2-  MSB Most significant bit is transmitted first
 *		*/
#define DATA_ORDER			 LSB




/* SELCTING CLOCK POLARITY
 *	 	1- LE_RISING  (for leading edge rising and trailing edge falling)
 * 		2- LE_FALLING (for leading edge falling and trailing edge rising)
 */
#define CLK_POLARITY 	LE_RISING



/*SELECTING CLOCK PHASE
 *		1- LE_SAMPLE (for leading edge sample and trailing edge setup)
 *		2- LE_SETUP  (for leading edge setup and trailing edge sample)
 *		*/
#define CLK_PHASE 		LE_SAMPLE




/*SELECTING DATA TRANSFER SPEED
 *		1- NORMAL_SPEED
 *		2- DOUBLE_SPEED */

#define TRANSFER_SPEED 	NORMAL_SPEED


#endif /* COTS_MCAL__SPI_SPI_CONFIG_H_ */
