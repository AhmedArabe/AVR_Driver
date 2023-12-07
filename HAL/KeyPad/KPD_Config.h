/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: HAL                  *************************/
/**************    SWC:KeyPad                  *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/


#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H


#define KPD_PORT            DIO_u8_PORTD
/*Column as output */
#define KPD_COL0_PIN    	DIO_u8_PIN0
#define KPD_COL1_PIN    	DIO_u8_PIN1
#define KPD_COL2_PIN   	 	DIO_u8_PIN2
#define KPD_COL3_PIN		DIO_u8_PIN3

/*Row as input with activate pull up */
#define KPD_ROW0_PIN        DIO_u8_PIN4
#define KPD_ROW1_PIN    	DIO_u8_PIN5
#define KPD_ROW2_PIN   		DIO_u8_PIN6
#define KPD_ROW3_PIN		DIO_u8_PIN7





#define KPD_ARR_Val    {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}



#endif
