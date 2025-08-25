
#include "stm32f4xx_hal.h"
#include "stdint.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"
#include "arm_math.h"
#include "FFT.h"
#include "math.h"

Typedef_fftParams     fftParams;
Typedef_fftTestParams fftTestParams;
Typedef_thdParams     thdParams;

arm_cfft_radix4_instance_f32 S_FFT;	/* ARM CFFT module */

int i = 0;
void fft_processFFTFunctions(float adcInputBuffer[])
{
    if (fftParams.fftEnable == 1)
    {
      arm_cfft_radix4_init_f32(&S_FFT, FFT_SIZE, 0, 1);
      arm_cfft_radix4_f32(&S_FFT, adcInputBuffer);
      arm_cmplx_mag_f32(adcInputBuffer, fftParams.OutputBuffer, FFT_SIZE);
      arm_max_f32(fftParams.OutputBuffer, FFT_SIZE, &fftParams.maxValue, &fftParams.maxIndex);
    }
}

void fft_generateTestSignal(void)
{
    #if 0
    if (fftTestParams.testSignalEnable == 1)
    {
      for(int i = 0; i < SAMPLES; i += 2)
      {
        fftTestParams.testInputBuffer[i] = fftTestParams.signalMagnitude[0] * sin(2 * PI * fftTestParams.signalFrequency[0] * i *   fftTestParams.timeConstant )
        + fftTestParams.signalMagnitude[1] * sin(2 * PI * fftTestParams.signalFrequency[1] * i *   fftTestParams.timeConstant ) +
          fftTestParams.signalMagnitude[2] * sin(2 * PI * fftTestParams.signalFrequency[2] * i *   fftTestParams.timeConstant );
        fftTestParams.testInputBuffer[i+1] = 0;
      }

      fft_processFFTFunctions(fftTestParams.testInputBuffer);

      //fftTestParams.testSignalEnable = 0;
      fft_calculateTHD();
    }
		
		#endif
		
		#if 1
		if (fftTestParams.testSignalEnable == 1)
    {
     
        fftTestParams.testInputBuffer[i] = fftTestParams.signalMagnitude[0] * sin(2 * PI * fftTestParams.signalFrequency[0] * i *   fftTestParams.timeConstant )
        + fftTestParams.signalMagnitude[1] * sin(2 * PI * fftTestParams.signalFrequency[1] * i *   fftTestParams.timeConstant ) +
          fftTestParams.signalMagnitude[2] * sin(2 * PI * fftTestParams.signalFrequency[2] * i *   fftTestParams.timeConstant );
        fftTestParams.testInputBuffer[i+1] = 0;
			  i += 2;
        if (i == SAMPLES)
				{
					fft_processFFTFunctions(fftTestParams.testInputBuffer);
					fft_calculateTHD();
					i = 0;
				}
     

      

      //fftTestParams.testSignalEnable = 0;
      
    }
		#endif
		

}

void fft_calculateTHD(void)
{
   fftParams.fftSize = FFT_SIZE;
   fftParams.sampleRate = TEST_SAMPLE_RATE;
   thdParams.totalFFTBin = (float)(fftParams.sampleRate / fftParams.fftSize);
   thdParams.fundCompIndex = (uint32_t)(50 / thdParams.totalFFTBin);

   for(int i = 2 * thdParams.fundCompIndex; i < FFT_SIZE / 2; i += thdParams.fundCompIndex)
   {
     thdParams.THD_Sum += fftParams.OutputBuffer[i] * fftParams.OutputBuffer[i];
   }
   thdParams.THD = (__sqrtf(thdParams.THD_Sum) / fftParams.OutputBuffer[thdParams.fundCompIndex])*100;
   thdParams.THD_Sum = 0;
}
