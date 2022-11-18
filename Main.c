/*
 * Main.c
 *
 *  Created on: Oct 7, 2022
 *  Author: omar hamdii
 */

#include "ADC.h"
#include "lcd.h"
#include "LM35.h"
#include "gpio.h"
 uint8 TEMP;

int main(void)
{
	 ADC_ConfigType config_ptr = {ADMUX_internal_voltage , Prescale_8};
 // uint64 config_ptr = NULL_PTR ;
	LCD_init(); /* initialize LCD driver */
	ADC_init(&config_ptr); /* initialize ADC driver */
	DcMotor_Init(); /*intialize DC MOTOR*/

	/*
	* Description :
	* Move the cursor to a specified row and column index on the screen
	*/
	 LCD_moveCursor(1,4);

	/* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_displayString("Temp =    C");

	/*
	 * Description :
	 * Move the cursor to a specified row and column index on the screen
	 */

    while(1)
    {

    	TEMP = LM35_GetTemperature();

		/* Display the temperature value every time at same position */
		LCD_moveCursor(1,11);

		if(TEMP >= 100)
		{
			LCD_intgerToString(TEMP);
		}
		else
		{
			LCD_intgerToString(TEMP);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
	TEMP_VS_MOTOR (TEMP);
	 if (TEMP<30)
	 {
		 LCD_moveCursor(0,4);
		 LCD_displayString("Fan Is OFF");
	 }
	 else
	 {
		 LCD_moveCursor(0,4);
		 LCD_displayString("Fan Is ON ");
	 }
    }
}
