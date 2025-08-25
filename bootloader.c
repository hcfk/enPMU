/**
  ******************************************************************************
  * STM32 Bootloader
  ******************************************************************************
  * @author		Asim Ahmed Demir
  * @file		bootloader.c
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
#include "bootloader.h"

/* Private typedef -----------------------------------------------------------*/
Typedef_bootParams bootParams;
typedef void (*pFunction)(void);

/* Functions -----------------------------------------------------------------*/
/**
  * @brief 		This function is used for trigger ST's internal bootloader memory
  * @note		After calling this function, bootloader will be triggered.
  *				Before jumping to System Memory Boot Mode, clock settings has to be reset.
  *				Everything about the system memory boot mode can be found on AN2606.
  * @param 		None
  * @retval		None
  */
void Bootloader_JumpToSysMem(void)
{
	if (bootParams.bootModeTrigger)
	{
		/* bootloader triggered */
		*((unsigned long *)0x20003FF0) = 0x0000BBBB;
		NVIC_SystemReset();		
		/* go System_Init() */
	}
}

/* Functions -----------------------------------------------------------------*/
/**
  * @brief 		This function is used for checking bootloader triggers
  * @note		The bootloader can be triggered in two ways.
  *				- with a flag on SD-card (USB_BOOTLOADER_MODE).
  *				- with IEC-104 command (USB_BOOTLOADER_104_ADDR).
  * @param 		None
  * @retval		None
  */
void Bootloader_CheckTrigger(void)
{
	if (bootParams.bootModeTrigger)
	{
		Bootloader_JumpToSysMem();
	}
}
