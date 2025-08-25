/**
  *****************************************************************************
  * @file    AdcProcess.c
  * @author  Serbay Ozkan
  * @version V1.0.0
  * @date    13-November-2016
  * @brief   Microchip MCP3914 and MCP3919 Analog-Front-End Reading Source File
  *****************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"
#include "spi.h"
#include "Adc_Process.h"
#include "Calibration.h"

/* Typedefs ------------------------------------------------------------------*/
Typedef_ADC_Shift_Registers ADC_Shift_Register;
Typedef_ADC_Values ADC_Values;
Typedef_ADC_Result ADC_Result;
Typedef_currentADCInternalRegisters currentADC1InternalRegisters;
Typedef_currentADCInternalRegisters voltageADCInternalRegisters;
Typedef_deviceParams deviceParams;
Typedef_userInterface turnRatio;
Typedef_userInterface polarity;
/* User varibles -------------------------------------------------------------*/
uint32_t adc_ReceiveDataBuffer[8];
uint32_t scalingCH1 = 1, scalingCH2 = 1, scalingCH3 = 1;


/**
  * @brief  This function reads all channels of MCP3919 ADC and converting
  			ADC data to processable format
  * @note
  * @param  None
  * @retval None
  */

void adc_readVoltageADC(void)
{
	/* Make chip select low to start communication with selected slave device */
	adc_selectVoltageADC();

	/* Send data request to external ADC */
	adc_transmitData(MCP39XX_CONTROL_BYTE, 1, 10);

	/* Receive requested data from slave device and convert to processable format */
	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	ADC_Result.VCH1 = (ADC_Shift_Register.adcShiftData_Res << 8) - VCH1_OFFSET;
	ADC_Values.VCH1 = (ADC_Result.VCH1 / 256) * ADC_CONVERSION_CONSTANT * VCH1_SCALE * turnRatio.VCH1;

	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	ADC_Result.VCH2 = (ADC_Shift_Register.adcShiftData_Res << 8) - VCH2_OFFSET;
	ADC_Values.VCH2 = (ADC_Result.VCH2 / 256) * ADC_CONVERSION_CONSTANT * VCH2_SCALE * turnRatio.VCH2;

	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	ADC_Result.VCH3 = (ADC_Shift_Register.adcShiftData_Res << 8) - VCH3_OFFSET;
	ADC_Values.VCH3 = (ADC_Result.VCH3 / 256) * ADC_CONVERSION_CONSTANT * VCH3_SCALE * turnRatio.VCH3;

	/* Calculate phase-to-phase voltages from phase-to-notr voltages */
	ADC_Values.VCH12 = ADC_Values.VCH1 - ADC_Values.VCH2;
	ADC_Values.VCH23 = ADC_Values.VCH2 - ADC_Values.VCH3;
	ADC_Values.VCH31 = ADC_Values.VCH3 - ADC_Values.VCH1;

	/* Make chip select high to terminate communication with selected slave device */
	adc_deselectVoltageADC();
}

void adc_readCurrentADC1(void)
{
	/* Make chip select low to start communication with selected slave device */
	adc_selectCurrentADC1();

	/* Send data request to external ADC */
	adc_transmitData(MCP39XX_CONTROL_BYTE, 1, 1);

	/* Receive requested data from slave device and convert to processable format */
	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	ADC_Result.ICH1 = (ADC_Shift_Register.adcShiftData_Res << 8) - ICH1_OFFSET;
	ADC_Values.ICH1 = (ADC_Result.ICH1 / 256) * ADC_CONVERSION_CONSTANT * ICH1_SCALE * turnRatio.ICH1 * polarity.ICH1;

	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	ADC_Result.ICH2 = (ADC_Shift_Register.adcShiftData_Res << 8) - ICH2_OFFSET;
	ADC_Values.ICH2 = (ADC_Result.ICH2 / 256) * ADC_CONVERSION_CONSTANT * ICH2_SCALE * turnRatio.ICH2 * polarity.ICH2;

	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	ADC_Result.ICH3 = (ADC_Shift_Register.adcShiftData_Res << 8) - ICH3_OFFSET;
	ADC_Values.ICH3 = (ADC_Result.ICH3 / 256) * ADC_CONVERSION_CONSTANT * ICH3_SCALE * turnRatio.ICH3 * polarity.ICH3;
	
	ADC_Values.ICHN_feeder1 = ADC_Values.ICH1 + ADC_Values.ICH2 + ADC_Values.ICH3;

	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	ADC_Result.ICH4 = (ADC_Shift_Register.adcShiftData_Res << 8) - ICH4_OFFSET;
	ADC_Values.ICH4 = (ADC_Result.ICH4 / 256) * ADC_CONVERSION_CONSTANT * ICH4_SCALE * turnRatio.ICH4 * polarity.ICH4;

	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	ADC_Result.ICH5 = (ADC_Shift_Register.adcShiftData_Res << 8) - ICH5_OFFSET;
	ADC_Values.ICH5 = (ADC_Result.ICH5 / 256) * ADC_CONVERSION_CONSTANT * ICH5_SCALE * turnRatio.ICH5 * polarity.ICH5;

	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	ADC_Result.ICH6 = (ADC_Shift_Register.adcShiftData_Res << 8) - ICH6_OFFSET;
	ADC_Values.ICH6 = (ADC_Result.ICH6 / 256) * ADC_CONVERSION_CONSTANT * ICH6_SCALE * turnRatio.ICH6 * polarity.ICH6;
	
	ADC_Values.ICHN_feeder2 = ADC_Values.ICH4 + ADC_Values.ICH5 + ADC_Values.ICH6;
	
	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	ADC_Result.ICH7 = (ADC_Shift_Register.adcShiftData_Res << 8) - ICH7_OFFSET;
	ADC_Values.ICH7 = (ADC_Result.ICH7 / 256) * ADC_CONVERSION_CONSTANT * ICH7_SCALE * turnRatio.ICH7 * polarity.ICH7;

	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	ADC_Result.ICH8 = (ADC_Shift_Register.adcShiftData_Res << 8) - ICH8_OFFSET;
	ADC_Values.ICH8 = (ADC_Result.ICH8 / 256) * ADC_CONVERSION_CONSTANT * ICH8_SCALE * turnRatio.ICH8 * polarity.ICH8;

	/* Make chip select high to terminate communication with selected slave device */
	adc_deselectCurrentADC1();
}


void adc_readCurrentADC2(void)
{
	/* Make chip select low to start communication with selected slave device */
	adc_selectCurrentADC2();

	/* Send data request to external ADC */
	adc_transmitData(MCP39XX_CONTROL_BYTE, 1, 1);

	/* Receive requested data from slave device and convert to processable format */
	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	ADC_Result.ICH9 = (ADC_Shift_Register.adcShiftData_Res << 8) - ICH9_OFFSET;
	ADC_Values.ICH9 = (ADC_Result.ICH9 / 256) * ADC_CONVERSION_CONSTANT * ICH9_SCALE * turnRatio.ICH9 * polarity.ICH9;
	
	ADC_Values.ICHN_feeder3 = ADC_Values.ICH7 + ADC_Values.ICH8 + ADC_Values.ICH9;

	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	ADC_Result.ICH10 = (ADC_Shift_Register.adcShiftData_Res << 8) - ICH10_OFFSET;
	ADC_Values.ICH10 = (ADC_Result.ICH10 / 256) * ADC_CONVERSION_CONSTANT * ICH10_SCALE * turnRatio.ICH10 * polarity.ICH10;

	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	ADC_Result.ICH11 = (ADC_Shift_Register.adcShiftData_Res << 8) - ICH11_OFFSET;
	ADC_Values.ICH11 = (ADC_Result.ICH11 / 256) * ADC_CONVERSION_CONSTANT * ICH11_SCALE * turnRatio.ICH11 * polarity.ICH11;

	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	ADC_Result.ICH12 = (ADC_Shift_Register.adcShiftData_Res << 8) - ICH12_OFFSET;
	ADC_Values.ICH12 = (ADC_Result.ICH12 / 256) * ADC_CONVERSION_CONSTANT * ICH12_SCALE * turnRatio.ICH12 * polarity.ICH12;
	
	ADC_Values.ICHN_feeder4 = ADC_Values.ICH10 + ADC_Values.ICH11 + ADC_Values.ICH12;

	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	ADC_Result.ICH13 = (ADC_Shift_Register.adcShiftData_Res << 8) - ICH13_OFFSET;
	ADC_Values.ICH13 = (ADC_Result.ICH13 / 256) * ADC_CONVERSION_CONSTANT * ICH13_SCALE * turnRatio.ICH13 * polarity.ICH13;

	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	ADC_Result.ICH14 = (ADC_Shift_Register.adcShiftData_Res << 8) - ICH14_OFFSET;
	ADC_Values.ICH14 = (ADC_Result.ICH14 / 256) * ADC_CONVERSION_CONSTANT * ICH14_SCALE * turnRatio.ICH14 * polarity.ICH14;

	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	ADC_Result.ICH15 = (ADC_Shift_Register.adcShiftData_Res << 8) - ICH15_OFFSET;
	ADC_Values.ICH15 = (ADC_Result.ICH15 / 256) * ADC_CONVERSION_CONSTANT * ICH15_SCALE * turnRatio.ICH15 * polarity.ICH15;
	
	ADC_Values.ICHN_feeder5 = ADC_Values.ICH13 + ADC_Values.ICH14 + ADC_Values.ICH15;

	/* Make chip select high to terminate communication with selected slave device */
	adc_deselectCurrentADC2();
}


void adc_writeVoltageADC(unsigned char adress, uint32_t data)
{
	static unsigned char adcWriteAdress;
	adc_selectVoltageADC();
	adcWriteAdress = (adress << 1);
	adcWriteAdress |= 0x40;
	uint8_t ser1 = 0x00;
	uint8_t ser2 = 0x07;
	uint8_t ser3 = 0xC0;
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &adcWriteAdress, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser1, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser2, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser3, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	adc_deselectVoltageADC();
}

void testWrite(void)
{
	  unsigned char adcWriteAdress2;
		adc_selectVoltageADC();
		adcWriteAdress2 = (0x0D << 1);
		adcWriteAdress2 |= 0x40;
		uint8_t ser1 = 0x38;
		uint8_t ser2 = 0x40;
		uint8_t ser3 = 0x50;
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1, &adcWriteAdress2, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser1, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser2, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser3, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		adc_deselectVoltageADC();
}

void testWrite2(void)
{
	  unsigned char adcWriteAdress2;
		adc_selectCurrentADC1();
		adcWriteAdress2 = (MCP3914_CONFIG0 << 1);
		adcWriteAdress2 |= 0x40;
		uint8_t ser1 = 0x38;
		uint8_t ser2 = 0x40;
		uint8_t ser3 = 0x50;
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1, &adcWriteAdress2, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser1, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser2, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser3, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		adc_deselectCurrentADC1();
}

void adc_shutdownVoltageADC(uint8_t status)
{
	if (status == ACTIVE)
	{
		static unsigned char adcWriteAdress;
		adc_selectVoltageADC();
		adcWriteAdress = (MCP3919_CONFIG1 << 1);
		adcWriteAdress |= 0x40;
		uint8_t ser1 = 0x00;
		uint8_t ser2 = 0x07;
		uint8_t ser3 = 0x40;
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1, &adcWriteAdress, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser1, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser2, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser3, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		adc_deselectVoltageADC();
	}

	if (status == INACTIVE)
	{
		static unsigned char adcWriteAdress;
		adc_selectVoltageADC();
		adcWriteAdress = (MCP3919_CONFIG1 << 1);
		adcWriteAdress |= 0x40;
		uint8_t ser1 = 0x00;
		uint8_t ser2 = 0x00;
		uint8_t ser3 = 0x40;
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1, &adcWriteAdress, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser1, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser2, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser3, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		adc_deselectVoltageADC();
	}
}

void adc_shutdownCurrentADC1(uint8_t status)
{
	if(status == ACTIVE)
	{
		unsigned char adcWriteAdress2;
		adc_selectCurrentADC1();
		adcWriteAdress2 = (MCP3914_CONFIG1 << 1);
		adcWriteAdress2 |= 0x40;
		uint8_t ser1 = 0x00;
		uint8_t ser2 = 0xFF;
		uint8_t ser3 = 0x40;
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1, &adcWriteAdress2, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser1, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser2, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser3, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		adc_deselectCurrentADC1();
	}

	if(status == INACTIVE)
	{
		unsigned char adcWriteAdress2;
		adc_selectCurrentADC1();
		adcWriteAdress2 = (MCP3914_CONFIG1 << 1);
		adcWriteAdress2 |= 0x40;
		uint8_t ser1 = 0x00;
		uint8_t ser2 = 0x00;
		uint8_t ser3 = 0x40;
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1, &adcWriteAdress2, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser1, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser2, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser3, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		adc_deselectCurrentADC1();
	}
}

void adc_shutdownCurrentADC2(uint8_t status)
{
	if(status == ACTIVE)
	{
		unsigned char adcWriteAdress2;
		adc_selectCurrentADC2();
		adcWriteAdress2 = (MCP3914_CONFIG1 << 1);
		adcWriteAdress2 |= 0x40;
		uint8_t ser1 = 0x00;
		uint8_t ser2 = 0xFF;
		uint8_t ser3 = 0x40;
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1, &adcWriteAdress2, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser1, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser2, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser3, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		adc_deselectCurrentADC2();
	}

	if(status == INACTIVE)
	{
		unsigned char adcWriteAdress2;
		adc_selectCurrentADC2();
		adcWriteAdress2 = (MCP3914_CONFIG1 << 1);
		adcWriteAdress2 |= 0x40;
		uint8_t ser1 = 0x00;
		uint8_t ser2 = 0x00;
		uint8_t ser3 = 0x40;
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1, &adcWriteAdress2, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser1, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser2, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser3, 1, 1);
		while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
		adc_deselectCurrentADC2();
	}
}

void adc_writeVoltageADC_2(unsigned char adress, uint32_t data)
{
	static unsigned char adcWriteAdress;
	adc_selectVoltageADC();
	adcWriteAdress = (adress << 1);
	adcWriteAdress |= 0x40;
	uint8_t ser1 = 0x00;
	uint8_t ser2 = 0x00;
	uint8_t ser3 = 0x40;
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &adcWriteAdress, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser1, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser2, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser3, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	adc_deselectVoltageADC();
}

void adc_writeCurrentADC1(unsigned char adress2, uint32_t data2)
{
	unsigned char adcWriteAdress2;
	adc_selectCurrentADC1();
	adcWriteAdress2 = (adress2 << 1);
	adcWriteAdress2 |= 0x40;
	uint8_t ser1 = 0x00;
	uint8_t ser2 = 0xFF;
	uint8_t ser3 = 0x40;
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &adcWriteAdress2, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser1, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser2, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser3, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	adc_deselectCurrentADC1();
}

void adc_writeCurrentADC1_2(unsigned char adress2, uint32_t data2)
{
	unsigned char adcWriteAdress2;
	adc_selectCurrentADC1();
	adcWriteAdress2 = (adress2 << 1);
	adcWriteAdress2 |= 0x40;
	uint8_t ser1 = 0x00;
	uint8_t ser2 = 0x00;
	uint8_t ser3 = 0x40;
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &adcWriteAdress2, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser1, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser2, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser3, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	adc_deselectCurrentADC1();
}

void adc_writeCurrentADC2(unsigned char adress, uint32_t data)
{
	unsigned char adcWriteAdress2;
	adc_selectCurrentADC2();
	adcWriteAdress2 = (adress << 1);
	adcWriteAdress2 |= 0x40;
	uint8_t ser1 = 0x00;
	uint8_t ser2 = 0xFF;
	uint8_t ser3 = 0x40;
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &adcWriteAdress2, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser1, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser2, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser3, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	adc_deselectCurrentADC2();
}

void adc_writeCurrentADC2_2(unsigned char adress, uint32_t data)
{
	unsigned char adcWriteAdress2;
	adc_selectCurrentADC2();
	adcWriteAdress2 = (adress << 1);
	adcWriteAdress2 |= 0x40;
	uint8_t ser1 = 0x00;
	uint8_t ser2 = 0x00;
	uint8_t ser3 = 0x40;
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &adcWriteAdress2, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser1, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser2, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1,(uint8_t*)&ser3, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	adc_deselectCurrentADC2();
}


void adc_readInternalRegisters(void)
{
	static unsigned char adcReadAdress;
	adc_selectCurrentADC1();
	adcReadAdress = (0x08 << 1);
	adcReadAdress |= 0x41;
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &adcReadAdress, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	adc_ReceiveDataBuffer[0] = 0x00;
	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	currentADC1InternalRegisters.MOD = ADC_Shift_Register.adcShiftData_Res;
	adc_deselectCurrentADC1();

	adc_selectCurrentADC1();
	adcReadAdress = (0x09 << 1);
	adcReadAdress |= 0x41;
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &adcReadAdress, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	adc_ReceiveDataBuffer[0] = 0x00;
	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	currentADC1InternalRegisters.PHASE0 = ADC_Shift_Register.adcShiftData_Res;
	adc_deselectCurrentADC1();

	adc_selectCurrentADC1();
	adcReadAdress = (0x0A << 1);
	adcReadAdress |= 0x41;
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &adcReadAdress, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	adc_ReceiveDataBuffer[0] = 0x00;
	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
  adc_receiveDataSignalConditioning();
	currentADC1InternalRegisters.PHASE1 = ADC_Shift_Register.adcShiftData_Res;
	adc_deselectCurrentADC1();

	adc_selectCurrentADC1();
	adcReadAdress = (0x0B << 1);
	adcReadAdress |= 0x41;
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &adcReadAdress, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	adc_ReceiveDataBuffer[0] = 0x00;
	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	currentADC1InternalRegisters.GAIN = adc_ReceiveDataBuffer[0];
	adc_deselectCurrentADC1();

	adc_selectCurrentADC1();
	adcReadAdress = (0x0C << 1);
	adcReadAdress |= 0x41;
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &adcReadAdress, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	adc_ReceiveDataBuffer[0] = 0x00;
	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	currentADC1InternalRegisters.STATUSCOM = ADC_Shift_Register.adcShiftData_Res;
	adc_deselectCurrentADC1();

	adc_selectCurrentADC1();
	adcReadAdress = (0x0D << 1);
	adcReadAdress |= 0x41;
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &adcReadAdress, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	adc_ReceiveDataBuffer[0] = 0x00;
	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	currentADC1InternalRegisters.CONFIG0 = ADC_Shift_Register.adcShiftData_Res;
	adc_deselectCurrentADC1();

	adc_selectCurrentADC1();
	adcReadAdress = (0x0E << 1);
	adcReadAdress |= 0x41;
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &adcReadAdress, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	adc_ReceiveDataBuffer[0] = 0x00;
	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	currentADC1InternalRegisters.CONFIG1 = ADC_Shift_Register.adcShiftData_Res;
	adc_deselectCurrentADC1();

}

void adc_readInternalRegisters_Voltage(void)
{
	static unsigned char adcReadAdress;
	adc_selectVoltageADC();
	adcReadAdress = (0x08 << 1);
	adcReadAdress |= 0x41;
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &adcReadAdress, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	adc_ReceiveDataBuffer[0] = 0x00;
	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	voltageADCInternalRegisters.MOD = ADC_Shift_Register.adcShiftData_Res;
	adc_deselectVoltageADC();

	adc_selectVoltageADC();
	adcReadAdress = (0x0A << 1);
	adcReadAdress |= 0x41;
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &adcReadAdress, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	adc_ReceiveDataBuffer[0] = 0x00;
	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	voltageADCInternalRegisters.PHASE0 = ADC_Shift_Register.adcShiftData_Res;
	adc_deselectVoltageADC();

	adc_selectVoltageADC();
	adcReadAdress = (0x0B << 1);
	adcReadAdress |= 0x41;
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &adcReadAdress, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	adc_ReceiveDataBuffer[0] = 0x00;
	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	voltageADCInternalRegisters.GAIN = ADC_Shift_Register.adcShiftData_Res;
	adc_deselectVoltageADC();

	adc_selectVoltageADC();
	adcReadAdress = (0x0C << 1);
	adcReadAdress |= 0x41;
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &adcReadAdress, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	adc_ReceiveDataBuffer[0] = 0x00;
	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	voltageADCInternalRegisters.STATUSCOM = ADC_Shift_Register.adcShiftData_Res;
	adc_deselectVoltageADC();

	adc_selectVoltageADC();
	adcReadAdress = (0x0D << 1);
	adcReadAdress |= 0x41;
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &adcReadAdress, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	adc_ReceiveDataBuffer[0] = 0x00;
	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	voltageADCInternalRegisters.CONFIG0 = ADC_Shift_Register.adcShiftData_Res;
	adc_deselectVoltageADC();

	adc_selectVoltageADC();
	adcReadAdress = (0x0E << 1);
	adcReadAdress |= 0x41;
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &adcReadAdress, 1, 1);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	adc_ReceiveDataBuffer[0] = 0x00;
	adc_receiveData((uint8_t*)adc_ReceiveDataBuffer, 3, 1);
	adc_receiveDataSignalConditioning();
	voltageADCInternalRegisters.CONFIG1 = ADC_Shift_Register.adcShiftData_Res;
	adc_deselectVoltageADC();

}

/**
  * @brief  This function sends data request registers to external ADC
  * @note   This function is platform-specific and it should be rearranged
  			when using with other platforms
  *
  * @param  controlByte : Control byte contains two device adress bits A<6:5>,
  			five register adress bits A<4:0> and Read/Write bit (R/W).
  * @param  transmitDataSize : Number of bytes transmitting to slave device
  * @param  requestTimeout : Data transmission timeout duration
  * @retval None
  */

void adc_transmitData(uint8_t controlByte, uint16_t transmitDataSize, uint32_t transmitTimeout)
{
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &controlByte, transmitDataSize, transmitTimeout);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
}


/**
  * @brief  This function receive data from master device
  * @note   This function is platform-specific and it should be rearranged
  			when using with other platforms
  *
  * @param  receiveDataBuffer : Buffer array for receive data coming from ADC
  * @param  receiveDataSize : Number of bytes receiving from master device
  * @param  receiveTimeout : Data receive timeout duration
  * @retval None
  */

void adc_receiveData(uint8_t receiveDataBuffer[], uint16_t receiveDataSize, uint32_t receiveTimeout)
{
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Receive(&hspi1, (uint8_t*)receiveDataBuffer, receiveDataSize, receiveTimeout);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
}


/**
  * @brief  This function combines higher and lower bytes of 24 bit ADC frame
  			in correct way
  * @note   This function is platform-specific and it should be rearranged
  			when using with other platforms
  * @param  None
  * @retval None
  */

void adc_receiveDataSignalConditioning(void)
{
	ADC_Shift_Register.adcShiftData_S1  = adc_ReceiveDataBuffer[0] & 0x0000FF;
	ADC_Shift_Register.adcShiftData_S2  = adc_ReceiveDataBuffer[0] & 0x00FF00;
	ADC_Shift_Register.adcShiftData_S3  = adc_ReceiveDataBuffer[0] & 0xFF0000;
	ADC_Shift_Register.adcShiftData_Res = (ADC_Shift_Register.adcShiftData_S1 << 16) |
										  (ADC_Shift_Register.adcShiftData_S2) |
										  (ADC_Shift_Register.adcShiftData_S3 >> 16);
}



/**
  * @brief  These functions selects voltage and current adc by driving related
  			chip select pin driving high-to-low
  * @note   These functions are platform-specific and it should be rearranged
  			when using with other platforms
  *
  * @param  None
  * @retval None
  */

void adc_selectVoltageADC(void)
{
	HAL_GPIO_WritePin(ADC_CS1_GPIO_Port,ADC_CS1_Pin,GPIO_PIN_RESET);
}

void adc_selectCurrentADC1(void)
{
	HAL_GPIO_WritePin(ADC_CS2_GPIO_Port,ADC_CS2_Pin,GPIO_PIN_RESET);
}

void adc_selectCurrentADC2(void)
{
	HAL_GPIO_WritePin(ADC_CS3_GPIO_Port,ADC_CS3_Pin,GPIO_PIN_RESET);
}



/**
  * @brief  These functions deselects current and voltage adc by driving related
  			chip select pin driving low-to-high
  * @note   These functions are platform-specific and it should be rearranged
  			when using with other platforms
  *
  * @param  None
  * @retval None
  */


void adc_deselectVoltageADC(void)
{
	HAL_GPIO_WritePin(ADC_CS1_GPIO_Port,ADC_CS1_Pin,GPIO_PIN_SET);
}

void adc_deselectCurrentADC1(void)
{
	HAL_GPIO_WritePin(ADC_CS2_GPIO_Port,ADC_CS2_Pin,GPIO_PIN_SET);
}

void adc_deselectCurrentADC2(void)
{
	HAL_GPIO_WritePin(ADC_CS3_GPIO_Port,ADC_CS3_Pin,GPIO_PIN_SET);
}

void adc_initAnalogFrontEnd(void)
{
	adc_shutdownVoltageADC(ACTIVE);
	adc_shutdownVoltageADC(ACTIVE);
	adc_shutdownCurrentADC1(ACTIVE);
	adc_shutdownCurrentADC1(ACTIVE);
	adc_shutdownCurrentADC2(ACTIVE);
	adc_shutdownCurrentADC2(ACTIVE);
	adc_shutdownVoltageADC(ACTIVE);
	adc_shutdownCurrentADC1(ACTIVE);
	adc_shutdownCurrentADC2(ACTIVE);
	HAL_Delay(1000);
	adc_shutdownVoltageADC(INACTIVE);
	adc_shutdownVoltageADC(INACTIVE);
	adc_shutdownCurrentADC1(INACTIVE);
	adc_shutdownCurrentADC1(INACTIVE);
	adc_shutdownCurrentADC2(INACTIVE);
	adc_shutdownCurrentADC2(INACTIVE);
	adc_shutdownVoltageADC(INACTIVE);
	adc_shutdownCurrentADC1(INACTIVE);
	adc_shutdownCurrentADC2(INACTIVE);
	HAL_Delay(1000);
}


void adc_initIOConfig(void)
{
	HAL_GPIO_WritePin(ADC_CS1_GPIO_Port,ADC_CS1_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(ADC_CS2_GPIO_Port,ADC_CS2_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(ADC_CS3_GPIO_Port,ADC_CS3_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(ADC_RESET_GPIO_Port,ADC_RESET_Pin,GPIO_PIN_SET);
}
