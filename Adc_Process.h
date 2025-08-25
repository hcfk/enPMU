/**
  ****************************************************************************************
  * @file    AdcProcess.h
  * @author  Serbay Ozkan
  * @version V1.0.0
  * @date    13-November-2016
  * @brief   Microchip MCP3914 and MCP3919 External Analog-Front-End Reading Header File
  ****************************************************************************************
  */

#include "stdint.h"

#ifndef ADC_PROCESS_H_
#define ADC_PROCESS_H_

#define TEST_PIN_HIGH   HAL_GPIO_WritePin(FLASH_CS_GPIO_Port, FLASH_CS_Pin, GPIO_PIN_SET);
#define TEST_PIN_LOW    HAL_GPIO_WritePin(FLASH_CS_GPIO_Port, FLASH_CS_Pin, GPIO_PIN_RESET);
#define TEST_PIN_TOGGLE HAL_GPIO_TogglePin(FLASH_CS_GPIO_Port, FLASH_CS_Pin);

#define ACTIVE                   1
#define INACTIVE                 0

#define ADC_CONVERSION_CONSTANT  0.00000009520848592F

#define MCP39XX_CONTROL_BYTE     0X41
#define SHUTDOWN_MCP3919_ON      0x000007C0
#define SHUTDOWN_MCP3919_OFF     0x00000040
#define SHUTDOWN_MCP3914_ON      0x000FFF40
#define SHUTDOWN_MCP3914_OFF     0x00000040

/* MCP3919 Internal Registers */
#define MCP3919_MOD           0x08
#define MCP3919_PHASE         0x0A
#define MCP3919_GAIN          0x0B
#define MCP3919_STATUSCOM     0x0C
#define MCP3919_CONFIG0       0x0D
#define MCP3919_CONFIG1       0x0E
#define MCP3919_OFFCAL_CH0    0x0F
#define MCP3919_GAINCAL_CH0   0x10
#define MCP3919_OFFCAL_CH1    0x11
#define MCP3919_GAINCAL_CH1   0x12
#define MCP3919_OFFCAL_CH2    0x13
#define MCP3919_GAINCAL_CH2   0x14
#define MCP3919_LOCK_CRC      0x1F

/* MCP3914 Internal Registers */
#define MCP3914_MOD            0x08
#define MCP3914_PHASE0         0x09
#define MCP3914_PHASE1         0x0A
#define MCP3914_GAIN           0x0B
#define MCP3914_STATUSCOM      0x0C
#define MCP3914_CONFIG0        0x0D
#define MCP3914_CONFIG1        0x0E
#define MCP3914_OFFCAL_CH0     0x0F
#define MCP3914_GAINCAL_CH0    0x10
#define MCP3914_OFFCAL_CH1     0x11
#define MCP3914_GAINCAL_CH1    0x12
#define MCP3914_OFFCAL_CH2     0x13
#define MCP3914_GAINCAL_CH2    0x14
#define MCP3914_OFFCAL_CH3     0x15
#define MCP3914_GAINCAL_CH3    0x16
#define MCP3914_OFFCAL_CH4     0x17
#define MCP3914_GAINCAL_CH4    0x18
#define MCP3914_OFFCAL_CH5     0x19
#define MCP3914_GAINCAL_CH5    0x1A
#define MCP3914_OFFCAL_CH6     0x1B
#define MCP3914_GAINCAL_CH6    0x1C
#define MCP3914_OFFCAL_CH7     0x1D
#define MCP3914_GAINCAL_CH7    0x1E
#define MCP3914_LOCK_CRC       0x1F

void adc_readVoltageADC(void);
void adc_readCurrentADC1(void);
void adc_readCurrentADC2(void);
void adc_transmitData(uint8_t controlByte, uint16_t transmitDataSize, uint32_t transmitTimeout);
void adc_receiveData(uint8_t receiveDataBuffer[], uint16_t receiveDataSize, uint32_t receiveTimeout);
void adc_writeVoltageADC(unsigned char adress, uint32_t data);
void adc_writeVoltageADC_2(unsigned char adress, uint32_t data);
void adc_writeCurrentADC1(unsigned char adress, uint32_t data);
void adc_writeCurrentADC1_2(unsigned char adress2, uint32_t data2);
void adc_writeCurrentADC2(unsigned char adress, uint32_t data);
void adc_writeCurrentADC2_2(unsigned char adress, uint32_t data);
void adc_receiveDataSignalConditioning(void);
void adc_deselectVoltageADC(void);
void adc_deselectCurrentADC1(void);
void adc_deselectCurrentADC2(void);
void adc_selectVoltageADC(void);
void adc_selectCurrentADC1(void);
void adc_selectCurrentADC2(void);
void adc_initIOConfig(void);
void adc_readInternalRegisters(void);
void adc_initAnalogFrontEnd(void);
void adc_shutdownVoltageADC(uint8_t status);
void adc_shutdownCurrentADC1(uint8_t status);
void adc_shutdownCurrentADC2(uint8_t status);
void adc_readInternalRegisters_Voltage(void);
void testWrite(void);
void testWrite2(void);

extern void adc_initIOConfig(void);
extern void adc_initAnalogFrontEnd(void);
extern void adc_readInternalRegisters(void);
extern void adc_shutdownVoltageADC(uint8_t status);
extern void adc_shutdownCurrentADC1(uint8_t status);
extern void adc_shutdownCurrentADC2(uint8_t status);
extern void adc_readInternalRegisters_Voltage(void);
extern void testWrite(void);
extern void testWrite2(void);
typedef struct
{
	int32_t adcShiftData_S1;
	int32_t adcShiftData_S2;
	int32_t adcShiftData_S3;
	int32_t adcShiftData_Res;
}Typedef_ADC_Shift_Registers;

typedef struct
{
	float VCH1;
	float VCH2;
	float VCH3;
	float VCH12;
	float VCH23;
	float VCH31;
	float ICH1;
	float ICH2;
	float ICH3;
	float ICH4;
	float ICH5;
	float ICH6;
	float ICH7;
	float ICH8;
	float ICH9;
	float ICH10;
	float ICH11;
	float ICH12;
	float ICH13;
	float ICH14;
	float ICH15;
	float ICHN_feeder1;
	float ICHN_feeder2;
	float ICHN_feeder3;
	float ICHN_feeder4;
	float ICHN_feeder5;
}Typedef_ADC_Values;

typedef struct
{
	int32_t VCH1;
	int32_t VCH2;
	int32_t VCH3;
	int32_t VCH12;
	int32_t VCH23;
	int32_t VCH31;
	int32_t ICH1;
	int32_t ICH2;
	int32_t ICH3;
	int32_t ICH4;
	int32_t ICH5;
	int32_t ICH6;
	int32_t ICH7;
	int32_t ICH8;
	int32_t ICH9;
	int32_t ICH10;
	int32_t ICH11;
	int32_t ICH12;
	int32_t ICH13;
	int32_t ICH14;
	int32_t ICH15;
}Typedef_ADC_Result;

typedef struct
{
	int16_t VCH1;
	int16_t VCH2;
	int16_t VCH3;
	int16_t ICH1;
	int16_t ICH2;
	int16_t ICH3;
	int16_t ICH4;
	int16_t ICH5;
	int16_t ICH6;
	int16_t ICH7;
	int16_t ICH8;
	int16_t ICH9;
	int16_t ICH10;
	int16_t ICH11;
	int16_t ICH12;
	int16_t ICH13;
	int16_t ICH14;
	int16_t ICH15;
}Typedef_userInterface;

typedef struct
{
		uint32_t MOD;
		uint32_t PHASE0;
		uint32_t PHASE1;
		uint32_t GAIN;
		uint32_t STATUSCOM;
		uint32_t CONFIG0;
		uint32_t CONFIG1;
		uint32_t OFFCAL_CH0;
		uint32_t GAINCAL_CH0;
		uint32_t OFFCAL_CH1;
		uint32_t GAINCAL_CH1;
		uint32_t OFFCAL_CH2;
		uint32_t GAINCAL_CH2;
		uint32_t OFFCAL_CH3;
		uint32_t GAINCAL_CH3;
		uint32_t OFFCAL_CH4;
		uint32_t GAINCAL_CH4;
		uint32_t OFFCAL_CH5;
		uint32_t GAINCAL_CH5;
		uint32_t OFFCAL_CH6;
		uint32_t GAINCAL_CH6;
		uint32_t OFFCAL_CH7;
		uint32_t GAINCAL_CH7;
		uint32_t LOCK_CRC;
}Typedef_currentADCInternalRegisters;

typedef struct
{
	uint16_t dataReadyFlag:1;
	uint32_t runtimeSuccess;
	uint32_t adcSuccess;
	uint32_t adcFailCounter;
	uint16_t adcFailFlag:1;
	uint16_t debugControl:1;
	uint16_t softwareReset:1;
	uint16_t saveEnergyRegisters:1;
	uint16_t uniqueID;
	uint8_t  baudRate;
	uint32_t dummy1;
	uint32_t dummy2;
	uint32_t milisecond;
	uint32_t second;
	uint32_t minute;
	uint32_t minute2;
	uint32_t hour;
	uint32_t errorHandlerCounter;
	uint32_t slaveID[5];
}Typedef_deviceParams;

extern Typedef_ADC_Values ADC_Values;
extern Typedef_ADC_Result ADC_Result;
extern Typedef_deviceParams deviceParams;
extern Typedef_userInterface turnRatio;
extern Typedef_userInterface polarity;
#endif /* ADC_PROCESS_H_ */
