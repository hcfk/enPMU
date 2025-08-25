/**
  ****************************************************************************************
  * @file    AdcProcess.h
  * @author  Serbay Ozkan
  * @version V1.0.0
  * @date    13-November-2016
  * @brief   Microchip MCP3914 and MCP3919 External Analog-Front-End Reading Header File
  ****************************************************************************************
  */

#include "stdint.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"

#ifndef WATCHDOG_H_
#define WATCHDOG_H_

extern __IO uint32_t uwPeriodValue;
extern __IO uint32_t uwCaptureNumber;
extern __IO uint32_t uwMeasurementDone;

uint32_t GetLSIFrequency(void);
void pmu_watchdogStartUp(void);
void pmu_watchdogKickDog(void);

extern uint32_t GetLSIFrequency(void);
extern void pmu_watchdogStartUp(void);
extern void pmu_watchdogKickDog(void);
#endif /* WATCHDOG */
