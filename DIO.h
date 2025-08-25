/**
  ******************************************************************************
  * @file    Modbus_RTU_Slave.h
  * @author  Serbay Ozkan
  * @version V1.0.0
  * @date    15-November-2016
  * @brief   Modbus RTU Slave Application Layer Header File
  ******************************************************************************
  */

#include "stdint.h"
#include "gpio.h"

#ifndef DIO_H
#define DIO_H

#define TEST                1

#define MUX_SELECT1_H       HAL_GPIO_WritePin(MUX_SELECT1_GPIO_Port, MUX_SELECT1_Pin, GPIO_PIN_SET);
#define MUX_SELECT1_L       HAL_GPIO_WritePin(MUX_SELECT1_GPIO_Port, MUX_SELECT1_Pin, GPIO_PIN_RESET);

#define MUX_SELECT2_H       HAL_GPIO_WritePin(MUX_SELECT2_GPIO_Port, MUX_SELECT2_Pin, GPIO_PIN_SET);
#define MUX_SELECT2_L       HAL_GPIO_WritePin(MUX_SELECT2_GPIO_Port, MUX_SELECT2_Pin, GPIO_PIN_RESET);

#define MUX_SELECT3_H       HAL_GPIO_WritePin(MUX_SELECT3_GPIO_Port, MUX_SELECT3_Pin, GPIO_PIN_SET);
#define MUX_SELECT3_L       HAL_GPIO_WritePin(MUX_SELECT3_GPIO_Port, MUX_SELECT3_Pin, GPIO_PIN_RESET);

#define READ_MUX_OUT1      HAL_GPIO_ReadPin(MUX_OUT1_GPIO_Port, MUX_OUT1_Pin);
#define READ_MUX_OUT2      HAL_GPIO_ReadPin(MUX_OUT2_GPIO_Port, MUX_OUT2_Pin);

#define WRITE_OUT1_SET     HAL_GPIO_WritePin(MCU_DIO1_GPIO_Port, MCU_DIO1_Pin, GPIO_PIN_SET);
#define WRITE_OUT1_RESET     HAL_GPIO_WritePin(MCU_DIO1_GPIO_Port, MCU_DIO1_Pin, GPIO_PIN_RESET);

#define WRITE_OUT2_SET     HAL_GPIO_WritePin(MCU_DIO2_GPIO_Port, MCU_DIO2_Pin, GPIO_PIN_SET);
#define WRITE_OUT2_RESET     HAL_GPIO_WritePin(MCU_DIO2_GPIO_Port, MCU_DIO2_Pin, GPIO_PIN_RESET);

#define WRITE_OUT3_SET     HAL_GPIO_WritePin(MCU_DIO3_GPIO_Port, MCU_DIO3_Pin, GPIO_PIN_SET);
#define WRITE_OUT3_RESET     HAL_GPIO_WritePin(MCU_DIO3_GPIO_Port, MCU_DIO3_Pin, GPIO_PIN_RESET);

#define WRITE_OUT4_SET     HAL_GPIO_WritePin(MCU_DIO4_GPIO_Port, MCU_DIO4_Pin, GPIO_PIN_SET);
#define WRITE_OUT4_RESET     HAL_GPIO_WritePin(MCU_DIO4_GPIO_Port, MCU_DIO4_Pin, GPIO_PIN_RESET);

#define WRITE_OUT5_SET     HAL_GPIO_WritePin(MCU_DIO5_GPIO_Port, MCU_DIO5_Pin, GPIO_PIN_SET);
#define WRITE_OUT5_RESET     HAL_GPIO_WritePin(MCU_DIO5_GPIO_Port, MCU_DIO5_Pin, GPIO_PIN_RESET);

#define WRITE_OUT6_SET     HAL_GPIO_WritePin(MCU_DIO6_GPIO_Port, MCU_DIO6_Pin, GPIO_PIN_SET);
#define WRITE_OUT6_RESET     HAL_GPIO_WritePin(MCU_DIO6_GPIO_Port, MCU_DIO6_Pin, GPIO_PIN_RESET);

#define WRITE_OUT7_SET     HAL_GPIO_WritePin(MCU_DIO7_GPIO_Port, MCU_DIO7_Pin, GPIO_PIN_SET);
#define WRITE_OUT7_RESET     HAL_GPIO_WritePin(MCU_DIO7_GPIO_Port, MCU_DIO7_Pin, GPIO_PIN_RESET);

#define WRITE_OUT8_SET     HAL_GPIO_WritePin(MCU_DIO8_GPIO_Port, MCU_DIO8_Pin, GPIO_PIN_SET);
#define WRITE_OUT8_RESET     HAL_GPIO_WritePin(MCU_DIO8_GPIO_Port, MCU_DIO8_Pin, GPIO_PIN_RESET);


#define ON_STATE            1
#define OFF_STATE           0
#define INVERSE             1

#define ERROR_DEBUG         1

void GPIO_Startup_Init(void);
void dio_readInputStatus(void);
void dio_writeOutputStatus(void);
void dio_inputTestInit(void);
void dio_resetTransitionCounters(void);
void dio_checkSoftwareReset(void);
void dio_checkOperationSuccess(void);
void dio_checkFlashOperation(void);
void dio_startUpRoutine(void);
void dio_checkAllInputParams(void);
void dio_timeProcess(void);
void dio_clearTimeProcess(void);

typedef struct
{
  uint8_t CH1:1;
  uint8_t CH2:1;
  uint8_t CH3:1;
  uint8_t CH4:1;
  uint8_t CH5:1;
  uint8_t CH6:1;
  uint8_t CH7:1;
  uint8_t CH8:1;
  uint8_t CH9:1;
  uint8_t CH10:1;
  uint8_t CH11:1;
  uint8_t CH12:1;
  uint8_t CH13:1;
  uint8_t CH14:1;
  uint8_t CH15:1;
  uint8_t CH16:1;
	uint32_t ulas1;
	uint32_t ulas2;
	uint32_t ALL;
}Typedef_inputStatus;

typedef struct
{
  uint32_t CH1;
  uint32_t CH2;
  uint32_t CH3;
  uint32_t CH4;
  uint32_t CH5;
  uint32_t CH6;
  uint32_t CH7;
  uint32_t CH8;
  uint32_t CH9;
  uint32_t CH10;
  uint32_t CH11;
  uint32_t CH12;
  uint32_t CH13;
  uint32_t CH14;
  uint32_t CH15;
  uint32_t CH16;
}Typedef_inputStatusChangeCnt;

typedef struct
{
  uint8_t CH1:1;
  uint8_t CH2:1;
  uint8_t CH3:1;
  uint8_t CH4:1;
  uint8_t CH5:1;
  uint8_t CH6:1;
  uint8_t CH7:1;
  uint8_t CH8:1;
	uint8_t ALL;
}Typedef_outputStatus;

typedef struct
{
  uint8_t CH1:1;
  uint8_t CH2:1;
  uint8_t CH3:1;
  uint8_t CH4:1;
  uint8_t CH5:1;
  uint8_t CH6:1;
  uint8_t CH7:1;
  uint8_t CH8:1;
}Typedef_outputControlFlag;

typedef struct
{
  uint32_t CH1;
  uint32_t CH2;
  uint32_t CH3;
  uint32_t CH4;
  uint32_t CH5;
  uint32_t CH6;
  uint32_t CH7;
  uint32_t CH8;
}Typedef_outputControlCounter;

typedef struct
{
  uint32_t CH1;
  uint32_t CH2;
  uint32_t CH3;
  uint32_t CH4;
  uint32_t CH5;
  uint32_t CH6;
  uint32_t CH7;
  uint32_t CH8;
}Typedef_relayLatchTimeOut;

typedef struct
{
  uint8_t CH1:1;
  uint8_t CH2:1;
  uint8_t CH3:1;
  uint8_t CH4:1;
  uint8_t CH5:1;
  uint8_t CH6:1;
  uint8_t CH7:1;
  uint8_t CH8:1;
	uint16_t ALL;
}Typedef_relayLatchType;

typedef struct
{
	uint32_t ACTIVE;
	uint8_t CH1:1;
	uint8_t CH2:1;
	uint8_t CH3:1;
	uint8_t CH4:1;
	uint8_t CH5:1;
	uint8_t CH6:1;
	uint8_t CH7:1;
	uint8_t CH8:1;
	uint8_t CH9:1;
	uint8_t CH10:1;
	uint8_t CH11:1;
	uint8_t CH12:1;
	uint8_t CH13:1;
	uint8_t CH14:1;
	uint8_t CH15:1;
	uint8_t CH16:1;
}Typedef_inputTest;

typedef struct
{
	uint16_t CH1;
	uint16_t CH2;
	uint16_t CH3;
	uint16_t CH4;
	uint16_t CH5;
	uint16_t CH6;
	uint16_t CH7;
	uint16_t CH8;
	uint16_t CH9;
	uint16_t CH10;
	uint16_t CH11;
	uint16_t CH12;
	uint16_t CH13;
	uint16_t CH14;
	uint16_t CH15;
	uint16_t CH16;
}Typedef_inputTransitionParams;

typedef struct 
{
  uint8_t  softwareReset:1;
  uint32_t relayLatchTimeOut;
  uint32_t latchType;
  uint8_t flashSaveAll:1;
  uint8_t resetTransitionCounters:1;
	uint8_t inputTestMode:1;
	uint8_t uartBaudRate;
  uint32_t operationSuccess;
	uint32_t milisecond;
	uint32_t second;
	uint32_t minute;
	uint32_t hour;
	uint16_t runTimeErrorCounter;
}Typedef_deviceParams;

extern void dio_checkSoftwareReset(void);
extern void dio_checkOperationSuccess(void);
extern void dio_checkFlashOperation(void);
extern void dio_startUpRoutine(void);
extern void dio_checkAllInputParams(void);
extern void dio_timeProcess(void);
extern void dio_clearTimeProcess(void);

extern Typedef_inputStatus inputStatus;
extern Typedef_inputStatus inputStatus_NP;
extern Typedef_outputStatus outputStatus;
extern Typedef_inputStatusChangeCnt inputStatusChangeCnt;
extern Typedef_outputControlFlag outputControlFlag;
extern Typedef_outputControlCounter outputControlCounter;
extern Typedef_relayLatchTimeOut relayLatchTimeOut;
extern Typedef_relayLatchType relayLatchType;
extern Typedef_inputTest inputTest;
extern Typedef_inputTest inputPolarity;
extern Typedef_inputTransitionParams inputONCnt;
extern Typedef_inputTransitionParams inputOFFCnt;
extern Typedef_inputTransitionParams inputLowToHighTranCnt;
extern Typedef_inputTransitionParams inputHighToLowTranCnt;
extern Typedef_inputTransitionParams inputFilterTimeOut;
extern Typedef_inputTransitionParams inputTransitionFlag;
extern Typedef_deviceParams deviceParams;

#endif /* DIO_H */

