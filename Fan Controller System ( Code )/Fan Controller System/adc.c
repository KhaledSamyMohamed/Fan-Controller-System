 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ADC driver
 *
 * Author: Khaled Samy
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the AVR Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/* ADMUX Register Bits Description:
	 * Bit 7:6 – REFS1:0: Reference Selection Bits
	 * Bit 5 – ADLAR: ADC Left Adjust Result (1 -> Left) | (0 -> Right)
	 * Bits 4:0 – MUX4:0: Analog Channel (MUX4:0 = 0000 -> channel 0 in Initialize)
	 */
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->ref_volt) << 6);

	/* ADCSRA Register Bits Description:
	 * Bit 7 – ADEN: ADC Enable (1 -> Enable)
	 * Bit 6 – ADSC: ADC Start Conversion (1 -> in ADC_readChannel to Start Conversion)
	 * Bit 5 – ADATE: ADC Auto Trigger Enable (0 -> Disable Auto Trigger)
	 * Bit 4 – ADIF: ADC Interrupt Flag
	 * Bit 3 – ADIE: ADC Interrupt Enable (0 -> Disable ADC Interrupt)
	 * Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits
	 */
	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr->prescaler) | (1<<ADEN);
}

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num)
{
	ADMUX = (ADMUX & 0xE0) | (channel_num); /* Clear first 5 bits (MUX4:0 bits) and  set the the channel number */
	SET_BIT(ADCSRA,ADSC); /* (1 -> Start Conversion) */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Polling Until ADIF becomes -> 1 */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF -> 1) */
	return ADC; /* Read the digital value from ADC register */
}
