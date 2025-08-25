/**
  *****************************************************************************
  * @file    RMS_Calculation.c
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
#include "math.h"
#include "string.h"
#include "PQ_Calculation.h"
#include "RMS_Calculation.h"
#include "ADC_Process.h"
#include "PhaseShift.h"
#include "Modbus_RTU_Slave.h"
/* Typedefs ------------------------------------------------------------------*/
Typedef_PowerSum P_Sum;
Typedef_PowerSum Q_Sum;
Typedef_PowerSum Q_Sum_New;
Typedef_Power    P;
Typedef_Power    Q;
Typedef_Power    Q_New;
Typedef_Power    S;
Typedef_Power    S_New;
Typedef_Power    PF;
Typedef_Power    PF_New;
Typedef_Current_Ang Current_Angle;
Typedef_Voltage_Ang Voltage_Angle;
Typedef_demandParams  demandParams;

struct struct_Energy_Calculation Energy;
struct struct_Energy_Calculation_Tot Energy_Total;
/* User Variables ------------------------------------------------------------*/
uint32_t pqCounter = 0;

/**
  * @brief  This function reads all channels of MCP3919 ADC and converting
  			ADC data to processable format
  * @note
  * @param  None
  * @retval None
  */


void pmu_powerParamsCalculation(void)
{
    pqCounter++;
    pmu_P_Sum_Calculation();
    pmu_Q_Sum_Calculation();
    pmu_Q_Sum_Calculation_New();

    if (pqCounter == 631)
		{
			pmu_P_Calculation();
			// pmu_Q_Calculation();
      pmu_Q_Calculation_New();
			// pmu_S_Calculation();
      pmu_S_Calculation_New();
			// pmu_PF_Calculation();
      pmu_PF_Calculation_New();
			// pmu_Energy_Calculation();
      pmu_Energy_Calculation_New();
			pmu_Current_Angle_Calculation();
			pmu_clear_PQ_Sum_Array();
      pqCounter = 0;
		}
}

void pmu_P_Sum_Calculation(void)
{
    if (channelReference.CH1 == VOLTAGE_REFERENCE_VCH1){ P_Sum.Feeder1_A =
                         P_Sum.Feeder1_A + (ADC_Values.VCH1 * ADC_Values.ICH1);}
    if (channelReference.CH1 == VOLTAGE_REFERENCE_VCH2){ P_Sum.Feeder1_A =
                         P_Sum.Feeder1_A + (ADC_Values.VCH2 * ADC_Values.ICH1);}
    if (channelReference.CH1 == VOLTAGE_REFERENCE_VCH3){ P_Sum.Feeder1_A =
                         P_Sum.Feeder1_A + (ADC_Values.VCH3 * ADC_Values.ICH1);}

   if (channelReference.CH2 == VOLTAGE_REFERENCE_VCH1){ P_Sum.Feeder1_B =
                         P_Sum.Feeder1_B + (ADC_Values.VCH1 * ADC_Values.ICH2);}
   if (channelReference.CH2 == VOLTAGE_REFERENCE_VCH2){ P_Sum.Feeder1_B =
                         P_Sum.Feeder1_B + (ADC_Values.VCH2 * ADC_Values.ICH2);}
   if (channelReference.CH2 == VOLTAGE_REFERENCE_VCH3){ P_Sum.Feeder1_B =
                         P_Sum.Feeder1_B + (ADC_Values.VCH3 * ADC_Values.ICH2);}

   if (channelReference.CH3 == VOLTAGE_REFERENCE_VCH1){ P_Sum.Feeder1_C =
                         P_Sum.Feeder1_C + (ADC_Values.VCH1 * ADC_Values.ICH3);}
   if (channelReference.CH3 == VOLTAGE_REFERENCE_VCH2){ P_Sum.Feeder1_C =
                         P_Sum.Feeder1_C + (ADC_Values.VCH2 * ADC_Values.ICH3);}
   if (channelReference.CH3 == VOLTAGE_REFERENCE_VCH3){ P_Sum.Feeder1_C =
                         P_Sum.Feeder1_C + (ADC_Values.VCH3 * ADC_Values.ICH3);}

   if (channelReference.CH4 == VOLTAGE_REFERENCE_VCH1){ P_Sum.Feeder2_A =
                         P_Sum.Feeder2_A + (ADC_Values.VCH1 * ADC_Values.ICH4);}
   if (channelReference.CH4 == VOLTAGE_REFERENCE_VCH2){ P_Sum.Feeder2_A =
                         P_Sum.Feeder2_A + (ADC_Values.VCH2 * ADC_Values.ICH4);}
   if (channelReference.CH4 == VOLTAGE_REFERENCE_VCH3){ P_Sum.Feeder2_A =
                         P_Sum.Feeder2_A + (ADC_Values.VCH3 * ADC_Values.ICH4);}

   if (channelReference.CH5 == VOLTAGE_REFERENCE_VCH1){ P_Sum.Feeder2_B =
                         P_Sum.Feeder2_B + (ADC_Values.VCH1 * ADC_Values.ICH5);}
   if (channelReference.CH5 == VOLTAGE_REFERENCE_VCH2){ P_Sum.Feeder2_B =
                         P_Sum.Feeder2_B + (ADC_Values.VCH2 * ADC_Values.ICH5);}
   if (channelReference.CH5 == VOLTAGE_REFERENCE_VCH3){ P_Sum.Feeder2_B =
                         P_Sum.Feeder2_B + (ADC_Values.VCH3 * ADC_Values.ICH5);}

   if (channelReference.CH6 == VOLTAGE_REFERENCE_VCH1){ P_Sum.Feeder2_C =
                         P_Sum.Feeder2_C + (ADC_Values.VCH1 * ADC_Values.ICH6);}
   if (channelReference.CH6 == VOLTAGE_REFERENCE_VCH2){ P_Sum.Feeder2_C =
                         P_Sum.Feeder2_C + (ADC_Values.VCH2 * ADC_Values.ICH6);}
   if (channelReference.CH6 == VOLTAGE_REFERENCE_VCH3){ P_Sum.Feeder2_C =
                         P_Sum.Feeder2_C + (ADC_Values.VCH3 * ADC_Values.ICH6);}

   if (channelReference.CH7 == VOLTAGE_REFERENCE_VCH1){ P_Sum.Feeder3_A =
                         P_Sum.Feeder3_A + (ADC_Values.VCH1 * ADC_Values.ICH7);}
   if (channelReference.CH7 == VOLTAGE_REFERENCE_VCH2){ P_Sum.Feeder3_A =
                         P_Sum.Feeder3_A + (ADC_Values.VCH2 * ADC_Values.ICH7);}
   if (channelReference.CH7 == VOLTAGE_REFERENCE_VCH3){ P_Sum.Feeder3_A =
                         P_Sum.Feeder3_A + (ADC_Values.VCH3 * ADC_Values.ICH7);}

   if (channelReference.CH8 == VOLTAGE_REFERENCE_VCH1){ P_Sum.Feeder3_B =
                         P_Sum.Feeder3_B + (ADC_Values.VCH1 * ADC_Values.ICH8);}
   if (channelReference.CH8 == VOLTAGE_REFERENCE_VCH2){ P_Sum.Feeder3_B =
                         P_Sum.Feeder3_B + (ADC_Values.VCH2 * ADC_Values.ICH8);}
   if (channelReference.CH8 == VOLTAGE_REFERENCE_VCH3){ P_Sum.Feeder3_B =
                         P_Sum.Feeder3_B + (ADC_Values.VCH3 * ADC_Values.ICH8);}

   if (channelReference.CH9 == VOLTAGE_REFERENCE_VCH1){ P_Sum.Feeder3_C =
                         P_Sum.Feeder3_C + (ADC_Values.VCH1 * ADC_Values.ICH9);}
   if (channelReference.CH9 == VOLTAGE_REFERENCE_VCH2){ P_Sum.Feeder3_C =
                         P_Sum.Feeder3_C + (ADC_Values.VCH2 * ADC_Values.ICH9);}
   if (channelReference.CH9 == VOLTAGE_REFERENCE_VCH3){ P_Sum.Feeder3_C =
                         P_Sum.Feeder3_C + (ADC_Values.VCH3 * ADC_Values.ICH9);}

   if (channelReference.CH10 == VOLTAGE_REFERENCE_VCH1){ P_Sum.Feeder4_A =
                        P_Sum.Feeder4_A + (ADC_Values.VCH1 * ADC_Values.ICH10);}
   if (channelReference.CH10 == VOLTAGE_REFERENCE_VCH2){ P_Sum.Feeder4_A =
                        P_Sum.Feeder4_A + (ADC_Values.VCH2 * ADC_Values.ICH10);}
   if (channelReference.CH10 == VOLTAGE_REFERENCE_VCH3){ P_Sum.Feeder4_A =
                        P_Sum.Feeder4_A + (ADC_Values.VCH3 * ADC_Values.ICH10);}

   if (channelReference.CH11 == VOLTAGE_REFERENCE_VCH1){ P_Sum.Feeder4_B =
                        P_Sum.Feeder4_B + (ADC_Values.VCH1 * ADC_Values.ICH11);}
   if (channelReference.CH11 == VOLTAGE_REFERENCE_VCH2){ P_Sum.Feeder4_B =
                        P_Sum.Feeder4_B + (ADC_Values.VCH2 * ADC_Values.ICH11);}
   if (channelReference.CH11 == VOLTAGE_REFERENCE_VCH3){ P_Sum.Feeder4_B =
                        P_Sum.Feeder4_B + (ADC_Values.VCH3 * ADC_Values.ICH11);}

   if (channelReference.CH12 == VOLTAGE_REFERENCE_VCH1){ P_Sum.Feeder4_C =
                        P_Sum.Feeder4_C + (ADC_Values.VCH1 * ADC_Values.ICH12);}
   if (channelReference.CH12 == VOLTAGE_REFERENCE_VCH2){ P_Sum.Feeder4_C =
                        P_Sum.Feeder4_C + (ADC_Values.VCH2 * ADC_Values.ICH12);}
   if (channelReference.CH12 == VOLTAGE_REFERENCE_VCH3){ P_Sum.Feeder4_C =
                        P_Sum.Feeder4_C + (ADC_Values.VCH3 * ADC_Values.ICH12);}

   if (channelReference.CH13 == VOLTAGE_REFERENCE_VCH1){ P_Sum.Feeder5_A =
                        P_Sum.Feeder5_A + (ADC_Values.VCH1 * ADC_Values.ICH13);}
   if (channelReference.CH13 == VOLTAGE_REFERENCE_VCH2){ P_Sum.Feeder5_A =
                        P_Sum.Feeder5_A + (ADC_Values.VCH2 * ADC_Values.ICH13);}
   if (channelReference.CH13 == VOLTAGE_REFERENCE_VCH3){ P_Sum.Feeder5_A =
                        P_Sum.Feeder5_A + (ADC_Values.VCH3 * ADC_Values.ICH13);}

   if (channelReference.CH14 == VOLTAGE_REFERENCE_VCH1){ P_Sum.Feeder5_B =
                        P_Sum.Feeder5_B + (ADC_Values.VCH1 * ADC_Values.ICH14);}
   if (channelReference.CH14 == VOLTAGE_REFERENCE_VCH2){ P_Sum.Feeder5_B =
                        P_Sum.Feeder5_B + (ADC_Values.VCH2 * ADC_Values.ICH14);}
   if (channelReference.CH14 == VOLTAGE_REFERENCE_VCH3){ P_Sum.Feeder5_B =
                        P_Sum.Feeder5_B + (ADC_Values.VCH3 * ADC_Values.ICH14);}

   if (channelReference.CH15 == VOLTAGE_REFERENCE_VCH1){ P_Sum.Feeder5_C =
                        P_Sum.Feeder5_C + (ADC_Values.VCH1 * ADC_Values.ICH15);}
   if (channelReference.CH15 == VOLTAGE_REFERENCE_VCH2){ P_Sum.Feeder5_C =
                        P_Sum.Feeder5_C + (ADC_Values.VCH2 * ADC_Values.ICH15);}
   if (channelReference.CH15 == VOLTAGE_REFERENCE_VCH3){ P_Sum.Feeder5_C =
                        P_Sum.Feeder5_C + (ADC_Values.VCH3 * ADC_Values.ICH15);}
}

void pmu_Q_Sum_Calculation(void)
{
    Q_Sum.Feeder1_A = Q_Sum.Feeder1_A + (ADC_Values.VCH23 * ADC_Values.ICH1);
    Q_Sum.Feeder1_B = Q_Sum.Feeder1_B + (ADC_Values.VCH31 * ADC_Values.ICH2);
    Q_Sum.Feeder1_C = Q_Sum.Feeder1_C + (ADC_Values.VCH12 * ADC_Values.ICH3);

    Q_Sum.Feeder2_A = Q_Sum.Feeder2_A + (ADC_Values.VCH23 * ADC_Values.ICH4);
    Q_Sum.Feeder2_B = Q_Sum.Feeder2_B + (ADC_Values.VCH31 * ADC_Values.ICH5);
    Q_Sum.Feeder2_C = Q_Sum.Feeder2_C + (ADC_Values.VCH12 * ADC_Values.ICH6);

    Q_Sum.Feeder3_A = Q_Sum.Feeder3_A + (ADC_Values.VCH23 * ADC_Values.ICH7);
    Q_Sum.Feeder3_B = Q_Sum.Feeder3_B + (ADC_Values.VCH31 * ADC_Values.ICH8);
    Q_Sum.Feeder3_C = Q_Sum.Feeder3_C + (ADC_Values.VCH12 * ADC_Values.ICH9);

    Q_Sum.Feeder4_A = Q_Sum.Feeder4_A + (ADC_Values.VCH23 * ADC_Values.ICH10);
    Q_Sum.Feeder4_B = Q_Sum.Feeder4_B + (ADC_Values.VCH31 * ADC_Values.ICH11);
    Q_Sum.Feeder4_C = Q_Sum.Feeder4_C + (ADC_Values.VCH12 * ADC_Values.ICH12);

    Q_Sum.Feeder5_A = Q_Sum.Feeder5_A + (ADC_Values.VCH23 * ADC_Values.ICH13);
    Q_Sum.Feeder5_B = Q_Sum.Feeder5_B + (ADC_Values.VCH31 * ADC_Values.ICH14);
    Q_Sum.Feeder5_C = Q_Sum.Feeder5_C + (ADC_Values.VCH12 * ADC_Values.ICH15);
}

void pmu_Q_Sum_Calculation_New(void)
{
  if (channelReference.CH1 == VOLTAGE_REFERENCE_VCH1){ Q_Sum_New.Feeder1_A =
     Q_Sum_New.Feeder1_A + (ADC_Values.VCH1 * signalShiftParams2.lagICH1Shift);}
  if (channelReference.CH1 == VOLTAGE_REFERENCE_VCH2){ Q_Sum_New.Feeder1_A =
     Q_Sum_New.Feeder1_A + (ADC_Values.VCH2 * signalShiftParams2.lagICH1Shift);}
  if (channelReference.CH1 == VOLTAGE_REFERENCE_VCH3){ Q_Sum_New.Feeder1_A =
     Q_Sum_New.Feeder1_A + (ADC_Values.VCH3 * signalShiftParams2.lagICH1Shift);}

  if (channelReference.CH2 == VOLTAGE_REFERENCE_VCH1){ Q_Sum_New.Feeder1_B =
     Q_Sum_New.Feeder1_B + (ADC_Values.VCH1 * signalShiftParams2.lagICH2Shift);}
  if (channelReference.CH2 == VOLTAGE_REFERENCE_VCH2){ Q_Sum_New.Feeder1_B =
     Q_Sum_New.Feeder1_B + (ADC_Values.VCH2 * signalShiftParams2.lagICH2Shift);}
  if (channelReference.CH2 == VOLTAGE_REFERENCE_VCH3){ Q_Sum_New.Feeder1_B =
     Q_Sum_New.Feeder1_B + (ADC_Values.VCH3 * signalShiftParams2.lagICH2Shift);}

  if (channelReference.CH3 == VOLTAGE_REFERENCE_VCH1){ Q_Sum_New.Feeder1_C =
     Q_Sum_New.Feeder1_C + (ADC_Values.VCH1 * signalShiftParams2.lagICH3Shift);}
  if (channelReference.CH3 == VOLTAGE_REFERENCE_VCH2){ Q_Sum_New.Feeder1_C =
     Q_Sum_New.Feeder1_C + (ADC_Values.VCH2 * signalShiftParams2.lagICH3Shift);}
  if (channelReference.CH3 == VOLTAGE_REFERENCE_VCH3){ Q_Sum_New.Feeder1_C =
     Q_Sum_New.Feeder1_C + (ADC_Values.VCH3 * signalShiftParams2.lagICH3Shift);}

  if (channelReference.CH4 == VOLTAGE_REFERENCE_VCH1){ Q_Sum_New.Feeder2_A =
     Q_Sum_New.Feeder2_A + (ADC_Values.VCH1 * signalShiftParams2.lagICH4Shift);}
  if (channelReference.CH4 == VOLTAGE_REFERENCE_VCH2){ Q_Sum_New.Feeder2_A =
     Q_Sum_New.Feeder2_A + (ADC_Values.VCH2 * signalShiftParams2.lagICH4Shift);}
  if (channelReference.CH4 == VOLTAGE_REFERENCE_VCH3){ Q_Sum_New.Feeder2_A =
     Q_Sum_New.Feeder2_A + (ADC_Values.VCH3 * signalShiftParams2.lagICH4Shift);}

  if (channelReference.CH5 == VOLTAGE_REFERENCE_VCH1){ Q_Sum_New.Feeder2_B =
     Q_Sum_New.Feeder2_B + (ADC_Values.VCH1 * signalShiftParams2.lagICH5Shift);}
  if (channelReference.CH5 == VOLTAGE_REFERENCE_VCH2){ Q_Sum_New.Feeder2_B =
     Q_Sum_New.Feeder2_B + (ADC_Values.VCH2 * signalShiftParams2.lagICH5Shift);}
  if (channelReference.CH5 == VOLTAGE_REFERENCE_VCH3){ Q_Sum_New.Feeder2_B =
     Q_Sum_New.Feeder2_B + (ADC_Values.VCH3 * signalShiftParams2.lagICH5Shift);}

  if (channelReference.CH6 == VOLTAGE_REFERENCE_VCH1){ Q_Sum_New.Feeder2_C =
     Q_Sum_New.Feeder2_C + (ADC_Values.VCH1 * signalShiftParams2.lagICH6Shift);}
  if (channelReference.CH6 == VOLTAGE_REFERENCE_VCH2){ Q_Sum_New.Feeder2_C =
     Q_Sum_New.Feeder2_C + (ADC_Values.VCH2 * signalShiftParams2.lagICH6Shift);}
  if (channelReference.CH6 == VOLTAGE_REFERENCE_VCH3){ Q_Sum_New.Feeder2_C =
     Q_Sum_New.Feeder2_C + (ADC_Values.VCH3 * signalShiftParams2.lagICH6Shift);}

  if (channelReference.CH7 == VOLTAGE_REFERENCE_VCH1){ Q_Sum_New.Feeder3_A =
     Q_Sum_New.Feeder3_A + (ADC_Values.VCH1 * signalShiftParams2.lagICH7Shift);}
  if (channelReference.CH7 == VOLTAGE_REFERENCE_VCH2){ Q_Sum_New.Feeder3_A =
     Q_Sum_New.Feeder3_A + (ADC_Values.VCH2 * signalShiftParams2.lagICH7Shift);}
  if (channelReference.CH7 == VOLTAGE_REFERENCE_VCH3){ Q_Sum_New.Feeder3_A =
     Q_Sum_New.Feeder3_A + (ADC_Values.VCH3 * signalShiftParams2.lagICH7Shift);}

  if (channelReference.CH8 == VOLTAGE_REFERENCE_VCH1){ Q_Sum_New.Feeder3_B =
     Q_Sum_New.Feeder3_B + (ADC_Values.VCH1 * signalShiftParams2.lagICH8Shift);}
  if (channelReference.CH8 == VOLTAGE_REFERENCE_VCH2){ Q_Sum_New.Feeder3_B =
     Q_Sum_New.Feeder3_B + (ADC_Values.VCH2 * signalShiftParams2.lagICH8Shift);}
  if (channelReference.CH8 == VOLTAGE_REFERENCE_VCH3){ Q_Sum_New.Feeder3_B =
     Q_Sum_New.Feeder3_B + (ADC_Values.VCH3 * signalShiftParams2.lagICH8Shift);}

  if (channelReference.CH9 == VOLTAGE_REFERENCE_VCH1){ Q_Sum_New.Feeder3_C =
     Q_Sum_New.Feeder3_C + (ADC_Values.VCH1 * signalShiftParams2.lagICH9Shift);}
  if (channelReference.CH9 == VOLTAGE_REFERENCE_VCH2){ Q_Sum_New.Feeder3_C =
     Q_Sum_New.Feeder3_C + (ADC_Values.VCH2 * signalShiftParams2.lagICH9Shift);}
  if (channelReference.CH9 == VOLTAGE_REFERENCE_VCH3){ Q_Sum_New.Feeder3_C =
     Q_Sum_New.Feeder3_C + (ADC_Values.VCH3 * signalShiftParams2.lagICH9Shift);}

  if (channelReference.CH10 == VOLTAGE_REFERENCE_VCH1){ Q_Sum_New.Feeder4_A =
    Q_Sum_New.Feeder4_A + (ADC_Values.VCH1 * signalShiftParams2.lagICH10Shift);}
  if (channelReference.CH10 == VOLTAGE_REFERENCE_VCH2){ Q_Sum_New.Feeder4_A =
    Q_Sum_New.Feeder4_A + (ADC_Values.VCH2 * signalShiftParams2.lagICH10Shift);}
  if (channelReference.CH10 == VOLTAGE_REFERENCE_VCH3){ Q_Sum_New.Feeder4_A =
    Q_Sum_New.Feeder4_A + (ADC_Values.VCH3 * signalShiftParams2.lagICH10Shift);}

  if (channelReference.CH11 == VOLTAGE_REFERENCE_VCH1){ Q_Sum_New.Feeder4_B =
    Q_Sum_New.Feeder4_B + (ADC_Values.VCH1 * signalShiftParams2.lagICH11Shift);}
  if (channelReference.CH11 == VOLTAGE_REFERENCE_VCH2){ Q_Sum_New.Feeder4_B =
    Q_Sum_New.Feeder4_B + (ADC_Values.VCH2 * signalShiftParams2.lagICH11Shift);}
  if (channelReference.CH11 == VOLTAGE_REFERENCE_VCH3){ Q_Sum_New.Feeder4_B =
    Q_Sum_New.Feeder4_B + (ADC_Values.VCH3 * signalShiftParams2.lagICH11Shift);}

  if (channelReference.CH12 == VOLTAGE_REFERENCE_VCH1){ Q_Sum_New.Feeder4_C =
    Q_Sum_New.Feeder4_C + (ADC_Values.VCH1 * signalShiftParams2.lagICH12Shift);}
  if (channelReference.CH12 == VOLTAGE_REFERENCE_VCH2){ Q_Sum_New.Feeder4_C =
    Q_Sum_New.Feeder4_C + (ADC_Values.VCH2 * signalShiftParams2.lagICH12Shift);}
  if (channelReference.CH12 == VOLTAGE_REFERENCE_VCH3){ Q_Sum_New.Feeder4_C =
    Q_Sum_New.Feeder4_C + (ADC_Values.VCH3 * signalShiftParams2.lagICH12Shift);}

  if (channelReference.CH13 == VOLTAGE_REFERENCE_VCH1){ Q_Sum_New.Feeder5_A =
    Q_Sum_New.Feeder5_A + (ADC_Values.VCH1 * signalShiftParams2.lagICH13Shift);}
  if (channelReference.CH13 == VOLTAGE_REFERENCE_VCH2){ Q_Sum_New.Feeder5_A =
    Q_Sum_New.Feeder5_A + (ADC_Values.VCH2 * signalShiftParams2.lagICH13Shift);}
  if (channelReference.CH13 == VOLTAGE_REFERENCE_VCH3){ Q_Sum_New.Feeder5_A =
    Q_Sum_New.Feeder5_A + (ADC_Values.VCH3 * signalShiftParams2.lagICH13Shift);}

  if (channelReference.CH14 == VOLTAGE_REFERENCE_VCH1){ Q_Sum_New.Feeder5_B =
    Q_Sum_New.Feeder5_B + (ADC_Values.VCH1 * signalShiftParams2.lagICH14Shift);}
  if (channelReference.CH14 == VOLTAGE_REFERENCE_VCH2){ Q_Sum_New.Feeder5_B =
    Q_Sum_New.Feeder5_B + (ADC_Values.VCH2 * signalShiftParams2.lagICH14Shift);}
  if (channelReference.CH14 == VOLTAGE_REFERENCE_VCH3){ Q_Sum_New.Feeder5_B =
    Q_Sum_New.Feeder5_B + (ADC_Values.VCH3 * signalShiftParams2.lagICH14Shift);}

  if (channelReference.CH15 == VOLTAGE_REFERENCE_VCH1){ Q_Sum_New.Feeder5_C =
    Q_Sum_New.Feeder5_C + (ADC_Values.VCH1 * signalShiftParams2.lagICH15Shift);}
  if (channelReference.CH15 == VOLTAGE_REFERENCE_VCH2){ Q_Sum_New.Feeder5_C =
    Q_Sum_New.Feeder5_C + (ADC_Values.VCH2 * signalShiftParams2.lagICH15Shift);}
  if (channelReference.CH15 == VOLTAGE_REFERENCE_VCH3){ Q_Sum_New.Feeder5_C =
    Q_Sum_New.Feeder5_C + (ADC_Values.VCH3 * signalShiftParams2.lagICH15Shift);}
}

void pmu_P_Calculation(void)
{
    P.Feeder1_A   = P_Sum.Feeder1_A * PQ_CONSTANT;
    P.Feeder1_B   = P_Sum.Feeder1_B * PQ_CONSTANT;
    P.Feeder1_C   = P_Sum.Feeder1_C * PQ_CONSTANT;
    P.Feeder1_TOT = P.Feeder1_A + P.Feeder1_B + P.Feeder1_C;

    P.Feeder2_A   = P_Sum.Feeder2_A * PQ_CONSTANT;
    P.Feeder2_B   = P_Sum.Feeder2_B * PQ_CONSTANT;
    P.Feeder2_C   = P_Sum.Feeder2_C * PQ_CONSTANT;
    P.Feeder2_TOT = P.Feeder2_A + P.Feeder2_B + P.Feeder2_C;

    P.Feeder3_A   = P_Sum.Feeder3_A * PQ_CONSTANT;
    P.Feeder3_B   = P_Sum.Feeder3_B * PQ_CONSTANT;
    P.Feeder3_C   = P_Sum.Feeder3_C * PQ_CONSTANT;
    P.Feeder3_TOT = P.Feeder3_A + P.Feeder3_B + P.Feeder3_C;

    P.Feeder4_A   = P_Sum.Feeder4_A * PQ_CONSTANT;
    P.Feeder4_B   = P_Sum.Feeder4_B * PQ_CONSTANT;
    P.Feeder4_C   = P_Sum.Feeder4_C * PQ_CONSTANT;
    P.Feeder4_TOT = P.Feeder4_A + P.Feeder4_B + P.Feeder4_C;

    P.Feeder5_A   = P_Sum.Feeder5_A * PQ_CONSTANT;
    P.Feeder5_B   = P_Sum.Feeder5_B * PQ_CONSTANT;
    P.Feeder5_C   = P_Sum.Feeder5_C * PQ_CONSTANT;
    P.Feeder5_TOT = P.Feeder5_A + P.Feeder5_B + P.Feeder5_C;
}

void pmu_Q_Calculation(void)
{
   Q.Feeder1_A   = Q_Sum.Feeder1_A * ISQRT3 * PQ_CONSTANT;
   Q.Feeder1_B   = Q_Sum.Feeder1_B * ISQRT3 * PQ_CONSTANT;
   Q.Feeder1_C   = Q_Sum.Feeder1_C * ISQRT3 * PQ_CONSTANT;
   Q.Feeder1_TOT = Q.Feeder1_A + Q.Feeder1_B + Q.Feeder1_C;

   Q.Feeder2_A   = Q_Sum.Feeder2_A * ISQRT3 * PQ_CONSTANT;
   Q.Feeder2_B   = Q_Sum.Feeder2_B * ISQRT3 * PQ_CONSTANT;
   Q.Feeder2_C   = Q_Sum.Feeder2_C * ISQRT3 * PQ_CONSTANT;
   Q.Feeder2_TOT = Q.Feeder2_A + Q.Feeder2_B + Q.Feeder2_C;

   Q.Feeder3_A   = Q_Sum.Feeder3_A * ISQRT3 * PQ_CONSTANT;
   Q.Feeder3_B   = Q_Sum.Feeder3_B * ISQRT3 * PQ_CONSTANT;
   Q.Feeder3_C   = Q_Sum.Feeder3_C * ISQRT3 * PQ_CONSTANT;
   Q.Feeder3_TOT = Q.Feeder3_A + Q.Feeder3_B + Q.Feeder3_C;

   Q.Feeder4_A   = Q_Sum.Feeder4_A * ISQRT3 * PQ_CONSTANT;
   Q.Feeder4_B   = Q_Sum.Feeder4_B * ISQRT3 * PQ_CONSTANT;
   Q.Feeder4_C   = Q_Sum.Feeder4_C * ISQRT3 * PQ_CONSTANT;
   Q.Feeder4_TOT = Q.Feeder4_A + Q.Feeder4_B + Q.Feeder4_C;

   Q.Feeder5_A   = Q_Sum.Feeder5_A * ISQRT3 * PQ_CONSTANT;
   Q.Feeder5_B   = Q_Sum.Feeder5_B * ISQRT3 * PQ_CONSTANT;
   Q.Feeder5_C   = Q_Sum.Feeder5_C * ISQRT3 * PQ_CONSTANT;
   Q.Feeder5_TOT = Q.Feeder5_A + Q.Feeder5_B + Q.Feeder5_C;
}

void pmu_Q_Calculation_New(void)
{
   Q_New.Feeder1_A   = -(Q_Sum_New.Feeder1_A  * PQ_CONSTANT) + (RMS_Value.ICH1 * 0.8333333333333333f);
   Q_New.Feeder1_B   = -(Q_Sum_New.Feeder1_B  * PQ_CONSTANT) + (RMS_Value.ICH2 * 0.8333333333333333f);
   Q_New.Feeder1_C   = -(Q_Sum_New.Feeder1_C  * PQ_CONSTANT) + (RMS_Value.ICH3 * 0.8333333333333333f);
   Q_New.Feeder1_TOT = Q_New.Feeder1_A + Q_New.Feeder1_B + Q_New.Feeder1_C;

   Q_New.Feeder2_A   = -(Q_Sum_New.Feeder2_A  * PQ_CONSTANT) + (RMS_Value.ICH4 * 0.8333333333333333f);
   Q_New.Feeder2_B   = -(Q_Sum_New.Feeder2_B  * PQ_CONSTANT) + (RMS_Value.ICH5 * 0.8333333333333333f);
   Q_New.Feeder2_C   = -(Q_Sum_New.Feeder2_C  * PQ_CONSTANT) + (RMS_Value.ICH6 * 0.8333333333333333f);
   Q_New.Feeder2_TOT = Q_New.Feeder2_A + Q_New.Feeder2_B + Q_New.Feeder2_C;

   Q_New.Feeder3_A   = -(Q_Sum_New.Feeder3_A  * PQ_CONSTANT) + (RMS_Value.ICH7 * 0.8333333333333333f);
   Q_New.Feeder3_B   = -(Q_Sum_New.Feeder3_B  * PQ_CONSTANT) + (RMS_Value.ICH8 * 0.8333333333333333f);
   Q_New.Feeder3_C   = -(Q_Sum_New.Feeder3_C  * PQ_CONSTANT) + (RMS_Value.ICH9 * 0.8333333333333333f);
   Q_New.Feeder3_TOT = Q_New.Feeder3_A + Q_New.Feeder3_B + Q_New.Feeder3_C;

   Q_New.Feeder4_A   = -(Q_Sum_New.Feeder4_A  * PQ_CONSTANT) + (RMS_Value.ICH10 * 0.8333333333333333f);
   Q_New.Feeder4_B   = -(Q_Sum_New.Feeder4_B  * PQ_CONSTANT) + (RMS_Value.ICH11 * 0.8333333333333333f);
   Q_New.Feeder4_C   = -(Q_Sum_New.Feeder4_C  * PQ_CONSTANT) + (RMS_Value.ICH12 * 0.8333333333333333f);
   Q_New.Feeder4_TOT = Q_New.Feeder4_A + Q_New.Feeder4_B + Q_New.Feeder4_C;

   Q_New.Feeder5_A   = -(Q_Sum_New.Feeder5_A  * PQ_CONSTANT) + (RMS_Value.ICH13 * 0.8333333333333333f);
   Q_New.Feeder5_B   = -(Q_Sum_New.Feeder5_B  * PQ_CONSTANT) + (RMS_Value.ICH14 * 0.8333333333333333f);
   Q_New.Feeder5_C   = -(Q_Sum_New.Feeder5_C  * PQ_CONSTANT) + (RMS_Value.ICH15 * 0.8333333333333333f);
   Q_New.Feeder5_TOT = Q_New.Feeder5_A + Q_New.Feeder5_B + Q_New.Feeder5_C;
}

void pmu_S_Calculation(void)
{
    S.Feeder1_A   = __sqrtf(P.Feeder1_A * P.Feeder1_A + Q.Feeder1_A * Q.Feeder1_A);
    S.Feeder1_B   = __sqrtf(P.Feeder1_B * P.Feeder1_B + Q.Feeder1_B * Q.Feeder1_B);
    S.Feeder1_C   = __sqrtf(P.Feeder1_C * P.Feeder1_C + Q.Feeder1_C * Q.Feeder1_C);
    S.Feeder1_TOT = __sqrtf(P.Feeder1_TOT * P.Feeder1_TOT + Q.Feeder1_TOT * Q.Feeder1_TOT);

    S.Feeder2_A   = __sqrtf(P.Feeder2_A * P.Feeder2_A + Q.Feeder2_A * Q.Feeder2_A);
    S.Feeder2_B   = __sqrtf(P.Feeder2_B * P.Feeder2_B + Q.Feeder2_B * Q.Feeder2_B);
    S.Feeder2_C   = __sqrtf(P.Feeder2_C * P.Feeder2_C + Q.Feeder2_C * Q.Feeder2_C);
    S.Feeder2_TOT = __sqrtf(P.Feeder2_TOT * P.Feeder2_TOT + Q.Feeder2_TOT * Q.Feeder2_TOT);

    S.Feeder3_A   = __sqrtf(P.Feeder3_A * P.Feeder3_A + Q.Feeder3_A * Q.Feeder3_A);
    S.Feeder3_B   = __sqrtf(P.Feeder3_B * P.Feeder3_B + Q.Feeder3_B * Q.Feeder3_B);
    S.Feeder3_C   = __sqrtf(P.Feeder3_C * P.Feeder3_C + Q.Feeder3_C * Q.Feeder3_C);
    S.Feeder3_TOT = __sqrtf(P.Feeder3_TOT * P.Feeder3_TOT + Q.Feeder3_TOT * Q.Feeder3_TOT);

    S.Feeder4_A   = __sqrtf(P.Feeder4_A * P.Feeder4_A + Q.Feeder4_A * Q.Feeder4_A);
    S.Feeder4_B   = __sqrtf(P.Feeder4_B * P.Feeder4_B + Q.Feeder4_B * Q.Feeder4_B);
    S.Feeder4_C   = __sqrtf(P.Feeder4_C * P.Feeder4_C + Q.Feeder4_C * Q.Feeder4_C);
    S.Feeder4_TOT = __sqrtf(P.Feeder4_TOT * P.Feeder4_TOT + Q.Feeder4_TOT * Q.Feeder4_TOT);


    S.Feeder5_A   = __sqrtf(P.Feeder5_A * P.Feeder5_A + Q.Feeder5_A * Q.Feeder5_A);
    S.Feeder5_B   = __sqrtf(P.Feeder5_B * P.Feeder5_B + Q.Feeder5_B * Q.Feeder5_B);
    S.Feeder5_C   = __sqrtf(P.Feeder5_C * P.Feeder5_C + Q.Feeder5_C * Q.Feeder5_C);
    S.Feeder5_TOT = __sqrtf(P.Feeder5_TOT * P.Feeder5_TOT + Q.Feeder5_TOT * Q.Feeder5_TOT);
}

void pmu_S_Calculation_New(void)
{
    S_New.Feeder1_A   = __sqrtf(P.Feeder1_A * P.Feeder1_A + Q_New.Feeder1_A * Q_New.Feeder1_A);
    S_New.Feeder1_B   = __sqrtf(P.Feeder1_B * P.Feeder1_B + Q_New.Feeder1_B * Q_New.Feeder1_B);
    S_New.Feeder1_C   = __sqrtf(P.Feeder1_C * P.Feeder1_C + Q_New.Feeder1_C * Q_New.Feeder1_C);
    S_New.Feeder1_TOT = __sqrtf(P.Feeder1_TOT * P.Feeder1_TOT + Q_New.Feeder1_TOT * Q_New.Feeder1_TOT);

    S_New.Feeder2_A   = __sqrtf(P.Feeder2_A * P.Feeder2_A + Q_New.Feeder2_A * Q_New.Feeder2_A);
    S_New.Feeder2_B   = __sqrtf(P.Feeder2_B * P.Feeder2_B + Q_New.Feeder2_B * Q_New.Feeder2_B);
    S_New.Feeder2_C   = __sqrtf(P.Feeder2_C * P.Feeder2_C + Q_New.Feeder2_C * Q_New.Feeder2_C);
    S_New.Feeder2_TOT = __sqrtf(P.Feeder2_TOT * P.Feeder2_TOT + Q_New.Feeder2_TOT * Q_New.Feeder2_TOT);

    S_New.Feeder3_A   = __sqrtf(P.Feeder3_A * P.Feeder3_A + Q_New.Feeder3_A * Q_New.Feeder3_A);
    S_New.Feeder3_B   = __sqrtf(P.Feeder3_B * P.Feeder3_B + Q_New.Feeder3_B * Q_New.Feeder3_B);
    S_New.Feeder3_C   = __sqrtf(P.Feeder3_C * P.Feeder3_C + Q_New.Feeder3_C * Q_New.Feeder3_C);
    S_New.Feeder3_TOT = __sqrtf(P.Feeder3_TOT * P.Feeder3_TOT + Q_New.Feeder3_TOT * Q_New.Feeder3_TOT);

    S_New.Feeder4_A   = __sqrtf(P.Feeder4_A * P.Feeder4_A + Q_New.Feeder4_A * Q_New.Feeder4_A);
    S_New.Feeder4_B   = __sqrtf(P.Feeder4_B * P.Feeder4_B + Q_New.Feeder4_B * Q_New.Feeder4_B);
    S_New.Feeder4_C   = __sqrtf(P.Feeder4_C * P.Feeder4_C + Q_New.Feeder4_C * Q_New.Feeder4_C);
    S_New.Feeder4_TOT = __sqrtf(P.Feeder4_TOT * P.Feeder4_TOT + Q_New.Feeder4_TOT * Q_New.Feeder4_TOT);

    S_New.Feeder5_A   = __sqrtf(P.Feeder5_A * P.Feeder5_A + Q_New.Feeder5_A * Q_New.Feeder5_A);
    S_New.Feeder5_B   = __sqrtf(P.Feeder5_B * P.Feeder5_B + Q_New.Feeder5_B * Q_New.Feeder5_B);
    S_New.Feeder5_C   = __sqrtf(P.Feeder5_C * P.Feeder5_C + Q_New.Feeder5_C * Q_New.Feeder5_C);
    S_New.Feeder5_TOT = __sqrtf(P.Feeder5_TOT * P.Feeder5_TOT + Q_New.Feeder5_TOT * Q_New.Feeder5_TOT);
}

void pmu_PF_Calculation(void)
{
    PF.Feeder1_TOT  =  fabsf(P.Feeder1_TOT / S.Feeder1_TOT);
    PF.Feeder1_TOT  =  fabsf(P.Feeder1_TOT / S.Feeder1_TOT);
    PF.Feeder2_TOT  =  fabsf(P.Feeder2_TOT / S.Feeder2_TOT);
    PF.Feeder3_TOT  =  fabsf(P.Feeder3_TOT / S.Feeder3_TOT);
    PF.Feeder4_TOT  =  fabsf(P.Feeder4_TOT / S.Feeder4_TOT);
    PF.Feeder5_TOT  =  fabsf(P.Feeder5_TOT / S.Feeder5_TOT);
}

void pmu_PF_Calculation_New(void)
{
    PF_New.Feeder1_A   = fabsf(P.Feeder1_A / S_New.Feeder1_A);
    PF_New.Feeder1_B   = fabsf(P.Feeder1_B / S_New.Feeder1_B);
    PF_New.Feeder1_C   = fabsf(P.Feeder1_C / S_New.Feeder1_C);
    PF_New.Feeder1_TOT = fabsf(P.Feeder1_TOT / S_New.Feeder1_TOT);

    PF_New.Feeder2_A = fabsf(P.Feeder2_A / S_New.Feeder2_A);
    PF_New.Feeder2_B = fabsf(P.Feeder2_B / S_New.Feeder2_B);
    PF_New.Feeder2_C = fabsf(P.Feeder2_C / S_New.Feeder2_C);
    PF_New.Feeder2_TOT = fabsf(P.Feeder2_TOT / S_New.Feeder2_TOT);

    PF_New.Feeder3_A = fabsf(P.Feeder3_A / S_New.Feeder3_A);
    PF_New.Feeder3_B = fabsf(P.Feeder3_B / S_New.Feeder3_B);
    PF_New.Feeder3_C = fabsf(P.Feeder3_C / S_New.Feeder3_C);
    PF_New.Feeder3_TOT = fabsf(P.Feeder3_TOT / S_New.Feeder3_TOT);

    PF_New.Feeder4_A = fabsf(P.Feeder4_A / S_New.Feeder4_A);
    PF_New.Feeder4_B = fabsf(P.Feeder4_B / S_New.Feeder4_B);
    PF_New.Feeder4_C = fabsf(P.Feeder4_C / S_New.Feeder4_C);
    PF_New.Feeder4_TOT = fabsf(P.Feeder4_TOT / S_New.Feeder4_TOT);

    PF_New.Feeder5_A = fabsf(P.Feeder1_A / S_New.Feeder1_A);
    PF_New.Feeder5_B = fabsf(P.Feeder1_B / S_New.Feeder1_B);
    PF_New.Feeder5_C = fabsf(P.Feeder1_C / S_New.Feeder1_C);
    PF_New.Feeder5_TOT = fabsf(P.Feeder5_TOT / S_New.Feeder5_TOT);
}

void pmu_Energy_Calculation_New(void)
{
  /********************* CH1 Energy Calculation *******************************/
  if (P.Feeder1_A > 0 && Q_New.Feeder1_A > 0) // I
  {
      Energy.Active.Feeder1_A_Import   += P.Feeder1_A     * ENERGY_CONSTANT;
      Energy.Reactive.Feeder1_A_Import += Q_New.Feeder1_A * ENERGY_CONSTANT;
  }

  if (P.Feeder1_A < 0 && Q_New.Feeder1_A > 0) // II
  {
      Energy.Active.Feeder1_A_Export   += P.Feeder1_A     * ENERGY_CONSTANT;
      Energy.Reactive.Feeder1_A_Import += Q_New.Feeder1_A * ENERGY_CONSTANT;
  }

  if (P.Feeder1_A < 0 && Q_New.Feeder1_A < 0) // III
  {
      Energy.Active.Feeder1_A_Export   += P.Feeder1_A     * ENERGY_CONSTANT;
      Energy.Reactive.Feeder1_A_Export += Q_New.Feeder1_A * ENERGY_CONSTANT;
  }

  if (P.Feeder1_A > 0 && Q_New.Feeder1_A < 0) // IV
  {
      Energy.Active.Feeder1_A_Import   += P.Feeder1_A     * ENERGY_CONSTANT;
      Energy.Reactive.Feeder1_A_Export += Q_New.Feeder1_A * ENERGY_CONSTANT;
  }
 /*****************************************************************************/

 /******************* Energy Time Pulse Section Feeder1 ***********************/
 if (Energy.Active.Feeder1_A_Import > 1)      // Her 0.01kWh ta bir artiriyoruz.
 {
     Energy_Total.Active.Feeder1_A_Import += (uint32_t)(Energy.Active.Feeder1_A_Import);
     Energy.Active.Feeder1_A_Import = Energy.Active.Feeder1_A_Import -
                                           (uint32_t)(Energy.Active.Feeder1_A_Import);
 }

 if (fabsf(Energy.Active.Feeder1_A_Export) > 1)
 {
     Energy_Total.Active.Feeder1_A_Export += (uint32_t)(fabsf(Energy.Active.Feeder1_A_Export));
     Energy.Active.Feeder1_A_Export = Energy.Active.Feeder1_A_Export -
                                           (int32_t)(Energy.Active.Feeder1_A_Export);
 }

 if (Energy.Reactive.Feeder1_A_Import > 1)
 {
     Energy_Total.Reactive.Feeder1_A_Import += (uint32_t)(Energy.Reactive.Feeder1_A_Import);
     Energy.Reactive.Feeder1_A_Import = Energy.Reactive.Feeder1_A_Import -
                                            (uint32_t)(Energy.Reactive.Feeder1_A_Import);
 }

 if (fabsf(Energy.Reactive.Feeder1_A_Export) > 1)
 {
     Energy_Total.Reactive.Feeder1_A_Export += (uint32_t)(fabsf(Energy.Reactive.Feeder1_A_Export));
     Energy.Reactive.Feeder1_A_Export = Energy.Reactive.Feeder1_A_Export -
                                             (int32_t)(Energy.Reactive.Feeder1_A_Export);
 }
 /*****************************************************************************/

 /********************* CH2 Energy Calculation *******************************/
 if (P.Feeder1_B > 0 && Q_New.Feeder1_B > 0) // I
 {
     Energy.Active.Feeder1_B_Import   += P.Feeder1_B     * ENERGY_CONSTANT;
     Energy.Reactive.Feeder1_B_Import += Q_New.Feeder1_B * ENERGY_CONSTANT;
 }

 if (P.Feeder1_B < 0 && Q_New.Feeder1_B > 0) // II
 {
     Energy.Active.Feeder1_B_Export   += P.Feeder1_B     * ENERGY_CONSTANT;
     Energy.Reactive.Feeder1_B_Import += Q_New.Feeder1_B * ENERGY_CONSTANT;
 }

 if (P.Feeder1_B < 0 && Q_New.Feeder1_B < 0) // III
 {
     Energy.Active.Feeder1_B_Export   += P.Feeder1_B     * ENERGY_CONSTANT;
     Energy.Reactive.Feeder1_B_Export += Q_New.Feeder1_B * ENERGY_CONSTANT;
 }

 if (P.Feeder1_B > 0 && Q_New.Feeder1_B < 0) // IV
 {
     Energy.Active.Feeder1_B_Import   += P.Feeder1_B     * ENERGY_CONSTANT;
     Energy.Reactive.Feeder1_B_Export += Q_New.Feeder1_B * ENERGY_CONSTANT;
 }
/*****************************************************************************/

/******************* Energy Time Pulse Section Feeder1 ***********************/
if (Energy.Active.Feeder1_B_Import > 1)       // Her 0.01kWh ta bir artiriyoruz.
{
    Energy_Total.Active.Feeder1_B_Import += (uint32_t)(Energy.Active.Feeder1_B_Import);
    Energy.Active.Feeder1_B_Import = Energy.Active.Feeder1_B_Import -
                                          (uint32_t)(Energy.Active.Feeder1_B_Import);
}

if (fabsf(Energy.Active.Feeder1_B_Export) > 1)
{
    Energy_Total.Active.Feeder1_B_Export += (uint32_t)(fabsf(Energy.Active.Feeder1_B_Export));
    Energy.Active.Feeder1_B_Export = Energy.Active.Feeder1_B_Export -
                                          (int32_t)(Energy.Active.Feeder1_B_Export);
}

if (Energy.Reactive.Feeder1_B_Import > 1)
{
    Energy_Total.Reactive.Feeder1_B_Import += (uint32_t)(Energy.Reactive.Feeder1_B_Import);
    Energy.Reactive.Feeder1_B_Import = Energy.Reactive.Feeder1_B_Import -
                                           (uint32_t)(Energy.Reactive.Feeder1_B_Import);
}

if (fabsf(Energy.Reactive.Feeder1_B_Export) > 1)
{
    Energy_Total.Reactive.Feeder1_B_Export += (uint32_t)(fabsf(Energy.Reactive.Feeder1_B_Export));
    Energy.Reactive.Feeder1_B_Export = Energy.Reactive.Feeder1_B_Export -
                                            (int32_t)(Energy.Reactive.Feeder1_B_Export);
}
/*****************************************************************************/

/********************* CH3 Energy Calculation *******************************/
if (P.Feeder1_C > 0 && Q_New.Feeder1_C > 0) // I
{
    Energy.Active.Feeder1_C_Import   += P.Feeder1_C     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder1_C_Import += Q_New.Feeder1_C * ENERGY_CONSTANT;
}

if (P.Feeder1_C < 0 && Q_New.Feeder1_C > 0) // II
{
    Energy.Active.Feeder1_C_Export   += P.Feeder1_C     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder1_C_Import += Q_New.Feeder1_C * ENERGY_CONSTANT;
}

if (P.Feeder1_C < 0 && Q_New.Feeder1_C < 0) // III
{
    Energy.Active.Feeder1_C_Export   += P.Feeder1_C     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder1_C_Export += Q_New.Feeder1_C * ENERGY_CONSTANT;
}

if (P.Feeder1_C > 0 && Q_New.Feeder1_C < 0) // IV
{
    Energy.Active.Feeder1_C_Import   += P.Feeder1_C     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder1_C_Export += Q_New.Feeder1_C * ENERGY_CONSTANT;
}
/*****************************************************************************/

/************************ Energy Time Pulse Section CH3 ***********************/
if (Energy.Active.Feeder1_C_Import > 1)       // Her 0.01kWh ta bir artiriyoruz.
{
   Energy_Total.Active.Feeder1_C_Import += (uint32_t)(Energy.Active.Feeder1_C_Import);
   Energy.Active.Feeder1_C_Import = Energy.Active.Feeder1_C_Import -
                                         (uint32_t)(Energy.Active.Feeder1_C_Import);
}

if (fabsf(Energy.Active.Feeder1_C_Export) > 1)
{
   Energy_Total.Active.Feeder1_C_Export += (uint32_t)(fabsf(Energy.Active.Feeder1_C_Export));
   Energy.Active.Feeder1_C_Export = Energy.Active.Feeder1_C_Export -
                                         (int32_t)(Energy.Active.Feeder1_C_Export);
}

if (Energy.Reactive.Feeder1_C_Import > 1)
{
   Energy_Total.Reactive.Feeder1_C_Import += (uint32_t)(Energy.Reactive.Feeder1_C_Import);
   Energy.Reactive.Feeder1_C_Import = Energy.Reactive.Feeder1_C_Import -
                                          (uint32_t)(Energy.Reactive.Feeder1_C_Import);
}

if (fabsf(Energy.Reactive.Feeder1_C_Export) > 1)
{
   Energy_Total.Reactive.Feeder1_C_Export += (uint32_t)(fabsf(Energy.Reactive.Feeder1_C_Export));
   Energy.Reactive.Feeder1_C_Export = Energy.Reactive.Feeder1_C_Export -
                                           (int32_t)(Energy.Reactive.Feeder1_C_Export);
}
/*****************************************************************************/

/********************* CH4 Energy Calculation *******************************/
if (P.Feeder2_A > 0 && Q_New.Feeder2_A > 0) // I
{
    Energy.Active.Feeder2_A_Import   += P.Feeder2_A     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder2_A_Import += Q_New.Feeder2_A * ENERGY_CONSTANT;
}

if (P.Feeder2_A < 0 && Q_New.Feeder2_A > 0) // II
{
    Energy.Active.Feeder2_A_Export   += P.Feeder2_A     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder2_A_Import += Q_New.Feeder2_A * ENERGY_CONSTANT;
}

if (P.Feeder2_A < 0 && Q_New.Feeder2_A < 0) // III
{
    Energy.Active.Feeder2_A_Export   += P.Feeder2_A     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder2_A_Export += Q_New.Feeder2_A * ENERGY_CONSTANT;
}

if (P.Feeder2_A > 0 && Q_New.Feeder2_A < 0) // IV
{
    Energy.Active.Feeder2_A_Import   += P.Feeder2_A     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder2_A_Export += Q_New.Feeder2_A * ENERGY_CONSTANT;
}
/*****************************************************************************/

/************************ Energy Time Pulse Section CH4 ***********************/
if (Energy.Active.Feeder2_A_Import > 1)       // Her 0.01kWh ta bir artiriyoruz.
{
   Energy_Total.Active.Feeder2_A_Import += (uint32_t)(Energy.Active.Feeder2_A_Import);
   Energy.Active.Feeder2_A_Import = Energy.Active.Feeder2_A_Import -
                                         (uint32_t)(Energy.Active.Feeder2_A_Import);
}

if (fabsf(Energy.Active.Feeder2_A_Export) > 1)
{
   Energy_Total.Active.Feeder2_A_Export += (uint32_t)(fabsf(Energy.Active.Feeder2_A_Export));
   Energy.Active.Feeder2_A_Export = Energy.Active.Feeder2_A_Export -
                                         (int32_t)(Energy.Active.Feeder2_A_Export);
}

if (Energy.Reactive.Feeder2_A_Import > 1)
{
   Energy_Total.Reactive.Feeder2_A_Import += (uint32_t)(Energy.Reactive.Feeder2_A_Import);
   Energy.Reactive.Feeder2_A_Import = Energy.Reactive.Feeder2_A_Import -
                                          (uint32_t)(Energy.Reactive.Feeder2_A_Import);
}

if (fabsf(Energy.Reactive.Feeder2_A_Export) > 1)
{
   Energy_Total.Reactive.Feeder2_A_Export += (uint32_t)(fabsf(Energy.Reactive.Feeder2_A_Export));
   Energy.Reactive.Feeder2_A_Export = Energy.Reactive.Feeder2_A_Export -
                                           (int32_t)(Energy.Reactive.Feeder2_A_Export);
}
/*****************************************************************************/

/********************* CH5 Energy Calculation *******************************/
if (P.Feeder2_B > 0 && Q_New.Feeder2_B > 0) // I
{
    Energy.Active.Feeder2_B_Import   += P.Feeder2_B     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder2_B_Import += Q_New.Feeder2_B * ENERGY_CONSTANT;
}

if (P.Feeder2_B < 0 && Q_New.Feeder2_B > 0) // II
{
    Energy.Active.Feeder2_B_Export   += P.Feeder2_B     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder2_B_Import += Q_New.Feeder2_B * ENERGY_CONSTANT;
}

if (P.Feeder2_B < 0 && Q_New.Feeder2_B < 0) // III
{
    Energy.Active.Feeder2_B_Export   += P.Feeder2_B     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder2_B_Export += Q_New.Feeder2_B * ENERGY_CONSTANT;
}

if (P.Feeder2_B > 0 && Q_New.Feeder2_B < 0) // IV
{
    Energy.Active.Feeder2_B_Import   += P.Feeder2_B     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder2_B_Export += Q_New.Feeder2_B * ENERGY_CONSTANT;
}
/*****************************************************************************/

/************************ Energy Time Pulse Section CH5 ***********************/
if (Energy.Active.Feeder2_B_Import > 1)       // Her 0.01kWh ta bir artiriyoruz.
{
   Energy_Total.Active.Feeder2_B_Import += (uint32_t)(Energy.Active.Feeder2_B_Import);
   Energy.Active.Feeder2_B_Import = Energy.Active.Feeder2_B_Import -
                                         (uint32_t)(Energy.Active.Feeder2_B_Import);
}

if (fabsf(Energy.Active.Feeder2_B_Export) > 1)
{
   Energy_Total.Active.Feeder2_B_Export += (uint32_t)(fabsf(Energy.Active.Feeder2_B_Export));
   Energy.Active.Feeder2_B_Export = Energy.Active.Feeder2_B_Export -
                                         (int32_t)(Energy.Active.Feeder2_B_Export);
}

if (Energy.Reactive.Feeder2_B_Import > 1)
{
   Energy_Total.Reactive.Feeder2_B_Import += (uint32_t)(Energy.Reactive.Feeder2_B_Import);
   Energy.Reactive.Feeder2_B_Import = Energy.Reactive.Feeder2_B_Import -
                                          (uint32_t)(Energy.Reactive.Feeder2_B_Import);
}

if (fabsf(Energy.Reactive.Feeder2_B_Export) > 1)
{
   Energy_Total.Reactive.Feeder2_B_Export += (uint32_t)(fabsf(Energy.Reactive.Feeder2_B_Export));
   Energy.Reactive.Feeder2_B_Export = Energy.Reactive.Feeder2_B_Export -
                                           (int32_t)(Energy.Reactive.Feeder2_B_Export);
}
/*****************************************************************************/

/********************* CH6 Energy Calculation *******************************/
if (P.Feeder2_C > 0 && Q_New.Feeder2_C > 0) // I
{
    Energy.Active.Feeder2_C_Import   += P.Feeder2_C     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder2_C_Import += Q_New.Feeder2_C * ENERGY_CONSTANT;
}

if (P.Feeder2_C < 0 && Q_New.Feeder2_C > 0) // II
{
    Energy.Active.Feeder2_C_Export   += P.Feeder2_C     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder2_C_Import += Q_New.Feeder2_C * ENERGY_CONSTANT;
}

if (P.Feeder2_C < 0 && Q_New.Feeder2_C < 0) // III
{
    Energy.Active.Feeder2_C_Export   += P.Feeder2_C     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder2_C_Export += Q_New.Feeder2_C * ENERGY_CONSTANT;
}

if (P.Feeder2_C > 0 && Q_New.Feeder2_C < 0) // IV
{
    Energy.Active.Feeder2_C_Import   += P.Feeder2_C     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder2_C_Export += Q_New.Feeder2_C * ENERGY_CONSTANT;
}
/*****************************************************************************/

/************************ Energy Time Pulse Section CH6 ***********************/
if (Energy.Active.Feeder2_C_Import > 1)       // Her 0.01kWh ta bir artiriyoruz.
{
   Energy_Total.Active.Feeder2_C_Import += (uint32_t)(Energy.Active.Feeder2_C_Import);
   Energy.Active.Feeder2_C_Import = Energy.Active.Feeder2_C_Import -
                                         (uint32_t)(Energy.Active.Feeder2_C_Import);
}

if (fabsf(Energy.Active.Feeder2_C_Export) > 1)
{
   Energy_Total.Active.Feeder2_C_Export += (uint32_t)(fabsf(Energy.Active.Feeder2_C_Export));
   Energy.Active.Feeder2_C_Export = Energy.Active.Feeder2_C_Export -
                                         (int32_t)(Energy.Active.Feeder2_C_Export);
}

if (Energy.Reactive.Feeder2_C_Import > 1)
{
   Energy_Total.Reactive.Feeder2_C_Import += (uint32_t)(Energy.Reactive.Feeder2_C_Import);
   Energy.Reactive.Feeder2_C_Import = Energy.Reactive.Feeder2_C_Import -
                                          (uint32_t)(Energy.Reactive.Feeder2_C_Import);
}

if (fabsf(Energy.Reactive.Feeder2_C_Export) > 1)
{
   Energy_Total.Reactive.Feeder2_C_Export += (uint32_t)(fabsf(Energy.Reactive.Feeder2_C_Export));
   Energy.Reactive.Feeder2_C_Export = Energy.Reactive.Feeder2_C_Export -
                                           (int32_t)(Energy.Reactive.Feeder2_C_Export);
}
/*****************************************************************************/

/********************* CH7 Energy Calculation *******************************/
if (P.Feeder3_A > 0 && Q_New.Feeder3_A > 0) // I
{
    Energy.Active.Feeder3_A_Import   += P.Feeder3_A     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder3_A_Import += Q_New.Feeder3_A * ENERGY_CONSTANT;
}

if (P.Feeder3_A < 0 && Q_New.Feeder3_A > 0) // II
{
    Energy.Active.Feeder3_A_Export   += P.Feeder3_A     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder3_A_Import += Q_New.Feeder3_A * ENERGY_CONSTANT;
}

if (P.Feeder3_A < 0 && Q_New.Feeder3_A < 0) // III
{
    Energy.Active.Feeder3_A_Export   += P.Feeder3_A     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder3_A_Export += Q_New.Feeder3_A * ENERGY_CONSTANT;
}

if (P.Feeder3_A > 0 && Q_New.Feeder3_A < 0) // IV
{
    Energy.Active.Feeder3_A_Import   += P.Feeder3_A     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder3_A_Export += Q_New.Feeder3_A * ENERGY_CONSTANT;
}
/*****************************************************************************/

/************************ Energy Time Pulse Section CH7 ***********************/
if (Energy.Active.Feeder3_A_Import > 1)       // Her 0.01kWh ta bir artiriyoruz.
{
   Energy_Total.Active.Feeder3_A_Import += (uint32_t)(Energy.Active.Feeder3_A_Import);
   Energy.Active.Feeder3_A_Import = Energy.Active.Feeder3_A_Import -
                                         (uint32_t)(Energy.Active.Feeder3_A_Import);
}

if (fabsf(Energy.Active.Feeder3_A_Export) > 1)
{
   Energy_Total.Active.Feeder3_A_Export += (uint32_t)(fabsf(Energy.Active.Feeder3_A_Export));
   Energy.Active.Feeder3_A_Export = Energy.Active.Feeder3_A_Export -
                                         (int32_t)(Energy.Active.Feeder3_A_Export);
}

if (Energy.Reactive.Feeder3_A_Import > 1)
{
   Energy_Total.Reactive.Feeder3_A_Import += (uint32_t)(Energy.Reactive.Feeder3_A_Import);
   Energy.Reactive.Feeder3_A_Import = Energy.Reactive.Feeder3_A_Import -
                                          (uint32_t)(Energy.Reactive.Feeder3_A_Import);
}

if (fabsf(Energy.Reactive.Feeder3_A_Export) > 1)
{
   Energy_Total.Reactive.Feeder3_A_Export += (uint32_t)(fabsf(Energy.Reactive.Feeder3_A_Export));
   Energy.Reactive.Feeder3_A_Export = Energy.Reactive.Feeder3_A_Export -
                                           (int32_t)(Energy.Reactive.Feeder3_A_Export);
}
/*****************************************************************************/

/********************* CH8 Energy Calculation *******************************/
if (P.Feeder3_B > 0 && Q_New.Feeder3_B > 0) // I
{
    Energy.Active.Feeder3_B_Import   += P.Feeder3_B     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder3_B_Import += Q_New.Feeder3_B * ENERGY_CONSTANT;
}

if (P.Feeder3_B < 0 && Q_New.Feeder3_B > 0) // II
{
    Energy.Active.Feeder3_B_Export   += P.Feeder3_B     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder3_B_Import += Q_New.Feeder3_B * ENERGY_CONSTANT;
}

if (P.Feeder3_B < 0 && Q_New.Feeder3_B < 0) // III
{
    Energy.Active.Feeder3_B_Export   += P.Feeder3_B     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder3_B_Export += Q_New.Feeder3_B * ENERGY_CONSTANT;
}

if (P.Feeder3_B > 0 && Q_New.Feeder3_B < 0) // IV
{
    Energy.Active.Feeder3_B_Import   += P.Feeder3_B     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder3_B_Export += Q_New.Feeder3_B * ENERGY_CONSTANT;
}
/*****************************************************************************/

/************************ Energy Time Pulse Section CH8 ***********************/
if (Energy.Active.Feeder3_B_Import > 1)       // Her 0.01kWh ta bir artiriyoruz.
{
   Energy_Total.Active.Feeder3_B_Import += (uint32_t)(Energy.Active.Feeder3_B_Import);
   Energy.Active.Feeder3_B_Import = Energy.Active.Feeder3_B_Import -
                                         (uint32_t)(Energy.Active.Feeder3_B_Import);
}

if (fabsf(Energy.Active.Feeder3_B_Export) > 1)
{
   Energy_Total.Active.Feeder3_B_Export += (uint32_t)(fabsf(Energy.Active.Feeder3_B_Export));
   Energy.Active.Feeder3_B_Export = Energy.Active.Feeder3_B_Export -
                                         (int32_t)(Energy.Active.Feeder3_B_Export);
}

if (Energy.Reactive.Feeder3_B_Import > 1)
{
   Energy_Total.Reactive.Feeder3_B_Import += (uint32_t)(Energy.Reactive.Feeder3_B_Import);
   Energy.Reactive.Feeder3_B_Import = Energy.Reactive.Feeder3_B_Import -
                                          (uint32_t)(Energy.Reactive.Feeder3_B_Import);
}

if (fabsf(Energy.Reactive.Feeder3_B_Export) > 1)
{
   Energy_Total.Reactive.Feeder3_B_Export += (uint32_t)(fabsf(Energy.Reactive.Feeder3_B_Export));
   Energy.Reactive.Feeder3_B_Export = Energy.Reactive.Feeder3_B_Export -
                                           (int32_t)(Energy.Reactive.Feeder3_B_Export);
}
/*****************************************************************************/

/********************* CH9 Energy Calculation *******************************/
if (P.Feeder3_C > 0 && Q_New.Feeder3_C > 0) // I
{
    Energy.Active.Feeder3_C_Import   += P.Feeder3_C     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder3_C_Import += Q_New.Feeder3_C * ENERGY_CONSTANT;
}

if (P.Feeder3_C < 0 && Q_New.Feeder3_C > 0) // II
{
    Energy.Active.Feeder3_C_Export   += P.Feeder3_C     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder3_C_Import += Q_New.Feeder3_C * ENERGY_CONSTANT;
}

if (P.Feeder3_C < 0 && Q_New.Feeder3_C < 0) // III
{
    Energy.Active.Feeder3_C_Export   += P.Feeder3_C     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder3_C_Export += Q_New.Feeder3_C * ENERGY_CONSTANT;
}

if (P.Feeder3_C > 0 && Q_New.Feeder3_C < 0) // IV
{
    Energy.Active.Feeder3_C_Import   += P.Feeder3_C     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder3_C_Export += Q_New.Feeder3_C * ENERGY_CONSTANT;
}
/*****************************************************************************/

/************************ Energy Time Pulse Section CH9 ***********************/
if (Energy.Active.Feeder3_C_Import > 1)       // Her 0.01kWh ta bir artiriyoruz.
{
   Energy_Total.Active.Feeder3_C_Import += (uint32_t)(Energy.Active.Feeder3_C_Import);
   Energy.Active.Feeder3_C_Import = Energy.Active.Feeder3_C_Import -
                                         (uint32_t)(Energy.Active.Feeder3_C_Import);
}

if (fabsf(Energy.Active.Feeder3_C_Export) > 1)
{
   Energy_Total.Active.Feeder3_C_Export += (uint32_t)(fabsf(Energy.Active.Feeder3_C_Export));
   Energy.Active.Feeder3_C_Export = Energy.Active.Feeder3_C_Export -
                                         (int32_t)(Energy.Active.Feeder3_C_Export);
}

if (Energy.Reactive.Feeder3_C_Import > 1)
{
   Energy_Total.Reactive.Feeder3_C_Import += (uint32_t)(Energy.Reactive.Feeder3_C_Import);
   Energy.Reactive.Feeder3_C_Import = Energy.Reactive.Feeder3_C_Import -
                                          (uint32_t)(Energy.Reactive.Feeder3_C_Import);
}

if (fabsf(Energy.Reactive.Feeder3_C_Export) > 1)
{
   Energy_Total.Reactive.Feeder3_C_Export += (uint32_t)(fabsf(Energy.Reactive.Feeder3_C_Export));
   Energy.Reactive.Feeder3_C_Export = Energy.Reactive.Feeder3_C_Export -
                                           (int32_t)(Energy.Reactive.Feeder3_C_Export);
}
/*****************************************************************************/

/********************* CH10 Energy Calculation *******************************/
if (P.Feeder4_A > 0 && Q_New.Feeder4_A > 0) // I
{
    Energy.Active.Feeder4_A_Import   += P.Feeder4_A     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder4_A_Import += Q_New.Feeder4_A * ENERGY_CONSTANT;
}

if (P.Feeder4_A < 0 && Q_New.Feeder4_A > 0) // II
{
    Energy.Active.Feeder4_A_Export   += P.Feeder4_A     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder4_A_Import += Q_New.Feeder4_A * ENERGY_CONSTANT;
}

if (P.Feeder4_A < 0 && Q_New.Feeder4_A < 0) // III
{
    Energy.Active.Feeder4_A_Export   += P.Feeder4_A     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder4_A_Export += Q_New.Feeder4_A * ENERGY_CONSTANT;
}

if (P.Feeder4_A > 0 && Q_New.Feeder4_A < 0) // IV
{
    Energy.Active.Feeder4_A_Import   += P.Feeder4_A     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder4_A_Export += Q_New.Feeder4_A * ENERGY_CONSTANT;
}
/*****************************************************************************/

/************************ Energy Time Pulse Section CH10 ***********************/
if (Energy.Active.Feeder4_A_Import > 1)       // Her 0.01kWh ta bir artiriyoruz.
{
   Energy_Total.Active.Feeder4_A_Import += (uint32_t)(Energy.Active.Feeder4_A_Import);
   Energy.Active.Feeder4_A_Import = Energy.Active.Feeder4_A_Import -
                                         (uint32_t)(Energy.Active.Feeder4_A_Import);
}

if (fabsf(Energy.Active.Feeder4_A_Export) > 1)
{
   Energy_Total.Active.Feeder4_A_Export += (uint32_t)(fabsf(Energy.Active.Feeder4_A_Export));
   Energy.Active.Feeder4_A_Export = Energy.Active.Feeder4_A_Export -
                                         (int32_t)(Energy.Active.Feeder4_A_Export);
}

if (Energy.Reactive.Feeder4_A_Import > 1)
{
   Energy_Total.Reactive.Feeder4_A_Import += (uint32_t)(Energy.Reactive.Feeder4_A_Import);
   Energy.Reactive.Feeder4_A_Import = Energy.Reactive.Feeder4_A_Import -
                                          (uint32_t)(Energy.Reactive.Feeder4_A_Import);
}

if (fabsf(Energy.Reactive.Feeder4_A_Export) > 1)
{
   Energy_Total.Reactive.Feeder4_A_Export += (uint32_t)(fabsf(Energy.Reactive.Feeder4_A_Export));
   Energy.Reactive.Feeder4_A_Export = Energy.Reactive.Feeder4_A_Export -
                                           (int32_t)(Energy.Reactive.Feeder4_A_Export);
}
/*****************************************************************************/

/********************* CH11 Energy Calculation *******************************/
if (P.Feeder4_B > 0 && Q_New.Feeder4_B > 0) // I
{
    Energy.Active.Feeder4_B_Import   += P.Feeder4_B     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder4_B_Import += Q_New.Feeder4_B * ENERGY_CONSTANT;
}

if (P.Feeder4_B < 0 && Q_New.Feeder4_B > 0) // II
{
    Energy.Active.Feeder4_B_Export   += P.Feeder4_B     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder4_B_Import += Q_New.Feeder4_B * ENERGY_CONSTANT;
}

if (P.Feeder4_B < 0 && Q_New.Feeder4_B < 0) // III
{
    Energy.Active.Feeder4_B_Export   += P.Feeder4_B     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder4_B_Export += Q_New.Feeder4_B * ENERGY_CONSTANT;
}

if (P.Feeder4_B > 0 && Q_New.Feeder4_B < 0) // IV
{
    Energy.Active.Feeder4_B_Import   += P.Feeder4_B     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder4_B_Export += Q_New.Feeder4_B * ENERGY_CONSTANT;
}
/*****************************************************************************/

/************************ Energy Time Pulse Section CH11 ***********************/
if (Energy.Active.Feeder4_B_Import > 1)       // Her 0.01kWh ta bir artiriyoruz.
{
   Energy_Total.Active.Feeder4_B_Import += (uint32_t)(Energy.Active.Feeder4_B_Import);
   Energy.Active.Feeder4_B_Import = Energy.Active.Feeder4_B_Import -
                                         (uint32_t)(Energy.Active.Feeder4_B_Import);
}

if (fabsf(Energy.Active.Feeder4_B_Export) > 1)
{
   Energy_Total.Active.Feeder4_B_Export += (uint32_t)(fabsf(Energy.Active.Feeder4_B_Export));
   Energy.Active.Feeder4_B_Export = Energy.Active.Feeder4_B_Export -
                                         (int32_t)(Energy.Active.Feeder4_B_Export);
}

if (Energy.Reactive.Feeder4_B_Import > 1)
{
   Energy_Total.Reactive.Feeder4_B_Import += (uint32_t)(Energy.Reactive.Feeder4_B_Import);
   Energy.Reactive.Feeder4_B_Import = Energy.Reactive.Feeder4_B_Import -
                                          (uint32_t)(Energy.Reactive.Feeder4_B_Import);
}

if (fabsf(Energy.Reactive.Feeder4_B_Export) > 1)
{
   Energy_Total.Reactive.Feeder4_B_Export += (uint32_t)(fabsf(Energy.Reactive.Feeder4_B_Export));
   Energy.Reactive.Feeder4_B_Export = Energy.Reactive.Feeder4_B_Export -
                                           (int32_t)(Energy.Reactive.Feeder4_B_Export);
}
/*****************************************************************************/

/********************* CH12 Energy Calculation *******************************/
if (P.Feeder4_C > 0 && Q_New.Feeder4_C > 0) // I
{
    Energy.Active.Feeder4_C_Import   += P.Feeder4_C     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder4_C_Import += Q_New.Feeder4_C * ENERGY_CONSTANT;
}

if (P.Feeder4_C < 0 && Q_New.Feeder4_C > 0) // II
{
    Energy.Active.Feeder4_C_Export   += P.Feeder4_C     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder4_C_Import += Q_New.Feeder4_C * ENERGY_CONSTANT;
}

if (P.Feeder4_C < 0 && Q_New.Feeder4_C < 0) // III
{
    Energy.Active.Feeder4_C_Export   += P.Feeder4_C     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder4_C_Export += Q_New.Feeder4_C * ENERGY_CONSTANT;
}

if (P.Feeder4_C > 0 && Q_New.Feeder4_C < 0) // IV
{
    Energy.Active.Feeder4_C_Import   += P.Feeder4_C     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder4_C_Export += Q_New.Feeder4_C * ENERGY_CONSTANT;
}
/*****************************************************************************/

/************************ Energy Time Pulse Section CH12 ***********************/
if (Energy.Active.Feeder4_C_Import > 1)       // Her 0.01kWh ta bir artiriyoruz.
{
   Energy_Total.Active.Feeder4_C_Import += (uint32_t)(Energy.Active.Feeder4_C_Import);
   Energy.Active.Feeder4_C_Import = Energy.Active.Feeder4_C_Import -
                                         (uint32_t)(Energy.Active.Feeder4_C_Import);
}

if (fabsf(Energy.Active.Feeder4_C_Export) > 1)
{
   Energy_Total.Active.Feeder4_C_Export += (uint32_t)(fabsf(Energy.Active.Feeder4_C_Export));
   Energy.Active.Feeder4_C_Export = Energy.Active.Feeder4_C_Export -
                                         (int32_t)(Energy.Active.Feeder4_C_Export);
}

if (Energy.Reactive.Feeder4_C_Import > 1)
{
   Energy_Total.Reactive.Feeder4_C_Import += (uint32_t)(Energy.Reactive.Feeder4_C_Import);
   Energy.Reactive.Feeder4_C_Import = Energy.Reactive.Feeder4_C_Import -
                                          (uint32_t)(Energy.Reactive.Feeder4_C_Import);
}

if (fabsf(Energy.Reactive.Feeder4_C_Export) > 1)
{
   Energy_Total.Reactive.Feeder4_C_Export += (uint32_t)(fabsf(Energy.Reactive.Feeder4_C_Export));
   Energy.Reactive.Feeder4_C_Export = Energy.Reactive.Feeder4_C_Export -
                                           (int32_t)(Energy.Reactive.Feeder4_C_Export);
}
/*****************************************************************************/

/********************* CH13 Energy Calculation *******************************/
if (P.Feeder5_A > 0 && Q_New.Feeder5_A > 0) // I
{
    Energy.Active.Feeder5_A_Import   += P.Feeder5_A     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder5_A_Import += Q_New.Feeder5_A * ENERGY_CONSTANT;
}

if (P.Feeder5_A < 0 && Q_New.Feeder5_A > 0) // II
{
    Energy.Active.Feeder5_A_Export   += P.Feeder5_A     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder5_A_Import += Q_New.Feeder5_A * ENERGY_CONSTANT;
}

if (P.Feeder5_A < 0 && Q_New.Feeder5_A < 0) // III
{
    Energy.Active.Feeder5_A_Export   += P.Feeder5_A     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder5_A_Export += Q_New.Feeder5_A * ENERGY_CONSTANT;
}

if (P.Feeder5_A > 0 && Q_New.Feeder5_A < 0) // IV
{
    Energy.Active.Feeder5_A_Import   += P.Feeder5_A     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder5_A_Export += Q_New.Feeder5_A * ENERGY_CONSTANT;
}
/*****************************************************************************/

/************************ Energy Time Pulse Section CH13 ***********************/
if (Energy.Active.Feeder5_A_Import > 1)       // Her 0.01kWh ta bir artiriyoruz.
{
   Energy_Total.Active.Feeder5_A_Import += (uint32_t)(Energy.Active.Feeder5_A_Import);
   Energy.Active.Feeder5_A_Import = Energy.Active.Feeder5_A_Import -
                                         (uint32_t)(Energy.Active.Feeder5_A_Import);
}

if (fabsf(Energy.Active.Feeder5_A_Export) > 1)
{
   Energy_Total.Active.Feeder5_A_Export += (uint32_t)(fabsf(Energy.Active.Feeder5_A_Export));
   Energy.Active.Feeder5_A_Export = Energy.Active.Feeder5_A_Export -
                                         (int32_t)(Energy.Active.Feeder5_A_Export);
}

if (Energy.Reactive.Feeder5_A_Import > 1)
{
   Energy_Total.Reactive.Feeder5_A_Import += (uint32_t)(Energy.Reactive.Feeder5_A_Import);
   Energy.Reactive.Feeder5_A_Import = Energy.Reactive.Feeder5_A_Import -
                                          (uint32_t)(Energy.Reactive.Feeder5_A_Import);
}

if (fabsf(Energy.Reactive.Feeder5_A_Export) > 1)
{
   Energy_Total.Reactive.Feeder5_A_Export += (uint32_t)(fabsf(Energy.Reactive.Feeder5_A_Export));
   Energy.Reactive.Feeder5_A_Export = Energy.Reactive.Feeder5_A_Export -
                                           (int32_t)(Energy.Reactive.Feeder5_A_Export);
}
/*****************************************************************************/

/********************* CH14 Energy Calculation *******************************/
if (P.Feeder5_B > 0 && Q_New.Feeder5_B > 0) // I
{
    Energy.Active.Feeder5_B_Import   += P.Feeder5_B     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder5_B_Import += Q_New.Feeder5_B * ENERGY_CONSTANT;
}

if (P.Feeder5_B < 0 && Q_New.Feeder5_B > 0) // II
{
    Energy.Active.Feeder5_B_Export   += P.Feeder5_B     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder5_B_Import += Q_New.Feeder5_B * ENERGY_CONSTANT;
}

if (P.Feeder5_B < 0 && Q_New.Feeder5_B < 0) // III
{
    Energy.Active.Feeder5_B_Export   += P.Feeder5_B     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder5_B_Export += Q_New.Feeder5_B * ENERGY_CONSTANT;
}

if (P.Feeder5_B > 0 && Q_New.Feeder5_B < 0) // IV
{
    Energy.Active.Feeder5_B_Import   += P.Feeder5_B     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder5_B_Export += Q_New.Feeder5_B * ENERGY_CONSTANT;
}
/*****************************************************************************/

/************************ Energy Time Pulse Section CH14 ***********************/
if (Energy.Active.Feeder5_B_Import > 1)       // Her 0.01kWh ta bir artiriyoruz.
{
   Energy_Total.Active.Feeder5_B_Import += (uint32_t)(Energy.Active.Feeder5_B_Import);
   Energy.Active.Feeder5_B_Import = Energy.Active.Feeder5_B_Import -
                                         (uint32_t)(Energy.Active.Feeder5_B_Import);
}

if (fabsf(Energy.Active.Feeder5_B_Export) > 1)
{
   Energy_Total.Active.Feeder5_B_Export += (uint32_t)(fabsf(Energy.Active.Feeder5_B_Export));
   Energy.Active.Feeder5_B_Export = Energy.Active.Feeder5_B_Export -
                                         (int32_t)(Energy.Active.Feeder5_B_Export);
}

if (Energy.Reactive.Feeder5_B_Import > 1)
{
   Energy_Total.Reactive.Feeder5_B_Import += (uint32_t)(Energy.Reactive.Feeder5_B_Import);
   Energy.Reactive.Feeder5_B_Import = Energy.Reactive.Feeder5_B_Import -
                                          (uint32_t)(Energy.Reactive.Feeder5_B_Import);
}

if (fabsf(Energy.Reactive.Feeder5_B_Export) > 1)
{
   Energy_Total.Reactive.Feeder5_B_Export += (uint32_t)(fabsf(Energy.Reactive.Feeder5_B_Export));
   Energy.Reactive.Feeder5_B_Export = Energy.Reactive.Feeder5_B_Export -
                                           (int32_t)(Energy.Reactive.Feeder5_B_Export);
}
/*****************************************************************************/

/********************* CH15 Energy Calculation *******************************/
if (P.Feeder5_C > 0 && Q_New.Feeder5_C > 0) // I
{
    Energy.Active.Feeder5_C_Import   += P.Feeder5_C     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder5_C_Import += Q_New.Feeder5_C * ENERGY_CONSTANT;
}

if (P.Feeder5_C < 0 && Q_New.Feeder5_C > 0) // II
{
    Energy.Active.Feeder5_C_Export   += P.Feeder5_C     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder5_C_Import += Q_New.Feeder5_C * ENERGY_CONSTANT;
}

if (P.Feeder5_C < 0 && Q_New.Feeder5_C < 0) // III
{
    Energy.Active.Feeder5_C_Export   += P.Feeder5_C     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder5_C_Export += Q_New.Feeder5_C * ENERGY_CONSTANT;
}

if (P.Feeder5_C > 0 && Q_New.Feeder5_C < 0) // IV
{
    Energy.Active.Feeder5_C_Import   += P.Feeder5_C     * ENERGY_CONSTANT;
    Energy.Reactive.Feeder5_C_Export += Q_New.Feeder5_C * ENERGY_CONSTANT;
}
/*****************************************************************************/

/************************ Energy Time Pulse Section CH15 ***********************/
if (Energy.Active.Feeder5_C_Import > 1)       // Her 0.01kWh ta bir artiriyoruz.
{
   Energy_Total.Active.Feeder5_C_Import += (uint32_t)(Energy.Active.Feeder5_C_Import);
   Energy.Active.Feeder5_C_Import = Energy.Active.Feeder5_C_Import -
                                         (uint32_t)(Energy.Active.Feeder5_C_Import);
}

if (fabsf(Energy.Active.Feeder5_C_Export) > 1)
{
   Energy_Total.Active.Feeder5_C_Export += (uint32_t)(fabsf(Energy.Active.Feeder5_C_Export));
   Energy.Active.Feeder5_C_Export = Energy.Active.Feeder5_C_Export -
                                         (int32_t)(Energy.Active.Feeder5_C_Export);
}

if (Energy.Reactive.Feeder5_C_Import > 1)
{
   Energy_Total.Reactive.Feeder5_C_Import += (uint32_t)(Energy.Reactive.Feeder5_C_Import);
   Energy.Reactive.Feeder5_C_Import = Energy.Reactive.Feeder5_C_Import -
                                          (uint32_t)(Energy.Reactive.Feeder5_C_Import);
}

if (fabsf(Energy.Reactive.Feeder5_C_Export) > 1)
{
   Energy_Total.Reactive.Feeder5_C_Export += (uint32_t)(fabsf(Energy.Reactive.Feeder5_C_Export));
   Energy.Reactive.Feeder5_C_Export = Energy.Reactive.Feeder5_C_Export -
                                           (int32_t)(Energy.Reactive.Feeder5_C_Export);
}
/*****************************************************************************/

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

if (Energy_Total.Active.Feeder1_A_Import   > 4e9) { Energy_Total.Active.Feeder1_A_Import   = 0;}
if (Energy_Total.Active.Feeder1_A_Export   > 4e9) { Energy_Total.Active.Feeder1_A_Export   = 0;}
if (Energy_Total.Reactive.Feeder1_A_Import > 4e9) { Energy_Total.Reactive.Feeder1_A_Import = 0;}
if (Energy_Total.Reactive.Feeder1_A_Export > 4e9) { Energy_Total.Reactive.Feeder1_A_Export = 0;}

if (Energy_Total.Active.Feeder1_B_Import   > 4e9) { Energy_Total.Active.Feeder1_B_Import   = 0;}
if (Energy_Total.Active.Feeder1_B_Export   > 4e9) { Energy_Total.Active.Feeder1_B_Export   = 0;}
if (Energy_Total.Reactive.Feeder1_B_Import > 4e9) { Energy_Total.Reactive.Feeder1_B_Import = 0;}
if (Energy_Total.Reactive.Feeder1_B_Export > 4e9) { Energy_Total.Reactive.Feeder1_B_Export = 0;}

if (Energy_Total.Active.Feeder1_C_Import   > 4e9) { Energy_Total.Active.Feeder1_C_Import   = 0;}
if (Energy_Total.Active.Feeder1_C_Export   > 4e9) { Energy_Total.Active.Feeder1_C_Export   = 0;}
if (Energy_Total.Reactive.Feeder1_C_Import > 4e9) { Energy_Total.Reactive.Feeder1_C_Import = 0;}
if (Energy_Total.Reactive.Feeder1_C_Export > 4e9) { Energy_Total.Reactive.Feeder1_C_Export = 0;}

if (Energy_Total.Active.Feeder2_A_Import   > 4e9) { Energy_Total.Active.Feeder2_A_Import   = 0;}
if (Energy_Total.Active.Feeder2_A_Export   > 4e9) { Energy_Total.Active.Feeder2_A_Export   = 0;}
if (Energy_Total.Reactive.Feeder2_A_Import > 4e9) { Energy_Total.Reactive.Feeder2_A_Import = 0;}
if (Energy_Total.Reactive.Feeder2_A_Export > 4e9) { Energy_Total.Reactive.Feeder2_A_Export = 0;}

if (Energy_Total.Active.Feeder2_B_Import   > 4e9) { Energy_Total.Active.Feeder2_B_Import   = 0;}
if (Energy_Total.Active.Feeder2_B_Export   > 4e9) { Energy_Total.Active.Feeder2_B_Export   = 0;}
if (Energy_Total.Reactive.Feeder2_B_Import > 4e9) { Energy_Total.Reactive.Feeder2_B_Import = 0;}
if (Energy_Total.Reactive.Feeder2_B_Export > 4e9) { Energy_Total.Reactive.Feeder2_B_Export = 0;}

if (Energy_Total.Active.Feeder2_C_Import   > 4e9) { Energy_Total.Active.Feeder2_C_Import   = 0;}
if (Energy_Total.Active.Feeder2_C_Export   > 4e9) { Energy_Total.Active.Feeder2_C_Export   = 0;}
if (Energy_Total.Reactive.Feeder2_C_Import > 4e9) { Energy_Total.Reactive.Feeder2_C_Import = 0;}
if (Energy_Total.Reactive.Feeder2_C_Export > 4e9) { Energy_Total.Reactive.Feeder2_C_Export = 0;}

if (Energy_Total.Active.Feeder3_A_Import   > 4e9) { Energy_Total.Active.Feeder3_A_Import   = 0;}
if (Energy_Total.Active.Feeder3_A_Export   > 4e9) { Energy_Total.Active.Feeder3_A_Export   = 0;}
if (Energy_Total.Reactive.Feeder3_A_Import > 4e9) { Energy_Total.Reactive.Feeder3_A_Import = 0;}
if (Energy_Total.Reactive.Feeder3_A_Export > 4e9) { Energy_Total.Reactive.Feeder3_A_Export = 0;}

if (Energy_Total.Active.Feeder3_B_Import   > 4e9) { Energy_Total.Active.Feeder3_B_Import   = 0;}
if (Energy_Total.Active.Feeder3_B_Export   > 4e9) { Energy_Total.Active.Feeder3_B_Export   = 0;}
if (Energy_Total.Reactive.Feeder3_B_Import > 4e9) { Energy_Total.Reactive.Feeder3_B_Import = 0;}
if (Energy_Total.Reactive.Feeder3_B_Export > 4e9) { Energy_Total.Reactive.Feeder3_B_Export = 0;}

if (Energy_Total.Active.Feeder3_C_Import   > 4e9) { Energy_Total.Active.Feeder3_C_Import   = 0;}
if (Energy_Total.Active.Feeder3_C_Export   > 4e9) { Energy_Total.Active.Feeder3_C_Export   = 0;}
if (Energy_Total.Reactive.Feeder3_C_Import > 4e9) { Energy_Total.Reactive.Feeder3_C_Import = 0;}
if (Energy_Total.Reactive.Feeder3_C_Export > 4e9) { Energy_Total.Reactive.Feeder3_C_Export = 0;}

if (Energy_Total.Active.Feeder4_A_Import   > 4e9) { Energy_Total.Active.Feeder4_A_Import   = 0;}
if (Energy_Total.Active.Feeder4_A_Export   > 4e9) { Energy_Total.Active.Feeder4_A_Export   = 0;}
if (Energy_Total.Reactive.Feeder4_A_Import > 4e9) { Energy_Total.Reactive.Feeder4_A_Import = 0;}
if (Energy_Total.Reactive.Feeder4_A_Export > 4e9) { Energy_Total.Reactive.Feeder4_A_Export = 0;}

if (Energy_Total.Active.Feeder4_B_Import   > 4e9) { Energy_Total.Active.Feeder4_B_Import   = 0;}
if (Energy_Total.Active.Feeder4_B_Export   > 4e9) { Energy_Total.Active.Feeder4_B_Export   = 0;}
if (Energy_Total.Reactive.Feeder4_B_Import > 4e9) { Energy_Total.Reactive.Feeder4_B_Import = 0;}
if (Energy_Total.Reactive.Feeder4_B_Export > 4e9) { Energy_Total.Reactive.Feeder4_B_Export = 0;}

if (Energy_Total.Active.Feeder4_C_Import   > 4e9) { Energy_Total.Active.Feeder4_C_Import   = 0;}
if (Energy_Total.Active.Feeder4_C_Export   > 4e9) { Energy_Total.Active.Feeder4_C_Export   = 0;}
if (Energy_Total.Reactive.Feeder4_C_Import > 4e9) { Energy_Total.Reactive.Feeder4_C_Import = 0;}
if (Energy_Total.Reactive.Feeder4_C_Export > 4e9) { Energy_Total.Reactive.Feeder4_C_Export = 0;}

if (Energy_Total.Active.Feeder5_A_Import   > 4e9) { Energy_Total.Active.Feeder5_A_Import   = 0;}
if (Energy_Total.Active.Feeder5_A_Export   > 4e9) { Energy_Total.Active.Feeder5_A_Export   = 0;}
if (Energy_Total.Reactive.Feeder5_A_Import > 4e9) { Energy_Total.Reactive.Feeder5_A_Import = 0;}
if (Energy_Total.Reactive.Feeder5_A_Export > 4e9) { Energy_Total.Reactive.Feeder5_A_Export = 0;}

if (Energy_Total.Active.Feeder5_B_Import   > 4e9) { Energy_Total.Active.Feeder5_B_Import   = 0;}
if (Energy_Total.Active.Feeder5_B_Export   > 4e9) { Energy_Total.Active.Feeder5_B_Export   = 0;}
if (Energy_Total.Reactive.Feeder5_B_Import > 4e9) { Energy_Total.Reactive.Feeder5_B_Import = 0;}
if (Energy_Total.Reactive.Feeder5_B_Export > 4e9) { Energy_Total.Reactive.Feeder5_B_Export = 0;}

if (Energy_Total.Active.Feeder5_C_Import   > 4e9) { Energy_Total.Active.Feeder5_C_Import   = 0;}
if (Energy_Total.Active.Feeder5_C_Export   > 4e9) { Energy_Total.Active.Feeder5_C_Export   = 0;}
if (Energy_Total.Reactive.Feeder5_C_Import > 4e9) { Energy_Total.Reactive.Feeder5_C_Import = 0;}
if (Energy_Total.Reactive.Feeder5_C_Export > 4e9) { Energy_Total.Reactive.Feeder5_C_Export = 0;}

if (Energy_Total.Active.Feeder1_Import_TOT > 4e9)
{
  Energy_Total.Active.Feeder1_A_Import = 0;
  Energy_Total.Active.Feeder1_B_Import = 0;
  Energy_Total.Active.Feeder1_C_Import = 0;
  Energy_Total.Active.Feeder1_Import_TOT = 0;
}

if (Energy_Total.Active.Feeder1_Export_TOT > 4e9)
{
  Energy_Total.Active.Feeder1_A_Export = 0;
  Energy_Total.Active.Feeder1_B_Export = 0;
  Energy_Total.Active.Feeder1_C_Export = 0;
  Energy_Total.Active.Feeder1_Export_TOT = 0;
}

if (Energy_Total.Reactive.Feeder1_Import_TOT > 4e9)
{
  Energy_Total.Reactive.Feeder1_A_Import = 0;
  Energy_Total.Reactive.Feeder1_B_Import = 0;
  Energy_Total.Reactive.Feeder1_C_Import = 0;
  Energy_Total.Reactive.Feeder1_Import_TOT = 0;
}

if (Energy_Total.Reactive.Feeder1_Export_TOT > 4e9)
{
  Energy_Total.Reactive.Feeder1_A_Export = 0;
  Energy_Total.Reactive.Feeder1_B_Export = 0;
  Energy_Total.Reactive.Feeder1_C_Export = 0;
  Energy_Total.Reactive.Feeder1_Export_TOT = 0;
}

/***************************************************************************/

if (Energy_Total.Active.Feeder2_Import_TOT > 4e9)
{
  Energy_Total.Active.Feeder2_A_Import = 0;
  Energy_Total.Active.Feeder2_B_Import = 0;
  Energy_Total.Active.Feeder2_C_Import = 0;
  Energy_Total.Active.Feeder2_Import_TOT = 0;
}

if (Energy_Total.Active.Feeder2_Export_TOT > 4e9)
{
  Energy_Total.Active.Feeder2_A_Export = 0;
  Energy_Total.Active.Feeder2_B_Export = 0;
  Energy_Total.Active.Feeder2_C_Export = 0;
  Energy_Total.Active.Feeder2_Export_TOT = 0;
}

if (Energy_Total.Reactive.Feeder2_Import_TOT > 4e9)
{
  Energy_Total.Reactive.Feeder2_A_Import = 0;
  Energy_Total.Reactive.Feeder2_B_Import = 0;
  Energy_Total.Reactive.Feeder2_C_Import = 0;
  Energy_Total.Reactive.Feeder2_Import_TOT = 0;
}

if (Energy_Total.Reactive.Feeder2_Export_TOT > 4e9)
{
  Energy_Total.Reactive.Feeder2_A_Export = 0;
  Energy_Total.Reactive.Feeder2_B_Export = 0;
  Energy_Total.Reactive.Feeder2_C_Export = 0;
  Energy_Total.Reactive.Feeder2_Export_TOT = 0;
}

/************************************************************************/

if (Energy_Total.Active.Feeder3_Import_TOT > 4e9)
{
  Energy_Total.Active.Feeder3_A_Import = 0;
  Energy_Total.Active.Feeder3_B_Import = 0;
  Energy_Total.Active.Feeder3_C_Import = 0;
  Energy_Total.Active.Feeder3_Import_TOT = 0;
}

if (Energy_Total.Active.Feeder3_Export_TOT > 4e9)
{
  Energy_Total.Active.Feeder3_A_Export = 0;
  Energy_Total.Active.Feeder3_B_Export = 0;
  Energy_Total.Active.Feeder3_C_Export = 0;
  Energy_Total.Active.Feeder3_Export_TOT = 0;
}

if (Energy_Total.Reactive.Feeder3_Import_TOT > 4e9)
{
  Energy_Total.Reactive.Feeder3_A_Import = 0;
  Energy_Total.Reactive.Feeder3_B_Import = 0;
  Energy_Total.Reactive.Feeder3_C_Import = 0;
  Energy_Total.Reactive.Feeder3_Import_TOT = 0;
}

if (Energy_Total.Reactive.Feeder3_Export_TOT > 4e9)
{
  Energy_Total.Reactive.Feeder3_A_Export = 0;
  Energy_Total.Reactive.Feeder3_B_Export = 0;
  Energy_Total.Reactive.Feeder3_C_Export = 0;
  Energy_Total.Reactive.Feeder3_Export_TOT = 0;
}

/*****************************************************************************/

if (Energy_Total.Active.Feeder4_Import_TOT > 4e9)
{
  Energy_Total.Active.Feeder4_A_Import = 0;
  Energy_Total.Active.Feeder4_B_Import = 0;
  Energy_Total.Active.Feeder4_C_Import = 0;
  Energy_Total.Active.Feeder4_Import_TOT = 0;
}

if (Energy_Total.Active.Feeder4_Export_TOT > 4e9)
{
  Energy_Total.Active.Feeder4_A_Export = 0;
  Energy_Total.Active.Feeder4_B_Export = 0;
  Energy_Total.Active.Feeder4_C_Export = 0;
  Energy_Total.Active.Feeder4_Export_TOT = 0;
}

if (Energy_Total.Reactive.Feeder4_Import_TOT > 4e9)
{
  Energy_Total.Reactive.Feeder4_A_Import = 0;
  Energy_Total.Reactive.Feeder4_B_Import = 0;
  Energy_Total.Reactive.Feeder4_C_Import = 0;
  Energy_Total.Reactive.Feeder4_Import_TOT = 0;
}

if (Energy_Total.Reactive.Feeder4_Export_TOT > 4e9)
{
  Energy_Total.Reactive.Feeder4_A_Export = 0;
  Energy_Total.Reactive.Feeder4_B_Export = 0;
  Energy_Total.Reactive.Feeder4_C_Export = 0;
  Energy_Total.Reactive.Feeder4_Export_TOT = 0;
}

/****************************************************************************/

if (Energy_Total.Active.Feeder5_Import_TOT > 4e9)
{
  Energy_Total.Active.Feeder5_A_Import = 0;
  Energy_Total.Active.Feeder5_B_Import = 0;
  Energy_Total.Active.Feeder5_C_Import = 0;
  Energy_Total.Active.Feeder5_Import_TOT = 0;
}

if (Energy_Total.Active.Feeder5_Export_TOT > 4e9)
{
  Energy_Total.Active.Feeder5_A_Export = 0;
  Energy_Total.Active.Feeder5_B_Export = 0;
  Energy_Total.Active.Feeder5_C_Export = 0;
  Energy_Total.Active.Feeder5_Export_TOT = 0;
}

if (Energy_Total.Reactive.Feeder5_Import_TOT > 4e9)
{
  Energy_Total.Reactive.Feeder5_A_Import = 0;
  Energy_Total.Reactive.Feeder5_B_Import = 0;
  Energy_Total.Reactive.Feeder5_C_Import = 0;
  Energy_Total.Reactive.Feeder5_Import_TOT = 0;
}

if (Energy_Total.Reactive.Feeder5_Export_TOT > 4e9)
{
  Energy_Total.Reactive.Feeder5_A_Export = 0;
  Energy_Total.Reactive.Feeder5_B_Export = 0;
  Energy_Total.Reactive.Feeder5_C_Export = 0;
  Energy_Total.Reactive.Feeder5_Export_TOT = 0;
}

}

void pmu_Energy_Calculation(void)
{

}

void pmu_Current_Angle_Calculation(void)
{
    /***************************** Feeder 1  Current Angle ******************************************/
    Current_Angle.ICH1 = (acosf(P.Feeder1_A / S_New.Feeder1_A)) * RAD_TO_DEG ;
    Current_Angle.ICH2 = (acosf(P.Feeder1_B / S_New.Feeder1_B)) * RAD_TO_DEG ;
    Current_Angle.ICH3 = (acosf(P.Feeder1_C / S_New.Feeder1_C)) * RAD_TO_DEG ;

    if (Q_New.Feeder1_A < 0)          Current_Angle.ICH1 = -Current_Angle.ICH1;
    if (Q_New.Feeder1_B < 0)          Current_Angle.ICH2 = -Current_Angle.ICH2;
    if (Q_New.Feeder1_C < 0)          Current_Angle.ICH3 = -Current_Angle.ICH3;
    if (Current_Angle.ICH2 > 360) Current_Angle.ICH2 =  Current_Angle.ICH2 - 360.0f;

    Current_Angle.ICH1 = 0.0f   -  Current_Angle.ICH1;
    Current_Angle.ICH2 = 240.0f -  Current_Angle.ICH2;
    Current_Angle.ICH3 = 120.0f -  Current_Angle.ICH3;
    /************************************************************************************************/


    /***************************** Feeder 2  Current Angle ******************************************/
    Current_Angle.ICH4 = (acosf(P.Feeder2_A / S_New.Feeder2_A)) * RAD_TO_DEG ;
    Current_Angle.ICH5 = (acosf(P.Feeder2_B / S_New.Feeder2_B)) * RAD_TO_DEG ;
    Current_Angle.ICH6 = (acosf(P.Feeder2_C / S_New.Feeder2_C)) * RAD_TO_DEG ;

    if (Q_New.Feeder2_A < 0)          Current_Angle.ICH4 = -Current_Angle.ICH4;
    if (Q_New.Feeder2_B < 0)          Current_Angle.ICH5 = -Current_Angle.ICH5;
    if (Q_New.Feeder2_C < 0)          Current_Angle.ICH6 = -Current_Angle.ICH6;
    if (Current_Angle.ICH5 > 360) Current_Angle.ICH5 =  Current_Angle.ICH5 - 360.0f;

    Current_Angle.ICH4 = 0.0f   -  Current_Angle.ICH4;
    Current_Angle.ICH5 = 240.0f -  Current_Angle.ICH5;
    Current_Angle.ICH6 = 120.0f-  Current_Angle.ICH6;
    /************************************************************************************************/

    /***************************** Feeder 3  Current Angle ******************************************/
    Current_Angle.ICH7 = (acosf(P.Feeder3_A / S_New.Feeder3_A)) * RAD_TO_DEG ;
    Current_Angle.ICH8 = (acosf(P.Feeder3_B / S_New.Feeder3_B)) * RAD_TO_DEG ;
    Current_Angle.ICH9 = (acosf(P.Feeder3_C / S_New.Feeder3_C)) * RAD_TO_DEG ;

    if (Q_New.Feeder3_A < 0)          Current_Angle.ICH7 = -Current_Angle.ICH7;
    if (Q_New.Feeder3_B < 0)          Current_Angle.ICH8 = -Current_Angle.ICH8;
    if (Q_New.Feeder3_C < 0)          Current_Angle.ICH9 = -Current_Angle.ICH9;
    if (Current_Angle.ICH8 > 360) Current_Angle.ICH8 =  Current_Angle.ICH8 - 360.0f;

    Current_Angle.ICH7 = 0.0f   -  Current_Angle.ICH7;
    Current_Angle.ICH8 = 240.0f -  Current_Angle.ICH8;
    Current_Angle.ICH9 = 120.0f -  Current_Angle.ICH9;
    /************************************************************************************************/

    /***************************** Feeder 4  Current Angle ******************************************/
    Current_Angle.ICH10 = (acosf(P.Feeder4_A / S_New.Feeder4_A)) * RAD_TO_DEG ;
    Current_Angle.ICH11 = (acosf(P.Feeder4_B / S_New.Feeder4_B)) * RAD_TO_DEG ;
    Current_Angle.ICH12 = (acosf(P.Feeder4_C / S_New.Feeder4_C)) * RAD_TO_DEG ;

    if (Q_New.Feeder4_A < 0)           Current_Angle.ICH10 = -Current_Angle.ICH10;
    if (Q_New.Feeder4_B < 0)           Current_Angle.ICH11 = -Current_Angle.ICH11;
    if (Q_New.Feeder4_C < 0)           Current_Angle.ICH12 = -Current_Angle.ICH12;
    if (Current_Angle.ICH11 > 360) Current_Angle.ICH11 =  Current_Angle.ICH11 - 360.0f;

    Current_Angle.ICH10 = 0.0f   -  Current_Angle.ICH10;
    Current_Angle.ICH11 = 240.0f -  Current_Angle.ICH11;
    Current_Angle.ICH12 = 120.0f -  Current_Angle.ICH12;
    /************************************************************************************************/

/***************************** Feeder 5  Current Angle ******************************************/
    Current_Angle.ICH13 = (acosf(P.Feeder5_A / S_New.Feeder5_A)) * RAD_TO_DEG ;
    Current_Angle.ICH14 = (acosf(P.Feeder5_B / S_New.Feeder5_B)) * RAD_TO_DEG ;
    Current_Angle.ICH15 = (acosf(P.Feeder5_C / S_New.Feeder5_C)) * RAD_TO_DEG ;

    if (Q_New.Feeder5_A < 0)           Current_Angle.ICH13 = -Current_Angle.ICH13;
    if (Q_New.Feeder5_B < 0)           Current_Angle.ICH14 = -Current_Angle.ICH14;
    if (Q_New.Feeder5_C < 0)           Current_Angle.ICH15 = -Current_Angle.ICH15;
    if (Current_Angle.ICH14 > 360) Current_Angle.ICH14 =  Current_Angle.ICH14 - 360.0f;

    Current_Angle.ICH13 = 0.0f   -  Current_Angle.ICH13;
    Current_Angle.ICH14 = 240.0f -  Current_Angle.ICH14;
    Current_Angle.ICH15 = 120.0f -  Current_Angle.ICH15;
/************************************************************************************************/
}

void pmu_clear_PQ_Sum_Array(void)
{
	memset(&P_Sum, 0, sizeof(P_Sum));
  memset(&Q_Sum, 0, sizeof(Q_Sum));
  memset(&Q_Sum_New, 0 , sizeof(Q_Sum_New));
}

void pmu_calculateDemand(void)
{
	demandParams.feeder1 = (demandParams.secondEnergyIndex[0] - demandParams.firstEnergyIndex[0]) * 4;
	demandParams.feeder2 = (demandParams.secondEnergyIndex[1] - demandParams.firstEnergyIndex[1]) * 4;
	demandParams.feeder3 = (demandParams.secondEnergyIndex[2] - demandParams.firstEnergyIndex[2]) * 4;
	demandParams.feeder4 = (demandParams.secondEnergyIndex[3] - demandParams.firstEnergyIndex[3]) * 4;
	demandParams.feeder5 = (demandParams.secondEnergyIndex[4] - demandParams.firstEnergyIndex[4]) * 4;
	
	demandParams.timerCnt = 0;
}

void pmu_getFirstEnergyIndex(void)
{
	demandParams.firstEnergyIndex[0] = Energy_Total.Active.Feeder1_Import_TOT;
	demandParams.firstEnergyIndex[1] = Energy_Total.Active.Feeder2_Import_TOT;
	demandParams.firstEnergyIndex[2] = Energy_Total.Active.Feeder3_Import_TOT;
	demandParams.firstEnergyIndex[3] = Energy_Total.Active.Feeder4_Import_TOT;
	demandParams.firstEnergyIndex[4] = Energy_Total.Active.Feeder5_Import_TOT;
}

void pmu_getSecondEnergyIndex(void)
{
	demandParams.secondEnergyIndex[0] = Energy_Total.Active.Feeder1_Import_TOT;
	demandParams.secondEnergyIndex[1] = Energy_Total.Active.Feeder2_Import_TOT;
	demandParams.secondEnergyIndex[2] = Energy_Total.Active.Feeder3_Import_TOT;
	demandParams.secondEnergyIndex[3] = Energy_Total.Active.Feeder4_Import_TOT;
	demandParams.secondEnergyIndex[4] = Energy_Total.Active.Feeder5_Import_TOT;
}
