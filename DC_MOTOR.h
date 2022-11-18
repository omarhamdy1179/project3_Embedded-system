/*
 * DC_MOTOR.h
 *
 *  Created on: Oct 7, 2022
 *      Author: omar hamdii
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "std_types.h"

typedef enum
{
DC_OFF,DC_CW ,DC_A_CW

}DcMotor_State;


/*
 * Description :
 * Initialize the Motor:
 * The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 * stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void);



/*
 * Description :
 * Initialize the Motor:
 * The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate (DcMotor_State state , uint8 speed) ;


void TEMP_VS_MOTOR (uint8 TEMP);



#endif /* DC_MOTOR_H_ */
