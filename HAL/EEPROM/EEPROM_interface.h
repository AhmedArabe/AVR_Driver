/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: HAL                  *************************/
/**************    SWC:EEPROM                  *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_


ErrorState EEPROM_ErrorStateSendDataByte	( u16 Copy_u8ByteAddress , u8 Copy_u8Data	);

ErrorState EEPROM_ErrorStateReadDataByte	( u16 Copy_u8ByteAddress , u8* Copy_pu8Data	);



#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
