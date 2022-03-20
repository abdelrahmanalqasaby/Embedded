/*
 * mcal_std_types.h
 *
 *  Created on: Mar 16, 2022
 *      Author: ACER
 */

#ifndef MCAL_STD_TYPES_H_
#define MCAL_STD_TYPES_H_

/*  section : Includes      */

/*  Section : Data Types Declaration  */

typedef unsigned char		uint8;
typedef unsigned short		uint16;
typedef unsigned long		uint32;
typedef signed char			sint8;
typedef signed short		sint16;
typedef signed long			sint32;
typedef float				fp32;
typedef double				fp64;

typedef uint8 Std_ReturnType;

/*  Section : Macro Declarations */
#define STD_HIGH		0x01
#define STD_LOW			0x00

#define CONFIG_ENABLE   0x01
#define CONFIG_DISABLE	0x00

#define STD_ON			0x01
#define STD_OFF			0x00

#define STD_ACTIVE		0x01
#define STD_IDLE		0x00

#define E_Ok			(Std_ReturnType)0x01
#define E_Not_Ok		(Std_ReturnType)0x00

/*  Section : Macro Functions Declarations */



/*  Section : Functions  */

#endif /* MCAL_STD_TYPES_H_ */
