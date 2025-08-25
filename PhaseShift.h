/**
  ******************************************************************************
  * @file    PhaseShift.h
  * @author  Serbay Ozkan
  * @version V1.0.0
  * @date    5-March-2017
  * @brief   Includes functions header file for shifting input signal
  ******************************************************************************
  */

#include "stdint.h"

#ifndef PHASE_SHIFT_H_
#define PHASE_SHIFT_H_

#define SAMPLE_SHIFT            21
#define SAMPLE_SHIFT_90_DEGREE  17 /* 90 Degree */

void pmu_signalShift(void);
void pmu_signalShift_powerCalculation(void);

typedef struct
{
  float    VAN_Shift[SAMPLE_SHIFT];
  float    VBN_Shift[SAMPLE_SHIFT];
  float    VCN_Shift[SAMPLE_SHIFT];
  float    lagVANShift;
  float    lagVBNShift;
  float    lagVCNShift;
  float    lagVABShift;
  float    lagVACShift;
  uint32_t shiftSampleNumber;
}Typedef_signalShiftParams;

typedef struct
{
  float    ICH1_Shift[SAMPLE_SHIFT_90_DEGREE];
  float    ICH2_Shift[SAMPLE_SHIFT_90_DEGREE];
  float    ICH3_Shift[SAMPLE_SHIFT_90_DEGREE];
  float    ICH4_Shift[SAMPLE_SHIFT_90_DEGREE];
  float    ICH5_Shift[SAMPLE_SHIFT_90_DEGREE];
  float    ICH6_Shift[SAMPLE_SHIFT_90_DEGREE];
  float    ICH7_Shift[SAMPLE_SHIFT_90_DEGREE];
  float    ICH8_Shift[SAMPLE_SHIFT_90_DEGREE];
  float    ICH9_Shift[SAMPLE_SHIFT_90_DEGREE];
  float    ICH10_Shift[SAMPLE_SHIFT_90_DEGREE];
  float    ICH11_Shift[SAMPLE_SHIFT_90_DEGREE];
  float    ICH12_Shift[SAMPLE_SHIFT_90_DEGREE];
  float    ICH13_Shift[SAMPLE_SHIFT_90_DEGREE];
  float    ICH14_Shift[SAMPLE_SHIFT_90_DEGREE];
  float    ICH15_Shift[SAMPLE_SHIFT_90_DEGREE];
  float    lagICH1Shift;
  float    lagICH2Shift;
  float    lagICH3Shift;
  float    lagICH4Shift;
  float    lagICH5Shift;
  float    lagICH6Shift;
  float    lagICH7Shift;
  float    lagICH8Shift;
  float    lagICH9Shift;
  float    lagICH10Shift;
  float    lagICH11Shift;
  float    lagICH12Shift;
  float    lagICH13Shift;
  float    lagICH14Shift;
  float    lagICH15Shift;
  uint32_t shiftSampleNumber;
}Typedef_signalShiftParams2;

extern Typedef_signalShiftParams  signalShiftParams;
extern Typedef_signalShiftParams2 signalShiftParams2;
#endif /* PHASE_SHIFT_H_ */
