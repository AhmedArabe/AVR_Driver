/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: SERVICES             *************************/
/**************    SWC:RTOS                    *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/

#include  "STD_TYPES.h"

#include "RTOS_interface.h"
#include "RTOS_config.h"
#include "RTOS_private.h"

#include "DIO_interface.h"
#include "TIMERS_Interface.h"
#include "GIE_interface.h"

Task_t SystemTasks[NUM_SYSTEM_TASKS] = {{NULL}};

void RTOS_voidInit(void)
{
	/* Enable  CTC interrupt */
	TIMER0_OC_InterruptEnable();
	/*Set Callback Timer 0*/
	Timer0_CTC_SetCallBack(&voidScheduler);
	/*Set The Compare Match Value To Be 125, To Make A CTC Event Every 1msec*/
	TIMER0_CTC_SetOCR0(125);
	/*Enable Global Interrupt*/
	GIE_voidEnable();
	/*Initiate Timer0*/
	TIMER0_Init(TIMER0_CTC_MODE,TIMER0_SCALER_64);

}

void RTOS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void(*Copy_pvTaskFunc)(void))
{

	SystemTasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
	SystemTasks[Copy_u8Priority].TaskFunc    = Copy_pvTaskFunc;
	SystemTasks[Copy_u8Priority].TaskState   = READY;
}

void RTOS_voidDeleteTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].TaskFunc = NULL;
}



void RTOS_voidChangeState(u8 Copy_u8Priority, u8 Copy_u8TaskState)
{
	SystemTasks[Copy_u8Priority].TaskState = Copy_u8TaskState;
}

static void voidScheduler(void)
{
	volatile static u32 Local_u32TickCounter = 0;
	Local_u32TickCounter++;
	u8 Local_u8LoopCounter;
	for(Local_u8LoopCounter = 0; Local_u8LoopCounter < NUM_SYSTEM_TASKS; Local_u8LoopCounter++)
	{
		if(SystemTasks[Local_u8LoopCounter].TaskState == READY)
		{
			if((Local_u32TickCounter % SystemTasks[Local_u8LoopCounter].Periodicity) == 0)
			{
				/*Invoke The Task Function*/
				if(SystemTasks[Local_u8LoopCounter].TaskFunc != NULL)
				{
					SystemTasks[Local_u8LoopCounter].TaskFunc();
				}
			}
			else
			{
				/* Do Nothing */
			}
		}
		else
		{
			/* Do Nothing */
		}
	}
}
