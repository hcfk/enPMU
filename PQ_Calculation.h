/**
  ****************************************************************************************
  * @file    PQ_Calculation.h
  * @author  Serbay Ozkan
  * @version V1.0.0
  * @date    13-November-2016
  * @brief   Microchip MCP3914 and MCP3919 External Analog-Front-End Reading Header File
  ****************************************************************************************
  */

#include "stdint.h"

#ifndef PQ_CALCULATION_H_
#define PQ_CALCULATION_H_

#define PQ_CONSTANT     0.00158478605388272583201267828843F
#define ISQRT3          0.57735026918962576450914878050195F
#define ENERGY_CONSTANT 5.5555555555555e-6F  // Normal --> 5.5555555555555e-8 Float rounding önlemek amaclı X100 yapıldı. // 200ms / 1 hour
#define RAD_TO_DEG      57.295779578552298943021782279762F
#define DEMAND_TIME     900000 /* 15 DK */

void pmu_powerParamsCalculation(void);
void pmu_P_Sum_Calculation(void);
void pmu_Q_Sum_Calculation(void);
void pmu_Q_Sum_Calculation_New(void);
void pmu_clear_PQ_Sum_Array(void);
void pmu_P_Calculation(void);
void pmu_Q_Calculation(void);
void pmu_Q_Calculation_New(void);
void pmu_S_Calculation(void);
void pmu_S_Calculation_New(void);
void pmu_PF_Calculation(void);
void pmu_PF_Calculation_New(void);
void pmu_Energy_Calculation(void);
void pmu_Energy_Calculation_New(void);
void pmu_Current_Angle_Calculation(void);
void pmu_calculateDemand(void);
void pmu_getFirstEnergyIndex(void);
void pmu_getSecondEnergyIndex(void);

typedef struct
{
   float Feeder1_A;
   float Feeder1_B;
   float Feeder1_C;

   float Feeder2_A;
   float Feeder2_B;
   float Feeder2_C;

   float Feeder3_A;
   float Feeder3_B;
   float Feeder3_C;

   float Feeder4_A;
   float Feeder4_B;
   float Feeder4_C;

   float Feeder5_A;
   float Feeder5_B;
   float Feeder5_C;

}Typedef_PowerSum;

typedef struct
{
   float Feeder1_A;
   float Feeder1_B;
   float Feeder1_C;
   float Feeder1_TOT;

   float Feeder2_A;
   float Feeder2_B;
   float Feeder2_C;
   float Feeder2_TOT;

   float Feeder3_A;
   float Feeder3_B;
   float Feeder3_C;
   float Feeder3_TOT;

   float Feeder4_A;
   float Feeder4_B;
   float Feeder4_C;
   float Feeder4_TOT;

   float Feeder5_A;
   float Feeder5_B;
   float Feeder5_C;
   float Feeder5_TOT;
}Typedef_Power;

struct struct_Energy_Calculation
{
    struct
    {
      float Feeder1_A_Import;
      float Feeder1_B_Import;
      float Feeder1_C_Import;
      float Feeder2_A_Import;
      float Feeder2_B_Import;
      float Feeder2_C_Import;
      float Feeder3_A_Import;
      float Feeder3_B_Import;
      float Feeder3_C_Import;
      float Feeder4_A_Import;
      float Feeder4_B_Import;
      float Feeder4_C_Import;
      float Feeder5_A_Import;
      float Feeder5_B_Import;
      float Feeder5_C_Import;

      float Feeder1_A_Export;
      float Feeder1_B_Export;
      float Feeder1_C_Export;
      float Feeder2_A_Export;
      float Feeder2_B_Export;
      float Feeder2_C_Export;
      float Feeder3_A_Export;
      float Feeder3_B_Export;
      float Feeder3_C_Export;
      float Feeder4_A_Export;
      float Feeder4_B_Export;
      float Feeder4_C_Export;
      float Feeder5_A_Export;
      float Feeder5_B_Export;
      float Feeder5_C_Export;
    }Active;

    struct
    {
      float Feeder1_A_Import;
      float Feeder1_B_Import;
      float Feeder1_C_Import;
      float Feeder2_A_Import;
      float Feeder2_B_Import;
      float Feeder2_C_Import;
      float Feeder3_A_Import;
      float Feeder3_B_Import;
      float Feeder3_C_Import;
      float Feeder4_A_Import;
      float Feeder4_B_Import;
      float Feeder4_C_Import;
      float Feeder5_A_Import;
      float Feeder5_B_Import;
      float Feeder5_C_Import;

      float Feeder1_A_Export;
      float Feeder1_B_Export;
      float Feeder1_C_Export;
      float Feeder2_A_Export;
      float Feeder2_B_Export;
      float Feeder2_C_Export;
      float Feeder3_A_Export;
      float Feeder3_B_Export;
      float Feeder3_C_Export;
      float Feeder4_A_Export;
      float Feeder4_B_Export;
      float Feeder4_C_Export;
      float Feeder5_A_Export;
      float Feeder5_B_Export;
      float Feeder5_C_Export;
    }Reactive;
};

struct struct_Energy_Calculation_Tot
{
    struct
    {
      uint32_t Feeder1_A_Import;
      uint32_t Feeder1_B_Import;
      uint32_t Feeder1_C_Import;
      uint32_t Feeder1_Import_TOT;

      uint32_t Feeder2_A_Import;
      uint32_t Feeder2_B_Import;
      uint32_t Feeder2_C_Import;
      uint32_t Feeder2_Import_TOT;

      uint32_t Feeder3_A_Import;
      uint32_t Feeder3_B_Import;
      uint32_t Feeder3_C_Import;
      uint32_t Feeder3_Import_TOT;

      uint32_t Feeder4_A_Import;
      uint32_t Feeder4_B_Import;
      uint32_t Feeder4_C_Import;
      uint32_t Feeder4_Import_TOT;

      uint32_t Feeder5_A_Import;
      uint32_t Feeder5_B_Import;
      uint32_t Feeder5_C_Import;
      uint32_t Feeder5_Import_TOT;

      uint32_t Feeder1_A_Export;
      uint32_t Feeder1_B_Export;
      uint32_t Feeder1_C_Export;
      uint32_t Feeder1_Export_TOT;

      uint32_t Feeder2_A_Export;
      uint32_t Feeder2_B_Export;
      uint32_t Feeder2_C_Export;
      uint32_t Feeder2_Export_TOT;

      uint32_t Feeder3_A_Export;
      uint32_t Feeder3_B_Export;
      uint32_t Feeder3_C_Export;
      uint32_t Feeder3_Export_TOT;

      uint32_t Feeder4_A_Export;
      uint32_t Feeder4_B_Export;
      uint32_t Feeder4_C_Export;
      uint32_t Feeder4_Export_TOT;

      uint32_t Feeder5_A_Export;
      uint32_t Feeder5_B_Export;
      uint32_t Feeder5_C_Export;
      uint32_t Feeder5_Export_TOT;
    }Active;

    struct
    {
      uint32_t Feeder1_A_Import;
      uint32_t Feeder1_B_Import;
      uint32_t Feeder1_C_Import;
      uint32_t Feeder1_Import_TOT;

      uint32_t Feeder2_A_Import;
      uint32_t Feeder2_B_Import;
      uint32_t Feeder2_C_Import;
      uint32_t Feeder2_Import_TOT;

      uint32_t Feeder3_A_Import;
      uint32_t Feeder3_B_Import;
      uint32_t Feeder3_C_Import;
      uint32_t Feeder3_Import_TOT;

      uint32_t Feeder4_A_Import;
      uint32_t Feeder4_B_Import;
      uint32_t Feeder4_C_Import;
      uint32_t Feeder4_Import_TOT;

      uint32_t Feeder5_A_Import;
      uint32_t Feeder5_B_Import;
      uint32_t Feeder5_C_Import;
      uint32_t Feeder5_Import_TOT;

      uint32_t Feeder1_A_Export;
      uint32_t Feeder1_B_Export;
      uint32_t Feeder1_C_Export;
      uint32_t Feeder1_Export_TOT;

      uint32_t Feeder2_A_Export;
      uint32_t Feeder2_B_Export;
      uint32_t Feeder2_C_Export;
      uint32_t Feeder2_Export_TOT;

      uint32_t Feeder3_A_Export;
      uint32_t Feeder3_B_Export;
      uint32_t Feeder3_C_Export;
      uint32_t Feeder3_Export_TOT;

      uint32_t Feeder4_A_Export;
      uint32_t Feeder4_B_Export;
      uint32_t Feeder4_C_Export;
      uint32_t Feeder4_Export_TOT;

      uint32_t Feeder5_A_Export;
      uint32_t Feeder5_B_Export;
      uint32_t Feeder5_C_Export;
      uint32_t Feeder5_Export_TOT;
    }Reactive;
};

typedef struct
{
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
}Typedef_Current_Ang;

typedef struct
{
    float VCH1;
    float VCH2;
    float VCH3;
}Typedef_Voltage_Ang;

typedef struct{

	uint32_t feeder1;
	uint32_t feeder2;
	uint32_t feeder3;
	uint32_t feeder4;
	uint32_t feeder5;
	uint32_t timerCnt;
	uint8_t timerFlag;
	uint32_t firstEnergyIndex[5];
	uint32_t secondEnergyIndex[5];
	uint8_t  runTimeFlag;
}Typedef_demandParams;


extern Typedef_Power    P;
extern Typedef_Power    Q;
extern Typedef_Power    Q_New;
extern Typedef_Power    S;
extern Typedef_Power    S_New;
extern Typedef_Power    PF;
extern Typedef_Power    PF_New;
extern Typedef_Current_Ang Current_Angle;
extern Typedef_Voltage_Ang Voltage_Angle;
extern Typedef_demandParams  demandParams;
extern struct struct_Energy_Calculation Energy;
extern struct struct_Energy_Calculation_Tot Energy_Total;
#endif /* PQ_CALCULATION_H_ */
