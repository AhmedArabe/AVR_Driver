/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: HAL                  *************************/
/**************    SWC:EEPROM                  *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#define F_CPU 8000000UL

#include "TWI_interface.h"

#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"


ErrorState EEPROM_ErrorStateSendDataByte	( u16 Copy_u16ByteAddress , u8 Copy_u8Data	)
{
	ErrorState Local_ErrorState = STD_TYPES_OK ;
	u8 Local_u8I2cError = NoError ;
	/*Start Condition*/
	Local_u8I2cError = TWI_ErrorStatusSendStartConditionWithACK();
	if(Local_u8I2cError != NoError)
	{
		Local_ErrorState = STD_TYPES_NOK ;
	}
	/*Send SLA + W ACK*/
	Local_u8I2cError = TWI_ErrorStatusSendSlaveAddressWithWriteACK(0x50 | (EEPROM_A2 << 2) | (Copy_u16ByteAddress >> 8)	);
	if(Local_u8I2cError != NoError)
	{
		Local_ErrorState = STD_TYPES_NOK ;
	}
	/*Send Rest of byte address*/
	Local_u8I2cError = TWI_ErrorStatusMasterWriteDataByteWithACK((u8) Copy_u16ByteAddress);
	if(Local_u8I2cError != NoError)
	{
		Local_ErrorState = STD_TYPES_NOK ;
	}
	/*Send Data */

	Local_u8I2cError = TWI_ErrorStatusMasterWriteDataByteWithACK(Copy_u8Data );
	if(Local_u8I2cError != NoError)
	{
		Local_ErrorState = STD_TYPES_NOK ;
	}
	/*Stop Condition*/
	TWI_voidSendStopCondition();

	_delay_ms(10);

	return Local_ErrorState ;
}

ErrorState EEPROM_ErrorStateReadDataByte	( u16 Copy_u16ByteAddress , u8* Copy_pu8Data	)
{
	ErrorState Local_ErrorState = STD_TYPES_OK ;
	u8 Local_u8I2cError = NoError ;
	/*Start Condition */
	Local_u8I2cError = TWI_ErrorStatusSendStartConditionWithACK();
	if(Local_u8I2cError != NoError)
	{
		Local_ErrorState = STD_TYPES_NOK ;
	}
	/*Send SLA+W ACK*/
	Local_u8I2cError = TWI_ErrorStatusSendSlaveAddressWithWriteACK(0x50 | (EEPROM_A2 << 2) | (Copy_u16ByteAddress >> 8)	);
	if(Local_u8I2cError != NoError)
	{
		Local_ErrorState = STD_TYPES_NOK ;
	}
	/*Send Reset of byte address*/
	Local_u8I2cError = TWI_ErrorStatusMasterWriteDataByteWithACK((u8) Copy_u16ByteAddress);
	if(Local_u8I2cError != NoError)
	{
		Local_ErrorState = STD_TYPES_NOK ;
	}
	/*send repeated start*/
	Local_u8I2cError = TWI_ErrorStatusSendRepeatedStartConditionWithACK();
	if(Local_u8I2cError != NoError)
		{
			Local_ErrorState = STD_TYPES_NOK ;
		}
	/*Send SLA+R*/
	Local_u8I2cError = TWI_ErrorStatusSendSlaveAddressWithReadACK(0x50 | (EEPROM_A2 << 2) | (Copy_u16ByteAddress >> 8));
	if(Local_u8I2cError != NoError)
			{
				Local_ErrorState = STD_TYPES_NOK ;
			}
	/*Read Data */
	TWI_ErrorStatusMasterReadDataByteWithACK(Copy_pu8Data);
	if(Local_u8I2cError != NoError)
			{
				Local_ErrorState = STD_TYPES_NOK ;
			}
	/*Stop Conditon*/
	TWI_voidSendStopCondition();
	return Local_ErrorState ;
}
