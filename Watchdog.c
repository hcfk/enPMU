
#include "stm32f4xx_hal.h"
#include "crc.h"
#include "dma.h"
#include "rtc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "usb_otg.h"
#include "gpio.h"
#include "stm32f4xx_hal_iwdg.h"
#include "Watchdog.h"

IWDG_HandleTypeDef IwdgHandle;
TIM_HandleTypeDef  TimInputCaptureHandle;
RCC_ClkInitTypeDef RCC_ClockFreq;

static __IO uint32_t uwLsiFreq = 0;
__IO uint32_t uwCaptureNumber = 0;
__IO uint32_t uwPeriodValue = 0;
__IO uint32_t uwMeasurementDone = 0;

/**
  * @brief  Configures TIM5 to measure the LSI oscillator frequency. 
  * @param  None
  * @retval LSI Frequency
  */
uint32_t GetLSIFrequency(void)
{
  uint32_t pclk1 = 0;
  TIM_IC_InitTypeDef timinputconfig;  
  
  /* Enable the LSI oscillator */
  __HAL_RCC_LSI_ENABLE();
  
  /* Wait till LSI is ready */
  while (__HAL_RCC_GET_FLAG(RCC_FLAG_LSIRDY) == RESET)
  {
  }
  
  /* Configure the TIM peripheral */ 
  /* Set TIM5 instance */  
  TimInputCaptureHandle.Instance = TIM5;
  
  /* TIM5 configuration: Input Capture mode ---------------------
  The LSI oscillator is connected to TIM5 CH4.
  The Rising edge is used as active edge.
  The TIM5 CCR4 is used to compute the frequency value. 
  ------------------------------------------------------------ */
  TimInputCaptureHandle.Init.Prescaler         = 0; 
  TimInputCaptureHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;  
  TimInputCaptureHandle.Init.Period            = 0xFFFF; 
  TimInputCaptureHandle.Init.ClockDivision     = 0;     
  TimInputCaptureHandle.Init.RepetitionCounter = 0; 
  
  if(HAL_TIM_IC_Init(&TimInputCaptureHandle) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }
  /* Connect internally the TIM5_CH4 Input Capture to the LSI clock output */
  HAL_TIMEx_RemapConfig(&TimInputCaptureHandle, TIM_TIM5_LSI);
  
  /* Configure the Input Capture of channel 4 */
  timinputconfig.ICPolarity  = TIM_ICPOLARITY_RISING;
  timinputconfig.ICSelection = TIM_ICSELECTION_DIRECTTI;
  timinputconfig.ICPrescaler = TIM_ICPSC_DIV8;
  timinputconfig.ICFilter    = 0;
  
  if(HAL_TIM_IC_ConfigChannel(&TimInputCaptureHandle, &timinputconfig, TIM_CHANNEL_4) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }
  
  /* Reset the flags */
  TimInputCaptureHandle.Instance->SR = 0;
  
  /* Start the TIM Input Capture measurement in interrupt mode */
  if(HAL_TIM_IC_Start_IT(&TimInputCaptureHandle, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  
  /* Wait until the TIM5 get 2 LSI edges (refer to TIM5_IRQHandler() in 
  stm32f4xx_it.c file) */
  while(uwMeasurementDone == 0)
  {
  }
  uwCaptureNumber = 0;
  
  /* Deinitialize the TIM5 peripheral registers to their default reset values */
  HAL_TIM_IC_DeInit(&TimInputCaptureHandle);
  
  /* Compute the LSI frequency, depending on TIM5 input clock frequency (PCLK1)*/
  /* Get PCLK1 frequency */
  pclk1 = HAL_RCC_GetPCLK1Freq();
  
  /* Get PCLK1 prescaler */
  if((RCC->CFGR & RCC_CFGR_PPRE1) == 0)
  { 
    /* PCLK1 prescaler equal to 1 => TIMCLK = PCLK1 */
    return ((pclk1 / uwPeriodValue) * 8);
  }
  else
  { 
    /* PCLK1 prescaler different from 1 => TIMCLK = 2 * PCLK1 */
    return (((2 * pclk1) / uwPeriodValue) * 8);
  }
}

void pmu_watchdogStartUp(void)
{
	uwLsiFreq = GetLSIFrequency();
	
	IwdgHandle.Instance = IWDG;

  IwdgHandle.Init.Prescaler = IWDG_PRESCALER_32;
  // IwdgHandle.Init.Reload    = uwLsiFreq / 2;
  IwdgHandle.Init.Reload    = 0XFFE;
	
  if(HAL_IWDG_Init(&IwdgHandle) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }
}

void pmu_watchdogKickDog(void)
{
	if(HAL_IWDG_Refresh(&IwdgHandle) != HAL_OK)
    {
      /* Refresh Error */
      Error_Handler();
    }
}
