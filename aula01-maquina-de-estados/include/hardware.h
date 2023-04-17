/**
 * hardware.h
 *
 *  @date Created at:	17/04/2023 14:56:12
 *	@author:	Pedro Igor B. S.
 *	@email:		pibscontato@gmail.com
 * 	GitHub:		https://github.com/pedro-ibs
 * 	tabSize:	8
 *
 * #######################################################################
 *
 *   Copyright (C) Pedro Igor B. S 2021
 * -------------------------------------------------------------------
 *
 *   Licença: GNU GPL 2
 * -------------------------------------------------------------------
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License as
 *   published by the Free Software Foundation; version 2 of the
 *   License.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 * -------------------------------------------------------------------
 * #######################################################################
 * 
 * Definições de hardware da shield edu
 *
 */

/* Includes ---------------------------------------------------------------------------------------------------------------------------------------------*/
#include <Arduino.h>


#ifndef hardware_H_
#define hardware_H_

/* settings ----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Definition --------------------------------------------------------------------------------------------------------------------------------------------*/




/* ************************************************************************************************************ */
/* hardware sem acesso externo											*/
/* ************************************************************************************************************ */
#define    LCD_PIN_LED_A       	( 13			)		// LCD 7 SEGMENTO A OU LED A
#define    LCD_PIN_LED_B       	( 12			)		// LCD 7 SEGMENTO B OU LED B, DISPLAY 16X2 D7
#define    LCD_PIN_LED_C       	( 11			)		// LCD 7 SEGMENTO C OU LED C, DISPLAY 16X2 D6
#define    LCD_PIN_LED_D       	( 5			)		// LCD 7 SEGMENTO D OU LED D, DISPLAY 16X2 D5
#define    LCD_PIN_LED_E       	( 4			)		// LCD 7 SEGMENTO E OU LED E, DISPLAY 16X2 D4
#define    LCD_PIN_LED_F       	( 3			)		// LCD 7 SEGMENTO F OU LED F, DISPLAY 16X2 E
#define    LCD_PIN_LED_G       	( 2			)		// LCD 7 SEGMENTO G OU LED G, DISPLAY 16X2 RS

#define    POT_PIN		( A1			)		// ADC1, POTENCIÔMETRO

#define    BT1_PIN		( A0			)		// BOTÃO COM TRAVA
#define    BT2_PIN		( 7			)		// BOTÃO 1
#define    BT3_PIN		( 8			)		// BOTÃO 2

/* ************************************************************************************************************ */
/* hardware com acesso externo											*/
/* ************************************************************************************************************ */
#define    ADC2_BORNE_PIN	( A2			)		// BORNE
#define    ADC3_BORNE_PIN	( A3			)		// BORNE
#define    ADC4_BORNE_PIN	( A4			)		// BORNE
#define    ADC5_BORNE_PIN	( A5			)		// BORNE
#define    ADC6_BORNE_PIN	( A6			)		// BUZZER OU BORNE ( PWM6 )

#define    BUZZER_PIN		( ADC6_BORNE_PIN	)		// BUZZER OU BORNE ( PWM6 )
#define    MOTOR1_PIN   	( 9			)		// BORNE (BC548 - VCC BATERIA E COLETOR)
#define    MOTOR2_PIN   	( 10			)		// BORNE (BC548 - VCC BATERIA E COLETOR)

#endif /* hardware_H_ */
