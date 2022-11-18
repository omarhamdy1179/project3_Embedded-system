/*
 * ADC.c
 *
 *  Created on: Oct 4, 2022
 *  Author: omar hamdii
 */
#include "ADC.h"
#include "common_Macros.h"
#include <avr/io.h>

void ADC_init (const ADC_ConfigType* config_ptr )
{
	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * REFS1   =1 internal voltage
	 * REFS0   =1 internal voltage
	 * ADPS2:0 = 111 to choose ADC_Clock = F_CPU/128 = 16Mhz/128 = 125Khz --> ADC must operate in range 50-200Khz
	 */
	ADCSRA |= (1<<ADEN);
	switch (config_ptr->voltage_ref)
	{
	case 0:
		CLEAR_BIT (ADMUX , REFS0); /*working with AREF */
		CLEAR_BIT (ADMUX , REFS0);
		break ;

	case 1:
		SET_BIT (ADMUX , REFS0); /*working with AVCC */
		break ;

	case 2:
        #warning "Reserved" ;
		break;

	case 3:
		SET_BIT (ADMUX , REFS1); /*working with internal voltage 2.56 */
		SET_BIT (ADMUX , REFS0);
		break;
	}


	switch (config_ptr->Prescale)
	{
	case Prescale_2: /* to choose ADC_Clock = F_CPU/2  */
	break;

	case Prescale_4:   /* to choose ADC_Clock = F_CPU/4   */
		SET_BIT (ADCSRA , ADPS1);
		break;

	case Prescale_8:  /* to choose ADC_Clock = F_CPU/8   */
		SET_BIT (ADCSRA , ADPS1);
		SET_BIT (ADCSRA , ADPS0);
		break;

	case Prescale_16: /* to choose ADC_Clock = F_CPU/16   */
			SET_BIT (ADCSRA , ADPS2);
			break;

	case Prescale_32: /* to choose ADC_Clock = F_CPU/32   */
		SET_BIT (ADCSRA , ADPS2);
		SET_BIT (ADCSRA , ADPS0);
		break;

	case Prescale_64: /* to choose ADC_Clock = F_CPU/64   */
		SET_BIT (ADCSRA , ADPS2);
		SET_BIT (ADCSRA , ADPS1);
		break;

	case Prescale_128: /* to choose ADC_Clock = F_CPU/128   */
		SET_BIT (ADCSRA , ADPS2);
		SET_BIT (ADCSRA , ADPS1);
		SET_BIT (ADCSRA , ADPS0);
		break;

	}
}

uint16 ADC_readchannel (uint8 ch_channel)
{
	ADMUX = (ADMUX & 0XE0) | (ch_channel & 0x1F);
	SET_BIT (ADCSRA,ADSC);       /* Start conversion write '1' to ADSC */

	while (BIT_IS_CLEAR(ADCSRA,ADIF))   /* Wait for conversion to complete, ADIF becomes '1' */
	{

	}
	SET_BIT (ADCSRA,ADIF);  /* Wait for conversion to complete, ADIF becomes '1' */
	return ADC;          /* Wait for conversion to complete, ADIF becomes '1' */
}

