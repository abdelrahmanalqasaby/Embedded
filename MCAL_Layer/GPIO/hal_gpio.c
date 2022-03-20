/*
 * hal_gpio.c
 *
 *  Created on: Mar 16, 2022
 *      Author: ACER
 */

#include "hal_gpio.h"

/*Refrence for direction control register  */
volatile uint8 *ddr_registers[] = {&DDRA, &DDRB, &DDRC, &DDRD};
/*Refrence for reading status register  */
volatile uint8 *pin_registers[] = {&PINA, &PINB, &PINC, &PIND};
/*Refrence for output data register  */
volatile uint8 *port_registers[] = {&PORTA, &PORTB, &PORTC, &PORTD};


#if PORT_PIN_CONFIGURATAION == CONFIG_ENABLE
Std_ReturnType gpio_pin_direction_init(const pin_config * pin_config)
{
	Std_ReturnType ret = E_Ok;

	if (NULL==pin_config || pin_config->pin > PORT_PIN_MAX_NUMBER-1)
	{
		ret = E_Not_Ok;
	}
	else
	{
		switch (pin_config->direction)
		{
			case GPIO_OUTPUT :
				CLEAR_BIT(*ddr_registers[pin_config->port],pin_config->pin);
				break;

			case GPIO_INPUT :
				SET_BIT(*ddr_registers[pin_config->port],pin_config->pin);
				break;

			default : ret= E_Not_Ok;
		}
	}
	return ret;
}

#endif

#if PORT_PIN_CONFIGURATAION == CONFIG_ENABLE

Std_ReturnType gpio_pin_get_direction_status(const pin_config * pin_config, direction * ddr_status)
{
	Std_ReturnType ret = E_Ok;

	if (NULL==pin_config || pin_config->pin > PORT_PIN_MAX_NUMBER-1 || NULL==ddr_status)
	{
		ret = E_Not_Ok;
	}
	else
	{
		*ddr_status = READ_BIT(*ddr_registers[pin_config->port],pin_config->pin);
	}
	return ret;
}

#endif

#if PORT_PIN_CONFIGURATAION == CONFIG_ENABLE

Std_ReturnType gpio_pin_write_logic(const pin_config * pin_config, logic _logic)
{
	Std_ReturnType ret = E_Ok;

	if (NULL==pin_config || pin_config->pin > PORT_PIN_MAX_NUMBER-1)
	{
		ret = E_Not_Ok;
	}
	else
	{
		switch (_logic)
		{
			case GPIO_LOW :
				CLEAR_BIT(*port_registers[pin_config->port],pin_config->pin);
				break;
			case GPIO_HIGH :
				SET_BIT(*port_registers[pin_config->port],pin_config->pin);
				break;
			default : ret= E_Not_Ok;
		}
	}
	return ret;

}

#endif

#if PORT_PIN_CONFIGURATAION == CONFIG_ENABLE

Std_ReturnType gpio_pin_read_logic(const pin_config * pin_config, logic * _logic)
{
	Std_ReturnType ret = E_Ok;

	if (NULL==pin_config || NULL==_logic || pin_config->pin > PORT_PIN_MAX_NUMBER-1)
	{
		ret = E_Not_Ok;
	}
	else
	{
		*_logic = READ_BIT(*pin_registers[pin_config->port],pin_config->pin);
	}
	return ret;
}

#endif

#if PORT_PIN_CONFIGURATAION == CONFIG_ENABLE

Std_ReturnType gpio_pin_toggle_logic(const pin_config * pin_config)
{
	Std_ReturnType ret = E_Ok;

	if (NULL==pin_config || pin_config->pin > PORT_PIN_MAX_NUMBER-1)
	{
		ret = E_Not_Ok;
	}
	else
	{
		TOGGLE_BIT(*port_registers[pin_config->port],pin_config->pin);
	}
	return ret;
}

#endif

#if PORT_PIN_CONFIGURATAION == CONFIG_ENABLE

Std_ReturnType gpio_pin_init(const pin_config * pin_config)
{
	Std_ReturnType ret = E_Ok;

	if (NULL==pin_config || pin_config->pin > PORT_PIN_MAX_NUMBER-1)
	{
		ret = E_Not_Ok;
	}
	else
	{
		ret = gpio_pin_direction_init(pin_config);
		ret = gpio_pin_write_logic(pin_config,pin_config->logic);
	}
	return ret;
}

#endif

#if PORT_CONFIGURATAION == CONFIG_ENABLE

Std_ReturnType gpio_port_direction_init(port_index port, uint8 direction)
{
	Std_ReturnType ret = E_Ok;

	if (port > PORT_MAX_NUMBER-1)
	{
		ret = E_Not_Ok;
	}
	else
	{
		*ddr_registers[port] = direction;
	}
	return ret;
}

#endif

#if PORT_CONFIGURATAION == CONFIG_ENABLE

Std_ReturnType gpio_port_get_direction_status(port_index port, uint8 * ddr_status)
{
	Std_ReturnType ret = E_Ok;

	if (NULL == ddr_status || port > PORT_MAX_NUMBER-1)
	{
		ret = E_Not_Ok;
	}
	else
	{
		*ddr_status = *ddr_registers[port];
	}
	return ret;
}

#endif

#if PORT_CONFIGURATAION == CONFIG_ENABLE

Std_ReturnType gpio_port_write_logic(port_index port, uint8  _logic)
{
	Std_ReturnType ret = E_Ok;

	if (port > PORT_MAX_NUMBER-1)
	{
		ret = E_Not_Ok;
	}
	else
	{
		*port_registers[port] = _logic;
	}
	return ret;
}

#endif

#if PORT_CONFIGURATAION == CONFIG_ENABLE

Std_ReturnType gpio_port_read_logic(port_index port, uint8 *_logic)
{
	Std_ReturnType ret = E_Ok;

		if (NULL==_logic || port > PORT_MAX_NUMBER-1)
		{
			ret = E_Not_Ok;
		}
		else
		{
			*_logic = *pin_registers[port] ;
		}
		return ret;
}
#endif

#if PORT_CONFIGURATAION == CONFIG_ENABLE

Std_ReturnType gpio_port_toggle_logic(port_index port)
{
	Std_ReturnType ret = E_Ok;

		if ( port > PORT_MAX_NUMBER-1)
		{
			ret = E_Not_Ok;
		}
		else
		{
			*port_registers[port] ^= PORT_MASK ;
		}
		return ret;
}
#endif


