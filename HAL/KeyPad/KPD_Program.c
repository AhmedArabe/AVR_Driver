#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "KPD_Interface.h"
#include "KPD_Config.h"
#include "KPD_Private.h"

u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey=KPD_NO_PRESSED_KEY;
	u8 Local_u8ColumnIndex,Local_u8RowIndex;
	u8 Local_u8PinSate;

	DIO_u8SetPinDirection(KPD_PORT,KPD_COL0_PIN,DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_PORT,KPD_COL1_PIN,DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_PORT,KPD_COL2_PIN,DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_PORT,KPD_COL3_PIN,DIO_u8_PIN_OUTPUT);

	DIO_u8SetPinValue(KPD_PORT,KPD_COL0_PIN,DIO_u8_PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT,KPD_COL1_PIN,DIO_u8_PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT,KPD_COL2_PIN,DIO_u8_PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT,KPD_COL3_PIN,DIO_u8_PIN_HIGH);

	DIO_u8SetPinDirection(KPD_PORT,KPD_ROW0_PIN,DIO_u8_PIN_LOW);
	DIO_u8SetPinDirection(KPD_PORT,KPD_ROW1_PIN,DIO_u8_PIN_LOW);
	DIO_u8SetPinDirection(KPD_PORT,KPD_ROW2_PIN,DIO_u8_PIN_LOW);
	DIO_u8SetPinDirection(KPD_PORT,KPD_ROW3_PIN,DIO_u8_PIN_LOW);

	/*Activate Pull up */
	DIO_u8SetPinValue(KPD_PORT,KPD_ROW0_PIN,DIO_u8_PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT,KPD_ROW1_PIN,DIO_u8_PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT,KPD_ROW2_PIN,DIO_u8_PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT,KPD_ROW3_PIN,DIO_u8_PIN_HIGH);


	static u8 Local_u8KPDArr[ROW_NUM][COLUMN_NUM]=KPD_ARR_Val;

	static u8 Local_u8KPDColArr[COLUMN_NUM]={KPD_COL0_PIN,KPD_COL1_PIN,KPD_COL2_PIN,KPD_COL3_PIN};

	static u8 Local_u8KPDRowArr[ROW_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

	for(Local_u8ColumnIndex=0;Local_u8ColumnIndex<COLUMN_NUM;Local_u8ColumnIndex++)
	{
		/*Activate Current Column*/

		DIO_u8SetPinValue(KPD_PORT,Local_u8KPDColArr[Local_u8ColumnIndex],DIO_u8_PIN_LOW);

		for(Local_u8RowIndex=0;Local_u8RowIndex<ROW_NUM;Local_u8RowIndex++)
		{

			/*Read the current Row*/

			DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRowArr[Local_u8RowIndex],&Local_u8PinSate);


			/*Check if switch is Pressed*/
			if(DIO_u8_PIN_LOW==Local_u8PinSate)
			{
				Local_u8PressedKey=Local_u8KPDArr[Local_u8RowIndex][Local_u8ColumnIndex];
				/*Polling (busy waiting )until the key is released*/
				while(DIO_u8_PIN_LOW==Local_u8PinSate)
				{
					DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRowArr[Local_u8RowIndex],&Local_u8PinSate);
				}
				return  Local_u8PressedKey;
			}
		}
		/*DeActivate the Current Column*/
		DIO_u8SetPinValue(KPD_PORT,Local_u8KPDColArr[Local_u8ColumnIndex],DIO_u8_PIN_HIGH);
	}

	return Local_u8PressedKey;

}
