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
#include "RMS_Calculation.h"
#include "ADC_Process.h"
#include "PQ_Calculation.h"
#include "PhaseShift.h"
/* Typedefs ------------------------------------------------------------------*/
Typedef_rmsGenParams rmsGenParams;
Typedef_ADC_RMS_Params ADC_Sum;
Typedef_ADC_RMS_Params RMS_Value;
Typedef_maxInstantCurrent maxInstantCurrent;
Typedef_maxInstantCurrent minInstantCurrent;
Typedef_currentUnbalanceFactor currentUnbalanceFactor;
/* User varibles -------------------------------------------------------------*/


/**
  * @brief  This function reads all channels of MCP3919 ADC and converting
  			ADC data to processable format
  * @note
  * @param  None
  * @retval None
  */

void pmu_rmsCalculation(void)
{
		ADC_Sum.lagVAB = ADC_Sum.lagVAB + signalShiftParams.lagVABShift * signalShiftParams.lagVABShift;
		ADC_Sum.lagVAC = ADC_Sum.lagVAC + signalShiftParams.lagVACShift * signalShiftParams.lagVACShift;
   	ADC_Sum.VCH1   = ADC_Sum.VCH1   + ADC_Values.VCH1  * ADC_Values.VCH1;
    ADC_Sum.VCH2   = ADC_Sum.VCH2   + ADC_Values.VCH2  * ADC_Values.VCH2;
    ADC_Sum.VCH3   = ADC_Sum.VCH3   + ADC_Values.VCH3  * ADC_Values.VCH3;
    ADC_Sum.VCH12  = ADC_Sum.VCH12  + ADC_Values.VCH12 * ADC_Values.VCH12;
    ADC_Sum.VCH23  = ADC_Sum.VCH23  + ADC_Values.VCH23 * ADC_Values.VCH23;
    ADC_Sum.VCH31  = ADC_Sum.VCH31  + ADC_Values.VCH31 * ADC_Values.VCH31;
    ADC_Sum.ICH1   = ADC_Sum.ICH1   + ADC_Values.ICH1  * ADC_Values.ICH1;
    ADC_Sum.ICH2   = ADC_Sum.ICH2   + ADC_Values.ICH2  * ADC_Values.ICH2;
    ADC_Sum.ICH3   = ADC_Sum.ICH3   + ADC_Values.ICH3  * ADC_Values.ICH3;
    ADC_Sum.ICH4   = ADC_Sum.ICH4   + ADC_Values.ICH4  * ADC_Values.ICH4;
    ADC_Sum.ICH5   = ADC_Sum.ICH5   + ADC_Values.ICH5  * ADC_Values.ICH5;
    ADC_Sum.ICH6   = ADC_Sum.ICH6   + ADC_Values.ICH6  * ADC_Values.ICH6;
    ADC_Sum.ICH7   = ADC_Sum.ICH7   + ADC_Values.ICH7  * ADC_Values.ICH7;
    ADC_Sum.ICH8   = ADC_Sum.ICH8   + ADC_Values.ICH8  * ADC_Values.ICH8;
    ADC_Sum.ICH9   = ADC_Sum.ICH9   + ADC_Values.ICH9  * ADC_Values.ICH9;
    ADC_Sum.ICH10  = ADC_Sum.ICH10  + ADC_Values.ICH10 * ADC_Values.ICH10;
    ADC_Sum.ICH11  = ADC_Sum.ICH11  + ADC_Values.ICH11 * ADC_Values.ICH11;
    ADC_Sum.ICH12  = ADC_Sum.ICH12  + ADC_Values.ICH12 * ADC_Values.ICH12;
    ADC_Sum.ICH13  = ADC_Sum.ICH13  + ADC_Values.ICH13 * ADC_Values.ICH13;
    ADC_Sum.ICH14  = ADC_Sum.ICH14  + ADC_Values.ICH14 * ADC_Values.ICH14;
    ADC_Sum.ICH15  = ADC_Sum.ICH15  + ADC_Values.ICH15 * ADC_Values.ICH15;
	
	ADC_Sum.neutralCurrent_feeder1 = ADC_Sum.neutralCurrent_feeder1 + (ADC_Values.ICHN_feeder1 * ADC_Values.ICHN_feeder1);
	ADC_Sum.neutralCurrent_feeder2 = ADC_Sum.neutralCurrent_feeder2 + (ADC_Values.ICHN_feeder2 * ADC_Values.ICHN_feeder2);
	ADC_Sum.neutralCurrent_feeder3 = ADC_Sum.neutralCurrent_feeder3 + (ADC_Values.ICHN_feeder3 * ADC_Values.ICHN_feeder3);
	ADC_Sum.neutralCurrent_feeder4 = ADC_Sum.neutralCurrent_feeder4 + (ADC_Values.ICHN_feeder4 * ADC_Values.ICHN_feeder4);
	ADC_Sum.neutralCurrent_feeder5 = ADC_Sum.neutralCurrent_feeder5 + (ADC_Values.ICHN_feeder5 * ADC_Values.ICHN_feeder5);

    rmsGenParams.rmsCounter++;

		if(rmsGenParams.rmsCounter == 631)
		{
			RMS_Value.lagVAB = __sqrtf(ADC_Sum.lagVAB * RMS_CONSTANT);
			RMS_Value.lagVAC = __sqrtf(ADC_Sum.lagVAC * RMS_CONSTANT);
			RMS_Value.VCH1   = __sqrtf(ADC_Sum.VCH1   * RMS_CONSTANT);
    	RMS_Value.VCH2   = __sqrtf(ADC_Sum.VCH2   * RMS_CONSTANT);
    	RMS_Value.VCH3   = __sqrtf(ADC_Sum.VCH3   * RMS_CONSTANT);
    	RMS_Value.VCH12  = __sqrtf(ADC_Sum.VCH12  * RMS_CONSTANT);
    	RMS_Value.VCH23  = __sqrtf(ADC_Sum.VCH23  * RMS_CONSTANT);
    	RMS_Value.VCH31  = __sqrtf(ADC_Sum.VCH31  * RMS_CONSTANT);
			RMS_Value.ICH1   = __sqrtf(ADC_Sum.ICH1   * RMS_CONSTANT);
    	RMS_Value.ICH2   = __sqrtf(ADC_Sum.ICH2   * RMS_CONSTANT);
    	RMS_Value.ICH3   = __sqrtf(ADC_Sum.ICH3   * RMS_CONSTANT);
    	RMS_Value.ICH4   = __sqrtf(ADC_Sum.ICH4   * RMS_CONSTANT);
    	RMS_Value.ICH5   = __sqrtf(ADC_Sum.ICH5   * RMS_CONSTANT);
    	RMS_Value.ICH6   = __sqrtf(ADC_Sum.ICH6   * RMS_CONSTANT);
			RMS_Value.ICH7   = __sqrtf(ADC_Sum.ICH7   * RMS_CONSTANT);
    	RMS_Value.ICH8   = __sqrtf(ADC_Sum.ICH8   * RMS_CONSTANT);
    	RMS_Value.ICH9   = __sqrtf(ADC_Sum.ICH9   * RMS_CONSTANT);
    	RMS_Value.ICH10  = __sqrtf(ADC_Sum.ICH10  * RMS_CONSTANT);
			RMS_Value.ICH11  = __sqrtf(ADC_Sum.ICH11  * RMS_CONSTANT);
    	RMS_Value.ICH12  = __sqrtf(ADC_Sum.ICH12  * RMS_CONSTANT);
    	RMS_Value.ICH13  = __sqrtf(ADC_Sum.ICH13  * RMS_CONSTANT);
    	RMS_Value.ICH14  = __sqrtf(ADC_Sum.ICH14  * RMS_CONSTANT);
    	RMS_Value.ICH15  = __sqrtf(ADC_Sum.ICH15  * RMS_CONSTANT);
		
		
		pmu_calculateNeutralFeederCurrent();
		pmu_calculateAvarageFeederCurrent();
		pmu_findMaxCurrent();
		pmu_findMinCurrent();
		// pmu_calculateCurrentUnbalanceFactor();
		pmu_calculateCurrentUnbalanceFactorNew();
		
		rmsGenParams.rmsCounter = 0;
		pmu_checkVoltageAngle();
		pmu_clearRMS_Sum_Array();
		}

}

void pmu_calculateCurrentUnbalanceFactor(void)
{
	currentUnbalanceFactor.feeder1 = ((maxInstantCurrent.feeder1 - RMS_Value.averageCurrent_feeder1) / (RMS_Value.averageCurrent_feeder1)) * 100.0f;
	currentUnbalanceFactor.feeder2 = ((maxInstantCurrent.feeder2 - RMS_Value.averageCurrent_feeder2) / (RMS_Value.averageCurrent_feeder2)) * 100.0f;
	currentUnbalanceFactor.feeder3 = ((maxInstantCurrent.feeder3 - RMS_Value.averageCurrent_feeder3) / (RMS_Value.averageCurrent_feeder3)) * 100.0f;
	currentUnbalanceFactor.feeder4 = ((maxInstantCurrent.feeder4 - RMS_Value.averageCurrent_feeder4) / (RMS_Value.averageCurrent_feeder4)) * 100.0f;
	currentUnbalanceFactor.feeder5 = ((maxInstantCurrent.feeder5 - RMS_Value.averageCurrent_feeder5) / (RMS_Value.averageCurrent_feeder5)) * 100.0f;
}

void pmu_calculateCurrentUnbalanceFactorNew(void)
{
	currentUnbalanceFactor.feeder1 = ((maxInstantCurrent.feeder1 - minInstantCurrent.feeder1) / minInstantCurrent.feeder1) * 100.0f;
	currentUnbalanceFactor.feeder2 = ((maxInstantCurrent.feeder2 - minInstantCurrent.feeder2) / minInstantCurrent.feeder2) * 100.0f;
	currentUnbalanceFactor.feeder3 = ((maxInstantCurrent.feeder3 - minInstantCurrent.feeder3) / minInstantCurrent.feeder3) * 100.0f;
	currentUnbalanceFactor.feeder4 = ((maxInstantCurrent.feeder4 - minInstantCurrent.feeder4) / minInstantCurrent.feeder4) * 100.0f;
	currentUnbalanceFactor.feeder5 = ((maxInstantCurrent.feeder5 - minInstantCurrent.feeder5) / minInstantCurrent.feeder5) * 100.0f;
}

void pmu_calculateNeutralFeederCurrent(void)
{
	#if 1
	RMS_Value.neutralCurrent_feeder1 = __sqrtf(ADC_Sum.neutralCurrent_feeder1 * RMS_CONSTANT);
	RMS_Value.neutralCurrent_feeder2 = __sqrtf(ADC_Sum.neutralCurrent_feeder2 * RMS_CONSTANT);
	RMS_Value.neutralCurrent_feeder3 = __sqrtf(ADC_Sum.neutralCurrent_feeder3 * RMS_CONSTANT);
	RMS_Value.neutralCurrent_feeder4 = __sqrtf(ADC_Sum.neutralCurrent_feeder4 * RMS_CONSTANT);
	RMS_Value.neutralCurrent_feeder5 = __sqrtf(ADC_Sum.neutralCurrent_feeder5 * RMS_CONSTANT);
	#endif
	
	#if 0
	float neutralSum1 = (RMS_Value.ICH1 * RMS_Value.ICH1) + (RMS_Value.ICH2 * RMS_Value.ICH2) + (RMS_Value.ICH3 * RMS_Value.ICH3);
	float neutralSum2 = (RMS_Value.ICH1 * RMS_Value.ICH2) + (RMS_Value.ICH2 * RMS_Value.ICH3) + (RMS_Value.ICH3 * RMS_Value.ICH1);
	float neutralRes = neutralSum1 - neutralSum2;
	RMS_Value.neutralCurrent_feeder1 = __sqrtf(neutralRes);
	
	neutralSum1 = (RMS_Value.ICH4 * RMS_Value.ICH4) + (RMS_Value.ICH5 * RMS_Value.ICH5) + (RMS_Value.ICH6 * RMS_Value.ICH6);
	neutralSum2 = (RMS_Value.ICH4 * RMS_Value.ICH5) + (RMS_Value.ICH5 * RMS_Value.ICH6) + (RMS_Value.ICH6 * RMS_Value.ICH4);
	neutralRes = neutralSum1 - neutralSum2;
	RMS_Value.neutralCurrent_feeder2 = __sqrtf(neutralRes);
	
	neutralSum1 = (RMS_Value.ICH7 * RMS_Value.ICH7) + (RMS_Value.ICH8 * RMS_Value.ICH8) + (RMS_Value.ICH9 * RMS_Value.ICH9);
	neutralSum2 = (RMS_Value.ICH7 * RMS_Value.ICH8) + (RMS_Value.ICH8 * RMS_Value.ICH9) + (RMS_Value.ICH9 * RMS_Value.ICH7);
	neutralRes = neutralSum1 - neutralSum2;
	RMS_Value.neutralCurrent_feeder3 = __sqrtf(neutralRes);
	
	neutralSum1 = (RMS_Value.ICH10 * RMS_Value.ICH10) + (RMS_Value.ICH11 * RMS_Value.ICH11) + (RMS_Value.ICH12 * RMS_Value.ICH12);
	neutralSum2 = (RMS_Value.ICH10 * RMS_Value.ICH11) + (RMS_Value.ICH11 * RMS_Value.ICH12) + (RMS_Value.ICH12 * RMS_Value.ICH10);
	neutralRes = neutralSum1 - neutralSum2;
	RMS_Value.neutralCurrent_feeder4 = __sqrtf(neutralRes);
	
	neutralSum1 = (RMS_Value.ICH13 * RMS_Value.ICH13) + (RMS_Value.ICH14 * RMS_Value.ICH14) + (RMS_Value.ICH15 * RMS_Value.ICH15);
	neutralSum2 = (RMS_Value.ICH13 * RMS_Value.ICH14) + (RMS_Value.ICH14 * RMS_Value.ICH15) + (RMS_Value.ICH15 * RMS_Value.ICH13);
	neutralRes = neutralSum1 - neutralSum2;
	RMS_Value.neutralCurrent_feeder5 = __sqrtf(neutralRes);
	#endif
}

void pmu_calculateAvarageFeederCurrent(void)
{
	 RMS_Value.averageCurrent_feeder1 = ((RMS_Value.ICH1 + RMS_Value.ICH2 + RMS_Value.ICH3)    * 0.33333333333333333f);
	 RMS_Value.averageCurrent_feeder2 = ((RMS_Value.ICH4 + RMS_Value.ICH5 + RMS_Value.ICH6)    * 0.33333333333333333f);
	 RMS_Value.averageCurrent_feeder3 = ((RMS_Value.ICH7 + RMS_Value.ICH8 + RMS_Value.ICH9)    * 0.33333333333333333f);
	 RMS_Value.averageCurrent_feeder4 = ((RMS_Value.ICH10 + RMS_Value.ICH11 + RMS_Value.ICH12) * 0.33333333333333333f);
	 RMS_Value.averageCurrent_feeder5 = ((RMS_Value.ICH13 + RMS_Value.ICH14 + RMS_Value.ICH15) * 0.33333333333333333f);
} 

void pmu_findMinCurrent(void)
{
	float minCurrent = RMS_Value.ICH1;
	
	if (minCurrent < RMS_Value.ICH2 && minCurrent > RMS_Value.ICH3) minCurrent = RMS_Value.ICH3;
	if (minCurrent < RMS_Value.ICH3 && minCurrent > RMS_Value.ICH2) minCurrent = RMS_Value.ICH2;
	if (minCurrent > RMS_Value.ICH2 && minCurrent > RMS_Value.ICH3)
	{
		if (RMS_Value.ICH2 < RMS_Value.ICH3) minCurrent = RMS_Value.ICH2;
		else minCurrent = RMS_Value.ICH3;
	}
	
	minInstantCurrent.feeder1 = minCurrent;
	
	minCurrent = RMS_Value.ICH4;
	
	if (minCurrent < RMS_Value.ICH5 && minCurrent > RMS_Value.ICH6) minCurrent = RMS_Value.ICH6;
	if (minCurrent < RMS_Value.ICH6 && minCurrent > RMS_Value.ICH5) minCurrent = RMS_Value.ICH5;
	if (minCurrent > RMS_Value.ICH5 && minCurrent > RMS_Value.ICH6)
	{
		if (RMS_Value.ICH5 < RMS_Value.ICH6) minCurrent = RMS_Value.ICH5;
		else minCurrent = RMS_Value.ICH6;
	}
	
	minInstantCurrent.feeder2 = minCurrent;
	
	minCurrent = RMS_Value.ICH7;
	
	if (minCurrent < RMS_Value.ICH8 && minCurrent > RMS_Value.ICH9) minCurrent = RMS_Value.ICH9;
	if (minCurrent < RMS_Value.ICH9 && minCurrent > RMS_Value.ICH8) minCurrent = RMS_Value.ICH8;
	if (minCurrent > RMS_Value.ICH8 && minCurrent > RMS_Value.ICH9)
	{
		if (RMS_Value.ICH8 < RMS_Value.ICH9) minCurrent = RMS_Value.ICH8;
		else minCurrent = RMS_Value.ICH9;
	}
	
	minInstantCurrent.feeder3 = minCurrent;
	
	minCurrent = RMS_Value.ICH10;
	
	if (minCurrent < RMS_Value.ICH11 && minCurrent > RMS_Value.ICH12) minCurrent = RMS_Value.ICH12;
	if (minCurrent < RMS_Value.ICH12 && minCurrent > RMS_Value.ICH11) minCurrent = RMS_Value.ICH11;
	if (minCurrent > RMS_Value.ICH11 && minCurrent > RMS_Value.ICH12)
	{
		if (RMS_Value.ICH11 < RMS_Value.ICH12) minCurrent = RMS_Value.ICH11;
		else minCurrent = RMS_Value.ICH12;
	}
	
	minInstantCurrent.feeder4 = minCurrent;
	
	minCurrent = RMS_Value.ICH13;
	
	if (minCurrent < RMS_Value.ICH14 && minCurrent > RMS_Value.ICH15) minCurrent = RMS_Value.ICH15;
	if (minCurrent < RMS_Value.ICH15 && minCurrent > RMS_Value.ICH14) minCurrent = RMS_Value.ICH14;
	if (minCurrent > RMS_Value.ICH14 && minCurrent > RMS_Value.ICH15)
	{
		if (RMS_Value.ICH14 < RMS_Value.ICH15) minCurrent = RMS_Value.ICH14;
		else minCurrent = RMS_Value.ICH15;
	}
	
	minInstantCurrent.feeder5 = minCurrent;
	
}

void pmu_findMaxCurrent(void)
{
	float maxCurrent = RMS_Value.ICH1;
	
	if (maxCurrent < RMS_Value.ICH2 && maxCurrent > RMS_Value.ICH3) maxCurrent = RMS_Value.ICH2;
	if (maxCurrent < RMS_Value.ICH3 && maxCurrent > RMS_Value.ICH2) maxCurrent = RMS_Value.ICH3;
	if (maxCurrent < RMS_Value.ICH2 && maxCurrent < RMS_Value.ICH3)
	{
		if (RMS_Value.ICH2 > RMS_Value.ICH3) maxCurrent = RMS_Value.ICH2;
		else maxCurrent = RMS_Value.ICH3;
	}
	
	maxInstantCurrent.feeder1 = maxCurrent;
	
	maxCurrent = RMS_Value.ICH4;
	
	if (maxCurrent < RMS_Value.ICH5 && maxCurrent > RMS_Value.ICH6) maxCurrent = RMS_Value.ICH5;
	if (maxCurrent < RMS_Value.ICH6 && maxCurrent > RMS_Value.ICH5) maxCurrent = RMS_Value.ICH6;
	if (maxCurrent < RMS_Value.ICH5 && maxCurrent < RMS_Value.ICH6)
	{
		if (RMS_Value.ICH5 > RMS_Value.ICH6) maxCurrent = RMS_Value.ICH5;
		else maxCurrent = RMS_Value.ICH6;
	}
	
	maxInstantCurrent.feeder2 = maxCurrent;
	
	maxCurrent = RMS_Value.ICH7;
	
	if (maxCurrent < RMS_Value.ICH8 && maxCurrent > RMS_Value.ICH9) maxCurrent = RMS_Value.ICH8;
	if (maxCurrent < RMS_Value.ICH9 && maxCurrent > RMS_Value.ICH8) maxCurrent = RMS_Value.ICH9;
	if (maxCurrent < RMS_Value.ICH8 && maxCurrent < RMS_Value.ICH9)
	{
		if (RMS_Value.ICH8 > RMS_Value.ICH9) maxCurrent = RMS_Value.ICH8;
		else maxCurrent = RMS_Value.ICH9;
	}
	
	maxInstantCurrent.feeder3 = maxCurrent;
	
	maxCurrent = RMS_Value.ICH10;
	
	if (maxCurrent < RMS_Value.ICH11 && maxCurrent > RMS_Value.ICH12) maxCurrent = RMS_Value.ICH11;
	if (maxCurrent < RMS_Value.ICH12 && maxCurrent > RMS_Value.ICH11) maxCurrent = RMS_Value.ICH12;
	if (maxCurrent < RMS_Value.ICH11 && maxCurrent < RMS_Value.ICH12)
	{
		if (RMS_Value.ICH11 > RMS_Value.ICH12) maxCurrent = RMS_Value.ICH11;
		else maxCurrent = RMS_Value.ICH12;
	}
	
	maxInstantCurrent.feeder4 = maxCurrent;
	
	maxCurrent = RMS_Value.ICH13;
	
	if (maxCurrent < RMS_Value.ICH14 && maxCurrent > RMS_Value.ICH15) maxCurrent = RMS_Value.ICH14;
	if (maxCurrent < RMS_Value.ICH15 && maxCurrent > RMS_Value.ICH14) maxCurrent = RMS_Value.ICH15;
	if (maxCurrent < RMS_Value.ICH14 && maxCurrent < RMS_Value.ICH15)
	{
		if (RMS_Value.ICH14 > RMS_Value.ICH15) maxCurrent = RMS_Value.ICH14;
		else maxCurrent = RMS_Value.ICH15;
	}
	
	maxInstantCurrent.feeder5 = maxCurrent;
}

void pmu_checkVoltageAngle(void)
{
	if (RMS_Value.lagVAB < RMS_Value.lagVAC)
	{
		Voltage_Angle.VCH1 = 0.0;
		Voltage_Angle.VCH2 = 240.0;
		Voltage_Angle.VCH3 = 120.0;
	}
	else
	{
		Voltage_Angle.VCH1 = 0.0;
		Voltage_Angle.VCH2 = 120.0;
		Voltage_Angle.VCH3 = 240.0;
	}
}

void pmu_clearRMS_Sum_Array(void)
{
	memset(&ADC_Sum, 0, sizeof(ADC_Sum));
}
