/*
 * ADC.h
 *
 *  Created on: Oct 4, 2022
 *  Author: omar hamdii
 */

#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"

#define ADC_MAXIMUM_VALUE      1023
#define ADC_REF_VOLT_VALUE     2.56


typedef enum
{
ADMUX_AREF , ADMUX_AVCC, ADMUX_reserved, ADMUX_internal_voltage
}ADC_voltage;



typedef enum
{
Prescale_2, Prescale_4, Prescale_8, Prescale_16, Prescale_32 ,Prescale_64,Prescale_128
}ADC_prescale;



typedef struct
{
	ADC_voltage voltage_ref ;
	ADC_prescale  Prescale;
}ADC_ConfigType;


// #define SENSOR_CHANNEL_ID      2

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init (const ADC_ConfigType* config_ptr );


/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readchannel (uint8 ch_channel);


#endif /* ADC_H_ */
