/**
  ******************************************************************************
  * @file    Modbus_RTU_Slave.h
  * @author  Serbay Ozkan
  * @version V1.0.1
  * @date    06-March-2017
  * @brief   Modbus RTU Slave Application Layer Header File
  ******************************************************************************
  */

#include "stdint.h"

#ifndef MODBUS_RTU_SLAVE_H
#define MODBUS_RTU_SLAVE_H

/************************* Modbus General Definitions *************************/
#define DEBUG                                   0

#define RX_BUFFER_LIMIT                         500
#define TX_BUFFER_LIMIT                         1000
#define WRITE_MULTIPLE_BUFFER_LIMIT             100
#define WRITE_SINGLE_BUFFER_LIMIT               4
#define RECEIVE_TIMEOUT                         10  /* ms */

#define DEVICE_SLAVE_ID                         1
#define DI1000_UI_SLAVE_ID                      250
#define SLAVE_ID                                0
#define TOT_NUM_OF_INT_SLAVE_DEVICES            15
#define MODBUS_STARTING_ADRESS                  1000
#define MODBUS_UPPER_LIMIT_ADRESS               3000
#define MODBUS_LOWER_LIMIT_ADRESS               1000
#define READ_HOLDING_REGISTER_ADRESS_LIMIT      3000
#define WRITE_MULTIPLE_REGISTER_ADRESS_LIMIT    3000
#define MODBUS_MAX_DATA_LEN                     40000

#define FUNCODE                                 1
#define REG_ADRESS_HIGH                         2
#define REG_ADRESS_LOW                          3
#define DATA_LEN_HIGH                           4
#define DATA_LEN_LOW                            5
#define RES_BYTE_COUNT                          2

#define READ_HOLDING_REGISTER                   3
#define READ_DISCRETE_INPUT                     2
#define WRITE_MULTIPLE_REGISTER                 16
#define WRITE_SINGLE_REGISTER                   6
#define UNIQUE_FUNCTION_REGISTER                0X31
/******************************************************************************/

/************************* Holding Register Definitions ***********************/
#define READ_VAN                                1000
#define READ_VBN                                1002
#define READ_VCN                                1004
#define READ_VAB                                1006
#define READ_VBC                                1008
#define READ_VCA                                1010
#define READ_ICHN                               1012
#define READ_P_FEEDER           	            1014
#define READ_Q_FEEDER                           1016
#define READ_S_FEEDER                           1018
#define READ_PF_FEEDER                          1020
#define READ_E_FEEDER_ACT_IMP                   1022
#define READ_E_FEEDER_ACT_EXP                   1024
#define READ_E_FEEDER_REACT_IMP                 1026
#define READ_E_FEEDER_REACT_EXP                 1028
#define READ_FEEDER_SLAVE_ADRESS                1030
#define READ_VOLTAGE_SCALING_VAN                1032
#define READ_VOLTAGE_SCALING_VBN                1034
#define READ_VOLTAGE_SCALING_VCN                1036
#define READ_CURRENT_SCALING_ICHN               1038
#define READ_CURRENT_POLARITY_ICHN              1040
#define READ_VOLTAGE_ANGLE_VCH_AN               1042
#define READ_VOLTAGE_ANGLE_VCH_BN               1044
#define READ_VOLTAGE_ANGLE_VCH_CN               1046
#define READ_CURRENT_ANGLE_ICHN                 1048
#define READ_CHANNEL_REFERENCE                  1050
/******************************************************************************/

/************************* Holding Register Definitions ***********************/
#define READ_VAN_THREE_PHASE                    2000
#define READ_VBN_THREE_PHASE                    2002
#define READ_VCN_THREE_PHASE                    2004

#define READ_VAB_THREE_PHASE                    2006
#define READ_VBC_THREE_PHASE                    2008
#define READ_VCA_THREE_PHASE                    2010

#define READ_ICH1_THREE_PHASE                   2012
#define READ_ICH1_FUND_THREE_PHASE              2014
#define READ_ICH1_3HF_THREE_PHASE               2016

#define READ_ICH2_THREE_PHASE                   2018
#define READ_ICH2_FUND_THREE_PHASE              2020
#define READ_ICH2_3HF_THREE_PHASE               2022

#define READ_ICH3_THREE_PHASE                   2024
#define READ_ICH3_FUND_THREE_PHASE              2026
#define READ_ICH3_3HF_THREE_PHASE               2028

#define READ_ICHN_THREE_PHASE                   2030

#define READ_P_FEEDER_THREE_PHASE1           	2032
#define READ_P_FEEDER_THREE_PHASE2           	2034
#define READ_P_FEEDER_THREE_PHASE3           	2036
#define READ_P_FEEDER_THREE_PHASE           	2038

#define READ_Q_FEEDER_THREE_PHASE1              2040
#define READ_Q_FEEDER_THREE_PHASE2              2042
#define READ_Q_FEEDER_THREE_PHASE3              2044
#define READ_Q_FEEDER_THREE_PHASE               2046

#define READ_S_FEEDER_THREE_PHASE               2048

#define READ_PF_FEEDER_THREE_PHASE              2050

#define READ_E_FEEDER_ACT_IMP_THREE_PHASE       2052
#define READ_E_FEEDER_ACT_EXP_THREE_PHASE       2054
#define READ_E_FEEDER_REACT_IMP_THREE_PHASE     2056
#define READ_E_FEEDER_REACT_EXP_THREE_PHASE     2058

#define READ_CURRENT_UNB_FACTOR                 2060
#define READ_FEEDER_DEMAND                      2062

#define READ_FEEDER_SLAVE_ADRESS_THREE_PHASE    2064
#define READ_VOLTAGE_SCALING_VAN_THREE_PHASE    2066
#define READ_VOLTAGE_SCALING_VBN_THREE_PHASE    2068
#define READ_VOLTAGE_SCALING_VCN_THREE_PHASE    2070
#define READ_CURRENT_SCALING_ICH1_THREE_PHASE   2072
#define READ_CURRENT_SCALING_ICH2_THREE_PHASE   2074
#define READ_CURRENT_SCALING_ICH3_THREE_PHASE   2076
#define READ_CURRENT_POLARITY_ICH1_THREE_PHASE  2078
#define READ_CURRENT_POLARITY_ICH2_THREE_PHASE  2080
#define READ_CURRENT_POLARITY_ICH3_THREE_PHASE  2082
#define READ_VOLTAGE_ANGLE_VCH_AN_THREE_PHASE   2084
#define READ_VOLTAGE_ANGLE_VCH_BN_THREE_PHASE   2086
#define READ_VOLTAGE_ANGLE_VCH_CN_THREE_PHASE   2088
#define READ_CURRENT_ANGLE_ICH1_THREE_PHASE     2090
#define READ_CURRENT_ANGLE_ICH2_THREE_PHASE     2092
#define READ_CURRENT_ANGLE_ICH3_THREE_PHASE     2094
/******************************************************************************/

/******************* Write Multiple Register Definitions **********************/
#define CHANGE_SLAVEID_FEEDER1                  1000
#define CHANGE_SLAVEID_FEEDER2                  1001
#define CHANGE_SLAVEID_FEEDER3                  1002
#define CHANGE_SLAVEID_FEEDER4                  1003
#define CHANGE_SLAVEID_FEEDER5                  1004
#define CHANGE_SLAVEID_FEEDER6                  1005
#define CHANGE_SLAVEID_FEEDER7                  1006
#define CHANGE_SLAVEID_FEEDER8                  1007
#define CHANGE_SLAVEID_FEEDER9                  1008
#define CHANGE_SLAVEID_FEEDER10                 1009
#define CHANGE_SLAVEID_FEEDER11                 1010
#define CHANGE_SLAVEID_FEEDER12                 1011
#define CHANGE_SLAVEID_FEEDER13                 1012
#define CHANGE_SLAVEID_FEEDER14                 1013
#define CHANGE_SLAVEID_FEEDER15                 1014
#define CHANGE_DEVICE_BAUDRATE                  1015
#define CHANGE_VOLTAGE_SCALING_VCH1             1016
#define CHANGE_VOLTAGE_SCALING_VCH2             1017
#define CHANGE_VOLTAGE_SCALING_VCH3             1018
#define CHANGE_CURRENT_SCALING_ICH1             1019
#define CHANGE_CURRENT_SCALING_ICH2             1020
#define CHANGE_CURRENT_SCALING_ICH3             1021
#define CHANGE_CURRENT_SCALING_ICH4             1022
#define CHANGE_CURRENT_SCALING_ICH5             1023
#define CHANGE_CURRENT_SCALING_ICH6             1024
#define CHANGE_CURRENT_SCALING_ICH7             1025
#define CHANGE_CURRENT_SCALING_ICH8             1026
#define CHANGE_CURRENT_SCALING_ICH9             1027
#define CHANGE_CURRENT_SCALING_ICH10            1028
#define CHANGE_CURRENT_SCALING_ICH11            1029
#define CHANGE_CURRENT_SCALING_ICH12            1030
#define CHANGE_CURRENT_SCALING_ICH13            1031
#define CHANGE_CURRENT_SCALING_ICH14            1032
#define CHANGE_CURRENT_SCALING_ICH15            1033
#define CHANGE_CURRENT_POLARITY_ICH1            1034
#define CHANGE_CURRENT_POLARITY_ICH2            1035
#define CHANGE_CURRENT_POLARITY_ICH3            1036
#define CHANGE_CURRENT_POLARITY_ICH4            1037
#define CHANGE_CURRENT_POLARITY_ICH5            1038
#define CHANGE_CURRENT_POLARITY_ICH6            1039
#define CHANGE_CURRENT_POLARITY_ICH7            1040
#define CHANGE_CURRENT_POLARITY_ICH8            1041
#define CHANGE_CURRENT_POLARITY_ICH9            1042
#define CHANGE_CURRENT_POLARITY_ICH10           1043
#define CHANGE_CURRENT_POLARITY_ICH11           1044
#define CHANGE_CURRENT_POLARITY_ICH12           1045
#define CHANGE_CURRENT_POLARITY_ICH13           1046
#define CHANGE_CURRENT_POLARITY_ICH14           1047
#define CHANGE_CURRENT_POLARITY_ICH15           1048
#define CHANGE_VOLTAGE_REFERENCE_CH1            1049
#define CHANGE_VOLTAGE_REFERENCE_CH2            1050
#define CHANGE_VOLTAGE_REFERENCE_CH3            1051
#define CHANGE_VOLTAGE_REFERENCE_CH4            1052
#define CHANGE_VOLTAGE_REFERENCE_CH5            1053
#define CHANGE_VOLTAGE_REFERENCE_CH6            1054
#define CHANGE_VOLTAGE_REFERENCE_CH7            1055
#define CHANGE_VOLTAGE_REFERENCE_CH8            1056
#define CHANGE_VOLTAGE_REFERENCE_CH9            1057
#define CHANGE_VOLTAGE_REFERENCE_CH10           1058
#define CHANGE_VOLTAGE_REFERENCE_CH11           1059
#define CHANGE_VOLTAGE_REFERENCE_CH12           1060
#define CHANGE_VOLTAGE_REFERENCE_CH13           1061
#define CHANGE_VOLTAGE_REFERENCE_CH14           1062
#define CHANGE_VOLTAGE_REFERENCE_CH15           1063
/******************************************************************************/

#define VOLTAGE_REFERENCE_VCH1                  1
#define VOLTAGE_REFERENCE_VCH2                  2
#define VOLTAGE_REFERENCE_VCH3                  3

/******************* Write Single Register Definitions ************************/
#define WRITE_FLASH_SAVE_ALL                    1000
#define WRITE_DEVICE_SOFTWARE_RESET             1001
#define USB_BOOT_MODE_ENABLE                    2000
/******************************************************************************/

/*************************** Typedef Definitions ******************************/
typedef struct
{
  uint16_t calculated;
  uint16_t calculated_H;
  uint16_t calculated_L;
  uint16_t received;
  uint16_t received_H;
  uint16_t received_L;
}Typedef_rtuCRC;

typedef struct
{
  uint16_t rxFrameLen;
  uint16_t rxIndex;
  uint16_t regAdress;
  uint16_t dataLength;
  uint16_t txLength;
  uint16_t selectedSlaveID;
  uint16_t txBufferIndex;
  uint32_t startingAdress;
  uint32_t endingAdress;
  uint32_t deviceSlaveID[TOT_NUM_OF_INT_SLAVE_DEVICES];
  uint16_t recTimeOut;
  uint8_t  recComp:1;
  uint8_t  recFlag:1;
  uint8_t  transmitComp:1;
  uint8_t  receivedData;
  unsigned char modbusRxBuffer[RX_BUFFER_LIMIT];
  unsigned char modbusTxBuffer[TX_BUFFER_LIMIT];
  float RMS_ICH;
  float RMS_ICH1;
  float RMS_ICH1_FUND;
  float RMS_ICH1_3HF;
  float RMS_ICH2;
  float RMS_ICH2_FUND;
  float RMS_ICH2_3HF;
  float RMS_ICH3;
  float RMS_ICH3_FUND;
  float RMS_ICH3_3HF;
  float RMS_ICHN;
  float P;
  float P_Phase1;
  float P_Phase2;
  float P_Phase3;
  float P_total;
  float Q;
  float Q_Phase1;
  float Q_Phase2;
  float Q_Phase3;
  float Q_total;
  float S;
  float S_Phase1;
  float S_Phase2;
  float S_Phase3;
  float S_total;
  float PF;
  float PF_Phase1;
  float PF_Phase2;
  float PF_Phase3;
  float PF_total;
  uint32_t E_ACT_IMP;
  uint32_t E_ACT_EXP;
  uint32_t E_REAC_IMP;
  uint32_t E_REAC_EXP;
  uint32_t E_ACT_IMP_TOTAL;
  uint32_t E_ACT_EXP_TOTAL;
  uint32_t E_REAC_IMP_TOTAL;
  uint32_t E_REAC_EXP_TOTAL;
  uint32_t channelRef;
  uint32_t ICH_turnRatio;
  int32_t ICH_polarity;
  float   currentAngle;
  float   currentAngle_CH1;
  float   currentAngle_CH2;
  float   currentAngle_CH3;
  uint32_t ICH_turnRatio_CH1;
  uint32_t ICH_turnRatio_CH2;
  uint32_t ICH_turnRatio_CH3;
  int32_t  ICH_polarity_CH1;
  int32_t  ICH_polarity_CH2;
  int32_t  ICH_polarity_CH3;
  float    currentUnbFactor;
  int32_t  userInterfaceDataBuffer[1024];
  uint32_t demand;
}Typedef_modbusParams;
/******************************************************************************/

typedef struct
{
  uint8_t CH1;
  uint8_t CH2;
  uint8_t CH3;
  uint8_t CH4;
  uint8_t CH5;
  uint8_t CH6;
  uint8_t CH7;
  uint8_t CH8;
  uint8_t CH9;
  uint8_t CH10;
  uint8_t CH11;
  uint8_t CH12;
  uint8_t CH13;
  uint8_t CH14;
  uint8_t CH15;
}Typedef_channelReference;

/************************ Modbus Function Prototypes **************************/
void rtu_crcCalculation(unsigned char *crcBuf, uint16_t crcLength);
void rtu_Feeder1DataPrep_writeMultipleRegisters(void);
void rtu_Feeder1DataPrep_writeMultipleRegisters(void);
void rtu_Feeder1DataPrep_singleWriteRegisters(void);
void rtu_transmitData_writeMultipleRegisters(void);
void rtu_getFeeder1_writeMultipleRegisters(void);
void rtu_transmitData_readHoldingRegister(void);
void rtu_transmitData_writeSingleRegister(void);
void rtu_getFeeder1_writeSingleRegister(void);
void rtu_transmitEnable_receiveDisable(void);
void rtu_transmitDisable_receiveEnable(void);
void rtu_modbusReceiveCompCallBack(void);
void rtu_writeMultipleRegisters(void);
void rtu_ModbusFrameProcessing(void);
void rtu_readHoldingRegister(void);
void rtu_modbusReceiveTimeout(void);
void rtu_modbusRuntimeProcess(void);
void rtu_writeSingleRegister(void);
void rtu_readUniqueRegisters(void);
void rtu_Feeder1DataPrep(void);
void rtu_genericDataPrep(void);
void rtu_prepareUserInterfaceData(void);
/******************************************************************************/

/************************ Modbus Extern Function Prototypes *******************/
extern void rtu_modbusReceiveTimeout(void);
extern void rtu_modbusReceiveCompCallBack(void);
extern void rtu_modbusRuntimeProcess(void);
extern Typedef_modbusParams     modbusParams;
extern Typedef_channelReference channelReference;
/******************************************************************************/

#endif /* MODBUS_RTU_SLAVE_H */
