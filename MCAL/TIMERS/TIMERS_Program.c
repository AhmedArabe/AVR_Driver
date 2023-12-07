/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: MCAL                 *************************/
/**************    SWC:TIMERS                  *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMERS_Interface.h"
#include "TIMERS_Register.h"
#include "TIMERS_Config.h"
#include "TIMERS_Private.h"
#include "math.h"




/*************************Pointer to functions to be assigned to ISR*********************************/

static void (*Timer0_OVF_Fptr) (void)=NULL;
static void (*Timer0_CTC_Fptr) (void)=NULL;


/******************************************************************************************/
/*************************Pointer to functions to be assigned to ISR*********************************/

static void (*Timer1_OVF_Fptr) (void)=NULL;
static void (*Timer1_OCA_Fptr) (void)=NULL;
static void (*Timer1_OCB_Fptr) (void)=NULL;
static void (*Timer1_ICU_Fptr) (void)=NULL;
/******************************************************************************************/
/*timer 0 functions*/
void TIMER0_Init(Timer0Mode_type mode,Timer0Scaler_type scaler)
{
	switch (mode)
	{
	case TIMER0_NORMAL_MODE:
		CLR_BIT(TCCR0_REG,TCCR0_WGM00);
		CLR_BIT(TCCR0_REG,TCCR0_WGM01);
		break;
	case TIMER0_PHASECORRECT_MODE:
		SET_BIT(TCCR0_REG,TCCR0_WGM00);
		CLR_BIT(TCCR0_REG,TCCR0_WGM01);
		break;
	case TIMER0_CTC_MODE:
		CLR_BIT(TCCR0_REG,TCCR0_WGM00);
		SET_BIT(TCCR0_REG,TCCR0_WGM01);
		break;
	case TIMER0_FASTPWM_MODE:
		SET_BIT(TCCR0_REG,TCCR0_WGM00);
		SET_BIT(TCCR0_REG,TCCR0_WGM01);
		/*###############################################*/
		// Set On Top Clear On Compare
		SET_BIT(TCCR0_REG, TCCR0_COM01);
		CLR_BIT(TCCR0_REG, TCCR0_COM00);
		/*###############################################*/

		break;
	}
	TCCR0_REG&=0XF8;//0b11111000
	TCCR0_REG|=scaler;
}

void TIMER0_OC0Mode(OC0Mode_type mode)
{
	switch (mode)
	{
	case OC0_DISCONNECTED:
		CLR_BIT(TCCR0_REG,TCCR0_COM00);
		CLR_BIT(TCCR0_REG,TCCR0_COM01);
		break;
	case OC0_TOGGLE:
		SET_BIT(TCCR0_REG,TCCR0_COM00);
		CLR_BIT(TCCR0_REG,TCCR0_COM01);
		break;
	case OC0_NON_INVERTING:
		CLR_BIT(TCCR0_REG,TCCR0_COM00);
		SET_BIT(TCCR0_REG,TCCR0_COM01);
		break;
	case OC0_INVERTING:
		SET_BIT(TCCR0_REG,TCCR0_COM00);
		SET_BIT(TCCR0_REG,TCCR0_COM01);
		break;
	}
}

void TIMER0_OV_InterruptEnable(void)
{
	SET_BIT(TIMSK_REG,TIMSK_TOIE0);
}
void TIMER0_OV_InterruptDisable(void)
{
	CLR_BIT(TIMSK_REG,TIMSK_TOIE0);
}
void TIMER0_OC_InterruptEnable(void)
{
	SET_BIT(TIMSK_REG,TIMSK_OCIE0);
}
void TIMER0_OC_InterruptDisable(void)
{
	CLR_BIT(TIMSK_REG,TIMSK_OCIE0);
}
/*********************READ TCNT***************************************/
u8 TIMER0_Read_TCNT(void)
{
	return TCNT0_REG;
}


/*********************SET OCR0 Value*********************************/
void TIMER0_CTC_SetOCR0(u8 Local_u8OCRValue)
{
	if(Local_u8OCRValue <=255)
	{

		OCR0_REG = Local_u8OCRValue;
	}
}



/***************************Timer0 callback*************************/
void Timer0_OVF_SetCallBack(void(*LocalFptr)(void))
{
	if(LocalFptr != NULL)
	{
		Timer0_OVF_Fptr = LocalFptr;
	}
}



void Timer0_CTC_SetCallBack(void(*LocalFptr)(void))
{
	if(LocalFptr != NULL)
	{
		Timer0_CTC_Fptr = LocalFptr;
	}
}

/*********************************Timer 0 ISR functions*********************************************/
ISR(TIMER0_OVF_vect)
{
	if(Timer0_OVF_Fptr != NULL)
	{
		Timer0_OVF_Fptr();
	}
}

ISR(TIMER0_OC_vect)
{
	if(Timer0_CTC_Fptr != NULL)
	{
		Timer0_CTC_Fptr();
	}
}



/***********************************************************************/
/*timer 1 functions*/
void Timer1_Init( Timer1Mode_type mode,Timer1Scaler_type scaler)
{
	switch (mode)
	{
	case TIMER1_NORMAL_MODE:
		CLR_BIT(TCCR1A_REG,TCCR1A_WGM10);
		CLR_BIT(TCCR1A_REG,TCCR1A_WGM11);
		CLR_BIT(TCCR1B_REG,TCCR1B_WGM12);
		CLR_BIT(TCCR1B_REG,TCCR1B_WGM13);
		break;
	case TIMER1_CTC_ICR_TOP_MODE:
		CLR_BIT(TCCR1A_REG,TCCR1A_WGM10);
		CLR_BIT(TCCR1A_REG,TCCR1A_WGM11);
		SET_BIT(TCCR1B_REG,TCCR1B_WGM12);
		SET_BIT(TCCR1B_REG,TCCR1B_WGM13);
		break;

	case TIMER1_CTC_OCRA_TOP_MODE:
		CLR_BIT(TCCR1A_REG,TCCR1A_WGM10);
		CLR_BIT(TCCR1A_REG,TCCR1A_WGM11);
		SET_BIT(TCCR1B_REG,TCCR1B_WGM12);
		CLR_BIT(TCCR1B_REG,TCCR1B_WGM13);
		break;

	case TIMER1_FASTPWM_ICR_TOP_MODE:
		CLR_BIT(TCCR1A_REG,TCCR1A_WGM10);
		SET_BIT(TCCR1A_REG,TCCR1A_WGM11);
		SET_BIT(TCCR1B_REG,TCCR1B_WGM12);
		SET_BIT(TCCR1B_REG,TCCR1B_WGM13);
		break;

	case TIMER1_FASTPWM_OCRA_TOP_MODE:
		SET_BIT(TCCR1A_REG,TCCR1A_WGM10);
		SET_BIT(TCCR1A_REG,TCCR1A_WGM11);
		SET_BIT(TCCR1B_REG,TCCR1B_WGM12);
		SET_BIT(TCCR1B_REG,TCCR1B_WGM13);
		break;
	}

	TCCR1B_REG&=0XF8;
	TCCR1B_REG|=scaler;

}
void Timer1_OCRA1Mode(OC1A_Mode_type oc1a_mode)
{
	switch (oc1a_mode)
	{
	case OCRA_DISCONNECTED:
		CLR_BIT(TCCR1A_REG,TCCR1A_COM1A0);
		CLR_BIT(TCCR1A_REG,TCCR1A_COM1A1);
		break;
	case OCRA_TOGGLE:
		SET_BIT(TCCR1A_REG,TCCR1A_COM1A0);
		CLR_BIT(TCCR1A_REG,TCCR1A_COM1A1);
		break;
	case OCRA_NON_INVERTING:
		CLR_BIT(TCCR1A_REG,TCCR1A_COM1A0);
		SET_BIT(TCCR1A_REG,TCCR1A_COM1A1);
		break;
	case OCRA_INVERTING:
		SET_BIT(TCCR1A_REG,TCCR1A_COM1A0);
		SET_BIT(TCCR1A_REG,TCCR1A_COM1A1);
		break;
	}
}
void Timer1_OCRB1Mode(OC1B_Mode_type oc1b_mode)
{
	switch (oc1b_mode)
	{
	case OCRB_DISCONNECTED:
		CLR_BIT(TCCR1A_REG,TCCR1A_COM1B0);
		CLR_BIT(TCCR1A_REG,TCCR1A_COM1B1);
		break;
	case OCRB_TOGGLE:
		SET_BIT(TCCR1A_REG,TCCR1A_COM1B0);
		CLR_BIT(TCCR1A_REG,TCCR1A_COM1B1);
		break;
	case OCRB_NON_INVERTING:
		CLR_BIT(TCCR1A_REG,TCCR1A_COM1B0);
		SET_BIT(TCCR1A_REG,TCCR1A_COM1B1);
		break;
	case OCRB_INVERTING:
		SET_BIT(TCCR1A_REG,TCCR1A_COM1B0);
		SET_BIT(TCCR1A_REG,TCCR1A_COM1B1);
		break;
	}
}
void Timer1_InputCaptureEdge(ICU_Edge_type edge)
{
	if(edge==RISING)
		SET_BIT(TCCR1B_REG,TCCR1B_ICES1);

	else if(edge==FALLING)
		CLR_BIT(TCCR1B_REG,TCCR1B_ICES1);
}

u8 Timer1_ReadInputCaptureValue(void)
{
	return ICR1_REG;
}


/****************************Timer 1 Interrupt functions**************************************/

void Timer1_ICU_InterruptEnable(void)
{
	SET_BIT(TIMSK_REG,TIMSK_TICIE1);
}
void Timer1_ICU_InterruptDisable(void)
{
	CLR_BIT(TIMSK_REG,TIMSK_TICIE1);
}
void Timer1_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK_REG,TIMSK_TOIE1);
}
void Timer1_OVF_InterruptDisable(void)
{
	CLR_BIT(TIMSK_REG,TIMSK_TOIE1);
}
void Timer1_OCA_InterruptEnable(void)
{
	SET_BIT(TIMSK_REG,TIMSK_OCIE1A);
}
void Timer1_OCA_InterruptDisable(void)
{
	CLR_BIT(TIMSK_REG,TIMSK_OCIE1A);
}
void Timer1_OCB_InterruptEnable(void)
{
	SET_BIT(TIMSK_REG,TIMSK_OCIE1B);
}
void Timer1_OCB_InterruptDisable(void)
{
	CLR_BIT(TIMSK_REG,TIMSK_OCIE1B);
}

void TIMER1_PreloadOCR1B(u16 preload_value)
{
	OCR1B_REG = preload_value;
}
void TIMER1_PreloadOCR1A(u16 preload_value)
{
	OCR1A_REG = preload_value;
}


/*********************************Timer 1 Call Back functions*****************************************/

void Timer1_OVF_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OVF_Fptr=LocalFptr;
}
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCA_Fptr=LocalFptr;
}
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCB_Fptr=LocalFptr;
}
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_ICU_Fptr=LocalFptr;
}

/*********************************Timer 1 ISR functions*********************************************/
ISR(TIMER1_OVF_vect)
{
	if(Timer1_OVF_Fptr!=NULL)
	{
		Timer1_OVF_Fptr();
	}
}
ISR(TIMER1_OCA_vect)
{
	if(Timer1_OCA_Fptr!=NULL)
	{
		Timer1_OCA_Fptr();
	}
}
ISR(TIMER1_OCB_vect)
{
	if(Timer1_OCB_Fptr!=NULL)
	{
		Timer1_OCB_Fptr();
	}
}
ISR(TIMER1_ICU_vect)
{
	if(Timer1_ICU_Fptr!=NULL)
	{
		Timer1_ICU_Fptr();
	}
}

