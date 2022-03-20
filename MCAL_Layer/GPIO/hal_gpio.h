/*
 * hal_gpio.h
 *
 *  Created on: Mar 16, 2022
 *      Author: ACER
 */

#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_

/*  section : Includes      */
#include "../mcal_std_types.h"
#include <stdlib.h>
#include <avr/io.h>



/*  Section : Macro Declarations */
#define BIT_MASK				(uint8)1
#define PORT_MASK				0xFF

#define PORT_PIN_MAX_NUMBER		8
#define PORT_MAX_NUMBER			4

/*  Section : Macro Functions Declarations */

#define HWREG(_X)					(*((volatile uint8 *)(_X)))

#define SET_BIT(REG, BIT_POS)		(REG |= (BIT_MASK << BIT_POS))
#define CLEAR_BIT(REG, BIT_POS)		(REG &= ~ (BIT_MASK << BIT_POS))
#define TOGGLE_BIT(REG, BIT_POS)	(REG ^= (BIT_MASK << BIT_POS))
#define READ_BIT(REG, BIT_POS)		((REG >> BIT_POS) & BIT_MASK)

#define PORT_PIN_CONFIGURATAION		CONFIG_ENABLE
#define PORT_CONFIGURATAION		CONFIG_ENABLE


/*  Section : Data Types Declarations  */

typedef enum{
	GPIO_LOW = 0,
	GPIO_HIGH
}logic;

typedef enum{
	GPIO_OUTPUT = 0,
	GPIO_INPUT
}direction;

typedef enum{
	PIN0_INDEX = 0,
	PIN1_INDEX,
	PIN2_INDEX,
	PIN3_INDEX,
	PIN4_INDEX,
	PIN5_INDEX,
	PIN6_INDEX,
	PIN7_INDEX
}pin_index;

typedef enum{
	PORTA_INDEX = 0,
	PORTB_INDEX,
	PORTC_INDEX,
	PORTD_INDEX
}port_index;

typedef struct {
	uint8 port : 2;
	uint8 pin : 3;
	uint8 direction : 1;
	uint8 logic : 1;
} pin_config ;


/*  Section : Functions Declarations  */

Std_ReturnType gpio_pin_direction_init(const pin_config * pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pin_config * pin_config, direction * drr_status);
Std_ReturnType gpio_pin_write_logic(const pin_config * pin_config, logic  _logic);
Std_ReturnType gpio_pin_read_logic(const pin_config * pin_config, logic * _logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config * pin_config);
Std_ReturnType gpio_pin_init(const pin_config * pin_config);


Std_ReturnType gpio_port_direction_init(port_index port, uint8 direction);
Std_ReturnType gpio_port_get_direction_status(port_index port, uint8 * drr_status);
Std_ReturnType gpio_port_write_logic(port_index port, uint8  _logic);
Std_ReturnType gpio_port_read_logic(port_index port, uint8 *_logic);
Std_ReturnType gpio_port_toggle_logic(port_index port);








#endif /* HAL_GPIO_H_ */
