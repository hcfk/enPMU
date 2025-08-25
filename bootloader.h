/**
  ******************************************************************************
  * STM32 Bootloader
  ******************************************************************************
  * @author		Asim Ahmed Demir
  * @file		bootloader.h
  * @version	V1.0
  * @date		16.02.2018
  * @brief 		STM32 internal Bootloader implementation
  *	        	This file contains the functions of the bootloader.
  *				The bootloader implementation uses the official HAL library.
  * @see		Don't change anything without reading the Bootloader document!
  ******************************************************************************
  * Copyright (c) 2018 Endoks Embedded.						 https://endoks.com/
  ******************************************************************************
**/

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

/* Definitions ---------------------------------------------------------------*/
#define SYSMEM_ADDRESS	(uint32_t)0x1FFF0000
#define MSP_ADDRESS		(uint32_t)0x20001D80

/* Typedefs Structs ----------------------------------------------------------*/
typedef struct
{	
	bool		bootModeTrigger;
} Typedef_bootParams;

/* Extern --------------------------------------------------------------------*/
extern Typedef_bootParams bootParams;

/* Function Prototypes -------------------------------------------------------*/
void Bootloader_JumpToSysMem(void);
void Bootloader_CheckTrigger(void);
