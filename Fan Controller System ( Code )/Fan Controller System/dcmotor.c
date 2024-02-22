/******************************************************************************
 *
 * Module: DC-Motor
 *
 * File Name: DC_Motor.c
 *
 * Description: Source file for the DC-Motor driver
 *
 * Author: Khaled Samy
 *
 *******************************************************************************/

#include "dcmotor.h"
#include "gpio.h"
#include "pwm.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for setup the direction for the two motor pins and stop at the DC-Motor at the beginning.
 */
void DcMotor_Init(void) {
	/* DC-Motor 2 output pins */
	GPIO_setupPinDirection(DcMotor_Pin0_PORT_ID, DcMotor_Pin0_PIN_ID,
			PIN_OUTPUT);
	GPIO_setupPinDirection(DcMotor_Pin1_PORT_ID, DcMotor_Pin1_PIN_ID,
			PIN_OUTPUT);

	/* Stop the DC-Motor at the beginning */
	GPIO_writePin(DcMotor_Pin0_PORT_ID, DcMotor_Pin0_PIN_ID, LOGIC_LOW);
	GPIO_writePin(DcMotor_Pin1_PORT_ID, DcMotor_Pin1_PIN_ID, LOGIC_LOW);
}

/*
 * Description :
 * Function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value
 * and send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed) {
	uint8 duty_cycle;

	/*
	 * Write on the DC-Motor pins
	 * Set direction of motor based on state-
	 * */

	switch (state) {
	case CLOCKWISE:
		// Rotate motor clockwise
		GPIO_writePin(DcMotor_Pin0_PORT_ID, DcMotor_Pin0_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(DcMotor_Pin1_PORT_ID, DcMotor_Pin1_PIN_ID, LOGIC_LOW);
		break;
	case ANTI_CLOCKWISE:
		// Rotate motor anti-clockwise
		GPIO_writePin(DcMotor_Pin0_PORT_ID, DcMotor_Pin0_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DcMotor_Pin1_PORT_ID, DcMotor_Pin1_PIN_ID, LOGIC_HIGH);
		break;
	case STOP:
		// Stop the motor
		GPIO_writePin(DcMotor_Pin0_PORT_ID, DcMotor_Pin0_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DcMotor_Pin1_PORT_ID, DcMotor_Pin1_PIN_ID, LOGIC_LOW);
		break;
	default:
		// Invalid motor state
		return;
	}
//	/* Write on the DC-Motor pins */
//	GPIO_writePin(PORTB_ID, PIN0_ID, (state & 0x01));
//	GPIO_writePin(PORTB_ID, PIN1_ID, ((state >> 1) & 0x01));
	/*Calculate the Duty Cycle and send it to the PWM Driver*/
	duty_cycle = ((uint8) (((uint16) (speed * TOP)) / 100));
	PWM_Timer0_Start(duty_cycle);
}

