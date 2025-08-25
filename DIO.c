/**
  ******************************************************************************
  * @file    DIO.c
  * @author  Serbay Ozkan
  * @version V1.0.0
  * @date    15-November-2016
  * @brief   Modbus RTU Slave Application Layer File
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "string.h"
#include "dma.h"
#include "usart.h"
#include "gpio.h"
#include "DIO.h"

/* User Specific Includes ------------------------------------------------------------*/
#include "flash.h"
#include "Modbus_RTU_Slave.h"

/* Typedefs ------------------------------------------------------------------*/
Typedef_inputStatus inputStatus;
Typedef_inputStatus inputStatus_NP;
Typedef_inputTest inputTest;
Typedef_inputTest inputPolarity;
Typedef_inputStatusChangeCnt inputStatusCnt;
Typedef_inputTransitionParams inputTransitionFlag;
Typedef_outputControlFlag outputControlFlag;
Typedef_outputStatus outputStatus;
Typedef_outputControlCounter outputControlCounter;
Typedef_relayLatchTimeOut relayLatchTimeOut;
Typedef_relayLatchType relayLatchType;
Typedef_inputTransitionParams inputLowToHighTranCnt;
Typedef_inputTransitionParams inputHighToLowTranCnt;
Typedef_inputTransitionParams inputONCnt;
Typedef_inputTransitionParams inputOFFCnt;
Typedef_inputTransitionParams inputFilterTimeOut;
Typedef_deviceParams deviceParams;


/**
  * @brief  This function performs Modbus CRC16 generation.  
  * @param  crcBuf:Input buffer that contains related registers to be calculated
  * @param  crcLength: CRC16 length
  * @retval None
  */

void GPIO_Startup_Init(void)
{
	HAL_GPIO_WritePin(MCU_DIO1_GPIO_Port, MCU_DIO1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MCU_DIO2_GPIO_Port, MCU_DIO2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MCU_DIO3_GPIO_Port, MCU_DIO3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MCU_DIO4_GPIO_Port, MCU_DIO4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MCU_DIO5_GPIO_Port, MCU_DIO5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MCU_DIO6_GPIO_Port, MCU_DIO6_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(MCU_DIO7_GPIO_Port, MCU_DIO7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MCU_DIO8_GPIO_Port, MCU_DIO8_Pin, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(MUX_SELECT1_GPIO_Port, MUX_SELECT1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MUX_SELECT2_GPIO_Port, MUX_SELECT2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MUX_SELECT3_GPIO_Port, MUX_SELECT3_Pin, GPIO_PIN_RESET);
}

void dio_writeOutputStatus(void)
{
	/***********************************************************/
	if(outputStatus.CH1 == ON_STATE && relayLatchType.CH1 == 0)
	{
		WRITE_OUT1_SET
		outputControlFlag.CH1 = 1;
	}
	
	if(relayLatchType.CH1 == 1)
	{
		if(outputStatus.CH1 == ON_STATE)  WRITE_OUT1_SET
		if(outputStatus.CH1 == OFF_STATE) WRITE_OUT1_RESET
	}
	/***********************************************************/
	
	/***********************************************************/
	if(outputStatus.CH2 == ON_STATE && relayLatchType.CH2 == 0)
	{
		WRITE_OUT2_SET
		outputControlFlag.CH2 = 1;
	}
	
	if(relayLatchType.CH2 == 1)
	{
		if(outputStatus.CH2 == ON_STATE)  WRITE_OUT2_SET
		if(outputStatus.CH2 == OFF_STATE) WRITE_OUT2_RESET
	}
	/***********************************************************/
	
	/***********************************************************/
	if(outputStatus.CH3 == ON_STATE && relayLatchType.CH3 == 0)
	{
		WRITE_OUT3_SET
		outputControlFlag.CH3 = 1;
	}
	
	if(relayLatchType.CH3 == 1)
	{
		if(outputStatus.CH3 == ON_STATE)  WRITE_OUT3_SET
		if(outputStatus.CH3 == OFF_STATE) WRITE_OUT3_RESET
	}
	/***********************************************************/
	
	/***********************************************************/
	if(outputStatus.CH4 == ON_STATE && relayLatchType.CH4 == 0)
	{
		WRITE_OUT4_SET
		outputControlFlag.CH4 = 1;
	}
	
	if(relayLatchType.CH4 == 1)
	{
		if(outputStatus.CH4 == ON_STATE)  WRITE_OUT4_SET
		if(outputStatus.CH4 == OFF_STATE) WRITE_OUT4_RESET
	}
	/***********************************************************/
	
	/***********************************************************/
	if(outputStatus.CH5 == ON_STATE && relayLatchType.CH5 == 0)
	{
		WRITE_OUT5_SET
		outputControlFlag.CH5 = 1;
	}
	
	if(relayLatchType.CH5 == 1)
	{
		if(outputStatus.CH5 == ON_STATE)  WRITE_OUT5_SET
		if(outputStatus.CH5 == OFF_STATE) WRITE_OUT5_RESET
	}
	/***********************************************************/
	
	/***********************************************************/
	if(outputStatus.CH6 == ON_STATE && relayLatchType.CH6 == 0)
	{
		WRITE_OUT6_SET
		outputControlFlag.CH6 = 1;
	}
	
	if(relayLatchType.CH6 == 1)
	{
		if(outputStatus.CH6 == ON_STATE)  WRITE_OUT6_SET
		if(outputStatus.CH6 == OFF_STATE) WRITE_OUT6_RESET
	}
	/***********************************************************/
	
	/***********************************************************/
	if(outputStatus.CH7 == ON_STATE && relayLatchType.CH7 == 0)
	{
		WRITE_OUT7_SET
		outputControlFlag.CH7 = 1;
	}
	
	if(relayLatchType.CH7 == 1)
	{
		if(outputStatus.CH7 == ON_STATE)  WRITE_OUT7_SET
		if(outputStatus.CH7 == OFF_STATE) WRITE_OUT7_RESET
	}
	/***********************************************************/
	
	/***********************************************************/
	if(outputStatus.CH8 == ON_STATE && relayLatchType.CH8 == 0)
	{
		WRITE_OUT8_SET
		outputControlFlag.CH8 = 1;
	}
	
	if(relayLatchType.CH8 == 1)
	{
		if(outputStatus.CH8 == ON_STATE)  WRITE_OUT8_SET
		if(outputStatus.CH8 == OFF_STATE) WRITE_OUT8_RESET
	}
  /***********************************************************/
	outputStatus.ALL = outputStatus.CH1 | (outputStatus.CH2 << 1) | (outputStatus.CH3 << 2) | (outputStatus.CH3 << 2) | (outputStatus.CH4 << 3)
	                                    | (outputStatus.CH5 << 4) | (outputStatus.CH6 << 5) | (outputStatus.CH7 << 6) | (outputStatus.CH8 << 7);
	flashParamsWrite.outputStatusALL = outputStatus.ALL;
}

void dio_resetTransitionCounters(void)
{
	if(deviceParams.resetTransitionCounters == 1)
	{
		memset(&inputHighToLowTranCnt, 0, sizeof(inputHighToLowTranCnt));
		memset(&inputLowToHighTranCnt, 0, sizeof(inputLowToHighTranCnt));
		deviceParams.resetTransitionCounters = 0;
	}
}

void dio_readInputStatus(void)
{

	deviceParams.inputTestMode = inputTest.ACTIVE;
	if(deviceParams.inputTestMode == 1)
	{
		inputStatus.CH1 = inputTest.CH1;
		inputStatus.CH2 = inputTest.CH2;
		inputStatus.CH3 = inputTest.CH3;
		inputStatus.CH4 = inputTest.CH4;
		inputStatus.CH5 = inputTest.CH5;
		inputStatus.CH6 = inputTest.CH6;
		inputStatus.CH7 = inputTest.CH7;
		inputStatus.CH8 = inputTest.CH8;
		inputStatus.CH9 = inputTest.CH9;
		inputStatus.CH10 = inputTest.CH10;
		inputStatus.CH11 = inputTest.CH11;
		inputStatus.CH12 = inputTest.CH12;
		inputStatus.CH13 = inputTest.CH13;
		inputStatus.CH14 = inputTest.CH14;
		inputStatus.CH15 = inputTest.CH15;
		inputStatus.CH16 = inputTest.CH16;
		memset(&inputONCnt,0,sizeof(inputONCnt));
		memset(&inputOFFCnt,0,sizeof(inputOFFCnt));
	}
	
	else
	{
	
	/****************************  D0 *****************************************/
	MUX_SELECT1_L
	MUX_SELECT2_L
	MUX_SELECT3_L
	HAL_Delay(1);
	if(inputPolarity.CH14 == INVERSE)
	{
		inputStatus_NP.CH14 = READ_MUX_OUT1
		if(inputStatus_NP.CH14 == ON_STATE)  inputTransitionFlag.CH14 = 0;
		if(inputStatus_NP.CH14 == OFF_STATE) inputTransitionFlag.CH14 = 1;
	}
	else
	{
		inputStatus_NP.CH14 = READ_MUX_OUT1
		if(inputStatus_NP.CH14 == ON_STATE)  inputTransitionFlag.CH14 = 1;
		if(inputStatus_NP.CH14 == OFF_STATE) inputTransitionFlag.CH14 = 0;
	}
	
	if(inputPolarity.CH10 == INVERSE)
	{
		inputStatus_NP.CH10 = READ_MUX_OUT2
		if(inputStatus_NP.CH10 == ON_STATE)  inputTransitionFlag.CH10 = 0;
		if(inputStatus_NP.CH10 == OFF_STATE) inputTransitionFlag.CH10 = 1;
	}
	else
	{
		inputStatus_NP.CH10 = READ_MUX_OUT2
		if(inputStatus_NP.CH10 == ON_STATE)  inputTransitionFlag.CH10 = 1;
		if(inputStatus_NP.CH10 == OFF_STATE) inputTransitionFlag.CH10 = 0;
	}
	HAL_Delay(1);
  /**************************************************************************/
	
	/****************************  D1 *****************************************/
	MUX_SELECT1_L
	MUX_SELECT2_L
	MUX_SELECT3_H
	HAL_Delay(1);	
	if(inputPolarity.CH7 == INVERSE)
	{
		inputStatus_NP.CH7 = READ_MUX_OUT1
		if(inputStatus_NP.CH7 == ON_STATE)  inputTransitionFlag.CH7 = 0;
		if(inputStatus_NP.CH7 == OFF_STATE) inputTransitionFlag.CH7 = 1;
	}
	else
	{
		inputStatus_NP.CH7 = READ_MUX_OUT1
		if(inputStatus_NP.CH7 == ON_STATE)  inputTransitionFlag.CH7 = 1;
		if(inputStatus_NP.CH7 == OFF_STATE) inputTransitionFlag.CH7 = 0;
	}
	
	if(inputPolarity.CH3 == INVERSE)
	{
		inputStatus_NP.CH3 = READ_MUX_OUT2
		if(inputStatus_NP.CH3 == ON_STATE)  inputTransitionFlag.CH3 = 0;
		if(inputStatus_NP.CH3 == OFF_STATE) inputTransitionFlag.CH3 = 1;
	}
	else
	{
		inputStatus_NP.CH3 = READ_MUX_OUT2
		if(inputStatus_NP.CH3 == ON_STATE)  inputTransitionFlag.CH3 = 1;
		if(inputStatus_NP.CH3 == OFF_STATE) inputTransitionFlag.CH3 = 0;
	}
	HAL_Delay(1);
	/**************************************************************************/
	
	
	/****************************  D2 *****************************************/
	MUX_SELECT1_L
	MUX_SELECT2_H
	MUX_SELECT3_L
	HAL_Delay(1);
	if(inputPolarity.CH5 == INVERSE)
	{
		inputStatus_NP.CH5 = READ_MUX_OUT1
		if(inputStatus_NP.CH5 == ON_STATE)  inputTransitionFlag.CH5 = 0;
		if(inputStatus_NP.CH5 == OFF_STATE) inputTransitionFlag.CH5 = 1;
	}
	else
	{
		inputStatus_NP.CH5 = READ_MUX_OUT1
		if(inputStatus_NP.CH5 == ON_STATE)  inputTransitionFlag.CH5 = 1;
		if(inputStatus_NP.CH5 == OFF_STATE) inputTransitionFlag.CH5 = 0;
	}
	
	if(inputPolarity.CH1 == INVERSE)
	{
		inputStatus_NP.CH1 = READ_MUX_OUT2
		if(inputStatus_NP.CH1 == ON_STATE)  inputTransitionFlag.CH1 = 0;
		if(inputStatus_NP.CH1 == OFF_STATE) inputTransitionFlag.CH1 = 1;
	}
	else
	{
		inputStatus_NP.CH1 = READ_MUX_OUT2
		if(inputStatus_NP.CH1 == ON_STATE)  inputTransitionFlag.CH1 = 1;
		if(inputStatus_NP.CH1 == OFF_STATE) inputTransitionFlag.CH1 = 0;

	}
	HAL_Delay(1);
	/**************************************************************************/
	
	
	/****************************  D3 *****************************************/
	MUX_SELECT1_L
	MUX_SELECT2_H
	MUX_SELECT3_H
	HAL_Delay(1);
	if(inputPolarity.CH16 == INVERSE)
	{
		inputStatus_NP.CH16 = READ_MUX_OUT1
		if(inputStatus_NP.CH16 == ON_STATE)  inputTransitionFlag.CH16 = 0;
		if(inputStatus_NP.CH16 == OFF_STATE) inputTransitionFlag.CH16 = 1;
	}
	else
	{
		inputStatus_NP.CH16 = READ_MUX_OUT1
		if(inputStatus_NP.CH16 == ON_STATE)  inputTransitionFlag.CH16 = 1;
		if(inputStatus_NP.CH16 == OFF_STATE) inputTransitionFlag.CH16 = 0;
	}
	if(inputPolarity.CH12 == INVERSE)
	{
		inputStatus_NP.CH12 = READ_MUX_OUT2
		if(inputStatus_NP.CH12 == ON_STATE)  inputTransitionFlag.CH12 = 0;
		if(inputStatus_NP.CH12 == OFF_STATE) inputTransitionFlag.CH12 = 1;
	}
	else
	{
		inputStatus_NP.CH12 = READ_MUX_OUT2
		if(inputStatus_NP.CH12 == ON_STATE)  inputTransitionFlag.CH12 = 1;
		if(inputStatus_NP.CH12 == OFF_STATE) inputTransitionFlag.CH12 = 0;
	}
	HAL_Delay(1);
	/**************************************************************************/
	
	
	/****************************  D4 *****************************************/
	MUX_SELECT1_H
	MUX_SELECT2_L
	MUX_SELECT3_L
	HAL_Delay(1);
	if(inputPolarity.CH13 == INVERSE)
	{
		inputStatus_NP.CH13 = READ_MUX_OUT1
		if(inputStatus_NP.CH13 == ON_STATE)  inputTransitionFlag.CH13 = 0;
		if(inputStatus_NP.CH13 == OFF_STATE) inputTransitionFlag.CH13 = 1;
	}
	else
	{
		inputStatus_NP.CH13 = READ_MUX_OUT1
		if(inputStatus_NP.CH13 == ON_STATE)  inputTransitionFlag.CH13 = 1;
		if(inputStatus_NP.CH13 == OFF_STATE) inputTransitionFlag.CH13 = 0;
	}
	if(inputPolarity.CH9 == INVERSE)
	{
		inputStatus_NP.CH9 = READ_MUX_OUT2
		if(inputStatus_NP.CH9 == ON_STATE)  inputTransitionFlag.CH9 = 0;
		if(inputStatus_NP.CH9 == OFF_STATE) inputTransitionFlag.CH9 = 1;
	}
	else
	{
		inputStatus_NP.CH9 = READ_MUX_OUT2
		if(inputStatus_NP.CH9 == ON_STATE)  inputTransitionFlag.CH9 = 1;
		if(inputStatus_NP.CH9 == OFF_STATE) inputTransitionFlag.CH9 = 0;
	}
	HAL_Delay(1);
	/**************************************************************************/
	
	/****************************  D5 *****************************************/
	MUX_SELECT1_H
	MUX_SELECT2_L
	MUX_SELECT3_H
	HAL_Delay(1);
	if(inputPolarity.CH8 == INVERSE)
	{
		inputStatus_NP.CH8 = READ_MUX_OUT1
		if(inputStatus_NP.CH8 == ON_STATE)  inputTransitionFlag.CH8 = 0;
		if(inputStatus_NP.CH8 == OFF_STATE) inputTransitionFlag.CH8 = 1;
	}
	else
	{
		inputStatus_NP.CH8 = READ_MUX_OUT1
		if(inputStatus_NP.CH8 == ON_STATE)  inputTransitionFlag.CH8 = 1;
		if(inputStatus_NP.CH8 == OFF_STATE) inputTransitionFlag.CH8 = 0;
	}
	if(inputPolarity.CH4 == INVERSE)
	{
		inputStatus_NP.CH4 = READ_MUX_OUT2
		if(inputStatus_NP.CH4 == ON_STATE)  inputTransitionFlag.CH4 = 0;
		if(inputStatus_NP.CH4 == OFF_STATE) inputTransitionFlag.CH4 = 1;
	}
	else
	{
		inputStatus_NP.CH4 = READ_MUX_OUT2
		if(inputStatus_NP.CH4 == ON_STATE)  inputTransitionFlag.CH4 = 1;
		if(inputStatus_NP.CH4 == OFF_STATE) inputTransitionFlag.CH4 = 0;
	}
	HAL_Delay(1);
	/**************************************************************************/
	
	/****************************  D6 *****************************************/
	MUX_SELECT1_H
	MUX_SELECT2_H
	MUX_SELECT3_L
	HAL_Delay(1);
	if(inputPolarity.CH6 == INVERSE)
	{
		inputStatus_NP.CH6 = READ_MUX_OUT1
		if(inputStatus_NP.CH6 == ON_STATE)  inputTransitionFlag.CH6 = 0;
		if(inputStatus_NP.CH6 == OFF_STATE) inputTransitionFlag.CH6 = 1;
	}
	else
	{
		inputStatus_NP.CH6 = READ_MUX_OUT1
		if(inputStatus_NP.CH6 == ON_STATE)  inputTransitionFlag.CH6 = 1;
		if(inputStatus_NP.CH6 == OFF_STATE) inputTransitionFlag.CH6 = 0;
	}
	if(inputPolarity.CH2 == INVERSE)
	{
		inputStatus_NP.CH2 = READ_MUX_OUT2
		if(inputStatus_NP.CH2 == ON_STATE)  inputTransitionFlag.CH2 = 0;
		if(inputStatus_NP.CH2 == OFF_STATE) inputTransitionFlag.CH2 = 1;
	}
	else
	{
		inputStatus_NP.CH2 = READ_MUX_OUT2
		if(inputStatus_NP.CH2 == ON_STATE)  inputTransitionFlag.CH2 = 1;
		if(inputStatus_NP.CH2 == OFF_STATE) inputTransitionFlag.CH2 = 0;
	}
	HAL_Delay(1);
	/**************************************************************************/
	
	/****************************  D7 *****************************************/
	MUX_SELECT1_H
	MUX_SELECT2_H
	MUX_SELECT3_H
	HAL_Delay(1);
	if(inputPolarity.CH15 == INVERSE)
	{
		inputStatus_NP.CH15 = READ_MUX_OUT1
		if(inputStatus_NP.CH15 == ON_STATE)  inputTransitionFlag.CH15 = 0;
		if(inputStatus_NP.CH15 == OFF_STATE) inputTransitionFlag.CH15 = 1;
	}
	else
	{
		inputStatus_NP.CH15 = READ_MUX_OUT1
		if(inputStatus_NP.CH15 == ON_STATE)  inputTransitionFlag.CH15 = 1;
		if(inputStatus_NP.CH15 == OFF_STATE) inputTransitionFlag.CH15 = 0;
	}
	if(inputPolarity.CH11 == INVERSE)
	{
		inputStatus_NP.CH11 = READ_MUX_OUT2
		if(inputStatus_NP.CH11 == ON_STATE)  inputTransitionFlag.CH11 = 0;
		if(inputStatus_NP.CH11 == OFF_STATE) inputTransitionFlag.CH11 = 1;
	}
	else
	{
		inputStatus_NP.CH11 = READ_MUX_OUT2
		if(inputStatus_NP.CH11 == ON_STATE)  inputTransitionFlag.CH11 = 1;
		if(inputStatus_NP.CH11 == OFF_STATE) inputTransitionFlag.CH11 = 0;
	}
	HAL_Delay(1);
	
	}
  /**************************************************************************/
	/*ALL*/
	
	inputStatus.ALL =    inputStatus.CH1         | (inputStatus.CH2 << 1)   | (inputStatus.CH3 << 2)
	                  | (inputStatus.CH4 << 3)   | (inputStatus.CH5 << 4)   | (inputStatus.CH6 << 5)
					  | (inputStatus.CH7 << 6)   | (inputStatus.CH8 << 7)   | (inputStatus.CH9 << 8)
					  | (inputStatus.CH10 << 9)  | (inputStatus.CH11 << 10) | (inputStatus.CH12 << 11)
					  | (inputStatus.CH13 << 12) | (inputStatus.CH14 << 13) | (inputStatus.CH15 << 14)
					  | (inputStatus.CH16 << 15);
	
	inputStatus.ulas1 = inputStatus.CH1         | (inputStatus.CH2 << 1)   | (inputStatus.CH3 << 2)
	                  | (inputStatus.CH4 << 3)   | (inputStatus.CH5 << 4)   | (inputStatus.CH6 << 5)
					  | (inputStatus.CH7 << 6)   | (inputStatus.CH8 << 7);
	
	inputStatus.ulas2 = inputStatus.CH9         | (inputStatus.CH10 << 1)   | (inputStatus.CH11 << 2)
	                  | (inputStatus.CH12 << 3)   | (inputStatus.CH13<< 4)   | (inputStatus.CH14 << 5)
					  | (inputStatus.CH15 << 6)   | (inputStatus.CH16 << 7);
	
}

void dio_checkSoftwareReset(void)
{
	if(deviceParams.softwareReset == 1) NVIC_SystemReset();
}

void dio_checkOperationSuccess(void)
{
	if(deviceParams.operationSuccess++ == 0xFFFF) deviceParams.operationSuccess = 0;
}

void dio_checkFlashOperation(void)
{
	if(deviceParams.flashSaveAll == 1)
	{
		deviceParams.flashSaveAll = 0;
		internalFlashWrite();
		HAL_Delay(1000);
		HAL_NVIC_SystemReset();
	}
}

void dio_startUpRoutine(void)
{
	internalFlashRead();
	if(flashParamsRead.uniqueID != 0X31) { dio_loadDefaultSettings(); }
	internalFlashRead();
    dio_paramInit();
	dio_inputTestInit();
	MX_USART6_UART_Init();
	rtu_transmitDisable_receiveEnable();
	HAL_Delay(100);
    HAL_UART_Receive_IT(&huart6,&modbusParams.receivedData, 1);	//activate UART receive interrupt every time
}

void dio_checkAllInputParams(void)
{
	if(deviceParams.inputTestMode == 0)
	{	
		if(inputTransitionFlag.CH1 == 1)
		{
			inputOFFCnt.CH1 = 0;
			inputONCnt.CH1++;
			if(inputONCnt.CH1 == inputFilterTimeOut.CH1)
			{
				inputStatus.CH1 = ON_STATE;
				inputLowToHighTranCnt.CH1++;
			}
			if(inputONCnt.CH1 == 0xFFFF) inputONCnt.CH1 = (inputFilterTimeOut.CH1)+1;
		}
		
		if(inputTransitionFlag.CH1 == 0)
		{
			inputONCnt.CH1 = 0;
			inputOFFCnt.CH1++;
			if(inputOFFCnt.CH1 == inputFilterTimeOut.CH1)
			{
				inputStatus.CH1 = OFF_STATE;
				inputHighToLowTranCnt.CH1++;
			}
			if(inputOFFCnt.CH1 == 0xFFFF) inputOFFCnt.CH1 = (inputFilterTimeOut.CH1)+1;
		}
		
		if(inputTransitionFlag.CH2 == 1)
		{
			inputOFFCnt.CH2 = 0;
			inputONCnt.CH2++;
			if(inputONCnt.CH2 == inputFilterTimeOut.CH2)
			{
				inputStatus.CH2 = ON_STATE;
				inputLowToHighTranCnt.CH2++;
			}
			if(inputONCnt.CH2 == 0xFFFF) inputONCnt.CH2 = (inputFilterTimeOut.CH2)+1;
		}
		
		if(inputTransitionFlag.CH2 == 0)
		{
			inputONCnt.CH2 = 0;
			inputOFFCnt.CH2++;
			if(inputOFFCnt.CH2 == inputFilterTimeOut.CH2)
			{
				inputStatus.CH2 = OFF_STATE;
				inputHighToLowTranCnt.CH2++;
			}
			if(inputOFFCnt.CH2 == 0xFFFF) inputOFFCnt.CH2 = (inputFilterTimeOut.CH2)+1;
		}
		
		if(inputTransitionFlag.CH3 == 1)
		{
			inputOFFCnt.CH3 = 0;
			inputONCnt.CH3++;
			if(inputONCnt.CH3 == inputFilterTimeOut.CH3)
			{
				inputStatus.CH3 = ON_STATE;
				inputLowToHighTranCnt.CH3++;
			}
			if(inputONCnt.CH3 == 0xFFFF) inputONCnt.CH3 = (inputFilterTimeOut.CH3)+1;
		}
		
		if(inputTransitionFlag.CH3 == 0)
		{
			inputONCnt.CH3 = 0;
			inputOFFCnt.CH3++;
			if(inputOFFCnt.CH3 == inputFilterTimeOut.CH3)
			{
				inputStatus.CH3 = OFF_STATE;
				inputHighToLowTranCnt.CH3++;
			}
			if(inputOFFCnt.CH3 == 0xFFFF) inputOFFCnt.CH3 = (inputFilterTimeOut.CH3)+1;
		}
		
		if(inputTransitionFlag.CH4 == 1)
		{
			inputOFFCnt.CH4 = 0;
			inputONCnt.CH4++;
			if(inputONCnt.CH4 == inputFilterTimeOut.CH4)
			{
				inputStatus.CH4 = ON_STATE;
				inputLowToHighTranCnt.CH4++;
			}
			if(inputONCnt.CH4 == 0xFFFF) inputONCnt.CH4 = (inputFilterTimeOut.CH4)+1;
		}
		
		if(inputTransitionFlag.CH4 == 0)
		{
			inputONCnt.CH4 = 0;
			inputOFFCnt.CH4++;
			if(inputOFFCnt.CH4 == inputFilterTimeOut.CH4)
			{
				inputStatus.CH4 = OFF_STATE;
				inputHighToLowTranCnt.CH4++;
			}
			if(inputOFFCnt.CH4 == 0xFFFF) inputOFFCnt.CH4 = (inputFilterTimeOut.CH4)+1;
		}
		
		if(inputTransitionFlag.CH5 == 1)
		{
			inputOFFCnt.CH5 = 0;
			inputONCnt.CH5++;
			if(inputONCnt.CH5 == inputFilterTimeOut.CH5)
			{
				inputStatus.CH5 = ON_STATE;
				inputLowToHighTranCnt.CH5++;
			}
			if(inputONCnt.CH5 == 0xFFFF) inputONCnt.CH5 = (inputFilterTimeOut.CH5)+1;
		}
		
		if(inputTransitionFlag.CH5 == 0)
		{
			inputONCnt.CH5 = 0;
			inputOFFCnt.CH5++;
			if(inputOFFCnt.CH5 == inputFilterTimeOut.CH5)
			{
				inputStatus.CH5 = OFF_STATE;
				inputHighToLowTranCnt.CH5++;
			}
			if(inputOFFCnt.CH5 == 0xFFFF) inputOFFCnt.CH5 = (inputFilterTimeOut.CH5)+1;
		}
		
		if(inputTransitionFlag.CH6 == 1)
		{
			inputOFFCnt.CH6 = 0;
			inputONCnt.CH6++;
			if(inputONCnt.CH6 == inputFilterTimeOut.CH6)
			{
				inputStatus.CH6 = ON_STATE;
				inputLowToHighTranCnt.CH6++;
			}
			if(inputONCnt.CH6 == 0xFFFF) inputONCnt.CH6 = (inputFilterTimeOut.CH6)+1;
		}
		
		if(inputTransitionFlag.CH6 == 0)
		{
			inputONCnt.CH6 = 0;
			inputOFFCnt.CH6++;
			if(inputOFFCnt.CH6 == inputFilterTimeOut.CH6)
			{
				inputStatus.CH6 = OFF_STATE;
				inputHighToLowTranCnt.CH6++;
			}
			if(inputOFFCnt.CH6 == 0xFFFF) inputOFFCnt.CH6 = (inputFilterTimeOut.CH6)+1;
		}
		
		if(inputTransitionFlag.CH7 == 1)
		{
			inputOFFCnt.CH7 = 0;
			inputONCnt.CH7++;
			if(inputONCnt.CH7 == inputFilterTimeOut.CH7)
			{
				inputStatus.CH7 = ON_STATE;
				inputLowToHighTranCnt.CH7++;
			}
			if(inputONCnt.CH7 == 0xFFFF) inputONCnt.CH7 = (inputFilterTimeOut.CH7)+1;
		}
		
		if(inputTransitionFlag.CH7 == 0)
		{
			inputONCnt.CH7 = 0;
			inputOFFCnt.CH7++;
			if(inputOFFCnt.CH7 == inputFilterTimeOut.CH7)
			{
				inputStatus.CH7 = OFF_STATE;
				inputHighToLowTranCnt.CH7++;
			}
			if(inputOFFCnt.CH7 == 0xFFFF) inputOFFCnt.CH7 = (inputFilterTimeOut.CH7)+1;
		}
		
		if(inputTransitionFlag.CH8 == 1)
		{
			inputOFFCnt.CH8 = 0;
			inputONCnt.CH8++;
			if(inputONCnt.CH8 == inputFilterTimeOut.CH8)
			{
				inputStatus.CH8 = ON_STATE;
				inputLowToHighTranCnt.CH8++;
			}
			if(inputONCnt.CH8 == 0xFFFF) inputONCnt.CH8 = (inputFilterTimeOut.CH8)+1;
		}
		
		if(inputTransitionFlag.CH8 == 0)
		{
			inputONCnt.CH8 = 0;
			inputOFFCnt.CH8++;
			if(inputOFFCnt.CH8 == inputFilterTimeOut.CH8)
			{
				inputStatus.CH8 = OFF_STATE;
				inputHighToLowTranCnt.CH8++;
			}
			if(inputOFFCnt.CH8 == 0xFFFF) inputOFFCnt.CH8 = (inputFilterTimeOut.CH8)+1;
		}
		
		if(inputTransitionFlag.CH9 == 1)
		{
			inputOFFCnt.CH9 = 0;
			inputONCnt.CH9++;
			if(inputONCnt.CH9 == inputFilterTimeOut.CH9)
			{
				inputStatus.CH9 = ON_STATE;
				inputLowToHighTranCnt.CH9++;
			}
			if(inputONCnt.CH9 == 0xFFFF) inputONCnt.CH9 = (inputFilterTimeOut.CH9)+1;
		}
		
		if(inputTransitionFlag.CH9 == 0)
		{
			inputONCnt.CH9 = 0;
			inputOFFCnt.CH9++;
			if(inputOFFCnt.CH9 == inputFilterTimeOut.CH9)
			{
				inputStatus.CH9 = OFF_STATE;
				inputHighToLowTranCnt.CH9++;
			}
			if(inputOFFCnt.CH9 == 0xFFFF) inputOFFCnt.CH9 = (inputFilterTimeOut.CH9)+1;
		}
		
		if(inputTransitionFlag.CH10 == 1)
		{
			inputOFFCnt.CH10 = 0;
			inputONCnt.CH10++;
			if(inputONCnt.CH10 == inputFilterTimeOut.CH10)
			{
				inputStatus.CH10 = ON_STATE;
				inputLowToHighTranCnt.CH10++;
			}
			if(inputONCnt.CH10 == 0xFFFF) inputONCnt.CH10 = (inputFilterTimeOut.CH10)+1;
		}
		
		if(inputTransitionFlag.CH10 == 0)
		{
			inputONCnt.CH10 = 0;
			inputOFFCnt.CH10++;
			if(inputOFFCnt.CH10 == inputFilterTimeOut.CH10)
			{
				inputStatus.CH10 = OFF_STATE;
				inputHighToLowTranCnt.CH10++;
			}
			if(inputOFFCnt.CH10 == 0xFFFF) inputOFFCnt.CH10 = (inputFilterTimeOut.CH10)+1;
		}
		
		if(inputTransitionFlag.CH11 == 1)
		{
			inputOFFCnt.CH11 = 0;
			inputONCnt.CH11++;
			if(inputONCnt.CH11 == inputFilterTimeOut.CH11)
			{
				inputStatus.CH11 = ON_STATE;
				inputLowToHighTranCnt.CH11++;
			}
			if(inputONCnt.CH11 == 0xFFFF) inputONCnt.CH11 = (inputFilterTimeOut.CH11)+1;
		}
		
		if(inputTransitionFlag.CH11 == 0)
		{
			inputONCnt.CH11 = 0;
			inputOFFCnt.CH11++;
			if(inputOFFCnt.CH11 == inputFilterTimeOut.CH11)
			{
				inputStatus.CH11 = OFF_STATE;
				inputHighToLowTranCnt.CH11++;
			}
			if(inputOFFCnt.CH11 == 0xFFFF) inputOFFCnt.CH11 = (inputFilterTimeOut.CH11)+1;
		}
		
		if(inputTransitionFlag.CH12 == 1)
		{
			inputOFFCnt.CH12 = 0;
			inputONCnt.CH12++;
			if(inputONCnt.CH12 == inputFilterTimeOut.CH12)
			{
				inputStatus.CH12 = ON_STATE;
				inputLowToHighTranCnt.CH12++;
			}
			if(inputONCnt.CH12 == 0xFFFF) inputONCnt.CH12 = (inputFilterTimeOut.CH12)+1;
		}
		
		if(inputTransitionFlag.CH12 == 0)
		{
			inputONCnt.CH12 = 0;
			inputOFFCnt.CH12++;
			if(inputOFFCnt.CH12 == inputFilterTimeOut.CH12)
			{
				inputStatus.CH12 = OFF_STATE;
				inputHighToLowTranCnt.CH12++;
			}
			if(inputOFFCnt.CH12 == 0xFFFF) inputOFFCnt.CH12 = (inputFilterTimeOut.CH12)+1;
		}
		
		if(inputTransitionFlag.CH13 == 1)
		{
			inputOFFCnt.CH13 = 0;
			inputONCnt.CH13++;
			if(inputONCnt.CH13 == inputFilterTimeOut.CH13)
			{
				inputStatus.CH13 = ON_STATE;
				inputLowToHighTranCnt.CH13++;
			}
			if(inputONCnt.CH13 == 0xFFFF) inputONCnt.CH13 = (inputFilterTimeOut.CH13)+1;
		}
		
		if(inputTransitionFlag.CH13 == 0)
		{
			inputONCnt.CH13 = 0;
			inputOFFCnt.CH13++;
			if(inputOFFCnt.CH13 == inputFilterTimeOut.CH13)
			{
				inputStatus.CH13 = OFF_STATE;
				inputHighToLowTranCnt.CH13++;
			}
			if(inputOFFCnt.CH13 == 0xFFFF) inputOFFCnt.CH13 = (inputFilterTimeOut.CH13)+1;
		}
		
		if(inputTransitionFlag.CH14 == 1)
		{
			inputOFFCnt.CH14 = 0;
			inputONCnt.CH14++;
			if(inputONCnt.CH14 == inputFilterTimeOut.CH14)
			{
				inputStatus.CH14 = ON_STATE;
				inputLowToHighTranCnt.CH14++;
			}
			if(inputONCnt.CH14 == 0xFFFF) inputONCnt.CH14 = (inputFilterTimeOut.CH14)+1;
		}
		
		if(inputTransitionFlag.CH14 == 0)
		{
			inputONCnt.CH14 = 0;
			inputOFFCnt.CH14++;
			if(inputOFFCnt.CH14 == inputFilterTimeOut.CH14)
			{
				inputStatus.CH14 = OFF_STATE;
				inputHighToLowTranCnt.CH14++;
			}
			if(inputOFFCnt.CH14 == 0xFFFF) inputOFFCnt.CH14 = (inputFilterTimeOut.CH14)+1;
		}
		
		if(inputTransitionFlag.CH15 == 1)
		{
			inputOFFCnt.CH15 = 0;
			inputONCnt.CH15++;
			if(inputONCnt.CH15 == inputFilterTimeOut.CH15)
			{
				inputStatus.CH15 = ON_STATE;
				inputLowToHighTranCnt.CH15++;
			}
			if(inputONCnt.CH15 == 0xFFFF) inputONCnt.CH15 = (inputFilterTimeOut.CH15)+1;
		}
		
		if(inputTransitionFlag.CH15 == 0)
		{
			inputONCnt.CH15 = 0;
			inputOFFCnt.CH15++;
			if(inputOFFCnt.CH15 == inputFilterTimeOut.CH15)
			{
				inputStatus.CH15 = OFF_STATE;
				inputHighToLowTranCnt.CH15++;
			}
			if(inputOFFCnt.CH15 == 0xFFFF) inputOFFCnt.CH15 = (inputFilterTimeOut.CH15)+1;
		}
		
		if(inputTransitionFlag.CH16 == 1)
		{
			inputOFFCnt.CH16 = 0;
			inputONCnt.CH16++;
			if(inputONCnt.CH16 == inputFilterTimeOut.CH16)
			{
				inputStatus.CH16 = ON_STATE;
				inputLowToHighTranCnt.CH16++;
			}
			if(inputONCnt.CH16 == 0xFFFF) inputONCnt.CH16 = (inputFilterTimeOut.CH16)+1;
		}
		
		if(inputTransitionFlag.CH16 == 0)
		{
			inputONCnt.CH16 = 0;
			inputOFFCnt.CH16++;
			if(inputOFFCnt.CH16 == inputFilterTimeOut.CH16)
			{
				inputStatus.CH16 = OFF_STATE;
				inputHighToLowTranCnt.CH16++;
			}
			if(inputOFFCnt.CH16 == 0xFFFF) inputOFFCnt.CH16 = (inputFilterTimeOut.CH16)+1;
		}
	}
		if(outputControlFlag.CH1 == 1)
		{
			if(outputControlCounter.CH1 == relayLatchTimeOut.CH1)
			{
				outputControlFlag.CH1 = 0;
				outputControlCounter.CH1 = 0;
				WRITE_OUT1_RESET
			  outputStatus.CH1 = OFF_STATE;
			}
			outputControlCounter.CH1++;
		}
		
		if(outputControlFlag.CH2 == 1)
		{
			if(outputControlCounter.CH2 == relayLatchTimeOut.CH2)
			{
				outputControlFlag.CH2 = 0;
				outputControlCounter.CH2 = 0;
				WRITE_OUT2_RESET
			  outputStatus.CH2 = OFF_STATE;
			}
			outputControlCounter.CH2++;
		}
		
		if(outputControlFlag.CH3 == 1)
		{
			if(outputControlCounter.CH3 == relayLatchTimeOut.CH3)
			{
				outputControlFlag.CH3 = 0;
				outputControlCounter.CH3 = 0;
				WRITE_OUT3_RESET
			  outputStatus.CH3 = OFF_STATE;
			}
			outputControlCounter.CH3++;
		}
		
		if(outputControlFlag.CH4 == 1)
		{
			if(outputControlCounter.CH4 == relayLatchTimeOut.CH4)
			{
				outputControlFlag.CH4 = 0;
				outputControlCounter.CH4 = 0;
				WRITE_OUT4_RESET
			  outputStatus.CH4 = OFF_STATE;
			}
			outputControlCounter.CH4++;
		}
		
		if(outputControlFlag.CH5 == 1)
		{
			if(outputControlCounter.CH5 == relayLatchTimeOut.CH5)
			{
				outputControlFlag.CH5 = 0;
				outputControlCounter.CH5 = 0;
				WRITE_OUT5_RESET
			  outputStatus.CH5 = OFF_STATE;
			}
			outputControlCounter.CH5++;
		}
		
		if(outputControlFlag.CH6 == 1)
		{
			if(outputControlCounter.CH6 == relayLatchTimeOut.CH6)
			{
				outputControlFlag.CH6 = 0;
				outputControlCounter.CH6 = 0;
				WRITE_OUT6_RESET
			  outputStatus.CH6 = OFF_STATE;
			}
			outputControlCounter.CH6++;
		}
		
		if(outputControlFlag.CH7 == 1)
		{	
			if(outputControlCounter.CH7 == relayLatchTimeOut.CH7)
			{
				outputControlFlag.CH7 = 0;
				outputControlCounter.CH7 = 0;
				WRITE_OUT7_RESET
			  outputStatus.CH7 = OFF_STATE;
			}
			outputControlCounter.CH7++;
		}
		
		if(outputControlFlag.CH8 == 1)
		{
			if(outputControlCounter.CH8 == relayLatchTimeOut.CH8)
			{
				outputControlFlag.CH8 = 0;
				outputControlCounter.CH8 = 0;
				WRITE_OUT8_RESET
			  outputStatus.CH8 = OFF_STATE;
			}
			outputControlCounter.CH8++;
		}
}

void dio_inputTestInit(void)
{
	memset(&inputTest,0,sizeof(inputTest));
}

void dio_timeProcess(void)
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
			if (deviceParams.minute == 60)
			{
				deviceParams.minute = 0;
				deviceParams.hour++;
				if(deviceParams.hour == 2) NVIC_SystemReset();
			}
		}
	}
}

void dio_clearTimeProcess(void)
{
	deviceParams.milisecond = 0;
	deviceParams.second = 0;
	deviceParams.minute = 0;
	deviceParams.hour = 0;
}

