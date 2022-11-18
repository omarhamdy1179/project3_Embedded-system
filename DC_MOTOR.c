/*
 * DC_MOTOR.c
 *
 *  Created on: Oct 7, 2022
 *      Author: omar hamdii
 */

#include "DC_MOTOR.h"
#include "gpio.h"
#include "common_macros.h"
#include "Timer0.h"


/*
 * Description :
 * Initialize the Motor:
 * The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 * stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT); /* making portB pin0 output pin*/
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT); /* making portB pin1 output pin*/
	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);   /*intialy motor is off*/
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);   /*intialy motor is off*/

}




/*
 * Description :
 * Initialize the Motor:
 * The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	switch (state)
	{
	case DC_OFF:
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW); /*DC IS OFF*/
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
		break;

	case DC_CW:
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_HIGH);  /*DC Rotate CW*/
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
		PWM_Timer0_Init(speed);
		break;

	case DC_A_CW:
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_HIGH); /*DC Rotate A_cw*/
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
		PWM_Timer0_Init(speed);
	}
}


void TEMP_VS_MOTOR (uint8 TEMP)
{
	if (TEMP<30)
	{
		DcMotor_Rotate(DC_OFF,0);
	}
	else
		if ((TEMP>=30) && (TEMP<60))
		{
			DcMotor_Rotate(DC_CW,64);
		}
		else
			if ((TEMP>=60) && (TEMP<90))
		{
			DcMotor_Rotate(DC_CW,128);
		}
		else
			if ((TEMP>=90) && (TEMP<120))
		{
			DcMotor_Rotate(DC_CW,192);
		}
	    else
			if (TEMP>=120)
		{
			DcMotor_Rotate(DC_CW,511);
		}
}
