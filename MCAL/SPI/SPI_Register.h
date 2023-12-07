/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: MCAL                 *************************/
/**************    SWC:SPI                     *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SPDR_REG  *((volatile u8*)0x2F)
#define SPSR_REG  *((volatile u8*)0x2E)

#define SPIF_BIT  7
#define WCOL_BIT  6
#define SPI2X_BIT  0

#define SPCR_REG  *((volatile u8*)0x2D)

#define SPIE_BIT  7
#define SPE_BIT   6
#define DORD_BIT  5
#define MSTR_BIT  4
#define CPOL_BIT  3
#define CPHA_BIT  2


#endif /* COTS_MCAL__SPI_SPI_PRIVATE_H_ */
