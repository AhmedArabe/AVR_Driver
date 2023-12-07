/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: MCAL                 *************************/
/**************    SWC:SPI                     *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "SPI_Register.h"


void SPI_voidInit(CLOCK_t clock)
{
	#if SPI_TECHNIQUE == SPI_POLLING
	CLR_BIT(SPCR_REG,SPIE_BIT);
	#elif SPI_TECHNIQUE == SPI_INTERRUPT
	SET_BIT(SPCR_REG,SPIE_BIT);
	#endif

	/* 	ENABLE SPI */
	SET_BIT(SPCR_REG,SPE_BIT);

	#if DATA_ORDER == MSB
	CLR_BIT(SPCR_REG,DORD_BIT);
	#elif DATA_ORDER == LSB
	SET_BIT(SPCR_REG,DORD_BIT);
	#endif

	#if SPI_MODE == SPI_MASTER
	SET_BIT(SPCR_REG,MSTR_BIT);
	#elif SPI_MODE == SPI_SLAVE
	SET_BIT(SPCR_REG,MSTR_BIT);
	#endif

    #if CLK_POLARITY == LE_FALLING
	SET_BIT(SPCR_REG,CPOL_BIT);
	#elif CLK_POLARITY == LE_RISING
	SET_BIT(SPCR_REG,CPOL_BIT);
	#endif

    #if CLK_PHASE == LE_SETUP
	SET_BIT(SPCR_REG,CPHA_BIT);
	#elif CLK_PHASE == LE_SAMPLE
	SET_BIT(SPCR_REG,CPHA_BIT);
	#endif

	#if TRANSFER_SPEED == NORMAL_SPEED
	switch(clock)
	{
		case CLK_4:
		{
			SPCR_REG &= 0xFC;
			SPCR_REG |= CLK_4;
		}
		break;
		case CLK_16:
		{
			SPCR_REG &= 0xFC;
			SPCR_REG |= CLK_16;
		}
		break;
		case CLK_64:
		{
			SPCR_REG &= 0xFC;
			SPCR_REG |= CLK_64;
		}
		break;
		case CLK_128:
		{
			SPCR_REG &= 0xFC;
			SPCR_REG |= CLK_128;
		}
		break;
		default:
		break;
	}
	#elif TRANSFER_SPEED == DOUBLE_SPEED
	SET_BIT(SPSR_REG,SPI2X_BIT);
	switch(clock)
	{
		case CLK_4:
		{
			SPCR_REG &= 0xFC;
			SPCR_REG |= CLK_4;
		}
		break;
		case CLK_16:
		{
			SPCR_REG &= 0xFC;
			SPCR_REG |= CLK_16;
		}
		break;
		case CLK_64:
		{
			SPCR_REG &= 0xFC;
			SPCR_REG |= CLK_64;
		}
		break;
		case CLK_128:
		{
			SPCR_REG &= 0xFC;
			SPCR_REG |= CLK_128;
		}
		break;
		default:
		break;
	}
	#endif
}
u8 SPI_u8TransmitReceive(u8 copy_u8Data)
{
	SPDR_REG = copy_u8Data;
	while(GET_BIT(SPSR_REG,SPIF_BIT) != 1);
	return SPDR_REG;
}
