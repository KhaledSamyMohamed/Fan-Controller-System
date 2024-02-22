 /******************************************************************************
 *
 * Module: DCMotor
 *
 * File Name: dcmotor.h
 *
 * Description: Header file for the DC-Motor driver
 *
 * Author: Khaled Samy
 *
 *******************************************************************************/

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
	STOP,CLOCKWISE,ANTI_CLOCKWISE
}DcMotor_State;

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* DcMotor HW Ports and Pins Ids */
#define DcMotor_Pin0_PORT_ID           PORTB_ID
#define DcMotor_Pin0_PIN_ID            PIN0_ID

#define DcMotor_Pin1_PORT_ID           PORTB_ID
#define DcMotor_Pin1_PIN_ID            PIN1_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for setup the direction for the two motor pins and stop at the DC-Motor at the beginning.
 */
void DcMotor_Init(void);

/*
 * Description :
 * Function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value
 * and send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DCMOTOR_H_ */
