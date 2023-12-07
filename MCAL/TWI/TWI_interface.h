/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: MCAL                 *************************/
/**************    SWC:TWI	                   *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/

#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H

typedef enum
{
    NoError,
    StartConditionError,
    RepeatedStartError,
    SLA_WError,
    SLA_RError,
    MasterWriteDataError,
    MasterReadDataError,

}TWI_ErrorStatus_t;


void TWI_voidMasterInit(u8 Copy_u8MasterAddress);
void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);
TWI_ErrorStatus_t TWI_ErrorStatusSendStartConditionWithACK(void);
TWI_ErrorStatus_t TWI_ErrorStatusSendRepeatedStartConditionWithACK(void);
TWI_ErrorStatus_t TWI_ErrorStatusSendSlaveAddressWithWriteACK(u8 Copy_u8SlaveAddress);
TWI_ErrorStatus_t TWI_ErrorStatusSendSlaveAddressWithReadACK(u8 Copy_u8SlaveAddress);
TWI_ErrorStatus_t TWI_ErrorStatusMasterWriteDataByteWithACK(u8 Copy_u8Data);
TWI_ErrorStatus_t TWI_ErrorStatusMasterReadDataByteWithACK(u8 * Copy_pu8ReceivedData);
void TWI_voidStopCondition(void);


#endif
