# Project Objective

The objective of this project is to design a temperature-controlled fan system using an ATmega32 microcontroller and an LM35 temperature sensor. The system will monitor the temperature and adjust the fan speed accordingly, displaying both the temperature and fan state on an LCD.

## Project Components

The project involves the following components:
- ADC
- GPIO
- LCD
- Temperature Sensor
- DC-Motor
- PWM drivers

Each component has specific requirements and specifications, including reference voltage, prescaler, data mode, and pin configurations.

## Project Logic

The project logic follows these steps:
1. The LM35 temperature sensor provides continuous analog output corresponding to the temperature, which is converted to digital by the ADC.
2. The microcontroller performs calculations to determine the temperature from the digital output and displays it on the LCD.
3. The microcontroller continuously monitors the temperature and adjusts the fan speed using PWM signals to control the DC-Motor speed.
4. The fan operates in five states based on temperature ranges: off, 25%, 50%, 75%, and 100% of its maximum speed.

## Project Architecture

The project should be designed and implemented based on a layered architecture model. Each component, including drivers, should have its own set of functions and inputs to ensure modularity and scalability.
