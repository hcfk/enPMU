/**
  ******************************************************************************
  * @file    Modbus_RTU_Slave.c
  * @author  Serbay Ozkan
  * @version V1.0.1
  * @date    06-March-2017
  * @brief   Modbus RTU Slave Application Layer File
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>
#include "usart.h"
#include "Modbus_RTU_Slave.h"

/* User Specific Includes  ---------------------------------------------------*/
#include "flash.h"
#include "RMS_Calculation.h"
#include "PQ_Calculation.h"
#include "ADC_Process.h"
#include "spectra.h"
#include "bootloader.h"

/* Typedefs ------------------------------------------------------------------*/
Typedef_rtuCRC           rtuCRC;
Typedef_modbusParams     modbusParams;
Typedef_channelReference channelReference;
/**
  * @brief  This function performs Modbus CRC16 generation.
  * @param  crcBuf:Input buffer that contains related registers to be calculated
  * @param  crcLength: CRC16 length
  * @retval None
  */

void rtu_crcCalculation(unsigned char *crcBuf, uint16_t crcLength)
{
   uint16_t crcTemp, crcRes;
   uint16_t i, j;
   crcRes = 0xFFFF;

    for (i = 0; i < crcLength; i++)
    {
      crcRes = crcRes ^ crcBuf[i];
      for ( j = 0; j < 8; j++)
      {
        crcTemp = crcRes & 0x0001;
        crcRes = crcRes >> 1;
        if (crcTemp)
        {
            crcRes = crcRes ^ 0xa001;
        }
      }
    }
    rtuCRC.calculated = crcRes;
    rtuCRC.calculated_L = (crcRes & 0XFF00) >> 8 ;
    rtuCRC.calculated_H = (crcRes & 0X00FF);
}

/**
  * @brief  This function performs incoming RTU data frame processing and
  			extracts all modbus master requests and returns from function when
  			unexpected frame is received.
  * @note   After debug operation, DEBUG flag should be reset in header file
  			not to add additional delay to real-time process.
  * @param  none
  * @retval None
  */

void rtu_ModbusFrameProcessing(void)
{

	  uint16_t i;

    for (i = 0; i < TOT_NUM_OF_INT_SLAVE_DEVICES; i++)
    {
      if (modbusParams.modbusRxBuffer[SLAVE_ID] == modbusParams.deviceSlaveID[i] || modbusParams.modbusRxBuffer[SLAVE_ID] == 255)
      {
        modbusParams.selectedSlaveID = modbusParams.deviceSlaveID[i];
        #if DEBUG
        printf("Selected device is me \n");
        printf("Request device id is %d \n", modbusParams.selectedSlaveID);
        #endif
        break;
      }

      if (i == TOT_NUM_OF_INT_SLAVE_DEVICES - 1 )
      {
        #if DEBUG
        printf("Selected device is not me \n");
        #endif
				rtu_transmitDisable_receiveEnable();
        return;
      }
    }


    modbusParams.regAdress = (modbusParams.modbusRxBuffer[REG_ADRESS_HIGH] << 8) | modbusParams.modbusRxBuffer[REG_ADRESS_LOW];

    if (modbusParams.regAdress >= MODBUS_LOWER_LIMIT_ADRESS && modbusParams.regAdress <= MODBUS_UPPER_LIMIT_ADRESS)
    {
      #if DEBUG
      printf("Modbus RTU starting adress is in the range \n");
      printf("Modbus RTU starting adress is %d \n", modbusParams.regAdress);
      #endif
    }

    else
    {
      #if DEBUG
      printf("Modbus RTU starting adress is out of range of device \n");
      #endif
			rtu_transmitDisable_receiveEnable();
      return;
    }

    modbusParams.dataLength = (modbusParams.modbusRxBuffer[DATA_LEN_HIGH] << 8) | modbusParams.modbusRxBuffer[DATA_LEN_LOW];

    if(modbusParams.dataLength <= MODBUS_MAX_DATA_LEN)
    {
      #if DEBUG
      printf("Modbus RTU requested data length is in the range \n");
      printf("Modbus RTU requested data length is %d \n", modbusParams.dataLength);
      #endif
    }

    else
    {
      #if DEBUG
      printf("Modbus RTU requested data length is out of the range \n");
      #endif
			rtu_transmitDisable_receiveEnable();
      return;
    }

    rtuCRC.received_H = modbusParams.modbusRxBuffer[modbusParams.rxIndex - 2];
    rtuCRC.received_L = modbusParams.modbusRxBuffer[modbusParams.rxIndex - 1];
    modbusParams.rxFrameLen = modbusParams.rxIndex - 2;
    rtu_crcCalculation(modbusParams.modbusRxBuffer, modbusParams.rxFrameLen);

    if ((rtuCRC.received_L == rtuCRC.calculated_L) && (rtuCRC.received_H == rtuCRC.calculated_H))
    {
      #if DEBUG
      printf("CRC Check is OK \n");
      #endif
    }

    else
    {
      #if DEBUG
      printf("CRC Check is not OK \n");
      #endif
			rtu_transmitDisable_receiveEnable();
      return;
    }

    modbusParams.startingAdress = modbusParams.regAdress;
    modbusParams.endingAdress = modbusParams.startingAdress + modbusParams.dataLength;
		rtu_transmitEnable_receiveDisable();

    switch(modbusParams.modbusRxBuffer[FUNCODE])
    {
      case READ_HOLDING_REGISTER:
			{
				if(modbusParams.endingAdress > READ_HOLDING_REGISTER_ADRESS_LIMIT )
				{
					#if DEBUG
					printf("Requested data adress and length is not satisfied \n");
					#endif
					rtu_transmitDisable_receiveEnable();
					return;
				}

        if (modbusParams.modbusRxBuffer[SLAVE_ID] == 255)
        {
            rtu_prepareUserInterfaceData();
        }

        else
        {
            rtu_readHoldingRegister();
        }
				
				break;
			}

			case WRITE_SINGLE_REGISTER:
			{
				#if DEBUG
        printf("I am in Single Write function \n");
        printf("modbusParams.regAdress is %d \n"      ,modbusParams.regAdress);
        printf("modbusParams.startingAdress is %d \n" ,modbusParams.startingAdress);
        printf("modbusParams.endingAdress is %d \n"   ,modbusParams.endingAdress);
        printf("modbusParams.dataLength is %d \n"     ,modbusParams.dataLength);
        printf("Selected ID is %d \n"                 ,modbusParams.selectedSlaveID);
				#endif
				rtu_writeSingleRegister();
				break;
			}

      case WRITE_MULTIPLE_REGISTER:
      {
				if(modbusParams.endingAdress > WRITE_MULTIPLE_REGISTER_ADRESS_LIMIT)
				{
					#if DEBUG
					printf("Requested data adress and length is not satisfied \n");
					#endif
					rtu_transmitDisable_receiveEnable();
					return;
				}

				#if DEBUG
        printf("I am in Multiple Write function \n");
        printf("modbusParams.regAdress is %d \n"      ,modbusParams.regAdress);
        printf("modbusParams.startingAdress is %d \n" ,modbusParams.startingAdress);
        printf("modbusParams.endingAdress is %d \n"   ,modbusParams.endingAdress);
        printf("modbusParams.dataLength is %d \n"     ,modbusParams.dataLength);
        printf("Selected ID is %d \n"                 ,modbusParams.selectedSlaveID);
				#endif
        rtu_writeMultipleRegisters();
        break;
      }

			case UNIQUE_FUNCTION_REGISTER:
			{
				#if DEBUG
				printf("I am in Unique Read function \n");
        printf("modbusParams.regAdress is %d \n"       ,modbusParams.regAdress);
        printf("modbusParams.startingAdress is %d \n"  ,modbusParams.startingAdress);
        printf("modbusParams.endingAdress is %d \n"    ,modbusParams.endingAdress);
        printf("modbusParams.dataLength is %d \n"      ,modbusParams.dataLength);
        printf("Selected ID is %d \n"                  ,modbusParams.selectedSlaveID);
				#endif
				rtu_readUniqueRegisters();
				break;
			}

      default:
      {
        #if DEBUG
        printf("Modbus rtu function code is wrong !\n");
        #endif
				rtu_transmitDisable_receiveEnable();
        break;
      }
    }

}

void rtu_readUniqueRegisters(void)
{
	  modbusParams.txBufferIndex = 3;
    modbusParams.modbusTxBuffer[SLAVE_ID] = modbusParams.modbusRxBuffer[SLAVE_ID];
    modbusParams.modbusTxBuffer[FUNCODE]  = modbusParams.modbusRxBuffer[FUNCODE];
    modbusParams.modbusTxBuffer[RES_BYTE_COUNT] = 2 * modbusParams.dataLength;

  if (modbusParams.regAdress == READ_VAN)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.deviceSlaveID[0])) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.deviceSlaveID[0]));
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

	rtu_transmitData_readHoldingRegister();
}


/**
  * @brief  This function includes Modbus RTU Holding Register function
            implementation.
  * @note   This function is written for multiple slave devices in one
            device. Making this function for only one slave ID makes this
            function generic for other platforms.
  * @param  none
  * @retval None
  */

void rtu_readHoldingRegister(void)
{
    modbusParams.txBufferIndex = 3;
    modbusParams.modbusTxBuffer[SLAVE_ID] = modbusParams.modbusRxBuffer[SLAVE_ID];
    modbusParams.modbusTxBuffer[FUNCODE]  = modbusParams.modbusRxBuffer[FUNCODE];
    modbusParams.modbusTxBuffer[RES_BYTE_COUNT] = 2 * modbusParams.dataLength;

    if      (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[0])  rtu_Feeder1DataPrep();
	  else if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[1])  rtu_Feeder1DataPrep();
	  else if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[2])  rtu_Feeder1DataPrep();
	  else if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[3])  rtu_Feeder1DataPrep();
	  else if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[4])  rtu_Feeder1DataPrep();
    else if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[5])  rtu_Feeder1DataPrep();
	  else if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[6])  rtu_Feeder1DataPrep();
	  else if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[7])  rtu_Feeder1DataPrep();
	  else if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[8])  rtu_Feeder1DataPrep();
    else if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[9])  rtu_Feeder1DataPrep();
	  else if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[10]) rtu_Feeder1DataPrep();
	  else if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[11]) rtu_Feeder1DataPrep();
	  else if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[12]) rtu_Feeder1DataPrep();
    else if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[13]) rtu_Feeder1DataPrep();
	  else if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[14]) rtu_Feeder1DataPrep();
	  else return;
}

/**
  * @brief  This function includes Modbus RTU Holding Register function
            implementation.
  * @note   This function is written for multiple slave devices in one
            device. Making this function for only one slave ID makes this
            function generic for other platforms.
  * @param  none
  * @retval None
  */

void rtu_writeMultipleRegisters(void)
{
    if(modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[0]) rtu_getFeeder1_writeMultipleRegisters();
	  else
		{
			rtu_transmitDisable_receiveEnable();
			return;
		}
}


/**
  * @brief  This function includes Modbus RTU Holding Register function
            implementation.
  * @note   This function is written for multiple slave devices in one
            device. Making this function for only one slave ID makes this
            function generic for other platforms.
  * @param  none
  * @retval None
  */
void rtu_getFeeder1_writeMultipleRegisters(void)
{
    modbusParams.rxIndex = 7;
    rtu_Feeder1DataPrep_writeMultipleRegisters();
    rtu_transmitData_writeMultipleRegisters();
}

/**
  * @brief  This function performs modbus RTU response to Modbus Master's request
        according to appropriate slave ID, function code, data adress and
        data length.
  * @note   DMA function is platform specific function. It should be changed
            in other platforms.
  * @param  none
  * @retval None
  */
void rtu_transmitData_writeMultipleRegisters(void)
{
    modbusParams.modbusTxBuffer[0] = modbusParams.modbusRxBuffer[0];
    modbusParams.modbusTxBuffer[1] = modbusParams.modbusRxBuffer[1];
    modbusParams.modbusTxBuffer[2] = modbusParams.modbusRxBuffer[2];
    modbusParams.modbusTxBuffer[3] = modbusParams.modbusRxBuffer[3];
    modbusParams.modbusTxBuffer[4] = modbusParams.modbusRxBuffer[4];
    modbusParams.modbusTxBuffer[5] = modbusParams.modbusRxBuffer[5];
    rtu_crcCalculation(modbusParams.modbusRxBuffer, 6);
    modbusParams.modbusTxBuffer[6] = rtuCRC.calculated_H;
    modbusParams.modbusTxBuffer[7] = rtuCRC.calculated_L;
    HAL_UART_Transmit_IT(&huart6, modbusParams.modbusTxBuffer, 8);
}

/**
  * @brief  This function performs modbus RTU response to Modbus Master's request
        according to appropriate slave ID, function code, data adress and
        data length.
  * @note   DMA function is platform specific function. It should be changed
            in other platforms.
  * @param  none
  * @retval None
  */
void rtu_transmitData_writeSingleRegister(void)
{
    modbusParams.modbusTxBuffer[0] = modbusParams.modbusRxBuffer[0];
    modbusParams.modbusTxBuffer[1] = modbusParams.modbusRxBuffer[1];
    modbusParams.modbusTxBuffer[2] = modbusParams.modbusRxBuffer[2];
    modbusParams.modbusTxBuffer[3] = modbusParams.modbusRxBuffer[3];
    modbusParams.modbusTxBuffer[4] = modbusParams.modbusRxBuffer[4];
    modbusParams.modbusTxBuffer[5] = modbusParams.modbusRxBuffer[5];
    rtu_crcCalculation(modbusParams.modbusRxBuffer, 6);
    modbusParams.modbusTxBuffer[6] = rtuCRC.calculated_H;
    modbusParams.modbusTxBuffer[7] = rtuCRC.calculated_L;
    HAL_UART_Transmit_IT(&huart6, modbusParams.modbusTxBuffer, 8);
}


/**
  * @brief  This function performs modbus RTU response to Modbus Master's request
  			    according to appropriate slave ID, function code, data adress and
  			    data length.
  * @note   DMA function is platform specific function. It should be changed
            in other platforms.
  * @param  none
  * @retval None
  */

void rtu_transmitData_readHoldingRegister(void)
{
    rtu_crcCalculation(modbusParams.modbusTxBuffer, modbusParams.txBufferIndex);
    modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = rtuCRC.calculated_H;
    modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = rtuCRC.calculated_L;
    modbusParams.txLength = modbusParams.txBufferIndex;
    HAL_UART_Transmit_IT(&huart6, modbusParams.modbusTxBuffer, modbusParams.txBufferIndex);
}


void rtu_getFeeder1_writeSingleRegister(void)
{
    rtu_Feeder1DataPrep_singleWriteRegisters();
    rtu_transmitData_writeSingleRegister();
}

void rtu_writeSingleRegister(void)
{
    if(modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[0]) rtu_getFeeder1_writeSingleRegister();
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	  if (huart->Instance == USART6)
		{
		HAL_UART_Receive_IT(&huart6,&modbusParams.receivedData, 1);
		rtu_modbusReceiveCompCallBack();
		}
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART6)
    {
			rtu_transmitDisable_receiveEnable();
			modbusParams.transmitComp = 1;
    }
}


void rtu_modbusReceiveTimeout(void)
{
  modbusParams.recTimeOut++;
  if(modbusParams.recFlag == 1 && modbusParams.recTimeOut == RECEIVE_TIMEOUT)
  {
    modbusParams.recComp = 1;
    modbusParams.recTimeOut = 0;
  }

  if(modbusParams.recTimeOut == 0XFFFF)
  {
    modbusParams.recTimeOut = 0;
  }
}

void rtu_modbusReceiveCompCallBack(void)
{
    modbusParams.modbusRxBuffer[modbusParams.rxIndex++] = modbusParams.receivedData;
    modbusParams.recTimeOut = 0;
    modbusParams.recFlag = 1;
    modbusParams.transmitComp = 0;
}

void rtu_modbusRuntimeProcess(void)
{
   if(modbusParams.recComp == 1 && modbusParams.recFlag == 1)
   {
    rtu_ModbusFrameProcessing();
    modbusParams.rxIndex = 0;
    modbusParams.recComp = 0;
    modbusParams.recFlag = 0;
   }
}

void rtu_transmitEnable_receiveDisable(void)
{
  HAL_GPIO_WritePin(MCU_COM_RTU_GPIO_Port, MCU_COM_RTU_Pin, GPIO_PIN_SET);
  #if DEBUG
  printf("Transmit Enabled, Receive Disabled for RTU Comm \n");
  #endif
}

void rtu_transmitDisable_receiveEnable(void)
{
  HAL_GPIO_WritePin(MCU_COM_RTU_GPIO_Port, MCU_COM_RTU_Pin, GPIO_PIN_RESET);
  #if DEBUG
  printf("Receive Enabled, Transmit Disabled for RTU Comm \n");
  #endif
}


/**
  * @brief  This function prepares all calculated data in device for modbus
  			    response.
  * @note   All data is prepared when the data send over RTU.
            Be careful that when 32 bit data is sent, modbusParams.regAdress is
            increased by two, when 16 bit data is sent, modbusParams.regAdress is
            increased by one.
  * @param  none
  * @retval None
  */

void rtu_genericDataPrep(void)
{
  if (  modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[0]
     || modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[1]
     || modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[2])
  {
    modbusParams.RMS_ICH1 = RMS_Value.ICH1;
	modbusParams.RMS_ICH1_FUND = spect_feeder1_a.foutMag[1];
    modbusParams.RMS_ICH1_3HF =  spect_feeder1_a.foutMag[3];
	  
    modbusParams.RMS_ICH2 = RMS_Value.ICH2;
	modbusParams.RMS_ICH2_FUND = spect_feeder1_b.foutMag[1];
    modbusParams.RMS_ICH2_3HF =  spect_feeder1_b.foutMag[3];
	  
    modbusParams.RMS_ICH3 = RMS_Value.ICH3;
	modbusParams.RMS_ICH3_FUND = spect_feeder1_c.foutMag[1];
    modbusParams.RMS_ICH3_3HF =  spect_feeder1_c.foutMag[3];
	  
    modbusParams.RMS_ICHN = RMS_Value.neutralCurrent_feeder1;
	  
	modbusParams.P_Phase1 =  P.Feeder1_A;
	modbusParams.P_Phase2 =  P.Feeder1_B;
	modbusParams.P_Phase3 =  P.Feeder1_C;	  
    modbusParams.P_total =  P.Feeder1_TOT;
	
	modbusParams.Q_Phase1 = Q_New.Feeder1_A;
	modbusParams.Q_Phase2 = Q_New.Feeder1_B;
	modbusParams.Q_Phase3 = Q_New.Feeder1_C;
    modbusParams.Q_total =  Q_New.Feeder1_TOT;
	
	modbusParams.S_Phase1 =  S_New.Feeder1_A;
	modbusParams.S_Phase2 =  S_New.Feeder1_B;
	modbusParams.S_Phase3 =  S_New.Feeder1_C;
    modbusParams.S_total =  S_New.Feeder1_TOT;
	
	modbusParams.PF_Phase1 = PF_New.Feeder1_A;
	modbusParams.PF_Phase2 = PF_New.Feeder1_B;
	modbusParams.PF_Phase3 = PF_New.Feeder1_C;
    modbusParams.PF_total = PF_New.Feeder1_TOT;
	
    modbusParams.E_ACT_IMP_TOTAL = Energy_Total.Active.Feeder1_Import_TOT;
    modbusParams.E_ACT_EXP_TOTAL = Energy_Total.Active.Feeder1_Export_TOT;
    modbusParams.E_REAC_IMP_TOTAL = Energy_Total.Reactive.Feeder1_Import_TOT;
    modbusParams.E_REAC_EXP_TOTAL = Energy_Total.Reactive.Feeder1_Export_TOT;
	
	modbusParams.currentUnbFactor = currentUnbalanceFactor.feeder1;
	modbusParams.demand = demandParams.feeder1;
	
    modbusParams.currentAngle_CH1 = Current_Angle.ICH1;
    modbusParams.currentAngle_CH2 = Current_Angle.ICH2;
    modbusParams.currentAngle_CH3 = Current_Angle.ICH3;
	
    modbusParams.ICH_turnRatio_CH1 = turnRatio.ICH1;
    modbusParams.ICH_turnRatio_CH2 = turnRatio.ICH2;
    modbusParams.ICH_turnRatio_CH3 = turnRatio.ICH3;
	
    modbusParams.ICH_polarity_CH1  = polarity.ICH1;
    modbusParams.ICH_polarity_CH2  = polarity.ICH2;
    modbusParams.ICH_polarity_CH3  = polarity.ICH3;
  }

  if ( modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[3]
    || modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[4]
    || modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[5])
  {
    modbusParams.RMS_ICH1 = RMS_Value.ICH4;
	modbusParams.RMS_ICH1_FUND = spect_feeder2_a.foutMag[1];
    modbusParams.RMS_ICH1_3HF =  spect_feeder2_a.foutMag[3];
	  
    modbusParams.RMS_ICH2 = RMS_Value.ICH5;
	modbusParams.RMS_ICH2_FUND = spect_feeder2_b.foutMag[1];
    modbusParams.RMS_ICH2_3HF =  spect_feeder2_b.foutMag[3];
	  
    modbusParams.RMS_ICH3 = RMS_Value.ICH6;
	modbusParams.RMS_ICH3_FUND = spect_feeder2_c.foutMag[1];
    modbusParams.RMS_ICH3_3HF =  spect_feeder2_c.foutMag[3];
	  
	modbusParams.RMS_ICHN = RMS_Value.neutralCurrent_feeder2;
	
	modbusParams.P_Phase1 =  P.Feeder2_A;
	modbusParams.P_Phase2 =  P.Feeder2_B;
	modbusParams.P_Phase3 =  P.Feeder2_C;	 
    modbusParams.P_total =  P.Feeder2_TOT;
	  
	modbusParams.Q_Phase1 = Q_New.Feeder2_A;
	modbusParams.Q_Phase2 = Q_New.Feeder2_B;
	modbusParams.Q_Phase3 = Q_New.Feeder2_C;
    modbusParams.Q_total =  Q_New.Feeder2_TOT;
	
	modbusParams.S_Phase1 =  S_New.Feeder2_A;
	modbusParams.S_Phase2 =  S_New.Feeder2_B;
	modbusParams.S_Phase3 =  S_New.Feeder2_C;
    modbusParams.S_total =  S_New.Feeder2_TOT;
	
	modbusParams.PF_Phase1 = PF_New.Feeder2_A;
	modbusParams.PF_Phase2 = PF_New.Feeder2_B;
	modbusParams.PF_Phase3 = PF_New.Feeder2_C;
    modbusParams.PF_total = PF_New.Feeder2_TOT;
	
    modbusParams.E_ACT_IMP_TOTAL = Energy_Total.Active.Feeder2_Import_TOT;
    modbusParams.E_ACT_EXP_TOTAL = Energy_Total.Active.Feeder2_Export_TOT;
    modbusParams.E_REAC_IMP_TOTAL = Energy_Total.Reactive.Feeder2_Import_TOT;
    modbusParams.E_REAC_EXP_TOTAL = Energy_Total.Reactive.Feeder2_Export_TOT;
	
	modbusParams.currentUnbFactor = currentUnbalanceFactor.feeder2;
	modbusParams.demand = demandParams.feeder2;
	
    modbusParams.currentAngle_CH1 = Current_Angle.ICH4;
    modbusParams.currentAngle_CH2 = Current_Angle.ICH5;
    modbusParams.currentAngle_CH3 = Current_Angle.ICH6;
    modbusParams.ICH_turnRatio_CH1 = turnRatio.ICH4;
    modbusParams.ICH_turnRatio_CH2 = turnRatio.ICH5;
    modbusParams.ICH_turnRatio_CH3 = turnRatio.ICH6;
    modbusParams.ICH_polarity_CH1  = polarity.ICH4;
    modbusParams.ICH_polarity_CH2  = polarity.ICH5;
    modbusParams.ICH_polarity_CH3  = polarity.ICH6;
  }

  if ( modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[6]
    || modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[7]
    || modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[8])
  {
    modbusParams.RMS_ICH1 = RMS_Value.ICH7;
	modbusParams.RMS_ICH1_FUND = spect_feeder3_a.foutMag[1];
    modbusParams.RMS_ICH1_3HF =  spect_feeder3_a.foutMag[3];
	  
    modbusParams.RMS_ICH2 = RMS_Value.ICH8;
	modbusParams.RMS_ICH2_FUND = spect_feeder3_b.foutMag[1];
    modbusParams.RMS_ICH2_3HF =  spect_feeder3_b.foutMag[3];
	  
    modbusParams.RMS_ICH3 = RMS_Value.ICH9;
	modbusParams.RMS_ICH3_FUND = spect_feeder3_c.foutMag[1];
    modbusParams.RMS_ICH3_3HF =  spect_feeder3_c.foutMag[3];
	  
    modbusParams.RMS_ICHN = RMS_Value.neutralCurrent_feeder3;
	  
	modbusParams.P_Phase1 =  P.Feeder3_A;
	modbusParams.P_Phase2 =  P.Feeder3_B;
	modbusParams.P_Phase3 =  P.Feeder3_C;	
    modbusParams.P_total =  P.Feeder3_TOT;
	
	modbusParams.Q_Phase1 = Q_New.Feeder3_A;
	modbusParams.Q_Phase2 = Q_New.Feeder3_B;
	modbusParams.Q_Phase3 = Q_New.Feeder3_C;
    modbusParams.Q_total =  Q_New.Feeder3_TOT;
	
	modbusParams.S_Phase1 =  S_New.Feeder3_A;
	modbusParams.S_Phase2 =  S_New.Feeder3_B;
	modbusParams.S_Phase3 =  S_New.Feeder3_C;
    modbusParams.S_total =  S_New.Feeder3_TOT;
	
	modbusParams.PF_Phase1 = PF_New.Feeder3_A;
	modbusParams.PF_Phase2 = PF_New.Feeder3_B;
	modbusParams.PF_Phase3 = PF_New.Feeder3_C;
    modbusParams.PF_total = PF_New.Feeder3_TOT;
	
    modbusParams.E_ACT_IMP_TOTAL = Energy_Total.Active.Feeder3_Import_TOT;
    modbusParams.E_ACT_EXP_TOTAL = Energy_Total.Active.Feeder3_Export_TOT;
    modbusParams.E_REAC_IMP_TOTAL = Energy_Total.Reactive.Feeder3_Import_TOT;
    modbusParams.E_REAC_EXP_TOTAL = Energy_Total.Reactive.Feeder3_Export_TOT;
	
	modbusParams.currentUnbFactor = currentUnbalanceFactor.feeder3;
	modbusParams.demand = demandParams.feeder3;
	
    modbusParams.currentAngle_CH1 = Current_Angle.ICH7;
    modbusParams.currentAngle_CH2 = Current_Angle.ICH8;
    modbusParams.currentAngle_CH3 = Current_Angle.ICH9;
    modbusParams.ICH_turnRatio_CH1 = turnRatio.ICH7;
    modbusParams.ICH_turnRatio_CH2 = turnRatio.ICH8;
    modbusParams.ICH_turnRatio_CH3 = turnRatio.ICH9;
    modbusParams.ICH_polarity_CH1  = polarity.ICH7;
    modbusParams.ICH_polarity_CH2  = polarity.ICH8;
    modbusParams.ICH_polarity_CH3  = polarity.ICH9;
  }

  if ( modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[9]
    || modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[10]
    || modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[11])
  {
    modbusParams.RMS_ICH1 = RMS_Value.ICH10;
	modbusParams.RMS_ICH1_FUND = spect_feeder4_a.foutMag[1];
    modbusParams.RMS_ICH1_3HF =  spect_feeder4_a.foutMag[3];
	  
    modbusParams.RMS_ICH2 = RMS_Value.ICH11;
	modbusParams.RMS_ICH2_FUND = spect_feeder4_b.foutMag[1];
    modbusParams.RMS_ICH2_3HF =  spect_feeder4_b.foutMag[3];
	  
    modbusParams.RMS_ICH3 = RMS_Value.ICH12;
	modbusParams.RMS_ICH3_FUND = spect_feeder4_c.foutMag[1];
    modbusParams.RMS_ICH3_3HF =  spect_feeder4_c.foutMag[3];
	  
	modbusParams.RMS_ICHN = RMS_Value.neutralCurrent_feeder4;
	
	modbusParams.P_Phase1 =  P.Feeder4_A;
	modbusParams.P_Phase2 =  P.Feeder4_B;
	modbusParams.P_Phase3 =  P.Feeder4_C;	
    modbusParams.P_total =  P.Feeder4_TOT;
	 
	modbusParams.Q_Phase1 = Q_New.Feeder4_A;
	modbusParams.Q_Phase2 = Q_New.Feeder4_B;
	modbusParams.Q_Phase3 = Q_New.Feeder4_C;
    modbusParams.Q_total =  Q_New.Feeder4_TOT;
	
	modbusParams.S_Phase1 =  S_New.Feeder4_A;
	modbusParams.S_Phase2 =  S_New.Feeder4_B;
	modbusParams.S_Phase3 =  S_New.Feeder4_C;
    modbusParams.S_total =  S_New.Feeder4_TOT;
	
	modbusParams.PF_Phase1 = PF_New.Feeder4_A;
	modbusParams.PF_Phase2 = PF_New.Feeder4_B;
	modbusParams.PF_Phase3 = PF_New.Feeder4_C;
    modbusParams.PF_total = PF_New.Feeder4_TOT;
	
    modbusParams.E_ACT_IMP_TOTAL = Energy_Total.Active.Feeder4_Import_TOT;
    modbusParams.E_ACT_EXP_TOTAL = Energy_Total.Active.Feeder4_Export_TOT;
    modbusParams.E_REAC_IMP_TOTAL = Energy_Total.Reactive.Feeder4_Import_TOT;
    modbusParams.E_REAC_EXP_TOTAL = Energy_Total.Reactive.Feeder4_Export_TOT;
	
	modbusParams.currentUnbFactor = currentUnbalanceFactor.feeder4;
	modbusParams.demand = demandParams.feeder4;
	
    modbusParams.currentAngle_CH1 = Current_Angle.ICH10;
    modbusParams.currentAngle_CH2 = Current_Angle.ICH11;
    modbusParams.currentAngle_CH3 = Current_Angle.ICH12;
    modbusParams.ICH_turnRatio_CH1 = turnRatio.ICH10;
    modbusParams.ICH_turnRatio_CH2 = turnRatio.ICH11;
    modbusParams.ICH_turnRatio_CH3 = turnRatio.ICH12;
    modbusParams.ICH_polarity_CH1  = polarity.ICH10;
    modbusParams.ICH_polarity_CH2  = polarity.ICH11;
    modbusParams.ICH_polarity_CH3  = polarity.ICH12;
  }

  if ( modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[12]
    || modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[13]
    || modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[14])
  {
    modbusParams.RMS_ICH1 = RMS_Value.ICH13;
	modbusParams.RMS_ICH1_FUND = spect_feeder5_a.foutMag[1];
    modbusParams.RMS_ICH1_3HF =  spect_feeder5_a.foutMag[3];
	  
    modbusParams.RMS_ICH2 = RMS_Value.ICH14;
	modbusParams.RMS_ICH2_FUND = spect_feeder5_b.foutMag[1];
    modbusParams.RMS_ICH2_3HF =  spect_feeder5_b.foutMag[3];
	  
    modbusParams.RMS_ICH3 = RMS_Value.ICH15;
	modbusParams.RMS_ICH3_FUND = spect_feeder5_c.foutMag[1];
    modbusParams.RMS_ICH3_3HF =  spect_feeder5_c.foutMag[3];
	  
	modbusParams.RMS_ICHN = RMS_Value.neutralCurrent_feeder5;
	 
	modbusParams.P_Phase1 =  P.Feeder5_A;
	modbusParams.P_Phase2 =  P.Feeder5_B;
	modbusParams.P_Phase3 =  P.Feeder5_C;	
    modbusParams.P_total =  P.Feeder5_TOT;
	
	modbusParams.Q_Phase1 = Q_New.Feeder5_A;
	modbusParams.Q_Phase2 = Q_New.Feeder5_B;
	modbusParams.Q_Phase3 = Q_New.Feeder5_C;
    modbusParams.Q_total =  Q_New.Feeder5_TOT;
	
	modbusParams.S_Phase1 =  S_New.Feeder5_A;
	modbusParams.S_Phase2 =  S_New.Feeder5_B;
	modbusParams.S_Phase3 =  S_New.Feeder5_C;
    modbusParams.S_total =  S_New.Feeder5_TOT;
	
	modbusParams.PF_Phase1 = PF_New.Feeder5_A;
	modbusParams.PF_Phase2 = PF_New.Feeder5_B;
	modbusParams.PF_Phase3 = PF_New.Feeder5_C;
    modbusParams.PF_total = PF_New.Feeder5_TOT;
	
    modbusParams.E_ACT_IMP_TOTAL = Energy_Total.Active.Feeder5_Import_TOT;
    modbusParams.E_ACT_EXP_TOTAL = Energy_Total.Active.Feeder5_Export_TOT;
    modbusParams.E_REAC_IMP_TOTAL = Energy_Total.Reactive.Feeder5_Import_TOT;
    modbusParams.E_REAC_EXP_TOTAL = Energy_Total.Reactive.Feeder5_Export_TOT;
	
	modbusParams.currentUnbFactor = currentUnbalanceFactor.feeder5;
	modbusParams.demand = demandParams.feeder5;
	
    modbusParams.currentAngle_CH1 = Current_Angle.ICH13;
    modbusParams.currentAngle_CH2 = Current_Angle.ICH14;
    modbusParams.currentAngle_CH3 = Current_Angle.ICH15;
    modbusParams.ICH_turnRatio_CH1 = turnRatio.ICH13;
    modbusParams.ICH_turnRatio_CH2 = turnRatio.ICH14;
    modbusParams.ICH_turnRatio_CH3 = turnRatio.ICH15;
    modbusParams.ICH_polarity_CH1  = polarity.ICH13;
    modbusParams.ICH_polarity_CH2  = polarity.ICH14;
    modbusParams.ICH_polarity_CH3  = polarity.ICH15;
  }

  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[0])  modbusParams.RMS_ICH = RMS_Value.ICH1;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[1])  modbusParams.RMS_ICH = RMS_Value.ICH2;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[2])  modbusParams.RMS_ICH = RMS_Value.ICH3;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[3])  modbusParams.RMS_ICH = RMS_Value.ICH4;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[4])  modbusParams.RMS_ICH = RMS_Value.ICH5;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[5])  modbusParams.RMS_ICH = RMS_Value.ICH6;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[6])  modbusParams.RMS_ICH = RMS_Value.ICH7;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[7])  modbusParams.RMS_ICH = RMS_Value.ICH8;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[8])  modbusParams.RMS_ICH = RMS_Value.ICH9;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[9])  modbusParams.RMS_ICH = RMS_Value.ICH10;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[10]) modbusParams.RMS_ICH = RMS_Value.ICH11;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[11]) modbusParams.RMS_ICH = RMS_Value.ICH12;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[12]) modbusParams.RMS_ICH = RMS_Value.ICH13;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[13]) modbusParams.RMS_ICH = RMS_Value.ICH14;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[14]) modbusParams.RMS_ICH = RMS_Value.ICH15;

  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[0])  modbusParams.P = P.Feeder1_A;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[1])  modbusParams.P = P.Feeder1_B;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[2])  modbusParams.P = P.Feeder1_C;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[3])  modbusParams.P = P.Feeder2_A;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[4])  modbusParams.P = P.Feeder2_B;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[5])  modbusParams.P = P.Feeder2_C;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[6])  modbusParams.P = P.Feeder3_A;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[7])  modbusParams.P = P.Feeder3_B;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[8])  modbusParams.P = P.Feeder3_C;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[9])  modbusParams.P = P.Feeder4_A;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[10]) modbusParams.P = P.Feeder4_B;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[11]) modbusParams.P = P.Feeder4_C;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[12]) modbusParams.P = P.Feeder5_A;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[13]) modbusParams.P = P.Feeder5_B;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[14]) modbusParams.P = P.Feeder5_C;


  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[0])  modbusParams.Q = Q_New.Feeder1_A;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[1])  modbusParams.Q = Q_New.Feeder1_B;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[2])  modbusParams.Q = Q_New.Feeder1_C;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[3])  modbusParams.Q = Q_New.Feeder2_A;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[4])  modbusParams.Q = Q_New.Feeder2_B;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[5])  modbusParams.Q = Q_New.Feeder2_C;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[6])  modbusParams.Q = Q_New.Feeder3_A;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[7])  modbusParams.Q = Q_New.Feeder3_B;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[8])  modbusParams.Q = Q_New.Feeder3_C;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[9])  modbusParams.Q = Q_New.Feeder4_A;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[10]) modbusParams.Q = Q_New.Feeder4_B;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[11]) modbusParams.Q = Q_New.Feeder4_C;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[12]) modbusParams.Q = Q_New.Feeder5_A;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[13]) modbusParams.Q = Q_New.Feeder5_B;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[14]) modbusParams.Q = Q_New.Feeder5_C;

  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[0])  modbusParams.S = S_New.Feeder1_A;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[1])  modbusParams.S = S_New.Feeder1_B;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[2])  modbusParams.S = S_New.Feeder1_C;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[3])  modbusParams.S = S_New.Feeder2_A;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[4])  modbusParams.S = S_New.Feeder2_B;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[5])  modbusParams.S = S_New.Feeder2_C;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[6])  modbusParams.S = S_New.Feeder3_A;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[7])  modbusParams.S = S_New.Feeder3_B;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[8])  modbusParams.S = S_New.Feeder3_C;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[9])  modbusParams.S = S_New.Feeder4_A;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[10]) modbusParams.S = S_New.Feeder4_B;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[11]) modbusParams.S = S_New.Feeder4_C;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[12]) modbusParams.S = S_New.Feeder5_A;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[13]) modbusParams.S = S_New.Feeder5_B;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[14]) modbusParams.S = S_New.Feeder5_C;

  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[0])  modbusParams.PF = PF_New.Feeder1_A;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[1])  modbusParams.PF = PF_New.Feeder1_B;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[2])  modbusParams.PF = PF_New.Feeder1_C;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[3])  modbusParams.PF = PF_New.Feeder2_A;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[4])  modbusParams.PF = PF_New.Feeder2_B;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[5])  modbusParams.PF = PF_New.Feeder2_C;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[6])  modbusParams.PF = PF_New.Feeder3_A;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[7])  modbusParams.PF = PF_New.Feeder3_B;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[8])  modbusParams.PF = PF_New.Feeder3_C;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[9])  modbusParams.PF = PF_New.Feeder4_A;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[10]) modbusParams.PF = PF_New.Feeder4_B;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[11]) modbusParams.PF = PF_New.Feeder4_C;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[12]) modbusParams.PF = PF_New.Feeder5_A;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[13]) modbusParams.PF = PF_New.Feeder5_B;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[14]) modbusParams.PF = PF_New.Feeder5_C;

  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[0])  modbusParams.E_ACT_IMP = Energy_Total.Active.Feeder1_A_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[1])  modbusParams.E_ACT_IMP = Energy_Total.Active.Feeder1_B_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[2])  modbusParams.E_ACT_IMP = Energy_Total.Active.Feeder1_C_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[3])  modbusParams.E_ACT_IMP = Energy_Total.Active.Feeder2_A_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[4])  modbusParams.E_ACT_IMP = Energy_Total.Active.Feeder2_B_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[5])  modbusParams.E_ACT_IMP = Energy_Total.Active.Feeder2_C_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[6])  modbusParams.E_ACT_IMP = Energy_Total.Active.Feeder3_A_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[7])  modbusParams.E_ACT_IMP = Energy_Total.Active.Feeder3_B_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[8])  modbusParams.E_ACT_IMP = Energy_Total.Active.Feeder3_C_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[9])  modbusParams.E_ACT_IMP = Energy_Total.Active.Feeder4_A_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[10]) modbusParams.E_ACT_IMP = Energy_Total.Active.Feeder4_B_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[11]) modbusParams.E_ACT_IMP = Energy_Total.Active.Feeder4_C_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[12]) modbusParams.E_ACT_IMP = Energy_Total.Active.Feeder5_A_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[13]) modbusParams.E_ACT_IMP = Energy_Total.Active.Feeder5_B_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[14]) modbusParams.E_ACT_IMP = Energy_Total.Active.Feeder5_C_Import;

  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[0])  modbusParams.E_ACT_EXP = Energy_Total.Active.Feeder1_A_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[1])  modbusParams.E_ACT_EXP = Energy_Total.Active.Feeder1_B_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[2])  modbusParams.E_ACT_EXP = Energy_Total.Active.Feeder1_C_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[3])  modbusParams.E_ACT_EXP = Energy_Total.Active.Feeder2_A_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[4])  modbusParams.E_ACT_EXP = Energy_Total.Active.Feeder2_B_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[5])  modbusParams.E_ACT_EXP = Energy_Total.Active.Feeder2_C_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[6])  modbusParams.E_ACT_EXP = Energy_Total.Active.Feeder3_A_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[7])  modbusParams.E_ACT_EXP = Energy_Total.Active.Feeder3_B_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[8])  modbusParams.E_ACT_EXP = Energy_Total.Active.Feeder3_C_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[9])  modbusParams.E_ACT_EXP = Energy_Total.Active.Feeder4_A_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[10]) modbusParams.E_ACT_EXP = Energy_Total.Active.Feeder4_B_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[11]) modbusParams.E_ACT_EXP = Energy_Total.Active.Feeder4_C_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[12]) modbusParams.E_ACT_EXP = Energy_Total.Active.Feeder5_A_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[13]) modbusParams.E_ACT_EXP = Energy_Total.Active.Feeder5_B_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[14]) modbusParams.E_ACT_EXP = Energy_Total.Active.Feeder5_C_Export;

  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[0])  modbusParams.E_REAC_IMP = Energy_Total.Reactive.Feeder1_A_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[1])  modbusParams.E_REAC_IMP = Energy_Total.Reactive.Feeder1_B_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[2])  modbusParams.E_REAC_IMP = Energy_Total.Reactive.Feeder1_C_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[3])  modbusParams.E_REAC_IMP = Energy_Total.Reactive.Feeder2_A_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[4])  modbusParams.E_REAC_IMP = Energy_Total.Reactive.Feeder2_B_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[5])  modbusParams.E_REAC_IMP = Energy_Total.Reactive.Feeder2_C_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[6])  modbusParams.E_REAC_IMP = Energy_Total.Reactive.Feeder3_A_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[7])  modbusParams.E_REAC_IMP = Energy_Total.Reactive.Feeder3_B_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[8])  modbusParams.E_REAC_IMP = Energy_Total.Reactive.Feeder3_C_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[9])  modbusParams.E_REAC_IMP = Energy_Total.Reactive.Feeder4_A_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[10]) modbusParams.E_REAC_IMP = Energy_Total.Reactive.Feeder4_B_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[11]) modbusParams.E_REAC_IMP = Energy_Total.Reactive.Feeder4_C_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[12]) modbusParams.E_REAC_IMP = Energy_Total.Reactive.Feeder5_A_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[13]) modbusParams.E_REAC_IMP = Energy_Total.Reactive.Feeder5_B_Import;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[14]) modbusParams.E_REAC_IMP = Energy_Total.Reactive.Feeder5_C_Import;

  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[0])  modbusParams.E_REAC_EXP = Energy_Total.Reactive.Feeder1_A_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[1])  modbusParams.E_REAC_EXP = Energy_Total.Reactive.Feeder1_B_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[2])  modbusParams.E_REAC_EXP = Energy_Total.Reactive.Feeder1_C_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[3])  modbusParams.E_REAC_EXP = Energy_Total.Reactive.Feeder2_A_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[4])  modbusParams.E_REAC_EXP = Energy_Total.Reactive.Feeder2_B_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[5])  modbusParams.E_REAC_EXP = Energy_Total.Reactive.Feeder2_C_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[6])  modbusParams.E_REAC_EXP = Energy_Total.Reactive.Feeder3_A_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[7])  modbusParams.E_REAC_EXP = Energy_Total.Reactive.Feeder3_B_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[8])  modbusParams.E_REAC_EXP = Energy_Total.Reactive.Feeder3_C_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[9])  modbusParams.E_REAC_EXP = Energy_Total.Reactive.Feeder4_A_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[10]) modbusParams.E_REAC_EXP = Energy_Total.Reactive.Feeder4_B_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[11]) modbusParams.E_REAC_EXP = Energy_Total.Reactive.Feeder4_C_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[12]) modbusParams.E_REAC_EXP = Energy_Total.Reactive.Feeder5_A_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[13]) modbusParams.E_REAC_EXP = Energy_Total.Reactive.Feeder5_B_Export;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[14]) modbusParams.E_REAC_EXP = Energy_Total.Reactive.Feeder5_C_Export;

  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[0])  modbusParams.ICH_turnRatio = turnRatio.ICH1;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[1])  modbusParams.ICH_turnRatio = turnRatio.ICH2;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[2])  modbusParams.ICH_turnRatio = turnRatio.ICH3;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[3])  modbusParams.ICH_turnRatio = turnRatio.ICH4;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[4])  modbusParams.ICH_turnRatio = turnRatio.ICH5;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[5])  modbusParams.ICH_turnRatio = turnRatio.ICH6;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[6])  modbusParams.ICH_turnRatio = turnRatio.ICH7;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[7])  modbusParams.ICH_turnRatio = turnRatio.ICH8;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[8])  modbusParams.ICH_turnRatio = turnRatio.ICH9;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[9])  modbusParams.ICH_turnRatio = turnRatio.ICH10;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[10]) modbusParams.ICH_turnRatio = turnRatio.ICH11;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[11]) modbusParams.ICH_turnRatio = turnRatio.ICH12;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[12]) modbusParams.ICH_turnRatio = turnRatio.ICH13;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[13]) modbusParams.ICH_turnRatio = turnRatio.ICH14;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[14]) modbusParams.ICH_turnRatio = turnRatio.ICH15;

  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[0])  modbusParams.ICH_polarity = polarity.ICH1;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[1])  modbusParams.ICH_polarity = polarity.ICH2;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[2])  modbusParams.ICH_polarity = polarity.ICH3;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[3])  modbusParams.ICH_polarity = polarity.ICH4;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[4])  modbusParams.ICH_polarity = polarity.ICH5;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[5])  modbusParams.ICH_polarity = polarity.ICH6;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[6])  modbusParams.ICH_polarity = polarity.ICH7;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[7])  modbusParams.ICH_polarity = polarity.ICH8;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[8])  modbusParams.ICH_polarity = polarity.ICH9;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[9])  modbusParams.ICH_polarity = polarity.ICH10;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[10]) modbusParams.ICH_polarity = polarity.ICH11;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[11]) modbusParams.ICH_polarity = polarity.ICH12;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[12]) modbusParams.ICH_polarity = polarity.ICH13;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[13]) modbusParams.ICH_polarity = polarity.ICH14;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[14]) modbusParams.ICH_polarity = polarity.ICH15;

  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[0])  modbusParams.currentAngle = Current_Angle.ICH1;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[1])  modbusParams.currentAngle = Current_Angle.ICH2;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[2])  modbusParams.currentAngle = Current_Angle.ICH3;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[3])  modbusParams.currentAngle = Current_Angle.ICH4;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[4])  modbusParams.currentAngle = Current_Angle.ICH5;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[5])  modbusParams.currentAngle = Current_Angle.ICH6;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[6])  modbusParams.currentAngle = Current_Angle.ICH7;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[7])  modbusParams.currentAngle = Current_Angle.ICH8;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[8])  modbusParams.currentAngle = Current_Angle.ICH9;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[9])  modbusParams.currentAngle = Current_Angle.ICH10;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[10]) modbusParams.currentAngle = Current_Angle.ICH11;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[11]) modbusParams.currentAngle = Current_Angle.ICH12;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[12]) modbusParams.currentAngle = Current_Angle.ICH13;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[13]) modbusParams.currentAngle = Current_Angle.ICH14;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[14]) modbusParams.currentAngle = Current_Angle.ICH15;

  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[0])  modbusParams.channelRef = channelReference.CH1;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[1])  modbusParams.channelRef = channelReference.CH2;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[2])  modbusParams.channelRef = channelReference.CH3;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[3])  modbusParams.channelRef = channelReference.CH4;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[4])  modbusParams.channelRef = channelReference.CH5;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[5])  modbusParams.channelRef = channelReference.CH6;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[6])  modbusParams.channelRef = channelReference.CH7;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[7])  modbusParams.channelRef = channelReference.CH8;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[8])  modbusParams.channelRef = channelReference.CH9;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[9])  modbusParams.channelRef = channelReference.CH10;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[10]) modbusParams.channelRef = channelReference.CH11;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[11]) modbusParams.channelRef = channelReference.CH12;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[12]) modbusParams.channelRef = channelReference.CH13;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[13]) modbusParams.channelRef = channelReference.CH14;
  if (modbusParams.selectedSlaveID == modbusParams.deviceSlaveID[14]) modbusParams.channelRef = channelReference.CH15;
}

void rtu_Feeder1DataPrep(void)
{
  rtu_genericDataPrep();

  if (modbusParams.regAdress == READ_VAN)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(RMS_Value.VCH1 * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(RMS_Value.VCH1 * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(RMS_Value.VCH1 * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(RMS_Value.VCH1 * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

	if (modbusParams.regAdress == READ_VBN)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(RMS_Value.VCH2 * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(RMS_Value.VCH2 * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(RMS_Value.VCH2 * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(RMS_Value.VCH2 * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

	if (modbusParams.regAdress == READ_VCN)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(RMS_Value.VCH3 * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(RMS_Value.VCH3 * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(RMS_Value.VCH3 * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(RMS_Value.VCH3 * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

	if (modbusParams.regAdress == READ_VAB)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(RMS_Value.VCH12 * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(RMS_Value.VCH12 * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(RMS_Value.VCH12 * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(RMS_Value.VCH12 * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

	if (modbusParams.regAdress == READ_VBC)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(RMS_Value.VCH23 * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(RMS_Value.VCH23 * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(RMS_Value.VCH23 * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(RMS_Value.VCH23 * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

	if (modbusParams.regAdress == READ_VCA)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(RMS_Value.VCH31 * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(RMS_Value.VCH31 * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(RMS_Value.VCH31 * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(RMS_Value.VCH31 * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

	if (modbusParams.regAdress == READ_ICHN)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.RMS_ICH * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.RMS_ICH * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.RMS_ICH * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.RMS_ICH * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

	if (modbusParams.regAdress == READ_P_FEEDER)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.P)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.P)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.P)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.P));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

	if (modbusParams.regAdress == READ_Q_FEEDER)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.Q)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.Q)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.Q)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.Q));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

	if (modbusParams.regAdress == READ_S_FEEDER)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.S)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.S)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.S)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.S));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

	if (modbusParams.regAdress == READ_PF_FEEDER)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.PF * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.PF * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.PF * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.PF * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

	if (modbusParams.regAdress == READ_E_FEEDER_ACT_IMP)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.E_ACT_IMP)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.E_ACT_IMP)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.E_ACT_IMP)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.E_ACT_IMP));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

	if (modbusParams.regAdress == READ_E_FEEDER_ACT_EXP)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.E_ACT_EXP)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.E_ACT_EXP)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.E_ACT_EXP)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.E_ACT_EXP));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

	if (modbusParams.regAdress == READ_E_FEEDER_REACT_IMP)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.E_REAC_IMP)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.E_REAC_IMP)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.E_REAC_IMP)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.E_REAC_IMP));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

	if (modbusParams.regAdress == READ_E_FEEDER_REACT_EXP)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.E_REAC_EXP)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.E_REAC_EXP)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.E_REAC_EXP)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.E_REAC_EXP));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_FEEDER_SLAVE_ADRESS)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.selectedSlaveID)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.selectedSlaveID)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.selectedSlaveID)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.selectedSlaveID));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_VOLTAGE_SCALING_VAN)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(turnRatio.VCH1)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(turnRatio.VCH1)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(turnRatio.VCH1)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(turnRatio.VCH1));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_VOLTAGE_SCALING_VBN)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(turnRatio.VCH2)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(turnRatio.VCH2)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(turnRatio.VCH2)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(turnRatio.VCH2));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_VOLTAGE_SCALING_VCN)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(turnRatio.VCH3)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(turnRatio.VCH3)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(turnRatio.VCH3)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(turnRatio.VCH3));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_CURRENT_SCALING_ICHN)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.ICH_turnRatio)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.ICH_turnRatio)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.ICH_turnRatio)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.ICH_turnRatio));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_CURRENT_POLARITY_ICHN)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.ICH_polarity)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.ICH_polarity)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.ICH_polarity)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.ICH_polarity));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_VOLTAGE_ANGLE_VCH_AN)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(Voltage_Angle.VCH1)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(Voltage_Angle.VCH1)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(Voltage_Angle.VCH1)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(Voltage_Angle.VCH1));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_VOLTAGE_ANGLE_VCH_BN)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(Voltage_Angle.VCH2)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(Voltage_Angle.VCH2)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(Voltage_Angle.VCH2)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(Voltage_Angle.VCH2));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_VOLTAGE_ANGLE_VCH_CN)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(Voltage_Angle.VCH3)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(Voltage_Angle.VCH3)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(Voltage_Angle.VCH3)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(Voltage_Angle.VCH3));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_CURRENT_ANGLE_ICHN)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.currentAngle)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.currentAngle)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.currentAngle)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.currentAngle));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_CHANNEL_REFERENCE)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.channelRef)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.channelRef)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.channelRef)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.channelRef));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  /**************************************** Three Phase Map ***********************************************/

  if (modbusParams.regAdress == READ_VAN_THREE_PHASE)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(RMS_Value.VCH1 * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(RMS_Value.VCH1 * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(RMS_Value.VCH1 * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(RMS_Value.VCH1 * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_VBN_THREE_PHASE)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(RMS_Value.VCH2 * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(RMS_Value.VCH2 * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(RMS_Value.VCH2 * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(RMS_Value.VCH2 * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_VCN_THREE_PHASE)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(RMS_Value.VCH3 * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(RMS_Value.VCH3 * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(RMS_Value.VCH3 * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(RMS_Value.VCH3 * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_VAB_THREE_PHASE)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(RMS_Value.VCH12 * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(RMS_Value.VCH12 * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(RMS_Value.VCH12 * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(RMS_Value.VCH12 * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_VBC_THREE_PHASE)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(RMS_Value.VCH23 * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(RMS_Value.VCH23 * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(RMS_Value.VCH23 * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(RMS_Value.VCH23 * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_VCA_THREE_PHASE)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(RMS_Value.VCH31 * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(RMS_Value.VCH31 * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(RMS_Value.VCH31 * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(RMS_Value.VCH31 * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_ICH1_THREE_PHASE)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.RMS_ICH1 * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.RMS_ICH1 * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.RMS_ICH1 * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.RMS_ICH1 * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }
  
  if (modbusParams.regAdress == READ_ICH1_FUND_THREE_PHASE)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.RMS_ICH1_FUND * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.RMS_ICH1_FUND * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.RMS_ICH1_FUND * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.RMS_ICH1_FUND * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }
  
  if (modbusParams.regAdress == READ_ICH1_3HF_THREE_PHASE)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.RMS_ICH1_3HF * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.RMS_ICH1_3HF * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.RMS_ICH1_3HF * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.RMS_ICH1_3HF * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_ICH2_THREE_PHASE)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.RMS_ICH2 * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.RMS_ICH2 * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.RMS_ICH2 * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.RMS_ICH2 * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }
  
  if (modbusParams.regAdress == READ_ICH2_FUND_THREE_PHASE)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.RMS_ICH2_FUND * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.RMS_ICH2_FUND * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.RMS_ICH2_FUND * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.RMS_ICH2_FUND * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }
  
  if (modbusParams.regAdress == READ_ICH2_3HF_THREE_PHASE)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.RMS_ICH2_3HF * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.RMS_ICH2_3HF * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.RMS_ICH2_3HF * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.RMS_ICH2_3HF * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_ICH3_THREE_PHASE)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.RMS_ICH3 * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.RMS_ICH3 * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.RMS_ICH3 * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.RMS_ICH3 * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }
  
  if (modbusParams.regAdress == READ_ICH3_FUND_THREE_PHASE)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.RMS_ICH3_FUND * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.RMS_ICH3_FUND * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.RMS_ICH3_FUND * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.RMS_ICH3_FUND * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }
  
  if (modbusParams.regAdress == READ_ICH3_3HF_THREE_PHASE)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.RMS_ICH3_3HF * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.RMS_ICH3_3HF * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.RMS_ICH3_3HF * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.RMS_ICH3_3HF * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }
  
  if (modbusParams.regAdress == READ_ICHN_THREE_PHASE)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.RMS_ICHN * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.RMS_ICHN * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.RMS_ICHN * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.RMS_ICHN * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_P_FEEDER_THREE_PHASE1)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.P_Phase1)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.P_Phase1)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.P_Phase1)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.P_Phase1));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }
  
  if (modbusParams.regAdress == READ_P_FEEDER_THREE_PHASE2)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.P_Phase2)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.P_Phase2)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.P_Phase2)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.P_Phase2));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }
  
  if (modbusParams.regAdress == READ_P_FEEDER_THREE_PHASE3)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.P_Phase3)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.P_Phase3)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.P_Phase3)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.P_Phase3));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }
  
  if (modbusParams.regAdress == READ_P_FEEDER_THREE_PHASE)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.P_total)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.P_total)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.P_total)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.P_total));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_Q_FEEDER_THREE_PHASE1)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.Q_Phase1)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.Q_Phase1)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.Q_Phase1)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.Q_Phase1));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }
  
  if (modbusParams.regAdress == READ_Q_FEEDER_THREE_PHASE2)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.Q_Phase2)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.Q_Phase2)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.Q_Phase2)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.Q_Phase2));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }
  
  if (modbusParams.regAdress == READ_Q_FEEDER_THREE_PHASE3)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.Q_Phase3)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.Q_Phase3)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.Q_Phase3)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.Q_Phase3));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }
  
  if (modbusParams.regAdress == READ_Q_FEEDER_THREE_PHASE)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.Q_total)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.Q_total)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.Q_total)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.Q_total));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

	if (modbusParams.regAdress == READ_S_FEEDER_THREE_PHASE)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.S_total)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.S_total)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.S_total)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.S_total));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_PF_FEEDER_THREE_PHASE)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.PF_total * 100)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.PF_total * 100)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.PF_total * 100)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.PF_total * 100));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

	if (modbusParams.regAdress == READ_E_FEEDER_ACT_IMP_THREE_PHASE)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.E_ACT_IMP_TOTAL)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.E_ACT_IMP_TOTAL)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.E_ACT_IMP_TOTAL)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.E_ACT_IMP_TOTAL));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

	if (modbusParams.regAdress == READ_E_FEEDER_ACT_EXP_THREE_PHASE)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.E_ACT_EXP_TOTAL)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.E_ACT_EXP_TOTAL)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.E_ACT_EXP_TOTAL)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.E_ACT_EXP_TOTAL));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

	if (modbusParams.regAdress == READ_E_FEEDER_REACT_IMP_THREE_PHASE)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.E_REAC_IMP_TOTAL)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.E_REAC_IMP_TOTAL)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.E_REAC_IMP_TOTAL)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.E_REAC_IMP_TOTAL));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

	if (modbusParams.regAdress == READ_E_FEEDER_REACT_EXP_THREE_PHASE)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.E_REAC_EXP_TOTAL)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.E_REAC_EXP_TOTAL)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.E_REAC_EXP_TOTAL)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.E_REAC_EXP_TOTAL));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }
  
  if (modbusParams.regAdress == READ_CURRENT_UNB_FACTOR)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.currentUnbFactor)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.currentUnbFactor)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.currentUnbFactor)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.currentUnbFactor));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }
  
  if (modbusParams.regAdress == READ_FEEDER_DEMAND)
  {
	  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.demand)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.demand)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.demand)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.demand));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_FEEDER_SLAVE_ADRESS_THREE_PHASE)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.selectedSlaveID)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.selectedSlaveID)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.selectedSlaveID)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.selectedSlaveID));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_VOLTAGE_SCALING_VAN_THREE_PHASE)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(turnRatio.VCH1)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(turnRatio.VCH1)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(turnRatio.VCH1)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(turnRatio.VCH1));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_VOLTAGE_SCALING_VBN_THREE_PHASE)
  {
		  modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(turnRatio.VCH2)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(turnRatio.VCH2)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(turnRatio.VCH2)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(turnRatio.VCH2));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_VOLTAGE_SCALING_VCN_THREE_PHASE)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(turnRatio.VCH3)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(turnRatio.VCH3)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(turnRatio.VCH3)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(turnRatio.VCH3));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_CURRENT_SCALING_ICH1_THREE_PHASE)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.ICH_turnRatio_CH1)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.ICH_turnRatio_CH1)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.ICH_turnRatio_CH1)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.ICH_turnRatio_CH1));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_CURRENT_SCALING_ICH2_THREE_PHASE)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.ICH_turnRatio_CH2)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.ICH_turnRatio_CH2)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.ICH_turnRatio_CH2)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.ICH_turnRatio_CH2));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_CURRENT_SCALING_ICH3_THREE_PHASE)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(modbusParams.ICH_turnRatio_CH3)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(modbusParams.ICH_turnRatio_CH3)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(modbusParams.ICH_turnRatio_CH3)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(modbusParams.ICH_turnRatio_CH3));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_CURRENT_POLARITY_ICH1_THREE_PHASE)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.ICH_polarity_CH1)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.ICH_polarity_CH1)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.ICH_polarity_CH1)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.ICH_polarity_CH1));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_CURRENT_POLARITY_ICH2_THREE_PHASE)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.ICH_polarity_CH2)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.ICH_polarity_CH2)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.ICH_polarity_CH2)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.ICH_polarity_CH2));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_CURRENT_POLARITY_ICH3_THREE_PHASE)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.ICH_polarity_CH3)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.ICH_polarity_CH3)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.ICH_polarity_CH3)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.ICH_polarity_CH3));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_VOLTAGE_ANGLE_VCH_AN_THREE_PHASE)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(Voltage_Angle.VCH1)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(Voltage_Angle.VCH1)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(Voltage_Angle.VCH1)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(Voltage_Angle.VCH1));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_VOLTAGE_ANGLE_VCH_BN_THREE_PHASE)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(Voltage_Angle.VCH2)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(Voltage_Angle.VCH2)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(Voltage_Angle.VCH2)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(Voltage_Angle.VCH2));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_VOLTAGE_ANGLE_VCH_CN_THREE_PHASE)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (uint32_t)(Voltage_Angle.VCH3)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (uint32_t)(Voltage_Angle.VCH3)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (uint32_t)(Voltage_Angle.VCH3)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (uint32_t)(Voltage_Angle.VCH3));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_CURRENT_ANGLE_ICH1_THREE_PHASE)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.currentAngle_CH1)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.currentAngle_CH1)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.currentAngle_CH1)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.currentAngle_CH1));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_CURRENT_ANGLE_ICH2_THREE_PHASE)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.currentAngle_CH2)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.currentAngle_CH2)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.currentAngle_CH2)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.currentAngle_CH2));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  if (modbusParams.regAdress == READ_CURRENT_ANGLE_ICH3_THREE_PHASE)
  {
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.currentAngle_CH3)) >> 24;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.currentAngle_CH3)) >> 16;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.currentAngle_CH3)) >> 8;
      modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.currentAngle_CH3));
      modbusParams.regAdress += 2;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
  }

  rtu_transmitData_readHoldingRegister();

}

void rtu_Feeder1DataPrep_writeMultipleRegisters(void)
{

    if (modbusParams.regAdress == CHANGE_SLAVEID_FEEDER1)
    {
      modbusParams.deviceSlaveID[0] = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      modbusParams.deviceSlaveID[0] |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_SLAVEID_FEEDER2)
    {
      modbusParams.deviceSlaveID[1] = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      modbusParams.deviceSlaveID[1] |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_SLAVEID_FEEDER3)
    {
      modbusParams.deviceSlaveID[2] = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      modbusParams.deviceSlaveID[2] |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_SLAVEID_FEEDER4)
    {
      modbusParams.deviceSlaveID[3] = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      modbusParams.deviceSlaveID[3] |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_SLAVEID_FEEDER5)
    {
      modbusParams.deviceSlaveID[4] = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      modbusParams.deviceSlaveID[4] |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_SLAVEID_FEEDER6)
    {
      modbusParams.deviceSlaveID[5] = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      modbusParams.deviceSlaveID[5] |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_SLAVEID_FEEDER7)
    {
      modbusParams.deviceSlaveID[6] = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      modbusParams.deviceSlaveID[6] |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_SLAVEID_FEEDER8)
    {
      modbusParams.deviceSlaveID[7] = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      modbusParams.deviceSlaveID[7] |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_SLAVEID_FEEDER9)
    {
      modbusParams.deviceSlaveID[8] = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      modbusParams.deviceSlaveID[8] |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_SLAVEID_FEEDER10)
    {
      modbusParams.deviceSlaveID[9] = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      modbusParams.deviceSlaveID[9] |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_SLAVEID_FEEDER11)
    {
      modbusParams.deviceSlaveID[10] = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      modbusParams.deviceSlaveID[10] |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_SLAVEID_FEEDER12)
    {
      modbusParams.deviceSlaveID[11] = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      modbusParams.deviceSlaveID[11] |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_SLAVEID_FEEDER13)
    {
      modbusParams.deviceSlaveID[12] = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      modbusParams.deviceSlaveID[12] |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_SLAVEID_FEEDER14)
    {
      modbusParams.deviceSlaveID[13] = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      modbusParams.deviceSlaveID[13] |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_SLAVEID_FEEDER15)
    {
      modbusParams.deviceSlaveID[14] = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      modbusParams.deviceSlaveID[14] |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_DEVICE_BAUDRATE)
    {
      deviceParams.baudRate = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      deviceParams.baudRate |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_VOLTAGE_SCALING_VCH1)
    {
      turnRatio.VCH1 = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      turnRatio.VCH1 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_VOLTAGE_SCALING_VCH2)
    {
      turnRatio.VCH2 = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      turnRatio.VCH2 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_VOLTAGE_SCALING_VCH3)
    {
      turnRatio.VCH3 = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      turnRatio.VCH3 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_SCALING_ICH1)
    {
      turnRatio.ICH1 = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      turnRatio.ICH1 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_SCALING_ICH2)
    {
      turnRatio.ICH2 = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      turnRatio.ICH2 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_SCALING_ICH3)
    {
      turnRatio.ICH3 = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      turnRatio.ICH3 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_SCALING_ICH4)
    {
      turnRatio.ICH4 = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      turnRatio.ICH4 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_SCALING_ICH5)
    {
      turnRatio.ICH5 = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      turnRatio.ICH5 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_SCALING_ICH6)
    {
      turnRatio.ICH6 = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      turnRatio.ICH6 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_SCALING_ICH7)
    {
      turnRatio.ICH7 = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      turnRatio.ICH7 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_SCALING_ICH8)
    {
      turnRatio.ICH8 = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      turnRatio.ICH8 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_SCALING_ICH9)
    {
      turnRatio.ICH9 = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      turnRatio.ICH9 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_SCALING_ICH10)
    {
      turnRatio.ICH10 = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      turnRatio.ICH10 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_SCALING_ICH11)
    {
      turnRatio.ICH11 = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      turnRatio.ICH11 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_SCALING_ICH12)
    {
      turnRatio.ICH12 = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      turnRatio.ICH12 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_SCALING_ICH13)
    {
      turnRatio.ICH13 = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      turnRatio.ICH13 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_SCALING_ICH14)
    {
      turnRatio.ICH14 = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      turnRatio.ICH14 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_SCALING_ICH15)
    {
      turnRatio.ICH15 = (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      turnRatio.ICH15 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_POLARITY_ICH1)
    {
      polarity.ICH1 = (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      polarity.ICH1 |= (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_POLARITY_ICH2)
    {
      polarity.ICH2 = (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      polarity.ICH2 |= (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_POLARITY_ICH3)
    {
      polarity.ICH3 = (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      polarity.ICH3 |= (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_POLARITY_ICH4)
    {
      polarity.ICH4 = (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      polarity.ICH4 |= (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_POLARITY_ICH5)
    {
      polarity.ICH5 = (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      polarity.ICH5 |= (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_POLARITY_ICH6)
    {
      polarity.ICH6 = (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      polarity.ICH6 |= (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_POLARITY_ICH7)
    {
      polarity.ICH7 = (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      polarity.ICH7 |= (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_POLARITY_ICH8)
    {
      polarity.ICH8 = (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      polarity.ICH8 |= (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_POLARITY_ICH9)
    {
      polarity.ICH9 = (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      polarity.ICH9 |= (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_POLARITY_ICH10)
    {
      polarity.ICH10 = (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      polarity.ICH10 |= (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_POLARITY_ICH11)
    {
      polarity.ICH11 = (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      polarity.ICH11 |= (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_POLARITY_ICH12)
    {
      polarity.ICH12 = (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      polarity.ICH12 |= (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_POLARITY_ICH13)
    {
      polarity.ICH13 = (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      polarity.ICH13 |= (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_POLARITY_ICH14)
    {
      polarity.ICH14 = (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      polarity.ICH14 |= (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_CURRENT_POLARITY_ICH15)
    {
      polarity.ICH15 = (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      polarity.ICH15 |= (int16_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_VOLTAGE_REFERENCE_CH1)
    {
      channelReference.CH1 =  (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      channelReference.CH1 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_VOLTAGE_REFERENCE_CH2)
    {
      channelReference.CH2 =  (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      channelReference.CH2 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_VOLTAGE_REFERENCE_CH3)
    {
      channelReference.CH3 =  (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      channelReference.CH3 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_VOLTAGE_REFERENCE_CH4)
    {
      channelReference.CH4 =  (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      channelReference.CH4 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_VOLTAGE_REFERENCE_CH5)
    {
      channelReference.CH5 =  (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      channelReference.CH5 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_VOLTAGE_REFERENCE_CH6)
    {
      channelReference.CH6 =  (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      channelReference.CH6 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_VOLTAGE_REFERENCE_CH7)
    {
      channelReference.CH7 =  (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      channelReference.CH7 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_VOLTAGE_REFERENCE_CH8)
    {
      channelReference.CH8 =  (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      channelReference.CH8 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_VOLTAGE_REFERENCE_CH9)
    {
      channelReference.CH9 =  (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      channelReference.CH9 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_VOLTAGE_REFERENCE_CH10)
    {
      channelReference.CH10 =  (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      channelReference.CH10 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_VOLTAGE_REFERENCE_CH11)
    {
      channelReference.CH11 =  (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      channelReference.CH11 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_VOLTAGE_REFERENCE_CH12)
    {
      channelReference.CH12 =  (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      channelReference.CH12 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_VOLTAGE_REFERENCE_CH13)
    {
      channelReference.CH13 =  (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      channelReference.CH13 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_VOLTAGE_REFERENCE_CH14)
    {
      channelReference.CH14 =  (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      channelReference.CH14 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

    if (modbusParams.regAdress == CHANGE_VOLTAGE_REFERENCE_CH15)
    {
      channelReference.CH15 =  (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]) << 8;
      channelReference.CH15 |= (uint32_t)(modbusParams.modbusRxBuffer[modbusParams.rxIndex++]);
      modbusParams.regAdress += 1;
      if (modbusParams.regAdress == modbusParams.endingAdress) modbusParams.regAdress = 0;
    }

}

void rtu_Feeder1DataPrep_singleWriteRegisters(void)
{
    if (modbusParams.regAdress == WRITE_FLASH_SAVE_ALL)
    {
      deviceParams.saveEnergyRegisters = (uint32_t)(modbusParams.modbusRxBuffer[4]) << 8;
      deviceParams.saveEnergyRegisters |= (uint32_t)(modbusParams.modbusRxBuffer[5]);
    }

    if (modbusParams.regAdress == WRITE_DEVICE_SOFTWARE_RESET)
    {
      deviceParams.softwareReset = (uint32_t)(modbusParams.modbusRxBuffer[4]) << 8;
      deviceParams.softwareReset |= (uint32_t)(modbusParams.modbusRxBuffer[5]);
    }
	
	if (modbusParams.regAdress == USB_BOOT_MODE_ENABLE)
    {
      bootParams.bootModeTrigger= (uint32_t)(modbusParams.modbusRxBuffer[4]) << 8;
      bootParams.bootModeTrigger |= (uint32_t)(modbusParams.modbusRxBuffer[5]);
    }
}

void rtu_prepareUserInterfaceData(void)
{
    uint32_t index = 0;

    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.VCH1  * 100;
    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.VCH2  * 100;
    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.VCH3  * 100;
    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.VCH12 * 100;
    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.VCH23 * 100;
    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.VCH31 * 100;

    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.ICH1  * 100;
    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.ICH2  * 100;
    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.ICH3  * 100;
    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.ICH4  * 100;
    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.ICH5  * 100;
    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.ICH6  * 100;
    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.ICH7  * 100;
    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.ICH8  * 100;
    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.ICH9  * 100;
    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.ICH10 * 100;
    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.ICH11 * 100;
    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.ICH12 * 100;
    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.ICH13 * 100;
    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.ICH14 * 100;
    modbusParams.userInterfaceDataBuffer[index++] = RMS_Value.ICH15 * 100;

    modbusParams.userInterfaceDataBuffer[index++] = P.Feeder1_A;
    modbusParams.userInterfaceDataBuffer[index++] = P.Feeder1_B;
    modbusParams.userInterfaceDataBuffer[index++] = P.Feeder1_C;
    modbusParams.userInterfaceDataBuffer[index++] = P.Feeder2_A;
    modbusParams.userInterfaceDataBuffer[index++] = P.Feeder2_B;
    modbusParams.userInterfaceDataBuffer[index++] = P.Feeder2_C;
    modbusParams.userInterfaceDataBuffer[index++] = P.Feeder3_A;
    modbusParams.userInterfaceDataBuffer[index++] = P.Feeder3_B;
    modbusParams.userInterfaceDataBuffer[index++] = P.Feeder3_C;
    modbusParams.userInterfaceDataBuffer[index++] = P.Feeder4_A;
    modbusParams.userInterfaceDataBuffer[index++] = P.Feeder4_B;
    modbusParams.userInterfaceDataBuffer[index++] = P.Feeder4_C;
    modbusParams.userInterfaceDataBuffer[index++] = P.Feeder5_A;
    modbusParams.userInterfaceDataBuffer[index++] = P.Feeder5_B;
    modbusParams.userInterfaceDataBuffer[index++] = P.Feeder5_C;

    modbusParams.userInterfaceDataBuffer[index++] = P.Feeder1_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = P.Feeder2_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = P.Feeder3_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = P.Feeder4_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = P.Feeder5_TOT;

    modbusParams.userInterfaceDataBuffer[index++] = Q_New.Feeder1_A;
    modbusParams.userInterfaceDataBuffer[index++] = Q_New.Feeder1_B;
    modbusParams.userInterfaceDataBuffer[index++] = Q_New.Feeder1_C;
    modbusParams.userInterfaceDataBuffer[index++] = Q_New.Feeder2_A;
    modbusParams.userInterfaceDataBuffer[index++] = Q_New.Feeder2_B;
    modbusParams.userInterfaceDataBuffer[index++] = Q_New.Feeder2_C;
    modbusParams.userInterfaceDataBuffer[index++] = Q_New.Feeder3_A;
    modbusParams.userInterfaceDataBuffer[index++] = Q_New.Feeder3_B;
    modbusParams.userInterfaceDataBuffer[index++] = Q_New.Feeder3_C;
    modbusParams.userInterfaceDataBuffer[index++] = Q_New.Feeder4_A;
    modbusParams.userInterfaceDataBuffer[index++] = Q_New.Feeder4_B;
    modbusParams.userInterfaceDataBuffer[index++] = Q_New.Feeder4_C;
    modbusParams.userInterfaceDataBuffer[index++] = Q_New.Feeder5_A;
    modbusParams.userInterfaceDataBuffer[index++] = Q_New.Feeder5_B;
    modbusParams.userInterfaceDataBuffer[index++] = Q_New.Feeder5_C;

    modbusParams.userInterfaceDataBuffer[index++] = Q_New.Feeder1_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = Q_New.Feeder2_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = Q_New.Feeder3_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = Q_New.Feeder4_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = Q_New.Feeder5_TOT;

    modbusParams.userInterfaceDataBuffer[index++] = S_New.Feeder1_A;
    modbusParams.userInterfaceDataBuffer[index++] = S_New.Feeder1_B;
    modbusParams.userInterfaceDataBuffer[index++] = S_New.Feeder1_C;
    modbusParams.userInterfaceDataBuffer[index++] = S_New.Feeder2_A;
    modbusParams.userInterfaceDataBuffer[index++] = S_New.Feeder2_B;
    modbusParams.userInterfaceDataBuffer[index++] = S_New.Feeder2_C;
    modbusParams.userInterfaceDataBuffer[index++] = S_New.Feeder3_A;
    modbusParams.userInterfaceDataBuffer[index++] = S_New.Feeder3_B;
    modbusParams.userInterfaceDataBuffer[index++] = S_New.Feeder3_C;
    modbusParams.userInterfaceDataBuffer[index++] = S_New.Feeder4_A;
    modbusParams.userInterfaceDataBuffer[index++] = S_New.Feeder4_B;
    modbusParams.userInterfaceDataBuffer[index++] = S_New.Feeder4_C;
    modbusParams.userInterfaceDataBuffer[index++] = S_New.Feeder5_A;
    modbusParams.userInterfaceDataBuffer[index++] = S_New.Feeder5_B;
    modbusParams.userInterfaceDataBuffer[index++] = S_New.Feeder5_C;

    modbusParams.userInterfaceDataBuffer[index++] = S_New.Feeder1_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = S_New.Feeder2_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = S_New.Feeder3_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = S_New.Feeder4_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = S_New.Feeder5_TOT;

    modbusParams.userInterfaceDataBuffer[index++] = PF_New.Feeder1_A * 100;
    modbusParams.userInterfaceDataBuffer[index++] = PF_New.Feeder1_B * 100;
    modbusParams.userInterfaceDataBuffer[index++] = PF_New.Feeder1_C * 100;
    modbusParams.userInterfaceDataBuffer[index++] = PF_New.Feeder2_A * 100;
    modbusParams.userInterfaceDataBuffer[index++] = PF_New.Feeder2_B * 100;
    modbusParams.userInterfaceDataBuffer[index++] = PF_New.Feeder2_C * 100;
    modbusParams.userInterfaceDataBuffer[index++] = PF_New.Feeder3_A * 100;
    modbusParams.userInterfaceDataBuffer[index++] = PF_New.Feeder3_B * 100;
    modbusParams.userInterfaceDataBuffer[index++] = PF_New.Feeder3_C * 100;
    modbusParams.userInterfaceDataBuffer[index++] = PF_New.Feeder4_A * 100;
    modbusParams.userInterfaceDataBuffer[index++] = PF_New.Feeder4_B * 100;
    modbusParams.userInterfaceDataBuffer[index++] = PF_New.Feeder4_C * 100;
    modbusParams.userInterfaceDataBuffer[index++] = PF_New.Feeder5_A * 100;
    modbusParams.userInterfaceDataBuffer[index++] = PF_New.Feeder5_B * 100;
    modbusParams.userInterfaceDataBuffer[index++] = PF_New.Feeder5_C * 100;

    modbusParams.userInterfaceDataBuffer[index++] = PF_New.Feeder1_TOT * 100;
    modbusParams.userInterfaceDataBuffer[index++] = PF_New.Feeder2_TOT * 100;
    modbusParams.userInterfaceDataBuffer[index++] = PF_New.Feeder3_TOT * 100;
    modbusParams.userInterfaceDataBuffer[index++] = PF_New.Feeder4_TOT * 100;
    modbusParams.userInterfaceDataBuffer[index++] = PF_New.Feeder5_TOT * 100;

    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder1_A_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder1_B_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder1_C_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder2_A_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder2_B_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder2_C_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder3_A_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder3_B_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder3_C_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder4_A_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder4_B_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder4_C_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder5_A_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder5_B_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder5_C_Import;

    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder1_Import_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder2_Import_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder3_Import_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder4_Import_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder5_Import_TOT;

    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder1_A_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder1_B_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder1_C_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder2_A_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder2_B_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder2_C_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder3_A_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder3_B_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder3_C_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder4_A_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder4_B_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder4_C_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder5_A_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder5_B_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder5_C_Export;

    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder1_Export_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder2_Export_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder3_Export_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder4_Export_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Active.Feeder5_Export_TOT;

    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder1_A_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder1_B_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder1_C_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder2_A_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder2_B_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder2_C_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder3_A_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder3_B_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder3_C_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder4_A_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder4_B_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder4_C_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder5_A_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder5_B_Import;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder5_C_Import;

    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder1_Import_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder2_Import_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder3_Import_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder4_Import_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder5_Import_TOT;

    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder1_A_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder1_B_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder1_C_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder2_A_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder2_B_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder2_C_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder3_A_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder3_B_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder3_C_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder4_A_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder4_B_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder4_C_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder5_A_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder5_B_Export;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder5_C_Export;

    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder1_Export_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder2_Export_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder3_Export_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder4_Export_TOT;
    modbusParams.userInterfaceDataBuffer[index++] = Energy_Total.Reactive.Feeder5_Export_TOT;

    modbusParams.userInterfaceDataBuffer[index++] = Voltage_Angle.VCH1;
    modbusParams.userInterfaceDataBuffer[index++] = Voltage_Angle.VCH2;
    modbusParams.userInterfaceDataBuffer[index++] = Voltage_Angle.VCH3;

    modbusParams.userInterfaceDataBuffer[index++] = Current_Angle.ICH1;
    modbusParams.userInterfaceDataBuffer[index++] = Current_Angle.ICH2;
    modbusParams.userInterfaceDataBuffer[index++] = Current_Angle.ICH3;
    modbusParams.userInterfaceDataBuffer[index++] = Current_Angle.ICH4;
    modbusParams.userInterfaceDataBuffer[index++] = Current_Angle.ICH5;
    modbusParams.userInterfaceDataBuffer[index++] = Current_Angle.ICH6;
    modbusParams.userInterfaceDataBuffer[index++] = Current_Angle.ICH7;
    modbusParams.userInterfaceDataBuffer[index++] = Current_Angle.ICH8;
    modbusParams.userInterfaceDataBuffer[index++] = Current_Angle.ICH9;
    modbusParams.userInterfaceDataBuffer[index++] = Current_Angle.ICH10;
    modbusParams.userInterfaceDataBuffer[index++] = Current_Angle.ICH11;
    modbusParams.userInterfaceDataBuffer[index++] = Current_Angle.ICH12;
    modbusParams.userInterfaceDataBuffer[index++] = Current_Angle.ICH13;
    modbusParams.userInterfaceDataBuffer[index++] = Current_Angle.ICH14;
    modbusParams.userInterfaceDataBuffer[index++] = Current_Angle.ICH15;

    modbusParams.userInterfaceDataBuffer[index++] = turnRatio.VCH1;
    modbusParams.userInterfaceDataBuffer[index++] = turnRatio.VCH2;
    modbusParams.userInterfaceDataBuffer[index++] = turnRatio.VCH3;

    modbusParams.userInterfaceDataBuffer[index++] = turnRatio.ICH1;
    modbusParams.userInterfaceDataBuffer[index++] = turnRatio.ICH2;
    modbusParams.userInterfaceDataBuffer[index++] = turnRatio.ICH3;
    modbusParams.userInterfaceDataBuffer[index++] = turnRatio.ICH4;
    modbusParams.userInterfaceDataBuffer[index++] = turnRatio.ICH5;
    modbusParams.userInterfaceDataBuffer[index++] = turnRatio.ICH6;
    modbusParams.userInterfaceDataBuffer[index++] = turnRatio.ICH7;
    modbusParams.userInterfaceDataBuffer[index++] = turnRatio.ICH8;
    modbusParams.userInterfaceDataBuffer[index++] = turnRatio.ICH9;
    modbusParams.userInterfaceDataBuffer[index++] = turnRatio.ICH10;
    modbusParams.userInterfaceDataBuffer[index++] = turnRatio.ICH11;
    modbusParams.userInterfaceDataBuffer[index++] = turnRatio.ICH12;
    modbusParams.userInterfaceDataBuffer[index++] = turnRatio.ICH13;
    modbusParams.userInterfaceDataBuffer[index++] = turnRatio.ICH14;
    modbusParams.userInterfaceDataBuffer[index++] = turnRatio.ICH15;

    modbusParams.userInterfaceDataBuffer[index++] = polarity.ICH1;
    modbusParams.userInterfaceDataBuffer[index++] = polarity.ICH2;
    modbusParams.userInterfaceDataBuffer[index++] = polarity.ICH3;
    modbusParams.userInterfaceDataBuffer[index++] = polarity.ICH4;
    modbusParams.userInterfaceDataBuffer[index++] = polarity.ICH5;
    modbusParams.userInterfaceDataBuffer[index++] = polarity.ICH6;
    modbusParams.userInterfaceDataBuffer[index++] = polarity.ICH7;
    modbusParams.userInterfaceDataBuffer[index++] = polarity.ICH8;
    modbusParams.userInterfaceDataBuffer[index++] = polarity.ICH9;
    modbusParams.userInterfaceDataBuffer[index++] = polarity.ICH10;
    modbusParams.userInterfaceDataBuffer[index++] = polarity.ICH11;
    modbusParams.userInterfaceDataBuffer[index++] = polarity.ICH12;
    modbusParams.userInterfaceDataBuffer[index++] = polarity.ICH13;
    modbusParams.userInterfaceDataBuffer[index++] = polarity.ICH14;
    modbusParams.userInterfaceDataBuffer[index++] = polarity.ICH15;

    modbusParams.userInterfaceDataBuffer[index++] = channelReference.CH1;
    modbusParams.userInterfaceDataBuffer[index++] = channelReference.CH2;
    modbusParams.userInterfaceDataBuffer[index++] = channelReference.CH3;
    modbusParams.userInterfaceDataBuffer[index++] = channelReference.CH4;
    modbusParams.userInterfaceDataBuffer[index++] = channelReference.CH5;
    modbusParams.userInterfaceDataBuffer[index++] = channelReference.CH6;
    modbusParams.userInterfaceDataBuffer[index++] = channelReference.CH7;
    modbusParams.userInterfaceDataBuffer[index++] = channelReference.CH8;
    modbusParams.userInterfaceDataBuffer[index++] = channelReference.CH9;
    modbusParams.userInterfaceDataBuffer[index++] = channelReference.CH10;
    modbusParams.userInterfaceDataBuffer[index++] = channelReference.CH11;
    modbusParams.userInterfaceDataBuffer[index++] = channelReference.CH12;
    modbusParams.userInterfaceDataBuffer[index++] = channelReference.CH13;
    modbusParams.userInterfaceDataBuffer[index++] = channelReference.CH14;
    modbusParams.userInterfaceDataBuffer[index++] = channelReference.CH15;

    modbusParams.userInterfaceDataBuffer[index++] = 0;
	
	modbusParams.userInterfaceDataBuffer[index++] = modbusParams.deviceSlaveID[0];
	modbusParams.userInterfaceDataBuffer[index++] = modbusParams.deviceSlaveID[1];
	modbusParams.userInterfaceDataBuffer[index++] = modbusParams.deviceSlaveID[2];
	modbusParams.userInterfaceDataBuffer[index++] = modbusParams.deviceSlaveID[3];
	modbusParams.userInterfaceDataBuffer[index++] = modbusParams.deviceSlaveID[4];
	modbusParams.userInterfaceDataBuffer[index++] = modbusParams.deviceSlaveID[5];
	modbusParams.userInterfaceDataBuffer[index++] = modbusParams.deviceSlaveID[6];
	modbusParams.userInterfaceDataBuffer[index++] = modbusParams.deviceSlaveID[7];
	modbusParams.userInterfaceDataBuffer[index++] = modbusParams.deviceSlaveID[8];
	modbusParams.userInterfaceDataBuffer[index++] = modbusParams.deviceSlaveID[9];
	modbusParams.userInterfaceDataBuffer[index++] = modbusParams.deviceSlaveID[10];
	modbusParams.userInterfaceDataBuffer[index++] = modbusParams.deviceSlaveID[11];
	modbusParams.userInterfaceDataBuffer[index++] = modbusParams.deviceSlaveID[12];
	modbusParams.userInterfaceDataBuffer[index++] = modbusParams.deviceSlaveID[13];
	modbusParams.userInterfaceDataBuffer[index++] = modbusParams.deviceSlaveID[14];

    modbusParams.txBufferIndex = 3;
    modbusParams.modbusTxBuffer[SLAVE_ID] = modbusParams.modbusRxBuffer[SLAVE_ID];
    modbusParams.modbusTxBuffer[FUNCODE]  = modbusParams.modbusRxBuffer[FUNCODE];
    modbusParams.modbusTxBuffer[RES_BYTE_COUNT] = 2 * modbusParams.dataLength;

    if (modbusParams.regAdress == 1000)
    {
        for (int i = 0; i < 62; i++)
        {
          modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.userInterfaceDataBuffer[i])) >> 24;
          modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.userInterfaceDataBuffer[i])) >> 16;
          modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.userInterfaceDataBuffer[i])) >> 8;
          modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.userInterfaceDataBuffer[i]));
        }
        
    }

    if (modbusParams.regAdress == 1124)
    {
				for (int i = 62; i < 124; i++)
        {
          modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.userInterfaceDataBuffer[i])) >> 24;
          modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.userInterfaceDataBuffer[i])) >> 16;
          modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.userInterfaceDataBuffer[i])) >> 8;
          modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.userInterfaceDataBuffer[i]));
        }
    }
    
		if (modbusParams.regAdress == 1248)
    {
				for (int i = 124; i < 186; i++)
        {
          modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.userInterfaceDataBuffer[i])) >> 24;
          modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.userInterfaceDataBuffer[i])) >> 16;
          modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.userInterfaceDataBuffer[i])) >> 8;
          modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.userInterfaceDataBuffer[i]));
        }
    }
		
		if (modbusParams.regAdress == 1372)
    {
				for (int i = 186; i < 248; i++)
        {
          modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.userInterfaceDataBuffer[i])) >> 24;
          modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.userInterfaceDataBuffer[i])) >> 16;
          modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.userInterfaceDataBuffer[i])) >> 8;
          modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.userInterfaceDataBuffer[i]));
        }
    }
		
		
		if (modbusParams.regAdress == 1496)
    {
				for (int i = 248; i < 310; i++)
        {
          modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0xFF000000 & (int32_t)(modbusParams.userInterfaceDataBuffer[i])) >> 24;
          modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x00FF0000 & (int32_t)(modbusParams.userInterfaceDataBuffer[i])) >> 16;
          modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x0000FF00 & (int32_t)(modbusParams.userInterfaceDataBuffer[i])) >> 8;
          modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = (0x000000FF & (int32_t)(modbusParams.userInterfaceDataBuffer[i]));
        }
    }
    rtu_crcCalculation(modbusParams.modbusTxBuffer, modbusParams.txBufferIndex);
    modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = rtuCRC.calculated_H;
    modbusParams.modbusTxBuffer[modbusParams.txBufferIndex++] = rtuCRC.calculated_L;
    modbusParams.txLength = modbusParams.txBufferIndex;
    HAL_UART_Transmit_IT(&huart6, modbusParams.modbusTxBuffer, modbusParams.txBufferIndex);
}
