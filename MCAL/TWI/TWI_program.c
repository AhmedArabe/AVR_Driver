/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: MCAL                 *************************/
/**************    SWC:TWI	                   *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"

void TWI_voidMasterInit(u8 Copy_u8MasterAddress)
{
    /*Enable Acknowledge*/
    SET_BIT(TWCR, TWCR_TWEA);

    /*Set Freq*/
    /*Set SCL Freq = 100KHz, With TWPS bit = 0 and CPU Clock = 8MHz*/
    TWBR = 2;
    CLR_BIT(TWSR, TWSR_TWPS0);
    CLR_BIT(TWSR, TWSR_TWPS1);


    if(Copy_u8MasterAddress == 0)
    {
        /*Do Nothing*/
    }
    else
    {
        /*Set The Required Address For The Master*/
        TWAR = Copy_u8MasterAddress << 1;
    }

    /*Enabel TWI Peripheral*/
    SET_BIT(TWCR, TWCR_TWEN);
}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
    /*Enable Acknowledge*/
    SET_BIT(TWCR, TWCR_TWEA);
    /*Set Slave Address In The TWAR Register*/
    TWAR = Copy_u8SlaveAddress << 1;

    /*Enabel TWI Peripheral*/
    SET_BIT(TWCR, TWCR_TWEN);
}


TWI_ErrorStatus_t TWI_ErrorStatusSendStartConditionWithACK(void)
{
    TWI_ErrorStatus_t Local_ErrorStatus = NoError;
    /*Set Start Condition Bit*/
    SET_BIT(TWCR, TWCR_TWSTA);

    /*Clear The TWINT Flag*/
    SET_BIT(TWCR, TWCR_TWINT);

    /*Polling (Busy Wait) On The TWINT Flag*/
    while(GET_BIT(TWCR, TWCR_TWINT) == 0);

    /*Check If The Operation Is Transmitted Successfully*/
    if((TWSR & 0xF8) != START_CONDITION_ACK)
    {
        /*Return Error*/
        Local_ErrorStatus = StartConditionError;
    }
    else
    {
        /*Do Nothing*/
    }
    return Local_ErrorStatus;
}

TWI_ErrorStatus_t TWI_ErrorStatusSendRepeatedStartConditionWithACK(void)
{
    TWI_ErrorStatus_t Local_ErrorStatus = NoError;

    /*Set Start Condition Bit*/
    SET_BIT(TWCR, TWCR_TWSTA);

    /*Clear The TWINT Flag*/
    SET_BIT(TWCR, TWCR_TWINT);

    /*Polling (Busy Wait) On The TWINT Flag*/
    while(GET_BIT(TWCR, TWCR_TWINT) == 0);

    /*Check If The Operation Is Transmitted Successfully*/
    if((TWSR & 0xF8) != REPEATED_START_CONDITION_ACK)
    {
        /*Return Error*/
        Local_ErrorStatus = RepeatedStartError;
    }
    else
    {
        /*Do Nothing*/
    }
    return Local_ErrorStatus;
}

TWI_ErrorStatus_t TWI_ErrorStatusSendSlaveAddressWithWriteACK(u8 Copy_u8SlaveAddress)
{
    TWI_ErrorStatus_t Local_ErrorStatus = NoError;

    /*Set The Slave Address In The TWDR*/
    TWDR = (Copy_u8SlaveAddress << 1);
    /*Clear Bit 0 In The TWDR Register, W=0, R=1*/
    CLR_BIT(TWDR, 0);
    /*Clear Start Condition Bit*/
    CLR_BIT(TWCR, TWCR_TWSTA);
    /*Clear The TWINT Flag*/
    SET_BIT(TWCR, TWCR_TWINT);

    /*Polling (Busy Wait) On The TWINT Flag*/
    while(GET_BIT(TWCR, TWCR_TWINT) == 0);

    /*Check If The Operation Is Transmitted Successfully*/
    if((TWSR & 0xF8) != 0x18)
    {
        /*Return Error*/
        Local_ErrorStatus = SLA_WError;
    }
    else
    {
        /*Do Nothing*/
    }
    return Local_ErrorStatus;
}

TWI_ErrorStatus_t TWI_ErrorStatusSendSlaveAddressWithReadACK(u8 Copy_u8SlaveAddress)
{
    TWI_ErrorStatus_t Local_ErrorStatus = NoError;
    
    /*Set The Slave Address In The TWDR*/
    TWDR = (Copy_u8SlaveAddress << 1);
    /*Clear Bit 0 In The TWDR Register, W=0, R=1*/
    SET_BIT(TWDR, 0);
    /*Clear Start Condition Bit*/
    CLR_BIT(TWCR, TWCR_TWSTA);
    /*Clear The TWINT Flag*/
    SET_BIT(TWCR, TWCR_TWINT);

    /*Polling (Busy Wait) On The TWINT Flag*/
    while(GET_BIT(TWCR, TWCR_TWINT) == 0);

    /*Check If The Operation Is Transmitted Successfully*/
    if((TWSR & 0xF8) != 0x40)
    {
        /*Return Error*/
        Local_ErrorStatus = SLA_WError;
    }
    else
    {
        /*Do Nothing*/
    }
    return Local_ErrorStatus;
}

TWI_ErrorStatus_t TWI_ErrorStatusMasterWriteDataByteWithACK(u8 Copy_u8Data)
{
    TWI_ErrorStatus_t Local_ErrorStatus = NoError;
    
    /*Set The Data In The TWDR Register*/
    TWDR = Copy_u8Data;
    /*Clear The TWINT Flag*/
    SET_BIT(TWCR, TWCR_TWINT);

    /*Polling (Busy Wait) On The TWINT Flag*/
    while(GET_BIT(TWCR, TWCR_TWINT) == 0);

    /*Check If The Operation Is Transmitted Successfully*/
    if((TWSR & 0xF8) != 0x28)
    {
        /*Return Error*/
        Local_ErrorStatus = MasterWriteDataError;
    }
    else
    {
        /*Do Nothing*/
    }
    return Local_ErrorStatus;
}

TWI_ErrorStatus_t TWI_ErrorStatusMasterReadDataByteWithACK(u8 * Copy_pu8ReceivedData)
{
    TWI_ErrorStatus_t Local_ErrorStatus = NoError;
    /*Clear The TWINT Flag To Make The Slave Send Its Data*/
    SET_BIT(TWCR, TWCR_TWINT);
    /*Polling (Busy Wait) On The TWINT Flag*/
    while(GET_BIT(TWCR, TWCR_TWINT) == 0);
    /*Check If The Operation Is Transmitted Successfully*/
    if((TWSR & 0xF8) != 0x50)
    {
        /*Return Error*/
        Local_ErrorStatus = MasterReadDataError;
    }
    else
    {
        /*Read The TWDR Received Data*/
        *Copy_pu8ReceivedData = TWDR;
    }
    return Local_ErrorStatus;
}

void TWI_voidStopCondition(void)
{
    /*Set Stop Condition Bit*/    
    SET_BIT(TWCR, TWCR_TWSTO);
    /*Clear The TWINT Flag To Make The Slave Send Its Data*/
    SET_BIT(TWCR, TWCR_TWINT);
    /*Polling (Busy Wait) On The TWINT Flag*/
    while(GET_BIT(TWCR, TWCR_TWINT) == 0);
}
