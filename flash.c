/**
  ******************************************************************************
  * @file    FLASH/FLASH_EraseProgram/Src/main.c
  * @author  MCD Application Team
  * @version V1.2.6
  * @date    06-May-2016
  * @brief   This example provides a description of how to erase and program the
  *          STM32F4xx FLASH.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "flash.h"
#include "string.h"
/* User Specific Includes ----------------------------------------------------*/
#include "Modbus_RTU_Slave.h"
#include "PQ_Calculation.h"
#include "ADC_Process.h"
#include "Watchdog.h"
/** @addtogroup STM32F4xx_HAL_Examples
  * @{
  */

/** @addtogroup FLASH_Program
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define FLASH_USER_START_ADDR   ADDR_FLASH_SECTOR_5 /* Start @ of user Flash area */
#define FLASH_USER_END_ADDR     ADDR_FLASH_SECTOR_5  +  GetSectorSize(ADDR_FLASH_SECTOR_5) -1 /* End @ of user Flash area : sector start address + sector size -1 */

#define DATA_32                 ((uint32_t)0x12345678)

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t FirstSector = 0, NbOfSectors = 0, Address = 0;
uint32_t SectorError = 0;
__IO uint32_t data32 = 0 , MemoryProgramStatus = 0;

/*Variable used for Erase procedure*/
static FLASH_EraseInitTypeDef EraseInitStruct;

/* Private function prototypes -----------------------------------------------*/
static uint32_t GetSector(uint32_t Address);
static uint32_t GetSectorSize(uint32_t Sector);



/* Private functions ---------------------------------------------------------*/
Typedef_flashParams flashParamsWrite;
Typedef_flashParams flashParamsRead;

/**
  * @brief  Gets the sector of a given address
  * @param  None
  * @retval The sector of a given address
  */
static uint32_t GetSector(uint32_t Address)
{
  uint32_t sector = 0;

  if((Address < ADDR_FLASH_SECTOR_1) && (Address >= ADDR_FLASH_SECTOR_0))
  {
    sector = FLASH_SECTOR_0;
  }
  else if((Address < ADDR_FLASH_SECTOR_2) && (Address >= ADDR_FLASH_SECTOR_1))
  {
    sector = FLASH_SECTOR_1;
  }
  else if((Address < ADDR_FLASH_SECTOR_3) && (Address >= ADDR_FLASH_SECTOR_2))
  {
    sector = FLASH_SECTOR_2;
  }
  else if((Address < ADDR_FLASH_SECTOR_4) && (Address >= ADDR_FLASH_SECTOR_3))
  {
    sector = FLASH_SECTOR_3;
  }
  else if((Address < ADDR_FLASH_SECTOR_5) && (Address >= ADDR_FLASH_SECTOR_4))
  {
    sector = FLASH_SECTOR_4;
  }
   else/*(Address < FLASH_END_ADDR) && (Address >= ADDR_FLASH_SECTOR_5))*/
  {
    sector = FLASH_SECTOR_5;
  }

  return sector;
}


/**
  * @brief  Gets sector Size
  * @param  None
  * @retval The size of a given sector
  */
static uint32_t GetSectorSize(uint32_t Sector)
{
  uint32_t sectorsize = 0x00;

  if((Sector == FLASH_SECTOR_0) || (Sector == FLASH_SECTOR_1) || (Sector == FLASH_SECTOR_2) || (Sector == FLASH_SECTOR_3))
  {
    sectorsize = 16 * 1024;
  }
  else if(Sector == FLASH_SECTOR_4)
  {
    sectorsize = 64 * 1024;
  }
  else
  {
    sectorsize = 128 * 1024;
  }
  return sectorsize;
}


void internalFlashWrite(void)
{
	  /* Unlock the Flash to enable the flash control register access *************/
  HAL_FLASH_Unlock();

  /* Erase the user Flash area
    (area defined by FLASH_USER_START_ADDR and FLASH_USER_END_ADDR) ***********/

  /* Get the 1st sector to erase */
  FirstSector = GetSector(FLASH_USER_START_ADDR);
  /* Get the number of sector to erase from 1st sector*/
  NbOfSectors = GetSector(FLASH_USER_END_ADDR) - FirstSector + 1;

  /* Fill EraseInit structure*/
  EraseInitStruct.TypeErase = FLASH_TYPEERASE_SECTORS;
  EraseInitStruct.VoltageRange = FLASH_VOLTAGE_RANGE_3;
  EraseInitStruct.Sector = FirstSector;
  EraseInitStruct.NbSectors = NbOfSectors;
  if(HAL_FLASHEx_Erase(&EraseInitStruct, &SectorError) != HAL_OK)
  {
    /*
      Error occurred while sector erase.
      User can add here some code to deal with this error.
      SectorError will contain the faulty sector and then to know the code error on this sector,
      user can call function 'HAL_FLASH_GetError()'
    */
    /*
      FLASH_ErrorTypeDef errorcode = HAL_FLASH_GetError();
    */
  }

  __HAL_FLASH_DATA_CACHE_DISABLE();
  __HAL_FLASH_INSTRUCTION_CACHE_DISABLE();

  __HAL_FLASH_DATA_CACHE_RESET();
  __HAL_FLASH_INSTRUCTION_CACHE_RESET();

  __HAL_FLASH_INSTRUCTION_CACHE_ENABLE();
  __HAL_FLASH_DATA_CACHE_ENABLE();

  /* Program the user Flash area word by word
    (area defined by FLASH_USER_START_ADDR and FLASH_USER_END_ADDR) ***********/

  Address = FLASH_USER_START_ADDR;

		/****************************************** CH1 Energy Registers ***************************************************/
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder1_A_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }
		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder1_A_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder1_A_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder1_A_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
		/*************************************************************************************************************************/


    /****************************************** CH2 Energy Registers ***************************************************/
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder1_B_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }
		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder1_B_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder1_B_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder1_B_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
		/*************************************************************************************************************************/

    /****************************************** CH3 Energy Registers ***************************************************/
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder1_C_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder1_C_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder1_C_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder1_C_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    /*************************************************************************************************************************/

    /****************************************** CH4 Energy Registers ***************************************************/
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder2_A_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder2_A_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder2_A_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder2_A_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    /*************************************************************************************************************************/

    /****************************************** CH5 Energy Registers ***************************************************/
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder2_B_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder2_B_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder2_B_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder2_B_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    /*************************************************************************************************************************/

    /****************************************** CH6 Energy Registers ***************************************************/
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder2_C_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder2_C_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder2_C_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder2_C_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    /*************************************************************************************************************************/

    /****************************************** CH7 Energy Registers ***************************************************/
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder3_A_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder3_A_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder3_A_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder3_A_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    /*************************************************************************************************************************/

    /****************************************** CH8 Energy Registers ***************************************************/
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder3_B_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder3_B_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder3_B_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder3_B_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    /*************************************************************************************************************************/

    /****************************************** CH9 Energy Registers ***************************************************/
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder3_C_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder3_C_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder3_C_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder3_C_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    /*************************************************************************************************************************/

    /****************************************** CH7 Energy Registers ***************************************************/
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder4_A_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder4_A_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder4_A_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder4_A_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    /*************************************************************************************************************************/

    /****************************************** CH7 Energy Registers ***************************************************/
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder4_B_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder4_B_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder4_B_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder4_B_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    /*************************************************************************************************************************/

    /****************************************** CH7 Energy Registers ***************************************************/
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder4_C_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder4_C_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder4_C_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder4_C_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    /*************************************************************************************************************************/

    /****************************************** CH7 Energy Registers ***************************************************/
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder5_A_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder5_A_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder5_A_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder5_A_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    /*************************************************************************************************************************/

    /****************************************** CH7 Energy Registers ***************************************************/
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder5_B_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder5_B_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder5_B_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder5_B_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    /*************************************************************************************************************************/

    /****************************************** CH7 Energy Registers ***************************************************/
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder5_C_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Active.Feeder5_C_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder5_C_Import)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)Energy_Total.Reactive.Feeder5_C_Export)) == HAL_OK)
    {
      Address = Address + 4;
    }
    /*************************************************************************************************************************/


		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)deviceParams.uniqueID)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)modbusParams.deviceSlaveID[0])) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)modbusParams.deviceSlaveID[1])) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)modbusParams.deviceSlaveID[2])) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)modbusParams.deviceSlaveID[3])) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)modbusParams.deviceSlaveID[4])) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)modbusParams.deviceSlaveID[5])) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)modbusParams.deviceSlaveID[6])) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)modbusParams.deviceSlaveID[7])) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)modbusParams.deviceSlaveID[8])) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)modbusParams.deviceSlaveID[9])) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)modbusParams.deviceSlaveID[10])) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)modbusParams.deviceSlaveID[11])) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)modbusParams.deviceSlaveID[12])) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)modbusParams.deviceSlaveID[13])) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)modbusParams.deviceSlaveID[14])) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)deviceParams.baudRate)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)turnRatio.VCH1)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)turnRatio.ICH1)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)turnRatio.ICH2)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)turnRatio.ICH3)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)turnRatio.ICH4)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)turnRatio.ICH5)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)turnRatio.ICH6)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)turnRatio.ICH7)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)turnRatio.ICH8)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)turnRatio.ICH9)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)turnRatio.ICH10)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)turnRatio.ICH11)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)turnRatio.ICH12)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)turnRatio.ICH13)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)turnRatio.ICH14)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)turnRatio.ICH15)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)polarity.ICH1)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)polarity.ICH2)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)polarity.ICH3)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)polarity.ICH4)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)polarity.ICH5)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)polarity.ICH6)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)polarity.ICH7)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)polarity.ICH8)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)polarity.ICH9)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)polarity.ICH10)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)polarity.ICH11)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)polarity.ICH12)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)polarity.ICH13)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)polarity.ICH14)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)polarity.ICH15)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)channelReference.CH1)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)channelReference.CH2)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)channelReference.CH3)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)channelReference.CH4)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)channelReference.CH5)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)channelReference.CH6)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)channelReference.CH7)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)channelReference.CH8)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)channelReference.CH9)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)channelReference.CH10)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)channelReference.CH11)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)channelReference.CH12)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)channelReference.CH13)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)channelReference.CH14)) == HAL_OK)
    {
      Address = Address + 4;
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)channelReference.CH15)) == HAL_OK)
    {
      Address = Address + 4;
    }

		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)deviceParams.errorHandlerCounter)) == HAL_OK)
    {
      Address = Address + 4;
    }

	if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)0)) == HAL_OK)
    {
      Address = Address + 4;
    }
	
	if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)demandParams.feeder1)) == HAL_OK)
    {
      Address = Address + 4;
    }
	
	if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)demandParams.feeder2)) == HAL_OK)
    {
      Address = Address + 4;
    }
	
	if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)demandParams.feeder3)) == HAL_OK)
    {
      Address = Address + 4;
    }
	
	if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)demandParams.feeder4)) == HAL_OK)
    {
      Address = Address + 4;
    }
	
	if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, ((uint32_t)demandParams.feeder5)) == HAL_OK)
    {
      Address = Address + 4;
    }
	
	



  /* Lock the Flash to disable the flash control register access (recommended
     to protect the FLASH memory against possible unwanted operation) *********/
  HAL_FLASH_Lock();
}

void internalFlashRead(void)
{
	  /* Check if the programmed data is OK
      MemoryProgramStatus = 0: data programmed correctly
      MemoryProgramStatus != 0: number of words not programmed correctly ******/
  Address = FLASH_USER_START_ADDR;
  MemoryProgramStatus = 0x0;

    Energy_Total.Active.Feeder1_A_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Active.Feeder1_A_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder1_A_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder1_A_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;

    Energy_Total.Active.Feeder1_B_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Active.Feeder1_B_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder1_B_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder1_B_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;

    Energy_Total.Active.Feeder1_C_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Active.Feeder1_C_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder1_C_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder1_C_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;

    Energy_Total.Active.Feeder2_A_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Active.Feeder2_A_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder2_A_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder2_A_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;

    Energy_Total.Active.Feeder2_B_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Active.Feeder2_B_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder2_B_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder2_B_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;

    Energy_Total.Active.Feeder2_C_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Active.Feeder2_C_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder2_C_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder2_C_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;

    Energy_Total.Active.Feeder3_A_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Active.Feeder3_A_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder3_A_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder3_A_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;

    Energy_Total.Active.Feeder3_B_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Active.Feeder3_B_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder3_B_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder3_B_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;

    Energy_Total.Active.Feeder3_C_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Active.Feeder3_C_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder3_C_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder3_C_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;

    Energy_Total.Active.Feeder4_A_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Active.Feeder4_A_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder4_A_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder4_A_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;

    Energy_Total.Active.Feeder4_B_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Active.Feeder4_B_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder4_B_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder4_B_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;

    Energy_Total.Active.Feeder4_C_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Active.Feeder4_C_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder4_C_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder4_C_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;

    Energy_Total.Active.Feeder5_A_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Active.Feeder5_A_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder5_A_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder5_A_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;

    Energy_Total.Active.Feeder5_B_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Active.Feeder5_B_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder5_B_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder5_B_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;

    Energy_Total.Active.Feeder5_C_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Active.Feeder5_C_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder5_C_Import = *(__IO uint32_t*)Address;
    Address = Address + 4;
    Energy_Total.Reactive.Feeder5_C_Export = *(__IO uint32_t*)Address;
    Address = Address + 4;

	
	Energy_Total.Active.Feeder1_Import_TOT = Energy_Total.Active.Feeder1_A_Import +
                                         Energy_Total.Active.Feeder1_B_Import +
                                         Energy_Total.Active.Feeder1_C_Import;
Energy_Total.Active.Feeder2_Import_TOT = Energy_Total.Active.Feeder2_A_Import +
                                         Energy_Total.Active.Feeder2_B_Import +
                                         Energy_Total.Active.Feeder2_C_Import;
Energy_Total.Active.Feeder3_Import_TOT = Energy_Total.Active.Feeder3_A_Import +
                                         Energy_Total.Active.Feeder3_B_Import +
                                         Energy_Total.Active.Feeder3_C_Import;
Energy_Total.Active.Feeder4_Import_TOT = Energy_Total.Active.Feeder4_A_Import +
                                         Energy_Total.Active.Feeder4_B_Import +
                                         Energy_Total.Active.Feeder4_C_Import;
Energy_Total.Active.Feeder5_Import_TOT = Energy_Total.Active.Feeder5_A_Import +
                                         Energy_Total.Active.Feeder5_B_Import +
                                         Energy_Total.Active.Feeder5_C_Import;

 Energy_Total.Active.Feeder1_Export_TOT = Energy_Total.Active.Feeder1_A_Export +
                                          Energy_Total.Active.Feeder1_B_Export +
                                          Energy_Total.Active.Feeder1_C_Export;
 Energy_Total.Active.Feeder2_Export_TOT = Energy_Total.Active.Feeder2_A_Export +
                                          Energy_Total.Active.Feeder2_B_Export +
                                          Energy_Total.Active.Feeder2_C_Export;
 Energy_Total.Active.Feeder3_Export_TOT = Energy_Total.Active.Feeder3_A_Export +
                                          Energy_Total.Active.Feeder3_B_Export +
                                          Energy_Total.Active.Feeder3_C_Export;
 Energy_Total.Active.Feeder4_Export_TOT = Energy_Total.Active.Feeder4_A_Export +
                                          Energy_Total.Active.Feeder4_B_Export +
                                          Energy_Total.Active.Feeder4_C_Export;
 Energy_Total.Active.Feeder5_Export_TOT = Energy_Total.Active.Feeder5_A_Export +
                                          Energy_Total.Active.Feeder5_B_Export +
                                          Energy_Total.Active.Feeder5_C_Export;

Energy_Total.Reactive.Feeder1_Import_TOT = Energy_Total.Reactive.Feeder1_A_Import +
                                           Energy_Total.Reactive.Feeder1_B_Import +
                                           Energy_Total.Reactive.Feeder1_C_Import;
Energy_Total.Reactive.Feeder2_Import_TOT = Energy_Total.Reactive.Feeder2_A_Import +
                                           Energy_Total.Reactive.Feeder2_B_Import +
                                           Energy_Total.Reactive.Feeder2_C_Import;
Energy_Total.Reactive.Feeder3_Import_TOT = Energy_Total.Reactive.Feeder3_A_Import +
                                           Energy_Total.Reactive.Feeder3_B_Import +
                                           Energy_Total.Reactive.Feeder3_C_Import;
Energy_Total.Reactive.Feeder4_Import_TOT = Energy_Total.Reactive.Feeder4_A_Import +
                                           Energy_Total.Reactive.Feeder4_B_Import +
                                           Energy_Total.Reactive.Feeder4_C_Import;
Energy_Total.Reactive.Feeder5_Import_TOT = Energy_Total.Reactive.Feeder5_A_Import +
                                           Energy_Total.Reactive.Feeder5_B_Import +
                                           Energy_Total.Reactive.Feeder5_C_Import;

Energy_Total.Reactive.Feeder1_Export_TOT = Energy_Total.Reactive.Feeder1_A_Export +
                                           Energy_Total.Reactive.Feeder1_B_Export +
                                           Energy_Total.Reactive.Feeder1_C_Export;
Energy_Total.Reactive.Feeder2_Export_TOT = Energy_Total.Reactive.Feeder2_A_Export +
                                           Energy_Total.Reactive.Feeder2_B_Export +
                                           Energy_Total.Reactive.Feeder2_C_Export;
Energy_Total.Reactive.Feeder3_Export_TOT = Energy_Total.Reactive.Feeder3_A_Export +
                                           Energy_Total.Reactive.Feeder3_B_Export +
                                           Energy_Total.Reactive.Feeder3_C_Export;
Energy_Total.Reactive.Feeder4_Export_TOT = Energy_Total.Reactive.Feeder4_A_Export +
                                           Energy_Total.Reactive.Feeder4_B_Export +
                                           Energy_Total.Reactive.Feeder4_C_Export;
Energy_Total.Reactive.Feeder5_Export_TOT = Energy_Total.Reactive.Feeder5_A_Export +
                                           Energy_Total.Reactive.Feeder5_B_Export +
                                           Energy_Total.Reactive.Feeder5_C_Export;

		deviceParams.uniqueID = *(__IO uint32_t*)Address;
    Address = Address + 4;
		modbusParams.deviceSlaveID[0] = *(__IO uint32_t*)Address;
    Address = Address + 4;
		modbusParams.deviceSlaveID[1] = *(__IO uint32_t*)Address;
    Address = Address + 4;
		modbusParams.deviceSlaveID[2] = *(__IO uint32_t*)Address;
    Address = Address + 4;
		modbusParams.deviceSlaveID[3] = *(__IO uint32_t*)Address;
    Address = Address + 4;
		modbusParams.deviceSlaveID[4] = *(__IO uint32_t*)Address;
    Address = Address + 4;
    modbusParams.deviceSlaveID[5] = *(__IO uint32_t*)Address;
    Address = Address + 4;
    modbusParams.deviceSlaveID[6] = *(__IO uint32_t*)Address;
    Address = Address + 4;
    modbusParams.deviceSlaveID[7] = *(__IO uint32_t*)Address;
    Address = Address + 4;
    modbusParams.deviceSlaveID[8] = *(__IO uint32_t*)Address;
    Address = Address + 4;
    modbusParams.deviceSlaveID[9] = *(__IO uint32_t*)Address;
    Address = Address + 4;
    modbusParams.deviceSlaveID[10] = *(__IO uint32_t*)Address;
    Address = Address + 4;
    modbusParams.deviceSlaveID[11] = *(__IO uint32_t*)Address;
    Address = Address + 4;
    modbusParams.deviceSlaveID[12] = *(__IO uint32_t*)Address;
    Address = Address + 4;
    modbusParams.deviceSlaveID[13] = *(__IO uint32_t*)Address;
    Address = Address + 4;
    modbusParams.deviceSlaveID[14] = *(__IO uint32_t*)Address;
    Address = Address + 4;
    deviceParams.baudRate = *(__IO uint32_t*)Address;
    Address = Address + 4;
		turnRatio.VCH1 = *(__IO uint32_t*)Address;
    Address = Address + 4;
    turnRatio.VCH2 = turnRatio.VCH1;
    turnRatio.VCH3 = turnRatio.VCH1;
		turnRatio.ICH1 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		turnRatio.ICH2 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		turnRatio.ICH3 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		turnRatio.ICH4 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		turnRatio.ICH5 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		turnRatio.ICH6 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		turnRatio.ICH7 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		turnRatio.ICH8 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		turnRatio.ICH9 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		turnRatio.ICH10 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		turnRatio.ICH11 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		turnRatio.ICH12 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		turnRatio.ICH13 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		turnRatio.ICH14 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		turnRatio.ICH15 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		polarity.ICH1 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		polarity.ICH2 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		polarity.ICH3 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		polarity.ICH4 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		polarity.ICH5 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		polarity.ICH6 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		polarity.ICH7 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		polarity.ICH8 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		polarity.ICH9 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		polarity.ICH10 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		polarity.ICH11 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		polarity.ICH12 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		polarity.ICH13 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		polarity.ICH14 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		polarity.ICH15 = *(__IO uint32_t*)Address;
    Address = Address + 4;

    channelReference.CH1 = *(__IO uint32_t*)Address;
    Address = Address + 4;
    channelReference.CH2 = *(__IO uint32_t*)Address;
    Address = Address + 4;
    channelReference.CH3 = *(__IO uint32_t*)Address;
    Address = Address + 4;
    channelReference.CH4 = *(__IO uint32_t*)Address;
    Address = Address + 4;
    channelReference.CH5 = *(__IO uint32_t*)Address;
    Address = Address + 4;
    channelReference.CH6 = *(__IO uint32_t*)Address;
    Address = Address + 4;
    channelReference.CH7 = *(__IO uint32_t*)Address;
    Address = Address + 4;
    channelReference.CH8 = *(__IO uint32_t*)Address;
    Address = Address + 4;
    channelReference.CH9 = *(__IO uint32_t*)Address;
    Address = Address + 4;
    channelReference.CH10 = *(__IO uint32_t*)Address;
    Address = Address + 4;
    channelReference.CH11 = *(__IO uint32_t*)Address;
    Address = Address + 4;
    channelReference.CH12 = *(__IO uint32_t*)Address;
    Address = Address + 4;
    channelReference.CH13 = *(__IO uint32_t*)Address;
    Address = Address + 4;
    channelReference.CH14 = *(__IO uint32_t*)Address;
    Address = Address + 4;
    channelReference.CH15 = *(__IO uint32_t*)Address;
    Address = Address + 4;
		deviceParams.errorHandlerCounter = *(__IO uint32_t*)Address;
    Address = Address + 4;
		deviceParams.dummy2 = *(__IO uint32_t*)Address;
    Address = Address + 4;
	
	demandParams.feeder1 = *(__IO uint32_t*)Address;
    Address = Address + 4;
	
	demandParams.feeder2 = *(__IO uint32_t*)Address;
    Address = Address + 4;
	
	demandParams.feeder3 = *(__IO uint32_t*)Address;
    Address = Address + 4;
	
	demandParams.feeder4 = *(__IO uint32_t*)Address;
    Address = Address + 4;
	
	demandParams.feeder5 = *(__IO uint32_t*)Address;
    Address = Address + 4;
}


void pmu_loadDefaultSettings(void)
{
    Energy_Total.Active.Feeder1_A_Import = 0;
    Energy_Total.Active.Feeder1_A_Export = 0;
    Energy_Total.Reactive.Feeder1_A_Import = 0;
    Energy_Total.Reactive.Feeder1_A_Export = 0;

    Energy_Total.Active.Feeder1_B_Import = 0;
    Energy_Total.Active.Feeder1_B_Export = 0;
    Energy_Total.Reactive.Feeder1_B_Import = 0;
    Energy_Total.Reactive.Feeder1_B_Export = 0;

    Energy_Total.Active.Feeder1_C_Import = 0;
    Energy_Total.Active.Feeder1_C_Export = 0;
    Energy_Total.Reactive.Feeder1_C_Import = 0;
    Energy_Total.Reactive.Feeder1_C_Export = 0;

    Energy_Total.Active.Feeder2_A_Import = 0;
    Energy_Total.Active.Feeder2_A_Export = 0;
    Energy_Total.Reactive.Feeder2_A_Import = 0;
    Energy_Total.Reactive.Feeder2_A_Export = 0;

    Energy_Total.Active.Feeder2_B_Import = 0;
    Energy_Total.Active.Feeder2_B_Export = 0;
    Energy_Total.Reactive.Feeder2_B_Import = 0;
    Energy_Total.Reactive.Feeder2_B_Export = 0;

    Energy_Total.Active.Feeder2_C_Import = 0;
    Energy_Total.Active.Feeder2_C_Export = 0;
    Energy_Total.Reactive.Feeder2_C_Import = 0;
    Energy_Total.Reactive.Feeder2_C_Export = 0;

    Energy_Total.Active.Feeder3_A_Import = 0;
    Energy_Total.Active.Feeder3_A_Export = 0;
    Energy_Total.Reactive.Feeder3_A_Import = 0;
    Energy_Total.Reactive.Feeder3_A_Export = 0;

    Energy_Total.Active.Feeder3_B_Import = 0;
    Energy_Total.Active.Feeder3_B_Export = 0;
    Energy_Total.Reactive.Feeder3_B_Import = 0;
    Energy_Total.Reactive.Feeder3_B_Export = 0;

    Energy_Total.Active.Feeder3_C_Import = 0;
    Energy_Total.Active.Feeder3_C_Export = 0;
    Energy_Total.Reactive.Feeder3_C_Import = 0;
    Energy_Total.Reactive.Feeder3_C_Export = 0;

    Energy_Total.Active.Feeder4_A_Import = 0;
    Energy_Total.Active.Feeder4_A_Export = 0;
    Energy_Total.Reactive.Feeder4_A_Import = 0;
    Energy_Total.Reactive.Feeder4_A_Export = 0;

    Energy_Total.Active.Feeder4_B_Import = 0;
    Energy_Total.Active.Feeder4_B_Export = 0;
    Energy_Total.Reactive.Feeder4_B_Import = 0;
    Energy_Total.Reactive.Feeder4_B_Export = 0;

    Energy_Total.Active.Feeder4_C_Import = 0;
    Energy_Total.Active.Feeder4_C_Export = 0;
    Energy_Total.Reactive.Feeder4_C_Import = 0;
    Energy_Total.Reactive.Feeder4_C_Export = 0;

    Energy_Total.Active.Feeder5_A_Import = 0;
    Energy_Total.Active.Feeder5_A_Export = 0;
    Energy_Total.Reactive.Feeder5_A_Import = 0;
    Energy_Total.Reactive.Feeder5_A_Export = 0;

    Energy_Total.Active.Feeder5_B_Import = 0;
    Energy_Total.Active.Feeder5_B_Export = 0;
    Energy_Total.Reactive.Feeder5_B_Import = 0;
    Energy_Total.Reactive.Feeder5_B_Export = 0;

    Energy_Total.Active.Feeder5_C_Import = 0;
    Energy_Total.Active.Feeder5_C_Export = 0;
    Energy_Total.Reactive.Feeder5_C_Import = 0;
    Energy_Total.Reactive.Feeder5_C_Export = 0;

	  deviceParams.uniqueID = 0x31;

	  for (int i = 0; i < TOT_NUM_OF_INT_SLAVE_DEVICES; i++)
		{
			modbusParams.deviceSlaveID[i] = i+1;
		}

		deviceParams.baudRate = 3;
    turnRatio.VCH1 = 1;
    turnRatio.VCH2 = 1;
    turnRatio.VCH3 = 1;
		turnRatio.ICH1 = 1;
		turnRatio.ICH2 = 1;
		turnRatio.ICH3 = 1;
		turnRatio.ICH4 = 1;
		turnRatio.ICH5 = 1;
		turnRatio.ICH6 = 1;
		turnRatio.ICH7 = 1;
		turnRatio.ICH8 = 1;
		turnRatio.ICH9 = 1;
		turnRatio.ICH10 = 1;
		turnRatio.ICH11 = 1;
		turnRatio.ICH12 = 1;
		turnRatio.ICH13 = 1;
		turnRatio.ICH14 = 1;
		turnRatio.ICH15 = 1;
		polarity.VCH1 = 1;
    polarity.VCH2 = 1;
    polarity.VCH3 = 1;
		polarity.ICH1 = 1;
		polarity.ICH2 = 1;
		polarity.ICH3 = 1;
		polarity.ICH4 = 1;
		polarity.ICH5 = 1;
		polarity.ICH6 = 1;
		polarity.ICH7 = 1;
		polarity.ICH8 = 1;
		polarity.ICH9 = 1;
		polarity.ICH10 = 1;
		polarity.ICH11 = 1;
		polarity.ICH12 = 1;
		polarity.ICH13 = 1;
		polarity.ICH14 = 1;
		polarity.ICH15 = 1;

    channelReference.CH1  = VOLTAGE_REFERENCE_VCH1;
    channelReference.CH2  = VOLTAGE_REFERENCE_VCH2;
    channelReference.CH3  = VOLTAGE_REFERENCE_VCH3;
    channelReference.CH4  = VOLTAGE_REFERENCE_VCH1;
    channelReference.CH5  = VOLTAGE_REFERENCE_VCH2;
    channelReference.CH6  = VOLTAGE_REFERENCE_VCH3;
    channelReference.CH7  = VOLTAGE_REFERENCE_VCH1;
    channelReference.CH8  = VOLTAGE_REFERENCE_VCH2;
    channelReference.CH9  = VOLTAGE_REFERENCE_VCH3;
    channelReference.CH10 = VOLTAGE_REFERENCE_VCH1;
    channelReference.CH11 = VOLTAGE_REFERENCE_VCH2;
    channelReference.CH12 = VOLTAGE_REFERENCE_VCH3;
    channelReference.CH13 = VOLTAGE_REFERENCE_VCH1;
    channelReference.CH14 = VOLTAGE_REFERENCE_VCH2;
    channelReference.CH15 = VOLTAGE_REFERENCE_VCH3;
	
	demandParams.feeder1 = 0;
	demandParams.feeder2 = 0;
	demandParams.feeder3 = 0;
	demandParams.feeder4 = 0;
	demandParams.feeder5 = 0;

		  /* Unlock the Flash to enable the flash control register access *************/
  HAL_FLASH_Unlock();

  /* Erase the user Flash area
    (area defined by FLASH_USER_START_ADDR and FLASH_USER_END_ADDR) ***********/

  /* Get the 1st sector to erase */
  FirstSector = GetSector(FLASH_USER_START_ADDR);
  /* Get the number of sector to erase from 1st sector*/
  NbOfSectors = GetSector(FLASH_USER_END_ADDR) - FirstSector + 1;

  /* Fill EraseInit structure*/
  EraseInitStruct.TypeErase = FLASH_TYPEERASE_SECTORS;
  EraseInitStruct.VoltageRange = FLASH_VOLTAGE_RANGE_3;
  EraseInitStruct.Sector = FirstSector;
  EraseInitStruct.NbSectors = NbOfSectors;
  if(HAL_FLASHEx_Erase(&EraseInitStruct, &SectorError) != HAL_OK)
  {
    /*
      Error occurred while sector erase.
      User can add here some code to deal with this error.
      SectorError will contain the faulty sector and then to know the code error on this sector,
      user can call function 'HAL_FLASH_GetError()'
    */
    /*
      FLASH_ErrorTypeDef errorcode = HAL_FLASH_GetError();
    */
  }

  /* Note: If an erase operation in Flash memory also concerns data in the data or instruction cache,
     you have to make sure that these data are rewritten before they are accessed during code
     execution. If this cannot be done safely, it is recommended to flush the caches by setting the
     DCRST and ICRST bits in the FLASH_CR register. */
  __HAL_FLASH_DATA_CACHE_DISABLE();
  __HAL_FLASH_INSTRUCTION_CACHE_DISABLE();

  __HAL_FLASH_DATA_CACHE_RESET();
  __HAL_FLASH_INSTRUCTION_CACHE_RESET();

  __HAL_FLASH_INSTRUCTION_CACHE_ENABLE();
  __HAL_FLASH_DATA_CACHE_ENABLE();

  /* Program the user Flash area word by word
    (area defined by FLASH_USER_START_ADDR and FLASH_USER_END_ADDR) ***********/

  Address = FLASH_USER_START_ADDR;

  internalFlashWrite();

  /* Lock the Flash to disable the flash control register access (recommended
     to protect the FLASH memory against possible unwanted operation) *********/
  HAL_FLASH_Lock();
}

void pmu_paramInit(void)
{
	deviceParams.softwareReset = INACTIVE;
	deviceParams.saveEnergyRegisters = INACTIVE;
}

void pmu_timeProcess(void)
{
	deviceParams.milisecond++;
	if (deviceParams.milisecond == 1000)
	{
		deviceParams.milisecond = 0;
		deviceParams.second++;
		if (deviceParams.second == 60)
		{
			deviceParams.second = 0;
			deviceParams.minute++;
			deviceParams.minute2++;

			if (deviceParams.minute2 == 32)
			{
				deviceParams.saveEnergyRegisters = ACTIVE;
				deviceParams.minute2 = 0;
			}

			if (deviceParams.minute == 180)
			{
				deviceParams.minute = 0;
				deviceParams.hour++;
				// if(deviceParams.hour == 8) deviceParams.softwareReset = INACTIVE;
			}

		}
	}
}

void pmu_testFlashRegisters(void)
{

}

void pmu_clearTimeProcess(void)
{
	deviceParams.milisecond = 0;
	deviceParams.second = 0;
	deviceParams.minute = 0;
	deviceParams.hour = 0;
}

void pmu_checkDeviceSoftwareReset(void)
{
	if(deviceParams.softwareReset == ACTIVE)
	{
		pmu_watchdogKickDog();
		internalFlashWrite();
		pmu_watchdogKickDog();
		NVIC_SystemReset();
	}
}

void pmu_saveEnergyRegisters(void)
{
	if(deviceParams.saveEnergyRegisters == ACTIVE)
	{
		rtu_transmitEnable_receiveDisable();
		HAL_NVIC_DisableIRQ(USART6_IRQn);
		__disable_irq();
		pmu_watchdogKickDog();
		internalFlashWrite();
		pmu_watchdogKickDog();
		deviceParams.saveEnergyRegisters = INACTIVE;
		// HAL_Delay(1000);
		pmu_watchdogKickDog();
		rtu_transmitDisable_receiveEnable();
		__enable_irq();
		HAL_NVIC_EnableIRQ(USART6_IRQn);
	}
}
