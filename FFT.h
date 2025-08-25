/**
  ******************************************************************************
  * @file    FFT.h
  * @author  Serbay Ozkan
  * @version V1.0.0
  * @date    13-November-2016
  * @brief   Includes FFT function prototypes and variables
  ******************************************************************************
  */

#include "stdint.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"

#ifndef FFT_H_
#define FFT_H_

#define SAMPLES         128
#define FFT_SIZE        SAMPLES / 2
#define PI_CONSTANT     3.14159265359F

/************************** FFT TEST FUNCTION MACROS **************************/
#define TEST_SAMPLE_RATE     3200
#define TIME_CONSTANT        1.5847860538827258320126782884311e-4F      /* 1 / TIME_CONSTANT * 2 */
/******************************************************************************/

typedef struct
{
  uint32_t  maxIndex;
  float32_t maxValue;
  float     inputBuffer[SAMPLES];
  float     OutputBuffer[FFT_SIZE];
  uint32_t   sampleRate;
  uint32_t   fftSize;
  uint16_t  fftEnable;
}Typedef_fftParams;

typedef struct
{
  float      testInputBuffer[SAMPLES];
  float      signalMagnitude[3];
  float      signalFrequency[3];
  float      timeConstant;
  uint32_t   testBufferIndex;
  uint16_t   testSignalEnable;
}Typedef_fftTestParams;

typedef struct
{
  float    ICH1;
  float    THD_Sum;
  float    THD;
  float    totalFFTBin;
  uint32_t fundCompIndex;
}Typedef_thdParams;

void fft_processFFTFunctions(float adcInputBuffer[]);
void fft_generateTestSignal(void);
void fft_calculateTHD(void);

extern void fft_processFFTFunctions(float adcInputBuffer[]);
extern void fft_generateTestSignal(void);
extern void fft_calculateTHD(void);

extern Typedef_fftParams     fftParams;
extern Typedef_fftTestParams fftTestParams;
extern Typedef_thdParams     thdParams;
#endif /* FFT */
