/*
 * Timer0.h
 *
 *  Created on: Oct 7, 2022
 *      Author: omar hamdii
 */

#ifndef TIMER0_H_
#define TIMER0_H_
#include <avr/io.h>
#include "std_types.h"
#include "gpio.h"
#include "common_macros.h"


void PWM_Timer0_Init (uint8 duty_cycle) ;

#endif /* TIMER0_H_ */
