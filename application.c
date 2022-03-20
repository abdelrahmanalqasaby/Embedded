/*
 * main.c
 *
 *  Created on: Oct 11, 2018
 *      Author: ACER
 */
/*  section : Includes      */
#include <avr/io.h>
#include "application.h"

pin_config led_1={
		.port = PORTC_INDEX,
		.pin = PIN6_INDEX,
		.direction = GPIO_OUTPUT,
		.logic = GPIO_LOW
};
pin_config led_2={
		.port = PORTC_INDEX,
		.pin = PIN7_INDEX,
		.direction = GPIO_OUTPUT,
		.logic = GPIO_LOW
};
pin_config led_3={
		.port = PORTA_INDEX,
		.pin = PIN2_INDEX,
		.direction = GPIO_OUTPUT,
		.logic = GPIO_LOW
};

Std_ReturnType ret= E_Not_Ok;

/*  Section : Macro Declarations */

/*  Section : Macro Functions  */

/*  Section : Data Types Declaration  */

/*  Section : Functions  */
int main()
{
	ret= gpio_pin_init(&led_1);
	ret= gpio_pin_init(&led_2);
	ret= gpio_pin_init(&led_3);





	return 0;
}
