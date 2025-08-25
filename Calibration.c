/*
 * Calibration.c
 *
 *  Created on: 13 Oca 2016
 *      Author: Serbay
 */

#include <stdint.h>
#include <stdio.h>
#include "math.h"
#include "PQ_Calculation.h"
#include "RMS_Calculation.h"
#include "ADC_Process.h"
#include "Calibration.h"



Typedef_calibrationParams  calibrationParams;




void pmu_scalingCalibrationInitSginalValue(void)
{
	calibrationParams.channelCalibrationSignalValue[0] = 220;
	calibrationParams.channelCalibrationSignalValue[1] = calibrationParams.channelCalibrationSignalValue[2] = 220;
	calibrationParams.channelCalibrationSignalValue[3] = calibrationParams.channelCalibrationSignalValue[4] = calibrationParams.channelCalibrationSignalValue[5] = 
	calibrationParams.channelCalibrationSignalValue[6] = calibrationParams.channelCalibrationSignalValue[7] = calibrationParams.channelCalibrationSignalValue[8] = 
	calibrationParams.channelCalibrationSignalValue[9] = calibrationParams.channelCalibrationSignalValue[10] = calibrationParams.channelCalibrationSignalValue[11] = 
	calibrationParams.channelCalibrationSignalValue[12] = calibrationParams.channelCalibrationSignalValue[13] = calibrationParams.channelCalibrationSignalValue[14] =
	calibrationParams.channelCalibrationSignalValue[15] = calibrationParams.channelCalibrationSignalValue[16] = calibrationParams.channelCalibrationSignalValue[17] = 1;
//	calibrationParams.channelCalibrationSignalValue[5] = 0.5;
}
	
void pmu_scalingCalibrationMean(float param)
{
	static float scalingMeanSum = 0;
	calibrationParams.scalingCounter++;
	/*if (calibrationParams.scalingIndex < 3)	
		scalingMeanSum = scalingMeanSum + (calibrationParams.calibrationSignalValue / param );
	else */
		scalingMeanSum = scalingMeanSum + (calibrationParams.channelCalibrationSignalValue[calibrationParams.scalingIndex] / param );
	
	if(calibrationParams.scalingCounter == 20000)//7500)
	{
		calibrationParams.scalingMean = scalingMeanSum / 20000;//7500;
		calibrationParams.scalingCounter = 0;
		scalingMeanSum = 0;
//		/*if (calibrationParams.scalingIndex >= 3)*/	pmu_scalingAutoCalibration();
	}
}

void pmu_offsetCalibrationMean(float param)
{

		static float offsetMeanSum = 0;
		calibrationParams.offsetCounter++;
		offsetMeanSum = offsetMeanSum + param;
		if(calibrationParams.offsetCounter == 2500)//7500)
		{
				calibrationParams.offsetMean = offsetMeanSum / 2500;//7500;
				calibrationParams.offsetCounter = 0;
				offsetMeanSum = 0;
				pmu_offsetAutoCalibration();
		}
}

int offsetResult = 0;

void pmu_offsetAutoCalibration(void)
{
	//static int offsetResult = 0;
	static uint32_t offsetCalCnt = 0;
	static int PreviousOffsetResult = 0;
	offsetCalCnt++;
	static int offsetChannelCnt = 0;
	offsetResult = fabsf(calibrationParams.offsetMean);
	//#ifdef CALIBRATION_DEBUG
	printf("Channel[%d] offset: %d \n", calibrationParams.offsetIndex, offsetResult);
	//#endif
	if (offsetChannelCnt >= 1)
	{
		if (offsetChannelCnt == 1)	PreviousOffsetResult = offsetResult;
		else 
		{	
			if (offsetResult > PreviousOffsetResult)
			{
				PreviousOffsetResult = offsetResult;
				calibrationParams.channel[calibrationParams.offsetIndex] = PreviousOffsetResult;
				printf("Channel[%d] offset bigger than previous is %d \n", calibrationParams.offsetIndex, PreviousOffsetResult);
			}
		}
	}
	offsetChannelCnt++;
	if (offsetChannelCnt == 9)
	{
		printf("Channel[%d] offset bigger than previous is %d \n", calibrationParams.offsetIndex, calibrationParams.channel[calibrationParams.offsetIndex]);
		if (calibrationParams.channel[calibrationParams.offsetIndex] != 0)	calibrationParams.offsetIndex++;
		offsetCalCnt = 0;
		if (calibrationParams.offsetIndex == 18)
		{
			calibrationParams.offsetEnable = INACTIVE;
			calibrationParams.offsetIndex = 0;
			return;
		}
		offsetChannelCnt = 0;
	}
}

int scalingResult = 0;

void pmu_scalingAutoCalibration(void)
{
	//static int scalingResult = 0;
	static uint32_t scalingCalCnt = 0;
	//static int PreviousScalingResult = 0;
	scalingCalCnt++;
	static int scalingChannelCnt = 0;
	scalingResult = fabsf(calibrationParams.scalingMean);
	//#ifdef CALIBRATION_DEBUG
	printf("Channel[%d] scaling: %f \n", calibrationParams.scalingIndex, calibrationParams.scalingMean);
	//#endif
	if (scalingChannelCnt >= 1)
	{
		//if (scalingChannelCnt == 1)	PreviousScalingResult = scalingResult;
		//else 
		if (calibrationParams.scalingIndex == 0 || calibrationParams.scalingIndex == 1 || calibrationParams.scalingIndex == 2)
		{	
			if (scalingResult >= 575 && scalingResult < 595)
			{
				//PreviousScalingResult = scalingResult;
				calibrationParams.scalingChannel[calibrationParams.scalingIndex] = calibrationParams.scalingMean;
				printf("Channel[%d] scaling bigger than previous is %f \n", calibrationParams.scalingIndex, calibrationParams.scalingMean);
			}
			else
				printf("Channel[%d] scaling is wrong. Again control  it and fix mistake \n", calibrationParams.scalingIndex);
		}
		else if (/*calibrationParams.scalingIndex == 5 || calibrationParams.scalingIndex == 6 || calibrationParams.scalingIndex == 7 || calibrationParams.scalingIndex == 8 || */
				 calibrationParams.scalingIndex == 3 || calibrationParams.scalingIndex == 4 || calibrationParams.scalingIndex == 5 || calibrationParams.scalingIndex == 6 ||
				 calibrationParams.scalingIndex == 7 || calibrationParams.scalingIndex == 8 || calibrationParams.scalingIndex == 9 || calibrationParams.scalingIndex == 10 ||
				 calibrationParams.scalingIndex == 11 || calibrationParams.scalingIndex == 12 || calibrationParams.scalingIndex == 13 || calibrationParams.scalingIndex == 14 ||
				 calibrationParams.scalingIndex == 15 || calibrationParams.scalingIndex == 16 || calibrationParams.scalingIndex == 17)
		{
			if (scalingResult >= 360 && scalingResult < 380)
			{
				//PreviousScalingResult = scalingResult;
				calibrationParams.scalingChannel[calibrationParams.scalingIndex] = calibrationParams.scalingMean;
				printf("Channel[%d] scaling bigger than previous is %f \n", calibrationParams.scalingIndex, calibrationParams.scalingMean);
			}
			else
				printf("Channel[%d] scaling is wrong. Again control  it and fix mistake \n", calibrationParams.scalingIndex);
		}
	}
	scalingChannelCnt++;
	if (scalingChannelCnt == 5)
	{
		printf("Channel[%d] scaling bigger than previous is %d \n", calibrationParams.scalingIndex, calibrationParams.channel[calibrationParams.scalingIndex]);
		/*if (calibrationParams.scalingChannel[calibrationParams.scalingIndex] != 0)	*/calibrationParams.scalingIndex++;
		scalingCalCnt = 0;
		if (calibrationParams.scalingIndex == 18)
		{
			calibrationParams.scalingEnable = INACTIVE;
			calibrationParams.scalingIndex = 0;
			scalingChannelCnt = 0;
			return;
		}
		scalingChannelCnt = 0;
	}
}

void pmu_offsetCalibration(void)
{
    switch(calibrationParams.offsetIndex)
    {
				case 0:  pmu_offsetCalibrationMean(ADC_Result.VCH1);  break;
				case 1:  pmu_offsetCalibrationMean(ADC_Result.VCH2);  break;
				case 2:  pmu_offsetCalibrationMean(ADC_Result.VCH3);  break;

				case 3:  pmu_offsetCalibrationMean(ADC_Result.ICH1);  break;
				case 4:  pmu_offsetCalibrationMean(ADC_Result.ICH2);  break;
				case 5:  pmu_offsetCalibrationMean(ADC_Result.ICH3);  break;

				case 6:  pmu_offsetCalibrationMean(ADC_Result.ICH4);  break;
				case 7:  pmu_offsetCalibrationMean(ADC_Result.ICH5);  break;
				case 8:  pmu_offsetCalibrationMean(ADC_Result.ICH6);  break;

				case 9:  pmu_offsetCalibrationMean(ADC_Result.ICH7);  break;
				case 10: pmu_offsetCalibrationMean(ADC_Result.ICH8);  break;
				case 11: pmu_offsetCalibrationMean(ADC_Result.ICH9);  break;

				case 12: pmu_offsetCalibrationMean(ADC_Result.ICH10); break;
				case 13: pmu_offsetCalibrationMean(ADC_Result.ICH11); break;
				case 14: pmu_offsetCalibrationMean(ADC_Result.ICH12); break;

				case 15: pmu_offsetCalibrationMean(ADC_Result.ICH13); break;
				case 16: pmu_offsetCalibrationMean(ADC_Result.ICH14); break;
				case 17: pmu_offsetCalibrationMean(ADC_Result.ICH15); break;
				default: break;
    }
}

void pmu_scalingCalibration(void)
{
    switch(calibrationParams.scalingIndex)
    {
				case 0:  pmu_scalingCalibrationMean(RMS_Value.VCH1);  break;
				case 1:  pmu_scalingCalibrationMean(RMS_Value.VCH2);  break;
				case 2:  pmu_scalingCalibrationMean(RMS_Value.VCH3);  break;

				case 3:  pmu_scalingCalibrationMean(RMS_Value.ICH1);  break;
				case 4:  pmu_scalingCalibrationMean(RMS_Value.ICH2);  break;
				case 5:  pmu_scalingCalibrationMean(RMS_Value.ICH3);  break;

				case 6:  pmu_scalingCalibrationMean(RMS_Value.ICH4);  break;
				case 7:  pmu_scalingCalibrationMean(RMS_Value.ICH5);  break;
				case 8:  pmu_scalingCalibrationMean(RMS_Value.ICH6);  break;

				case 9:  pmu_scalingCalibrationMean(RMS_Value.ICH7);  break;
				case 10: pmu_scalingCalibrationMean(RMS_Value.ICH8);  break;
				case 11: pmu_scalingCalibrationMean(RMS_Value.ICH9);  break;

				case 12: pmu_scalingCalibrationMean(RMS_Value.ICH10); break;
				case 13: pmu_scalingCalibrationMean(RMS_Value.ICH11); break;
				case 14: pmu_scalingCalibrationMean(RMS_Value.ICH12); break;

				case 15: pmu_scalingCalibrationMean(RMS_Value.ICH13); break;
				case 16: pmu_scalingCalibrationMean(RMS_Value.ICH14); break;
				case 17: pmu_scalingCalibrationMean(RMS_Value.ICH15); break;
				default: break;
    }
}

void pmu_runtimeCalibration()
{
    if (calibrationParams.offsetEnable == CALIBRATION_ACTIVE)
    {
        pmu_offsetCalibration();
    }

    if (calibrationParams.scalingEnable == CALIBRATION_ACTIVE)
    {
        pmu_scalingCalibration();
		pmu_scalingCalibrationInitSginalValue();
    }
}
