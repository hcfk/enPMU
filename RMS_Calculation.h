/**
  ****************************************************************************************
  * @file    RMS_Calculation.h
  * @author  Serbay Ozkan
  * @version V1.0.0
  * @date    13-November-2016
  * @brief   Microchip MCP3914 and MCP3919 External Analog-Front-End Reading Header File
  ****************************************************************************************
  */

#include "stdint.h"

#ifndef RMS_CALCULATION_H_
#define RMS_CALCULATION_H_

#define RMS_CONSTANT    0.00158478605388272583201267828843F

void pmu_rmsCalculation(void);
void pmu_clearRMS_Sum_Array(void);
void pmu_checkVoltageAngle(void);
void pmu_findMaxCurrent(void);
void pmu_findMinCurrent(void);
void pmu_calculateAvarageFeederCurrent(void);
void pmu_calculateNeutralFeederCurrent(void);
void pmu_calculateCurrentUnbalanceFactor(void);
void pmu_calculateCurrentUnbalanceFactorNew(void);

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
	float lagVAB;
	float lagVAC;
	float neutralCurrent_feeder1;
	float neutralCurrent_feeder2;
	float neutralCurrent_feeder3;
	float neutralCurrent_feeder4;
	float neutralCurrent_feeder5;
	
	float averageCurrent_feeder1;
	float averageCurrent_feeder2;
	float averageCurrent_feeder3;
	float averageCurrent_feeder4;
	float averageCurrent_feeder5;
	
}Typedef_ADC_RMS_Params;

typedef struct
{
	float feeder1;
	float feeder2;
	float feeder3;
	float feeder4;
	float feeder5;
}Typedef_maxInstantCurrent;

typedef struct
{
	float feeder1_A;
	float feeder1_B;
	float feeder1_C;
	float feeder1;
	
	float feeder2_A;
	float feeder2_B;
	float feeder2_C;
	float feeder2;
	
	float feeder3_A;
	float feeder3_B;
	float feeder3_C;
	float feeder3;
	
	float feeder4_A;
	float feeder4_B;
	float feeder4_C;
	float feeder4;
	
	float feeder5_A;
	float feeder5_B;
	float feeder5_C;
	float feeder5;
}Typedef_currentUnbalanceFactor;

typedef struct
{
	uint32_t rmsCounter;
}Typedef_rmsGenParams;

extern Typedef_ADC_RMS_Params RMS_Value;
extern Typedef_rmsGenParams rmsGenParams;
extern Typedef_currentUnbalanceFactor currentUnbalanceFactor;
#endif /* RMS_CALCULATION_H_ */
