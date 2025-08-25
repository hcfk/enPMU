/**
  *****************************************************************************
  * @file    PhaseShift.c
  * @author  Serbay Ozkan
  * @version V1.0.0
  * @date    5-March-2017
  * @brief   Includes functions for shifting input signal in certain degree
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

/* Typedefs ------------------------------------------------------------------*/
Typedef_signalShiftParams  signalShiftParams;
Typedef_signalShiftParams2 signalShiftParams2;

/* User Variables ------------------------------------------------------------*/
void pmu_signalShift(void)
{
  signalShiftParams.VAN_Shift[signalShiftParams.shiftSampleNumber] = ADC_Result.VCH1;
  signalShiftParams.VBN_Shift[signalShiftParams.shiftSampleNumber] = ADC_Result.VCH2;
  signalShiftParams.VCN_Shift[signalShiftParams.shiftSampleNumber] = ADC_Result.VCH3;
  signalShiftParams.shiftSampleNumber++;
  if (signalShiftParams.shiftSampleNumber == SAMPLE_SHIFT)
  {
    signalShiftParams.shiftSampleNumber = 0;
  }
  signalShiftParams.lagVANShift = signalShiftParams.VAN_Shift[signalShiftParams.shiftSampleNumber];
  signalShiftParams.lagVBNShift = signalShiftParams.VBN_Shift[signalShiftParams.shiftSampleNumber];
  signalShiftParams.lagVCNShift = signalShiftParams.VCN_Shift[signalShiftParams.shiftSampleNumber];

  signalShiftParams.lagVABShift = signalShiftParams.lagVANShift - ADC_Result.VCH2;
  signalShiftParams.lagVACShift = signalShiftParams.lagVANShift - ADC_Result.VCH3;
}

void pmu_signalShift_powerCalculation(void)
{
  signalShiftParams2.ICH1_Shift [signalShiftParams2.shiftSampleNumber] = ADC_Values.ICH1;
  signalShiftParams2.ICH2_Shift [signalShiftParams2.shiftSampleNumber] = ADC_Values.ICH2;
  signalShiftParams2.ICH3_Shift [signalShiftParams2.shiftSampleNumber] = ADC_Values.ICH3;
  signalShiftParams2.ICH4_Shift [signalShiftParams2.shiftSampleNumber] = ADC_Values.ICH4;
  signalShiftParams2.ICH5_Shift [signalShiftParams2.shiftSampleNumber] = ADC_Values.ICH5;
  signalShiftParams2.ICH6_Shift [signalShiftParams2.shiftSampleNumber] = ADC_Values.ICH6;
  signalShiftParams2.ICH7_Shift [signalShiftParams2.shiftSampleNumber] = ADC_Values.ICH7;
  signalShiftParams2.ICH8_Shift [signalShiftParams2.shiftSampleNumber] = ADC_Values.ICH8;
  signalShiftParams2.ICH9_Shift [signalShiftParams2.shiftSampleNumber] = ADC_Values.ICH9;
  signalShiftParams2.ICH10_Shift[signalShiftParams2.shiftSampleNumber] = ADC_Values.ICH10;
  signalShiftParams2.ICH11_Shift[signalShiftParams2.shiftSampleNumber] = ADC_Values.ICH11;
  signalShiftParams2.ICH12_Shift[signalShiftParams2.shiftSampleNumber] = ADC_Values.ICH12;
  signalShiftParams2.ICH13_Shift[signalShiftParams2.shiftSampleNumber] = ADC_Values.ICH13;
  signalShiftParams2.ICH14_Shift[signalShiftParams2.shiftSampleNumber] = ADC_Values.ICH14;
  signalShiftParams2.ICH15_Shift[signalShiftParams2.shiftSampleNumber] = ADC_Values.ICH15;
  signalShiftParams2.shiftSampleNumber++;
  if (signalShiftParams2.shiftSampleNumber == SAMPLE_SHIFT_90_DEGREE)
  {
    signalShiftParams2.shiftSampleNumber = 0;
  }
  signalShiftParams2.lagICH1Shift  = signalShiftParams2.ICH1_Shift [signalShiftParams2.shiftSampleNumber];
  signalShiftParams2.lagICH2Shift  = signalShiftParams2.ICH2_Shift [signalShiftParams2.shiftSampleNumber];
  signalShiftParams2.lagICH3Shift  = signalShiftParams2.ICH3_Shift [signalShiftParams2.shiftSampleNumber];
  signalShiftParams2.lagICH4Shift  = signalShiftParams2.ICH4_Shift [signalShiftParams2.shiftSampleNumber];
  signalShiftParams2.lagICH5Shift  = signalShiftParams2.ICH5_Shift [signalShiftParams2.shiftSampleNumber];
  signalShiftParams2.lagICH6Shift  = signalShiftParams2.ICH6_Shift [signalShiftParams2.shiftSampleNumber];
  signalShiftParams2.lagICH7Shift  = signalShiftParams2.ICH7_Shift [signalShiftParams2.shiftSampleNumber];
  signalShiftParams2.lagICH8Shift  = signalShiftParams2.ICH8_Shift [signalShiftParams2.shiftSampleNumber];
  signalShiftParams2.lagICH9Shift  = signalShiftParams2.ICH9_Shift [signalShiftParams2.shiftSampleNumber];
  signalShiftParams2.lagICH10Shift = signalShiftParams2.ICH10_Shift[signalShiftParams2.shiftSampleNumber];
  signalShiftParams2.lagICH11Shift = signalShiftParams2.ICH11_Shift[signalShiftParams2.shiftSampleNumber];
  signalShiftParams2.lagICH12Shift = signalShiftParams2.ICH12_Shift[signalShiftParams2.shiftSampleNumber];
  signalShiftParams2.lagICH13Shift = signalShiftParams2.ICH13_Shift[signalShiftParams2.shiftSampleNumber];
  signalShiftParams2.lagICH14Shift = signalShiftParams2.ICH14_Shift[signalShiftParams2.shiftSampleNumber];
  signalShiftParams2.lagICH15Shift = signalShiftParams2.ICH15_Shift[signalShiftParams2.shiftSampleNumber];
}
