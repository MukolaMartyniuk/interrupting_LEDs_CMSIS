# Interrupting LEDs CMSIS

## Description
An application for switching LEDs using the User button. Implemented in the CMSIS library. The STM32F411E DISCO board was used for the application.

## Hardware requirements
+ STM32F411E DISCO

## Software requirements
+ Programming language C
+ Keil uVision 5

## Instructions for use
To work with the application, you need to download it and open interrupting_LEDs.uvprojx in Keil uVision. After that, run the program, the green LED on the board will light up. When the user button is pressed, the LED will change to red. Pins PD12-PD15 are responsible for LEDs. PD12 - green, PD13 - yellow, PD14 - red, PD15 - blue.

## The result of the program
![LED_ON](https://github.com/MukolaMartyniuk/interrupting_LEDs_CMSIS/blob/main/images/LED_ON.jpeg)
____
![LED_OFF](https://github.com/MukolaMartyniuk/interrupting_LEDs_CMSIS/blob/main/images/LED_OFF.jpeg)
