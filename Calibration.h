/*
 * Calibration.h
 *
 *  Created on: 16 Ara 2015
 *      Author: Serbay
 */

#ifndef ENERGY_METER_CALIBRATION_H_
#define ENERGY_METER_CALIBRATION_H_
#include "stdint.h"

#define CALIBRATION_ACTIVE 1

void pmu_offsetCalibration(void);
void pmu_offsetAutoCalibration(void);
void pmu_scalingCalibration(void);
void pmu_scalingCalibrationMean(float param);
void pmu_offsetCalibrationMean(float param);
void pmu_runtimeCalibration(void);
void pmu_offsetAutoCalibration(void);
void pmu_scalingAutoCalibration(void);

typedef struct
{
	uint32_t offsetIndex;
	uint32_t offsetCounter;
	float    offsetMean;
	uint8_t  offsetEnable;
	uint32_t scalingIndex;
	uint32_t scalingCounter;
	float    scalingMean;
	float    calibrationSignalValue;
	uint8_t  scalingEnable;
	int 	 channel[18];
	float 	 scalingChannel[18];
	float    channelCalibrationSignalValue[18];
}Typedef_calibrationParams;

extern Typedef_calibrationParams  calibrationParams;

#define TEST 0
#define EM1 1
#define EM2 2
#define EM3 3
#define EM4 4
#define EM5 5
#define EM6 6
#define EM7 7
#define EM8 8
#define EM9 9
#define EM10 10
#define EM11 11
#define EM12 12
#define EM13 13
#define EM14 14
#define TEST0 15
#define INFLEXPMU1 16
#define INFLEXPMU2 17
#define INFLEXPMU3 18
#define INFLEXPMU4 19
#define INFLEXPMU5 20
#define INFLEXPMU6 21
#define INFLEXPMU7 22
#define INFLEXPMU8 23
#define INFLEXPMU9 24
#define INFLEXPMU_TEST 25
#define INFLEXPMU8_SOK 26
#define INFLEXPMU9_SOK 27

#define ENERJISA1      28
#define ENERJISA2      29
#define ENERJISA3      30
#define ENERJISA4      31
#define ENERJISA5      32
#define ENERJISA6      33
#define ENERJISA7      34
#define ENERJISA8      35
#define ENERJISA9      36
#define ENERJISA10      37
#define ENERJISA11      38
#define ENERJISA12      39
#define ENERJISA13      40
#define ENERJISA14      41
#define ENERJISA15      42
#define ENERJISA16      43
#define ENERJISA17      44
#define ENERJISA18      45
#define ENERJISA19      46
#define ENERJISA20      47
#define ENERJISA21      48
#define ENERJISA22      49
#define ENERJISA23      50
#define ENERJISA24      51
#define ENERJISA25      52

#define PMU1  53
#define PMU2  54
#define PMU3  55
#define PMU4  56
#define PMU5  57
#define PMU6  58
#define PMU7  59
#define PMU8  60
#define PMU9  61
#define PMU10 62
#define PMU11 63
#define PMU12 64
#define PMU13 65
#define PMU14 66
#define PMU15 67

#define ENDOKS3 68
#define ENDOKS7 69
#define ENDOKS9 70

#define BEDAS_PMU1 71
#define ARAS_PMU1 72

#define PMU16 73
#define PMU17 74
#define PMU18 75
#define PMU19 76
#define PMU20 77
#define PMU21 78
#define PMU22 79
#define PMU23 80
#define PMU24 81
#define PMU25 82
#define PMU26 83
#define PMU27 84
#define PMU28 85
#define PMU29 86
#define PMU30 87
#define PMU31 88
#define PMU32 89
#define PMU33 90
#define PMU5x 91
#define PMU6x 92
#define PMU7x 93
#define PMU34 94
#define PMU35 95
#define PMU36 96
#define PMU37 97
#define PMU38 98
#define PMU4xx 99
#define PMU6xx 100
#define PMU7xx 101
#define PMU39 102
#define PMU40 103
#define PMU41 104
#define PMU42 105
#define PMU43 106
#define PMU44 107
#define PMU45 108
#define PMU46 109
#define PMU47 110
#define PMU48 111
#define PMU49 112
#define PMU50 113
#define PMU51 114
#define PMU52 115
#define PMU53 116
#define PMU54 117
#define PMU55 118
#define PMU56 119
#define PMU57 120
#define PMU58 121
#define PMU59 122
#define PMU60 123
#define PMU61 124
#define PMU62 125
#define PMU63 126
#define PMU64 127
#define PMU65 128
#define PMU66 129
#define PMU67 130
#define PMU68 131
#define PMU69 132
#define PMU70 133
#define PMU71 134
#define PMU72 135
#define PMU73 136
#define PMU74 137
#define PMU75 138
#define PMU76 139
#define PMU77 140
#define PMU78 141
#define PMU79 142
#define PMU80 143
#define PMU81 144
#define PMU82 145
#define PMU83 146
#define PMU84 147
#define PMU85 148
#define PMU86 149
#define PMU87 150
#define PMU88 151
#define PMU89 152
#define PMU90 153
#define PMU91 154
#define PMU92 155
#define PMU93 156
#define PMU94 157
#define PMU95 158
#define PMU96 159
#define PMU97 160
#define PMU98 161
#define PMU99 162
#define PMU100 163
#define PMU101 164
#define PMU102 165
#define PMU103 166
#define PMU104 167
#define PMU105 168
#define PMU106 169
#define PMU107 170
#define PMU108 171
#define PMU109 172
#define PMU110 173
#define PMU111 174
#define PMU112 175
#define PMU113 176
#define PMU114 177
#define PMU115 178
#define PMU116 179
#define PMU117 180
#define PMU118 181
#define PMU119 182
#define PMU120 183
#define PMU121 184
#define PMU122 185
#define PMU123 186
#define PMU124 187
#define PMU125 188
#define PMU126 189
#define PMU127 190
#define PMU128 191
#define PMU129 192
#define PMU130 193
#define PMU131 194
#define PMU132 195
#define PMU133 196
#define PMU134 197
#define PMU135 198
#define PMU136 199
#define PMU137 200
#define PMU138 201
#define PMU139 202
#define PMU140 203
#define PMU141 204
#define PMU142 205
#define PMU143 206
#define PMU144 207
#define PMU145 208
#define PMU146 209
#define PMU147 210
#define PMU148 211
#define PMU149 212
#define PMU150 213
#define PMU151 214
#define PMU152 215
#define PMU153 216
#define PMU154 217
#define PMU155 218
#define PMU156 219
#define PMU157 220
#define PMU158 221
#define PMU159 222
#define PMU160 223
#define PMU161 224
#define PMU162 225
#define PMU163 226
#define PMU164 227
#define PMU165 228
#define PMU166 229
#define PMU167 230
#define PMU168 231
#define PMU169 232
#define PMU170 233
#define PMU171 234
#define PMU172 235
#define PMU173 236
#define PMU174 237
#define PMU175 238
#define PMU176 239
#define PMU177 240
#define PMU178 241
#define PMU179 242
#define PMU180 243
#define PMU181 244
#define PMU182 245
#define PMU183 246
#define PMU184 247
#define PMU185 248
#define PMU186 249
#define PMU187 250
#define PMU188 251
#define PMU189 252
#define PMU190 253
#define PMU191 254
#define PMU192 255
#define PMU193 256
#define PMU194 257
#define PMU195 258
#define PMU196 259
#define PMU197 260
#define PMU198 261
#define PMU199 262
#define PMU200 263
#define PMU201 264
#define PMU202 265
#define PMU203 266
#define PMU204 267
#define PMU205 268
#define PMU206 269
#define PMU207 270
#define PMU208 271
#define PMU209 272
#define PMU210 273
#define PMU211 274
#define PMU212 275
#define PMU213 276
#define PMU214 277
#define PMU215 278
#define PMU216 279
#define PMU217 280
#define PMU218 281
#define PMU219 282
#define PMU220 283
#define PMU221 284
#define PMU222 285
#define PMU223 286
#define PMU224 287
#define PMU225 288
#define PMU226 289
#define PMU227 290
#define PMU228 291
#define PMU229 292
#define PMU230 293
#define PMU231 294
#define PMU232 295
#define PMU233 296
#define PMU234 297
#define PMU235 298
#define PMU236 299
#define PMU237 300
#define PMU238 301
#define PMU239 302
#define PMU240 303
#define PMU241 304
#define PMU242 305
#define PMU243 306
#define PMU244 307
#define PMU245 308

#define Calibration_Index  PMU229

#if Calibration_Index == BEDAS_PMU1 
// OFFSET Calibration

// OFFSET Calibration
#define VCH1_OFFSET 1031160
#define VCH2_OFFSET 1359293
#define VCH3_OFFSET 1681427

#define ICH1_OFFSET 1934679
#define ICH2_OFFSET 1693448
#define ICH3_OFFSET 1628059
#define ICH4_OFFSET 1702285
#define ICH5_OFFSET 1491866
#define ICH6_OFFSET 1638015
#define ICH7_OFFSET 2815446
#define ICH8_OFFSET 1272438
#define ICH9_OFFSET 863619
#define ICH10_OFFSET 347256
#define ICH11_OFFSET 1425181
#define ICH12_OFFSET 1845772
#define ICH13_OFFSET 1453156
#define ICH14_OFFSET 1685403
#define ICH15_OFFSET 2028665

//SCALING Calibration
#define VCH1_SCALE 585.696228f
#define VCH2_SCALE 583.793335f
#define VCH3_SCALE 583.776917f
                  
#define ICH1_SCALE 378.324158f
#define ICH2_SCALE 377.962708f
#define ICH3_SCALE 378.562592f
#define ICH4_SCALE 378.638428f
#define ICH5_SCALE 377.756439f
#define ICH6_SCALE 377.42511f
#define ICH7_SCALE 378.408875f
#define ICH8_SCALE 379.22644f
#define ICH9_SCALE 378.413605f
#define ICH10_SCALE 378.328979f
#define ICH11_SCALE 378.961273f
#define ICH12_SCALE 379.761139f
#define ICH13_SCALE 379.06781f
#define ICH14_SCALE 379.311676f
#define ICH15_SCALE 378.082825f

#endif


#if Calibration_Index == ENDOKS9 
// OFFSET Calibration

#define VCH1_OFFSET 1113780
#define VCH2_OFFSET 1264889
#define VCH3_OFFSET 1749567
                   
#define ICH1_OFFSET 1645214
#define ICH2_OFFSET 1597858
#define ICH3_OFFSET 1618004
#define ICH4_OFFSET 1529104
#define ICH5_OFFSET 1700991
#define ICH6_OFFSET 1776901
#define ICH7_OFFSET 2764579
#define ICH8_OFFSET 1158680
#define ICH9_OFFSET 480905
#define ICH10_OFFSET 488861
#define ICH11_OFFSET 1423582
#define ICH12_OFFSET 1353542
#define ICH13_OFFSET 1511917
#define ICH14_OFFSET 1649305
#define ICH15_OFFSET 1794321

//SCALING Calibration
#define VCH1_SCALE 585.696228f
#define VCH2_SCALE 583.793335f
#define VCH3_SCALE 583.776917f
                  
#define ICH1_SCALE 378.324158f
#define ICH2_SCALE 377.962708f
#define ICH3_SCALE 378.562592f
#define ICH4_SCALE 378.638428f
#define ICH5_SCALE 377.756439f
#define ICH6_SCALE 377.42511f
#define ICH7_SCALE 378.408875f
#define ICH8_SCALE 379.22644f
#define ICH9_SCALE 378.413605f
#define ICH10_SCALE 378.328979f
#define ICH11_SCALE 378.961273f
#define ICH12_SCALE 379.761139f
#define ICH13_SCALE 379.06781f
#define ICH14_SCALE 379.311676f
#define ICH15_SCALE 378.082825f

#endif





#if Calibration_Index == ENDOKS7 
// OFFSET Calibration

#define VCH1_OFFSET 815440
#define VCH2_OFFSET 1239542
#define VCH3_OFFSET 1654547
                   
#define ICH1_OFFSET 1640836
#define ICH2_OFFSET 1606790
#define ICH3_OFFSET 1742056
#define ICH4_OFFSET 1717009
#define ICH5_OFFSET 1665358
#define ICH6_OFFSET 1589134
#define ICH7_OFFSET 3021530
#define ICH8_OFFSET 1569862
#define ICH9_OFFSET 405269
#define ICH10_OFFSET 423727
#define ICH11_OFFSET 1482573
#define ICH12_OFFSET 1567988
#define ICH13_OFFSET 2043289
#define ICH14_OFFSET 1818045
#define ICH15_OFFSET 1996601

//SCALING Calibration
#define VCH1_SCALE 581.629028f
#define VCH2_SCALE 583.697571f
#define VCH3_SCALE 582.599731f
                  
#define ICH1_SCALE 377.903687f
#define ICH2_SCALE 378.37619f
#define ICH3_SCALE 377.29129f
#define ICH4_SCALE 378.029236f
#define ICH5_SCALE 376.983978f
#define ICH6_SCALE 377.519928f
#define ICH7_SCALE 377.61203f
#define ICH8_SCALE 379.424438f
#define ICH9_SCALE 378.399139f
#define ICH10_SCALE 379.83548f
#define ICH11_SCALE 379.14624f
#define ICH12_SCALE 379.218231f
#define ICH13_SCALE 379.326813f
#define ICH14_SCALE 378.986633f
#define ICH15_SCALE 378.623627f

#endif




#if Calibration_Index == ENDOKS3 
// OFFSET Calibration

#define VCH1_OFFSET 704314
#define VCH2_OFFSET 1176965
#define VCH3_OFFSET 1370051

#define ICH1_OFFSET 1580546
#define ICH2_OFFSET 1521465
#define ICH3_OFFSET 1530907
#define ICH4_OFFSET 1474727
#define ICH5_OFFSET 1605966
#define ICH6_OFFSET 1745621
#define ICH7_OFFSET 2709068
#define ICH8_OFFSET 1523587
#define ICH9_OFFSET 594548
#define ICH10_OFFSET 34221
#define ICH11_OFFSET 1449060
#define ICH12_OFFSET 1502216
#define ICH13_OFFSET 1636631
#define ICH14_OFFSET 1770354
#define ICH15_OFFSET 1835305

//SCALING Calibration
#define VCH1_SCALE 584.853027f
#define VCH2_SCALE 582.815063f
#define VCH3_SCALE 584.710449f

#define ICH1_SCALE 373.54834f
#define ICH2_SCALE 373.656586f
#define ICH3_SCALE 372.643219f
#define ICH4_SCALE 373.438507f
#define ICH5_SCALE 374.542694f
#define ICH6_SCALE 373.861206f
#define ICH7_SCALE 373.710205f
#define ICH8_SCALE 374.26236f
#define ICH9_SCALE 371.947845f
#define ICH10_SCALE 373.118958f
#define ICH11_SCALE 373.595795f
#define ICH12_SCALE 373.920105f
#define ICH13_SCALE 373.319061f
#define ICH14_SCALE 373.03598f
#define ICH15_SCALE 373.354645f

#endif

#if Calibration_Index == TEST8
// OFFSET Calibration
#define VCH1_OFFSET (uint32_t) bufferOffset[0]
#define VCH2_OFFSET (uint32_t) bufferOffset[1]
#define VCH3_OFFSET (uint32_t) bufferOffset[2]
#define ICH1_OFFSET (uint32_t) bufferOffset[3]
#define ICH2_OFFSET (uint32_t) bufferOffset[4]
#define ICH3_OFFSET (uint32_t) bufferOffset[5]
#define ICH4_OFFSET (uint32_t) bufferOffset[6]
#define ICH5_OFFSET (uint32_t) bufferOffset[7]
#define ICH6_OFFSET (uint32_t) bufferOffset[8]
#define ICH7_OFFSET (uint32_t) bufferOffset[9]
#define ICH8_OFFSET (uint32_t) bufferOffset[10]
#define ICH9_OFFSET (uint32_t) bufferOffset[11]
#define ICH10_OFFSET (uint32_t) bufferOffset[12]
#define ICH11_OFFSET (uint32_t) bufferOffset[13]
#define ICH12_OFFSET (uint32_t) bufferOffset[14]
#define ICH13_OFFSET (uint32_t) bufferOffset[15]
#define ICH14_OFFSET (uint32_t) bufferOffset[16]
#define ICH15_OFFSET (uint32_t) bufferOffset[17]
#define ICH16_OFFSET (uint32_t) bufferOffset[18]
#define ICH17_OFFSET (uint32_t) bufferOffset[19]
#define ICH18_OFFSET (uint32_t) bufferOffset[20]
#define ICH19_OFFSET (uint32_t) bufferOffset[21]
#define ICH20_OFFSET (uint32_t) bufferOffset[22]
#define ICH21_OFFSET (uint32_t) bufferOffset[23]
#define ICH22_OFFSET (uint32_t) bufferOffset[24]
#define ICH23_OFFSET (uint32_t) bufferOffset[25]
#define ICH24_OFFSET (uint32_t) bufferOffset[26]
#define ICH25_OFFSET (uint32_t) bufferOffset[27]
#define ICH26_OFFSET (uint32_t) bufferOffset[28]
#define ICH27_OFFSET (uint32_t) bufferOffset[29]
#define ICH28_OFFSET (uint32_t) bufferOffset[30]
#define ICH29_OFFSET (uint32_t) bufferOffset[31]
#define ICH29_OFFSET (uint32_t) bufferOffset[31]
#define ICH30_OFFSET (uint32_t) bufferOffset[32]

//SCALING Calibration
#define VCH1_SCALE bufferScale[0]
#define VCH2_SCALE bufferScale[1]
#define VCH3_SCALE bufferScale[2]

#define ICH1_SCALE bufferScale[3]
#define ICH2_SCALE bufferScale[4]
#define ICH3_SCALE bufferScale[5]
#define ICH4_SCALE bufferScale[6]
#define ICH5_SCALE bufferScale[7]
#define ICH6_SCALE bufferScale[8]
#define ICH7_SCALE bufferScale[9]
#define ICH8_SCALE bufferScale[10]
#define ICH9_SCALE bufferScale[11]
#define ICH10_SCALE bufferScale[12]
#define ICH11_SCALE bufferScale[13]
#define ICH12_SCALE bufferScale[14]
#define ICH13_SCALE bufferScale[15]
#define ICH14_SCALE bufferScale[16]
#define ICH15_SCALE bufferScale[17]
#define ICH16_SCALE bufferScale[18]
#define ICH17_SCALE bufferScale[19]
#define ICH18_SCALE bufferScale[20]
#define ICH19_SCALE bufferScale[21]
#define ICH20_SCALE bufferScale[22]
#define ICH21_SCALE bufferScale[23]
#define ICH22_SCALE bufferScale[24]
#define ICH23_SCALE bufferScale[25]
#define ICH24_SCALE bufferScale[26]
#define ICH25_SCALE bufferScale[27]
#define ICH26_SCALE bufferScale[28]
#define ICH27_SCALE bufferScale[29]
#define ICH28_SCALE bufferScale[30]
#define ICH29_SCALE bufferScale[31]
#define ICH30_SCALE bufferScale[32]
#endif


#if Calibration_Index == TEST0
// OFFSET Calibration
#define VCH1_OFFSET 0
#define VCH2_OFFSET 0
#define VCH3_OFFSET 0

#define ICH1_OFFSET 0
#define ICH2_OFFSET 0
#define ICH3_OFFSET 0
#define ICH4_OFFSET 0
#define ICH5_OFFSET 0
#define ICH6_OFFSET 0
#define ICH7_OFFSET 0
#define ICH8_OFFSET 0
#define ICH9_OFFSET 0
#define ICH10_OFFSET 0
#define ICH11_OFFSET 0
#define ICH12_OFFSET 0
#define ICH13_OFFSET 0
#define ICH14_OFFSET 0
#define ICH15_OFFSET 0
#define ICH16_OFFSET 0
#define ICH17_OFFSET 0
#define ICH18_OFFSET 0
#define ICH19_OFFSET 0
#define ICH20_OFFSET 0
#define ICH21_OFFSET 0
#define ICH22_OFFSET 0
#define ICH23_OFFSET 0
#define ICH24_OFFSET 0
#define ICH25_OFFSET 0
#define ICH26_OFFSET 0
#define ICH27_OFFSET 0
#define ICH28_OFFSET 0
#define ICH29_OFFSET 0
#define ICH30_OFFSET 0


//SCALING Calibration
#define VCH1_SCALE 1
#define VCH2_SCALE 1
#define VCH3_SCALE 1

#define ICH1_SCALE 1
#define ICH2_SCALE 1
#define ICH3_SCALE 1
#define ICH4_SCALE 1
#define ICH5_SCALE 1
#define ICH6_SCALE 1
#define ICH7_SCALE 1
#define ICH8_SCALE 1
#define ICH9_SCALE 1
#define ICH10_SCALE 1
#define ICH11_SCALE 1
#define ICH12_SCALE 1
#define ICH13_SCALE 1
#define ICH14_SCALE 1
#define ICH15_SCALE 1
#define ICH16_SCALE 1
#define ICH17_SCALE 1
#define ICH18_SCALE 1
#define ICH19_SCALE 1
#define ICH20_SCALE 1
#define ICH21_SCALE 1
#define ICH22_SCALE 1
#define ICH23_SCALE 1
#define ICH24_SCALE 1
#define ICH25_SCALE 1
#define ICH26_SCALE 1
#define ICH27_SCALE 1
#define ICH28_SCALE 1
#define ICH29_SCALE 1
#define ICH30_SCALE 1

#endif

#if Calibration_Index == INFLEXPMU1
// OFFSET Calibration

#define VCH1_OFFSET -73341
#define VCH2_OFFSET 987953
#define VCH3_OFFSET 981453

#define ICH1_OFFSET 1977265
#define ICH2_OFFSET 1917491
#define ICH3_OFFSET 1958047
#define ICH4_OFFSET 1880344
#define ICH5_OFFSET 2158727
#define ICH6_OFFSET 1871795
#define ICH7_OFFSET 2394444
#define ICH8_OFFSET 2266798
#define ICH9_OFFSET 1227823
#define ICH10_OFFSET 1417141
#define ICH11_OFFSET 1557749
#define ICH12_OFFSET 1667375
#define ICH13_OFFSET 2025796
#define ICH14_OFFSET 1958103
#define ICH15_OFFSET 2374869

//SCALING Calibration
#define VCH1_SCALE 588.826416f
#define VCH2_SCALE 586.693115f
#define VCH3_SCALE 586.863037f

#define ICH1_SCALE 374.442047f
#define ICH2_SCALE 374.342468f
#define ICH3_SCALE 372.893158f
#define ICH4_SCALE 374.249695f
#define ICH5_SCALE 373.626556f
#define ICH6_SCALE 373.245544f
#define ICH7_SCALE 374.608154f
#define ICH8_SCALE 373.873718f
#define ICH9_SCALE 373.172302f
#define ICH10_SCALE 374.575531f
#define ICH11_SCALE 373.579895f
#define ICH12_SCALE 373.251465f
#define ICH13_SCALE 374.794861f
#define ICH14_SCALE 373.907959f
#define ICH15_SCALE 373.140533f

#endif

#if Calibration_Index == INFLEXPMU2
// OFFSET Calibration

#define VCH1_OFFSET 1363461
#define VCH2_OFFSET 1630096
#define VCH3_OFFSET 1790529

#define ICH1_OFFSET 1801475
#define ICH2_OFFSET 1767813
#define ICH3_OFFSET 2140603
#define ICH4_OFFSET 2095595
#define ICH5_OFFSET 1816537
#define ICH6_OFFSET 2169203
#define ICH7_OFFSET 2643390
#define ICH8_OFFSET 2272200
#define ICH9_OFFSET 1264274
#define ICH10_OFFSET 1570821
#define ICH11_OFFSET 1551477
#define ICH12_OFFSET 1915141
#define ICH13_OFFSET 1896244
#define ICH14_OFFSET 2049187
#define ICH15_OFFSET 2455294

//SCALING Calibration
#define VCH1_SCALE 585.409973f
#define VCH2_SCALE 584.708008f
#define VCH3_SCALE 585.131042f

#define ICH1_SCALE 373.023346f
#define ICH2_SCALE 372.868347f
#define ICH3_SCALE 371.826263f
#define ICH4_SCALE 372.799744f
#define ICH5_SCALE 372.328796f
#define ICH6_SCALE 372.094421f
#define ICH7_SCALE 372.842377f
#define ICH8_SCALE 372.658813f
#define ICH9_SCALE 374.300995f
#define ICH10_SCALE 375.769928f
#define ICH11_SCALE 374.773285f
#define ICH12_SCALE 374.337524f
#define ICH13_SCALE 375.808685f
#define ICH14_SCALE 375.551666f
#define ICH15_SCALE 374.524048f

#endif

#if Calibration_Index == INFLEXPMU3
// OFFSET Calibration

#define VCH1_OFFSET 328972
#define VCH2_OFFSET 350304
#define VCH3_OFFSET 639744

#define ICH1_OFFSET 1596429
#define ICH2_OFFSET 1867847
#define ICH3_OFFSET 1865223
#define ICH4_OFFSET 1534629
#define ICH5_OFFSET 1851447
#define ICH6_OFFSET 1668338
#define ICH7_OFFSET 2116341
#define ICH8_OFFSET 1756634
#define ICH9_OFFSET 1108107
#define ICH10_OFFSET 1028332
#define ICH11_OFFSET 1275698
#define ICH12_OFFSET 1494316
#define ICH13_OFFSET 1758644
#define ICH14_OFFSET 1732295
#define ICH15_OFFSET 1907002

//SCALING Calibration
#define VCH1_SCALE 586.818359f
#define VCH2_SCALE 588.541809f
#define VCH3_SCALE 584.324402f

#define ICH1_SCALE 374.730072f
#define ICH2_SCALE 374.874603f
#define ICH3_SCALE 374.018646f
#define ICH4_SCALE 375.993011f
#define ICH5_SCALE 375.354279f
#define ICH6_SCALE 374.572113f
#define ICH7_SCALE 375.579987f
#define ICH8_SCALE 375.250763f
#define ICH9_SCALE 373.728577f
#define ICH10_SCALE 375.098511f
#define ICH11_SCALE 374.676758f
#define ICH12_SCALE 374.368073f
#define ICH13_SCALE 375.308228f
#define ICH14_SCALE 374.887726f
#define ICH15_SCALE 374.344299f

#endif

#if Calibration_Index == INFLEXPMU4
// OFFSET Calibration

#define VCH1_OFFSET 1612441
#define VCH2_OFFSET 1957741
#define VCH3_OFFSET 2194459

#define ICH1_OFFSET 2043598
#define ICH2_OFFSET 2298127
#define ICH3_OFFSET 2178877
#define ICH4_OFFSET 2227352
#define ICH5_OFFSET 2070980
#define ICH6_OFFSET 2254447
#define ICH7_OFFSET 2654941
#define ICH8_OFFSET 2611144
#define ICH9_OFFSET 1333121
#define ICH10_OFFSET 1628063
#define ICH11_OFFSET 1652168
#define ICH12_OFFSET 1940333
#define ICH13_OFFSET 2033020
#define ICH14_OFFSET 2111154
#define ICH15_OFFSET 2284131

//SCALING Calibration
#define VCH1_SCALE 585.600037f
#define VCH2_SCALE 586.920776f
#define VCH3_SCALE 585.244263f

#define ICH1_SCALE 373.023682f
#define ICH2_SCALE 372.4823f
#define ICH3_SCALE 372.255707f
#define ICH4_SCALE 373.53186f
#define ICH5_SCALE 373.011444f
#define ICH6_SCALE 372.267639f
#define ICH7_SCALE 373.07547f
#define ICH8_SCALE 373.177094f
#define ICH9_SCALE 372.944153f
#define ICH10_SCALE 374.380035f
#define ICH11_SCALE 374.151672f
#define ICH12_SCALE 372.894409f
#define ICH13_SCALE 374.576233f
#define ICH14_SCALE 373.956665f
#define ICH15_SCALE 373.288208f

#endif
#if Calibration_Index == INFLEXPMU5
// OFFSET Calibration

#define VCH1_OFFSET 1173450
#define VCH2_OFFSET 1151976
#define VCH3_OFFSET 1211878

#define ICH1_OFFSET 1635657
#define ICH2_OFFSET 1486379
#define ICH3_OFFSET 1990680
#define ICH4_OFFSET 1998508
#define ICH5_OFFSET 1512781
#define ICH6_OFFSET 1744598
#define ICH7_OFFSET 2242756
#define ICH8_OFFSET 1794212
#define ICH9_OFFSET 965797
#define ICH10_OFFSET 1087992
#define ICH11_OFFSET 1491562
#define ICH12_OFFSET 1419422
#define ICH13_OFFSET 1513793
#define ICH14_OFFSET 1780264
#define ICH15_OFFSET 1918792

//SCALING Calibration
#define VCH1_SCALE 582.305603f
#define VCH2_SCALE 584.295654f
#define VCH3_SCALE 586.224487f

#define ICH1_SCALE 373.654846f
#define ICH2_SCALE 373.476807f
#define ICH3_SCALE 374.792908f
#define ICH4_SCALE 374.006348f
#define ICH5_SCALE 375.381165f
#define ICH6_SCALE 374.655365f
#define ICH7_SCALE 373.978638f
#define ICH8_SCALE 373.979462f
#define ICH9_SCALE 374.945251f
#define ICH10_SCALE 373.744263f
#define ICH11_SCALE 373.98819f
#define ICH12_SCALE 375.062561f
#define ICH13_SCALE 374.444305f
#define ICH14_SCALE 374.494446f
#define ICH15_SCALE 375.604126f

#endif

#if Calibration_Index == INFLEXPMU6
// OFFSET Calibration

#define VCH1_OFFSET 332161
#define VCH2_OFFSET 311254
#define VCH3_OFFSET 143928

#define ICH1_OFFSET 143928
#define ICH2_OFFSET 2034963
#define ICH3_OFFSET 1839735
#define ICH4_OFFSET 1922859
#define ICH5_OFFSET 2020741
#define ICH6_OFFSET 2032886
#define ICH7_OFFSET 2654868
#define ICH8_OFFSET 1975105
#define ICH9_OFFSET 43826
#define ICH10_OFFSET 331682
#define ICH11_OFFSET 390092
#define ICH12_OFFSET 693070
#define ICH13_OFFSET 548420
#define ICH14_OFFSET 916847
#define ICH15_OFFSET 0

//SCALING Calibration
#define VCH1_SCALE 585.793884f
#define VCH2_SCALE 585.273376f
#define VCH3_SCALE 585.682739f

#define ICH1_SCALE 372.352478f
#define ICH2_SCALE 373.70462f
#define ICH3_SCALE 373.188477f
#define ICH4_SCALE 372.798492f
#define ICH5_SCALE 373.824402f
#define ICH6_SCALE 373.905975f
#define ICH7_SCALE 372.434174f
#define ICH8_SCALE 373.888458f
#define ICH9_SCALE 374.017609f
#define ICH10_SCALE 373.046265f
#define ICH11_SCALE 374.242157f
#define ICH12_SCALE 373.656097f
#define ICH13_SCALE 373.306732f
#define ICH14_SCALE 374.362274f
#define ICH15_SCALE 373.621063f

#endif

#if Calibration_Index == INFLEXPMU7
// OFFSET Calibration

#define VCH1_OFFSET 229403
#define VCH2_OFFSET 429592
#define VCH3_OFFSET 738489

#define ICH1_OFFSET 1632202
#define ICH2_OFFSET 1878854
#define ICH3_OFFSET 1494515
#define ICH4_OFFSET 1585205
#define ICH5_OFFSET 1844045
#define ICH6_OFFSET 1371263
#define ICH7_OFFSET 2037322
#define ICH8_OFFSET 2070701
#define ICH9_OFFSET 890215
#define ICH10_OFFSET 1181802
#define ICH11_OFFSET 1096917
#define ICH12_OFFSET 1412756
#define ICH13_OFFSET 1369731
#define ICH14_OFFSET 1800605
#define ICH15_OFFSET 1943137

//SCALING Calibration
#define VCH1_SCALE 1
#define VCH2_SCALE 1
#define VCH3_SCALE 1

#define ICH1_SCALE 373.826294f
#define ICH2_SCALE 375.477905f
#define ICH3_SCALE 374.991791f
#define ICH4_SCALE 374.504669f
#define ICH5_SCALE 376.352142f
#define ICH6_SCALE 374.700806f
#define ICH7_SCALE 374.712433f
#define ICH8_SCALE 375.791779f
#define ICH9_SCALE 373.751465f
#define ICH10_SCALE 372.664246f
#define ICH11_SCALE 374.35672f
#define ICH12_SCALE 373.901459f
#define ICH13_SCALE 373.723877f
#define ICH14_SCALE 374.258301f
#define ICH15_SCALE 374.27417f

#endif

#if Calibration_Index == INFLEXPMU8
// OFFSET Calibration

#define VCH1_OFFSET 375137
#define VCH2_OFFSET 529121
#define VCH3_OFFSET 635029

#define ICH1_OFFSET 228233
#define ICH2_OFFSET 223304
#define ICH3_OFFSET 406870
#define ICH4_OFFSET 226696
#define ICH5_OFFSET 259853
#define ICH6_OFFSET 348820
#define ICH7_OFFSET 813629
#define ICH8_OFFSET 815897
#define ICH9_OFFSET 601335
#define ICH10_OFFSET 1004556
#define ICH11_OFFSET 668840
#define ICH12_OFFSET 1096246
#define ICH13_OFFSET 1092541
#define ICH14_OFFSET 1372511
#define ICH15_OFFSET 1197865

//SCALING Calibration
#define VCH1_SCALE 584.628296f
#define VCH2_SCALE 582.267212f
#define VCH3_SCALE 584.042725f

#define ICH1_SCALE 372.831757f
#define ICH2_SCALE 373.78891f
#define ICH3_SCALE 373.632507f
#define ICH4_SCALE 372.950378f
#define ICH5_SCALE 373.800842f
#define ICH6_SCALE 373.530853f
#define ICH7_SCALE 372.907379f
#define ICH8_SCALE 374.087921f
#define ICH9_SCALE 373.805389f
#define ICH10_SCALE 373.42688f
#define ICH11_SCALE 374.224701f
#define ICH12_SCALE 374.232147f
#define ICH13_SCALE 373.400085f
#define ICH14_SCALE 374.525787f
#define ICH15_SCALE 374.478973f

#endif

#if Calibration_Index == INFLEXPMU9
// OFFSET Calibration

#define VCH1_OFFSET -273569
#define VCH2_OFFSET -40542
#define VCH3_OFFSET 15223

#define ICH1_OFFSET 1747121
#define ICH2_OFFSET 1452969
#define ICH3_OFFSET 1392756
#define ICH4_OFFSET 1619906
#define ICH5_OFFSET 1582124
#define ICH6_OFFSET 1644390
#define ICH7_OFFSET 2213625
#define ICH8_OFFSET 1397375
#define ICH9_OFFSET 817292
#define ICH10_OFFSET 1065303
#define ICH11_OFFSET 948021
#define ICH12_OFFSET 1470655
#define ICH13_OFFSET 1407192
#define ICH14_OFFSET 1403049
#define ICH15_OFFSET 1853686

//SCALING Calibration
#define VCH1_SCALE 586.583557f
#define VCH2_SCALE 586.433228f
#define VCH3_SCALE 586.171021f

#define ICH1_SCALE 373.675171f
#define ICH2_SCALE 374.581177f
#define ICH3_SCALE 374.04483f
#define ICH4_SCALE 373.732361f
#define ICH5_SCALE 374.812286f
#define ICH6_SCALE 373.425415f
#define ICH7_SCALE 373.620331f
#define ICH8_SCALE 374.842133f
#define ICH9_SCALE 1
#define ICH10_SCALE 372.869537f
#define ICH11_SCALE 374.603973f
#define ICH12_SCALE 374.00119f
#define ICH13_SCALE 372.548279f
#define ICH14_SCALE 374.311035f
#define ICH15_SCALE 374.180542f

#endif

#if Calibration_Index == INFLEXPMU_TEST
// OFFSET Calibration

#define VCH1_OFFSET 262133
#define VCH2_OFFSET 417463
#define VCH3_OFFSET 579011

#define ICH1_OFFSET 247978
#define ICH2_OFFSET 343345
#define ICH3_OFFSET 411410

#define ICH4_OFFSET 1619906
#define ICH5_OFFSET 1582124
#define ICH6_OFFSET 1644390
#define ICH7_OFFSET 2213625
#define ICH8_OFFSET 1397375
#define ICH9_OFFSET 817292
#define ICH10_OFFSET 1065303
#define ICH11_OFFSET 948021
#define ICH12_OFFSET 1470655
#define ICH13_OFFSET 1407192
#define ICH14_OFFSET 1403049
#define ICH15_OFFSET 1853686

//SCALING Calibration
#define VCH1_SCALE 586.045959f
#define VCH2_SCALE 583.685608f
#define VCH3_SCALE 584.679321f

#define ICH1_SCALE 371.514801f
#define ICH2_SCALE 372.51059f
#define ICH3_SCALE 372.703033f
#define ICH4_SCALE 374.812286f
#define ICH5_SCALE 374.812286f
#define ICH6_SCALE 373.425415f
#define ICH7_SCALE 373.620331f
#define ICH8_SCALE 374.842133f
#define ICH9_SCALE 374.767822f
#define ICH10_SCALE 372.869537f
#define ICH11_SCALE 374.603973f
#define ICH12_SCALE 374.00119f
#define ICH13_SCALE 372.548279f
#define ICH14_SCALE 374.311035f
#define ICH15_SCALE 374.180542f

#endif

#if Calibration_Index == INFLEXPMU8_SOK
// OFFSET Calibration

#define VCH1_OFFSET 243952
#define VCH2_OFFSET 318240
#define VCH3_OFFSET 529294

#define ICH1_OFFSET 243034
#define ICH2_OFFSET 342509
#define ICH3_OFFSET 418130

#define ICH4_OFFSET 236958
#define ICH5_OFFSET 265261
#define ICH6_OFFSET 356523
#define ICH7_OFFSET 832465
#define ICH8_OFFSET 441414
#define ICH9_OFFSET 476302
#define ICH10_OFFSET 779354
#define ICH11_OFFSET 673340
#define ICH12_OFFSET 1065980
#define ICH13_OFFSET 986358
#define ICH14_OFFSET 1372406
#define ICH15_OFFSET 1307319

//SCALING Calibration
#define VCH1_SCALE 585.94928f
#define VCH2_SCALE 583.559021f
#define VCH3_SCALE 584.503662f

#define ICH1_SCALE 370.661469f
#define ICH2_SCALE 372.008057f
#define ICH3_SCALE 372.977264f
#define ICH4_SCALE 370.610565f
#define ICH5_SCALE 371.99472f
#define ICH6_SCALE 372.638855f
#define ICH7_SCALE 370.35849f
#define ICH8_SCALE 370.35849f
#define ICH9_SCALE 372.821442f
#define ICH10_SCALE 370.925934f
#define ICH11_SCALE 372.317139f
#define ICH12_SCALE 373.287872f
#define ICH13_SCALE 371.026154f
#define ICH14_SCALE 372.583374f
#define ICH15_SCALE 373.223511f

#endif

#if Calibration_Index == INFLEXPMU9_SOK
// OFFSET Calibration

#define VCH1_OFFSET -172157
#define VCH2_OFFSET -47855
#define VCH3_OFFSET 84632

#define ICH1_OFFSET 1728187
#define ICH2_OFFSET 1464533
#define ICH3_OFFSET 1391398

#define ICH4_OFFSET 1619934
#define ICH5_OFFSET 1589476
#define ICH6_OFFSET 1642785
#define ICH7_OFFSET 2057570
#define ICH8_OFFSET 1415707
#define ICH9_OFFSET 812810
#define ICH10_OFFSET 877386
#define ICH11_OFFSET 843812
#define ICH12_OFFSET 1380522
#define ICH13_OFFSET 1347301
#define ICH14_OFFSET 1490110
#define ICH15_OFFSET 2033514

//SCALING Calibration
#define VCH1_SCALE 586.309692f
#define VCH2_SCALE 586.726318f
#define VCH3_SCALE 586.682251f

#define ICH1_SCALE 371.487823f
#define ICH2_SCALE 372.687073f
#define ICH3_SCALE 373.334167f
#define ICH4_SCALE 371.529877f
#define ICH5_SCALE 372.5625f
#define ICH6_SCALE 372.916382f
#define ICH7_SCALE 371.213379f
#define ICH8_SCALE 372.550934f
#define ICH9_SCALE 371.830322f
#define ICH10_SCALE 370.340363f
#define ICH11_SCALE 372.015411f
#define ICH12_SCALE 373.044891f
#define ICH13_SCALE 370.476257f
#define ICH14_SCALE 371.905334f
#define ICH15_SCALE 372.828979f

#endif

#if Calibration_Index == ENERJISA1
// OFFSET Calibration

#define VCH1_OFFSET 1067472
#define VCH2_OFFSET 1220833
#define VCH3_OFFSET 1896714

#define ICH1_OFFSET 1363478
#define ICH2_OFFSET 1363478
#define ICH3_OFFSET 1372809
#define ICH4_OFFSET 1245696
#define ICH5_OFFSET 1385926
#define ICH6_OFFSET 1503755
#define ICH7_OFFSET 2752168
#define ICH8_OFFSET 1008358
#define ICH9_OFFSET 58617
#define ICH10_OFFSET -732664
#define ICH11_OFFSET 354115
#define ICH12_OFFSET 619548
#define ICH13_OFFSET 595028
#define ICH14_OFFSET 1024271
#define ICH15_OFFSET 1269363

//SCALING Calibration
#define VCH1_SCALE 585.002991f
#define VCH2_SCALE 585.22467f
#define VCH3_SCALE 584.235596f

#define ICH1_SCALE 369.645508f
#define ICH2_SCALE 370.711365f
#define ICH3_SCALE 370.008087f
#define ICH4_SCALE 369.437347f
#define ICH5_SCALE 370.56958f
#define ICH6_SCALE 370.384918f
#define ICH7_SCALE 369.912537f
#define ICH8_SCALE 370.606628f
#define ICH9_SCALE 370.153442f
#define ICH10_SCALE 369.942719f
#define ICH11_SCALE 369.998688f
#define ICH12_SCALE 369.998688f
#define ICH13_SCALE 370.169647f
#define ICH14_SCALE 370.779694f
#define ICH15_SCALE 370.658447f

#endif

#if Calibration_Index == ENERJISA2
// OFFSET Calibration

#define VCH1_OFFSET 826298
#define VCH2_OFFSET 1101789
#define VCH3_OFFSET 1101789

#define ICH1_OFFSET 1826330
#define ICH2_OFFSET 1597306
#define ICH3_OFFSET 1652117
#define ICH4_OFFSET 1633255
#define ICH5_OFFSET 1723751
#define ICH6_OFFSET 1887761
#define ICH7_OFFSET 2856491
#define ICH8_OFFSET 1472611
#define ICH9_OFFSET 328292
#define ICH10_OFFSET 80932
#define ICH11_OFFSET 893025
#define ICH12_OFFSET 1047943
#define ICH13_OFFSET 1144276
#define ICH14_OFFSET 1194894
#define ICH15_OFFSET 1568347

//SCALING Calibration
#define VCH1_SCALE 588.312317f
#define VCH2_SCALE 586.227417f
#define VCH3_SCALE 586.440125f

#define ICH1_SCALE 369.467224f
#define ICH2_SCALE 370.027893f
#define ICH3_SCALE 369.504364f
#define ICH4_SCALE 369.338745f
#define ICH5_SCALE 369.828094f
#define ICH6_SCALE 369.663452f
#define ICH7_SCALE 369.568634f
#define ICH8_SCALE 369.973236f
#define ICH9_SCALE 370.492615f
#define ICH10_SCALE 369.969879f
#define ICH11_SCALE 370.382874f
#define ICH12_SCALE 370.568604f
#define ICH13_SCALE 369.692291f
#define ICH14_SCALE 370.299835f
#define ICH15_SCALE 370.220032f

#endif

#if Calibration_Index == ENERJISA3
// OFFSET Calibration

#define VCH1_OFFSET 918203
#define VCH2_OFFSET 1230676
#define VCH3_OFFSET 1435458

#define ICH1_OFFSET 1015215
#define ICH2_OFFSET 796494
#define ICH3_OFFSET 808022
#define ICH4_OFFSET 627914
#define ICH5_OFFSET 813994
#define ICH6_OFFSET 621774
#define ICH7_OFFSET 2163175
#define ICH8_OFFSET 133465
#define ICH9_OFFSET 385403
#define ICH10_OFFSET 355810
#define ICH11_OFFSET 608001
#define ICH12_OFFSET 1124149
#define ICH13_OFFSET 1210474
#define ICH14_OFFSET 1634028
#define ICH15_OFFSET 2038880

//SCALING Calibration
#define VCH1_SCALE 586.056152f
#define VCH2_SCALE 586.81781f
#define VCH3_SCALE 586.261536f

#define ICH1_SCALE 370.564331f
#define ICH2_SCALE 370.753113f
#define ICH3_SCALE 371.031799f
#define ICH4_SCALE 370.432312f
#define ICH5_SCALE 370.339233f
#define ICH6_SCALE 371.119537f
#define ICH7_SCALE 369.959839f
#define ICH8_SCALE 370.81311f
#define ICH9_SCALE 370.985107f
#define ICH10_SCALE 370.019775f
#define ICH11_SCALE 371.33371f
#define ICH12_SCALE 371.065643f
#define ICH13_SCALE 370.684937f
#define ICH14_SCALE 371.073242f
#define ICH15_SCALE 371.338989f

#endif

#if Calibration_Index == ENERJISA4
// OFFSET Calibration

#define VCH1_OFFSET 1047053
#define VCH2_OFFSET 1140166
#define VCH3_OFFSET 1695424

#define ICH1_OFFSET 1715978
#define ICH2_OFFSET 1789532
#define ICH3_OFFSET 1625828
#define ICH4_OFFSET 1254545
#define ICH5_OFFSET 1565447
#define ICH6_OFFSET 1681469
#define ICH7_OFFSET 2163175
#define ICH8_OFFSET 1343632
#define ICH9_OFFSET 553496
#define ICH10_OFFSET 209757
#define ICH11_OFFSET 714365
#define ICH12_OFFSET 981311
#define ICH13_OFFSET 1226247
#define ICH14_OFFSET 1560137
#define ICH15_OFFSET 1941079

//SCALING Calibration
#define VCH1_SCALE 584.272705f
#define VCH2_SCALE 582.725647f
#define VCH3_SCALE 586.272949f

#define ICH1_SCALE 370.712097f
#define ICH2_SCALE 370.197418f
#define ICH3_SCALE 370.684723f
#define ICH4_SCALE 369.816833f
#define ICH5_SCALE 370.075653f
#define ICH6_SCALE 370.466736f
#define ICH7_SCALE 370.048065f
#define ICH8_SCALE 371.023743f
#define ICH9_SCALE 369.631836f
#define ICH10_SCALE 369.521332f
#define ICH11_SCALE 369.92749f
#define ICH12_SCALE 369.5896f
#define ICH13_SCALE 370.019348f
#define ICH14_SCALE 369.64621f
#define ICH15_SCALE 369.988098f

#endif

#if Calibration_Index == ENERJISA5
// OFFSET Calibration

#define VCH1_OFFSET 317131
#define VCH2_OFFSET 360529
#define VCH3_OFFSET 826467

#define ICH1_OFFSET 1592835
#define ICH2_OFFSET 1876159
#define ICH3_OFFSET 1493460
#define ICH4_OFFSET 1585325
#define ICH5_OFFSET 1848004
#define ICH6_OFFSET 1375170
#define ICH7_OFFSET 1877213
#define ICH8_OFFSET 1910400
#define ICH9_OFFSET 949820
#define ICH10_OFFSET 1131400
#define ICH11_OFFSET 1129080
#define ICH12_OFFSET 1386575
#define ICH13_OFFSET 1336528
#define ICH14_OFFSET 1785555
#define ICH15_OFFSET 1950895

//SCALING Calibration
#define VCH1_SCALE 586.993225f
#define VCH2_SCALE 589.003723f
#define VCH3_SCALE 589.737793f

#define ICH1_SCALE 372.940186f
#define ICH2_SCALE 373.365509f
#define ICH3_SCALE 373.797852f
#define ICH4_SCALE 373.150055f
#define ICH5_SCALE 373.150055f
#define ICH6_SCALE 373.663757f
#define ICH7_SCALE 372.334625f
#define ICH8_SCALE 371.599457f
#define ICH9_SCALE 371.229675f
#define ICH10_SCALE 370.28949f
#define ICH11_SCALE 370.939423f
#define ICH12_SCALE 370.958527f
#define ICH13_SCALE 370.740448f
#define ICH14_SCALE 371.454956f
#define ICH15_SCALE 370.836792f

#endif

#if Calibration_Index == ENERJISA6
// OFFSET Calibration

#define VCH1_OFFSET 575876
#define VCH2_OFFSET 1071937
#define VCH3_OFFSET 1187583

#define ICH1_OFFSET 1248173
#define ICH2_OFFSET 1518872
#define ICH3_OFFSET 1205903
#define ICH4_OFFSET 1450281
#define ICH5_OFFSET 1314949
#define ICH6_OFFSET 1524452
#define ICH7_OFFSET 2663735
#define ICH8_OFFSET 972277
#define ICH9_OFFSET 1336757
#define ICH10_OFFSET 633930
#define ICH11_OFFSET 1417797
#define ICH12_OFFSET 1883704
#define ICH13_OFFSET 1980452
#define ICH14_OFFSET 2239208
#define ICH15_OFFSET 2494089

//SCALING Calibration
#define VCH1_SCALE 587.317993f
#define VCH2_SCALE 587.465881f
#define VCH3_SCALE 586.678772f

#define ICH1_SCALE 370.220245f
#define ICH2_SCALE 370.349487f
#define ICH3_SCALE 369.963104f
#define ICH4_SCALE 369.775848f
#define ICH5_SCALE 370.043549f
#define ICH6_SCALE 369.702972f
#define ICH7_SCALE 369.936218f
#define ICH8_SCALE 370.808899f
#define ICH9_SCALE 370.679443f
#define ICH10_SCALE 369.893494f
#define ICH11_SCALE 369.884888f
#define ICH12_SCALE 370.78418f
#define ICH13_SCALE 370.060455f
#define ICH14_SCALE 370.693115f
#define ICH15_SCALE 370.536499f

#endif

#if Calibration_Index == ENERJISA7
// OFFSET Calibration

#define VCH1_OFFSET 910729
#define VCH2_OFFSET 1137860
#define VCH3_OFFSET 1304724

#define ICH1_OFFSET 1519782
#define ICH2_OFFSET 1667517
#define ICH3_OFFSET 1522007
#define ICH4_OFFSET 1424228
#define ICH5_OFFSET 1496425
#define ICH6_OFFSET 1536413
#define ICH7_OFFSET 3025202
#define ICH8_OFFSET 870038
#define ICH9_OFFSET 520807
#define ICH10_OFFSET -151746
#define ICH11_OFFSET 997646
#define ICH12_OFFSET 1030525
#define ICH13_OFFSET 1107939
#define ICH14_OFFSET 1417425
#define ICH15_OFFSET 1790553

//SCALING Calibration
#define VCH1_SCALE 585.502869f
#define VCH2_SCALE 585.806885f
#define VCH3_SCALE 585.317871f

#define ICH1_SCALE 369.953888f
#define ICH2_SCALE 369.724762f
#define ICH3_SCALE 369.441193f
#define ICH4_SCALE 370.321564f
#define ICH5_SCALE 369.071503f
#define ICH6_SCALE 369.95932f
#define ICH7_SCALE 369.94043f
#define ICH8_SCALE 369.959625f
#define ICH9_SCALE 368.980377f
#define ICH10_SCALE 371.122803f
#define ICH11_SCALE 370.912048f
#define ICH12_SCALE 371.52713f
#define ICH13_SCALE 371.100647f
#define ICH14_SCALE 370.789459f
#define ICH15_SCALE 370.898499f

#endif

#if Calibration_Index == ENERJISA8
// OFFSET Calibration

#define VCH1_OFFSET 993058
#define VCH2_OFFSET 1144548
#define VCH3_OFFSET 1451668

#define ICH1_OFFSET 1268102
#define ICH2_OFFSET 1446450
#define ICH3_OFFSET 1446909
#define ICH4_OFFSET 1193725
#define ICH5_OFFSET 1058544
#define ICH6_OFFSET 1184561
#define ICH7_OFFSET 2860504
#define ICH8_OFFSET 652784
#define ICH9_OFFSET 619078
#define ICH10_OFFSET -147033
#define ICH11_OFFSET 950163
#define ICH12_OFFSET 1015445
#define ICH13_OFFSET 1281871
#define ICH14_OFFSET 1390918
#define ICH15_OFFSET 1776515

//SCALING Calibration
#define VCH1_SCALE 587.178406f
#define VCH2_SCALE 584.00354f
#define VCH3_SCALE 587.500916f

#define ICH1_SCALE 369.882446f
#define ICH2_SCALE 370.499969f
#define ICH3_SCALE 369.981293f
#define ICH4_SCALE 369.756927f
#define ICH5_SCALE 369.799133f
#define ICH6_SCALE 370.221008f
#define ICH7_SCALE 369.581299f
#define ICH8_SCALE 369.42218f
#define ICH9_SCALE 368.547272f
#define ICH10_SCALE 369.210266f
#define ICH11_SCALE 369.307373f
#define ICH12_SCALE 369.764038f
#define ICH13_SCALE 369.215515f
#define ICH14_SCALE 368.949127f
#define ICH15_SCALE 370.149811f

#endif

#if Calibration_Index == ENERJISA9
// OFFSET Calibration

#define VCH1_OFFSET 1187081
#define VCH2_OFFSET 885316
#define VCH3_OFFSET 1776103

#define ICH1_OFFSET 1547262
#define ICH2_OFFSET 1544482
#define ICH3_OFFSET 1625077
#define ICH4_OFFSET 1303929
#define ICH5_OFFSET 1760052
#define ICH6_OFFSET 1451315
#define ICH7_OFFSET 2804895
#define ICH8_OFFSET 1065206
#define ICH9_OFFSET -181270
#define ICH10_OFFSET -694197
#define ICH11_OFFSET 462050
#define ICH12_OFFSET 180818
#define ICH13_OFFSET 833819
#define ICH14_OFFSET 1214110
#define ICH15_OFFSET 1246631

//SCALING Calibration
#define VCH1_SCALE 586.262695f
#define VCH2_SCALE 585.182861f
#define VCH3_SCALE 584.985718f

#define ICH1_SCALE 370.211212f
#define ICH2_SCALE 369.731964f
#define ICH3_SCALE 370.565155f
#define ICH4_SCALE 370.061859f
#define ICH5_SCALE 370.028381f
#define ICH6_SCALE 369.517975f
#define ICH7_SCALE 370.430634f
#define ICH8_SCALE 370.294434f
#define ICH9_SCALE 370.203278f
#define ICH10_SCALE 369.881592f
#define ICH11_SCALE 370.80423f
#define ICH12_SCALE 370.934845f
#define ICH13_SCALE 370.701202f
#define ICH14_SCALE 370.577393f
#define ICH15_SCALE 370.515015f

#endif

#if Calibration_Index == ENERJISA10
// OFFSET Calibration

#define VCH1_OFFSET 884975
#define VCH2_OFFSET 1166084
#define VCH3_OFFSET 1390063

#define ICH1_OFFSET 1112921
#define ICH2_OFFSET 842687
#define ICH3_OFFSET 1024272
#define ICH4_OFFSET 942569
#define ICH5_OFFSET 1085718
#define ICH6_OFFSET 640419
#define ICH7_OFFSET 2163988
#define ICH8_OFFSET 399262
#define ICH9_OFFSET 561235
#define ICH10_OFFSET 192478
#define ICH11_OFFSET 750250
#define ICH12_OFFSET 1054735
#define ICH13_OFFSET 1141904
#define ICH14_OFFSET 1400060
#define ICH15_OFFSET 1930099

//SCALING Calibration
#define VCH1_SCALE 585.55603f
#define VCH2_SCALE 586.23761f
#define VCH3_SCALE 585.500671f

#define ICH1_SCALE 370.023132f
#define ICH2_SCALE 370.476074f
#define ICH3_SCALE 370.856506f
#define ICH4_SCALE 369.382538f
#define ICH5_SCALE 369.931732f
#define ICH6_SCALE 370.353821f
#define ICH7_SCALE 369.88504f
#define ICH8_SCALE 370.917297f
#define ICH9_SCALE 370.306702f
#define ICH10_SCALE 370.12912f
#define ICH11_SCALE 370.622345f
#define ICH12_SCALE 370.574677f
#define ICH13_SCALE 370.731201f
#define ICH14_SCALE 370.461914f
#define ICH15_SCALE 370.980743f

#endif

#if Calibration_Index == ENERJISA11
// OFFSET Calibration

#define VCH1_OFFSET 850421
#define VCH2_OFFSET 1142033
#define VCH3_OFFSET 1749176

#define ICH1_OFFSET 576442
#define ICH2_OFFSET 400833
#define ICH3_OFFSET 492260
#define ICH4_OFFSET 646690
#define ICH5_OFFSET 414840
#define ICH6_OFFSET 488806
#define ICH7_OFFSET 1908229
#define ICH8_OFFSET 170582
#define ICH9_OFFSET 1002112
#define ICH10_OFFSET 1002112
#define ICH11_OFFSET 1266016
#define ICH12_OFFSET 1524954
#define ICH13_OFFSET 1564665
#define ICH14_OFFSET 1617082
#define ICH15_OFFSET 2088242

//SCALING Calibration
#define VCH1_SCALE 586.944458f
#define VCH2_SCALE 585.806885f
#define VCH3_SCALE 584.454224f

#define ICH1_SCALE 370.762756f
#define ICH2_SCALE 370.504822f
#define ICH3_SCALE 371.216339f
#define ICH4_SCALE 370.466156f
#define ICH5_SCALE 369.745056f
#define ICH6_SCALE 370.988342f
#define ICH7_SCALE 369.70343f
#define ICH8_SCALE 369.849243f
#define ICH9_SCALE 372.258026f
#define ICH10_SCALE 370.683624f
#define ICH11_SCALE 371.409607f
#define ICH12_SCALE 372.058838f
#define ICH13_SCALE 371.753967f
#define ICH14_SCALE 372.092499f
#define ICH15_SCALE 372.167633f

#endif

#if Calibration_Index == ENERJISA12
// OFFSET Calibration

#define VCH1_OFFSET 827369
#define VCH2_OFFSET 1236196
#define VCH3_OFFSET 1581392

#define ICH1_OFFSET 1435560
#define ICH2_OFFSET 1203567
#define ICH3_OFFSET 1491080
#define ICH4_OFFSET 1388290
#define ICH5_OFFSET 1250673
#define ICH6_OFFSET 1311654
#define ICH7_OFFSET 2777805
#define ICH8_OFFSET 1248308
#define ICH9_OFFSET 556835
#define ICH10_OFFSET 137486
#define ICH11_OFFSET 1351343
#define ICH12_OFFSET 1054522
#define ICH13_OFFSET 1421107
#define ICH14_OFFSET 1936914
#define ICH15_OFFSET 2329298

//SCALING Calibration
#define VCH1_SCALE 585.556213f
#define VCH2_SCALE 584.761597f
#define VCH3_SCALE 584.979797f

#define ICH1_SCALE 370.102264f
#define ICH2_SCALE 369.510925f
#define ICH3_SCALE 370.166534f
#define ICH4_SCALE 369.202972f
#define ICH5_SCALE 370.259644f
#define ICH6_SCALE 370.043121f
#define ICH7_SCALE 369.361755f
#define ICH8_SCALE 370.507263f
#define ICH9_SCALE 369.991364f
#define ICH10_SCALE 369.194763f
#define ICH11_SCALE 369.771576f
#define ICH12_SCALE 370.254242f
#define ICH13_SCALE 369.562225f
#define ICH14_SCALE 369.901581f
#define ICH15_SCALE 370.644897f

#endif

#if Calibration_Index == ENERJISA13
// OFFSET Calibration

#define VCH1_OFFSET 945086
#define VCH2_OFFSET 1128712
#define VCH3_OFFSET 1671980

#define ICH1_OFFSET 933402
#define ICH2_OFFSET 734867
#define ICH3_OFFSET 815985
#define ICH4_OFFSET 961310
#define ICH5_OFFSET 837056
#define ICH6_OFFSET 1097284
#define ICH7_OFFSET 2206816
#define ICH8_OFFSET 526053
#define ICH9_OFFSET -542944
#define ICH10_OFFSET -715483
#define ICH11_OFFSET 111265
#define ICH12_OFFSET 515412
#define ICH13_OFFSET 324373
#define ICH14_OFFSET 1035689
#define ICH15_OFFSET 1245786

//SCALING Calibration
#define VCH1_SCALE 582.730896f
#define VCH2_SCALE 582.011536f
#define VCH3_SCALE 584.94043f

#define ICH1_SCALE 369.542908f
#define ICH2_SCALE 369.721039f
#define ICH3_SCALE 370.283722f
#define ICH4_SCALE 369.825897f
#define ICH5_SCALE 369.16156f
#define ICH6_SCALE 369.527374f
#define ICH7_SCALE 370.349731f
#define ICH8_SCALE 369.617554f
#define ICH9_SCALE 369.789825f
#define ICH10_SCALE 369.375153f
#define ICH11_SCALE 369.708435f
#define ICH12_SCALE 370.012909f
#define ICH13_SCALE 369.678558f
#define ICH14_SCALE 369.563385f
#define ICH15_SCALE 370.05661f

#endif

#if Calibration_Index == ENERJISA14
// OFFSET Calibration

#define VCH1_OFFSET 819629
#define VCH2_OFFSET 1147401
#define VCH3_OFFSET 1684093

#define ICH1_OFFSET 1673743
#define ICH2_OFFSET 1369216
#define ICH3_OFFSET 1531485
#define ICH4_OFFSET 1578424
#define ICH5_OFFSET 1430554
#define ICH6_OFFSET 1809480
#define ICH7_OFFSET 3399226
#define ICH8_OFFSET 1319433
#define ICH9_OFFSET -321780
#define ICH10_OFFSET -731564
#define ICH11_OFFSET 54096
#define ICH12_OFFSET 256725
#define ICH13_OFFSET 58576
#define ICH14_OFFSET 634463
#define ICH15_OFFSET 1164696

//SCALING Calibration
#define VCH1_SCALE 584.939514f
#define VCH2_SCALE 585.511292f
#define VCH3_SCALE 586.421448f

#define ICH1_SCALE 369.94281f
#define ICH2_SCALE 370.334564f
#define ICH3_SCALE 370.926422f
#define ICH4_SCALE 370.256195f
#define ICH5_SCALE 370.502686f
#define ICH6_SCALE 370.520691f
#define ICH7_SCALE 369.709808f
#define ICH8_SCALE 371.08136f
#define ICH9_SCALE 370.713043f
#define ICH10_SCALE 370.354187f
#define ICH11_SCALE 371.468933f
#define ICH12_SCALE 370.940063f
#define ICH13_SCALE 370.474548f
#define ICH14_SCALE 371.342468f
#define ICH15_SCALE 371.254944f

#endif

#if Calibration_Index == ENERJISA15
// OFFSET Calibration

#define VCH1_OFFSET 935895
#define VCH2_OFFSET 919756
#define VCH3_OFFSET 1543620

#define ICH1_OFFSET 516694
#define ICH2_OFFSET 665407
#define ICH3_OFFSET 629643
#define ICH4_OFFSET 473706
#define ICH5_OFFSET 807547
#define ICH6_OFFSET 533534
#define ICH7_OFFSET 1629781
#define ICH8_OFFSET 248624
#define ICH9_OFFSET 186937
#define ICH10_OFFSET 75753
#define ICH11_OFFSET 599235
#define ICH12_OFFSET 664337
#define ICH13_OFFSET 817754
#define ICH14_OFFSET 1209822
#define ICH15_OFFSET 1561191

//SCALING Calibration
#define VCH1_SCALE 583.817505f
#define VCH2_SCALE 586.420044f
#define VCH3_SCALE 585.99646f

#define ICH1_SCALE 369.51236f
#define ICH2_SCALE 369.588715f
#define ICH3_SCALE 370.146332f
#define ICH4_SCALE 369.638153f
#define ICH5_SCALE 370.246643f
#define ICH6_SCALE 370.079742f
#define ICH7_SCALE 370.262329f
#define ICH8_SCALE 370.228271f
#define ICH9_SCALE 369.514954f
#define ICH10_SCALE 369.340698f
#define ICH11_SCALE 369.316742f
#define ICH12_SCALE 370.553589f
#define ICH13_SCALE 369.918091f
#define ICH14_SCALE 369.882172f
#define ICH15_SCALE 370.101563f

#endif

#if Calibration_Index == ENERJISA16
// OFFSET Calibration

#define VCH1_OFFSET 1150819
#define VCH2_OFFSET 1150819
#define VCH3_OFFSET 1586104

#define ICH1_OFFSET 1419913
#define ICH2_OFFSET 1305441
#define ICH3_OFFSET 1292930
#define ICH4_OFFSET 839386
#define ICH5_OFFSET 1156884
#define ICH6_OFFSET 975195
#define ICH7_OFFSET 2544387
#define ICH8_OFFSET 680878
#define ICH9_OFFSET -725503
#define ICH10_OFFSET 879341
#define ICH11_OFFSET -12923
#define ICH12_OFFSET 16019
#define ICH13_OFFSET 197970
#define ICH14_OFFSET 486088
#define ICH15_OFFSET 784919

//SCALING Calibration
#define VCH1_SCALE 584.764282f
#define VCH2_SCALE 583.954956f
#define VCH3_SCALE 584.680237f

#define ICH1_SCALE 370.08844f
#define ICH2_SCALE 370.351776f
#define ICH3_SCALE 370.574829f
#define ICH4_SCALE 370.345642f
#define ICH5_SCALE 369.809875f
#define ICH6_SCALE 370.687347f
#define ICH7_SCALE 370.369171f
#define ICH8_SCALE 370.01059f
#define ICH9_SCALE 371.201599f
#define ICH10_SCALE 360.796356f
#define ICH11_SCALE 370.604675f
#define ICH12_SCALE 370.703613f
#define ICH13_SCALE 370.226166f
#define ICH14_SCALE 370.331848f
#define ICH15_SCALE 370.893005f

#endif

#if Calibration_Index == ENERJISA17
// OFFSET Calibration

#define VCH1_OFFSET 751468
#define VCH2_OFFSET 1055726
#define VCH3_OFFSET 1454704

#define ICH1_OFFSET 1368640
#define ICH2_OFFSET 930847
#define ICH3_OFFSET 1008567
#define ICH4_OFFSET 991397
#define ICH5_OFFSET 1150946
#define ICH6_OFFSET 792397
#define ICH7_OFFSET 2375838
#define ICH8_OFFSET 1070231
#define ICH9_OFFSET -324290
#define ICH10_OFFSET -183249
#define ICH11_OFFSET 231586
#define ICH12_OFFSET 511144
#define ICH13_OFFSET 703334
#define ICH14_OFFSET 957256
#define ICH15_OFFSET 1385857

//SCALING Calibration
#define VCH1_SCALE 584.809387f
#define VCH2_SCALE 582.99646f
#define VCH3_SCALE 582.694763f

#define ICH1_SCALE 369.551025f
#define ICH2_SCALE 369.600128f
#define ICH3_SCALE 369.957886f
#define ICH4_SCALE 369.074341f
#define ICH5_SCALE 369.402771f
#define ICH6_SCALE 369.768036f
#define ICH7_SCALE 369.833588f
#define ICH8_SCALE 369.415894f
#define ICH9_SCALE 369.518585f
#define ICH10_SCALE 369.66037f
#define ICH11_SCALE 369.444611f
#define ICH12_SCALE 370.264709f
#define ICH13_SCALE 369.181458f
#define ICH14_SCALE 369.94574f
#define ICH15_SCALE 369.747742f

#endif

#if Calibration_Index == ENERJISA18
// OFFSET Calibration

#define VCH1_OFFSET 827823
#define VCH2_OFFSET 1119801
#define VCH3_OFFSET 1491335

#define ICH1_OFFSET 1221677
#define ICH2_OFFSET 1261605
#define ICH3_OFFSET 967024
#define ICH4_OFFSET 2133878
#define ICH5_OFFSET 1225944
#define ICH6_OFFSET 1318392
#define ICH7_OFFSET 2555997
#define ICH8_OFFSET 756462
#define ICH9_OFFSET 744022
#define ICH10_OFFSET 440903
#define ICH11_OFFSET 1058328
#define ICH12_OFFSET 1228789
#define ICH13_OFFSET 1385489
#define ICH14_OFFSET 1494831
#define ICH15_OFFSET 1856792

//SCALING Calibration
#define VCH1_SCALE 589.794006f
#define VCH2_SCALE 588.541016f
#define VCH3_SCALE 585.483459f

#define ICH1_SCALE 369.84079f
#define ICH2_SCALE 370.036469f
#define ICH3_SCALE 370.203979f
#define ICH4_SCALE 367.017822f
#define ICH5_SCALE 369.931488f
#define ICH6_SCALE 369.36911f
#define ICH7_SCALE 369.773132f
#define ICH8_SCALE 370.716736f
#define ICH9_SCALE 370.691376f
#define ICH10_SCALE 370.485657f
#define ICH11_SCALE 371.048126f
#define ICH12_SCALE 370.605347f
#define ICH13_SCALE 370.841278f
#define ICH14_SCALE 370.886536f
#define ICH15_SCALE 370.470215f

#endif

#if Calibration_Index == PMU1
// OFFSET Calibration

#define VCH1_OFFSET 1136885
#define VCH2_OFFSET 1225968
#define VCH3_OFFSET 1503237

#define ICH1_OFFSET 1211277
#define ICH2_OFFSET 1283678
#define ICH3_OFFSET 1286835
#define ICH4_OFFSET 1141798
#define ICH5_OFFSET 1403864
#define ICH6_OFFSET 1576283
#define ICH7_OFFSET 2562175
#define ICH8_OFFSET 918069
#define ICH9_OFFSET 917367
#define ICH10_OFFSET 383367
#define ICH11_OFFSET 1466100
#define ICH12_OFFSET 1454149
#define ICH13_OFFSET 1448589
#define ICH14_OFFSET 1933604
#define ICH15_OFFSET 2229134

//SCALING Calibration
#define VCH1_SCALE 583.30603f
#define VCH2_SCALE 586.251282f
#define VCH3_SCALE 586.443359f

#define ICH1_SCALE 370.803802f
#define ICH2_SCALE 371.021088f
#define ICH3_SCALE 370.921295f
#define ICH4_SCALE 370.916779f
#define ICH5_SCALE 370.450439f
#define ICH6_SCALE 370.50589f
#define ICH7_SCALE 369.588928f
#define ICH8_SCALE 371.287445f
#define ICH9_SCALE 370.622772f
#define ICH10_SCALE 371.049225f
#define ICH11_SCALE 370.753296f
#define ICH12_SCALE 370.900635f
#define ICH13_SCALE 371.223602f
#define ICH14_SCALE 370.437622f
#define ICH15_SCALE 370.887421f

#endif

#if Calibration_Index == PMU2
// OFFSET Calibration

#define VCH1_OFFSET 1020008
#define VCH2_OFFSET 1182757
#define VCH3_OFFSET 1524540

#define ICH1_OFFSET 1323237
#define ICH2_OFFSET 1089753
#define ICH3_OFFSET 1358440
#define ICH4_OFFSET 1203380
#define ICH5_OFFSET 1116600
#define ICH6_OFFSET 867485
#define ICH7_OFFSET 2063044
#define ICH8_OFFSET 944328
#define ICH9_OFFSET 996698
#define ICH10_OFFSET 599831
#define ICH11_OFFSET 1224040
#define ICH12_OFFSET 1168051
#define ICH13_OFFSET 1510568
#define ICH14_OFFSET 1986721
#define ICH15_OFFSET 2159628

//SCALING Calibration
#define VCH1_SCALE 585.73584f
#define VCH2_SCALE 584.500061f
#define VCH3_SCALE 587.264709f

#define ICH1_SCALE 370.544952f
#define ICH2_SCALE 370.016327f
#define ICH3_SCALE 371.218597f
#define ICH4_SCALE 371.051086f
#define ICH5_SCALE 370.430145f
#define ICH6_SCALE 370.805328f
#define ICH7_SCALE 370.685242f
#define ICH8_SCALE 371.137573f
#define ICH9_SCALE 370.412445f
#define ICH10_SCALE 370.492371f
#define ICH11_SCALE 370.808472f
#define ICH12_SCALE 370.751373f
#define ICH13_SCALE 370.424622f
#define ICH14_SCALE 370.948212f
#define ICH15_SCALE 370.890533f

#endif

#if Calibration_Index == PMU3
// OFFSET Calibration

#define VCH1_OFFSET 1203244
#define VCH2_OFFSET 1257220
#define VCH3_OFFSET 1793704

#define ICH1_OFFSET 506142
#define ICH2_OFFSET 242075
#define ICH3_OFFSET 365429
#define ICH4_OFFSET 24865
#define ICH5_OFFSET 190261
#define ICH6_OFFSET 189449
#define ICH7_OFFSET 407529
#define ICH8_OFFSET 1843443
#define ICH9_OFFSET -48387
#define ICH10_OFFSET 606664
#define ICH11_OFFSET 97572
#define ICH12_OFFSET 1331041
#define ICH13_OFFSET 1039180
#define ICH14_OFFSET 1472782
#define ICH15_OFFSET 1900444

//SCALING Calibration
#define VCH1_SCALE 585.679077f
#define VCH2_SCALE 585.557007f
#define VCH3_SCALE 586.309998f

#define ICH1_SCALE 370.267487f
#define ICH2_SCALE 370.632813f
#define ICH3_SCALE 370.641052f
#define ICH4_SCALE 370.60083f
#define ICH5_SCALE 370.507294f
#define ICH6_SCALE 370.502136f
#define ICH7_SCALE 364.92038f
#define ICH8_SCALE 359.894653f
#define ICH9_SCALE 368.110443f
#define ICH10_SCALE 370.055939f
#define ICH11_SCALE 366.840515f
#define ICH12_SCALE 370.424713f
#define ICH13_SCALE 370.375244f
#define ICH14_SCALE 370.25473f
#define ICH15_SCALE 370.662323f

#endif

#if Calibration_Index == PMU4
// OFFSET Calibration

#define VCH1_OFFSET 759525
#define VCH2_OFFSET 1094309
#define VCH3_OFFSET 1433157

#define ICH1_OFFSET 1687529
#define ICH2_OFFSET 1340710
#define ICH3_OFFSET 1353229
#define ICH4_OFFSET 1615918
#define ICH5_OFFSET 1531334
#define ICH6_OFFSET 1403233
#define ICH7_OFFSET 2864010
#define ICH8_OFFSET 1459324
#define ICH9_OFFSET 633799
#define ICH10_OFFSET -41375
#define ICH11_OFFSET 912321
#define ICH12_OFFSET 844425
#define ICH13_OFFSET 1162742
#define ICH14_OFFSET 1285559
#define ICH15_OFFSET 1702627

//SCALING Calibration
#define VCH1_SCALE 584.057007f
#define VCH2_SCALE 585.056519f
#define VCH3_SCALE 584.225281f

#define ICH1_SCALE 369.60141f
#define ICH2_SCALE 369.207947f
#define ICH3_SCALE 369.898743f
#define ICH4_SCALE 369.206635f
#define ICH5_SCALE 369.900208f
#define ICH6_SCALE 370.311066f
#define ICH7_SCALE 369.09729f
#define ICH8_SCALE 369.077728f
#define ICH9_SCALE 371.701599f
#define ICH10_SCALE 369.71048f
#define ICH11_SCALE 371.051758f
#define ICH12_SCALE 370.980438f
#define ICH13_SCALE 371.088959f
#define ICH14_SCALE 370.811981f
#define ICH15_SCALE 370.848999f

#endif

#if Calibration_Index == PMU5
// OFFSET Calibration

#define VCH1_OFFSET 1157487
#define VCH2_OFFSET 1117285
#define VCH3_OFFSET 1747838

#define ICH1_OFFSET 1121847
#define ICH2_OFFSET 1211202
#define ICH3_OFFSET 794398
#define ICH4_OFFSET 1056174
#define ICH5_OFFSET 1034841
#define ICH6_OFFSET 1154738
#define ICH7_OFFSET 1870458
#define ICH8_OFFSET 873949
#define ICH9_OFFSET 2427
#define ICH10_OFFSET -427756
#define ICH11_OFFSET 448368
#define ICH12_OFFSET 859821
#define ICH13_OFFSET 681865
#define ICH14_OFFSET 1344372
#define ICH15_OFFSET 1633544

//SCALING Calibration
#define VCH1_SCALE 587.186096f
#define VCH2_SCALE 585.500183f
#define VCH3_SCALE 585.545532f

#define ICH1_SCALE 370.219421f
#define ICH2_SCALE 370.039825f
#define ICH3_SCALE 369.973755f
#define ICH4_SCALE 369.607269f
#define ICH5_SCALE 369.888824f
#define ICH6_SCALE 370.033997f
#define ICH7_SCALE 370.377014f
#define ICH8_SCALE 370.309204f
#define ICH9_SCALE 370.250092f
#define ICH10_SCALE 370.381348f
#define ICH11_SCALE 370.644257f
#define ICH12_SCALE 371.220978f
#define ICH13_SCALE 370.667938f
#define ICH14_SCALE 370.276611f
#define ICH15_SCALE 370.769226f

#endif

#if Calibration_Index == PMU5x
// OFFSET Calibration

#define VCH1_OFFSET 1027735
#define VCH2_OFFSET 1367042
#define VCH3_OFFSET 1697088
                    
#define ICH1_OFFSET 1931363
#define ICH2_OFFSET 1697000
#define ICH3_OFFSET 1630693
#define ICH4_OFFSET 1698694
#define ICH5_OFFSET 1489026
#define ICH6_OFFSET 1628230
#define ICH7_OFFSET 1209354
#define ICH8_OFFSET 1209354
#define ICH9_OFFSET 853000
#define ICH10_OFFSET 301323
#define ICH11_OFFSET 1277362
#define ICH12_OFFSET 1698159
#define ICH13_OFFSET 1394854
#define ICH14_OFFSET 1808613
#define ICH15_OFFSET 2199247

//SCALING Calibration
#define VCH1_SCALE 584.190918f
#define VCH2_SCALE 587.309326f
#define VCH3_SCALE 586.94635f

#define ICH1_SCALE 373.65271f
#define ICH2_SCALE 372.946289f
#define ICH3_SCALE 373.364166f
#define ICH4_SCALE 373.424713f
#define ICH5_SCALE 373.260773f
#define ICH6_SCALE 373.488434f
#define ICH7_SCALE 365.864227f
#define ICH8_SCALE 373.936157f
#define ICH9_SCALE 373.853333f
#define ICH10_SCALE	374.059601f
#define ICH11_SCALE	374.539124f
#define ICH12_SCALE	373.8284f
#define ICH13_SCALE	374.123322f
#define ICH14_SCALE	374.716919f
#define ICH15_SCALE	373.991577f

#endif

#if Calibration_Index == PMU6
// OFFSET Calibration

#define VCH1_OFFSET 939654
#define VCH2_OFFSET 1239735
#define VCH3_OFFSET 1451842

#define ICH1_OFFSET 354800
#define ICH2_OFFSET 490220
#define ICH3_OFFSET 102140
#define ICH4_OFFSET 523782
#define ICH5_OFFSET 493766
#define ICH6_OFFSET 612115
#define ICH7_OFFSET 1876499
#define ICH8_OFFSET 170986
#define ICH9_OFFSET -200369
#define ICH10_OFFSET -836810
#define ICH11_OFFSET 420788
#define ICH12_OFFSET 614054
#define ICH13_OFFSET 565601
#define ICH14_OFFSET 1086603
#define ICH15_OFFSET 1734454

//SCALING Calibration
#define VCH1_SCALE 585.272522f
#define VCH2_SCALE 584.6828f
#define VCH3_SCALE 584.988586f

#define ICH1_SCALE 370.110504f
#define ICH2_SCALE 369.8396f
#define ICH3_SCALE 370.51944f
#define ICH4_SCALE 370.29364f
#define ICH5_SCALE 370.516876f
#define ICH6_SCALE 370.07724f
#define ICH7_SCALE 369.546356f
#define ICH8_SCALE 370.101257f
#define ICH9_SCALE 370.571136f
#define ICH10_SCALE 370.745026f
#define ICH11_SCALE 370.97171f
#define ICH12_SCALE 370.952637f
#define ICH13_SCALE 370.361298f
#define ICH14_SCALE 370.524231f
#define ICH15_SCALE 370.944153f

#endif

#if Calibration_Index == PMU6x
// OFFSET Calibration

#define VCH1_OFFSET 1142624
#define VCH2_OFFSET 1262092
#define VCH3_OFFSET 1786495
                    
#define ICH1_OFFSET 1646064
#define ICH2_OFFSET 1611209
#define ICH3_OFFSET 1619825
#define ICH4_OFFSET 1529966
#define ICH5_OFFSET 1701307
#define ICH6_OFFSET 1775655
#define ICH7_OFFSET 2715042
#define ICH8_OFFSET 1074236
#define ICH9_OFFSET 646012
#define ICH10_OFFSET 414509
#define ICH11_OFFSET 1336486
#define ICH12_OFFSET 1362338
#define ICH13_OFFSET 1551791
#define ICH14_OFFSET 1718427
#define ICH15_OFFSET 1860911

//SCALING Calibration
#define VCH1_SCALE 587.547485f
#define VCH2_SCALE 585.44397f
#define VCH3_SCALE 585.738708f

#define ICH1_SCALE 373.464264f
#define ICH2_SCALE 373.339325f
#define ICH3_SCALE 373.593262f
#define ICH4_SCALE 374.597809f
#define ICH5_SCALE 373.806244f
#define ICH6_SCALE 373.121155f
#define ICH7_SCALE 373.378876f
#define ICH8_SCALE 374.000824f
#define ICH9_SCALE 373.460846f
#define ICH10_SCALE	374.034882f
#define ICH11_SCALE	374.055695f
#define ICH12_SCALE	374.209656f
#define ICH13_SCALE	374.36084f
#define ICH14_SCALE	374.629425f
#define ICH15_SCALE	373.182159f

#endif
#if Calibration_Index == PMU7
// OFFSET Calibration

#define VCH1_OFFSET 1129765
#define VCH2_OFFSET 1356958
#define VCH3_OFFSET 1816609

#define ICH1_OFFSET 1470743
#define ICH2_OFFSET 1087739
#define ICH3_OFFSET 1069325
#define ICH4_OFFSET 932239
#define ICH5_OFFSET 1099807
#define ICH6_OFFSET 1223733
#define ICH7_OFFSET 2480362
#define ICH8_OFFSET 627641
#define ICH9_OFFSET 318167
#define ICH10_OFFSET -168453
#define ICH11_OFFSET 818640
#define ICH12_OFFSET 1151652
#define ICH13_OFFSET 996494
#define ICH14_OFFSET 1360926
#define ICH15_OFFSET 1958564

//SCALING Calibration
#define VCH1_SCALE 586.179077f
#define VCH2_SCALE 585.3172f
#define VCH3_SCALE 586.237732f

#define ICH1_SCALE 371.160431f
#define ICH2_SCALE 371.175659f
#define ICH3_SCALE 371.542389f
#define ICH4_SCALE 371.279205f
#define ICH5_SCALE 371.406036f
#define ICH6_SCALE 371.194611f
#define ICH7_SCALE 370.962128f
#define ICH8_SCALE 371.279053f
#define ICH9_SCALE 369.920654f
#define ICH10_SCALE 369.794464f
#define ICH11_SCALE 370.406525f
#define ICH12_SCALE 370.406525f
#define ICH13_SCALE 369.894012f
#define ICH14_SCALE 370.114563f
#define ICH15_SCALE 370.244324f

#endif

#if Calibration_Index == PMU7x
// OFFSET Calibration

#define VCH1_OFFSET 837998
#define VCH2_OFFSET 1235135
#define VCH3_OFFSET 1659732
                    
#define ICH1_OFFSET 1572629
#define ICH2_OFFSET 1628756
#define ICH3_OFFSET 1739138
#define ICH4_OFFSET 1710897
#define ICH5_OFFSET 1663262
#define ICH6_OFFSET 1591420
#define ICH7_OFFSET 3040457
#define ICH8_OFFSET 1462612
#define ICH9_OFFSET 568137
#define ICH10_OFFSET 486829
#define ICH11_OFFSET 1425954
#define ICH12_OFFSET 1500481
#define ICH13_OFFSET 2027074
#define ICH14_OFFSET 1905165
#define ICH15_OFFSET 2060684

//SCALING Calibration
#define VCH1_SCALE 583.819458f
#define VCH2_SCALE 585.51123f
#define VCH3_SCALE 584.452148f

#define ICH1_SCALE 373.667542f
#define ICH2_SCALE 374.054749f
#define ICH3_SCALE 373.227203f
#define ICH4_SCALE 373.846954f
#define ICH5_SCALE 373.240723f
#define ICH6_SCALE 373.411652f
#define ICH7_SCALE 371.727966f
#define ICH8_SCALE 373.816071f
#define ICH9_SCALE 373.457947f
#define ICH10_SCALE	374.408569f
#define ICH11_SCALE	373.575806f
#define ICH12_SCALE	373.975494f
#define ICH13_SCALE	374.075378f
#define ICH14_SCALE	373.927948f
#define ICH15_SCALE	373.943909f

#endif

#if Calibration_Index == PMU8
// OFFSET Calibration

#define VCH1_OFFSET 1169717
#define VCH2_OFFSET 1103731
#define VCH3_OFFSET 1682552

#define ICH1_OFFSET 1164912
#define ICH2_OFFSET 1051417
#define ICH3_OFFSET 941219
#define ICH4_OFFSET 1136194
#define ICH5_OFFSET 1102910
#define ICH6_OFFSET 807296
#define ICH7_OFFSET 2276316
#define ICH8_OFFSET 686330
#define ICH9_OFFSET 108832
#define ICH10_OFFSET -272079
#define ICH11_OFFSET 505938
#define ICH12_OFFSET 367998
#define ICH13_OFFSET 577966
#define ICH14_OFFSET 1094179
#define ICH15_OFFSET 1452956

//SCALING Calibration
#define VCH1_SCALE 585.320129f
#define VCH2_SCALE 586.809937f
#define VCH3_SCALE 587.488159f

#define ICH1_SCALE 369.557678f
#define ICH2_SCALE 369.249878f
#define ICH3_SCALE 370.479797f
#define ICH4_SCALE 370.044189f
#define ICH5_SCALE 369.893524f
#define ICH6_SCALE 369.85022f
#define ICH7_SCALE 369.166992f
#define ICH8_SCALE 370.174286f
#define ICH9_SCALE 370.12851f
#define ICH10_SCALE 370.516754f
#define ICH11_SCALE 370.926758f
#define ICH12_SCALE 370.684296f
#define ICH13_SCALE 370.890961f
#define ICH14_SCALE 370.535034f
#define ICH15_SCALE 370.988098f

#endif

#if Calibration_Index == PMU9
// OFFSET Calibration

#define VCH1_OFFSET 1018712
#define VCH2_OFFSET 1338975
#define VCH3_OFFSET 1718662

#define ICH1_OFFSET 1214339
#define ICH2_OFFSET 1392956
#define ICH3_OFFSET 1122097
#define ICH4_OFFSET 1320297
#define ICH5_OFFSET 1069901
#define ICH6_OFFSET 1214812
#define ICH7_OFFSET 2359392
#define ICH8_OFFSET 610151
#define ICH9_OFFSET 74514
#define ICH10_OFFSET -396645
#define ICH11_OFFSET 702781
#define ICH12_OFFSET 726392
#define ICH13_OFFSET 577148
#define ICH14_OFFSET 656667
#define ICH15_OFFSET 1208497

//SCALING Calibration
#define VCH1_SCALE 583.182617f
#define VCH2_SCALE 583.988037f
#define VCH3_SCALE 582.739441f

#define ICH1_SCALE 370.266296f
#define ICH2_SCALE 370.219421f
#define ICH3_SCALE 370.031036f
#define ICH4_SCALE 369.445801f
#define ICH5_SCALE 370.542114f
#define ICH6_SCALE 370.466705f
#define ICH7_SCALE 369.685455f
#define ICH8_SCALE 370.304779f
#define ICH9_SCALE 370.245758f
#define ICH10_SCALE 370.486481f
#define ICH11_SCALE 370.167999f
#define ICH12_SCALE 370.756897f
#define ICH13_SCALE 370.424133f
#define ICH14_SCALE 369.847931f
#define ICH15_SCALE 370.164795f

#endif

#if Calibration_Index == PMU10
// OFFSET Calibration

#define VCH1_OFFSET 879727
#define VCH2_OFFSET 1053831
#define VCH3_OFFSET 1522299

#define ICH1_OFFSET 1276183
#define ICH2_OFFSET 1061132
#define ICH3_OFFSET 865250
#define ICH4_OFFSET 927358
#define ICH5_OFFSET 1082010
#define ICH6_OFFSET 1073762
#define ICH7_OFFSET 2679404
#define ICH8_OFFSET 687753
#define ICH9_OFFSET 490433
#define ICH10_OFFSET 365044
#define ICH11_OFFSET 904761
#define ICH12_OFFSET 1227111
#define ICH13_OFFSET 1297632
#define ICH14_OFFSET 1275996
#define ICH15_OFFSET 1817149

//SCALING Calibration
#define VCH1_SCALE 584.682129f
#define VCH2_SCALE 583.996277f
#define VCH3_SCALE 585.014648f

#define ICH1_SCALE 370.412781f
#define ICH2_SCALE 369.685699f
#define ICH3_SCALE 370.517578f
#define ICH4_SCALE 370.548523f
#define ICH5_SCALE 370.034363f
#define ICH6_SCALE 370.631042f
#define ICH7_SCALE 369.686462f
#define ICH8_SCALE 370.614075f
#define ICH9_SCALE 372.390015f
#define ICH10_SCALE 371.724213f
#define ICH11_SCALE 371.389008f
#define ICH12_SCALE 372.428864f
#define ICH13_SCALE 372.481201f
#define ICH14_SCALE 371.738373f
#define ICH15_SCALE 372.233826f

#endif

#if Calibration_Index == PMU11
// OFFSET Calibration

#define VCH1_OFFSET 1113335
#define VCH2_OFFSET 1381928
#define VCH3_OFFSET 1184436

#define ICH1_OFFSET 958293
#define ICH2_OFFSET 985916
#define ICH3_OFFSET 1001443
#define ICH4_OFFSET 842453
#define ICH5_OFFSET 800912
#define ICH6_OFFSET 886770
#define ICH7_OFFSET 2239185
#define ICH8_OFFSET 444605
#define ICH9_OFFSET 195627
#define ICH10_OFFSET -245946
#define ICH11_OFFSET 641845
#define ICH12_OFFSET 715426
#define ICH13_OFFSET 851533
#define ICH14_OFFSET 1124948
#define ICH15_OFFSET 1696224

//SCALING Calibration
#define VCH1_SCALE 585.037781f
#define VCH2_SCALE 584.485962f
#define VCH3_SCALE 585.487976f

#define ICH1_SCALE 370.045929f
#define ICH2_SCALE 370.333435f
#define ICH3_SCALE 369.755829f
#define ICH4_SCALE 369.911774f
#define ICH5_SCALE 370.395935f
#define ICH6_SCALE 369.493866f
#define ICH7_SCALE 369.701538f
#define ICH8_SCALE 370.554443f
#define ICH9_SCALE 370.028107f
#define ICH10_SCALE 368.456207f
#define ICH11_SCALE 370.361237f
#define ICH12_SCALE 369.94101f
#define ICH13_SCALE 370.631836f
#define ICH14_SCALE 370.359741f
#define ICH15_SCALE 370.467194f

#endif

#if Calibration_Index == PMU12
// OFFSET Calibration

#define VCH1_OFFSET 422499
#define VCH2_OFFSET 414117
#define VCH3_OFFSET 716304

#define ICH1_OFFSET 1600267
#define ICH2_OFFSET 1669953
#define ICH3_OFFSET 1866109
#define ICH4_OFFSET 1531040
#define ICH5_OFFSET 1849904
#define ICH6_OFFSET 1678092
#define ICH7_OFFSET 2122036
#define ICH8_OFFSET 1695432
#define ICH9_OFFSET 1134505
#define ICH10_OFFSET 1090305
#define ICH11_OFFSET 1452372
#define ICH12_OFFSET 1580571
#define ICH13_OFFSET 1729706
#define ICH14_OFFSET 1656117
#define ICH15_OFFSET 1855934

//SCALING Calibration
#define VCH1_SCALE 585.773987f
#define VCH2_SCALE 587.778076f
#define VCH3_SCALE 583.724731f

#define ICH1_SCALE 372.739838f
#define ICH2_SCALE 376.107941f
#define ICH3_SCALE 372.828522f
#define ICH4_SCALE 373.488403f
#define ICH5_SCALE 376.328796f
#define ICH6_SCALE 372.904877f
#define ICH7_SCALE 372.062286f
#define ICH8_SCALE 375.240082f
#define ICH9_SCALE 370.961487f
#define ICH10_SCALE 371.536469f
#define ICH11_SCALE 374.185547f
#define ICH12_SCALE 370.974487f
#define ICH13_SCALE 371.272369f
#define ICH14_SCALE 374.607025f
#define ICH15_SCALE 370.570709f

#endif

#if Calibration_Index == PMU13
// OFFSET Calibration

#define VCH1_OFFSET 1307353
#define VCH2_OFFSET 1886412
#define VCH3_OFFSET 2032799

#define ICH1_OFFSET 1940342
#define ICH2_OFFSET 1926414
#define ICH3_OFFSET 1959878
#define ICH4_OFFSET 1885749
#define ICH5_OFFSET 2157976
#define ICH6_OFFSET 1882330
#define ICH7_OFFSET 2152962
#define ICH8_OFFSET 2243226
#define ICH9_OFFSET 1195807
#define ICH10_OFFSET 1407480
#define ICH11_OFFSET 1704111
#define ICH12_OFFSET 1731133
#define ICH13_OFFSET 2016954
#define ICH14_OFFSET 1893223
#define ICH15_OFFSET 2281888

//SCALING Calibration
#define VCH1_SCALE 587.773987f
#define VCH2_SCALE 585.691162f
#define VCH3_SCALE 586.496948f

#define ICH1_SCALE 371.550629f
#define ICH2_SCALE 371.596497f
#define ICH3_SCALE 371.677338f
#define ICH4_SCALE 371.37851f
#define ICH5_SCALE 371.078033f
#define ICH6_SCALE 371.91684f
#define ICH7_SCALE 370.920807f
#define ICH8_SCALE 371.100372f
#define ICH9_SCALE 372.008026f
#define ICH10_SCALE 371.590057f
#define ICH11_SCALE 371.378754f
#define ICH12_SCALE 371.471252f
#define ICH13_SCALE 371.742889f
#define ICH14_SCALE 370.986572f
#define ICH15_SCALE 371.344299f

#endif

#if Calibration_Index == PMU14
// OFFSET Calibration

#define VCH1_OFFSET 745121
#define VCH2_OFFSET 1090262
#define VCH3_OFFSET 1489260

#define ICH1_OFFSET 634901
#define ICH2_OFFSET 415873
#define ICH3_OFFSET 466041
#define ICH4_OFFSET 500647
#define ICH5_OFFSET 367703
#define ICH6_OFFSET 515260
#define ICH7_OFFSET 1690812
#define ICH8_OFFSET 93407
#define ICH9_OFFSET 574869
#define ICH10_OFFSET 98292
#define ICH11_OFFSET 677783
#define ICH12_OFFSET 1098433
#define ICH13_OFFSET 1400585
#define ICH14_OFFSET 1463372
#define ICH15_OFFSET 1987991

//SCALING Calibration
#define VCH1_SCALE 579.179932f
#define VCH2_SCALE 583.941284f
#define VCH3_SCALE 582.223755f

#define ICH1_SCALE 373.299713f
#define ICH2_SCALE 373.433105f
#define ICH3_SCALE 373.201508f
#define ICH4_SCALE 373.040375f
#define ICH5_SCALE 372.629578f
#define ICH6_SCALE 372.000488f
#define ICH7_SCALE 375.00174f
#define ICH8_SCALE 374.238373f
#define ICH9_SCALE 374.143494f
#define ICH10_SCALE 375.236328f
#define ICH11_SCALE 378.207489f
#define ICH12_SCALE 378.391235f
#define ICH13_SCALE 378.51593f
#define ICH14_SCALE 378.450348f
#define ICH15_SCALE 378.017273f

#endif

#if Calibration_Index == ARAS_PMU1
// OFFSET Calibration

#define VCH1_OFFSET 1195301
#define VCH2_OFFSET 1263404
#define VCH3_OFFSET 1665625
                   
#define ICH1_OFFSET 1426771
#define ICH2_OFFSET 1454894
#define ICH3_OFFSET 1616786
#define ICH4_OFFSET 1424935
#define ICH5_OFFSET 1567417
#define ICH6_OFFSET 837177
#define ICH7_OFFSET 2476164
#define ICH8_OFFSET 1347848
#define ICH9_OFFSET 770431
#define ICH10_OFFSET 230554
#define ICH11_OFFSET 1135678
#define ICH12_OFFSET 1362941
#define ICH13_OFFSET 1535367
#define ICH14_OFFSET 1845560
#define ICH15_OFFSET 2182755

//SCALING Calibration
#define VCH1_SCALE 588.478088f
#define VCH2_SCALE 586.056824f
#define VCH3_SCALE 586.414551f

#define ICH1_SCALE 376.065552f
#define ICH2_SCALE 376.933319f
#define ICH3_SCALE 377.460693f
#define ICH4_SCALE 375.475281f
#define ICH5_SCALE 376.268677f
#define ICH6_SCALE 374.581665f
#define ICH7_SCALE 375.228973f
#define ICH8_SCALE 375.578125f
#define ICH9_SCALE 374.444397f
#define ICH10_SCALE 374.400513f
#define ICH11_SCALE 374.480865f
#define ICH12_SCALE 374.037689f
#define ICH13_SCALE 374.455994f
#define ICH14_SCALE 374.175842f
#define ICH15_SCALE 374.401215f

#endif

#if Calibration_Index == PMU16
// OFFSET Calibration

#define VCH1_OFFSET 876957
#define VCH2_OFFSET 1038477
#define VCH3_OFFSET 1432542
                   
#define ICH1_OFFSET 1262777
#define ICH2_OFFSET 1325395
#define ICH3_OFFSET 1400403
#define ICH4_OFFSET 1530582
#define ICH5_OFFSET 1383695
#define ICH6_OFFSET 1583884
#define ICH7_OFFSET 2337288
#define ICH8_OFFSET 1417686
#define ICH9_OFFSET 728579
#define ICH10_OFFSET 23195
#define ICH11_OFFSET 997315
#define ICH12_OFFSET 1000749
#define ICH13_OFFSET 1848529
#define ICH14_OFFSET 1768558
#define ICH15_OFFSET 2028367

//SCALING Calibration
#define VCH1_SCALE 586.328064f
#define VCH2_SCALE 585.832947f
#define VCH3_SCALE 582.931152f
                   
#define ICH1_SCALE 376.168457f
#define ICH2_SCALE 376.421753f
#define ICH3_SCALE 377.175476f
#define ICH4_SCALE 375.634521f
#define ICH5_SCALE 375.416565f
#define ICH6_SCALE 376.418274f
#define ICH7_SCALE 375.931061f
#define ICH8_SCALE 376.455139f
#define ICH9_SCALE 376.114777f
#define ICH10_SCALE 375.19339f
#define ICH11_SCALE 376.143005f
#define ICH12_SCALE 376.73764f
#define ICH13_SCALE 374.479187f
#define ICH14_SCALE 375.833344f
#define ICH15_SCALE 376.539948f

#endif

#if Calibration_Index == PMU17
// OFFSET Calibration

#define VCH1_OFFSET 969599
#define VCH2_OFFSET 1166210
#define VCH3_OFFSET 1679509
                    
#define ICH1_OFFSET 1616946
#define ICH2_OFFSET 1524217
#define ICH3_OFFSET 1669619
#define ICH4_OFFSET 1466883
#define ICH5_OFFSET 1482692
#define ICH6_OFFSET 1349803
#define ICH7_OFFSET 2639964
#define ICH8_OFFSET 1500523
#define ICH9_OFFSET 791740
#define ICH10_OFFSET 254517
#define ICH11_OFFSET 971915
#define ICH12_OFFSET 1295733
#define ICH13_OFFSET 1383633
#define ICH14_OFFSET 1758356
#define ICH15_OFFSET 2118592

//SCALING Calibration
#define VCH1_SCALE 584.522339f
#define VCH2_SCALE 582.223328f
#define VCH3_SCALE 581.343933f

#define ICH1_SCALE 373.663513f
#define ICH2_SCALE 374.338226f
#define ICH3_SCALE 374.728638f
#define ICH4_SCALE 372.697205f
#define ICH5_SCALE 373.575104f
#define ICH6_SCALE 374.05307f
#define ICH7_SCALE 372.934113f
#define ICH8_SCALE 373.501007f
#define ICH9_SCALE 374.670105f
#define ICH10_SCALE 373.79126f
#define ICH11_SCALE 373.501007f
#define ICH12_SCALE 374.084015f
#define ICH13_SCALE 372.207794f
#define ICH14_SCALE 372.938629f
#define ICH15_SCALE 373.932434f

#endif

#if Calibration_Index == PMU18
// OFFSET Calibration

#define VCH1_OFFSET 545825
#define VCH2_OFFSET 982562
#define VCH3_OFFSET 1547141
                    
#define ICH1_OFFSET 1540953
#define ICH2_OFFSET 1311050
#define ICH3_OFFSET 1515717
#define ICH4_OFFSET 1211638
#define ICH5_OFFSET 1547290
#define ICH6_OFFSET 1383330
#define ICH7_OFFSET 2731976
#define ICH8_OFFSET 1184584
#define ICH9_OFFSET 158098
#define ICH10_OFFSET -88118//mc
#define ICH11_OFFSET 1050369
#define ICH12_OFFSET 1413654
#define ICH13_OFFSET 1496871
#define ICH14_OFFSET 1530582
#define ICH15_OFFSET 2187814

//SCALING Calibration
#define VCH1_SCALE 585.776794f
#define VCH2_SCALE 587.424072f
#define VCH3_SCALE 584.781128f

#define ICH1_SCALE 374.223267f
#define ICH2_SCALE 375.191772f
#define ICH3_SCALE 375.167023f
#define ICH4_SCALE 374.529694f
#define ICH5_SCALE 375.327667f
#define ICH6_SCALE 375.666656f
#define ICH7_SCALE 374.934479f
#define ICH8_SCALE 376.279144f
#define ICH9_SCALE 376.107819f
#define ICH10_SCALE 376.006622f
#define ICH11_SCALE 376.808746f
#define ICH12_SCALE 377.416656f
#define ICH13_SCALE 376.674896f
#define ICH14_SCALE 377.300079f
#define ICH15_SCALE 377.793671f

#endif
#if Calibration_Index == PMU19
// OFFSET Calibration

#define VCH1_OFFSET 821022
#define VCH2_OFFSET 1350456
#define VCH3_OFFSET 1811294
                    
#define ICH1_OFFSET	1661389
#define ICH2_OFFSET 1721796
#define ICH3_OFFSET 1546372
#define ICH4_OFFSET 1720491
#define ICH5_OFFSET 1710628
#define ICH6_OFFSET 1615279
#define ICH7_OFFSET -2414467//mc
#define ICH8_OFFSET 1814977
#define ICH9_OFFSET 520814
#define ICH10_OFFSET 60572
#define ICH11_OFFSET 1106555
#define ICH12_OFFSET 1403951
#define ICH13_OFFSET 1409103
#define ICH14_OFFSET 1409103
#define ICH15_OFFSET 1883318

//SCALING Calibration
#define VCH1_SCALE 584.180115f
#define VCH2_SCALE 583.592407f
#define VCH3_SCALE 583.359802f

#define ICH1_SCALE 372.365662f
#define ICH2_SCALE 372.726044f
#define ICH3_SCALE 372.535034f
#define ICH4_SCALE 371.020935f
#define ICH5_SCALE 371.883575f
#define ICH6_SCALE 371.856903f
#define ICH7_SCALE 370.721741f
#define ICH8_SCALE 371.86969f
#define ICH9_SCALE 371.551178f
#define ICH10_SCALE 370.104614f
#define ICH11_SCALE 370.56369f
#define ICH12_SCALE 371.256775f
#define ICH13_SCALE 370.733246f
#define ICH14_SCALE 370.212769f
#define ICH15_SCALE 370.658234f

#endif

#if Calibration_Index == PMU20
// OFFSET Calibration

#define VCH1_OFFSET 817029
#define VCH2_OFFSET 1040437
#define VCH3_OFFSET 1740721
                    
#define ICH1_OFFSET 1677106
#define ICH2_OFFSET 1604629
#define ICH3_OFFSET 1453795
#define ICH4_OFFSET 1777569
#define ICH5_OFFSET 1432307
#define ICH6_OFFSET 1576854
#define ICH7_OFFSET 2378264
#define ICH8_OFFSET 1354471
#define ICH9_OFFSET 845659
#define ICH10_OFFSET 62373
#define ICH11_OFFSET 1321572
#define ICH12_OFFSET 1253019
#define ICH13_OFFSET 1436154
#define ICH14_OFFSET 1601123
#define ICH15_OFFSET 1899271

//SCALING Calibration
#define VCH1_SCALE 583.654907f
#define VCH2_SCALE 583.246521f
#define VCH3_SCALE 583.626038f

#define ICH1_SCALE 374.040375f
#define ICH2_SCALE 374.040375f
#define ICH3_SCALE 376.319336f
#define ICH4_SCALE 374.49292f
#define ICH5_SCALE 375.412537f
#define ICH6_SCALE 375.239899f
#define ICH7_SCALE 374.517059f
#define ICH8_SCALE 374.220398f
#define ICH9_SCALE 374.418152f
#define ICH10_SCALE 374.260925f
#define ICH11_SCALE 374.223114f
#define ICH12_SCALE 374.968872f
#define ICH13_SCALE 374.089081f
#define ICH14_SCALE 375.337524f
#define ICH15_SCALE 375.765869f

#endif

#if Calibration_Index == PMU21
// OFFSET Calibration

#define VCH1_OFFSET 1088988
#define VCH2_OFFSET 1316171
#define VCH3_OFFSET 1918535
                    
#define ICH1_OFFSET 1732990
#define ICH2_OFFSET 1624972
#define ICH3_OFFSET 1441595
#define ICH4_OFFSET 2492307
#define ICH5_OFFSET 1653404
#define ICH6_OFFSET 1289899
#define ICH7_OFFSET 2506007
#define ICH8_OFFSET 1481724
#define ICH9_OFFSET 654997
#define ICH10_OFFSET 284495
#define ICH11_OFFSET 1184282
#define ICH12_OFFSET 1525985
#define ICH13_OFFSET 1408219
#define ICH14_OFFSET 1607400
#define ICH15_OFFSET 1840075

//SCALING Calibration
#define VCH1_SCALE 584.664246f
#define VCH2_SCALE 584.170959f
#define VCH3_SCALE 585.442688f

#define ICH1_SCALE 374.188721f
#define ICH2_SCALE 374.979248f
#define ICH3_SCALE 375.388031f
#define ICH4_SCALE 371.588165f
#define ICH5_SCALE 375.101044f
#define ICH6_SCALE 375.221161f
#define ICH7_SCALE 374.595123f
#define ICH8_SCALE 375.426056f
#define ICH9_SCALE 373.56839f
#define ICH10_SCALE 372.95694f
#define ICH11_SCALE 373.818481f
#define ICH12_SCALE 374.192841f
#define ICH13_SCALE 372.28302f
#define ICH14_SCALE 374.624054f
#define ICH15_SCALE 374.602722f

#endif

#if Calibration_Index == PMU22
// OFFSET Calibration

#define VCH1_OFFSET 549479
#define VCH2_OFFSET 1037862
#define VCH3_OFFSET 1686743
                    
#define ICH1_OFFSET 1567436
#define ICH2_OFFSET 1443405
#define ICH3_OFFSET 1632888
#define ICH4_OFFSET 1528642
#define ICH5_OFFSET 1458055
#define ICH6_OFFSET 1344963
#define ICH7_OFFSET 1754344
#define ICH8_OFFSET 1812453
#define ICH9_OFFSET 879603
#define ICH10_OFFSET 103428
#define ICH11_OFFSET 1038396
#define ICH12_OFFSET 1284862
#define ICH13_OFFSET 1351821
#define ICH14_OFFSET 1530500
#define ICH15_OFFSET 1525184

//SCALING Calibration
#define VCH1_SCALE 585.555847f
#define VCH2_SCALE 584.035583f
#define VCH3_SCALE 582.658508f

#define ICH1_SCALE 371.138306f
#define ICH2_SCALE 372.327148f
#define ICH3_SCALE 373.542175f
#define ICH4_SCALE 372.02179f
#define ICH5_SCALE 372.167938f
#define ICH6_SCALE 373.496521f
#define ICH7_SCALE 363.850494f
#define ICH8_SCALE 365.040771f
#define ICH9_SCALE 363.026947f
#define ICH10_SCALE 365.034088f
#define ICH11_SCALE 364.116882f
#define ICH12_SCALE 367.363647f
#define ICH13_SCALE 364.11969f
#define ICH14_SCALE 363.528046f
#define ICH15_SCALE 365.711212f

#endif

#if Calibration_Index == PMU23
// OFFSET Calibration

#define VCH1_OFFSET 1513387
#define VCH2_OFFSET 1478891
#define VCH3_OFFSET 1481953
                    
#define ICH1_OFFSET 1799736
#define ICH2_OFFSET 1680178
#define ICH3_OFFSET 1807112
#define ICH4_OFFSET 1526689
#define ICH5_OFFSET 1774709
#define ICH6_OFFSET 1707716
#define ICH7_OFFSET 4130946
#define ICH8_OFFSET 961678
#define ICH9_OFFSET -119825//mc
#define ICH10_OFFSET -950330//mc
#define ICH11_OFFSET 666512
#define ICH12_OFFSET 1295167
#define ICH13_OFFSET 1424038
#define ICH14_OFFSET 2077683
#define ICH15_OFFSET 2781634

//SCALING Calibration
#define VCH1_SCALE 583.36084f
#define VCH2_SCALE 581.891174f
#define VCH3_SCALE 582.863953f

#define ICH1_SCALE 370.700775f
#define ICH2_SCALE 371.238464f
#define ICH3_SCALE 372.647461f
#define ICH4_SCALE 371.664825f
#define ICH5_SCALE 371.84729f
#define ICH6_SCALE 372.281097f
#define ICH7_SCALE 373.492676f
#define ICH8_SCALE 372.358948f
#define ICH9_SCALE 372.077271f
#define ICH10_SCALE 369.76236f
#define ICH11_SCALE 371.340302f
#define ICH12_SCALE 371.22876f
#define ICH13_SCALE 370.849396f
#define ICH14_SCALE 370.943634f
#define ICH15_SCALE 370.93338f

#endif

#if Calibration_Index == PMU24
// OFFSET Calibration

#define VCH1_OFFSET 1097815
#define VCH2_OFFSET 1313286
#define VCH3_OFFSET 1700513
                    
#define ICH1_OFFSET 1338306
#define ICH2_OFFSET 1215240
#define ICH3_OFFSET 1371876
#define ICH4_OFFSET 1363437
#define ICH5_OFFSET 1493296
#define ICH6_OFFSET 1217099
#define ICH7_OFFSET 2488001
#define ICH8_OFFSET 1183578
#define ICH9_OFFSET 291296
#define ICH10_OFFSET 163573
#define ICH11_OFFSET 1140501
#define ICH12_OFFSET 1277977
#define ICH13_OFFSET 1173267
#define ICH14_OFFSET 1528188
#define ICH15_OFFSET 1771709

//SCALING Calibration
#define VCH1_SCALE 583.177856f
#define VCH2_SCALE 584.340332f
#define VCH3_SCALE 582.381226f

#define ICH1_SCALE 372.830688f
#define ICH2_SCALE 373.682434f
#define ICH3_SCALE 374.431213f
#define ICH4_SCALE 374.338867f
#define ICH5_SCALE 373.985748f
#define ICH6_SCALE 375.68396f
#define ICH7_SCALE 373.655792f
#define ICH8_SCALE 374.511139f
#define ICH9_SCALE 376.047668f
#define ICH10_SCALE 377.132324f
#define ICH11_SCALE 376.364166f
#define ICH12_SCALE 377.141663f
#define ICH13_SCALE 375.577759f
#define ICH14_SCALE 374.700073f
#define ICH15_SCALE 375.365021f

#endif

#if Calibration_Index == PMU25
// OFFSET Calibration

#define VCH1_OFFSET 943252
#define VCH2_OFFSET 1290300
#define VCH3_OFFSET 1745640
                    
#define ICH1_OFFSET 1636952
#define ICH2_OFFSET 1629402
#define ICH3_OFFSET 1509332
#define ICH4_OFFSET 1541305
#define ICH5_OFFSET 1355335
#define ICH6_OFFSET 1727947
#define ICH7_OFFSET 2543126
#define ICH8_OFFSET 1411442
#define ICH9_OFFSET 761951
#define ICH10_OFFSET 484277
#define ICH11_OFFSET 1268547
#define ICH12_OFFSET 1486609
#define ICH13_OFFSET 1751828
#define ICH14_OFFSET 1769793
#define ICH15_OFFSET 1981101

//SCALING Calibration
#define VCH1_SCALE 584.962524f
#define VCH2_SCALE 584.139954f
#define VCH3_SCALE 585.542358f

#define ICH1_SCALE 371.959869f
#define ICH2_SCALE 371.753998f
#define ICH3_SCALE 372.22348f
#define ICH4_SCALE 371.799042f
#define ICH5_SCALE 371.965302f
#define ICH6_SCALE 372.980743f
#define ICH7_SCALE 370.851624f
#define ICH8_SCALE 371.604553f
#define ICH9_SCALE 371.937958f
#define ICH10_SCALE 371.950836f
#define ICH11_SCALE 371.785034f
#define ICH12_SCALE 372.5672f
#define ICH13_SCALE 371.848938f
#define ICH14_SCALE 372.195007f
#define ICH15_SCALE 372.131927f

#endif

#if Calibration_Index == PMU26
// OFFSET Calibration

#define VCH1_OFFSET 1074287
#define VCH2_OFFSET 1256724
#define VCH3_OFFSET 1619477
                    
#define ICH1_OFFSET 1805241
#define ICH2_OFFSET 1625843
#define ICH3_OFFSET 1684179
#define ICH4_OFFSET 1281722
#define ICH5_OFFSET 1742721
#define ICH6_OFFSET 1570805
#define ICH7_OFFSET 2684581
#define ICH8_OFFSET 1279057
#define ICH9_OFFSET 333264
#define ICH10_OFFSET 375329
#define ICH11_OFFSET 995140
#define ICH12_OFFSET 1576227
#define ICH13_OFFSET 1422852
#define ICH14_OFFSET 1609291
#define ICH15_OFFSET 2120516

//SCALING Calibration
#define VCH1_SCALE 585.963806f
#define VCH2_SCALE 583.594604f
#define VCH3_SCALE 586.247253f

#define ICH1_SCALE 372.067535f
#define ICH2_SCALE 372.73584f
#define ICH3_SCALE 373.5737f
#define ICH4_SCALE 372.450226f
#define ICH5_SCALE 372.336639f
#define ICH6_SCALE 372.358032f
#define ICH7_SCALE 371.336029f
#define ICH8_SCALE 371.853912f
#define ICH9_SCALE 371.446167f
#define ICH10_SCALE 372.377502f
#define ICH11_SCALE 372.668365f
#define ICH12_SCALE 373.045563f
#define ICH13_SCALE 372.880035f
#define ICH14_SCALE 372.583313f
#define ICH15_SCALE 372.477295f

#endif

#if Calibration_Index == PMU27
// OFFSET Calibration

#define VCH1_OFFSET 975175
#define VCH2_OFFSET 1169916
#define VCH3_OFFSET 1602488
                    
#define ICH1_OFFSET 1488686
#define ICH2_OFFSET 1202843
#define ICH3_OFFSET 1267536
#define ICH4_OFFSET 1359088
#define ICH5_OFFSET 1232592
#define ICH6_OFFSET 1259252
#define ICH7_OFFSET 2726835
#define ICH8_OFFSET 1115705
#define ICH9_OFFSET 826854
#define ICH10_OFFSET 244509
#define ICH11_OFFSET 1006468
#define ICH12_OFFSET 1216026
#define ICH13_OFFSET 1714683
#define ICH14_OFFSET 1984578
#define ICH15_OFFSET 1966715

//SCALING Calibration
#define VCH1_SCALE 585.984314f
#define VCH2_SCALE 585.314453f
#define VCH3_SCALE 585.527893f

#define ICH1_SCALE 372.726807f
#define ICH2_SCALE 372.852539f
#define ICH3_SCALE 373.217438f
#define ICH4_SCALE 372.198364f
#define ICH5_SCALE 372.694977f
#define ICH6_SCALE 372.98996f
#define ICH7_SCALE 372.782166f
#define ICH8_SCALE 373.891388f
#define ICH9_SCALE 374.122345f
#define ICH10_SCALE 372.976624f
#define ICH11_SCALE 374.174408f
#define ICH12_SCALE 375.184326f
#define ICH13_SCALE 374.104279f
#define ICH14_SCALE 374.694031f
#define ICH15_SCALE 375.249908f

#endif

#if Calibration_Index == PMU28
// OFFSET Calibration

#define VCH1_OFFSET 824532
#define VCH2_OFFSET 1154028
#define VCH3_OFFSET 1809649
                    
#define ICH1_OFFSET 1681674
#define ICH2_OFFSET 1636496
#define ICH3_OFFSET 1576701
#define ICH4_OFFSET 1661196
#define ICH5_OFFSET 1397857
#define ICH6_OFFSET 1636635
#define ICH7_OFFSET 2945867
#define ICH8_OFFSET 1219573
#define ICH9_OFFSET 810819
#define ICH10_OFFSET 207001
#define ICH11_OFFSET 1282047
#define ICH12_OFFSET 1122442
#define ICH13_OFFSET 1463801
#define ICH14_OFFSET 1547614
#define ICH15_OFFSET 2290606

//SCALING Calibration
#define VCH1_SCALE 581.393494f
#define VCH2_SCALE 585.550415f
#define VCH3_SCALE 582.362244f

#define ICH1_SCALE 375.804169f
#define ICH2_SCALE 374.363342f
#define ICH3_SCALE 375.099823f
#define ICH4_SCALE 373.136078f
#define ICH5_SCALE 375.717438f
#define ICH6_SCALE 375.630524f
#define ICH7_SCALE 372.770386f
#define ICH8_SCALE 375.336334f
#define ICH9_SCALE 376.1586f
#define ICH10_SCALE 376.099243f
#define ICH11_SCALE 374.250946f
#define ICH12_SCALE 374.115662f
#define ICH13_SCALE 375.853119f
#define ICH14_SCALE 376.233459f
#define ICH15_SCALE 376.541534f

#endif

#if Calibration_Index == PMU29
// OFFSET Calibration

#define VCH1_OFFSET 852463
#define VCH2_OFFSET 1127405
#define VCH3_OFFSET 1376635
                    
#define ICH1_OFFSET 1558680
#define ICH2_OFFSET 1459420
#define ICH3_OFFSET 1358782
#define ICH4_OFFSET 1402369
#define ICH5_OFFSET 1435671
#define ICH6_OFFSET 1472811
#define ICH7_OFFSET 2461339
#define ICH8_OFFSET 1026615
#define ICH9_OFFSET 540269
#define ICH10_OFFSET 259097
#define ICH11_OFFSET 1390804
#define ICH12_OFFSET 1470027
#define ICH13_OFFSET 1516981
#define ICH14_OFFSET 1627822
#define ICH15_OFFSET 1744400

//SCALING Calibration
#define VCH1_SCALE 585.242798f
#define VCH2_SCALE 586.080017f
#define VCH3_SCALE 584.174561f

#define ICH1_SCALE 371.807739f
#define ICH2_SCALE 372.118042f
#define ICH3_SCALE 372.051636f
#define ICH4_SCALE 372.919403f
#define ICH5_SCALE 372.999573f
#define ICH6_SCALE 373.092255f
#define ICH7_SCALE 371.522827f
#define ICH8_SCALE 372.387939f
#define ICH9_SCALE 372.655273f
#define ICH10_SCALE 372.48468f
#define ICH11_SCALE 372.164154f
#define ICH12_SCALE 373.343933f
#define ICH13_SCALE 372.071625f
#define ICH14_SCALE 372.779785f
#define ICH15_SCALE 372.689941f

#endif

#if Calibration_Index == PMU30
// OFFSET Calibration

#define VCH1_OFFSET 745760
#define VCH2_OFFSET 1211984
#define VCH3_OFFSET 1390162
                    
#define ICH1_OFFSET 1506589
#define ICH2_OFFSET 1520890
#define ICH3_OFFSET 1529070
#define ICH4_OFFSET 1474139
#define ICH5_OFFSET 1605663
#define ICH6_OFFSET 1732174
#define ICH7_OFFSET 2803810
#define ICH8_OFFSET 1365713
#define ICH9_OFFSET 595821
#define ICH10_OFFSET 76487
#define ICH11_OFFSET 1407078
#define ICH12_OFFSET 1493236
#define ICH13_OFFSET 1636743
#define ICH14_OFFSET 1807638
#define ICH15_OFFSET 1868202

//SCALING Calibration
#define VCH1_SCALE 586.675354f
#define VCH2_SCALE 584.193542f
#define VCH3_SCALE 585.498657f

#define ICH1_SCALE 371.580994f
#define ICH2_SCALE 371.856598f
#define ICH3_SCALE 371.5896f
#define ICH4_SCALE 372.123077f
#define ICH5_SCALE 373.716278f
#define ICH6_SCALE 373.378906f
#define ICH7_SCALE 371.577606f
#define ICH8_SCALE 372.675964f
#define ICH9_SCALE 370.874481f
#define ICH10_SCALE 371.219604f
#define ICH11_SCALE 372.034698f
#define ICH12_SCALE 372.700439f
#define ICH13_SCALE 371.940125f
#define ICH14_SCALE 370.87207f
#define ICH15_SCALE 371.817902f

#endif

#if Calibration_Index == PMU31
// OFFSET Calibration

#define VCH1_OFFSET 582975
#define VCH2_OFFSET 1155713
#define VCH3_OFFSET 1403409
                    
#define ICH1_OFFSET 1722185
#define ICH2_OFFSET 1614569
#define ICH3_OFFSET 1720275
#define ICH4_OFFSET 1496654
#define ICH5_OFFSET 1549539
#define ICH6_OFFSET 1669403
#define ICH7_OFFSET 2543882
#define ICH8_OFFSET 1457942
#define ICH9_OFFSET 802722
#define ICH10_OFFSET 144623
#define ICH11_OFFSET 1182074
#define ICH12_OFFSET 1219292
#define ICH13_OFFSET 1620158
#define ICH14_OFFSET 1764049
#define ICH15_OFFSET 1866412

//SCALING Calibration
#define VCH1_SCALE 583.247253f
#define VCH2_SCALE 587.145447f
#define VCH3_SCALE 584.911133f

#define ICH1_SCALE 372.605835f
#define ICH2_SCALE 371.815643f
#define ICH3_SCALE 372.065857f
#define ICH4_SCALE 372.735443f
#define ICH5_SCALE 371.541779f
#define ICH6_SCALE 372.059296f
#define ICH7_SCALE 372.393433f
#define ICH8_SCALE 371.619263f
#define ICH9_SCALE 372.302673f
#define ICH10_SCALE 372.464722f
#define ICH11_SCALE 371.821564f
#define ICH12_SCALE 372.322144f
#define ICH13_SCALE 372.31308f
#define ICH14_SCALE 372.007843f
#define ICH15_SCALE 372.205566f

#endif

#if Calibration_Index == PMU32
// OFFSET Calibration

#define VCH1_OFFSET 1106824
#define VCH2_OFFSET 1325951
#define VCH3_OFFSET 1622522
                    
#define ICH1_OFFSET 1595322
#define ICH2_OFFSET 1538978
#define ICH3_OFFSET 1414179
#define ICH4_OFFSET 1488156
#define ICH5_OFFSET 1470482
#define ICH6_OFFSET 1674651
#define ICH7_OFFSET 2620153
#define ICH8_OFFSET 1250381
#define ICH9_OFFSET 489460
#define ICH10_OFFSET 227660
#define ICH11_OFFSET 1026854
#define ICH12_OFFSET 1366533
#define ICH13_OFFSET 1276238
#define ICH14_OFFSET 1690016
#define ICH15_OFFSET 1925330

//SCALING Calibration
#define VCH1_SCALE 590.952087f
#define VCH2_SCALE 585.158203f
#define VCH3_SCALE 584.443909f

#define ICH1_SCALE 372.790039f
#define ICH2_SCALE 373.1875f
#define ICH3_SCALE 373.662781f
#define ICH4_SCALE 373.522919f
#define ICH5_SCALE 373.303009f
#define ICH6_SCALE 373.127502f
#define ICH7_SCALE 372.613861f
#define ICH8_SCALE 373.149506f
#define ICH9_SCALE 373.195923f
#define ICH10_SCALE 372.238953f
#define ICH11_SCALE 372.340607f
#define ICH12_SCALE 373.326111f
#define ICH13_SCALE 372.456299f
#define ICH14_SCALE 372.754028f
#define ICH15_SCALE 373.170074f

#endif

#if Calibration_Index == PMU33
// OFFSET Calibration

#define VCH1_OFFSET 785639
#define VCH2_OFFSET 1080873
#define VCH3_OFFSET 1405586
                    
#define ICH1_OFFSET 1310076
#define ICH2_OFFSET 1327228
#define ICH3_OFFSET 1185241
#define ICH4_OFFSET 1260584
#define ICH5_OFFSET 1162673
#define ICH6_OFFSET 1361144
#define ICH7_OFFSET 2332883
#define ICH8_OFFSET 1018862
#define ICH9_OFFSET 766388
#define ICH10_OFFSET 308759
#define ICH11_OFFSET 1293303
#define ICH12_OFFSET 1293303
#define ICH13_OFFSET 1293303
#define ICH14_OFFSET 1765169
#define ICH15_OFFSET 2052526

//SCALING Calibration
#define VCH1_SCALE 583.941956f
#define VCH2_SCALE 584.693542f
#define VCH3_SCALE 585.000916f

#define ICH1_SCALE 372.787964f
#define ICH2_SCALE 374.378021f
#define ICH3_SCALE 373.106567f
#define ICH4_SCALE 373.008636f
#define ICH5_SCALE 373.659241f
#define ICH6_SCALE 373.659241f
#define ICH7_SCALE 372.666229f
#define ICH8_SCALE 373.721954f
#define ICH9_SCALE 373.953735f
#define ICH10_SCALE 373.678375f
#define ICH11_SCALE 374.682587f
#define ICH12_SCALE 372.663361f
#define ICH13_SCALE 373.366028f
#define ICH14_SCALE 374.066254f
#define ICH15_SCALE 374.066254f

#endif

#if Calibration_Index == PMU34
// OFFSET Calibration

#define VCH1_OFFSET 1041530
#define VCH2_OFFSET 1122989
#define VCH3_OFFSET 1716207
                    
#define ICH1_OFFSET 1638355
#define ICH2_OFFSET 1464101
#define ICH3_OFFSET 1630381
#define ICH4_OFFSET 1611208
#define ICH5_OFFSET 1420159
#define ICH6_OFFSET 1485446
#define ICH7_OFFSET 2610760
#define ICH8_OFFSET 910404
#define ICH9_OFFSET 611673
#define ICH10_OFFSET 23334
#define ICH11_OFFSET 975025
#define ICH12_OFFSET 987321
#define ICH13_OFFSET 1434082
#define ICH14_OFFSET 1919905
#define ICH15_OFFSET 1678512

//SCALING Calibration
#define VCH1_SCALE 586.264526f
#define VCH2_SCALE 586.264526f
#define VCH3_SCALE 583.68811f

#define ICH1_SCALE 373.299133f
#define ICH2_SCALE 373.299133f
#define ICH3_SCALE 372.984772f
#define ICH4_SCALE 373.350403f
#define ICH5_SCALE 374.092529f
#define ICH6_SCALE 372.846313f
#define ICH7_SCALE 373.555511f
#define ICH8_SCALE 374.912231f
#define ICH9_SCALE 372.254547f
#define ICH10_SCALE 372.590729f
#define ICH11_SCALE 372.254547f
#define ICH12_SCALE 372.214355f
#define ICH13_SCALE 372.345367f
#define ICH14_SCALE 373.366821f
#define ICH15_SCALE 372.176422f

#endif

#if Calibration_Index == PMU35
// OFFSET Calibration

#define VCH1_OFFSET 1007206
#define VCH2_OFFSET 1146333
#define VCH3_OFFSET 1599466
                    
#define ICH1_OFFSET 1041161
#define ICH2_OFFSET 1219542
#define ICH3_OFFSET 1280526
#define ICH4_OFFSET 1185665
#define ICH5_OFFSET 1525828
#define ICH6_OFFSET 1682476
#define ICH7_OFFSET 2249014
#define ICH8_OFFSET 986819
#define ICH9_OFFSET 789099
#define ICH10_OFFSET 66390
#define ICH11_OFFSET 1287884
#define ICH12_OFFSET 1075578
#define ICH13_OFFSET 1665175
#define ICH14_OFFSET 1813032
#define ICH15_OFFSET 2090210

//SCALING Calibration
#define VCH1_SCALE 584.054138f
#define VCH2_SCALE 585.499939f
#define VCH3_SCALE 584.454407f

#define ICH1_SCALE 371.778931f
#define ICH2_SCALE 373.504364f
#define ICH3_SCALE 372.412903f
#define ICH4_SCALE 373.561707f
#define ICH5_SCALE 374.025055f
#define ICH6_SCALE 372.238434f
#define ICH7_SCALE 370.998505f
#define ICH8_SCALE 372.457703f
#define ICH9_SCALE 371.499298f
#define ICH10_SCALE 373.782715f
#define ICH11_SCALE 373.807861f
#define ICH12_SCALE 372.809631f
#define ICH13_SCALE 373.217926f
#define ICH14_SCALE 373.856964f
#define ICH15_SCALE 372.36084f

#endif

#if Calibration_Index == PMU36
// OFFSET Calibration

#define VCH1_OFFSET 887966
#define VCH2_OFFSET 1206959
#define VCH3_OFFSET 1774870
                    
#define ICH1_OFFSET 1333870
#define ICH2_OFFSET 1392947
#define ICH3_OFFSET 1483276
#define ICH4_OFFSET 1278644
#define ICH5_OFFSET 1581433
#define ICH6_OFFSET 1533819
#define ICH7_OFFSET 2682461
#define ICH8_OFFSET 1373502
#define ICH9_OFFSET 554374
#define ICH10_OFFSET 445108
#define ICH11_OFFSET 978369
#define ICH12_OFFSET 1384958
#define ICH13_OFFSET 1277832
#define ICH14_OFFSET 1758895
#define ICH15_OFFSET 2119028

//SCALING Calibration
#define VCH1_SCALE 586.76178f
#define VCH2_SCALE 584.858643f
#define VCH3_SCALE 583.006714f

#define ICH1_SCALE 371.911285f
#define ICH2_SCALE 373.22467f
#define ICH3_SCALE 372.752472f
#define ICH4_SCALE 373.965302f
#define ICH5_SCALE 373.721497f
#define ICH6_SCALE 372.597687f
#define ICH7_SCALE 370.712494f
#define ICH8_SCALE 372.494934f
#define ICH9_SCALE 372.950378f
#define ICH10_SCALE 374.279236f
#define ICH11_SCALE 374.029999f
#define ICH12_SCALE 373.370728f
#define ICH13_SCALE 373.927765f
#define ICH14_SCALE 374.375641f
#define ICH15_SCALE 373.031464f

#endif

#if Calibration_Index == PMU37
// OFFSET Calibration

#define VCH1_OFFSET 838113
#define VCH2_OFFSET 1314486
#define VCH3_OFFSET 1787481
                    
#define ICH1_OFFSET 1573495
#define ICH2_OFFSET 1633375
#define ICH3_OFFSET 1489669
#define ICH4_OFFSET 1435492
#define ICH5_OFFSET 1361145
#define ICH6_OFFSET 1174135
#define ICH7_OFFSET 2737992
#define ICH8_OFFSET 1419708
#define ICH9_OFFSET 183093
#define ICH10_OFFSET 70933
#define ICH11_OFFSET 1290347
#define ICH12_OFFSET 1233030
#define ICH13_OFFSET 1484357
#define ICH14_OFFSET 1750444
#define ICH15_OFFSET 1974847

//SCALING Calibration
#define VCH1_SCALE 585.485046f
#define VCH2_SCALE 585.940491f
#define VCH3_SCALE 587.226013f

#define ICH1_SCALE 371.200745f
#define ICH2_SCALE 373.424103f
#define ICH3_SCALE 372.003052f
#define ICH4_SCALE 372.917786f
#define ICH5_SCALE 373.128815f
#define ICH6_SCALE 372.235504f
#define ICH7_SCALE 369.757263f
#define ICH8_SCALE 372.257019f
#define ICH9_SCALE 372.641693f
#define ICH10_SCALE 373.488464f
#define ICH11_SCALE 374.05603f
#define ICH12_SCALE 372.781952f
#define ICH13_SCALE 371.985077f
#define ICH14_SCALE 373.72757f
#define ICH15_SCALE 372.909119f

#endif

#if Calibration_Index == PMU38
// OFFSET Calibration

#define VCH1_OFFSET 1235845
#define VCH2_OFFSET 1157817
#define VCH3_OFFSET 1675859
                    
#define ICH1_OFFSET 1861996
#define ICH2_OFFSET 1498851
#define ICH3_OFFSET 1606725
#define ICH4_OFFSET 1740168
#define ICH5_OFFSET 1473240
#define ICH6_OFFSET 1403843
#define ICH7_OFFSET 2570247
#define ICH8_OFFSET 1368086
#define ICH9_OFFSET 911402
#define ICH10_OFFSET 94214
#define ICH11_OFFSET 1299306
#define ICH12_OFFSET 1212822
#define ICH13_OFFSET 1527793
#define ICH14_OFFSET 1874709
#define ICH15_OFFSET 2395498

//SCALING Calibration
#define VCH1_SCALE 585.514404f
#define VCH2_SCALE 584.557007f
#define VCH3_SCALE 585.223206f

#define ICH1_SCALE 371.632111f
#define ICH2_SCALE 373.383698f
#define ICH3_SCALE 372.462219f
#define ICH4_SCALE 373.82547f
#define ICH5_SCALE 373.98407f
#define ICH6_SCALE 372.950562f
#define ICH7_SCALE 371.200989f
#define ICH8_SCALE 373.512482f
#define ICH9_SCALE 371.694f
#define ICH10_SCALE 370.807587f
#define ICH11_SCALE 372.909393f
#define ICH12_SCALE 371.477325f
#define ICH13_SCALE 372.687408f
#define ICH14_SCALE 372.939606f
#define ICH15_SCALE 371.095215f

#endif

#if Calibration_Index == PMU6xx
// OFFSET Calibration

#define VCH1_OFFSET 997310 
#define VCH2_OFFSET 1153654 
#define VCH3_OFFSET 1540516 
                    
#define ICH1_OFFSET 1317434 
#define ICH2_OFFSET 1093443 
#define ICH3_OFFSET 1359593 
#define ICH4_OFFSET 1200082 
#define ICH5_OFFSET 1119804 
#define ICH6_OFFSET 868146 
#define ICH7_OFFSET 2307695 
#define ICH8_OFFSET 712150 
#define ICH9_OFFSET 985389 
#define ICH10_OFFSET 675195 
#define ICH11_OFFSET 1270914
#define ICH12_OFFSET 1209004
#define ICH13_OFFSET 1536052
#define ICH14_OFFSET 1983811
#define ICH15_OFFSET 2100070

//SCALING Calibration
#define VCH1_SCALE 585.227478f
#define VCH2_SCALE 584.29303f
#define VCH3_SCALE 586.999084f

#define ICH1_SCALE 371.881775f
#define ICH2_SCALE 371.646393f
#define ICH3_SCALE 371.465363f
#define ICH4_SCALE 372.41037f
#define ICH5_SCALE 372.111786f
#define ICH6_SCALE 372.111786f
#define ICH7_SCALE 371.21698f
#define ICH8_SCALE 372.468079f
#define ICH9_SCALE 371.382568f
#define ICH10_SCALE 372.40567f
#define ICH11_SCALE 373.015991f
#define ICH12_SCALE 371.30246f
#define ICH13_SCALE 372.178528f
#define ICH14_SCALE 372.856842f
#define ICH15_SCALE 371.77594f

#endif

#if Calibration_Index == PMU7xx
// OFFSET Calibration

#define VCH1_OFFSET 850828
#define VCH2_OFFSET 1228114
#define VCH3_OFFSET 1646191
                    
#define ICH1_OFFSET 1646191
#define ICH2_OFFSET 1626450
#define ICH3_OFFSET 1744353
#define ICH4_OFFSET 1714504
#define ICH5_OFFSET 1665536
#define ICH6_OFFSET 1593733
#define ICH7_OFFSET 3077336 //1795875 //
#define ICH8_OFFSET 1330756  //1695520 //1739184 //
#define ICH9_OFFSET 536129 //1678843 //1685230 //
#define ICH10_OFFSET 517962
#define ICH11_OFFSET 1465485
#define ICH12_OFFSET 1503816
#define ICH13_OFFSET 2024476
#define ICH14_OFFSET 1902340
#define ICH15_OFFSET 2091697

//SCALING Calibration
#define VCH1_SCALE 583.760681f
#define VCH2_SCALE 585.44397f
#define VCH3_SCALE 584.108826f

#define ICH1_SCALE 186.52626f
#define ICH2_SCALE 187.068588f
#define ICH3_SCALE 186.13298f
#define ICH4_SCALE 186.57486f
#define ICH5_SCALE 186.611237f
#define ICH6_SCALE 186.25972f
#define ICH7_SCALE 0.930037737f //93.8146362f 
#define ICH8_SCALE 0.934183478f //65.8642349f //56.5975113f 
#define ICH9_SCALE 0.932783782f//174.452835f //117.597778f 
#define ICH10_SCALE 186.7668f
#define ICH11_SCALE 186.855423f
#define ICH12_SCALE 186.641937f
#define ICH13_SCALE 186.763504f
#define ICH14_SCALE 186.996506f
#define ICH15_SCALE 186.719971f

#endif

#if Calibration_Index == PMU4xx
// OFFSET Calibration

#define VCH1_OFFSET 781853
#define VCH2_OFFSET 1111153
#define VCH3_OFFSET 1539084
                    
#define ICH1_OFFSET 632387
#define ICH2_OFFSET 419104
#define ICH3_OFFSET 471101
#define ICH4_OFFSET 504780
#define ICH5_OFFSET 372885
#define ICH6_OFFSET 522590
#define ICH7_OFFSET 1612391
#define ICH8_OFFSET 69586
#define ICH9_OFFSET 672535
#define ICH10_OFFSET 180445
#define ICH11_OFFSET 857003
#define ICH12_OFFSET 1173442
#define ICH13_OFFSET 1468767
#define ICH14_OFFSET 1442498
#define ICH15_OFFSET 1810424

//SCALING Calibration
#define VCH1_SCALE 585.737976f
#define VCH2_SCALE 586.486206f
#define VCH3_SCALE 583.371277f

#define ICH1_SCALE 370.760681f
#define ICH2_SCALE 371.528778f
#define ICH3_SCALE 369.889435f
#define ICH4_SCALE 370.554565f
#define ICH5_SCALE 371.236481f
#define ICH6_SCALE 369.525574f
#define ICH7_SCALE 372.406372f
#define ICH8_SCALE 372.84494f
#define ICH9_SCALE 371.893829f
#define ICH10_SCALE 372.608337f
#define ICH11_SCALE 373.010712f
#define ICH12_SCALE 372.243256f
#define ICH13_SCALE 372.944977f
#define ICH14_SCALE 373.207977f
#define ICH15_SCALE 371.867981f

#endif

#if Calibration_Index == PMU39
// OFFSET Calibration

#define VCH1_OFFSET 1410689
#define VCH2_OFFSET 1502096
#define VCH3_OFFSET 1576428
                    
#define ICH1_OFFSET 2119853
#define ICH2_OFFSET 2186875
#define ICH3_OFFSET 1985617
#define ICH4_OFFSET 1894757
#define ICH5_OFFSET 1809276
#define ICH6_OFFSET 1879819
#define ICH7_OFFSET 3176730
#define ICH8_OFFSET 1529757
#define ICH9_OFFSET 831161
#define ICH10_OFFSET 547634
#define ICH11_OFFSET 1627793
#define ICH12_OFFSET 1836095
#define ICH13_OFFSET 1843832
#define ICH14_OFFSET 1401102
#define ICH15_OFFSET 1819591

//SCALING Calibration
#define VCH1_SCALE 585.461609f
#define VCH2_SCALE 585.537048f
#define VCH3_SCALE 588.669617f

#define ICH1_SCALE 375.162842f
#define ICH2_SCALE 373.29834f
#define ICH3_SCALE 374.197662f
#define ICH4_SCALE 374.2229f
#define ICH5_SCALE 374.017456f
#define ICH6_SCALE 373.907227f
#define ICH7_SCALE 371.534119f
#define ICH8_SCALE 373.170929f
#define ICH9_SCALE 372.54541f
#define ICH10_SCALE 373.662415f
#define ICH11_SCALE 373.731232f
#define ICH12_SCALE 374.396332f
#define ICH13_SCALE 373.822662f
#define ICH14_SCALE 373.338287f
#define ICH15_SCALE 372.445587f

#endif

#if Calibration_Index == PMU40
// OFFSET Calibration

#define VCH1_OFFSET 861314
#define VCH2_OFFSET 1262707
#define VCH3_OFFSET 1456743
                    
#define ICH1_OFFSET 2122462
#define ICH2_OFFSET 2041391
#define ICH3_OFFSET 1999892
#define ICH4_OFFSET 1736552
#define ICH5_OFFSET 2070701
#define ICH6_OFFSET 1971754
#define ICH7_OFFSET 3562689
#define ICH8_OFFSET 1662323
#define ICH9_OFFSET 1073850
#define ICH10_OFFSET 724281
#define ICH11_OFFSET 1791663
#define ICH12_OFFSET 2228571
#define ICH13_OFFSET 1977607
#define ICH14_OFFSET 1753834
#define ICH15_OFFSET 2193984

//SCALING Calibration
#define VCH1_SCALE 589.244019f
#define VCH2_SCALE 588.791443f
#define VCH3_SCALE 581.435364f

#define ICH1_SCALE 374.479523f
#define ICH2_SCALE 372.427948f
#define ICH3_SCALE 371.827301f
#define ICH4_SCALE 372.028839f
#define ICH5_SCALE 371.620789f
#define ICH6_SCALE 372.155457f
#define ICH7_SCALE 371.79538f
#define ICH8_SCALE 371.877472f
#define ICH9_SCALE 371.451965f
#define ICH10_SCALE 371.780304f
#define ICH11_SCALE 371.789856f
#define ICH12_SCALE 371.69577f
#define ICH13_SCALE 371.78894f
#define ICH14_SCALE 371.172333f
#define ICH15_SCALE 371.106293f

#endif

#if Calibration_Index == PMU41
// OFFSET Calibration

#define VCH1_OFFSET 1149812
#define VCH2_OFFSET 1584481
#define VCH3_OFFSET 1767094
                    
#define ICH1_OFFSET 2040543
#define ICH2_OFFSET 2080115
#define ICH3_OFFSET 2176212
#define ICH4_OFFSET 2124844
#define ICH5_OFFSET 2004282
#define ICH6_OFFSET 1798724
#define ICH7_OFFSET 3314320
#define ICH8_OFFSET 1835700
#define ICH9_OFFSET 762115
#define ICH10_OFFSET 781410
#define ICH11_OFFSET 1841265
#define ICH12_OFFSET 2100127
#define ICH13_OFFSET 1943981
#define ICH14_OFFSET 1799515
#define ICH15_OFFSET 1949880

//SCALING Calibration
#define VCH1_SCALE 587.411072f
#define VCH2_SCALE 586.13446f
#define VCH3_SCALE 589.386719f

#define ICH1_SCALE 378.353668f
#define ICH2_SCALE 376.247925f
#define ICH3_SCALE 376.726837f
#define ICH4_SCALE 377.648621f
#define ICH5_SCALE 375.930756f
#define ICH6_SCALE 376.607605
#define ICH7_SCALE 373.121124f
#define ICH8_SCALE 372.635345f
#define ICH9_SCALE 373.698395f
#define ICH10_SCALE 374.245728f
#define ICH11_SCALE 374.503021f
#define ICH12_SCALE 374.003571f
#define ICH13_SCALE 374.647034f
#define ICH14_SCALE 375.080292f
#define ICH15_SCALE 375.171387f

#endif

#if Calibration_Index == PMU42
// OFFSET Calibration

#define VCH1_OFFSET 1548614
#define VCH2_OFFSET 1664645
#define VCH3_OFFSET 2033102
                    
#define ICH1_OFFSET 1830019
#define ICH2_OFFSET 2056879
#define ICH3_OFFSET 2012396
#define ICH4_OFFSET 1992008
#define ICH5_OFFSET 1931561
#define ICH6_OFFSET 1872517
#define ICH7_OFFSET 3504822
#define ICH8_OFFSET 1426259
#define ICH9_OFFSET 554305
#define ICH10_OFFSET 806713
#define ICH11_OFFSET 2161630
#define ICH12_OFFSET 2238546
#define ICH13_OFFSET 1715971
#define ICH14_OFFSET 1604247
#define ICH15_OFFSET 1997506

//SCALING Calibration
#define VCH1_SCALE 596.515625f//599.405029f
#define VCH2_SCALE 587.864746f
#define VCH3_SCALE 581.12146f

#define ICH1_SCALE 374.250488f
#define ICH2_SCALE 372.33844f
#define ICH3_SCALE 372.789429f
#define ICH4_SCALE 373.109894f
#define ICH5_SCALE 372.564667f
#define ICH6_SCALE 373.245178f
#define ICH7_SCALE 371.519226f
#define ICH8_SCALE 371.211975f
#define ICH9_SCALE 370.868561f
#define ICH10_SCALE 370.588989f
#define ICH11_SCALE 370.994141f
#define ICH12_SCALE 370.688995f
#define ICH13_SCALE 371.229065f
#define ICH14_SCALE 370.704865f
#define ICH15_SCALE 370.943665f

#endif

#if Calibration_Index == PMU43
// OFFSET Calibration

#define VCH1_OFFSET 898873
#define VCH2_OFFSET 1454959
#define VCH3_OFFSET 1446225
                    
#define ICH1_OFFSET 2183175
#define ICH2_OFFSET 2080173
#define ICH3_OFFSET 2060979
#define ICH4_OFFSET 2214721
#define ICH5_OFFSET 1916457
#define ICH6_OFFSET 2100590
#define ICH7_OFFSET 3603224
#define ICH8_OFFSET 1880803
#define ICH9_OFFSET 1103190
#define ICH10_OFFSET 958082
#define ICH11_OFFSET 1911430
#define ICH12_OFFSET 2014387
#define ICH13_OFFSET 1994812
#define ICH14_OFFSET 1706188
#define ICH15_OFFSET 2439327

//SCALING Calibration
#define VCH1_SCALE 593.989929f
#define VCH2_SCALE 586.805115f
#define VCH3_SCALE 578.36676f

#define ICH1_SCALE 373.298492f
#define ICH2_SCALE 371.203644f
#define ICH3_SCALE 371.900299f
#define ICH4_SCALE 372.016602f
#define ICH5_SCALE 371.532257f
#define ICH6_SCALE 372.131256f
#define ICH7_SCALE 370.288361f
#define ICH8_SCALE 370.119354f
#define ICH9_SCALE 374.271301f
#define ICH10_SCALE 375.046112f
#define ICH11_SCALE 374.631836f
#define ICH12_SCALE 375.531311f
#define ICH13_SCALE 373.953918f
#define ICH14_SCALE 373.743744f
#define ICH15_SCALE 374.314423f

#endif

#if Calibration_Index == PMU44
// OFFSET Calibration

#define VCH1_OFFSET 1624800
#define VCH2_OFFSET 1893023
#define VCH3_OFFSET 1564548
                    
#define ICH1_OFFSET 1851106
#define ICH2_OFFSET 1969869
#define ICH3_OFFSET 1715178
#define ICH4_OFFSET 1978736
#define ICH5_OFFSET 1944294
#define ICH6_OFFSET 1993367
#define ICH7_OFFSET 2805840
#define ICH8_OFFSET 1730249
#define ICH9_OFFSET 644903
#define ICH10_OFFSET 637984
#define ICH11_OFFSET 1276718
#define ICH12_OFFSET 1479388
#define ICH13_OFFSET 1379664
#define ICH14_OFFSET 1173830
#define ICH15_OFFSET 1522291

//SCALING Calibration
#define VCH1_SCALE 587.921692f
#define VCH2_SCALE 587.11377f
#define VCH3_SCALE 586.06311f

#define ICH1_SCALE 365.901947f
#define ICH2_SCALE 368.064423f
#define ICH3_SCALE 366.941101f
#define ICH4_SCALE 368.125458f
#define ICH5_SCALE 366.675964f
#define ICH6_SCALE 369.262848f
#define ICH7_SCALE 366.591278f
#define ICH8_SCALE 367.176056f
#define ICH9_SCALE 366.920258f
#define ICH10_SCALE 365.613678f
#define ICH11_SCALE 366.544647f
#define ICH12_SCALE 370.400574f
#define ICH13_SCALE 367.73468f
#define ICH14_SCALE 367.73468f
#define ICH15_SCALE 366.302063f

#endif

#if Calibration_Index == PMU45
// OFFSET Calibration

#define VCH1_OFFSET 129379
#define VCH2_OFFSET 174355
#define VCH3_OFFSET 170471
                    
#define ICH1_OFFSET 1894060
#define ICH2_OFFSET 1468755
#define ICH3_OFFSET 1615339
#define ICH4_OFFSET 1511503
#define ICH5_OFFSET 1557258
#define ICH6_OFFSET 1635728
#define ICH7_OFFSET 3604298
#define ICH8_OFFSET 1170736
#define ICH9_OFFSET 154618
#define ICH10_OFFSET 190718
#define ICH11_OFFSET 1587876
#define ICH12_OFFSET 1751898
#define ICH13_OFFSET 1499370
#define ICH14_OFFSET 1643289
#define ICH15_OFFSET 1913076

//SCALING Calibration
#define VCH1_SCALE 581.898254f
#define VCH2_SCALE 588.331909f
#define VCH3_SCALE 586.634766f

#define ICH1_SCALE 372.383606f
#define ICH2_SCALE 375.727905f
#define ICH3_SCALE 373.584045f
#define ICH4_SCALE 373.710999f
#define ICH5_SCALE 372.822662f
#define ICH6_SCALE 374.12207f
#define ICH7_SCALE 372.847229f
#define ICH8_SCALE 374.157715f
#define ICH9_SCALE 375.759247f
#define ICH10_SCALE 375.89325f
#define ICH11_SCALE 375.425415f
#define ICH12_SCALE 376.743408f
#define ICH13_SCALE 373.982758f
#define ICH14_SCALE 376.262726f
#define ICH15_SCALE 375.503571f

#endif

#if Calibration_Index == PMU46
// OFFSET Calibration

#define VCH1_OFFSET 513972
#define VCH2_OFFSET 858352
#define VCH3_OFFSET 892182
                    
#define ICH1_OFFSET 1496794
#define ICH2_OFFSET 1559139
#define ICH3_OFFSET 1435756
#define ICH4_OFFSET 1118455
#define ICH5_OFFSET 1515446
#define ICH6_OFFSET 1194521
#define ICH7_OFFSET 3551306
#define ICH8_OFFSET 827232
#define ICH9_OFFSET 215046
#define ICH10_OFFSET 498571
#define ICH11_OFFSET 1679220
#define ICH12_OFFSET 1635038
#define ICH13_OFFSET 1634740
#define ICH14_OFFSET 1421957
#define ICH15_OFFSET 1835926

//SCALING Calibration
#define VCH1_SCALE 583.669067f
#define VCH2_SCALE 582.590515f
#define VCH3_SCALE 585.765442f

#define ICH1_SCALE 373.96875f
#define ICH2_SCALE 373.359375f
#define ICH3_SCALE 374.395721f
#define ICH4_SCALE 374.412231f
#define ICH5_SCALE 372.783905f
#define ICH6_SCALE 375.508484f
#define ICH7_SCALE 372.846405f
#define ICH8_SCALE 374.123749f
#define ICH9_SCALE 372.524231f
#define ICH10_SCALE 369.400665f
#define ICH11_SCALE 372.062714f
#define ICH12_SCALE 373.675201f
#define ICH13_SCALE 371.354004f
#define ICH14_SCALE 373.96048f
#define ICH15_SCALE 373.104736f

#endif

#if Calibration_Index == PMU47
// OFFSET Calibration

#define VCH1_OFFSET 533037
#define VCH2_OFFSET 533037
#define VCH3_OFFSET 318078
                    
#define ICH1_OFFSET 1540132
#define ICH2_OFFSET 1540132
#define ICH3_OFFSET 1460020
#define ICH4_OFFSET 1460020
#define ICH5_OFFSET 1476707
#define ICH6_OFFSET 1478387
#define ICH7_OFFSET 3299750
#define ICH8_OFFSET 1209101
#define ICH9_OFFSET 26535
#define ICH10_OFFSET 26535
#define ICH11_OFFSET 1575253
#define ICH12_OFFSET 1443377
#define ICH13_OFFSET 1468148
#define ICH14_OFFSET 1666380
#define ICH15_OFFSET 1686522

//SCALING Calibration
#define VCH1_SCALE 583.947998f
#define VCH2_SCALE 586.852661f
#define VCH3_SCALE 588.214172f

#define ICH1_SCALE 372.011841f
#define ICH2_SCALE 372.011841f
#define ICH3_SCALE 373.827301f
#define ICH4_SCALE 374.009155f
#define ICH5_SCALE 372.364746f
#define ICH6_SCALE 375.134613f
#define ICH7_SCALE 375.134613f
#define ICH8_SCALE 371.644623f
#define ICH9_SCALE 372.794373f
#define ICH10_SCALE 373.139099f
#define ICH11_SCALE 371.626892f
#define ICH12_SCALE 374.104401f
#define ICH13_SCALE 372.572357f
#define ICH14_SCALE 373.020203f
#define ICH15_SCALE 373.763397f

#endif

#if Calibration_Index == PMU48
// OFFSET Calibration

#define VCH1_OFFSET 414995
#define VCH2_OFFSET 686201
#define VCH3_OFFSET 1166593
                    
#define ICH1_OFFSET 1552727
#define ICH2_OFFSET 1523732
#define ICH3_OFFSET 1275209
#define ICH4_OFFSET 1291595
#define ICH5_OFFSET 1595236
#define ICH6_OFFSET 1443390
#define ICH7_OFFSET 3651561
#define ICH8_OFFSET 1257475
#define ICH9_OFFSET 12223
#define ICH10_OFFSET 192043
#define ICH11_OFFSET 1839877
#define ICH12_OFFSET 1601674
#define ICH13_OFFSET 1696455
#define ICH14_OFFSET 1680973
#define ICH15_OFFSET 1976629

//SCALING Calibration
#define VCH1_SCALE 587.079163f
#define VCH2_SCALE 584.127136f
#define VCH3_SCALE 587.837891f

#define ICH1_SCALE 372.820404f
#define ICH2_SCALE 372.972443f
#define ICH3_SCALE 375.564789f
#define ICH4_SCALE 371.459595f
#define ICH5_SCALE 373.873657f
#define ICH6_SCALE 374.721619f
#define ICH7_SCALE 371.143005f
#define ICH8_SCALE 375.039429f
#define ICH9_SCALE 374.456177f
#define ICH10_SCALE 373.906952f
#define ICH11_SCALE 374.802216f
#define ICH12_SCALE 375.103607f
#define ICH13_SCALE 374.171631f
#define ICH14_SCALE 375.119171f
#define ICH15_SCALE 375.219025f

#endif

#if Calibration_Index == PMU49
// OFFSET Calibration

#define VCH1_OFFSET 659250
#define VCH2_OFFSET 585916
#define VCH3_OFFSET 1248085
                    
#define ICH1_OFFSET 1906538
#define ICH2_OFFSET 1657050
#define ICH3_OFFSET 1613543
#define ICH4_OFFSET 1576641
#define ICH5_OFFSET 1636513
#define ICH6_OFFSET 1555614
#define ICH7_OFFSET 4327731
#define ICH8_OFFSET 1213091
#define ICH9_OFFSET 259680
#define ICH10_OFFSET 259589
#define ICH11_OFFSET 1820987
#define ICH12_OFFSET 1838122
#define ICH13_OFFSET 1486240
#define ICH14_OFFSET 1713423
#define ICH15_OFFSET 1998234

//SCALING Calibration
#define VCH1_SCALE 585.729248f
#define VCH2_SCALE 583.557251f
#define VCH3_SCALE 583.115845f

#define ICH1_SCALE 373.076599f
#define ICH2_SCALE 373.886627f
#define ICH3_SCALE 375.545441f
#define ICH4_SCALE 372.209503f
#define ICH5_SCALE 374.391235f
#define ICH6_SCALE 373.486877f
#define ICH7_SCALE 372.017334f
#define ICH8_SCALE 374.432251f
#define ICH9_SCALE 373.368011f
#define ICH10_SCALE 372.404053f
#define ICH11_SCALE 372.997314f
#define ICH12_SCALE 374.210419f
#define ICH13_SCALE 372.328033f
#define ICH14_SCALE 373.361664f
#define ICH15_SCALE 372.223785f

#endif

#if Calibration_Index == PMU50
// OFFSET Calibration

#define VCH1_OFFSET 240887
#define VCH2_OFFSET 612400
#define VCH3_OFFSET 1000470
                    
#define ICH1_OFFSET 1655811
#define ICH2_OFFSET 1756173
#define ICH3_OFFSET 1774046
#define ICH4_OFFSET 1537724
#define ICH5_OFFSET 1609918
#define ICH6_OFFSET 1620090
#define ICH7_OFFSET 4372722
#define ICH8_OFFSET 788257
#define ICH9_OFFSET 35475
#define ICH10_OFFSET 353050
#define ICH11_OFFSET 1792897
#define ICH12_OFFSET 1740080
#define ICH13_OFFSET 1799329
#define ICH14_OFFSET 1517960
#define ICH15_OFFSET 2296522

//SCALING Calibration
#define VCH1_SCALE 586.842285f
#define VCH2_SCALE 587.665161f
#define VCH3_SCALE 588.295471f

#define ICH1_SCALE 375.411102f
#define ICH2_SCALE 374.29187f
#define ICH3_SCALE 375.439026f
#define ICH4_SCALE 373.845612f
#define ICH5_SCALE 375.161194f
#define ICH6_SCALE 374.873932f
#define ICH7_SCALE 372.220276f
#define ICH8_SCALE 374.074554f
#define ICH9_SCALE 372.731293f
#define ICH10_SCALE 372.447571f
#define ICH11_SCALE 372.553741f
#define ICH12_SCALE 374.393646f
#define ICH13_SCALE 373.113983f
#define ICH14_SCALE 372.99295f
#define ICH15_SCALE 372.548676f

#endif

#if Calibration_Index == PMU51	//ICH10
// OFFSET Calibration

#define VCH1_OFFSET 52984
#define VCH2_OFFSET 208523
#define VCH3_OFFSET 121354
                    
#define ICH1_OFFSET 1719884
#define ICH2_OFFSET 1387822
#define ICH3_OFFSET 1429560
#define ICH4_OFFSET 1618561
#define ICH5_OFFSET 1503792
#define ICH6_OFFSET 1645077
#define ICH7_OFFSET 6055346
#define ICH8_OFFSET 1527740
#define ICH9_OFFSET 360521
#define ICH10_OFFSET -379511
#define ICH11_OFFSET 2653110
#define ICH12_OFFSET 2414706
#define ICH13_OFFSET 1581879
#define ICH14_OFFSET 292627
#define ICH15_OFFSET 2017851

//SCALING Calibration
#define VCH1_SCALE 584.318115f
#define VCH2_SCALE 585.310364f
#define VCH3_SCALE 585.310364f

#define ICH1_SCALE 374.276672f
#define ICH2_SCALE 371.878601f
#define ICH3_SCALE 374.398987f
#define ICH4_SCALE 370.649567f
#define ICH5_SCALE 374.07312f
#define ICH6_SCALE 373.626221f
#define ICH7_SCALE 360.505493f
#define ICH8_SCALE 373.277008f
#define ICH9_SCALE 372.60025f
#define ICH10_SCALE 372.390259f
#define ICH11_SCALE 370.720947f
#define ICH12_SCALE 373.728912f
#define ICH13_SCALE 373.586609f
#define ICH14_SCALE 368.56723f
#define ICH15_SCALE 373.101379f

#endif

#if Calibration_Index == PMU52	//ICH14
// OFFSET Calibration

#define VCH1_OFFSET 918087
#define VCH2_OFFSET 1120860
#define VCH3_OFFSET 1377400
                    
#define ICH1_OFFSET 1131452
#define ICH2_OFFSET 1211753
#define ICH3_OFFSET 1164695
#define ICH4_OFFSET 1041280
#define ICH5_OFFSET 1361322
#define ICH6_OFFSET 1256431
#define ICH7_OFFSET 3937611
#define ICH8_OFFSET 746115
#define ICH9_OFFSET 430869
#define ICH10_OFFSET 836079
#define ICH11_OFFSET 1341286
#define ICH12_OFFSET 1437554
#define ICH13_OFFSET 1405579
#define ICH14_OFFSET 1855193
#define ICH15_OFFSET 1770284

//SCALING Calibration
#define VCH1_SCALE 583.557739f
#define VCH2_SCALE 587.311279f
#define VCH3_SCALE 585.685242f

#define ICH1_SCALE 375.616516f
#define ICH2_SCALE 375.616516f
#define ICH3_SCALE 374.841309f
#define ICH4_SCALE 374.246429f
#define ICH5_SCALE 373.860718f
#define ICH6_SCALE 374.451202f
#define ICH7_SCALE 373.118286f
#define ICH8_SCALE 373.438293f
#define ICH9_SCALE 374.249664f
#define ICH10_SCALE 365.568329f
#define ICH11_SCALE 375.43512f
#define ICH12_SCALE 374.581543f
#define ICH13_SCALE 376.517365f
#define ICH14_SCALE 375.351227f
#define ICH15_SCALE 374.648071f

#endif

#if Calibration_Index == PMU53
// OFFSET Calibration

#define VCH1_OFFSET 224065
#define VCH2_OFFSET 391048
#define VCH3_OFFSET 397997
                    
#define ICH1_OFFSET 1626490
#define ICH2_OFFSET 1615166
#define ICH3_OFFSET 1590447
#define ICH4_OFFSET 1769547
#define ICH5_OFFSET 1718333
#define ICH6_OFFSET 1665398
#define ICH7_OFFSET 3374613
#define ICH8_OFFSET 1412044
#define ICH9_OFFSET 342582
#define ICH10_OFFSET 70389
#define ICH11_OFFSET 1527309
#define ICH12_OFFSET 1410749
#define ICH13_OFFSET 1777362
#define ICH14_OFFSET 1563483
#define ICH15_OFFSET 2043189

//SCALING Calibration
#define VCH1_SCALE 586.921082f
#define VCH2_SCALE 584.703369f
#define VCH3_SCALE 584.86731f

#define ICH1_SCALE 372.700134f
#define ICH2_SCALE 373.997131f
#define ICH3_SCALE 374.845642f
#define ICH4_SCALE 372.700043f
#define ICH5_SCALE 373.183624f
#define ICH6_SCALE 374.715668f
#define ICH7_SCALE 364.740509f
#define ICH8_SCALE 374.893768f
#define ICH9_SCALE 374.893768f
#define ICH10_SCALE 374.893768f
#define ICH11_SCALE 372.685913f
#define ICH12_SCALE 374.155151f
#define ICH13_SCALE 373.01767f
#define ICH14_SCALE 373.18689f
#define ICH15_SCALE 373.17868f

#endif

#if Calibration_Index == PMU54
// OFFSET Calibration

#define VCH1_OFFSET 464404
#define VCH2_OFFSET 171565
#define VCH3_OFFSET 53590
                    
#define ICH1_OFFSET 1788880
#define ICH2_OFFSET 1535396
#define ICH3_OFFSET 1291802
#define ICH4_OFFSET 1464846
#define ICH5_OFFSET 1506017
#define ICH6_OFFSET 1469572
#define ICH7_OFFSET 3191399
#define ICH8_OFFSET 1214709
#define ICH9_OFFSET 49495
#define ICH10_OFFSET 258104
#define ICH11_OFFSET 1645598
#define ICH12_OFFSET 1663526
#define ICH13_OFFSET 1467004
#define ICH14_OFFSET 1553944
#define ICH15_OFFSET 1992747

//SCALING Calibration
#define VCH1_SCALE 591.025757f
#define VCH2_SCALE 591.297363f
#define VCH3_SCALE 587.264587f

#define ICH1_SCALE 373.776428f
#define ICH2_SCALE 374.139038f
#define ICH3_SCALE 372.438721f
#define ICH4_SCALE 373.151001f
#define ICH5_SCALE 373.88385f
#define ICH6_SCALE 373.2659f
#define ICH7_SCALE 372.645508f
#define ICH8_SCALE 373.459045f
#define ICH9_SCALE 374.59317f
#define ICH10_SCALE 372.662415f
#define ICH11_SCALE 373.992859f
#define ICH12_SCALE 374.568726f
#define ICH13_SCALE 374.917603f
#define ICH14_SCALE 374.222107f
#define ICH15_SCALE 373.063202f

#endif

#if Calibration_Index == PMU55
// OFFSET Calibration

#define VCH1_OFFSET 1039305
#define VCH2_OFFSET 1039305
#define VCH3_OFFSET 1288708
                    
#define ICH1_OFFSET 1442882
#define ICH2_OFFSET 1471477
#define ICH3_OFFSET 1503847
#define ICH4_OFFSET 1677112
#define ICH5_OFFSET 1498983
#define ICH6_OFFSET 1349286
#define ICH7_OFFSET 3630477
#define ICH8_OFFSET 844856
#define ICH9_OFFSET 116416
#define ICH10_OFFSET 82949
#define ICH11_OFFSET 1644107
#define ICH12_OFFSET 1733311
#define ICH13_OFFSET 1557730
#define ICH14_OFFSET 1247862
#define ICH15_OFFSET 2087152

//SCALING Calibration
#define VCH1_SCALE 582.085327f
#define VCH2_SCALE 583.714539f
#define VCH3_SCALE 582.454346f

#define ICH1_SCALE 373.679382f
#define ICH2_SCALE 374.568542f
#define ICH3_SCALE 373.551605f
#define ICH4_SCALE 373.809509f
#define ICH5_SCALE 374.521179f
#define ICH6_SCALE 374.014709f
#define ICH7_SCALE 373.635498f
#define ICH8_SCALE 374.011993f
#define ICH9_SCALE 374.640839f
#define ICH10_SCALE 373.094025f
#define ICH11_SCALE 374.420471f
#define ICH12_SCALE 374.439514f
#define ICH13_SCALE 373.307648f
#define ICH14_SCALE 374.733887f
#define ICH15_SCALE 373.84433f

#endif

#if Calibration_Index == PMU56
// OFFSET Calibration

#define VCH1_OFFSET 703683
#define VCH2_OFFSET 716092
#define VCH3_OFFSET 625160
                    
#define ICH1_OFFSET 1247004
#define ICH2_OFFSET 1082269
#define ICH3_OFFSET 1210592
#define ICH4_OFFSET 1153099
#define ICH5_OFFSET 1130443
#define ICH6_OFFSET 1014215
#define ICH7_OFFSET 2537814
#define ICH8_OFFSET 1192008
#define ICH9_OFFSET 505190
#define ICH10_OFFSET 307418
#define ICH11_OFFSET 2015637
#define ICH12_OFFSET 1676075
#define ICH13_OFFSET 1649518
#define ICH14_OFFSET 1652677
#define ICH15_OFFSET 1994489

//SCALING Calibration
#define VCH1_SCALE 586.804565f
#define VCH2_SCALE 584.050598f
#define VCH3_SCALE 585.110535f

#define ICH1_SCALE 373.242126f
#define ICH2_SCALE 373.489197f
#define ICH3_SCALE 374.952911f
#define ICH4_SCALE 372.423401f
#define ICH5_SCALE 375.31604f
#define ICH6_SCALE 372.95575f
#define ICH7_SCALE 371.584869f
#define ICH8_SCALE 374.851593f
#define ICH9_SCALE 374.302948f
#define ICH10_SCALE 373.423096f
#define ICH11_SCALE 373.407227f
#define ICH12_SCALE 374.421143f
#define ICH13_SCALE 373.610931f
#define ICH14_SCALE 373.784943f
#define ICH15_SCALE 374.285065f

#endif

#if Calibration_Index == PMU57
// OFFSET Calibration

#define VCH1_OFFSET 940641
#define VCH2_OFFSET 1427896
#define VCH3_OFFSET 1377083
                    
#define ICH1_OFFSET 1594811
#define ICH2_OFFSET 1810944
#define ICH3_OFFSET 1673440
#define ICH4_OFFSET 1647849
#define ICH5_OFFSET 1903181
#define ICH6_OFFSET 1704198
#define ICH7_OFFSET 4006636
#define ICH8_OFFSET 874645
#define ICH9_OFFSET 52374
#define ICH10_OFFSET 307490
#define ICH11_OFFSET 1678578
#define ICH12_OFFSET 1854463
#define ICH13_OFFSET 1690916
#define ICH14_OFFSET 1591081
#define ICH15_OFFSET 1985409

//SCALING Calibration
#define VCH1_SCALE 587.348755f
#define VCH2_SCALE 587.686401f
#define VCH3_SCALE 585.290649f

#define ICH1_SCALE 373.463348f
#define ICH2_SCALE 375.221619f
#define ICH3_SCALE 372.099091f
#define ICH4_SCALE 374.466248f
#define ICH5_SCALE 375.531006f
#define ICH6_SCALE 373.060883f
#define ICH7_SCALE 374.701813f
#define ICH8_SCALE 374.701813f
#define ICH9_SCALE 374.290039f
#define ICH10_SCALE 372.091278f
#define ICH11_SCALE 374.41037f
#define ICH12_SCALE 371.668243f
#define ICH13_SCALE 372.458038f
#define ICH14_SCALE 372.458038f
#define ICH15_SCALE 374.516632f

#endif

#if Calibration_Index == PMU58
// OFFSET Calibration

#define VCH1_OFFSET 997400
#define VCH2_OFFSET 1288451
#define VCH3_OFFSET 1087741
                    
#define ICH1_OFFSET 1682720
#define ICH2_OFFSET 1449986
#define ICH3_OFFSET 1282299
#define ICH4_OFFSET 1214097
#define ICH5_OFFSET 1505894
#define ICH6_OFFSET 1424944
#define ICH7_OFFSET 3892279
#define ICH8_OFFSET 733959
#define ICH9_OFFSET 200677
#define ICH10_OFFSET 170417
#define ICH11_OFFSET 1854899
#define ICH12_OFFSET 1599524
#define ICH13_OFFSET 1792388
#define ICH14_OFFSET 1743473
#define ICH15_OFFSET 1850717

//SCALING Calibration
#define VCH1_SCALE 583.895752f
#define VCH2_SCALE 585.687866f
#define VCH3_SCALE 585.962891f

#define ICH1_SCALE 374.339935f
#define ICH2_SCALE 373.243744f
#define ICH3_SCALE 374.04306f
#define ICH4_SCALE 372.779388f
#define ICH5_SCALE 374.913116f
#define ICH6_SCALE 374.197418f
#define ICH7_SCALE 371.816772f
#define ICH8_SCALE 375.213623f
#define ICH9_SCALE 585.687866f
#define ICH10_SCALE 372.63681f
#define ICH11_SCALE 375.626038f
#define ICH12_SCALE 375.626038f
#define ICH13_SCALE 375.220642f
#define ICH14_SCALE 373.409668f
#define ICH15_SCALE 375.207123f

#endif

#if Calibration_Index == PMU59
// OFFSET Calibration

#define VCH1_OFFSET 688073
#define VCH2_OFFSET 588399
#define VCH3_OFFSET 514479
                    
#define ICH1_OFFSET 1523041
#define ICH2_OFFSET 1560454
#define ICH3_OFFSET 1173633
#define ICH4_OFFSET 1208011
#define ICH5_OFFSET 1283707
#define ICH6_OFFSET 1421467
#define ICH7_OFFSET 3442385
#define ICH8_OFFSET 962664
#define ICH9_OFFSET 439434
#define ICH10_OFFSET 421254
#define ICH11_OFFSET 1192239
#define ICH12_OFFSET 1344607
#define ICH13_OFFSET 1237814
#define ICH14_OFFSET 1499356
#define ICH15_OFFSET 1889055

//SCALING Calibration
#define VCH1_SCALE 585.794373f
#define VCH2_SCALE 589.046692f
#define VCH3_SCALE 589.565552f

#define ICH1_SCALE 375.4758f
#define ICH2_SCALE 374.15799f
#define ICH3_SCALE 374.022278f
#define ICH4_SCALE 375.159271f
#define ICH5_SCALE 375.101776f
#define ICH6_SCALE 374.587158f
#define ICH7_SCALE 371.707153f
#define ICH8_SCALE 374.607391f
#define ICH9_SCALE 373.048065f
#define ICH10_SCALE 373.890625f
#define ICH11_SCALE 374.950928f
#define ICH12_SCALE 373.567261f
#define ICH13_SCALE 374.576263f
#define ICH14_SCALE 373.290863f
#define ICH15_SCALE 374.61261f

#endif

#if Calibration_Index == PMU60
// OFFSET Calibration

#define VCH1_OFFSET 787786
#define VCH2_OFFSET 743776
#define VCH3_OFFSET 839785
                    
#define ICH1_OFFSET 1371247
#define ICH2_OFFSET 1335942
#define ICH3_OFFSET 1602740
#define ICH4_OFFSET 1562817
#define ICH5_OFFSET 1543698
#define ICH6_OFFSET 1385306
#define ICH7_OFFSET 3817926
#define ICH8_OFFSET 682137
#define ICH9_OFFSET 60258
#define ICH10_OFFSET 324096
#define ICH11_OFFSET 1921362
#define ICH12_OFFSET 1638970
#define ICH13_OFFSET 1654988
#define ICH14_OFFSET 1824866
#define ICH15_OFFSET 1854921

//SCALING Calibration
#define VCH1_SCALE 590.367432f
#define VCH2_SCALE 592.971497f
#define VCH3_SCALE 594.406616f

#define ICH1_SCALE 373.940948f
#define ICH2_SCALE 373.271545f
#define ICH3_SCALE 374.106171f
#define ICH4_SCALE 374.76358f
#define ICH5_SCALE 374.134033f
#define ICH6_SCALE 373.557159f
#define ICH7_SCALE 372.951996f
#define ICH8_SCALE 373.715851f
#define ICH9_SCALE 372.984253f
#define ICH10_SCALE 372.557159f
#define ICH11_SCALE 373.749298f
#define ICH12_SCALE 373.66983f
#define ICH13_SCALE 372.776337f
#define ICH14_SCALE 373.96228f
#define ICH15_SCALE 372.675018f

#endif

#if Calibration_Index == PMU61
// OFFSET Calibration

#define VCH1_OFFSET 802487
#define VCH2_OFFSET 850318
#define VCH3_OFFSET 689860
                    
#define ICH1_OFFSET 1284844
#define ICH2_OFFSET 1307315
#define ICH3_OFFSET 1512300
#define ICH4_OFFSET 1280586
#define ICH5_OFFSET 1411027
#define ICH6_OFFSET 1498533
#define ICH7_OFFSET 3704901
#define ICH8_OFFSET 769905
#define ICH9_OFFSET 8388
#define ICH10_OFFSET 350562
#define ICH11_OFFSET 1735296
#define ICH12_OFFSET 1510889
#define ICH13_OFFSET 1337388
#define ICH14_OFFSET 1977916
#define ICH15_OFFSET 2173156

//SCALING Calibration
#define VCH1_SCALE 590.231384f
#define VCH2_SCALE 585.386292f
#define VCH3_SCALE 588.392578f

#define ICH1_SCALE 374.306946f
#define ICH2_SCALE 374.535675f
#define ICH3_SCALE 371.764832f
#define ICH4_SCALE 373.889404f
#define ICH5_SCALE 374.399933f
#define ICH6_SCALE 374.131042f
#define ICH7_SCALE 372.183014f
#define ICH8_SCALE 373.40683f
#define ICH9_SCALE 372.874268f
#define ICH10_SCALE 373.438385f
#define ICH11_SCALE 372.879303f
#define ICH12_SCALE 373.3909f
#define ICH13_SCALE 373.500854f
#define ICH14_SCALE 373.18399f
#define ICH15_SCALE 374.059326f

#endif

#if Calibration_Index == PMU62
// OFFSET Calibration

#define VCH1_OFFSET 488210
#define VCH2_OFFSET 896001
#define VCH3_OFFSET 1003061
                    
#define ICH1_OFFSET 1464513
#define ICH2_OFFSET 1358900
#define ICH3_OFFSET 1608678
#define ICH4_OFFSET 1536714
#define ICH5_OFFSET 1371844
#define ICH6_OFFSET 1767769
#define ICH7_OFFSET 4015088
#define ICH8_OFFSET 1231672
#define ICH9_OFFSET 20820
#define ICH10_OFFSET 233228
#define ICH11_OFFSET 1468004
#define ICH12_OFFSET 1571880
#define ICH13_OFFSET 1602506
#define ICH14_OFFSET 1581463
#define ICH15_OFFSET 2157185

//SCALING Calibration
#define VCH1_SCALE 587.449158f
#define VCH2_SCALE 583.62146f
#define VCH3_SCALE 590.079834f

#define ICH1_SCALE 374.020935f
#define ICH2_SCALE 373.83609f
#define ICH3_SCALE 371.519226f
#define ICH4_SCALE 372.516235f
#define ICH5_SCALE 374.213196f
#define ICH6_SCALE 373.511475f
#define ICH7_SCALE 369.736633f
#define ICH8_SCALE 373.030212f
#define ICH9_SCALE 372.871277f
#define ICH10_SCALE 372.57724f
#define ICH11_SCALE 374.029541f
#define ICH12_SCALE 371.785187f
#define ICH13_SCALE 372.460724f
#define ICH14_SCALE 374.962402f
#define ICH15_SCALE 372.19458f

#endif

#if Calibration_Index == PMU63
// OFFSET Calibration

#define VCH1_OFFSET 822497
#define VCH2_OFFSET 1248144
#define VCH3_OFFSET 1137453
                    
#define ICH1_OFFSET 1530592
#define ICH2_OFFSET 1600658
#define ICH3_OFFSET 1534827
#define ICH4_OFFSET 1681740
#define ICH5_OFFSET 1445734
#define ICH6_OFFSET 1420005
#define ICH7_OFFSET 3710050
#define ICH8_OFFSET 783222
#define ICH9_OFFSET 257157
#define ICH10_OFFSET 579843
#define ICH11_OFFSET 1411014
#define ICH12_OFFSET 1329283
#define ICH13_OFFSET 1484583
#define ICH14_OFFSET 1414869
#define ICH15_OFFSET 1865844

//SCALING Calibration
#define VCH1_SCALE 585.781799f
#define VCH2_SCALE 585.144775f
#define VCH3_SCALE 586.460632f

#define ICH1_SCALE 374.342621f
#define ICH2_SCALE 374.161682f
#define ICH3_SCALE 373.969055f
#define ICH4_SCALE 373.489929f
#define ICH5_SCALE 374.323486f
#define ICH6_SCALE 373.88501f
#define ICH7_SCALE 372.074646f
#define ICH8_SCALE 372.957886f
#define ICH9_SCALE 373.958435f
#define ICH10_SCALE 369.760681f
#define ICH11_SCALE 374.090179f
#define ICH12_SCALE 373.714844f
#define ICH13_SCALE 371.807068f
#define ICH14_SCALE 374.366058f
#define ICH15_SCALE 374.635315f

#endif

#if Calibration_Index == PMU64
// OFFSET Calibration

#define VCH1_OFFSET 426016
#define VCH2_OFFSET 486638
#define VCH3_OFFSET 925840
                    
#define ICH1_OFFSET 1319417
#define ICH2_OFFSET 1298061
#define ICH3_OFFSET 1255643
#define ICH4_OFFSET 1382205
#define ICH5_OFFSET 1450341
#define ICH6_OFFSET 1451793
#define ICH7_OFFSET 3152837
#define ICH8_OFFSET 383426
#define ICH9_OFFSET 990801
#define ICH10_OFFSET 139809
#define ICH11_OFFSET 1373814
#define ICH12_OFFSET 1275301
#define ICH13_OFFSET 1516305
#define ICH14_OFFSET 1149556
#define ICH15_OFFSET 1395510

//SCALING Calibration
#define VCH1_SCALE 586.813904f
#define VCH2_SCALE 587.631958f
#define VCH3_SCALE 588.572144f

#define ICH1_SCALE 373.864502f
#define ICH2_SCALE 373.024994f
#define ICH3_SCALE 374.445587f
#define ICH4_SCALE 373.71109f
#define ICH5_SCALE 373.927948f
#define ICH6_SCALE 375.361572f
#define ICH7_SCALE 373.269623f
#define ICH8_SCALE 373.891571f
#define ICH9_SCALE 367.112732f
#define ICH10_SCALE 371.696686f
#define ICH11_SCALE 373.765411f
#define ICH12_SCALE 372.911163f
#define ICH13_SCALE 373.200653f
#define ICH14_SCALE 372.065216f
#define ICH15_SCALE 372.243439f

#endif

#if Calibration_Index == PMU65
// OFFSET Calibration

#define VCH1_OFFSET 926847
#define VCH2_OFFSET 1195159
#define VCH3_OFFSET 1432393
                    
#define ICH1_OFFSET 1594157
#define ICH2_OFFSET 1517446
#define ICH3_OFFSET 1761594
#define ICH4_OFFSET 1482402
#define ICH5_OFFSET 1603577
#define ICH6_OFFSET 1648410
#define ICH7_OFFSET 3670947
#define ICH8_OFFSET 995658
#define ICH9_OFFSET 25659
#define ICH10_OFFSET 280791
#define ICH11_OFFSET 1614639
#define ICH12_OFFSET 1590577
#define ICH13_OFFSET 1645997
#define ICH14_OFFSET 1576293
#define ICH15_OFFSET 1694138

//SCALING Calibration
#define VCH1_SCALE 584.442139f
#define VCH2_SCALE 583.36853f
#define VCH3_SCALE 586.440857f

#define ICH1_SCALE 373.155396f
#define ICH2_SCALE 373.982758f
#define ICH3_SCALE 373.325745f
#define ICH4_SCALE 373.010681f
#define ICH5_SCALE 374.5354f
#define ICH6_SCALE 373.16037f
#define ICH7_SCALE 373.689819f
#define ICH8_SCALE 373.449615f
#define ICH9_SCALE 373.431091f
#define ICH10_SCALE 372.142883f
#define ICH11_SCALE 374.763397f
#define ICH12_SCALE 372.59259f
#define ICH13_SCALE 374.478699f
#define ICH14_SCALE 373.188019f
#define ICH15_SCALE 374.650146f

#endif
#if Calibration_Index == PMU66
// OFFSET Calibration

#define VCH1_OFFSET 932807
#define VCH2_OFFSET 921414
#define VCH3_OFFSET 797989
                    
#define ICH1_OFFSET 1654258
#define ICH2_OFFSET 1522139
#define ICH3_OFFSET 1873252
#define ICH4_OFFSET 1416485
#define ICH5_OFFSET 1615746
#define ICH6_OFFSET 1914265
#define ICH7_OFFSET 3707771
#define ICH8_OFFSET 1162403
#define ICH9_OFFSET 103120
#define ICH10_OFFSET 171811		
#define ICH11_OFFSET 1548936
#define ICH12_OFFSET 1577738
#define ICH13_OFFSET 1514055
#define ICH14_OFFSET 1536675
#define ICH15_OFFSET 1686414

//SCALING Calibration
#define VCH1_SCALE 585.762939f
#define VCH2_SCALE 585.932251f
#define VCH3_SCALE 588.781189f

#define ICH1_SCALE 373.186951f
#define ICH2_SCALE 373.584412f
#define ICH3_SCALE 375.766144f
#define ICH4_SCALE 375.766144f
#define ICH5_SCALE 374.166504f
#define ICH6_SCALE 374.12262f
#define ICH7_SCALE 372.05365f
#define ICH8_SCALE 374.951263f
#define ICH9_SCALE 371.645996f
#define ICH10_SCALE 373.756622f
#define ICH11_SCALE 373.085175f
#define ICH12_SCALE 373.313019f
#define ICH13_SCALE 371.283325f
#define ICH14_SCALE 373.545715f
#define ICH15_SCALE 372.404205f

#endif
#if Calibration_Index == PMU67
// OFFSET Calibration

#define VCH1_OFFSET 59985
#define VCH2_OFFSET 167766
#define VCH3_OFFSET 160213
                    
#define ICH1_OFFSET 1310086
#define ICH2_OFFSET 1472042
#define ICH3_OFFSET 1389229
#define ICH4_OFFSET 1331825
#define ICH5_OFFSET 1703860
#define ICH6_OFFSET 1448543
#define ICH7_OFFSET 3071925
#define ICH8_OFFSET 710053
#define ICH9_OFFSET 222615
#define ICH10_OFFSET 922340
#define ICH11_OFFSET 1231081
#define ICH12_OFFSET 816455
#define ICH13_OFFSET 1075372
#define ICH14_OFFSET 988458
#define ICH15_OFFSET 1122862

//SCALING Calibration
#define VCH1_SCALE 586.731323f
#define VCH2_SCALE 587.816772f
#define VCH3_SCALE 588.514954f

#define ICH1_SCALE 374.431519f
#define ICH2_SCALE 375.68869f
#define ICH3_SCALE 374.853394f
#define ICH4_SCALE 374.083466f
#define ICH5_SCALE 375.851501f
#define ICH6_SCALE 374.895691f
#define ICH7_SCALE 374.698059f
#define ICH8_SCALE 373.404663f
#define ICH9_SCALE 373.749725f
#define ICH10_SCALE 362.74411f
#define ICH11_SCALE 374.070892f
#define ICH12_SCALE 370.433441f
#define ICH13_SCALE 373.726166f
#define ICH14_SCALE 372.381042f
#define ICH15_SCALE 372.517181f

#endif
#if Calibration_Index == PMU68
// OFFSET Calibration

#define VCH1_OFFSET 20460
#define VCH2_OFFSET 385401
#define VCH3_OFFSET 588497
                    
#define ICH1_OFFSET 1580872
#define ICH2_OFFSET 1383842
#define ICH3_OFFSET 1534488
#define ICH4_OFFSET 1395394
#define ICH5_OFFSET 1425357
#define ICH6_OFFSET 1503739
#define ICH7_OFFSET 3823929
#define ICH8_OFFSET 894808
#define ICH9_OFFSET 151316
#define ICH10_OFFSET 19492
#define ICH11_OFFSET 1741628
#define ICH12_OFFSET 1607026
#define ICH13_OFFSET 1657328
#define ICH14_OFFSET 1825904
#define ICH15_OFFSET 2063966

//SCALING Calibration
#define VCH1_SCALE 584.006226f
#define VCH2_SCALE 587.053772f
#define VCH3_SCALE 587.053772f

#define ICH1_SCALE 372.070282f
#define ICH2_SCALE 374.543152f
#define ICH3_SCALE 372.857513f
#define ICH4_SCALE 374.13269f
#define ICH5_SCALE 374.284668f
#define ICH6_SCALE 374.001282f
#define ICH7_SCALE 374.550018f
#define ICH8_SCALE 370.940521f
#define ICH9_SCALE 374.064789f
#define ICH10_SCALE 372.048676f
#define ICH11_SCALE 373.919617f
#define ICH12_SCALE 371.706451f
#define ICH13_SCALE 374.073273f
#define ICH14_SCALE 372.3479f
#define ICH15_SCALE 373.249634f

#endif

#if Calibration_Index == PMU69
// OFFSET Calibration

#define VCH1_OFFSET 108390
#define VCH2_OFFSET 438959
#define VCH3_OFFSET 334034
                    
#define ICH1_OFFSET 1687826
#define ICH2_OFFSET 1429815
#define ICH3_OFFSET 1302777
#define ICH4_OFFSET 1252594
#define ICH5_OFFSET 1450615
#define ICH6_OFFSET 1352327
#define ICH7_OFFSET 3337358
#define ICH8_OFFSET 1144881
#define ICH9_OFFSET 138214
#define ICH10_OFFSET 441662
#define ICH11_OFFSET 1741932
#define ICH12_OFFSET 1573837
#define ICH13_OFFSET 1599260
#define ICH14_OFFSET 1556056
#define ICH15_OFFSET 1818562

//SCALING Calibration
#define VCH1_SCALE 587.322083f
#define VCH2_SCALE 587.322083f
#define VCH3_SCALE 586.370483f

#define ICH1_SCALE 373.359283f
#define ICH2_SCALE 372.856903f
#define ICH3_SCALE 373.278809f
#define ICH4_SCALE 372.44278f
#define ICH5_SCALE 373.541931f
#define ICH6_SCALE 374.21402f
#define ICH7_SCALE 374.21402f
#define ICH8_SCALE 374.182159f
#define ICH9_SCALE 374.182159f
#define ICH10_SCALE 371.499512f
#define ICH11_SCALE 373.516296f
#define ICH12_SCALE 374.133575f
#define ICH13_SCALE 374.133575f
#define ICH14_SCALE 373.52774f
#define ICH15_SCALE 373.144226f

#endif

#if Calibration_Index == PMU70
// OFFSET Calibration

#define VCH1_OFFSET 1266172
#define VCH2_OFFSET 1802331
#define VCH3_OFFSET 1817437
                    
#define ICH1_OFFSET 1702799
#define ICH2_OFFSET 1648345
#define ICH3_OFFSET 1780980
#define ICH4_OFFSET 1575216
#define ICH5_OFFSET 1538307
#define ICH6_OFFSET 1675044
#define ICH7_OFFSET 4233814
#define ICH8_OFFSET 943950
#define ICH9_OFFSET 113010
#define ICH10_OFFSET 217291
#define ICH11_OFFSET 1317075
#define ICH12_OFFSET 1532194
#define ICH13_OFFSET 1749716
#define ICH14_OFFSET 1587671
#define ICH15_OFFSET 1997555       

//SCALING Calibration
#define VCH1_SCALE 584.060608f
#define VCH2_SCALE 579.871643f
#define VCH3_SCALE 580.400085f

#define ICH1_SCALE 372.016785f
#define ICH2_SCALE 373.635254f
#define ICH3_SCALE 373.647156f
#define ICH4_SCALE 372.481506f
#define ICH5_SCALE 373.860321f
#define ICH6_SCALE 372.800415f
#define ICH7_SCALE 370.956299f
#define ICH8_SCALE 372.128143f
#define ICH9_SCALE 374.197693f
#define ICH10_SCALE 374.006866f
#define ICH11_SCALE 373.950531f
#define ICH12_SCALE 374.525269f
#define ICH13_SCALE 373.791626f
#define ICH14_SCALE 375.270386f
#define ICH15_SCALE 374.694275f

#endif

#if Calibration_Index == PMU71
// OFFSET Calibration

#define VCH1_OFFSET 48508
#define VCH2_OFFSET 437249
#define VCH3_OFFSET 424334
                    
#define ICH1_OFFSET 1563653
#define ICH2_OFFSET 1561603
#define ICH3_OFFSET 1601895
#define ICH4_OFFSET 1597505
#define ICH5_OFFSET 1266596
#define ICH6_OFFSET 1603730
#define ICH7_OFFSET 4105253
#define ICH8_OFFSET 671298
#define ICH9_OFFSET 255193
#define ICH10_OFFSET 394691
#define ICH11_OFFSET 1468224
#define ICH12_OFFSET 1255260
#define ICH13_OFFSET 1526955
#define ICH14_OFFSET 1422866
#define ICH15_OFFSET 1950573

//SCALING Calibration
#define VCH1_SCALE 587.405334f
#define VCH2_SCALE 586.671753f
#define VCH3_SCALE 588.544067f

#define ICH1_SCALE 373.724945f
#define ICH2_SCALE 372.63382f
#define ICH3_SCALE 373.513275f
#define ICH4_SCALE 373.479736f
#define ICH5_SCALE 371.957489f
#define ICH6_SCALE 374.6604f
#define ICH7_SCALE 367.930634f
#define ICH8_SCALE 371.881195f
#define ICH9_SCALE 372.879944f
#define ICH10_SCALE 373.310669f
#define ICH11_SCALE 372.951141f
#define ICH12_SCALE 373.939362f
#define ICH13_SCALE 373.499542f
#define ICH14_SCALE 373.601807f
#define ICH15_SCALE 373.354858f

#endif

#if Calibration_Index == PMU72
// OFFSET Calibration

#define VCH1_OFFSET 1263467
#define VCH2_OFFSET 1914128
#define VCH3_OFFSET 1677739
                    
#define ICH1_OFFSET 1364441
#define ICH2_OFFSET 1235857
#define ICH3_OFFSET 1376241
#define ICH4_OFFSET 1354612
#define ICH5_OFFSET 1361013
#define ICH6_OFFSET 1519344
#define ICH7_OFFSET 3995065
#define ICH8_OFFSET 619252
#define ICH9_OFFSET 28531
#define ICH10_OFFSET 208901
#define ICH11_OFFSET 1756429
#define ICH12_OFFSET 1601835
#define ICH13_OFFSET 1870271
#define ICH14_OFFSET 1446074
#define ICH15_OFFSET 1959212

//SCALING Calibration
#define VCH1_SCALE 582.658936f
#define VCH2_SCALE 586.333008f
#define VCH3_SCALE 585.794861f

#define ICH1_SCALE 373.675201f
#define ICH2_SCALE 373.141357f
#define ICH3_SCALE 374.082397f
#define ICH4_SCALE 373.279572f
#define ICH5_SCALE 372.770538f
#define ICH6_SCALE 374.43985f
#define ICH7_SCALE 369.323212f
#define ICH8_SCALE 372.248993f
#define ICH9_SCALE 372.879364f
#define ICH10_SCALE 373.244568f
#define ICH11_SCALE 372.91098f
#define ICH12_SCALE 372.98114f
#define ICH13_SCALE 372.363647f
#define ICH14_SCALE 372.336517f
#define ICH15_SCALE 372.239685f

#endif

#if Calibration_Index == PMU73
// OFFSET Calibration

#define VCH1_OFFSET 48568
#define VCH2_OFFSET 326660
#define VCH3_OFFSET 274071
                    
#define ICH1_OFFSET 1503677
#define ICH2_OFFSET 1481765
#define ICH3_OFFSET 1675862
#define ICH4_OFFSET 1462069
#define ICH5_OFFSET 1358684
#define ICH6_OFFSET 1397742
#define ICH7_OFFSET 3553774
#define ICH8_OFFSET 841888
#define ICH9_OFFSET 94740
#define ICH10_OFFSET 131344
#define ICH11_OFFSET 1405330
#define ICH12_OFFSET 1692520
#define ICH13_OFFSET 1679511
#define ICH14_OFFSET 1672671
#define ICH15_OFFSET 2111910

//SCALING Calibration
#define VCH1_SCALE 587.983765f
#define VCH2_SCALE 585.702637f
#define VCH3_SCALE 587.058655f

#define ICH1_SCALE 371.240631f
#define ICH2_SCALE 372.772461f
#define ICH3_SCALE 374.123108f
#define ICH4_SCALE 372.59552f
#define ICH5_SCALE 373.866333f
#define ICH6_SCALE 373.428711f
#define ICH7_SCALE 372.227631f
#define ICH8_SCALE 372.627319f
#define ICH9_SCALE 373.211426f
#define ICH10_SCALE 372.67392f
#define ICH11_SCALE 373.327759f
#define ICH12_SCALE 372.254059f
#define ICH13_SCALE 372.71991f
#define ICH14_SCALE 372.626831f
#define ICH15_SCALE 374.020905f

#endif

#if Calibration_Index == PMU74
// OFFSET Calibration

#define VCH1_OFFSET 590248
#define VCH2_OFFSET 644670
#define VCH3_OFFSET 792917
                    
#define ICH1_OFFSET 1291907
#define ICH2_OFFSET 1056595
#define ICH3_OFFSET 1211504
#define ICH4_OFFSET 1406997
#define ICH5_OFFSET 1283290
#define ICH6_OFFSET 1251327
#define ICH7_OFFSET 3332829
#define ICH8_OFFSET 638104
#define ICH9_OFFSET 403430
#define ICH10_OFFSET -553959
#define ICH11_OFFSET 1810839
#define ICH12_OFFSET 1571142
#define ICH13_OFFSET 1515925
#define ICH14_OFFSET 1269599
#define ICH15_OFFSET 1901187

//SCALING Calibration
#define VCH1_SCALE 586.306091f
#define VCH2_SCALE 585.508484f
#define VCH3_SCALE 588.184143f

#define ICH1_SCALE 374.2099f
#define ICH2_SCALE 372.637573f
#define ICH3_SCALE 374.984406f
#define ICH4_SCALE 373.919861f
#define ICH5_SCALE 373.172455f
#define ICH6_SCALE 374.60556f
#define ICH7_SCALE 372.226837f
#define ICH8_SCALE 371.726807f
#define ICH9_SCALE 373.063416f
#define ICH10_SCALE 373.549164f
#define ICH11_SCALE 373.213379f
#define ICH12_SCALE 373.059784f
#define ICH13_SCALE 373.312103f
#define ICH14_SCALE 371.751282f
#define ICH15_SCALE 372.594238f

#endif

#if Calibration_Index == PMU75
// OFFSET Calibration

#define VCH1_OFFSET 540412
#define VCH2_OFFSET 259256
#define VCH3_OFFSET 83300
                    
#define ICH1_OFFSET 1603678
#define ICH2_OFFSET 1546510
#define ICH3_OFFSET 1594025
#define ICH4_OFFSET 1540968
#define ICH5_OFFSET 1555870
#define ICH6_OFFSET 1690390
#define ICH7_OFFSET 4167338
#define ICH8_OFFSET 912546
#define ICH9_OFFSET 193262
#define ICH10_OFFSET 583472
#define ICH11_OFFSET 1506221
#define ICH12_OFFSET 1792494
#define ICH13_OFFSET 1403664
#define ICH14_OFFSET 1493205
#define ICH15_OFFSET 2077752

//SCALING Calibration
#define VCH1_SCALE 588.838013f
#define VCH2_SCALE 587.422363f
#define VCH3_SCALE 586.801575f

#define ICH1_SCALE 373.093323f
#define ICH2_SCALE 374.265686f
#define ICH3_SCALE 373.3815f
#define ICH4_SCALE 373.942688f
#define ICH5_SCALE 373.729675f
#define ICH6_SCALE 374.167664f
#define ICH7_SCALE 371.72052f
#define ICH8_SCALE 372.209747f
#define ICH9_SCALE 373.554535f
#define ICH10_SCALE 370.203735f
#define ICH11_SCALE 374.485077f
#define ICH12_SCALE 373.029663f
#define ICH13_SCALE 373.757965f
#define ICH14_SCALE 373.206879f
#define ICH15_SCALE 374.041077f

#endif

#if Calibration_Index == PMU76
// OFFSET Calibration

#define VCH1_OFFSET 1071821
#define VCH2_OFFSET 1344782
#define VCH3_OFFSET 1527909
                    
#define ICH1_OFFSET 1582751
#define ICH2_OFFSET 1565582
#define ICH3_OFFSET 1697265
#define ICH4_OFFSET 1393126
#define ICH5_OFFSET 1643372
#define ICH6_OFFSET 1593702
#define ICH7_OFFSET 4167032
#define ICH8_OFFSET 825821
#define ICH9_OFFSET 470270
#define ICH10_OFFSET 708740
#define ICH11_OFFSET 1411258
#define ICH12_OFFSET 1362010
#define ICH13_OFFSET 1073754
#define ICH14_OFFSET 1217424
#define ICH15_OFFSET 1643327

//SCALING Calibration
#define VCH1_SCALE 582.63446f
#define VCH2_SCALE 586.938721f
#define VCH3_SCALE 586.603027f

#define ICH1_SCALE 373.417664f
#define ICH2_SCALE 375.158447f
#define ICH3_SCALE 374.623505f
#define ICH4_SCALE 373.917358f
#define ICH5_SCALE 374.340088f
#define ICH6_SCALE 373.887146f
#define ICH7_SCALE 368.644653f
#define ICH8_SCALE 373.052216f
#define ICH9_SCALE 371.397644f
#define ICH10_SCALE 368.736786f
#define ICH11_SCALE 372.401794f
#define ICH12_SCALE 373.905792f
#define ICH13_SCALE 371.904602f
#define ICH14_SCALE 375.242218f
#define ICH15_SCALE 372.182251f

#endif

#if Calibration_Index == PMU77
// OFFSET Calibration

#define VCH1_OFFSET 671400
#define VCH2_OFFSET 978777
#define VCH3_OFFSET 1232139
                    
#define ICH1_OFFSET 1771812
#define ICH2_OFFSET 1708291
#define ICH3_OFFSET 1411254
#define ICH4_OFFSET 1573404
#define ICH5_OFFSET 1512667
#define ICH6_OFFSET 1504755
#define ICH7_OFFSET 3387708
#define ICH8_OFFSET 1282216
#define ICH9_OFFSET 463831
#define ICH10_OFFSET -654348
#define ICH11_OFFSET 1771309
#define ICH12_OFFSET 1476420
#define ICH13_OFFSET 1560495
#define ICH14_OFFSET 1168246
#define ICH15_OFFSET 1588312

//SCALING Calibration
#define VCH1_SCALE 586.989624f
#define VCH2_SCALE 585.339661f
#define VCH3_SCALE 582.889832f

#define ICH1_SCALE 371.874023f
#define ICH2_SCALE 375.155853f
#define ICH3_SCALE 373.991669f
#define ICH4_SCALE 373.847778f
#define ICH5_SCALE 375.293671f
#define ICH6_SCALE 373.739838f
#define ICH7_SCALE 374.296356f
#define ICH8_SCALE 371.864075f
#define ICH9_SCALE 374.668793f
#define ICH10_SCALE 373.242249f
#define ICH11_SCALE 375.109833f
#define ICH12_SCALE 373.91922f
#define ICH13_SCALE 373.933136f
#define ICH14_SCALE 374.177338f
#define ICH15_SCALE 374.391144f

#endif

#if Calibration_Index == PMU78
// OFFSET Calibration

#define VCH1_OFFSET 968284
#define VCH2_OFFSET 1072550
#define VCH3_OFFSET 1533959
                    
#define ICH1_OFFSET 1648639
#define ICH2_OFFSET 1419403
#define ICH3_OFFSET 1443500
#define ICH4_OFFSET 1384147
#define ICH5_OFFSET 1268373
#define ICH6_OFFSET 1322466
#define ICH7_OFFSET 3614211
#define ICH8_OFFSET 793098
#define ICH9_OFFSET 458706
#define ICH10_OFFSET 203688
#define ICH11_OFFSET 1535089
#define ICH12_OFFSET 1397556
#define ICH13_OFFSET 1488384
#define ICH14_OFFSET 1408693
#define ICH15_OFFSET 1995870

//SCALING Calibration
#define VCH1_SCALE 583.710632f
#define VCH2_SCALE 583.802856f
#define VCH3_SCALE 583.862f

#define ICH1_SCALE 372.812073f
#define ICH2_SCALE 373.65387f
#define ICH3_SCALE 373.036682f
#define ICH4_SCALE 372.781494f
#define ICH5_SCALE 373.834961f
#define ICH6_SCALE 373.170258f
#define ICH7_SCALE 372.070831f
#define ICH8_SCALE 371.715179f
#define ICH9_SCALE 371.645325f
#define ICH10_SCALE 372.094849f
#define ICH11_SCALE 373.478455f
#define ICH12_SCALE 372.461884f
#define ICH13_SCALE 372.790375f
#define ICH14_SCALE 373.39444f
#define ICH15_SCALE 373.349335f

#endif

#if Calibration_Index == PMU79
// OFFSET Calibration

#define VCH1_OFFSET 904768
#define VCH2_OFFSET 1259877
#define VCH3_OFFSET 1549562
                    
#define ICH1_OFFSET 1611897
#define ICH2_OFFSET 1500059
#define ICH3_OFFSET 1438070
#define ICH4_OFFSET 1598255
#define ICH5_OFFSET 1504303
#define ICH6_OFFSET 1498375
#define ICH7_OFFSET 3903681
#define ICH8_OFFSET 917140
#define ICH9_OFFSET 5048
#define ICH10_OFFSET 120483
#define ICH11_OFFSET 1480275
#define ICH12_OFFSET 1529438
#define ICH13_OFFSET 1531341
#define ICH14_OFFSET 1691148
#define ICH15_OFFSET 1899716

//SCALING Calibration
#define VCH1_SCALE 590.052124f
#define VCH2_SCALE 588.426086f
#define VCH3_SCALE 592.084106f

#define ICH1_SCALE 373.234924f
#define ICH2_SCALE 372.78949f
#define ICH3_SCALE 374.63205f
#define ICH4_SCALE 372.82547f
#define ICH5_SCALE 373.157379f
#define ICH6_SCALE 374.789337f
#define ICH7_SCALE 371.716003f
#define ICH8_SCALE 373.226105f
#define ICH9_SCALE 372.775909f
#define ICH10_SCALE 373.481445f
#define ICH11_SCALE 373.594727f
#define ICH12_SCALE 372.799561f
#define ICH13_SCALE 373.413635f
#define ICH14_SCALE 372.490753f
#define ICH15_SCALE 373.281372f

#endif

#if Calibration_Index == PMU80
// OFFSET Calibration

#define VCH1_OFFSET 495078
#define VCH2_OFFSET 910700
#define VCH3_OFFSET 954689
                    
#define ICH1_OFFSET 1814643
#define ICH2_OFFSET 1571992
#define ICH3_OFFSET 1708577
#define ICH4_OFFSET 1691381
#define ICH5_OFFSET 1463852
#define ICH6_OFFSET 1421988
#define ICH7_OFFSET 4058828
#define ICH8_OFFSET 1050882
#define ICH9_OFFSET 72396
#define ICH10_OFFSET 200771
#define ICH11_OFFSET 1621331
#define ICH12_OFFSET 1556968
#define ICH13_OFFSET 1733661
#define ICH14_OFFSET 1559799
#define ICH15_OFFSET 2047291

//SCALING Calibration
#define VCH1_SCALE 584.950256f
#define VCH2_SCALE 584.266785f
#define VCH3_SCALE 585.129333f

#define ICH1_SCALE 372.65033f
#define ICH2_SCALE 373.546204f
#define ICH3_SCALE 374.717377f
#define ICH4_SCALE 371.696625f
#define ICH5_SCALE 374.116791f
#define ICH6_SCALE 373.069489f
#define ICH7_SCALE 370.735901f
#define ICH8_SCALE 374.216248f
#define ICH9_SCALE 372.53006f
#define ICH10_SCALE 373.167358f
#define ICH11_SCALE 371.997742f
#define ICH12_SCALE 373.681488f
#define ICH13_SCALE 371.907318f
#define ICH14_SCALE 373.628967f
#define ICH15_SCALE 371.594452f

#endif

#if Calibration_Index == PMU81
// OFFSET Calibration

#define VCH1_OFFSET 183262
#define VCH2_OFFSET 31674
#define VCH3_OFFSET 207935
                    
#define ICH1_OFFSET 1407031
#define ICH2_OFFSET 1373784
#define ICH3_OFFSET 1461741
#define ICH4_OFFSET 1502773
#define ICH5_OFFSET 1291786
#define ICH6_OFFSET 1393180
#define ICH7_OFFSET 3649469
#define ICH8_OFFSET 1011400
#define ICH9_OFFSET 285231
#define ICH10_OFFSET 420751
#define ICH11_OFFSET 1130058
#define ICH12_OFFSET 1304498
#define ICH13_OFFSET 1136607
#define ICH14_OFFSET 1293027
#define ICH15_OFFSET 1999333

//SCALING Calibration
#define VCH1_SCALE 587.818542f
#define VCH2_SCALE 583.41272f
#define VCH3_SCALE 587.809937f

#define ICH1_SCALE 374.185669f
#define ICH2_SCALE 374.292816f
#define ICH3_SCALE 375.817322f
#define ICH4_SCALE 374.216461f
#define ICH5_SCALE 375.321655f
#define ICH6_SCALE 375.37088f
#define ICH7_SCALE 372.595276f
#define ICH8_SCALE 373.617615f
#define ICH9_SCALE 373.067352f
#define ICH10_SCALE 371.426849f
#define ICH11_SCALE 371.721771f
#define ICH12_SCALE 372.166412f
#define ICH13_SCALE 374.031372f
#define ICH14_SCALE 371.725647f
#define ICH15_SCALE 374.006042f

#endif


#if Calibration_Index == PMU82
// OFFSET Calibration

#define VCH1_OFFSET 1038024
#define VCH2_OFFSET 959082
#define VCH3_OFFSET 1125777
                    
#define ICH1_OFFSET 1491907
#define ICH2_OFFSET 1553620
#define ICH3_OFFSET 1535937
#define ICH4_OFFSET 1541793
#define ICH5_OFFSET 1486538
#define ICH6_OFFSET 1464475
#define ICH7_OFFSET 3505525
#define ICH8_OFFSET 1094959
#define ICH9_OFFSET 9534
#define ICH10_OFFSET 475913
#define ICH11_OFFSET 1818500
#define ICH12_OFFSET 1603857
#define ICH13_OFFSET 1541948
#define ICH14_OFFSET 1417496
#define ICH15_OFFSET 1895340

//SCALING Calibration
#define VCH1_SCALE 582.522522f
#define VCH2_SCALE 580.944336f
#define VCH3_SCALE 582.910645f

#define ICH1_SCALE 372.51651f
#define ICH2_SCALE 373.342499f
#define ICH3_SCALE 374.077881f
#define ICH4_SCALE 373.195557f
#define ICH5_SCALE 373.973083f
#define ICH6_SCALE 373.710327f
#define ICH7_SCALE 372.599182f
#define ICH8_SCALE 373.873993f
#define ICH9_SCALE 373.381958f
#define ICH10_SCALE 370.721924f
#define ICH11_SCALE 373.200714f
#define ICH12_SCALE 373.223206f
#define ICH13_SCALE 373.919983f
#define ICH14_SCALE 374.458679f
#define ICH15_SCALE 374.458679f

#endif

#if Calibration_Index == PMU83
// OFFSET Calibration

#define VCH1_OFFSET 877141
#define VCH2_OFFSET 980458
#define VCH3_OFFSET 1527461
                    
#define ICH1_OFFSET 1254014
#define ICH2_OFFSET 1224072
#define ICH3_OFFSET 1201257
#define ICH4_OFFSET 1345227
#define ICH5_OFFSET 1194851
#define ICH6_OFFSET 1366677
#define ICH7_OFFSET 3321055
#define ICH8_OFFSET 340677
#define ICH9_OFFSET 467236
#define ICH10_OFFSET 833125
#define ICH11_OFFSET 2033324
#define ICH12_OFFSET 1721181
#define ICH13_OFFSET 1360964
#define ICH14_OFFSET 1459959
#define ICH15_OFFSET 1405449

//SCALING Calibration
#define VCH1_SCALE 585.481567f
#define VCH2_SCALE 587.954712f
#define VCH3_SCALE 588.739502f

#define ICH1_SCALE 374.430023f
#define ICH2_SCALE 372.234741f
#define ICH3_SCALE 373.892212f
#define ICH4_SCALE 373.468384f
#define ICH5_SCALE 372.727539f
#define ICH6_SCALE 374.109192f
#define ICH7_SCALE 372.268646f
#define ICH8_SCALE 371.843048f
#define ICH9_SCALE 372.439758f
#define ICH10_SCALE 371.475769f
#define ICH11_SCALE 371.621399f
#define ICH12_SCALE 372.838409f
#define ICH13_SCALE 373.287506f
#define ICH14_SCALE 372.875885f
#define ICH15_SCALE 371.747437f

#endif

#if Calibration_Index == PMU84
// OFFSET Calibration

#define VCH1_OFFSET 515913
#define VCH2_OFFSET 984568
#define VCH3_OFFSET 779201
                    
#define ICH1_OFFSET 1910683
#define ICH2_OFFSET 1851343
#define ICH3_OFFSET 1448339
#define ICH4_OFFSET 1457161
#define ICH5_OFFSET 1418267
#define ICH6_OFFSET 1691078
#define ICH7_OFFSET 4373453
#define ICH8_OFFSET 772598
#define ICH9_OFFSET 75623
#define ICH10_OFFSET 59833
#define ICH11_OFFSET 1538586
#define ICH12_OFFSET 1591948
#define ICH13_OFFSET 1616310
#define ICH14_OFFSET 1578786
#define ICH15_OFFSET 1906374

//SCALING Calibration
#define VCH1_SCALE 588.03656f
#define VCH2_SCALE 585.389587f
#define VCH3_SCALE 585.396301f

#define ICH1_SCALE 371.38678f
#define ICH2_SCALE 374.222168f
#define ICH3_SCALE 374.222168f
#define ICH4_SCALE 372.387238f
#define ICH5_SCALE 374.732208f
#define ICH6_SCALE 372.527588f
#define ICH7_SCALE 371.44455f
#define ICH8_SCALE 372.489288f
#define ICH9_SCALE 372.232758f
#define ICH10_SCALE 372.59671f
#define ICH11_SCALE 372.966522f
#define ICH12_SCALE 373.301178f
#define ICH13_SCALE 373.093628f
#define ICH14_SCALE 373.611542f
#define ICH15_SCALE 371.525024f

#endif

#if Calibration_Index == PMU85
// OFFSET Calibration

#define VCH1_OFFSET 952605
#define VCH2_OFFSET 1350176
#define VCH3_OFFSET 1172589
                    
#define ICH1_OFFSET 1368366
#define ICH2_OFFSET 1139432
#define ICH3_OFFSET 1556832
#define ICH4_OFFSET 1544430
#define ICH5_OFFSET 1520953
#define ICH6_OFFSET 1247742
#define ICH7_OFFSET 3723771
#define ICH8_OFFSET 826987
#define ICH9_OFFSET 301235
#define ICH10_OFFSET 417201
#define ICH11_OFFSET 1560746
#define ICH12_OFFSET 1565359
#define ICH13_OFFSET 1232326
#define ICH14_OFFSET 1295507
#define ICH15_OFFSET 1930152

//SCALING Calibration
#define VCH1_SCALE 584.910522f
#define VCH2_SCALE 583.557861f
#define VCH3_SCALE 586.532837f

#define ICH1_SCALE 586.532837f
#define ICH2_SCALE 374.262238f
#define ICH3_SCALE 374.500977f
#define ICH4_SCALE 374.159027f
#define ICH5_SCALE 374.724579f
#define ICH6_SCALE 374.393097f
#define ICH7_SCALE 372.182312f
#define ICH8_SCALE 375.193787f
#define ICH9_SCALE 372.278961f
#define ICH10_SCALE 373.438751f
#define ICH11_SCALE 372.435394f
#define ICH12_SCALE 373.946716f
#define ICH13_SCALE 373.312256f
#define ICH14_SCALE 374.034363f
#define ICH15_SCALE 372.701233f

#endif

#if Calibration_Index == PMU86
// OFFSET Calibration

#define VCH1_OFFSET 399501
#define VCH2_OFFSET 450534
#define VCH3_OFFSET 657561
                    
#define ICH1_OFFSET 1742680
#define ICH2_OFFSET 1807913
#define ICH3_OFFSET 1536897
#define ICH4_OFFSET 1572391
#define ICH5_OFFSET 1501288
#define ICH6_OFFSET 1493351
#define ICH7_OFFSET 3644698
#define ICH8_OFFSET 575822
#define ICH9_OFFSET 161563
#define ICH10_OFFSET 144408
#define ICH11_OFFSET 1458158
#define ICH12_OFFSET 1562927
#define ICH13_OFFSET 1328152
#define ICH14_OFFSET 1110178
#define ICH15_OFFSET 1907970

//SCALING Calibration
#define VCH1_SCALE 588.912659f
#define VCH2_SCALE 588.912659f
#define VCH3_SCALE 586.670166f

#define ICH1_SCALE 373.009949f
#define ICH2_SCALE 373.961212f
#define ICH3_SCALE 373.353363f
#define ICH4_SCALE 373.077789f
#define ICH5_SCALE 372.662994f
#define ICH6_SCALE 373.414337f
#define ICH7_SCALE 373.407227f
#define ICH8_SCALE 372.934113f
#define ICH9_SCALE 374.079315f
#define ICH10_SCALE 373.148224f
#define ICH11_SCALE 374.287872f
#define ICH12_SCALE 373.55722f
#define ICH13_SCALE 373.544586f
#define ICH14_SCALE 374.163208f
#define ICH15_SCALE 372.855194f

#endif

#if Calibration_Index == PMU87
// OFFSET Calibration

#define VCH1_OFFSET 643533
#define VCH2_OFFSET 1074968
#define VCH3_OFFSET 1037836
                    
#define ICH1_OFFSET 1456200
#define ICH2_OFFSET 1465976
#define ICH3_OFFSET 1340501
#define ICH4_OFFSET 1329656
#define ICH5_OFFSET 1299936
#define ICH6_OFFSET 1423223
#define ICH7_OFFSET 4367707
#define ICH8_OFFSET 668542
#define ICH9_OFFSET 117789
#define ICH10_OFFSET 452456
#define ICH11_OFFSET 1655839
#define ICH12_OFFSET 1667389
#define ICH13_OFFSET 1151013
#define ICH14_OFFSET 1266951
#define ICH15_OFFSET 1662993

//SCALING Calibration
#define VCH1_SCALE 585.244934f
#define VCH2_SCALE 583.607971f
#define VCH3_SCALE 582.911072f

#define ICH1_SCALE 374.496918f
#define ICH2_SCALE 373.984619f
#define ICH3_SCALE 372.701385f
#define ICH4_SCALE 373.978027f
#define ICH5_SCALE 373.560059f
#define ICH6_SCALE 373.395844f
#define ICH7_SCALE 371.808289f
#define ICH8_SCALE 371.729462f
#define ICH9_SCALE 374.740936f
#define ICH10_SCALE 371.050201f
#define ICH11_SCALE 374.828064f
#define ICH12_SCALE 372.147552f
#define ICH13_SCALE 373.943787f
#define ICH14_SCALE 373.45636f
#define ICH15_SCALE 372.771545f

#endif

#if Calibration_Index == PMU88
// OFFSET Calibration

#define VCH1_OFFSET 210652
#define VCH2_OFFSET 845750
#define VCH3_OFFSET 948719
                    
#define ICH1_OFFSET 1649531
#define ICH2_OFFSET 1702584
#define ICH3_OFFSET 1536863
#define ICH4_OFFSET 1533606
#define ICH5_OFFSET 1794489
#define ICH6_OFFSET 1512046
#define ICH7_OFFSET 4346897
#define ICH8_OFFSET 935202
#define ICH9_OFFSET 585469
#define ICH10_OFFSET 805843
#define ICH11_OFFSET 1474197
#define ICH12_OFFSET 1188906
#define ICH13_OFFSET 954244
#define ICH14_OFFSET 1119268
#define ICH15_OFFSET 1718511

//SCALING Calibration
#define VCH1_SCALE 587.678162f
#define VCH2_SCALE 587.625f
#define VCH3_SCALE 587.235535f

#define ICH1_SCALE 373.477966f
#define ICH2_SCALE 373.727753f
#define ICH3_SCALE 373.819733f
#define ICH4_SCALE 372.335388f
#define ICH5_SCALE 373.960724f
#define ICH6_SCALE 373.983673f
#define ICH7_SCALE 369.800812f
#define ICH8_SCALE 373.453552f
#define ICH9_SCALE 370.492096f
#define ICH10_SCALE 367.219543f
#define ICH11_SCALE 372.701843f
#define ICH12_SCALE 374.763428f
#define ICH13_SCALE 373.182037f
#define ICH14_SCALE 375.325806f
#define ICH15_SCALE 374.411591f

#endif

#if Calibration_Index == PMU89
// OFFSET Calibration

#define VCH1_OFFSET 1204563
#define VCH2_OFFSET 1760206
#define VCH3_OFFSET 1407298
                    
#define ICH1_OFFSET 1534536
#define ICH2_OFFSET 1314725
#define ICH3_OFFSET 1316240
#define ICH4_OFFSET 1318132
#define ICH5_OFFSET 1282565
#define ICH6_OFFSET 1555950
#define ICH7_OFFSET 3702531
#define ICH8_OFFSET 1005260
#define ICH9_OFFSET 379054
#define ICH10_OFFSET 432409
#define ICH11_OFFSET 1342705
#define ICH12_OFFSET 1357393
#define ICH13_OFFSET 1603638
#define ICH14_OFFSET 1220151
#define ICH15_OFFSET 2106334

//SCALING Calibration
#define VCH1_SCALE 587.571045f
#define VCH2_SCALE 585.783081f
#define VCH3_SCALE 585.60675f

#define ICH1_SCALE 372.497192f
#define ICH2_SCALE 375.845673f
#define ICH3_SCALE 373.485352f
#define ICH4_SCALE 372.049744f
#define ICH5_SCALE 375.178192f
#define ICH6_SCALE 372.879913f
#define ICH7_SCALE 373.102661f
#define ICH8_SCALE 372.990326f
#define ICH9_SCALE 372.405487f
#define ICH10_SCALE 370.763916f
#define ICH11_SCALE 373.860168f
#define ICH12_SCALE 372.954132f
#define ICH13_SCALE 373.386292f
#define ICH14_SCALE 373.677032f
#define ICH15_SCALE 372.167023f

#endif

#if Calibration_Index == PMU90
// OFFSET Calibration

#define VCH1_OFFSET 612917
#define VCH2_OFFSET 249516
#define VCH3_OFFSET 8790
                    
#define ICH1_OFFSET 1600894
#define ICH2_OFFSET 1551173
#define ICH3_OFFSET 1602115
#define ICH4_OFFSET 1363680
#define ICH5_OFFSET 1580058
#define ICH6_OFFSET 1441458
#define ICH7_OFFSET 3535614
#define ICH8_OFFSET 884478
#define ICH9_OFFSET 30818
#define ICH10_OFFSET 473471
#define ICH11_OFFSET 1728361
#define ICH12_OFFSET 1621392
#define ICH13_OFFSET 1588964
#define ICH14_OFFSET 1396422
#define ICH15_OFFSET 2015097

//SCALING Calibration
#define VCH1_SCALE 587.57135f
#define VCH2_SCALE 583.960388f
#define VCH3_SCALE 585.463196f

#define ICH1_SCALE 372.245941f
#define ICH2_SCALE 374.490814f
#define ICH3_SCALE 374.282837f
#define ICH4_SCALE 372.51355f
#define ICH5_SCALE 375.203033f
#define ICH6_SCALE 373.50705f
#define ICH7_SCALE 372.368378f
#define ICH8_SCALE 373.083679f
#define ICH9_SCALE 374.140839f
#define ICH10_SCALE 371.421967f
#define ICH11_SCALE 373.858917f
#define ICH12_SCALE 373.220795f
#define ICH13_SCALE 374.391418f
#define ICH14_SCALE 375.498871f
#define ICH15_SCALE 374.127411f

#endif

#if Calibration_Index == PMU91
// OFFSET Calibration

#define VCH1_OFFSET 43636
#define VCH2_OFFSET 502915
#define VCH3_OFFSET 147796
                    
#define ICH1_OFFSET 1330312
#define ICH2_OFFSET 1577129
#define ICH3_OFFSET 1633208
#define ICH4_OFFSET 1583892
#define ICH5_OFFSET 1736727
#define ICH6_OFFSET 1692681
#define ICH7_OFFSET 3836013
#define ICH8_OFFSET 767160
#define ICH9_OFFSET 18568
#define ICH10_OFFSET 164841
#define ICH11_OFFSET 1432940
#define ICH12_OFFSET 1402541
#define ICH13_OFFSET 1468517
#define ICH14_OFFSET 1325058
#define ICH15_OFFSET 1810040

//SCALING Calibration
#define VCH1_SCALE 585.590576f
#define VCH2_SCALE 586.528381f
#define VCH3_SCALE 587.415771f

#define ICH1_SCALE 372.789307f
#define ICH2_SCALE 372.67157f
#define ICH3_SCALE 374.064026f
#define ICH4_SCALE 372.254883f
#define ICH5_SCALE 372.620087f
#define ICH6_SCALE 373.664307f
#define ICH7_SCALE 370.347046f
#define ICH8_SCALE 372.178223f
#define ICH9_SCALE 372.849121f
#define ICH10_SCALE 372.904968f
#define ICH11_SCALE 372.890839f
#define ICH12_SCALE 373.704285f
#define ICH13_SCALE 374.455811f
#define ICH14_SCALE 373.766846f
#define ICH15_SCALE 374.750305f

#endif

#if Calibration_Index == PMU92
// OFFSET Calibration

#define VCH1_OFFSET 152806
#define VCH2_OFFSET 661764
#define VCH3_OFFSET 877850
                    
#define ICH1_OFFSET 1397445
#define ICH2_OFFSET 1349555
#define ICH3_OFFSET 1333096
#define ICH4_OFFSET 1397572
#define ICH5_OFFSET 1517788
#define ICH6_OFFSET 1508162
#define ICH7_OFFSET 3669355
#define ICH8_OFFSET 820478
#define ICH9_OFFSET 44708
#define ICH10_OFFSET 226055
#define ICH11_OFFSET 1707342
#define ICH12_OFFSET 1583027
#define ICH13_OFFSET 1727780
#define ICH14_OFFSET 1493717
#define ICH15_OFFSET 1734682

//SCALING Calibration
#define VCH1_SCALE 588.34259f
#define VCH2_SCALE 586.794495f
#define VCH3_SCALE 585.674133f

#define ICH1_SCALE 373.282562f
#define ICH2_SCALE 376.251099f
#define ICH3_SCALE 373.564056f
#define ICH4_SCALE 373.271088f
#define ICH5_SCALE 376.216461f
#define ICH6_SCALE 373.820618f
#define ICH7_SCALE 369.249298f
#define ICH8_SCALE 373.270599f
#define ICH9_SCALE 374.107758f
#define ICH10_SCALE 372.893951f
#define ICH11_SCALE 374.357697f
#define ICH12_SCALE 374.27478f
#define ICH13_SCALE 373.933899f
#define ICH14_SCALE 375.094269f
#define ICH15_SCALE 373.02771f

#endif

#if Calibration_Index == PMU93
// OFFSET Calibration

#define VCH1_OFFSET 749116
#define VCH2_OFFSET 620171
#define VCH3_OFFSET 938012
                    
#define ICH1_OFFSET 1599910
#define ICH2_OFFSET 1665556
#define ICH3_OFFSET 1540679
#define ICH4_OFFSET 1299079
#define ICH5_OFFSET 1545831
#define ICH6_OFFSET 1493105
#define ICH7_OFFSET 3890952
#define ICH8_OFFSET 1004619
#define ICH9_OFFSET 248603
#define ICH10_OFFSET 408568
#define ICH11_OFFSET 1608259
#define ICH12_OFFSET 1012925
#define ICH13_OFFSET 1237003
#define ICH14_OFFSET 1190245
#define ICH15_OFFSET 1376079

//SCALING Calibration
#define VCH1_SCALE 585.588745f
#define VCH2_SCALE 585.570129f
#define VCH3_SCALE 585.531555f

#define ICH1_SCALE 373.161774f
#define ICH2_SCALE 374.430908f
#define ICH3_SCALE 373.186005f
#define ICH4_SCALE 374.30545f
#define ICH5_SCALE 373.166199f
#define ICH6_SCALE 374.321991f
#define ICH7_SCALE 372.475433f
#define ICH8_SCALE 371.293854f
#define ICH9_SCALE 373.506592f
#define ICH10_SCALE 370.72583f
#define ICH11_SCALE 373.717346f
#define ICH12_SCALE 372.222443f
#define ICH13_SCALE 373.759888f
#define ICH14_SCALE 373.805756f
#define ICH15_SCALE 373.4599f

#endif

#if Calibration_Index == PMU94
// OFFSET Calibration

#define VCH1_OFFSET 1319304
#define VCH2_OFFSET 1651479
#define VCH3_OFFSET 1509909
                    
#define ICH1_OFFSET 1639300
#define ICH2_OFFSET 1729822
#define ICH3_OFFSET 1726300
#define ICH4_OFFSET 1747381
#define ICH5_OFFSET 1602356
#define ICH6_OFFSET 1441572
#define ICH7_OFFSET 3595647
#define ICH8_OFFSET 778724
#define ICH9_OFFSET 53899
#define ICH10_OFFSET 205571
#define ICH11_OFFSET 1632143
#define ICH12_OFFSET 1336584
#define ICH13_OFFSET 1712155
#define ICH14_OFFSET 1581461
#define ICH15_OFFSET 1870875

//SCALING Calibration
#define VCH1_SCALE 585.304871f
#define VCH2_SCALE 584.684937f
#define VCH3_SCALE 583.97821f

#define ICH1_SCALE 372.701385f
#define ICH2_SCALE 374.595947f
#define ICH3_SCALE 371.183105f
#define ICH4_SCALE 373.903503f
#define ICH5_SCALE 372.472961f
#define ICH6_SCALE 372.973541f
#define ICH7_SCALE 372.372498f
#define ICH8_SCALE 370.78479f
#define ICH9_SCALE 375.165833f
#define ICH10_SCALE 371.996826f
#define ICH11_SCALE 375.350128f
#define ICH12_SCALE 373.456573f
#define ICH13_SCALE 374.602325f
#define ICH14_SCALE 374.555481f
#define ICH15_SCALE 374.555481f

#endif

#if Calibration_Index == PMU95
// OFFSET Calibration

#define VCH1_OFFSET 333224
#define VCH2_OFFSET 401794
#define VCH3_OFFSET 333022
                    
#define ICH1_OFFSET 1893496
#define ICH2_OFFSET 1636906
#define ICH3_OFFSET 1803261
#define ICH4_OFFSET 1588500
#define ICH5_OFFSET 1643794
#define ICH6_OFFSET 1707379
#define ICH7_OFFSET 3646695
#define ICH8_OFFSET 1171046
#define ICH9_OFFSET 143461
#define ICH10_OFFSET 234737
#define ICH11_OFFSET 1471465
#define ICH12_OFFSET 1502060
#define ICH13_OFFSET 1571991
#define ICH14_OFFSET 1490480
#define ICH15_OFFSET 2331997

//SCALING Calibration
#define VCH1_SCALE 587.038086f
#define VCH2_SCALE 584.165222f
#define VCH3_SCALE 584.668396f

#define ICH1_SCALE 373.007721f
#define ICH2_SCALE 374.531616f
#define ICH3_SCALE 373.453461f
#define ICH4_SCALE 373.963379f
#define ICH5_SCALE 373.362061f
#define ICH6_SCALE 373.245605f
#define ICH7_SCALE 372.884827f
#define ICH8_SCALE 372.11441f
#define ICH9_SCALE 374.411285f
#define ICH10_SCALE 374.411285f
#define ICH11_SCALE 374.713928f
#define ICH12_SCALE 371.775299f
#define ICH13_SCALE 374.448059f
#define ICH14_SCALE 371.274506f
#define ICH15_SCALE 374.137817f

#endif

#if Calibration_Index == PMU96
// OFFSET Calibration

#define VCH1_OFFSET 7073
#define VCH2_OFFSET 56346
#define VCH3_OFFSET 250162
                    
#define ICH1_OFFSET 1695600
#define ICH2_OFFSET 1541828
#define ICH3_OFFSET 1389762
#define ICH4_OFFSET 1368353
#define ICH5_OFFSET 1605634
#define ICH6_OFFSET 1409401
#define ICH7_OFFSET 3568178
#define ICH8_OFFSET 1060232
#define ICH9_OFFSET 587538
#define ICH10_OFFSET 140058
#define ICH11_OFFSET 1244355
#define ICH12_OFFSET 1338081
#define ICH13_OFFSET 1268033
#define ICH14_OFFSET 1224860
#define ICH15_OFFSET 1933239

//SCALING Calibration
#define VCH1_SCALE 584.052124f
#define VCH2_SCALE 583.937744f
#define VCH3_SCALE 584.218262f

#define ICH1_SCALE 372.86026f
#define ICH2_SCALE 374.555573f
#define ICH3_SCALE 373.780487f
#define ICH4_SCALE 373.432861f
#define ICH5_SCALE 373.686554f
#define ICH6_SCALE 375.044739f
#define ICH7_SCALE 370.215271f
#define ICH8_SCALE 373.557495f
#define ICH9_SCALE 370.333771f
#define ICH10_SCALE 374.17926f
#define ICH11_SCALE 372.691223f
#define ICH12_SCALE 374.090027f
#define ICH13_SCALE 371.492035f
#define ICH14_SCALE 374.340179f
#define ICH15_SCALE 372.179901f

#endif

#if Calibration_Index == PMU97
// OFFSET Calibration

#define VCH1_OFFSET 109627
#define VCH2_OFFSET 650851
#define VCH3_OFFSET 792326
                    
#define ICH1_OFFSET 1609481
#define ICH2_OFFSET 1470692
#define ICH3_OFFSET 1476896
#define ICH4_OFFSET 1446037
#define ICH5_OFFSET 1688878
#define ICH6_OFFSET 1613950
#define ICH7_OFFSET 3695970
#define ICH8_OFFSET 888567
#define ICH9_OFFSET 32270
#define ICH10_OFFSET 820919
#define ICH11_OFFSET 1613144
#define ICH12_OFFSET 1514862
#define ICH13_OFFSET 1444405
#define ICH14_OFFSET 1428363
#define ICH15_OFFSET 1957059

//SCALING Calibration
#define VCH1_SCALE 586.248108f
#define VCH2_SCALE 586.517151f
#define VCH3_SCALE 587.299011f

#define ICH1_SCALE 372.128479f
#define ICH2_SCALE 374.478241f
#define ICH3_SCALE 372.877594f
#define ICH4_SCALE 372.699097f
#define ICH5_SCALE 372.77301f
#define ICH6_SCALE 373.325745f
#define ICH7_SCALE 372.110474f
#define ICH8_SCALE 373.357117f
#define ICH9_SCALE 371.573242f
#define ICH10_SCALE 367.727509f
#define ICH11_SCALE 372.402313f
#define ICH12_SCALE 372.274231f
#define ICH13_SCALE 372.435913f
#define ICH14_SCALE 372.638214f
#define ICH15_SCALE 372.600677f

#endif

#if Calibration_Index == PMU98
// OFFSET Calibration

#define VCH1_OFFSET 1052256
#define VCH2_OFFSET 1450199
#define VCH3_OFFSET 1128524
                    
#define ICH1_OFFSET 1766918
#define ICH2_OFFSET 1514930
#define ICH3_OFFSET 1706643
#define ICH4_OFFSET 1376370
#define ICH5_OFFSET 1754967
#define ICH6_OFFSET 1463271
#define ICH7_OFFSET 3416702
#define ICH8_OFFSET 1213455
#define ICH9_OFFSET 240359
#define ICH10_OFFSET 296955
#define ICH11_OFFSET 1582459
#define ICH12_OFFSET 1455438
#define ICH13_OFFSET 1322401
#define ICH14_OFFSET 1457007
#define ICH15_OFFSET 1797186

//SCALING Calibration
#define VCH1_SCALE 585.863953f
#define VCH2_SCALE 583.403931f
#define VCH3_SCALE 586.138855f

#define ICH1_SCALE 373.619751f
#define ICH2_SCALE 374.029083f
#define ICH3_SCALE 374.521545f
#define ICH4_SCALE 373.154358f
#define ICH5_SCALE 373.880951f
#define ICH6_SCALE 374.242188f
#define ICH7_SCALE 373.991943f
#define ICH8_SCALE 373.483948f
#define ICH9_SCALE 375.205109f
#define ICH10_SCALE 372.515747f
#define ICH11_SCALE 374.947784f
#define ICH12_SCALE 372.684845f
#define ICH13_SCALE 375.494232f
#define ICH14_SCALE 373.199371f
#define ICH15_SCALE 374.858093f

#endif

#if Calibration_Index == PMU99
// OFFSET Calibration

#define VCH1_OFFSET 788439
#define VCH2_OFFSET 949411
#define VCH3_OFFSET 1383492
                    
#define ICH1_OFFSET 1493529
#define ICH2_OFFSET 1523929
#define ICH3_OFFSET 1725730
#define ICH4_OFFSET 1310065
#define ICH5_OFFSET 1745442
#define ICH6_OFFSET 1530717
#define ICH7_OFFSET 3971793
#define ICH8_OFFSET 1360071
#define ICH9_OFFSET 342291
#define ICH10_OFFSET 484042
#define ICH11_OFFSET 1572437
#define ICH12_OFFSET 1442764
#define ICH13_OFFSET 1563089
#define ICH14_OFFSET 1627993
#define ICH15_OFFSET 1751498

//SCALING Calibration
#define VCH1_SCALE 583.751465f
#define VCH2_SCALE 584.048706f
#define VCH3_SCALE 584.99353f

#define ICH1_SCALE 374.41391f
#define ICH2_SCALE 373.378387f
#define ICH3_SCALE 374.276184f
#define ICH4_SCALE 374.326782f
#define ICH5_SCALE 373.880615f
#define ICH6_SCALE 374.824371f
#define ICH7_SCALE 373.133148f
#define ICH8_SCALE 373.268372f
#define ICH9_SCALE 373.708038f
#define ICH10_SCALE 372.220367f
#define ICH11_SCALE 372.722321f
#define ICH12_SCALE 373.219086f
#define ICH13_SCALE 373.530701f
#define ICH14_SCALE 373.326599f
#define ICH15_SCALE 372.949554f

#endif

#if Calibration_Index == PMU100
// OFFSET Calibration

#define VCH1_OFFSET 814788
#define VCH2_OFFSET 1139808
#define VCH3_OFFSET 1211997
                    
#define ICH1_OFFSET 1623282
#define ICH2_OFFSET 1775029
#define ICH3_OFFSET 1715173
#define ICH4_OFFSET 1424332
#define ICH5_OFFSET 1522755
#define ICH6_OFFSET 1651745
#define ICH7_OFFSET 3681826
#define ICH8_OFFSET 1108838
#define ICH9_OFFSET 81965
#define ICH10_OFFSET 48408
#define ICH11_OFFSET 1848796
#define ICH12_OFFSET 1809962
#define ICH13_OFFSET 1973600
#define ICH14_OFFSET 1633832
#define ICH15_OFFSET 2071095

//SCALING Calibration
#define VCH1_SCALE 586.189575f
#define VCH2_SCALE 587.300049f
#define VCH3_SCALE 584.807617f

#define ICH1_SCALE 374.252441f
#define ICH2_SCALE 374.212341f
#define ICH3_SCALE 372.961243f
#define ICH4_SCALE 373.717133f
#define ICH5_SCALE 374.170044f
#define ICH6_SCALE 373.67099f
#define ICH7_SCALE 372.821075f
#define ICH8_SCALE 371.66275f
#define ICH9_SCALE 375.808014f
#define ICH10_SCALE 372.336182f
#define ICH11_SCALE 374.88031f
#define ICH12_SCALE 372.185303f
#define ICH13_SCALE 374.547363f
#define ICH14_SCALE 373.023254f
#define ICH15_SCALE 374.819794f

#endif

#if Calibration_Index == PMU101
// OFFSET Calibration

#define VCH1_OFFSET 261350
#define VCH2_OFFSET 443957
#define VCH3_OFFSET 839349
                    
#define ICH1_OFFSET 1677064
#define ICH2_OFFSET 1487460
#define ICH3_OFFSET 1390443
#define ICH4_OFFSET 1534158
#define ICH5_OFFSET 1746689
#define ICH6_OFFSET 1407228
#define ICH7_OFFSET 3817839
#define ICH8_OFFSET 791191
#define ICH9_OFFSET 86555
#define ICH10_OFFSET 80902
#define ICH11_OFFSET 1893773
#define ICH12_OFFSET 1986142
#define ICH13_OFFSET 1710644
#define ICH14_OFFSET 1640283
#define ICH15_OFFSET 2038696

//SCALING Calibration
#define VCH1_SCALE 589.216919f
#define VCH2_SCALE 585.660767f
#define VCH3_SCALE 586.57666f

#define ICH1_SCALE 372.793884f
#define ICH2_SCALE 373.355347f
#define ICH3_SCALE 373.66098f
#define ICH4_SCALE 372.534241f
#define ICH5_SCALE 373.423218f
#define ICH6_SCALE 371.897095f
#define ICH7_SCALE 373.839752f
#define ICH8_SCALE 372.497101f
#define ICH9_SCALE 373.978699f
#define ICH10_SCALE 372.15097f
#define ICH11_SCALE 374.18338f
#define ICH12_SCALE 372.791809f
#define ICH13_SCALE 374.436249f
#define ICH14_SCALE 372.673431f
#define ICH15_SCALE 373.580048f

#endif

#if Calibration_Index == PMU102
// OFFSET Calibration

#define VCH1_OFFSET 119593
#define VCH2_OFFSET 532588
#define VCH3_OFFSET 485796
                    
#define ICH1_OFFSET 1378892
#define ICH2_OFFSET 1404324
#define ICH3_OFFSET 1269390
#define ICH4_OFFSET 1527860
#define ICH5_OFFSET 1206053
#define ICH6_OFFSET 1198252
#define ICH7_OFFSET 3352965
#define ICH8_OFFSET 857393
#define ICH9_OFFSET 284792
#define ICH10_OFFSET 221660
#define ICH11_OFFSET 1637405
#define ICH12_OFFSET 1397852
#define ICH13_OFFSET 1267935
#define ICH14_OFFSET 1111106
#define ICH15_OFFSET 1407688

//SCALING Calibration
#define VCH1_SCALE 587.492126f
#define VCH2_SCALE 587.642883f
#define VCH3_SCALE 588.400513f

#define ICH1_SCALE 374.135254f
#define ICH2_SCALE 372.985443f
#define ICH3_SCALE 372.845642f
#define ICH4_SCALE 373.01474f
#define ICH5_SCALE 372.936646f
#define ICH6_SCALE 373.550323f
#define ICH7_SCALE 372.625061f
#define ICH8_SCALE 372.659088f
#define ICH9_SCALE 373.475739f
#define ICH10_SCALE 372.014099f
#define ICH11_SCALE 373.954895f
#define ICH12_SCALE 373.20752f
#define ICH13_SCALE 373.689178f
#define ICH14_SCALE 373.435028f
#define ICH15_SCALE 373.090668f

#endif

#if Calibration_Index == PMU103
// OFFSET Calibration

#define VCH1_OFFSET 43322
#define VCH2_OFFSET 328022
#define VCH3_OFFSET 442206
                    
#define ICH1_OFFSET 1698588
#define ICH2_OFFSET 1636686
#define ICH3_OFFSET 1720949
#define ICH4_OFFSET 1657594
#define ICH5_OFFSET 1433141
#define ICH6_OFFSET 1634487
#define ICH7_OFFSET 4072508
#define ICH8_OFFSET 947429
#define ICH9_OFFSET 163899
#define ICH10_OFFSET 542037
#define ICH11_OFFSET 1889057
#define ICH12_OFFSET 1695110
#define ICH13_OFFSET 1664770
#define ICH14_OFFSET 1505862
#define ICH15_OFFSET 1998896

//SCALING Calibration
#define VCH1_SCALE 582.970337f
#define VCH2_SCALE 586.002808f
#define VCH3_SCALE 582.386108f

#define ICH1_SCALE 373.688049f
#define ICH2_SCALE 375.305542f
#define ICH3_SCALE 373.360962f
#define ICH4_SCALE 372.287537f
#define ICH5_SCALE 374.164032f
#define ICH6_SCALE 373.521881f
#define ICH7_SCALE 373.979187f
#define ICH8_SCALE 372.186188f
#define ICH9_SCALE 373.416901f
#define ICH10_SCALE 368.747223f
#define ICH11_SCALE 373.518555f
#define ICH12_SCALE 373.005646f
#define ICH13_SCALE 373.159149f
#define ICH14_SCALE 372.785095f
#define ICH15_SCALE 373.079132f

#endif

#if Calibration_Index == PMU104
// OFFSET Calibration

#define VCH1_OFFSET 452645
#define VCH2_OFFSET 710114
#define VCH3_OFFSET 945216
                    
#define ICH1_OFFSET 1608184
#define ICH2_OFFSET 1431987
#define ICH3_OFFSET 1517541
#define ICH4_OFFSET 1699624
#define ICH5_OFFSET 1703744
#define ICH6_OFFSET 1389410
#define ICH7_OFFSET 3193956
#define ICH8_OFFSET 1397177
#define ICH9_OFFSET 246297
#define ICH10_OFFSET 385023
#define ICH11_OFFSET 1384924
#define ICH12_OFFSET 1297365
#define ICH13_OFFSET 1233688
#define ICH14_OFFSET 1267130
#define ICH15_OFFSET 1915078

//SCALING Calibration
#define VCH1_SCALE 587.783325f
#define VCH2_SCALE 584.824768f
#define VCH3_SCALE 585.766296f

#define ICH1_SCALE 373.520966f
#define ICH2_SCALE 373.862213f
#define ICH3_SCALE 375.154083f
#define ICH4_SCALE 371.989532f
#define ICH5_SCALE 374.154266f
#define ICH6_SCALE 373.958344f
#define ICH7_SCALE 373.04715f
#define ICH8_SCALE 374.124725f
#define ICH9_SCALE 373.259552f
#define ICH10_SCALE 371.545013f
#define ICH11_SCALE 373.599213f
#define ICH12_SCALE 372.431793f
#define ICH13_SCALE 374.037567f
#define ICH14_SCALE 373.28656f
#define ICH15_SCALE 373.180695f

#endif

#if Calibration_Index == PMU105
// OFFSET Calibration

#define VCH1_OFFSET 173387
#define VCH2_OFFSET 554459
#define VCH3_OFFSET 774705
                    
#define ICH1_OFFSET 1517251
#define ICH2_OFFSET 1751302
#define ICH3_OFFSET 1573072
#define ICH4_OFFSET 1508767
#define ICH5_OFFSET 1360538
#define ICH6_OFFSET 1592250
#define ICH7_OFFSET 3571567
#define ICH8_OFFSET 768606
#define ICH9_OFFSET 427883
#define ICH10_OFFSET 343050
#define ICH11_OFFSET 1529526
#define ICH12_OFFSET 1548853
#define ICH13_OFFSET 1535715
#define ICH14_OFFSET 1529104
#define ICH15_OFFSET 1788114

//SCALING Calibration
#define VCH1_SCALE 588.53772f
#define VCH2_SCALE 590.139404f
#define VCH3_SCALE 589.13031f

#define ICH1_SCALE 374.699097f
#define ICH2_SCALE 375.301453f
#define ICH3_SCALE 372.659119f
#define ICH4_SCALE 373.706604f
#define ICH5_SCALE 374.838928f
#define ICH6_SCALE 374.619568f
#define ICH7_SCALE 373.247192f
#define ICH8_SCALE 374.520691f
#define ICH9_SCALE 371.456299f
#define ICH10_SCALE 372.662903f
#define ICH11_SCALE 373.028198f
#define ICH12_SCALE 373.547821f
#define ICH13_SCALE 373.456299f
#define ICH14_SCALE 374.340851f
#define ICH15_SCALE 372.972046f

#endif

#if Calibration_Index == PMU106
// OFFSET Calibration

#define VCH1_OFFSET 805926
#define VCH2_OFFSET 1287992
#define VCH3_OFFSET 1328801
                    
#define ICH1_OFFSET 1361007
#define ICH2_OFFSET 1074153
#define ICH3_OFFSET 1298509
#define ICH4_OFFSET 1251720
#define ICH5_OFFSET 1227210
#define ICH6_OFFSET 1416105
#define ICH7_OFFSET 4447302
#define ICH8_OFFSET 129811
#define ICH9_OFFSET 240300
#define ICH10_OFFSET 322925
#define ICH11_OFFSET 1671255
#define ICH12_OFFSET 1599040
#define ICH13_OFFSET 1571092
#define ICH14_OFFSET 1478351
#define ICH15_OFFSET 1960228

//SCALING Calibration
#define VCH1_SCALE 585.840393f
#define VCH2_SCALE 585.193726f
#define VCH3_SCALE 585.414001f

#define ICH1_SCALE 374.369598f
#define ICH2_SCALE 374.977814f
#define ICH3_SCALE 374.635803f
#define ICH4_SCALE 374.725464f
#define ICH5_SCALE 374.302032f
#define ICH6_SCALE 375.880341f
#define ICH7_SCALE 369.439484f
#define ICH8_SCALE 373.571716f
#define ICH9_SCALE 372.511536f
#define ICH10_SCALE 374.244446f
#define ICH11_SCALE 373.33313f
#define ICH12_SCALE 374.097076f
#define ICH13_SCALE 373.44278f
#define ICH14_SCALE 375.577515f
#define ICH15_SCALE 372.410492f

#endif


#if Calibration_Index == PMU107
// OFFSET Calibration

#define VCH1_OFFSET 696187
#define VCH2_OFFSET 996270
#define VCH3_OFFSET 953547
                    
#define ICH1_OFFSET 1466894
#define ICH2_OFFSET 1681103
#define ICH3_OFFSET 1751012
#define ICH4_OFFSET 1595263
#define ICH5_OFFSET 1549462
#define ICH6_OFFSET 1513463
#define ICH7_OFFSET 3225650
#define ICH8_OFFSET 1107740
#define ICH9_OFFSET 582821
#define ICH10_OFFSET 198481
#define ICH11_OFFSET 1799141
#define ICH12_OFFSET 1636608
#define ICH13_OFFSET 1385079
#define ICH14_OFFSET 1638262
#define ICH15_OFFSET 1899892

//SCALING Calibration
#define VCH1_SCALE 584.923218f
#define VCH2_SCALE 588.067688f
#define VCH3_SCALE 583.982422f

#define ICH1_SCALE 371.066742f
#define ICH2_SCALE 373.476318f
#define ICH3_SCALE 372.815308f
#define ICH4_SCALE 373.789185f
#define ICH5_SCALE 371.410889f
#define ICH6_SCALE 371.410889f
#define ICH7_SCALE 371.150574f
#define ICH8_SCALE 371.150574f
#define ICH9_SCALE 371.83667f
#define ICH10_SCALE 372.020782f
#define ICH11_SCALE 372.9935f
#define ICH12_SCALE 372.992065f
#define ICH13_SCALE 374.577972f
#define ICH14_SCALE 373.280426f
#define ICH15_SCALE 373.818878f

#endif

#if Calibration_Index == PMU108
// OFFSET Calibration

#define VCH1_OFFSET 900658
#define VCH2_OFFSET 761301
#define VCH3_OFFSET 1024555
                    
#define ICH1_OFFSET 1472961
#define ICH2_OFFSET 1546323
#define ICH3_OFFSET 1524718
#define ICH4_OFFSET 1498198
#define ICH5_OFFSET 1300917
#define ICH6_OFFSET 1443651
#define ICH7_OFFSET 2420594
#define ICH8_OFFSET 1274700
#define ICH9_OFFSET 358757
#define ICH10_OFFSET 171563
#define ICH11_OFFSET 1821324
#define ICH12_OFFSET 1442433
#define ICH13_OFFSET 1488782
#define ICH14_OFFSET 1628399
#define ICH15_OFFSET 1648401

//SCALING Calibration
#define VCH1_SCALE 584.800598f
#define VCH2_SCALE 586.033691f
#define VCH3_SCALE 584.940125f

#define ICH1_SCALE 372.561462f
#define ICH2_SCALE 372.949738f
#define ICH3_SCALE 372.007263f
#define ICH4_SCALE 373.216309f
#define ICH5_SCALE 372.88858f
#define ICH6_SCALE 372.057404f
#define ICH7_SCALE 372.584534f
#define ICH8_SCALE 370.64093f
#define ICH9_SCALE 371.86319f
#define ICH10_SCALE 373.224304f
#define ICH11_SCALE 371.940857f
#define ICH12_SCALE 372.100098f
#define ICH13_SCALE 372.104919f
#define ICH14_SCALE 375.065033f
#define ICH15_SCALE 373.239868f

#endif

#if Calibration_Index == PMU109
// OFFSET Calibration

#define VCH1_OFFSET 449220
#define VCH2_OFFSET 169670
#define VCH3_OFFSET 216079
                    
#define ICH1_OFFSET 1217081
#define ICH2_OFFSET 1091619
#define ICH3_OFFSET 1073536
#define ICH4_OFFSET 1271919
#define ICH5_OFFSET 1250098
#define ICH6_OFFSET 1188824
#define ICH7_OFFSET 3611656
#define ICH8_OFFSET 787637
#define ICH9_OFFSET 186958
#define ICH10_OFFSET 18801
#define ICH11_OFFSET 1845496
#define ICH12_OFFSET 1927772
#define ICH13_OFFSET 1829110
#define ICH14_OFFSET 1661139
#define ICH15_OFFSET 2136530

//SCALING Calibration
#define VCH1_SCALE 584.24823f
#define VCH2_SCALE 585.982422f
#define VCH3_SCALE 584.52478f

#define ICH1_SCALE 374.204742f
#define ICH2_SCALE 375.603943f
#define ICH3_SCALE 374.864166f
#define ICH4_SCALE 376.387665f
#define ICH5_SCALE 374.230652f
#define ICH6_SCALE 374.38623f
#define ICH7_SCALE 370.091431f
#define ICH8_SCALE 374.910278f
#define ICH9_SCALE 372.164886f
#define ICH10_SCALE 373.659058f
#define ICH11_SCALE 370.98642f
#define ICH12_SCALE 372.731476f
#define ICH13_SCALE 373.531464f
#define ICH14_SCALE 372.78363f
#define ICH15_SCALE 371.4245f

#endif

#if Calibration_Index == PMU110
// OFFSET Calibration

#define VCH1_OFFSET 311640
#define VCH2_OFFSET 233393
#define VCH3_OFFSET 49479
                    
#define ICH1_OFFSET 1767435
#define ICH2_OFFSET 1907234
#define ICH3_OFFSET 1782884
#define ICH4_OFFSET 1637375
#define ICH5_OFFSET 1733473
#define ICH6_OFFSET 1571930
#define ICH7_OFFSET 3908258
#define ICH8_OFFSET 1026872
#define ICH9_OFFSET 78817
#define ICH10_OFFSET 720375
#define ICH11_OFFSET 1710120
#define ICH12_OFFSET 1676658
#define ICH13_OFFSET 1868847
#define ICH14_OFFSET 1704016
#define ICH15_OFFSET 1856042

//SCALING Calibration
#define VCH1_SCALE 587.542664f
#define VCH2_SCALE 586.855042f
#define VCH3_SCALE 586.177246f

#define ICH1_SCALE 372.416077f
#define ICH2_SCALE 373.330048f
#define ICH3_SCALE 374.823334f
#define ICH4_SCALE 372.948395f
#define ICH5_SCALE 373.297211f
#define ICH6_SCALE 374.270691f
#define ICH7_SCALE 371.440979f
#define ICH8_SCALE 373.514832f
#define ICH9_SCALE 372.43985f
#define ICH10_SCALE 368.588745f
#define ICH11_SCALE 372.522461f
#define ICH12_SCALE 374.022888f
#define ICH13_SCALE 373.518982f
#define ICH14_SCALE 373.700958f
#define ICH15_SCALE 373.994751f

#endif

#if Calibration_Index == PMU111
// OFFSET Calibration

#define VCH1_OFFSET 944629
#define VCH2_OFFSET 924563
#define VCH3_OFFSET 1092699
                    
#define ICH1_OFFSET 1822778
#define ICH2_OFFSET 1376410
#define ICH3_OFFSET 1698991
#define ICH4_OFFSET 1518460
#define ICH5_OFFSET 1957580
#define ICH6_OFFSET 1606570
#define ICH7_OFFSET 3400595
#define ICH8_OFFSET 1236305
#define ICH9_OFFSET 106370
#define ICH10_OFFSET 322657
#define ICH11_OFFSET 1359952
#define ICH12_OFFSET 1500689
#define ICH13_OFFSET 1517781
#define ICH14_OFFSET 1569922
#define ICH15_OFFSET 1958932

//SCALING Calibration
#define VCH1_SCALE 589.665283f
#define VCH2_SCALE 587.34552f
#define VCH3_SCALE 587.72583f

#define ICH1_SCALE 587.72583f
#define ICH2_SCALE 373.814178f
#define ICH3_SCALE 373.860657f
#define ICH4_SCALE 374.251923f
#define ICH5_SCALE 374.432159f
#define ICH6_SCALE 372.827759f
#define ICH7_SCALE 372.003174f
#define ICH8_SCALE 372.112793f
#define ICH9_SCALE 373.053711f
#define ICH10_SCALE 374.266449f
#define ICH11_SCALE 372.483429f
#define ICH12_SCALE 373.676178f
#define ICH13_SCALE 372.388031f
#define ICH14_SCALE 374.207367f
#define ICH15_SCALE 372.230743f

#endif

#if Calibration_Index == PMU112
// OFFSET Calibration

#define VCH1_OFFSET 963320
#define VCH2_OFFSET 1009247
#define VCH3_OFFSET 1252865
                    
#define ICH1_OFFSET 1268999
#define ICH2_OFFSET 1379172
#define ICH3_OFFSET 1351493
#define ICH4_OFFSET 1237963
#define ICH5_OFFSET 1249184
#define ICH6_OFFSET 1398743
#define ICH7_OFFSET 3552322
#define ICH8_OFFSET 637483
#define ICH9_OFFSET 3448
#define ICH10_OFFSET 235360
#define ICH11_OFFSET 1992561
#define ICH12_OFFSET 1843330
#define ICH13_OFFSET 1685103
#define ICH14_OFFSET 1657109
#define ICH15_OFFSET 1932143

//SCALING Calibration
#define VCH1_SCALE 586.204529f
#define VCH2_SCALE 586.005188f
#define VCH3_SCALE 589.272583f

#define ICH1_SCALE 375.396851f
#define ICH2_SCALE 373.37262f
#define ICH3_SCALE 372.80011f
#define ICH4_SCALE 372.654633f
#define ICH5_SCALE 374.088196f
#define ICH6_SCALE 371.749573f
#define ICH7_SCALE 369.892853f
#define ICH8_SCALE 373.817719f
#define ICH9_SCALE 371.681458f
#define ICH10_SCALE 374.7966f
#define ICH11_SCALE 373.643097f
#define ICH12_SCALE 372.76947f
#define ICH13_SCALE 372.59964f
#define ICH14_SCALE 372.760529f
#define ICH15_SCALE 374.412079f

#endif

#if Calibration_Index == PMU113
// OFFSET Calibration

#define VCH1_OFFSET 750852
#define VCH2_OFFSET 1183094
#define VCH3_OFFSET 1418064
                    
#define ICH1_OFFSET 1794767
#define ICH2_OFFSET 1446472
#define ICH3_OFFSET 1388890
#define ICH4_OFFSET 1386437
#define ICH5_OFFSET 1629663
#define ICH6_OFFSET 1414625
#define ICH7_OFFSET 4102656
#define ICH8_OFFSET 726472
#define ICH9_OFFSET 182576
#define ICH10_OFFSET 488291
#define ICH11_OFFSET 1571922
#define ICH12_OFFSET 1434264
#define ICH13_OFFSET 1305636
#define ICH14_OFFSET 1334210
#define ICH15_OFFSET 1737484

//SCALING Calibration
#define VCH1_SCALE 584.401855f
#define VCH2_SCALE 585.803894f
#define VCH3_SCALE 585.317566f

#define ICH1_SCALE 375.591644f
#define ICH2_SCALE 373.899658f
#define ICH3_SCALE 372.689758f
#define ICH4_SCALE 373.647278f
#define ICH5_SCALE 375.787231f
#define ICH6_SCALE 374.381592f
#define ICH7_SCALE 370.035095f
#define ICH8_SCALE 374.610718f
#define ICH9_SCALE 374.138153f
#define ICH10_SCALE 372.351044f
#define ICH11_SCALE 371.044128f
#define ICH12_SCALE 374.049255f
#define ICH13_SCALE 373.109375f
#define ICH14_SCALE 372.171539f
#define ICH15_SCALE 372.64444f

#endif

#if Calibration_Index == PMU114
// OFFSET Calibration

#define VCH1_OFFSET 668891
#define VCH2_OFFSET 807740
#define VCH3_OFFSET 1036225
                    
#define ICH1_OFFSET 1036225
#define ICH2_OFFSET 1810825
#define ICH3_OFFSET 1533551
#define ICH4_OFFSET 1591377
#define ICH5_OFFSET 1532525
#define ICH6_OFFSET 1547222
#define ICH7_OFFSET 4044427
#define ICH8_OFFSET 910694
#define ICH9_OFFSET 307253
#define ICH10_OFFSET 188565
#define ICH11_OFFSET 1654717
#define ICH12_OFFSET 1758784
#define ICH13_OFFSET 1466157
#define ICH14_OFFSET 1467924
#define ICH15_OFFSET 2080938

//SCALING Calibration
#define VCH1_SCALE 586.060791f
#define VCH2_SCALE 587.168945f
#define VCH3_SCALE 587.493958f

#define ICH1_SCALE 371.266235f
#define ICH2_SCALE 372.941895f
#define ICH3_SCALE 371.937561f
#define ICH4_SCALE 372.051941f
#define ICH5_SCALE 374.160736f
#define ICH6_SCALE 373.19165f
#define ICH7_SCALE 368.176849f
#define ICH8_SCALE 373.754059f
#define ICH9_SCALE 374.04306f
#define ICH10_SCALE 372.751434f
#define ICH11_SCALE 371.606171f
#define ICH12_SCALE 373.65509f
#define ICH13_SCALE 373.60022f
#define ICH14_SCALE 372.702881f
#define ICH15_SCALE 372.32016f

#endif

#if Calibration_Index == PMU115
// OFFSET Calibration

#define VCH1_OFFSET 185241
#define VCH2_OFFSET 708658
#define VCH3_OFFSET 985856
                    
#define ICH1_OFFSET 1535728
#define ICH2_OFFSET 1404993
#define ICH3_OFFSET 1586414
#define ICH4_OFFSET 1687101
#define ICH5_OFFSET 1583605
#define ICH6_OFFSET 1850705
#define ICH7_OFFSET 3410631
#define ICH8_OFFSET 1290616
#define ICH9_OFFSET 314398
#define ICH10_OFFSET 422323
#define ICH11_OFFSET 1719364
#define ICH12_OFFSET 1531317
#define ICH13_OFFSET 1744631
#define ICH14_OFFSET 1582654
#define ICH15_OFFSET 2084161

//SCALING Calibration
#define VCH1_SCALE 584.795166
#define VCH2_SCALE 588.072021f
#define VCH3_SCALE 588.283081f

#define ICH1_SCALE 374.926727f
#define ICH2_SCALE 375.705627f
#define ICH3_SCALE 375.134155f
#define ICH4_SCALE 377.239136f
#define ICH5_SCALE 375.432556f
#define ICH6_SCALE 374.330322f
#define ICH7_SCALE 374.059448f
#define ICH8_SCALE 374.07489f
#define ICH9_SCALE 373.041046f
#define ICH10_SCALE 371.933075f
#define ICH11_SCALE 374.148712f
#define ICH12_SCALE 374.29071f
#define ICH13_SCALE 372.613007f
#define ICH14_SCALE 373.287964f
#define ICH15_SCALE 374.824097f

#endif

#if Calibration_Index == PMU116
// OFFSET Calibration

#define VCH1_OFFSET 115987
#define VCH2_OFFSET 423714
#define VCH3_OFFSET 570522
                    
#define ICH1_OFFSET 1722576
#define ICH2_OFFSET 1637890
#define ICH3_OFFSET 1803304
#define ICH4_OFFSET 1683012
#define ICH5_OFFSET 1750100
#define ICH6_OFFSET 1496975
#define ICH7_OFFSET 3923644
#define ICH8_OFFSET 1157995
#define ICH9_OFFSET 462334
#define ICH10_OFFSET 539346
#define ICH11_OFFSET 1272943
#define ICH12_OFFSET 1620111
#define ICH13_OFFSET 1780428
#define ICH14_OFFSET 1595595
#define ICH15_OFFSET 1931373

//SCALING Calibration
#define VCH1_SCALE 588.711243f
#define VCH2_SCALE 586.352661f
#define VCH3_SCALE 589.701416f

#define ICH1_SCALE 374.03537f
#define ICH2_SCALE 372.821533f
#define ICH3_SCALE 371.730164f
#define ICH4_SCALE 372.832794f
#define ICH5_SCALE 374.358368f
#define ICH6_SCALE 373.373383f
#define ICH7_SCALE 371.892456f
#define ICH8_SCALE 371.519287f
#define ICH9_SCALE 373.507813f
#define ICH10_SCALE 373.093079f
#define ICH11_SCALE 375.510773f
#define ICH12_SCALE 372.955414f
#define ICH13_SCALE 374.522552f
#define ICH14_SCALE 373.474457f
#define ICH15_SCALE 372.4758f

#endif

#if Calibration_Index == PMU117
// OFFSET Calibration

#define VCH1_OFFSET 395030
#define VCH2_OFFSET 650478
#define VCH3_OFFSET 898315
                    
#define ICH1_OFFSET 1575879
#define ICH2_OFFSET 1688978
#define ICH3_OFFSET 1542794
#define ICH4_OFFSET 1723951
#define ICH5_OFFSET 1800279
#define ICH6_OFFSET 1966639
#define ICH7_OFFSET 4030611
#define ICH8_OFFSET 1171405
#define ICH9_OFFSET 192163
#define ICH10_OFFSET 416677
#define ICH11_OFFSET 1906250
#define ICH12_OFFSET 1543333
#define ICH13_OFFSET 1649744
#define ICH14_OFFSET 1769507
#define ICH15_OFFSET 2081006

//SCALING Calibration
#define VCH1_SCALE 588.139282f
#define VCH2_SCALE 581.793457f
#define VCH3_SCALE 588.310486f

#define ICH1_SCALE 373.078217f
#define ICH2_SCALE 373.235321f
#define ICH3_SCALE 371.323486f
#define ICH4_SCALE 373.454071f
#define ICH5_SCALE 373.641083f
#define ICH6_SCALE 372.684387f
#define ICH7_SCALE 372.670502f
#define ICH8_SCALE 371.427551f
#define ICH9_SCALE 372.804626f
#define ICH10_SCALE 371.531403f
#define ICH11_SCALE 374.565979f
#define ICH12_SCALE 372.798676f
#define ICH13_SCALE 373.796021f
#define ICH14_SCALE 373.803711f
#define ICH15_SCALE 373.8255f

#endif

#if Calibration_Index == PMU118
// OFFSET Calibration

#define VCH1_OFFSET 966743
#define VCH2_OFFSET 1194219
#define VCH3_OFFSET 1400603
                    
#define ICH1_OFFSET 1745673
#define ICH2_OFFSET 1836372
#define ICH3_OFFSET 1818713
#define ICH4_OFFSET 1620522
#define ICH5_OFFSET 1913169
#define ICH6_OFFSET 1979191
#define ICH7_OFFSET 3702048
#define ICH8_OFFSET 1643255
#define ICH9_OFFSET 237053
#define ICH10_OFFSET 451020
#define ICH11_OFFSET 1820428
#define ICH12_OFFSET 1457286
#define ICH13_OFFSET 1424140
#define ICH14_OFFSET 1608006
#define ICH15_OFFSET 1973446

//SCALING Calibration
#define VCH1_SCALE 587.721802f
#define VCH2_SCALE 585.637573f
#define VCH3_SCALE 587.044495f

#define ICH1_SCALE 372.971924f
#define ICH2_SCALE 371.462219f
#define ICH3_SCALE 372.632904f
#define ICH4_SCALE 371.509949f
#define ICH5_SCALE 372.674469f
#define ICH6_SCALE 372.855804f
#define ICH7_SCALE 369.670197f
#define ICH8_SCALE 371.163849f
#define ICH9_SCALE 374.043793f
#define ICH10_SCALE 370.315155f
#define ICH11_SCALE 374.759338f
#define ICH12_SCALE 373.625824f
#define ICH13_SCALE 373.476807f
#define ICH14_SCALE 373.517731f
#define ICH15_SCALE 374.705566f

#endif

#if Calibration_Index == PMU119
// OFFSET Calibration

#define VCH1_OFFSET 419453
#define VCH2_OFFSET 664157
#define VCH3_OFFSET 490197
                    
#define ICH1_OFFSET 1240897
#define ICH2_OFFSET 1321304
#define ICH3_OFFSET 1509587
#define ICH4_OFFSET 1305848
#define ICH5_OFFSET 1485770
#define ICH6_OFFSET 1468430
#define ICH7_OFFSET 3794629
#define ICH8_OFFSET 952739
#define ICH9_OFFSET 383563
#define ICH10_OFFSET 353225
#define ICH11_OFFSET 1546086
#define ICH12_OFFSET 1400868
#define ICH13_OFFSET 1378596
#define ICH14_OFFSET 1638614
#define ICH15_OFFSET 2045283

//SCALING Calibration
#define VCH1_SCALE 587.923401f
#define VCH2_SCALE 587.672791f
#define VCH3_SCALE 584.348022f

#define ICH1_SCALE 373.562164f
#define ICH2_SCALE 372.030365f
#define ICH3_SCALE 374.230591f
#define ICH4_SCALE 372.660431f
#define ICH5_SCALE 373.141174f
#define ICH6_SCALE 373.338348f
#define ICH7_SCALE 370.618378f
#define ICH8_SCALE 373.278961f
#define ICH9_SCALE 371.44516f
#define ICH10_SCALE 373.65094f
#define ICH11_SCALE 371.331451f
#define ICH12_SCALE 372.862549f
#define ICH13_SCALE 373.268677f
#define ICH14_SCALE 371.883606f
#define ICH15_SCALE 371.799286f

#endif

#if Calibration_Index == PMU120
// OFFSET Calibration

#define VCH1_OFFSET 797293
#define VCH2_OFFSET 1160073
#define VCH3_OFFSET 1456958
                    
#define ICH1_OFFSET 1686878
#define ICH2_OFFSET 1311638
#define ICH3_OFFSET 1441158
#define ICH4_OFFSET 1473728
#define ICH5_OFFSET 1530902
#define ICH6_OFFSET 1422237
#define ICH7_OFFSET 4187594
#define ICH8_OFFSET 708245
#define ICH9_OFFSET 256765
#define ICH10_OFFSET 359117
#define ICH11_OFFSET 1783509
#define ICH12_OFFSET 1512892
#define ICH13_OFFSET 1398233
#define ICH14_OFFSET 1516600
#define ICH15_OFFSET 1783509

//SCALING Calibration
#define VCH1_SCALE 585.243408f
#define VCH2_SCALE 582.473267f
#define VCH3_SCALE 586.860107f

#define ICH1_SCALE 374.722626f
#define ICH2_SCALE 375.404968f
#define ICH3_SCALE 374.177582f
#define ICH4_SCALE 373.250366f
#define ICH5_SCALE 374.563751f
#define ICH6_SCALE 374.855011f
#define ICH7_SCALE 369.368317f
#define ICH8_SCALE 371.66745f
#define ICH9_SCALE 372.634125f
#define ICH10_SCALE 372.158783f
#define ICH11_SCALE 373.095184f
#define ICH12_SCALE 374.435272f
#define ICH13_SCALE 372.657928f
#define ICH14_SCALE 373.992401f
#define ICH15_SCALE 371.817383f

#endif

#if Calibration_Index == PMU121
// OFFSET Calibration

#define VCH1_OFFSET 52351
#define VCH2_OFFSET 394756
#define VCH3_OFFSET 826195
                    
#define ICH1_OFFSET 1787575
#define ICH2_OFFSET 1484819
#define ICH3_OFFSET 1655895
#define ICH4_OFFSET 1305208
#define ICH5_OFFSET 1648675
#define ICH6_OFFSET 1385139
#define ICH7_OFFSET 3448879
#define ICH8_OFFSET 743960
#define ICH9_OFFSET 149860
#define ICH10_OFFSET 589342
#define ICH11_OFFSET 1462147
#define ICH12_OFFSET 1409398
#define ICH13_OFFSET 1165173
#define ICH14_OFFSET 1428847
#define ICH15_OFFSET 1644674

//SCALING Calibration
#define VCH1_SCALE 595.630859f
#define VCH2_SCALE 594.630859f
#define VCH3_SCALE 595.130859f

#define ICH1_SCALE 372.442383f
#define ICH2_SCALE 374.960236f
#define ICH3_SCALE 374.286377f
#define ICH4_SCALE 374.584991f
#define ICH5_SCALE 372.25827f
#define ICH6_SCALE 374.085236f
#define ICH7_SCALE 370.235565f
#define ICH8_SCALE 373.009216f
#define ICH9_SCALE 372.86438f
#define ICH10_SCALE 371.269073f
#define ICH11_SCALE 373.036102f
#define ICH12_SCALE 373.643402f
#define ICH13_SCALE 373.721161f
#define ICH14_SCALE 373.721161f
#define ICH15_SCALE 373.790863f

#endif

#if Calibration_Index == PMU122
// OFFSET Calibration

#define VCH1_OFFSET 660131
#define VCH2_OFFSET 1168161
#define VCH3_OFFSET 1468007
                    
#define ICH1_OFFSET 1525738
#define ICH2_OFFSET 1633813
#define ICH3_OFFSET 1460103
#define ICH4_OFFSET 1380322
#define ICH5_OFFSET 1542477
#define ICH6_OFFSET 1424751
#define ICH7_OFFSET 4083867
#define ICH8_OFFSET 1046071
#define ICH9_OFFSET 69586
#define ICH10_OFFSET 246926
#define ICH11_OFFSET 1820756
#define ICH12_OFFSET 1986911
#define ICH13_OFFSET 1540427
#define ICH14_OFFSET 1757385
#define ICH15_OFFSET 2053411

//SCALING Calibration
#define VCH1_SCALE 587.568359f
#define VCH2_SCALE 587.073181f
#define VCH3_SCALE 587.858032f

#define ICH1_SCALE 374.784241f
#define ICH2_SCALE 373.601532f
#define ICH3_SCALE 373.159882f
#define ICH4_SCALE 371.795258f
#define ICH5_SCALE 374.101868f
#define ICH6_SCALE 373.984344f
#define ICH7_SCALE 371.727112f
#define ICH8_SCALE 372.98526f
#define ICH9_SCALE 375.146667f
#define ICH10_SCALE 373.933868f
#define ICH11_SCALE 374.928467f
#define ICH12_SCALE 373.350586f
#define ICH13_SCALE 374.669495f
#define ICH14_SCALE 372.125397f
#define ICH15_SCALE 372.183105f

#endif

#if Calibration_Index == PMU123
// OFFSET Calibration

#define VCH1_OFFSET 684882
#define VCH2_OFFSET 451395
#define VCH3_OFFSET 1052286
                    
#define ICH1_OFFSET 1242965
#define ICH2_OFFSET 1335493
#define ICH3_OFFSET 1058635
#define ICH4_OFFSET 1090146
#define ICH5_OFFSET 1135247
#define ICH6_OFFSET 971844
#define ICH7_OFFSET 3325073
#define ICH8_OFFSET 373822
#define ICH9_OFFSET 123777
#define ICH10_OFFSET 517950
#define ICH11_OFFSET 1424047
#define ICH12_OFFSET 1346989
#define ICH13_OFFSET 1398611
#define ICH14_OFFSET 1436902
#define ICH15_OFFSET 1498579

//SCALING Calibration
#define VCH1_SCALE 586.148254f
#define VCH2_SCALE 587.002197f
#define VCH3_SCALE 586.252747f

#define ICH1_SCALE 374.899475f
#define ICH2_SCALE 374.070892f
#define ICH3_SCALE 374.052032f
#define ICH4_SCALE 373.0289f
#define ICH5_SCALE 373.975067f
#define ICH6_SCALE 375.106628f
#define ICH7_SCALE 371.064545f
#define ICH8_SCALE 371.81604f
#define ICH9_SCALE 373.167633f
#define ICH10_SCALE 370.818481f
#define ICH11_SCALE 375.081818f
#define ICH12_SCALE 373.323456f
#define ICH13_SCALE 372.94693f
#define ICH14_SCALE 372.848389f
#define ICH15_SCALE 374.167969f

#endif

#if Calibration_Index == PMU124
// OFFSET Calibration

#define VCH1_OFFSET 783974
#define VCH2_OFFSET 835753
#define VCH3_OFFSET 1199065
                    
#define ICH1_OFFSET 1795138
#define ICH2_OFFSET 1674154
#define ICH3_OFFSET 1480479
#define ICH4_OFFSET 1604383
#define ICH5_OFFSET 1330130
#define ICH6_OFFSET 1622746
#define ICH7_OFFSET 3887087
#define ICH8_OFFSET 1013380
#define ICH9_OFFSET 157533
#define ICH10_OFFSET 439331
#define ICH11_OFFSET 1924459
#define ICH12_OFFSET 1549131
#define ICH13_OFFSET 1608265
#define ICH14_OFFSET 1723561
#define ICH15_OFFSET 1699665

//SCALING Calibration
#define VCH1_SCALE 589.386963f
#define VCH2_SCALE 584.407898f
#define VCH3_SCALE 588.27948f

#define ICH1_SCALE 373.717926f
#define ICH2_SCALE 374.57193f
#define ICH3_SCALE 371.741089f
#define ICH4_SCALE 373.288483f
#define ICH5_SCALE 373.219818f
#define ICH6_SCALE 372.403076f
#define ICH7_SCALE 372.202179f
#define ICH8_SCALE 371.364075f
#define ICH9_SCALE 373.247925f
#define ICH10_SCALE 373.306183f
#define ICH11_SCALE 373.423004f
#define ICH12_SCALE 373.966156f
#define ICH13_SCALE 374.038361f
#define ICH14_SCALE 375.12851f
#define ICH15_SCALE 372.604431f

#endif

#if Calibration_Index == PMU125
// OFFSET Calibration

#define VCH1_OFFSET 142633
#define VCH2_OFFSET 326062
#define VCH3_OFFSET 523381
                    
#define ICH1_OFFSET 1438883
#define ICH2_OFFSET 1163943
#define ICH3_OFFSET 1332302
#define ICH4_OFFSET 1262169
#define ICH5_OFFSET 1256776
#define ICH6_OFFSET 1380144
#define ICH7_OFFSET 3480762
#define ICH8_OFFSET 589138
#define ICH9_OFFSET 174176
#define ICH10_OFFSET 59713
#define ICH11_OFFSET 1676814
#define ICH12_OFFSET 2163015
#define ICH13_OFFSET 1583995
#define ICH14_OFFSET 1714903
#define ICH15_OFFSET 2098920

//SCALING Calibration
#define VCH1_SCALE 589.550964f
#define VCH2_SCALE 588.416443f
#define VCH3_SCALE 585.926208f

#define ICH1_SCALE 374.678741f
#define ICH2_SCALE 374.580109f
#define ICH3_SCALE 374.09903f
#define ICH4_SCALE 373.448364f
#define ICH5_SCALE 374.801697f
#define ICH6_SCALE 373.286438f
#define ICH7_SCALE 372.407349f
#define ICH8_SCALE 375.069702f
#define ICH9_SCALE 373.347198f
#define ICH10_SCALE 372.468414f
#define ICH11_SCALE 371.593506f
#define ICH12_SCALE 373.414673f
#define ICH13_SCALE 372.336212f
#define ICH14_SCALE 370.876648f
#define ICH15_SCALE 372.368439f

#endif

#if Calibration_Index == PMU126
// OFFSET Calibration

#define VCH1_OFFSET 866758
#define VCH2_OFFSET 1252928
#define VCH3_OFFSET 1456335
                    
#define ICH1_OFFSET 1696801
#define ICH2_OFFSET 1626176
#define ICH3_OFFSET 1634918
#define ICH4_OFFSET 1731452
#define ICH5_OFFSET 1656667
#define ICH6_OFFSET 1664838
#define ICH7_OFFSET 3638268
#define ICH8_OFFSET 1304348
#define ICH9_OFFSET 266046
#define ICH10_OFFSET 35852
#define ICH11_OFFSET 1463307
#define ICH12_OFFSET 1757224
#define ICH13_OFFSET 1516017
#define ICH14_OFFSET 1941859
#define ICH15_OFFSET 2075893

//SCALING Calibration
#define VCH1_SCALE 585.538818f
#define VCH2_SCALE 587.664917f
#define VCH3_SCALE 592.2995f

#define ICH1_SCALE 375.92218f
#define ICH2_SCALE 376.339447f
#define ICH3_SCALE 373.824646f
#define ICH4_SCALE 375.41452f
#define ICH5_SCALE 376.53241f
#define ICH6_SCALE 375.493286f
#define ICH7_SCALE 373.535675f
#define ICH8_SCALE 374.150452f
#define ICH9_SCALE 372.036499f
#define ICH10_SCALE 373.190552f
#define ICH11_SCALE 372.754883f
#define ICH12_SCALE 373.440826f
#define ICH13_SCALE 373.566223f
#define ICH14_SCALE 374.614136f
#define ICH15_SCALE 372.461365f

#endif

#if Calibration_Index == PMU127
// OFFSET Calibration

#define VCH1_OFFSET 317419
#define VCH2_OFFSET 384476
#define VCH3_OFFSET 428892
                    
#define ICH1_OFFSET 1587356
#define ICH2_OFFSET 956213
#define ICH3_OFFSET 1176500
#define ICH4_OFFSET 1374233
#define ICH5_OFFSET 1385443
#define ICH6_OFFSET 1238691
#define ICH7_OFFSET 3708271
#define ICH8_OFFSET 1021281
#define ICH9_OFFSET 532406
#define ICH10_OFFSET 562981
#define ICH11_OFFSET 1371369
#define ICH12_OFFSET 1518863
#define ICH13_OFFSET 1305950
#define ICH14_OFFSET 1364433
#define ICH15_OFFSET 1596386

//SCALING Calibration
#define VCH1_SCALE 585.359619f
#define VCH2_SCALE 587.861755f
#define VCH3_SCALE 585.41925f

#define ICH1_SCALE 375.279541f
#define ICH2_SCALE 373.739044f
#define ICH3_SCALE 374.176056f
#define ICH4_SCALE 372.289581f
#define ICH5_SCALE 374.940033f
#define ICH6_SCALE 375.051788f
#define ICH7_SCALE 370.849304f
#define ICH8_SCALE 372.843384f
#define ICH9_SCALE 373.295074f
#define ICH10_SCALE 370.983826f
#define ICH11_SCALE 371.836609f
#define ICH12_SCALE 372.771332f
#define ICH13_SCALE 372.353882f
#define ICH14_SCALE 374.206573f
#define ICH15_SCALE 371.856262f

#endif

#if Calibration_Index == PMU128
// OFFSET Calibration

#define VCH1_OFFSET 804294
#define VCH2_OFFSET 1149101
#define VCH3_OFFSET 1126248
                    
#define ICH1_OFFSET 1365419
#define ICH2_OFFSET 1663991
#define ICH3_OFFSET 1430083
#define ICH4_OFFSET 1542339
#define ICH5_OFFSET 1379173
#define ICH6_OFFSET 1796356
#define ICH7_OFFSET 3131141
#define ICH8_OFFSET 1273244
#define ICH9_OFFSET 29734
#define ICH10_OFFSET 335687
#define ICH11_OFFSET 1526593
#define ICH12_OFFSET 1659520
#define ICH13_OFFSET 1615414
#define ICH14_OFFSET 1644885
#define ICH15_OFFSET 2112064

//SCALING Calibration
#define VCH1_SCALE 587.910889f
#define VCH2_SCALE 586.893799f
#define VCH3_SCALE 587.90802f

#define ICH1_SCALE 374.543793f
#define ICH2_SCALE 373.84671f
#define ICH3_SCALE 373.805084f
#define ICH4_SCALE 371.647583f
#define ICH5_SCALE 374.045837f
#define ICH6_SCALE 374.479401f
#define ICH7_SCALE 371.683594f
#define ICH8_SCALE 372.709381f
#define ICH9_SCALE 372.000275f
#define ICH10_SCALE 374.000854f
#define ICH11_SCALE 372.255585f
#define ICH12_SCALE 372.310913f
#define ICH13_SCALE 374.13266f
#define ICH14_SCALE 372.617065f
#define ICH15_SCALE 372.217377f

#endif

#if Calibration_Index == PMU129
// OFFSET Calibration

#define VCH1_OFFSET 581757
#define VCH2_OFFSET 92767
#define VCH3_OFFSET 309374
                    
#define ICH1_OFFSET 1314814
#define ICH2_OFFSET 933966
#define ICH3_OFFSET 1114176
#define ICH4_OFFSET 1302987
#define ICH5_OFFSET 1377931
#define ICH6_OFFSET 1142265
#define ICH7_OFFSET 3525437
#define ICH8_OFFSET 682581
#define ICH9_OFFSET 258446
#define ICH10_OFFSET 358330
#define ICH11_OFFSET 1632216
#define ICH12_OFFSET 1752447
#define ICH13_OFFSET 1759137
#define ICH14_OFFSET 1786975
#define ICH15_OFFSET 2055863

//SCALING Calibration
#define VCH1_SCALE 583.234863f
#define VCH2_SCALE 585.922913f
#define VCH3_SCALE 585.671509f

#define ICH1_SCALE 375.397552f
#define ICH2_SCALE 375.699554f
#define ICH3_SCALE 373.674072f
#define ICH4_SCALE 373.692474f
#define ICH5_SCALE 375.923706f
#define ICH6_SCALE 373.41037f
#define ICH7_SCALE 372.895569f
#define ICH8_SCALE 373.773621f
#define ICH9_SCALE 372.75296f
#define ICH10_SCALE 371.419189f
#define ICH11_SCALE 371.531311f
#define ICH12_SCALE 371.947479f
#define ICH13_SCALE 372.713409f
#define ICH14_SCALE 374.150604f
#define ICH15_SCALE 370.616974f

#endif


#if Calibration_Index == PMU130
// OFFSET Calibration

#define VCH1_OFFSET 540824
#define VCH2_OFFSET 498456
#define VCH3_OFFSET 799450
                    
#define ICH1_OFFSET 1512387
#define ICH2_OFFSET 1656704
#define ICH3_OFFSET 1507382
#define ICH4_OFFSET 1687573
#define ICH5_OFFSET 1301772
#define ICH6_OFFSET 1673080
#define ICH7_OFFSET 4250884
#define ICH8_OFFSET 912319
#define ICH9_OFFSET 298798
#define ICH10_OFFSET 357538
#define ICH11_OFFSET 1554575
#define ICH12_OFFSET 1561225
#define ICH13_OFFSET 1632566
#define ICH14_OFFSET 1257770
#define ICH15_OFFSET 1497739

//SCALING Calibration
#define VCH1_SCALE 584.315369f
#define VCH2_SCALE 582.413147f
#define VCH3_SCALE 582.556641f

#define ICH1_SCALE 373.138275f
#define ICH2_SCALE 373.235199f
#define ICH3_SCALE 374.697021f
#define ICH4_SCALE 373.207886f
#define ICH5_SCALE 374.878418f
#define ICH6_SCALE 373.28891f
#define ICH7_SCALE 371.842865f
#define ICH8_SCALE 372.25589f
#define ICH9_SCALE 374.16922f
#define ICH10_SCALE 372.286591f
#define ICH11_SCALE 372.45816f
#define ICH12_SCALE 372.62146f
#define ICH13_SCALE 372.625366f
#define ICH14_SCALE 372.976196f
#define ICH15_SCALE 372.196594f

#endif

#if Calibration_Index == PMU131
// OFFSET Calibration

#define VCH1_OFFSET 1029297
#define VCH2_OFFSET 969820
#define VCH3_OFFSET 1249036
                    
#define ICH1_OFFSET 1802793
#define ICH2_OFFSET 1746517
#define ICH3_OFFSET 1683344
#define ICH4_OFFSET 1632827
#define ICH5_OFFSET 1441430
#define ICH6_OFFSET 1581419
#define ICH7_OFFSET 4162124
#define ICH8_OFFSET 1314390
#define ICH9_OFFSET 254510
#define ICH10_OFFSET 63492
#define ICH11_OFFSET 1792758
#define ICH12_OFFSET 1476887
#define ICH13_OFFSET 1683336
#define ICH14_OFFSET 1310642
#define ICH15_OFFSET 1794115

//SCALING Calibration
#define VCH1_SCALE 589.652771f
#define VCH2_SCALE 585.858459f
#define VCH3_SCALE 585.602295f

#define ICH1_SCALE 373.184326f
#define ICH2_SCALE 372.325775f
#define ICH3_SCALE 373.362579f
#define ICH4_SCALE 372.808197f
#define ICH5_SCALE 374.269928f
#define ICH6_SCALE 372.627411f
#define ICH7_SCALE 372.178833f
#define ICH8_SCALE 371.513458f
#define ICH9_SCALE 373.663086f
#define ICH10_SCALE 372.661346f
#define ICH11_SCALE 372.860077f
#define ICH12_SCALE 373.637543f
#define ICH13_SCALE 371.521942f
#define ICH14_SCALE 373.802673f
#define ICH15_SCALE 373.029572f

#endif

#if Calibration_Index == PMU132
// OFFSET Calibration

#define VCH1_OFFSET 1216704
#define VCH2_OFFSET 1231536
#define VCH3_OFFSET 1536823
                    
#define ICH1_OFFSET 1495237
#define ICH2_OFFSET 1595946
#define ICH3_OFFSET 1820491
#define ICH4_OFFSET 1533613
#define ICH5_OFFSET 1548092
#define ICH6_OFFSET 1685003
#define ICH7_OFFSET 4041759
#define ICH8_OFFSET 945563
#define ICH9_OFFSET 102124
#define ICH10_OFFSET 121696
#define ICH11_OFFSET 1715697
#define ICH12_OFFSET 1997858
#define ICH13_OFFSET 1954614
#define ICH14_OFFSET 1684705
#define ICH15_OFFSET 2166384

//SCALING Calibration
#define VCH1_SCALE 584.302185f
#define VCH2_SCALE 586.306152f
#define VCH3_SCALE 589.66748f

#define ICH1_SCALE 372.760284f
#define ICH2_SCALE 375.126617f
#define ICH3_SCALE 372.35379f
#define ICH4_SCALE 374.551361f
#define ICH5_SCALE 373.452972f
#define ICH6_SCALE 374.597504f
#define ICH7_SCALE 371.361542f
#define ICH8_SCALE 372.050751f
#define ICH9_SCALE 371.325897f
#define ICH10_SCALE 372.720032f
#define ICH11_SCALE 371.87677f
#define ICH12_SCALE 372.202911f
#define ICH13_SCALE 371.979401f
#define ICH14_SCALE 374.622131f
#define ICH15_SCALE 372.186249f

#endif

#if Calibration_Index == PMU133
// OFFSET Calibration

#define VCH1_OFFSET 95590
#define VCH2_OFFSET 490729
#define VCH3_OFFSET 100728
                    
#define ICH1_OFFSET 1604753
#define ICH2_OFFSET 1482837
#define ICH3_OFFSET 1371831
#define ICH4_OFFSET 1426485
#define ICH5_OFFSET 1488846
#define ICH6_OFFSET 1496912
#define ICH7_OFFSET 3728436
#define ICH8_OFFSET 1021362
#define ICH9_OFFSET 154439
#define ICH10_OFFSET 477603
#define ICH11_OFFSET 1652524
#define ICH12_OFFSET 1603936
#define ICH13_OFFSET 1529828
#define ICH14_OFFSET 1495301
#define ICH15_OFFSET 1875964

//SCALING Calibration
#define VCH1_SCALE 588.039246f
#define VCH2_SCALE 586.183472f
#define VCH3_SCALE 583.620972f

#define ICH1_SCALE 371.893524f
#define ICH2_SCALE 373.249115f
#define ICH3_SCALE 373.064575f
#define ICH4_SCALE 373.655518f
#define ICH5_SCALE 373.058868f
#define ICH6_SCALE 373.00528f
#define ICH7_SCALE 372.572357f
#define ICH8_SCALE 372.58548f
#define ICH9_SCALE 373.99527f
#define ICH10_SCALE 371.881531f
#define ICH11_SCALE 374.321533f
#define ICH12_SCALE 374.416199f
#define ICH13_SCALE 372.057343f
#define ICH14_SCALE 374.728638f
#define ICH15_SCALE 373.853119f

#endif

#if Calibration_Index == PMU134
// OFFSET Calibration

#define VCH1_OFFSET 1179584
#define VCH2_OFFSET 1268081
#define VCH3_OFFSET 1396991
                    
#define ICH1_OFFSET 1587983
#define ICH2_OFFSET 1664900
#define ICH3_OFFSET 1616206
#define ICH4_OFFSET 1557875
#define ICH5_OFFSET 1669931
#define ICH6_OFFSET 1599686
#define ICH7_OFFSET 3768991
#define ICH8_OFFSET 1216704
#define ICH9_OFFSET 199928
#define ICH10_OFFSET 203986
#define ICH11_OFFSET 1406851
#define ICH12_OFFSET 1592475
#define ICH13_OFFSET 1763882
#define ICH14_OFFSET 1729231
#define ICH15_OFFSET 2132443

//SCALING Calibration
#define VCH1_SCALE 589.898804f
#define VCH2_SCALE 584.206055f
#define VCH3_SCALE 588.939636f

#define ICH1_SCALE 373.620972f
#define ICH2_SCALE 372.828949f
#define ICH3_SCALE 372.727936f
#define ICH4_SCALE 373.147552f
#define ICH5_SCALE 372.605316f
#define ICH6_SCALE 373.270233f
#define ICH7_SCALE 372.298584f
#define ICH8_SCALE 372.527679f
#define ICH9_SCALE 373.945129f
#define ICH10_SCALE 372.518066f
#define ICH11_SCALE 371.762756f
#define ICH12_SCALE 372.323822f
#define ICH13_SCALE 373.195313f
#define ICH14_SCALE 373.479614f
#define ICH15_SCALE 371.568268f

#endif

#if Calibration_Index == PMU135
// OFFSET Calibration

#define VCH1_OFFSET 385913
#define VCH2_OFFSET 821458
#define VCH3_OFFSET 1069100
                    
#define ICH1_OFFSET 1499269
#define ICH2_OFFSET 1350193
#define ICH3_OFFSET 1310048
#define ICH4_OFFSET 1454680
#define ICH5_OFFSET 1637366
#define ICH6_OFFSET 1862423
#define ICH7_OFFSET 4021974
#define ICH8_OFFSET 877871
#define ICH9_OFFSET 363981
#define ICH10_OFFSET 586914
#define ICH11_OFFSET 1645720
#define ICH12_OFFSET 1909478
#define ICH13_OFFSET 1278853
#define ICH14_OFFSET 1480555
#define ICH15_OFFSET 1635480

//SCALING Calibration
#define VCH1_SCALE 583.971375f
#define VCH2_SCALE 585.431335f
#define VCH3_SCALE 587.294373f

#define ICH1_SCALE 372.558105f
#define ICH2_SCALE 374.37677f
#define ICH3_SCALE 373.004608f
#define ICH4_SCALE 374.662231f
#define ICH5_SCALE 373.646637f
#define ICH6_SCALE 373.06723f
#define ICH7_SCALE 370.3013f
#define ICH8_SCALE 371.738525f
#define ICH9_SCALE 374.587402f
#define ICH10_SCALE 371.231964f
#define ICH11_SCALE 372.049469f
#define ICH12_SCALE 373.103333f
#define ICH13_SCALE 372.885284f
#define ICH14_SCALE 375.763611f
#define ICH15_SCALE 373.332092f

#endif

#if Calibration_Index == PMU136
// OFFSET Calibration

#define VCH1_OFFSET 400417
#define VCH2_OFFSET 1065194
#define VCH3_OFFSET 891824
                    
#define ICH1_OFFSET 1611034
#define ICH2_OFFSET 1298248
#define ICH3_OFFSET 1194063
#define ICH4_OFFSET 1605704
#define ICH5_OFFSET 1383464
#define ICH6_OFFSET 1255397
#define ICH7_OFFSET 3743289
#define ICH8_OFFSET 706695
#define ICH9_OFFSET 47849
#define ICH10_OFFSET  652218
#define ICH11_OFFSET  1736980
#define ICH12_OFFSET  1713411
#define ICH13_OFFSET  1047236
#define ICH14_OFFSET  1533354
#define ICH15_OFFSET  1719398

//SCALING Calibration
#define VCH1_SCALE 588.932739f
#define VCH2_SCALE 583.356995f
#define VCH3_SCALE 587.710938f

#define ICH1_SCALE 373.484253f
#define ICH2_SCALE 373.296478f
#define ICH3_SCALE 372.587341f
#define ICH4_SCALE 374.506012f
#define ICH5_SCALE 375.916443f
#define ICH6_SCALE 372.459137f
#define ICH7_SCALE 374.345306f
#define ICH8_SCALE 371.937134f
#define ICH9_SCALE 372.237183f
#define ICH10_SCALE 367.88504f
#define ICH11_SCALE 373.675171f
#define ICH12_SCALE 372.796783f
#define ICH13_SCALE 373.075897f
#define ICH14_SCALE 372.190308f
#define ICH15_SCALE 373.956757f

#endif

#if Calibration_Index == PMU137
// OFFSET Calibration

#define VCH1_OFFSET 532136
#define VCH2_OFFSET 513353
#define VCH3_OFFSET 751751
                    
#define ICH1_OFFSET 1594361
#define ICH2_OFFSET 1431703
#define ICH3_OFFSET 1306063
#define ICH4_OFFSET 1580331
#define ICH5_OFFSET 1544477
#define ICH6_OFFSET 1410545
#define ICH7_OFFSET 4429929
#define ICH8_OFFSET 831603
#define ICH9_OFFSET 302333
#define ICH10_OFFSET 234287
#define ICH11_OFFSET 1811895
#define ICH12_OFFSET 1530334
#define ICH13_OFFSET 1564455
#define ICH14_OFFSET 1378156
#define ICH15_OFFSET 2105735

//SCALING Calibration
#define VCH1_SCALE 581.461914f
#define VCH2_SCALE 580.825867f
#define VCH3_SCALE 583.991394f

#define ICH1_SCALE 374.182343f
#define ICH2_SCALE 375.071045f
#define ICH3_SCALE 373.745575f
#define ICH4_SCALE 375.195648f
#define ICH5_SCALE 373.776794f
#define ICH6_SCALE 373.644653f
#define ICH7_SCALE 370.040344f
#define ICH8_SCALE 373.724335f
#define ICH9_SCALE 373.768646f
#define ICH10_SCALE 373.828217f
#define ICH11_SCALE 371.904785f
#define ICH12_SCALE 372.970459f
#define ICH13_SCALE 374.23172f
#define ICH14_SCALE 372.511871f
#define ICH15_SCALE 373.197815f

#endif

#if Calibration_Index == PMU138
// OFFSET Calibration

#define VCH1_OFFSET 655450
#define VCH2_OFFSET 769879
#define VCH3_OFFSET 962425
                    
#define ICH1_OFFSET 1874837
#define ICH2_OFFSET 1777116
#define ICH3_OFFSET 1425404
#define ICH4_OFFSET 1877479
#define ICH5_OFFSET 1586214
#define ICH6_OFFSET 1756740
#define ICH7_OFFSET 3929928
#define ICH8_OFFSET 1254226
#define ICH9_OFFSET 49951
#define ICH10_OFFSET 348822
#define ICH11_OFFSET 1693763
#define ICH12_OFFSET 1613610
#define ICH13_OFFSET 1701162
#define ICH14_OFFSET 1712452
#define ICH15_OFFSET 2037141

//SCALING Calibration
#define VCH1_SCALE 583.316345f
#define VCH2_SCALE 586.299255f
#define VCH3_SCALE 585.903992f

#define ICH1_SCALE 373.391052f
#define ICH2_SCALE 375.573975f
#define ICH3_SCALE 373.180969f
#define ICH4_SCALE 375.856079f
#define ICH5_SCALE 372.908325f
#define ICH6_SCALE 372.908325f
#define ICH7_SCALE 372.908325f
#define ICH8_SCALE 374.029572f
#define ICH9_SCALE 371.243378f
#define ICH10_SCALE 372.677521f
#define ICH11_SCALE 372.664093f
#define ICH12_SCALE 373.088898f
#define ICH13_SCALE 374.105469f
#define ICH14_SCALE 372.704742f
#define ICH15_SCALE 372.704742f

#endif

#if Calibration_Index == PMU139
// OFFSET Calibration

#define VCH1_OFFSET 612189
#define VCH2_OFFSET 782354
#define VCH3_OFFSET 733726
                    
#define ICH1_OFFSET 1127959
#define ICH2_OFFSET 1274505
#define ICH3_OFFSET 965527
#define ICH4_OFFSET 973807
#define ICH5_OFFSET 969474
#define ICH6_OFFSET 496109
#define ICH7_OFFSET 2925194
#define ICH8_OFFSET 295007
#define ICH9_OFFSET 1421036
#define ICH10_OFFSET 1793112
#define ICH11_OFFSET 1442275
#define ICH12_OFFSET 1793112
#define ICH13_OFFSET 1442275
#define ICH14_OFFSET 1603289
#define ICH15_OFFSET 1990126

//SCALING Calibration
#define VCH1_SCALE 588.123657f
#define VCH2_SCALE 585.505981f
#define VCH3_SCALE 585.464172f

#define ICH1_SCALE 374.0401f
#define ICH2_SCALE 372.632019f
#define ICH3_SCALE 372.326019f
#define ICH4_SCALE 373.088684f
#define ICH5_SCALE 373.200592f
#define ICH6_SCALE 371.631134f
#define ICH7_SCALE 372.875732f
#define ICH8_SCALE 372.099792f
#define ICH9_SCALE 366.104401f
#define ICH10_SCALE 360.430023f
#define ICH11_SCALE 375.653778f
#define ICH12_SCALE 372.950836f
#define ICH13_SCALE 374.426239f
#define ICH14_SCALE 373.498566f
#define ICH15_SCALE 371.405457f

#endif

#if Calibration_Index == PMU140
// OFFSET Calibration

#define VCH1_OFFSET 352841
#define VCH2_OFFSET 39634
#define VCH3_OFFSET 170361
                    
#define ICH1_OFFSET 1101988
#define ICH2_OFFSET 1150918
#define ICH3_OFFSET 989970
#define ICH4_OFFSET 1014716
#define ICH5_OFFSET 1145966
#define ICH6_OFFSET 1018361
#define ICH7_OFFSET 3358395
#define ICH8_OFFSET 630859
#define ICH9_OFFSET 238972
#define ICH10_OFFSET 413397
#define ICH11_OFFSET 1699140
#define ICH12_OFFSET 1790058
#define ICH13_OFFSET 1599576
#define ICH14_OFFSET 1789308
#define ICH15_OFFSET 2010161

//SCALING Calibration
#define VCH1_SCALE 585.577454f
#define VCH2_SCALE 581.353638f
#define VCH3_SCALE 587.129028f

#define ICH1_SCALE 372.782562f
#define ICH2_SCALE 372.154388f
#define ICH3_SCALE 373.05307f
#define ICH4_SCALE 373.615417f
#define ICH5_SCALE 374.924011f
#define ICH6_SCALE 371.971375f
#define ICH7_SCALE 371.758698f
#define ICH8_SCALE 373.979889f
#define ICH9_SCALE 372.719208f
#define ICH10_SCALE 374.225433f
#define ICH11_SCALE 372.63205f
#define ICH12_SCALE 373.428619f
#define ICH13_SCALE 375.046143f
#define ICH14_SCALE 373.912048f
#define ICH15_SCALE 374.674591f

#endif

#if Calibration_Index == PMU141
// OFFSET Calibration

#define VCH1_OFFSET 157502
#define VCH2_OFFSET 284194
#define VCH3_OFFSET 590660
                    
#define ICH1_OFFSET 1930541
#define ICH2_OFFSET 1770869
#define ICH3_OFFSET 1789110
#define ICH4_OFFSET 2044309
#define ICH5_OFFSET 1661573
#define ICH6_OFFSET 1803826
#define ICH7_OFFSET 3866740
#define ICH8_OFFSET 1128037
#define ICH9_OFFSET 191014
#define ICH10_OFFSET 147675
#define ICH11_OFFSET 1688418
#define ICH12_OFFSET 1762154
#define ICH13_OFFSET 1829636
#define ICH14_OFFSET 1859258
#define ICH15_OFFSET 2060874

//SCALING Calibration
#define VCH1_SCALE 588.745605f
#define VCH2_SCALE 588.746704f
#define VCH3_SCALE 587.98822f

#define ICH1_SCALE 372.019104f
#define ICH2_SCALE 373.25354f
#define ICH3_SCALE 372.728363f
#define ICH4_SCALE 373.622467f
#define ICH5_SCALE 372.188324f
#define ICH6_SCALE 371.675232f
#define ICH7_SCALE 368.688904f
#define ICH8_SCALE 373.09552f
#define ICH9_SCALE 373.309448f
#define ICH10_SCALE 374.223907f
#define ICH11_SCALE 372.904266f
#define ICH12_SCALE 373.674652f
#define ICH13_SCALE 374.808899f
#define ICH14_SCALE 373.514648f
#define ICH15_SCALE 372.099548f

#endif

#if Calibration_Index == PMU142
// OFFSET Calibration

#define VCH1_OFFSET 528507
#define VCH2_OFFSET 521839
#define VCH3_OFFSET 776956
                    
#define ICH1_OFFSET 1429226
#define ICH2_OFFSET 1366847
#define ICH3_OFFSET 1455809
#define ICH4_OFFSET 1096693
#define ICH5_OFFSET 1307391
#define ICH6_OFFSET 1357004
#define ICH7_OFFSET 3674318
#define ICH8_OFFSET 1152754
#define ICH9_OFFSET 289441
#define ICH10_OFFSET 337153
#define ICH11_OFFSET 1643640
#define ICH12_OFFSET 1610488
#define ICH13_OFFSET 1701225
#define ICH14_OFFSET 1659900
#define ICH15_OFFSET 2013338

//SCALING Calibration
#define VCH1_SCALE 588.885742f
#define VCH2_SCALE 583.593506f
#define VCH3_SCALE 587.202087f

#define ICH1_SCALE 374.225342f
#define ICH2_SCALE 375.861511f
#define ICH3_SCALE 373.940979f
#define ICH4_SCALE 374.396271f
#define ICH5_SCALE 374.082886f
#define ICH6_SCALE 373.488159f
#define ICH7_SCALE 371.447998f
#define ICH8_SCALE 374.907959f
#define ICH9_SCALE 372.690399f
#define ICH10_SCALE 372.811066f
#define ICH11_SCALE 373.151764f
#define ICH12_SCALE 373.671417f
#define ICH13_SCALE 373.421875f
#define ICH14_SCALE 372.702148f
#define ICH15_SCALE 372.588409f

#endif

#if Calibration_Index == PMU143
// OFFSET Calibration

#define VCH1_OFFSET 252502
#define VCH2_OFFSET 901402
#define VCH3_OFFSET 1015993
                    
#define ICH1_OFFSET 1548389
#define ICH2_OFFSET 1588623
#define ICH3_OFFSET 1538253
#define ICH4_OFFSET 1616873
#define ICH5_OFFSET 1455690
#define ICH6_OFFSET 1371452
#define ICH7_OFFSET 3901747
#define ICH8_OFFSET 1126286
#define ICH9_OFFSET 231787
#define ICH10_OFFSET 341554
#define ICH11_OFFSET 1211020
#define ICH12_OFFSET 1562323
#define ICH13_OFFSET 1553078
#define ICH14_OFFSET 1744181
#define ICH15_OFFSET 1995990

//SCALING Calibration
#define VCH1_SCALE 585.948547f
#define VCH2_SCALE 587.612366f
#define VCH3_SCALE 585.713074f

#define ICH1_SCALE 374.077972f
#define ICH2_SCALE 372.610413f
#define ICH3_SCALE 373.529114f
#define ICH4_SCALE 372.80188f
#define ICH5_SCALE 373.402618f
#define ICH6_SCALE 374.01767f
#define ICH7_SCALE 370.312866f
#define ICH8_SCALE 372.356628f
#define ICH9_SCALE 372.501343f
#define ICH10_SCALE 376.131927f
#define ICH11_SCALE 373.482544f
#define ICH12_SCALE 372.371918f
#define ICH13_SCALE 375.927795f
#define ICH14_SCALE 374.683044f
#define ICH15_SCALE 373.133362f

#endif

#if Calibration_Index == PMU144
// OFFSET Calibration

#define VCH1_OFFSET 206556
#define VCH2_OFFSET 86360
#define VCH3_OFFSET 269204
                    
#define ICH1_OFFSET 1743943
#define ICH2_OFFSET 1688297
#define ICH3_OFFSET 1743561
#define ICH4_OFFSET 1591838
#define ICH5_OFFSET 1653620
#define ICH6_OFFSET 1513568
#define ICH7_OFFSET 3920573
#define ICH8_OFFSET 1197659
#define ICH9_OFFSET 14812
#define ICH10_OFFSET 244335
#define ICH11_OFFSET 1593361
#define ICH12_OFFSET 1517348
#define ICH13_OFFSET 1881543
#define ICH14_OFFSET 1652624
#define ICH15_OFFSET 1959960

//SCALING Calibration
#define VCH1_SCALE 584.343811f
#define VCH2_SCALE 585.464172f
#define VCH3_SCALE 583.219727f

#define ICH1_SCALE 374.245758f
#define ICH2_SCALE 374.612152f
#define ICH3_SCALE 374.750031f
#define ICH4_SCALE 372.640381f
#define ICH5_SCALE 375.307617f
#define ICH6_SCALE 372.896973f
#define ICH7_SCALE 372.65274f
#define ICH8_SCALE 372.339752f
#define ICH9_SCALE 373.770874f
#define ICH10_SCALE 374.37384f
#define ICH11_SCALE 376.069397f
#define ICH12_SCALE 374.191315f
#define ICH13_SCALE 376.635284f
#define ICH14_SCALE 373.920807f
#define ICH15_SCALE 375.865295f

#endif

#if Calibration_Index == PMU145
// OFFSET Calibration

#define VCH1_OFFSET 1296151
#define VCH2_OFFSET 1713039
#define VCH3_OFFSET 1839970
                    
#define ICH1_OFFSET 1449247
#define ICH2_OFFSET 1534755
#define ICH3_OFFSET 1563066
#define ICH4_OFFSET 1724256
#define ICH5_OFFSET 1532132
#define ICH6_OFFSET 1640092
#define ICH7_OFFSET 3780810
#define ICH8_OFFSET 1171386
#define ICH9_OFFSET 140928
#define ICH10_OFFSET 101729
#define ICH11_OFFSET 1470184
#define ICH12_OFFSET 1259641
#define ICH13_OFFSET 1573858
#define ICH14_OFFSET 1488075
#define ICH15_OFFSET 1758713

//SCALING Calibration
#define VCH1_SCALE 583.407776f
#define VCH2_SCALE 587.489563f
#define VCH3_SCALE 585.709717f

#define ICH1_SCALE 374.423462f
#define ICH2_SCALE 373.686066f
#define ICH3_SCALE 372.978699f
#define ICH4_SCALE 371.704803f
#define ICH5_SCALE 374.038971f
#define ICH6_SCALE 373.98288f
#define ICH7_SCALE 370.379211f
#define ICH8_SCALE 371.978119f
#define ICH9_SCALE 370.646393f
#define ICH10_SCALE 374.92099f
#define ICH11_SCALE 372.966156f
#define ICH12_SCALE 372.138824f
#define ICH13_SCALE 374.053497f
#define ICH14_SCALE 372.946228f
#define ICH15_SCALE 372.854675f

#endif

#if Calibration_Index == PMU146
// OFFSET Calibration

#define VCH1_OFFSET 625281
#define VCH2_OFFSET 857742
#define VCH3_OFFSET 981337
                    
#define ICH1_OFFSET 1463488
#define ICH2_OFFSET 1510844
#define ICH3_OFFSET 1608919
#define ICH4_OFFSET 1644688
#define ICH5_OFFSET 1478397
#define ICH6_OFFSET 1562214
#define ICH7_OFFSET 3569808
#define ICH8_OFFSET 1095228
#define ICH9_OFFSET 208031
#define ICH10_OFFSET 97859
#define ICH11_OFFSET 1746470
#define ICH12_OFFSET 1649005
#define ICH13_OFFSET 1796323
#define ICH14_OFFSET 1589937
#define ICH15_OFFSET 2141784

//SCALING Calibration
#define VCH1_SCALE 586.227356f
#define VCH2_SCALE 581.701172f
#define VCH3_SCALE 585.064514f

#define ICH1_SCALE 374.514221f
#define ICH2_SCALE 374.828369f
#define ICH3_SCALE 373.306396f
#define ICH4_SCALE 373.189117f
#define ICH5_SCALE 375.017914f
#define ICH6_SCALE 374.771851f
#define ICH7_SCALE 372.525238f
#define ICH8_SCALE 374.085541f
#define ICH9_SCALE 371.540833f
#define ICH10_SCALE 373.723633f
#define ICH11_SCALE 371.724487f
#define ICH12_SCALE 372.202911f
#define ICH13_SCALE 374.319183f
#define ICH14_SCALE 372.579498f
#define ICH15_SCALE 371.672821f

#endif

#if Calibration_Index == PMU147
// OFFSET Calibration

#define VCH1_OFFSET 452936
#define VCH2_OFFSET 710344
#define VCH3_OFFSET 858777
                    
#define ICH1_OFFSET 1743346
#define ICH2_OFFSET 1613277
#define ICH3_OFFSET 1712667
#define ICH4_OFFSET 1809917
#define ICH5_OFFSET 1803907
#define ICH6_OFFSET 1642298
#define ICH7_OFFSET 4479192
#define ICH8_OFFSET 889754
#define ICH9_OFFSET 265694
#define ICH10_OFFSET 153964
#define ICH11_OFFSET 1462519
#define ICH12_OFFSET 1645244
#define ICH13_OFFSET 1659005
#define ICH14_OFFSET 1455670
#define ICH15_OFFSET 1949651

//SCALING Calibration
#define VCH1_SCALE 586.095947f
#define VCH2_SCALE 582.310852f
#define VCH3_SCALE 590.067383f

#define ICH1_SCALE 375.43869f
#define ICH2_SCALE 374.936493f
#define ICH3_SCALE 371.767456f
#define ICH4_SCALE 371.96994f
#define ICH5_SCALE 375.818298f
#define ICH6_SCALE 373.057526f
#define ICH7_SCALE 368.785126f
#define ICH8_SCALE 373.506927f
#define ICH9_SCALE 373.561249f
#define ICH10_SCALE 374.096649f
#define ICH11_SCALE 372.910645f
#define ICH12_SCALE 374.767792f
#define ICH13_SCALE 374.315369f
#define ICH14_SCALE 373.575714f
#define ICH15_SCALE 374.027679f

#endif

#if Calibration_Index == PMU148
// OFFSET Calibration

#define VCH1_OFFSET 975164
#define VCH2_OFFSET 991094
#define VCH3_OFFSET 1402368
                    
#define ICH1_OFFSET 1540557
#define ICH2_OFFSET 1202529
#define ICH3_OFFSET 1384623
#define ICH4_OFFSET 1398357
#define ICH5_OFFSET 1642164
#define ICH6_OFFSET 1216098
#define ICH7_OFFSET 3855710
#define ICH8_OFFSET 939907
#define ICH9_OFFSET 95363
#define ICH10_OFFSET 228405
#define ICH11_OFFSET 1629851
#define ICH12_OFFSET 1778609
#define ICH13_OFFSET 1651098
#define ICH14_OFFSET 1511719
#define ICH15_OFFSET 1881234

//SCALING Calibration
#define VCH1_SCALE 585.892334f
#define VCH2_SCALE 588.503357f
#define VCH3_SCALE 585.431641f

#define ICH1_SCALE 375.990967f
#define ICH2_SCALE 372.310913f
#define ICH3_SCALE 373.583618f
#define ICH4_SCALE 372.154968f
#define ICH5_SCALE 374.79248f
#define ICH6_SCALE 375.69873f
#define ICH7_SCALE 370.713013f
#define ICH8_SCALE 372.785004f
#define ICH9_SCALE 370.495056f
#define ICH10_SCALE 374.729218f
#define ICH11_SCALE 373.261719f
#define ICH12_SCALE 373.176117f
#define ICH13_SCALE 372.800964f
#define ICH14_SCALE 372.227142f
#define ICH15_SCALE 372.189728f

#endif

#if Calibration_Index == PMU149
// OFFSET Calibration

#define VCH1_OFFSET 415922
#define VCH2_OFFSET 661701
#define VCH3_OFFSET 750922
                    
#define ICH1_OFFSET 1936849
#define ICH2_OFFSET 1768036
#define ICH3_OFFSET 1559792
#define ICH4_OFFSET 1686504
#define ICH5_OFFSET 1386100
#define ICH6_OFFSET 1513919
#define ICH7_OFFSET 3732827
#define ICH8_OFFSET 1066843
#define ICH9_OFFSET 497259
#define ICH10_OFFSET 610762
#define ICH11_OFFSET 1542738
#define ICH12_OFFSET 1643200
#define ICH13_OFFSET 1335241
#define ICH14_OFFSET 1492663
#define ICH15_OFFSET 1613978

//SCALING Calibration
#define VCH1_SCALE 583.168518f
#define VCH2_SCALE 586.802979f
#define VCH3_SCALE 583.776978f

#define ICH1_SCALE 373.618256f
#define ICH2_SCALE 374.650116f
#define ICH3_SCALE 374.873535f
#define ICH4_SCALE 371.216339f
#define ICH5_SCALE 374.72113f
#define ICH6_SCALE 373.030823f
#define ICH7_SCALE 371.191132f
#define ICH8_SCALE 373.330017f
#define ICH9_SCALE 371.959503f
#define ICH10_SCALE 371.090698f
#define ICH11_SCALE 373.577789f
#define ICH12_SCALE 371.633057f
#define ICH13_SCALE 373.649475f
#define ICH14_SCALE 372.516571f
#define ICH15_SCALE 373.314697f

#endif

#if Calibration_Index == PMU150
// OFFSET Calibration

#define VCH1_OFFSET 1080203
#define VCH2_OFFSET 1365009
#define VCH3_OFFSET 1586317
                    
#define ICH1_OFFSET 1769195
#define ICH2_OFFSET 1681388
#define ICH3_OFFSET 1623010
#define ICH4_OFFSET 1631275
#define ICH5_OFFSET 1552832
#define ICH6_OFFSET 1592555
#define ICH7_OFFSET 3823039
#define ICH8_OFFSET 1395177
#define ICH9_OFFSET 192918
#define ICH10_OFFSET 230585
#define ICH11_OFFSET 1911547
#define ICH12_OFFSET 1891973
#define ICH13_OFFSET 1747275
#define ICH14_OFFSET 1882077
#define ICH15_OFFSET 2041576

//SCALING Calibration
#define VCH1_SCALE 582.380676f
#define VCH2_SCALE 587.237122f
#define VCH3_SCALE 585.424316f

#define ICH1_SCALE 373.967407f
#define ICH2_SCALE 373.377167f
#define ICH3_SCALE 372.955414f
#define ICH4_SCALE 374.56781f
#define ICH5_SCALE 373.221771f
#define ICH6_SCALE 372.457886f
#define ICH7_SCALE 371.569641f
#define ICH8_SCALE 370.63205f
#define ICH9_SCALE 372.546844f
#define ICH10_SCALE 370.997925f
#define ICH11_SCALE 371.076538f
#define ICH12_SCALE 372.403534f
#define ICH13_SCALE 372.639069f
#define ICH14_SCALE 371.188049f
#define ICH15_SCALE 373.69519f

#endif

#if Calibration_Index == PMU151
// OFFSET Calibration

#define VCH1_OFFSET 625138
#define VCH2_OFFSET 587823
#define VCH3_OFFSET 989066
                    
#define ICH1_OFFSET 1423692
#define ICH2_OFFSET 1443593
#define ICH3_OFFSET 1297924
#define ICH4_OFFSET 1251452
#define ICH5_OFFSET 1400846
#define ICH6_OFFSET 1383562
#define ICH7_OFFSET 3875941
#define ICH8_OFFSET 574155
#define ICH9_OFFSET 216261
#define ICH10_OFFSET 540897
#define ICH11_OFFSET 1648684
#define ICH12_OFFSET 1682307
#define ICH13_OFFSET 1465006
#define ICH14_OFFSET 1712043
#define ICH15_OFFSET 2011691

//SCALING Calibration
#define VCH1_SCALE 585.927185f
#define VCH2_SCALE 584.572815f
#define VCH3_SCALE 585.534607f

#define ICH1_SCALE 374.862915f
#define ICH2_SCALE 373.049927f
#define ICH3_SCALE 374.346008f
#define ICH4_SCALE 372.384399f
#define ICH5_SCALE 374.314301f
#define ICH6_SCALE 375.695862f
#define ICH7_SCALE 369.732758f
#define ICH8_SCALE 372.437531f
#define ICH9_SCALE 372.172668f
#define ICH10_SCALE 371.84726f
#define ICH11_SCALE 371.365204f
#define ICH12_SCALE 373.510345f
#define ICH13_SCALE 374.53949f
#define ICH14_SCALE 373.413757f
#define ICH15_SCALE 374.654694f

#endif

#if Calibration_Index == PMU152
// OFFSET Calibration

#define VCH1_OFFSET 385171
#define VCH2_OFFSET 591025
#define VCH3_OFFSET 539715
                    
#define ICH1_OFFSET 1478682
#define ICH2_OFFSET 1470968
#define ICH3_OFFSET 1475418
#define ICH4_OFFSET 1506258
#define ICH5_OFFSET 1382623
#define ICH6_OFFSET 1484318
#define ICH7_OFFSET 3742620
#define ICH8_OFFSET 831329
#define ICH9_OFFSET 415245
#define ICH10_OFFSET 509174
#define ICH11_OFFSET 1469302
#define ICH12_OFFSET 1385583
#define ICH13_OFFSET 1064119
#define ICH14_OFFSET 1163605
#define ICH15_OFFSET 1647564

//SCALING Calibration
#define VCH1_SCALE 589.386841f
#define VCH2_SCALE 587.312195f
#define VCH3_SCALE 587.548706f

#define ICH1_SCALE 374.867065f
#define ICH2_SCALE 373.986237f
#define ICH3_SCALE 373.743317f
#define ICH4_SCALE 373.74527f
#define ICH5_SCALE 374.928894f
#define ICH6_SCALE 374.206635f
#define ICH7_SCALE 369.832764f
#define ICH8_SCALE 374.006775f
#define ICH9_SCALE 374.49057f
#define ICH10_SCALE 371.950745f
#define ICH11_SCALE 373.932281f
#define ICH12_SCALE 376.389313f
#define ICH13_SCALE 374.314972f
#define ICH14_SCALE 376.075409f
#define ICH15_SCALE 376.904083f

#endif

#if Calibration_Index == PMU153
// OFFSET Calibration

#define VCH1_OFFSET 760224
#define VCH2_OFFSET 864807
#define VCH3_OFFSET 1078474
                    
#define ICH1_OFFSET 1838561
#define ICH2_OFFSET 1783612
#define ICH3_OFFSET 1632159
#define ICH4_OFFSET 1901329
#define ICH5_OFFSET 1779922
#define ICH6_OFFSET 1808491
#define ICH7_OFFSET 4064048
#define ICH8_OFFSET 474727
#define ICH9_OFFSET 62274
#define ICH10_OFFSET 95398
#define ICH11_OFFSET 1913640
#define ICH12_OFFSET 1921194
#define ICH13_OFFSET 1895553
#define ICH14_OFFSET 1884776
#define ICH15_OFFSET 1866553

//SCALING Calibration
#define VCH1_SCALE 584.874817f
#define VCH2_SCALE 588.393677f
#define VCH3_SCALE 587.911499f

#define ICH1_SCALE 375.849487f
#define ICH2_SCALE 373.000244f
#define ICH3_SCALE 371.91629f
#define ICH4_SCALE 371.611542f
#define ICH5_SCALE 375.090302f
#define ICH6_SCALE 374.733002f
#define ICH7_SCALE 367.252411f
#define ICH8_SCALE 372.330902f
#define ICH9_SCALE 371.232727f
#define ICH10_SCALE 371.684387f
#define ICH11_SCALE 371.742004f
#define ICH12_SCALE 372.720398f
#define ICH13_SCALE 373.732727f
#define ICH14_SCALE 372.636658f
#define ICH15_SCALE 373.438538f

#endif

#if Calibration_Index == PMU154
// OFFSET Calibration

#define VCH1_OFFSET 121189
#define VCH2_OFFSET 35394
#define VCH3_OFFSET 320736
                    
#define ICH1_OFFSET 1992926
#define ICH2_OFFSET 1733857
#define ICH3_OFFSET 1936439
#define ICH4_OFFSET 1578113
#define ICH5_OFFSET 1529686
#define ICH6_OFFSET 1514371
#define ICH7_OFFSET 4232684
#define ICH8_OFFSET 1145304
#define ICH9_OFFSET 43849
#define ICH10_OFFSET 165967
#define ICH11_OFFSET 1690602
#define ICH12_OFFSET 1619392
#define ICH13_OFFSET 1674163
#define ICH14_OFFSET 1624323
#define ICH15_OFFSET 2289590

//SCALING Calibration
#define VCH1_SCALE 587.625122f
#define VCH2_SCALE 584.894226f
#define VCH3_SCALE 585.659302f

#define ICH1_SCALE 374.074982f
#define ICH2_SCALE 374.278107f
#define ICH3_SCALE 373.058777f
#define ICH4_SCALE 375.170258f
#define ICH5_SCALE 372.87207f
#define ICH6_SCALE 374.169556f
#define ICH7_SCALE 369.003204f
#define ICH8_SCALE 372.678436f
#define ICH9_SCALE 371.006226f
#define ICH10_SCALE 371.975952f
#define ICH11_SCALE 370.652008f
#define ICH12_SCALE 373.87854f
#define ICH13_SCALE 372.350098f
#define ICH14_SCALE 373.30188f
#define ICH15_SCALE 374.725586f

#endif

#if Calibration_Index == PMU155
// OFFSET Calibration

#define VCH1_OFFSET 885336
#define VCH2_OFFSET 927617
#define VCH3_OFFSET 1183157
                    
#define ICH1_OFFSET 1431360
#define ICH2_OFFSET 1431345
#define ICH3_OFFSET 1427394
#define ICH4_OFFSET 1096222
#define ICH5_OFFSET 1016154
#define ICH6_OFFSET 1374120
#define ICH7_OFFSET 3376958
#define ICH8_OFFSET 847897
#define ICH9_OFFSET 135362
#define ICH10_OFFSET 539355
#define ICH11_OFFSET 1725836
#define ICH12_OFFSET 1554751
#define ICH13_OFFSET 1273234
#define ICH14_OFFSET 1541648
#define ICH15_OFFSET 1624965

//SCALING Calibration
#define VCH1_SCALE 589.704346f
#define VCH2_SCALE 585.147949f
#define VCH3_SCALE 587.8927f

#define ICH1_SCALE 373.461273f
#define ICH2_SCALE 373.046204f
#define ICH3_SCALE 373.236053f
#define ICH4_SCALE 373.956848f
#define ICH5_SCALE 374.311981f
#define ICH6_SCALE 372.053223f
#define ICH7_SCALE 371.263641f
#define ICH8_SCALE 374.653351f
#define ICH9_SCALE 371.335632f
#define ICH10_SCALE 370.822449f
#define ICH11_SCALE 372.264252f
#define ICH12_SCALE 373.236725f
#define ICH13_SCALE 373.214813f
#define ICH14_SCALE 372.931732f
#define ICH15_SCALE 374.077972f

#endif

#if Calibration_Index == PMU156
// OFFSET Calibration

#define VCH1_OFFSET 392578
#define VCH2_OFFSET 558098
#define VCH3_OFFSET 481862
                    
#define ICH1_OFFSET 1516906
#define ICH2_OFFSET 1551183
#define ICH3_OFFSET 1471304
#define ICH4_OFFSET 1451507
#define ICH5_OFFSET 1625373
#define ICH6_OFFSET 1752609
#define ICH7_OFFSET 3756932
#define ICH8_OFFSET 1017021
#define ICH9_OFFSET 147696
#define ICH10_OFFSET 326561
#define ICH11_OFFSET 1678350
#define ICH12_OFFSET 1812343
#define ICH13_OFFSET 1556984
#define ICH14_OFFSET 1695847
#define ICH15_OFFSET 1964425

//SCALING Calibration
#define VCH1_SCALE 588.120789f
#define VCH2_SCALE 585.017395f
#define VCH3_SCALE 587.517395f

#define ICH1_SCALE 373.322052f
#define ICH2_SCALE 374.045471f
#define ICH3_SCALE 373.667419f
#define ICH4_SCALE 374.211884f
#define ICH5_SCALE 374.151276f
#define ICH6_SCALE 372.779633f
#define ICH7_SCALE 371.208801f
#define ICH8_SCALE 373.323395f
#define ICH9_SCALE 371.779175f
#define ICH10_SCALE 371.700195f
#define ICH11_SCALE 372.060638f
#define ICH12_SCALE 374.121613f
#define ICH13_SCALE 373.686829f
#define ICH14_SCALE 373.708588f
#define ICH15_SCALE 375.525208f

#endif

#if Calibration_Index == PMU157
// OFFSET Calibration

#define VCH1_OFFSET 468463
#define VCH2_OFFSET 623496
#define VCH3_OFFSET 1178599
                    
#define ICH1_OFFSET 1612217
#define ICH2_OFFSET 1380687
#define ICH3_OFFSET 1521127
#define ICH4_OFFSET 1373701
#define ICH5_OFFSET 1563518
#define ICH6_OFFSET 1297638
#define ICH7_OFFSET 3571128
#define ICH8_OFFSET 611787
#define ICH9_OFFSET 36596
#define ICH10_OFFSET 188674
#define ICH11_OFFSET 1705922
#define ICH12_OFFSET 1261891
#define ICH13_OFFSET 1381371
#define ICH14_OFFSET 1523945
#define ICH15_OFFSET 1770255

//SCALING Calibration
#define VCH1_SCALE 584.297607f
#define VCH2_SCALE 585.958374f
#define VCH3_SCALE 583.742981f

#define ICH1_SCALE 373.128571f
#define ICH2_SCALE 373.986115f
#define ICH3_SCALE 373.067505f
#define ICH4_SCALE 374.868958f
#define ICH5_SCALE 373.151978f
#define ICH6_SCALE 372.519867f
#define ICH7_SCALE 370.339966f
#define ICH8_SCALE 373.613495f
#define ICH9_SCALE 373.347168f
#define ICH10_SCALE 373.446594f
#define ICH11_SCALE 373.525726f
#define ICH12_SCALE 374.484467f
#define ICH13_SCALE 375.385101f
#define ICH14_SCALE 374.639832f
#define ICH15_SCALE 374.375854f

#endif

#if Calibration_Index == PMU158
// OFFSET Calibration

#define VCH1_OFFSET 814810
#define VCH2_OFFSET 1409150
#define VCH3_OFFSET 1698854
                    
#define ICH1_OFFSET 1709951
#define ICH2_OFFSET 1725258
#define ICH3_OFFSET 1752212
#define ICH4_OFFSET 1632354
#define ICH5_OFFSET 1655939
#define ICH6_OFFSET 1764806
#define ICH7_OFFSET 4110461
#define ICH8_OFFSET 553031
#define ICH9_OFFSET 13132
#define ICH10_OFFSET 170506
#define ICH11_OFFSET 1445490
#define ICH12_OFFSET 1636275
#define ICH13_OFFSET 1515007
#define ICH14_OFFSET 1456537
#define ICH15_OFFSET 1937744

//SCALING Calibration
#define VCH1_SCALE 587.418945f
#define VCH2_SCALE 585.60614f
#define VCH3_SCALE 584.556152f

#define ICH1_SCALE 372.328705f
#define ICH2_SCALE 373.424927f
#define ICH3_SCALE 374.932129f
#define ICH4_SCALE 373.532318f
#define ICH5_SCALE 374.20993f
#define ICH6_SCALE 374.201569f
#define ICH7_SCALE 370.147156f
#define ICH8_SCALE 373.184113f
#define ICH9_SCALE 371.841675f
#define ICH10_SCALE 372.68457f
#define ICH11_SCALE 372.802551f
#define ICH12_SCALE 373.285553f
#define ICH13_SCALE 373.793335f
#define ICH14_SCALE 373.848267f
#define ICH15_SCALE 374.316681f

#endif

#if Calibration_Index == PMU159
// OFFSET Calibration

#define VCH1_OFFSET 717435
#define VCH2_OFFSET 343378
#define VCH3_OFFSET 424419
                    
#define ICH1_OFFSET 1667952
#define ICH2_OFFSET 1547507
#define ICH3_OFFSET 1615688
#define ICH4_OFFSET 1727592
#define ICH5_OFFSET 1617357
#define ICH6_OFFSET 1638267
#define ICH7_OFFSET 3714171
#define ICH8_OFFSET 913356
#define ICH9_OFFSET 39159
#define ICH10_OFFSET 397059
#define ICH11_OFFSET 1846111
#define ICH12_OFFSET 1727885
#define ICH13_OFFSET 1544119
#define ICH14_OFFSET 1448045
#define ICH15_OFFSET 2043748

//SCALING Calibration
#define VCH1_SCALE 586.773926f
#define VCH2_SCALE 586.61322f
#define VCH3_SCALE 585.332642f

#define ICH1_SCALE 373.794678f
#define ICH2_SCALE 372.467255f
#define ICH3_SCALE 374.717255f
#define ICH4_SCALE 373.8461f
#define ICH5_SCALE 374.321686f
#define ICH6_SCALE 372.192963f
#define ICH7_SCALE 372.044312f
#define ICH8_SCALE 374.027222f
#define ICH9_SCALE 370.018738f
#define ICH10_SCALE 372.859436f
#define ICH11_SCALE 371.680237f
#define ICH12_SCALE 372.598694f
#define ICH13_SCALE 372.441315f
#define ICH14_SCALE 372.8909f
#define ICH15_SCALE 373.288269f

#endif

#if Calibration_Index == PMU160
// OFFSET Calibration

#define VCH1_OFFSET 570585
#define VCH2_OFFSET 657747
#define VCH3_OFFSET 873125
                    
#define ICH1_OFFSET 1768545
#define ICH2_OFFSET 1640176
#define ICH3_OFFSET 1484533
#define ICH4_OFFSET 1442826
#define ICH5_OFFSET 1610882
#define ICH6_OFFSET 1452685
#define ICH7_OFFSET 3342778
#define ICH8_OFFSET 1152953
#define ICH9_OFFSET 81237
#define ICH10_OFFSET 397909
#define ICH11_OFFSET 1884894
#define ICH12_OFFSET 1757453
#define ICH13_OFFSET 1557179
#define ICH14_OFFSET 1646602
#define ICH15_OFFSET 1876600

//SCALING Calibration
#define VCH1_SCALE 587.49707f
#define VCH2_SCALE 586.87616f
#define VCH3_SCALE 586.62384f

#define ICH1_SCALE 378.24707f
#define ICH2_SCALE 377.628998f
#define ICH3_SCALE 377.180267f
#define ICH4_SCALE 376.612396f
#define ICH5_SCALE 377.389343f
#define ICH6_SCALE 375.746552f
#define ICH7_SCALE 375.425842f
#define ICH8_SCALE 376.771027f
#define ICH9_SCALE 372.178436f
#define ICH10_SCALE 372.925873f
#define ICH11_SCALE 374.300018f
#define ICH12_SCALE 374.713379f
#define ICH13_SCALE 371.478027f
#define ICH14_SCALE 373.134827f
#define ICH15_SCALE 374.395447f

#endif

#if Calibration_Index == PMU161
// OFFSET Calibration

#define VCH1_OFFSET 614619
#define VCH2_OFFSET 774310
#define VCH3_OFFSET 756310
                    
#define ICH1_OFFSET 1903321
#define ICH2_OFFSET 1732176
#define ICH3_OFFSET 1801127
#define ICH4_OFFSET 1522373
#define ICH5_OFFSET 1612823
#define ICH6_OFFSET 1664648
#define ICH7_OFFSET 4041651
#define ICH8_OFFSET 1146813
#define ICH9_OFFSET 145703
#define ICH10_OFFSET 321864
#define ICH11_OFFSET 1520258
#define ICH12_OFFSET 1763534
#define ICH13_OFFSET 1678691
#define ICH14_OFFSET 1441616
#define ICH15_OFFSET 1779809

//SCALING Calibration
#define VCH1_SCALE 585.273865f
#define VCH2_SCALE 584.971069f
#define VCH3_SCALE 581.784668f

#define ICH1_SCALE 374.26123f
#define ICH2_SCALE 374.115173f
#define ICH3_SCALE 374.39856f
#define ICH4_SCALE 372.249329f
#define ICH5_SCALE 372.249329f
#define ICH6_SCALE 373.244995f
#define ICH7_SCALE 371.577423f
#define ICH8_SCALE 372.514221f
#define ICH9_SCALE 370.459778f
#define ICH10_SCALE 372.069824f
#define ICH11_SCALE 372.432281f
#define ICH12_SCALE 372.689148f
#define ICH13_SCALE 373.420746f
#define ICH14_SCALE 372.351715f
#define ICH15_SCALE 373.003113f

#endif

#if Calibration_Index == PMU162
// OFFSET Calibration

#define VCH1_OFFSET 100276
#define VCH2_OFFSET 233604
#define VCH3_OFFSET 189257
                    
#define ICH1_OFFSET 1586765
#define ICH2_OFFSET 1474200
#define ICH3_OFFSET 1472854
#define ICH4_OFFSET 1409180
#define ICH5_OFFSET 1717214
#define ICH6_OFFSET 1556661
#define ICH7_OFFSET 4030917
#define ICH8_OFFSET 811314
#define ICH9_OFFSET 975697
#define ICH10_OFFSET 781719
#define ICH11_OFFSET 807377
#define ICH12_OFFSET 783003
#define ICH13_OFFSET 1016997
#define ICH14_OFFSET 945739
#define ICH15_OFFSET 1493692

//SCALING Calibration
#define VCH1_SCALE 586.716492f
#define VCH2_SCALE 587.884705f
#define VCH3_SCALE 586.850708f

#define ICH1_SCALE 375.041473f
#define ICH2_SCALE 374.915283f
#define ICH3_SCALE 373.903625f
#define ICH4_SCALE 373.620697f
#define ICH5_SCALE 376.406586f
#define ICH6_SCALE 373.666962f
#define ICH7_SCALE 370.906372f
#define ICH8_SCALE 372.706573f
#define ICH9_SCALE 366.484985f
#define ICH10_SCALE 366.788757f
#define ICH11_SCALE 370.858185f
#define ICH12_SCALE 372.105072f
#define ICH13_SCALE 373.203308f
#define ICH14_SCALE 372.021576f
#define ICH15_SCALE 372.02832f

#endif

#if Calibration_Index == PMU163
// OFFSET Calibration

#define VCH1_OFFSET 193384
#define VCH2_OFFSET 55476
#define VCH3_OFFSET 325787
                    
#define ICH1_OFFSET 1457587
#define ICH2_OFFSET 1186137
#define ICH3_OFFSET 1251832
#define ICH4_OFFSET 1199983
#define ICH5_OFFSET 1416559
#define ICH6_OFFSET 1263377
#define ICH7_OFFSET 3861744
#define ICH8_OFFSET 478228
#define ICH9_OFFSET 348949
#define ICH10_OFFSET 261415
#define ICH11_OFFSET 1587851
#define ICH12_OFFSET 1762028
#define ICH13_OFFSET 1235797
#define ICH14_OFFSET 1545218
#define ICH15_OFFSET 1691624

//SCALING Calibration
#define VCH1_SCALE 587.41626f
#define VCH2_SCALE 586.6745f
#define VCH3_SCALE 585.937805f

#define ICH1_SCALE 373.692383f
#define ICH2_SCALE 373.486542f
#define ICH3_SCALE 374.59317f
#define ICH4_SCALE 372.479706f
#define ICH5_SCALE 373.690704f
#define ICH6_SCALE 373.817993f
#define ICH7_SCALE 371.230621f
#define ICH8_SCALE 372.770721f
#define ICH9_SCALE 371.351746f
#define ICH10_SCALE 374.738312f
#define ICH11_SCALE 373.451447f
#define ICH12_SCALE 372.449463f
#define ICH13_SCALE 374.487427f
#define ICH14_SCALE 374.757355f
#define ICH15_SCALE 374.10376f

#endif

#if Calibration_Index == PMU164
// OFFSET Calibration

#define VCH1_OFFSET 187469
#define VCH2_OFFSET 393095
#define VCH3_OFFSET 485075
                    
#define ICH1_OFFSET 1560070
#define ICH2_OFFSET 1470843
#define ICH3_OFFSET 1651679
#define ICH4_OFFSET 1333599
#define ICH5_OFFSET 1584596
#define ICH6_OFFSET 1484505
#define ICH7_OFFSET 3565265
#define ICH8_OFFSET 1007062
#define ICH9_OFFSET 86086
#define ICH10_OFFSET 154872
#define ICH11_OFFSET 1851412
#define ICH12_OFFSET 1795584
#define ICH13_OFFSET 1872019
#define ICH14_OFFSET 1301689
#define ICH15_OFFSET 1589277

//SCALING Calibration
#define VCH1_SCALE 585.366577f
#define VCH2_SCALE 587.475708f
#define VCH3_SCALE 585.906189f

#define ICH1_SCALE 373.975433f
#define ICH2_SCALE 371.378052f
#define ICH3_SCALE 373.43808f
#define ICH4_SCALE 371.479248f
#define ICH5_SCALE 373.218689f
#define ICH6_SCALE 374.095215f
#define ICH7_SCALE 369.681244f
#define ICH8_SCALE 371.167236f
#define ICH9_SCALE 371.678162f
#define ICH10_SCALE 373.807495f
#define ICH11_SCALE 372.440094f
#define ICH12_SCALE 373.630066f
#define ICH13_SCALE 372.451996f
#define ICH14_SCALE 373.57312f
#define ICH15_SCALE 373.57312f

#endif

#if Calibration_Index == PMU165
// OFFSET Calibration

#define VCH1_OFFSET 440497
#define VCH2_OFFSET 874565
#define VCH3_OFFSET 834635
                    
#define ICH1_OFFSET 1632748
#define ICH2_OFFSET 1565263
#define ICH3_OFFSET 1622758
#define ICH4_OFFSET 1365482
#define ICH5_OFFSET 1512222
#define ICH6_OFFSET 1413504
#define ICH7_OFFSET 3975023
#define ICH8_OFFSET 1016748
#define ICH9_OFFSET 39871
#define ICH10_OFFSET 138595
#define ICH11_OFFSET 1694184
#define ICH12_OFFSET 1404647
#define ICH13_OFFSET 1445101
#define ICH14_OFFSET 1479441
#define ICH15_OFFSET 1923782

//SCALING Calibration
#define VCH1_SCALE 586.929626f
#define VCH2_SCALE 586.982239f
#define VCH3_SCALE 586.627258f

#define ICH1_SCALE 373.397278f
#define ICH2_SCALE 373.387634f
#define ICH3_SCALE 373.616333f
#define ICH4_SCALE 373.231506f
#define ICH5_SCALE 374.399597f
#define ICH6_SCALE 374.54718f
#define ICH7_SCALE 367.436401f
#define ICH8_SCALE 372.493774f
#define ICH9_SCALE 371.263855f
#define ICH10_SCALE 374.132294f
#define ICH11_SCALE 370.281982f
#define ICH12_SCALE 373.039154f
#define ICH13_SCALE 374.068512f
#define ICH14_SCALE 372.934692f
#define ICH15_SCALE 372.823853f

#endif

#if Calibration_Index == PMU166
// OFFSET Calibration

#define VCH1_OFFSET 88528
#define VCH2_OFFSET 454563
#define VCH3_OFFSET 407169
                    
#define ICH1_OFFSET 1157151
#define ICH2_OFFSET 878213
#define ICH3_OFFSET 1103107
#define ICH4_OFFSET 1290676
#define ICH5_OFFSET 1285155
#define ICH6_OFFSET 1118159
#define ICH7_OFFSET 3650513
#define ICH8_OFFSET 596656
#define ICH9_OFFSET 124831
#define ICH10_OFFSET 413506
#define ICH11_OFFSET 1486253
#define ICH12_OFFSET 1575741
#define ICH13_OFFSET 1733302
#define ICH14_OFFSET 1109967
#define ICH15_OFFSET 1700308

//SCALING Calibration
#define VCH1_SCALE 587.257446f
#define VCH2_SCALE 587.250061f
#define VCH3_SCALE 588.431152f

#define ICH1_SCALE 372.482819f
#define ICH2_SCALE 374.261902f
#define ICH3_SCALE 374.336945f
#define ICH4_SCALE 373.996521f
#define ICH5_SCALE 372.924255f
#define ICH6_SCALE 374.345276f
#define ICH7_SCALE 370.552032f
#define ICH8_SCALE 370.855072f
#define ICH9_SCALE 371.410675f
#define ICH10_SCALE 373.360229f
#define ICH11_SCALE 373.372833f
#define ICH12_SCALE 372.42038f
#define ICH13_SCALE 374.541656f
#define ICH14_SCALE 373.932739f
#define ICH15_SCALE 372.352509f

#endif

#if Calibration_Index == PMU167
// OFFSET Calibration

#define VCH1_OFFSET 829576
#define VCH2_OFFSET 928656
#define VCH3_OFFSET 911122
                    
#define ICH1_OFFSET 1669471
#define ICH2_OFFSET 1590792
#define ICH3_OFFSET 1375799
#define ICH4_OFFSET 1276072
#define ICH5_OFFSET 1433140
#define ICH6_OFFSET 1275932
#define ICH7_OFFSET 3920969
#define ICH8_OFFSET 821442
#define ICH9_OFFSET 386955
#define ICH10_OFFSET 704585
#define ICH11_OFFSET 1902825
#define ICH12_OFFSET 1774114
#define ICH13_OFFSET 1587761
#define ICH14_OFFSET 1474647
#define ICH15_OFFSET 1956260

//SCALING Calibration
#define VCH1_SCALE 585.045776f
#define VCH2_SCALE 587.103333f
#define VCH3_SCALE 584.733643f

#define ICH1_SCALE 372.363831f
#define ICH2_SCALE 373.468292f
#define ICH3_SCALE 373.523499f
#define ICH4_SCALE 374.734039f
#define ICH5_SCALE 374.074036f
#define ICH6_SCALE 372.972168f
#define ICH7_SCALE 369.956543f
#define ICH8_SCALE 373.648773f
#define ICH9_SCALE 373.572601f
#define ICH10_SCALE 369.967621f
#define ICH11_SCALE 374.73587f
#define ICH12_SCALE 373.803833f
#define ICH13_SCALE 375.362762f
#define ICH14_SCALE 373.970032f
#define ICH15_SCALE 373.482819f

#endif

#if Calibration_Index == PMU168
// OFFSET Calibration

#define VCH1_OFFSET 816787
#define VCH2_OFFSET 757114
#define VCH3_OFFSET 1126675
                    
#define ICH1_OFFSET 1623127
#define ICH2_OFFSET 1726253
#define ICH3_OFFSET 1807047
#define ICH4_OFFSET 1220577
#define ICH5_OFFSET 1654236
#define ICH6_OFFSET 1496393
#define ICH7_OFFSET 4151476
#define ICH8_OFFSET 620274
#define ICH9_OFFSET 525726
#define ICH10_OFFSET 393847
#define ICH11_OFFSET 1446573
#define ICH12_OFFSET 1480707
#define ICH13_OFFSET 1655644
#define ICH14_OFFSET 1280185
#define ICH15_OFFSET 1793742

//SCALING Calibration
#define VCH1_SCALE 586.822327f
#define VCH2_SCALE 587.746338f
#define VCH3_SCALE 589.275208f

#define ICH1_SCALE 374.65979f
#define ICH2_SCALE 372.883667f
#define ICH3_SCALE 372.542786f
#define ICH4_SCALE 372.686768f
#define ICH5_SCALE 374.25528f
#define ICH6_SCALE 373.663544f
#define ICH7_SCALE 369.817078f
#define ICH8_SCALE 372.587097f
#define ICH9_SCALE 371.967804f
#define ICH10_SCALE 370.715851f
#define ICH11_SCALE 372.575043f
#define ICH12_SCALE 372.77829f
#define ICH13_SCALE 376.145508f
#define ICH14_SCALE 371.429443f
#define ICH15_SCALE 373.30246f

#endif

#if Calibration_Index == PMU169
// OFFSET Calibration

#define VCH1_OFFSET 619647
#define VCH2_OFFSET 792738
#define VCH3_OFFSET 1022830
                    
#define ICH1_OFFSET 1723466
#define ICH2_OFFSET 1801561
#define ICH3_OFFSET 1879851
#define ICH4_OFFSET 1691542
#define ICH5_OFFSET 1523658
#define ICH6_OFFSET 1470001
#define ICH7_OFFSET 3975557
#define ICH8_OFFSET 843861
#define ICH9_OFFSET 378379
#define ICH10_OFFSET 818763
#define ICH11_OFFSET 1446437
#define ICH12_OFFSET 1232995
#define ICH13_OFFSET 1049859
#define ICH14_OFFSET 1202672
#define ICH15_OFFSET 1377135

//SCALING Calibration
#define VCH1_SCALE 587.328308f
#define VCH2_SCALE 586.648499f
#define VCH3_SCALE 589.242859f

#define ICH1_SCALE 375.925934f
#define ICH2_SCALE 375.27359f
#define ICH3_SCALE 373.011169f
#define ICH4_SCALE 372.832458f
#define ICH5_SCALE 375.235687f
#define ICH6_SCALE 374.774841f
#define ICH7_SCALE 371.047607f
#define ICH8_SCALE 373.939606f
#define ICH9_SCALE 373.869354f
#define ICH10_SCALE 364.756775f
#define ICH11_SCALE 372.684479f
#define ICH12_SCALE 372.925964f
#define ICH13_SCALE 373.946533f
#define ICH14_SCALE 373.946533f
#define ICH15_SCALE 372.964264f

#endif

#if Calibration_Index == PMU170
// OFFSET Calibration

#define VCH1_OFFSET 931643
#define VCH2_OFFSET 1175023
#define VCH3_OFFSET 1182487
                    
#define ICH1_OFFSET 1515175
#define ICH2_OFFSET 1607563
#define ICH3_OFFSET 1366820
#define ICH4_OFFSET 1516295
#define ICH5_OFFSET 1348750
#define ICH6_OFFSET 1365935
#define ICH7_OFFSET 3981126
#define ICH8_OFFSET 427988
#define ICH9_OFFSET 108174
#define ICH10_OFFSET 108174
#define ICH11_OFFSET 1701984
#define ICH12_OFFSET 1475090
#define ICH13_OFFSET 1761985
#define ICH14_OFFSET 1615490
#define ICH15_OFFSET 1906535

//SCALING Calibration
#define VCH1_SCALE 586.606201f
#define VCH2_SCALE 585.14093f
#define VCH3_SCALE 583.702698f

#define ICH1_SCALE 375.077332f
#define ICH2_SCALE 373.807098f
#define ICH3_SCALE 373.457153f
#define ICH4_SCALE 372.836548f
#define ICH5_SCALE 375.861053f
#define ICH6_SCALE 373.494873f
#define ICH7_SCALE 369.766907f
#define ICH8_SCALE 373.098572f
#define ICH9_SCALE 371.691681f
#define ICH10_SCALE 374.295441f
#define ICH11_SCALE 372.479156f
#define ICH12_SCALE 373.50415f
#define ICH13_SCALE 373.09201f
#define ICH14_SCALE 372.428589f
#define ICH15_SCALE 372.968201f

#endif

#if Calibration_Index == PMU171
// OFFSET Calibration

#define VCH1_OFFSET 292363
#define VCH2_OFFSET 444680
#define VCH3_OFFSET 449037
                    
#define ICH1_OFFSET 1521885
#define ICH2_OFFSET 1422304
#define ICH3_OFFSET 1553405
#define ICH4_OFFSET 1360276
#define ICH5_OFFSET 1597396
#define ICH6_OFFSET 1478726
#define ICH7_OFFSET 3396617
#define ICH8_OFFSET 1044019
#define ICH9_OFFSET 14119
#define ICH10_OFFSET 169627
#define ICH11_OFFSET 1608974
#define ICH12_OFFSET 1659296
#define ICH13_OFFSET 1537010
#define ICH14_OFFSET 1642168
#define ICH15_OFFSET 2041270

//SCALING Calibration
#define VCH1_SCALE 588.086609f
#define VCH2_SCALE 587.673401f
#define VCH3_SCALE 587.433899f

#define ICH1_SCALE 373.802063f
#define ICH2_SCALE 373.743835f
#define ICH3_SCALE 374.506561f
#define ICH4_SCALE 373.188538f
#define ICH5_SCALE 374.091217f
#define ICH6_SCALE 373.495331f
#define ICH7_SCALE 371.372772f
#define ICH8_SCALE 372.010895f
#define ICH9_SCALE 372.417786f
#define ICH10_SCALE 372.817657f
#define ICH11_SCALE 373.539459f
#define ICH12_SCALE 374.777832f
#define ICH13_SCALE 372.812012f
#define ICH14_SCALE 374.501434f
#define ICH15_SCALE 373.925842f

#endif

#if Calibration_Index == PMU172
// OFFSET Calibration

#define VCH1_OFFSET 535139
#define VCH2_OFFSET 782425
#define VCH3_OFFSET 1094052
                    
#define ICH1_OFFSET 1094052
#define ICH2_OFFSET 1741493
#define ICH3_OFFSET 1767763
#define ICH4_OFFSET 1340205
#define ICH5_OFFSET 1841871
#define ICH6_OFFSET 1532930
#define ICH7_OFFSET 3873433
#define ICH8_OFFSET 855623
#define ICH9_OFFSET 55944
#define ICH10_OFFSET 147100
#define ICH11_OFFSET 1822329
#define ICH12_OFFSET 1669679
#define ICH13_OFFSET 1491919
#define ICH14_OFFSET 1550303
#define ICH15_OFFSET 2129789

//SCALING Calibration
#define VCH1_SCALE 585.599487f
#define VCH2_SCALE 584.486694f
#define VCH3_SCALE 587.743713f

#define ICH1_SCALE 372.021362f
#define ICH2_SCALE 374.856171f
#define ICH3_SCALE 373.451843f
#define ICH4_SCALE 373.610565f
#define ICH5_SCALE 373.132263f
#define ICH6_SCALE 373.263031f
#define ICH7_SCALE 372.013885f
#define ICH8_SCALE 372.658173f
#define ICH9_SCALE 370.591583f
#define ICH10_SCALE 373.135376f
#define ICH11_SCALE 371.820618f
#define ICH12_SCALE 372.86499f
#define ICH13_SCALE 372.7771f
#define ICH14_SCALE 371.418915f
#define ICH15_SCALE 372.897491f

#endif

#if Calibration_Index == PMU173
// OFFSET Calibration

#define VCH1_OFFSET 677249
#define VCH2_OFFSET 589697
#define VCH3_OFFSET 244258
                    
#define ICH1_OFFSET 1872182
#define ICH2_OFFSET 1764177
#define ICH3_OFFSET 1694355
#define ICH4_OFFSET 1772417
#define ICH5_OFFSET 1815874
#define ICH6_OFFSET 1574889
#define ICH7_OFFSET 4292370
#define ICH8_OFFSET 787615
#define ICH9_OFFSET 120901
#define ICH10_OFFSET 425830
#define ICH11_OFFSET 1828864
#define ICH12_OFFSET 1536214
#define ICH13_OFFSET 1550147
#define ICH14_OFFSET 1364075
#define ICH15_OFFSET 1922365

//SCALING Calibration
#define VCH1_SCALE 587.131775f
#define VCH2_SCALE 585.121521f
#define VCH3_SCALE 584.641541f

#define ICH1_SCALE 373.457642f
#define ICH2_SCALE 375.191162f
#define ICH3_SCALE 372.066254f
#define ICH4_SCALE 374.144531f
#define ICH5_SCALE 374.669189f
#define ICH6_SCALE 372.170166f
#define ICH7_SCALE 369.800201f
#define ICH8_SCALE 372.204224f
#define ICH9_SCALE 373.144867f
#define ICH10_SCALE 373.151062f
#define ICH11_SCALE 373.113708f
#define ICH12_SCALE 374.97113f
#define ICH13_SCALE 373.917114f
#define ICH14_SCALE 373.931396f
#define ICH15_SCALE 373.949768f

#endif

#if Calibration_Index == PMU174
// OFFSET Calibration

#define VCH1_OFFSET 910788
#define VCH2_OFFSET 1138955
#define VCH3_OFFSET 1468732
                    
#define ICH1_OFFSET 1725327
#define ICH2_OFFSET 1757440
#define ICH3_OFFSET 1410191
#define ICH4_OFFSET 1463227
#define ICH5_OFFSET 1647423
#define ICH6_OFFSET 1521600
#define ICH7_OFFSET 3885079
#define ICH8_OFFSET 1159993
#define ICH9_OFFSET 47785
#define ICH10_OFFSET 162843
#define ICH11_OFFSET 1447938
#define ICH12_OFFSET 1503907
#define ICH13_OFFSET 1503907
#define ICH14_OFFSET 1522080
#define ICH15_OFFSET 2189153

//SCALING Calibration
#define VCH1_SCALE 586.221497f
#define VCH2_SCALE 589.414978f
#define VCH3_SCALE 584.650085f

#define ICH1_SCALE 375.040192f
#define ICH2_SCALE 371.390533f
#define ICH3_SCALE 373.970123f
#define ICH4_SCALE 371.251709f
#define ICH5_SCALE 373.952576f
#define ICH6_SCALE 372.187714f
#define ICH7_SCALE 372.79599f
#define ICH8_SCALE 371.979187f
#define ICH9_SCALE 371.374603f
#define ICH10_SCALE 373.525879f
#define ICH11_SCALE 372.505707f
#define ICH12_SCALE 373.732758f
#define ICH13_SCALE 373.05249f
#define ICH14_SCALE 373.173279f
#define ICH15_SCALE 371.930817f

#endif

#if Calibration_Index == PMU175
// OFFSET Calibration

#define VCH1_OFFSET 631874
#define VCH2_OFFSET 924049
#define VCH3_OFFSET 840714
                    
#define ICH1_OFFSET 1661597
#define ICH2_OFFSET 1729408
#define ICH3_OFFSET 1913276
#define ICH4_OFFSET 1463043
#define ICH5_OFFSET 1888302
#define ICH6_OFFSET 1826223
#define ICH7_OFFSET 3614861
#define ICH8_OFFSET 1318652
#define ICH9_OFFSET 382005
#define ICH10_OFFSET 509360
#define ICH11_OFFSET 1504583
#define ICH12_OFFSET 1674940
#define ICH13_OFFSET 1719572
#define ICH14_OFFSET 1456075
#define ICH15_OFFSET 1765520

//SCALING Calibration
#define VCH1_SCALE 588.467773f
#define VCH2_SCALE 585.048401f
#define VCH3_SCALE 585.664185f

#define ICH1_SCALE 375.824127f
#define ICH2_SCALE 372.925537f
#define ICH3_SCALE 375.83725f
#define ICH4_SCALE 372.651489f
#define ICH5_SCALE 374.487518f
#define ICH6_SCALE 374.389618f
#define ICH7_SCALE 372.733337f
#define ICH8_SCALE 372.97879f
#define ICH9_SCALE 372.009552f
#define ICH10_SCALE 373.27829f
#define ICH11_SCALE 372.194244f
#define ICH12_SCALE 373.937988f
#define ICH13_SCALE 373.877747f
#define ICH14_SCALE 371.995331f
#define ICH15_SCALE 373.473602f

#endif

#if Calibration_Index == PMU176
// OFFSET Calibration

#define VCH1_OFFSET 1060664
#define VCH2_OFFSET 1544284
#define VCH3_OFFSET 1658456
                    
#define ICH1_OFFSET 1611273
#define ICH2_OFFSET 1699969
#define ICH3_OFFSET 1495625
#define ICH4_OFFSET 1644450
#define ICH5_OFFSET 1520661
#define ICH6_OFFSET 1682968
#define ICH7_OFFSET 4240137
#define ICH8_OFFSET 871780
#define ICH9_OFFSET 44957
#define ICH10_OFFSET 566459
#define ICH11_OFFSET 1618655
#define ICH12_OFFSET 1612964
#define ICH13_OFFSET 1658557
#define ICH14_OFFSET 1425051
#define ICH15_OFFSET 1962682

//SCALING Calibration
#define VCH1_SCALE 585.921814f
#define VCH2_SCALE 585.203491f
#define VCH3_SCALE 586.672302f

#define ICH1_SCALE 374.241699f
#define ICH2_SCALE 374.800079f
#define ICH3_SCALE 372.800415f
#define ICH4_SCALE 373.903656f
#define ICH5_SCALE 375.771637f
#define ICH6_SCALE 371.988159f
#define ICH7_SCALE 371.590637f
#define ICH8_SCALE 373.975067f
#define ICH9_SCALE 371.836823f
#define ICH10_SCALE 371.590668f
#define ICH11_SCALE 374.30365f
#define ICH12_SCALE 373.824005f
#define ICH13_SCALE 372.318573f
#define ICH14_SCALE 372.860107f
#define ICH15_SCALE 372.789246f

#endif

#if Calibration_Index == PMU177
// OFFSET Calibration

#define VCH1_OFFSET 1135350
#define VCH2_OFFSET 1365527
#define VCH3_OFFSET 979718
                    
#define ICH1_OFFSET 1536158
#define ICH2_OFFSET 1683507
#define ICH3_OFFSET 1606010
#define ICH4_OFFSET 1552849
#define ICH5_OFFSET 1660007
#define ICH6_OFFSET 1745189
#define ICH7_OFFSET 3861860
#define ICH8_OFFSET 1004825
#define ICH9_OFFSET 55043
#define ICH10_OFFSET 251495
#define ICH11_OFFSET 1307581
#define ICH12_OFFSET 1559912
#define ICH13_OFFSET 1545124
#define ICH14_OFFSET 1634567
#define ICH15_OFFSET 2098040

//SCALING Calibration
#define VCH1_SCALE 582.383484f
#define VCH2_SCALE 584.175842f
#define VCH3_SCALE 585.673096f

#define ICH1_SCALE 374.672119f
#define ICH2_SCALE 374.3414f
#define ICH3_SCALE 373.634674f
#define ICH4_SCALE 373.624939f
#define ICH5_SCALE 374.07489f
#define ICH6_SCALE 373.570465f
#define ICH7_SCALE 371.383698f
#define ICH8_SCALE 373.125702f
#define ICH9_SCALE 370.79364f
#define ICH10_SCALE 372.091675f
#define ICH11_SCALE 371.425171f
#define ICH12_SCALE 373.332977f
#define ICH13_SCALE 371.045929f
#define ICH14_SCALE 371.54715f
#define ICH15_SCALE 373.260529f

#endif

#if Calibration_Index == PMU178
// OFFSET Calibration

#define VCH1_OFFSET 299093
#define VCH2_OFFSET 214501
#define VCH3_OFFSET 313505
                    
#define ICH1_OFFSET 1839576
#define ICH2_OFFSET 2034244
#define ICH3_OFFSET 1778440
#define ICH4_OFFSET 1656669
#define ICH5_OFFSET 1608701
#define ICH6_OFFSET 1710587
#define ICH7_OFFSET 3923087
#define ICH8_OFFSET 1312057
#define ICH9_OFFSET 74440
#define ICH10_OFFSET 268488
#define ICH11_OFFSET 1506651
#define ICH12_OFFSET 1401854
#define ICH13_OFFSET 1381712
#define ICH14_OFFSET 1683559
#define ICH15_OFFSET 2025844

//SCALING Calibration
#define VCH1_SCALE 589.0625f
#define VCH2_SCALE 589.868347f
#define VCH3_SCALE 585.993347f
                   
#define ICH1_SCALE 374.675568f
#define ICH2_SCALE 374.651764f
#define ICH3_SCALE 376.645508f
#define ICH4_SCALE 375.819946f
#define ICH5_SCALE 375.107788f
#define ICH6_SCALE 374.296143f
#define ICH7_SCALE 374.642639f
#define ICH8_SCALE 373.459656f
#define ICH9_SCALE 372.372772f
#define ICH10_SCALE 374.446472f
#define ICH11_SCALE 373.650482f
#define ICH12_SCALE 375.076477f
#define ICH13_SCALE 374.956055f
#define ICH14_SCALE 374.512482f
#define ICH15_SCALE 374.736877f

#endif

#if Calibration_Index == PMU179
// OFFSET Calibration

#define VCH1_OFFSET 314526
#define VCH2_OFFSET 418156
#define VCH3_OFFSET 891771
                    
#define ICH1_OFFSET 1174185
#define ICH2_OFFSET 1449808
#define ICH3_OFFSET 1384474
#define ICH4_OFFSET 1340718
#define ICH5_OFFSET 1443403
#define ICH6_OFFSET 1526240
#define ICH7_OFFSET 4141139
#define ICH8_OFFSET 820209
#define ICH9_OFFSET 277026
#define ICH10_OFFSET 265917
#define ICH11_OFFSET 1746081
#define ICH12_OFFSET 1765395
#define ICH13_OFFSET 1534125
#define ICH14_OFFSET 1545050
#define ICH15_OFFSET 1673149

//SCALING Calibration
#define VCH1_SCALE 585.634521f
#define VCH2_SCALE 587.301147f
#define VCH3_SCALE 585.758179f
                   
#define ICH1_SCALE 373.408142f
#define ICH2_SCALE 373.967773f
#define ICH3_SCALE 373.073334f
#define ICH4_SCALE 375.166565f
#define ICH5_SCALE 373.789581f
#define ICH6_SCALE 374.258545f
#define ICH7_SCALE 374.258545f
#define ICH8_SCALE 372.231934f
#define ICH9_SCALE 371.02536f
#define ICH10_SCALE 371.625519f
#define ICH11_SCALE 373.447113f
#define ICH12_SCALE 374.40329f
#define ICH13_SCALE 373.328827f
#define ICH14_SCALE 373.574585f
#define ICH15_SCALE 372.953064f

#endif

#if Calibration_Index == PMU180
// OFFSET Calibration

#define VCH1_OFFSET 498475
#define VCH2_OFFSET 897801
#define VCH3_OFFSET 965088

#define ICH1_OFFSET 965088
#define ICH2_OFFSET 948568
#define ICH3_OFFSET 838095
#define ICH4_OFFSET 957589
#define ICH5_OFFSET 1151299
#define ICH6_OFFSET 1267351
#define ICH7_OFFSET 3854151
#define ICH8_OFFSET 229490
#define ICH9_OFFSET 190735
#define ICH10_OFFSET 117188
#define ICH11_OFFSET 1754753
#define ICH12_OFFSET 1615627
#define ICH13_OFFSET 1637103
#define ICH14_OFFSET 1473358
#define ICH15_OFFSET 2025825

//SCALING Calibration
#define VCH1_SCALE 584.90271f
#define VCH2_SCALE 584.04718f
#define VCH3_SCALE 588.998108f

#define ICH1_SCALE 373.197784f
#define ICH2_SCALE 374.875092f
#define ICH3_SCALE 372.368652f
#define ICH4_SCALE 372.606781f
#define ICH5_SCALE 375.064758f
#define ICH6_SCALE 371.423401f
#define ICH7_SCALE 370.881531f
#define ICH8_SCALE 372.375122f
#define ICH9_SCALE 372.630402f
#define ICH10_SCALE 372.945923f
#define ICH11_SCALE 372.829865f
#define ICH12_SCALE 374.251465f
#define ICH13_SCALE 372.671295f
#define ICH14_SCALE 372.29599f
#define ICH15_SCALE 372.304901f

#endif

#if Calibration_Index == PMU181
// OFFSET Calibration

#define VCH1_OFFSET 670798
#define VCH2_OFFSET 823340
#define VCH3_OFFSET 1125095
                    
#define ICH1_OFFSET 1298833
#define ICH2_OFFSET 1607429
#define ICH3_OFFSET 1427733
#define ICH4_OFFSET 1728689
#define ICH5_OFFSET 1446458
#define ICH6_OFFSET 1521380
#define ICH7_OFFSET 3756599
#define ICH8_OFFSET 777917
#define ICH9_OFFSET 70428
#define ICH10_OFFSET 154019
#define ICH11_OFFSET 1727443
#define ICH12_OFFSET 1660351
#define ICH13_OFFSET 1469674
#define ICH14_OFFSET 1612649
#define ICH15_OFFSET 1819345

//SCALING Calibration
#define VCH1_SCALE 583.823975f
#define VCH2_SCALE 588.321228f
#define VCH3_SCALE 587.065369f

#define ICH1_SCALE 374.911407f
#define ICH2_SCALE 373.250244f
#define ICH3_SCALE 374.006836f
#define ICH4_SCALE 373.510437f
#define ICH5_SCALE 374.328033f
#define ICH6_SCALE 373.623383f
#define ICH7_SCALE 371.577057f
#define ICH8_SCALE 373.846161f
#define ICH9_SCALE 372.477448f
#define ICH10_SCALE 373.101105f
#define ICH11_SCALE 373.34198f
#define ICH12_SCALE 372.888458f
#define ICH13_SCALE 373.095673f
#define ICH14_SCALE 371.030243f
#define ICH15_SCALE 371.71579f

#endif
#if Calibration_Index == PMU182
// OFFSET Calibration

#define VCH1_OFFSET 1007941
#define VCH2_OFFSET 1058560
#define VCH3_OFFSET 1090169
                    
#define ICH1_OFFSET 1838042
#define ICH2_OFFSET 1695794
#define ICH3_OFFSET 1673701
#define ICH4_OFFSET 1774677
#define ICH5_OFFSET 1703771
#define ICH6_OFFSET 1640970
#define ICH7_OFFSET 3974233
#define ICH8_OFFSET 1243724
#define ICH9_OFFSET 81528
#define ICH10_OFFSET 290195
#define ICH11_OFFSET 1455628
#define ICH12_OFFSET 1491846
#define ICH13_OFFSET 1752551
#define ICH14_OFFSET 1549050
#define ICH15_OFFSET 1917317

//SCALING Calibration
#define VCH1_SCALE 587.34021f
#define VCH2_SCALE 586.493164f
#define VCH3_SCALE 586.033142f

#define ICH1_SCALE 374.651154f
#define ICH2_SCALE 373.569977f
#define ICH3_SCALE 374.194946f
#define ICH4_SCALE 372.247101f
#define ICH5_SCALE 373.933777f
#define ICH6_SCALE 375.107025f
#define ICH7_SCALE 370.178711f
#define ICH8_SCALE 370.497681f
#define ICH9_SCALE 372.581757f
#define ICH10_SCALE 373.151886f
#define ICH11_SCALE 373.566132f
#define ICH12_SCALE 375.797424f
#define ICH13_SCALE 373.049957f
#define ICH14_SCALE 373.644196f
#define ICH15_SCALE 374.187866f

#endif
#if Calibration_Index == PMU183
// OFFSET Calibration

#define VCH1_OFFSET 94465
#define VCH2_OFFSET 420643
#define VCH3_OFFSET 215835
                    
#define ICH1_OFFSET 1068721
#define ICH2_OFFSET 991070
#define ICH3_OFFSET 1239330
#define ICH4_OFFSET 1199605
#define ICH5_OFFSET 1359930
#define ICH6_OFFSET 1156447
#define ICH7_OFFSET 2877787
#define ICH8_OFFSET 757434
#define ICH9_OFFSET 52393
#define ICH10_OFFSET 175283
#define ICH11_OFFSET 1813930
#define ICH12_OFFSET 1659113
#define ICH13_OFFSET 1507649
#define ICH14_OFFSET 1570324
#define ICH15_OFFSET 1983537

//SCALING Calibration
#define VCH1_SCALE 588.591553f
#define VCH2_SCALE 584.660278f
#define VCH3_SCALE 589.210022f

#define ICH1_SCALE 375.021454f
#define ICH2_SCALE 375.382141f
#define ICH3_SCALE 372.73175f
#define ICH4_SCALE 373.094849f
#define ICH5_SCALE 376.658325f
#define ICH6_SCALE 373.082825f
#define ICH7_SCALE 372.663055f
#define ICH8_SCALE 373.507385f
#define ICH9_SCALE 373.358215f
#define ICH10_SCALE 374.303986f
#define ICH11_SCALE 374.40741f
#define ICH12_SCALE 374.675873f
#define ICH13_SCALE 375.088959f
#define ICH14_SCALE 373.630951f
#define ICH15_SCALE 373.201996f

#endif
#if Calibration_Index == PMU184
// OFFSET Calibration

#define VCH1_OFFSET 873938
#define VCH2_OFFSET 1041835
#define VCH3_OFFSET 1308372
                    
#define ICH1_OFFSET 1291627
#define ICH2_OFFSET 1261197
#define ICH3_OFFSET 1280280
#define ICH4_OFFSET 1295756
#define ICH5_OFFSET 1260753
#define ICH6_OFFSET 1300224
#define ICH7_OFFSET 3685135
#define ICH8_OFFSET 708627
#define ICH9_OFFSET 52896
#define ICH10_OFFSET 12406
#define ICH11_OFFSET 1574795
#define ICH12_OFFSET 1394911
#define ICH13_OFFSET 1453552
#define ICH14_OFFSET 1370779
#define ICH15_OFFSET 1955993

//SCALING Calibration
#define VCH1_SCALE 590.351135f
#define VCH2_SCALE 585.856384f
#define VCH3_SCALE 585.668457f

#define ICH1_SCALE 374.459656f
#define ICH2_SCALE 374.062195f
#define ICH3_SCALE 374.097778f
#define ICH4_SCALE 373.051392f
#define ICH5_SCALE 374.645233f
#define ICH6_SCALE 373.507355f
#define ICH7_SCALE 370.699402f
#define ICH8_SCALE 372.878571f
#define ICH9_SCALE 372.35376f
#define ICH10_SCALE 371.946106f
#define ICH11_SCALE 374.27887f
#define ICH12_SCALE 375.846741f
#define ICH13_SCALE 374.45462f
#define ICH14_SCALE 374.290436f
#define ICH15_SCALE 374.938629f

#endif
#if Calibration_Index == PMU185
// OFFSET Calibration

#define VCH1_OFFSET 782595
#define VCH2_OFFSET 550118
#define VCH3_OFFSET 1157702
                    
#define ICH1_OFFSET 1322483
#define ICH2_OFFSET 1506509
#define ICH3_OFFSET 1347473
#define ICH4_OFFSET 1313788
#define ICH5_OFFSET 1396700
#define ICH6_OFFSET 1451794
#define ICH7_OFFSET 3176156
#define ICH8_OFFSET 801294
#define ICH9_OFFSET 187658
#define ICH10_OFFSET 271156
#define ICH11_OFFSET 1483391
#define ICH12_OFFSET 1589730
#define ICH13_OFFSET 1340060
#define ICH14_OFFSET 1337860
#define ICH15_OFFSET 1946668

//SCALING Calibration
#define VCH1_SCALE 584.837524f
#define VCH2_SCALE 586.248108f
#define VCH3_SCALE 588.507629f

#define ICH1_SCALE 375.474121f
#define ICH2_SCALE 373.36438f
#define ICH3_SCALE 373.604034f
#define ICH4_SCALE 373.263306f
#define ICH5_SCALE 374.45813f
#define ICH6_SCALE 371.995758f
#define ICH7_SCALE 370.747681f
#define ICH8_SCALE 373.34729f
#define ICH9_SCALE 373.362549f
#define ICH10_SCALE 373.46579f
#define ICH11_SCALE 372.552704f
#define ICH12_SCALE 373.01767f
#define ICH13_SCALE 374.132996f
#define ICH14_SCALE 372.374512f
#define ICH15_SCALE 371.173981f

#endif
#if Calibration_Index == PMU186
// OFFSET Calibration

#define VCH1_OFFSET 125601
#define VCH2_OFFSET 324027
#define VCH3_OFFSET 459115
                    
#define ICH1_OFFSET 1544219
#define ICH2_OFFSET 1656307
#define ICH3_OFFSET 1584360
#define ICH4_OFFSET 1586727
#define ICH5_OFFSET 1708283
#define ICH6_OFFSET 1613638
#define ICH7_OFFSET 4253683
#define ICH8_OFFSET 1020601
#define ICH9_OFFSET 327450
#define ICH10_OFFSET 182079
#define ICH11_OFFSET 1682977
#define ICH12_OFFSET 1823744
#define ICH13_OFFSET 1716088
#define ICH14_OFFSET 1920455
#define ICH15_OFFSET 2143324

//SCALING Calibration
#define VCH1_SCALE 587.435669
#define VCH2_SCALE 585.654297
#define VCH3_SCALE 584.170776

#define ICH1_SCALE 374.477753
#define ICH2_SCALE 374.861755f
#define ICH3_SCALE 375.118958f
#define ICH4_SCALE 373.949646f
#define ICH5_SCALE 373.76944f
#define ICH6_SCALE 373.9198f
#define ICH7_SCALE 372.123474f
#define ICH8_SCALE 373.392212f
#define ICH9_SCALE 369.414215f
#define ICH10_SCALE 373.288483f
#define ICH11_SCALE 372.478363f
#define ICH12_SCALE 373.022278f
#define ICH13_SCALE 372.447449f
#define ICH14_SCALE 372.084015f
#define ICH15_SCALE 372.497498f

#endif
#if Calibration_Index == PMU187
// OFFSET Calibration

#define VCH1_OFFSET 246285
#define VCH2_OFFSET 408650
#define VCH3_OFFSET 658345
                    
#define ICH1_OFFSET 1507313
#define ICH2_OFFSET 1425130
#define ICH3_OFFSET 1442525
#define ICH4_OFFSET 1786878
#define ICH5_OFFSET 1744373
#define ICH6_OFFSET 1707838
#define ICH7_OFFSET 3910138
#define ICH8_OFFSET 820897
#define ICH9_OFFSET 80801
#define ICH10_OFFSET 321503
#define ICH11_OFFSET 1791398
#define ICH12_OFFSET 1454688
#define ICH13_OFFSET 1986832
#define ICH14_OFFSET 1738988
#define ICH15_OFFSET 1801944

//SCALING Calibration
#define VCH1_SCALE 584.009644f
#define VCH2_SCALE 586.063843f
#define VCH3_SCALE 586.297485f

#define ICH1_SCALE 372.976166f
#define ICH2_SCALE 375.465027f
#define ICH3_SCALE 373.090179f
#define ICH4_SCALE 375.169495f
#define ICH5_SCALE 374.135284f
#define ICH6_SCALE 373.998688f
#define ICH7_SCALE 371.678772f
#define ICH8_SCALE 373.533234f
#define ICH9_SCALE 372.227509f
#define ICH10_SCALE 373.698853f
#define ICH11_SCALE 373.704468f
#define ICH12_SCALE 373.17453f
#define ICH13_SCALE 374.085663f
#define ICH14_SCALE 372.459381f
#define ICH15_SCALE 371.372528f

#endif
#if Calibration_Index == PMU188
// OFFSET Calibration

#define VCH1_OFFSET 1272244
#define VCH2_OFFSET 1505611
#define VCH3_OFFSET 1455142
                    
#define ICH1_OFFSET 1540007
#define ICH2_OFFSET 1358025
#define ICH3_OFFSET 1576594
#define ICH4_OFFSET 1526990
#define ICH5_OFFSET 1676317
#define ICH6_OFFSET 1858780
#define ICH7_OFFSET 3461986
#define ICH8_OFFSET 1601080
#define ICH9_OFFSET 72688
#define ICH10_OFFSET 589945
#define ICH11_OFFSET 1513402
#define ICH12_OFFSET 1331043
#define ICH13_OFFSET 1137158
#define ICH14_OFFSET 1424660
#define ICH15_OFFSET 1536067

//SCALING Calibration
#define VCH1_SCALE 586.881653f
#define VCH2_SCALE 589.049011f
#define VCH3_SCALE 586.528259f

#define ICH1_SCALE 375.53714f
#define ICH2_SCALE 374.337799f
#define ICH3_SCALE 374.245728f
#define ICH4_SCALE 372.854797f
#define ICH5_SCALE 374.973572f
#define ICH6_SCALE 374.339294f
#define ICH7_SCALE 371.964661f
#define ICH8_SCALE 372.161469f
#define ICH9_SCALE 372.931732f
#define ICH10_SCALE 371.868652f
#define ICH11_SCALE 373.35556f
#define ICH12_SCALE 373.072113f
#define ICH13_SCALE 375.578064f
#define ICH14_SCALE 373.447998f
#define ICH15_SCALE 374.15155f

#endif
#if Calibration_Index == PMU189
// OFFSET Calibration

#define VCH1_OFFSET 185833
#define VCH2_OFFSET 548736
#define VCH3_OFFSET 642012
                    
#define ICH1_OFFSET 1433027
#define ICH2_OFFSET 1487448
#define ICH3_OFFSET 1395876
#define ICH4_OFFSET 1254556
#define ICH5_OFFSET 1566200
#define ICH6_OFFSET 1268982
#define ICH7_OFFSET 3422030
#define ICH8_OFFSET 708438
#define ICH9_OFFSET 216479
#define ICH10_OFFSET 551086
#define ICH11_OFFSET 1755769
#define ICH12_OFFSET 1471939
#define ICH13_OFFSET 1701757
#define ICH14_OFFSET 1371953
#define ICH15_OFFSET 2082011

//SCALING Calibration
#define VCH1_SCALE 586.50116f
#define VCH2_SCALE 587.266113f
#define VCH3_SCALE 585.373047f

#define ICH1_SCALE 372.092621f
#define ICH2_SCALE 374.157684f
#define ICH3_SCALE 374.1073f
#define ICH4_SCALE 373.845032f
#define ICH5_SCALE 375.773285f
#define ICH6_SCALE 373.926727f
#define ICH7_SCALE 372.256165f
#define ICH8_SCALE 373.867188f
#define ICH9_SCALE 372.24408f
#define ICH10_SCALE 371.257843f
#define ICH11_SCALE 371.432068f
#define ICH12_SCALE 373.231018f
#define ICH13_SCALE 373.287415f
#define ICH14_SCALE 373.249542f
#define ICH15_SCALE 372.31723f

#endif
#if Calibration_Index == PMU190
// OFFSET Calibration

#define VCH1_OFFSET 667946
#define VCH2_OFFSET 1218302
#define VCH3_OFFSET 1097364
                    
#define ICH1_OFFSET 1619532
#define ICH2_OFFSET 1758028
#define ICH3_OFFSET 1704790
#define ICH4_OFFSET 1626835
#define ICH5_OFFSET 1818819
#define ICH6_OFFSET 1746563
#define ICH7_OFFSET 3469372
#define ICH8_OFFSET 1580556
#define ICH9_OFFSET 274836
#define ICH10_OFFSET 193903
#define ICH11_OFFSET 1619649
#define ICH12_OFFSET 1508301
#define ICH13_OFFSET 1635962
#define ICH14_OFFSET 1188333
#define ICH15_OFFSET 2036522

//SCALING Calibration
#define VCH1_SCALE 586.463684f
#define VCH2_SCALE 586.237f
#define VCH3_SCALE 584.833923f

#define ICH1_SCALE 372.239258f
#define ICH2_SCALE 374.204163f
#define ICH3_SCALE 373.282104f
#define ICH4_SCALE 372.862274f
#define ICH5_SCALE 374.315125f
#define ICH6_SCALE 372.204041f
#define ICH7_SCALE 370.477509f
#define ICH8_SCALE 372.940582f
#define ICH9_SCALE 372.431854f
#define ICH10_SCALE 371.9711f
#define ICH11_SCALE 371.157898f
#define ICH12_SCALE 372.53067f
#define ICH13_SCALE 372.305511f
#define ICH14_SCALE 371.65863f
#define ICH15_SCALE 372.543091f

#endif
#if Calibration_Index == PMU191
// OFFSET Calibration

#define VCH1_OFFSET 100265
#define VCH2_OFFSET 331505
#define VCH3_OFFSET 487582
                    
#define ICH1_OFFSET 1618584
#define ICH2_OFFSET 1732196
#define ICH3_OFFSET 1633949
#define ICH4_OFFSET 1497407
#define ICH5_OFFSET 1560264
#define ICH6_OFFSET 1494834
#define ICH7_OFFSET 3429598
#define ICH8_OFFSET 1378942
#define ICH9_OFFSET 84249
#define ICH10_OFFSET 171330
#define ICH11_OFFSET 2024481
#define ICH12_OFFSET 1770781
#define ICH13_OFFSET 1815890
#define ICH14_OFFSET 1533888
#define ICH15_OFFSET 1895494

//SCALING Calibration
#define VCH1_SCALE 587.802979f
#define VCH2_SCALE 584.4422f
#define VCH3_SCALE 587.239014f

#define ICH1_SCALE 374.663757f
#define ICH2_SCALE 374.149353f
#define ICH3_SCALE 373.490479f
#define ICH4_SCALE 372.252991f
#define ICH5_SCALE 372.784271f
#define ICH6_SCALE 373.588928f
#define ICH7_SCALE 370.299377f
#define ICH8_SCALE 371.69574f
#define ICH9_SCALE 371.921692f
#define ICH10_SCALE 372.030334f
#define ICH11_SCALE 372.460663f
#define ICH12_SCALE 374.911835f
#define ICH13_SCALE 374.911835f
#define ICH14_SCALE 374.008881f
#define ICH15_SCALE 373.114471f

#endif
#if Calibration_Index == PMU192
// OFFSET Calibration

#define VCH1_OFFSET 39766
#define VCH2_OFFSET 4931
#define VCH3_OFFSET 324249
                    
#define ICH1_OFFSET 1710167
#define ICH2_OFFSET 1683783
#define ICH3_OFFSET 1343367
#define ICH4_OFFSET 1459733
#define ICH5_OFFSET 1847106
#define ICH6_OFFSET 1597598
#define ICH7_OFFSET 4081841
#define ICH8_OFFSET 1145761
#define ICH9_OFFSET 326326
#define ICH10_OFFSET 511811
#define ICH11_OFFSET 1484419
#define ICH12_OFFSET 1413272
#define ICH13_OFFSET 1521213
#define ICH14_OFFSET 1294849
#define ICH15_OFFSET 1860381

//SCALING Calibration
#define VCH1_SCALE 587.755493f
#define VCH2_SCALE 583.596191f
#define VCH3_SCALE 587.372803f

#define ICH1_SCALE 374.109802f
#define ICH2_SCALE 375.800781f
#define ICH3_SCALE 374.484497f
#define ICH4_SCALE 373.8302f
#define ICH5_SCALE 374.391541f
#define ICH6_SCALE 372.641235f
#define ICH7_SCALE 371.608612f
#define ICH8_SCALE 373.111176f
#define ICH9_SCALE 371.154022f
#define ICH10_SCALE 369.896271f
#define ICH11_SCALE 371.804718f
#define ICH12_SCALE 373.389435f
#define ICH13_SCALE 372.009705f
#define ICH14_SCALE 372.408325f
#define ICH15_SCALE 372.487854f

#endif
#if Calibration_Index == PMU193
// OFFSET Calibration

#define VCH1_OFFSET 311522
#define VCH2_OFFSET 208999
#define VCH3_OFFSET 54321
                    
#define ICH1_OFFSET 1448735
#define ICH2_OFFSET 1507855
#define ICH3_OFFSET 1643227
#define ICH4_OFFSET 1567466
#define ICH5_OFFSET 1374536
#define ICH6_OFFSET 1344776
#define ICH7_OFFSET 3416749
#define ICH8_OFFSET 1532957
#define ICH9_OFFSET 112501
#define ICH10_OFFSET 450186
#define ICH11_OFFSET 1851769
#define ICH12_OFFSET 1564009
#define ICH13_OFFSET 1628785
#define ICH14_OFFSET 1449977
#define ICH15_OFFSET 1742759

//SCALING Calibration
#define VCH1_SCALE 587.224121f
#define VCH2_SCALE 588.853638f
#define VCH3_SCALE 586.986755f

#define ICH1_SCALE 374.985474f
#define ICH2_SCALE 373.379486f
#define ICH3_SCALE 373.917175f
#define ICH4_SCALE 372.165833f
#define ICH5_SCALE 374.09491f
#define ICH6_SCALE 373.96048f
#define ICH7_SCALE 371.361847f
#define ICH8_SCALE 371.6586f
#define ICH9_SCALE 371.869965f
#define ICH10_SCALE 370.786774f
#define ICH11_SCALE 373.201569f
#define ICH12_SCALE 374.667084f
#define ICH13_SCALE 372.56723f
#define ICH14_SCALE 372.912689f
#define ICH15_SCALE 373.074036f

#endif
#if Calibration_Index == PMU194
// OFFSET Calibration

#define VCH1_OFFSET 108808
#define VCH2_OFFSET 479390
#define VCH3_OFFSET 629287
                    
#define ICH1_OFFSET 1433568
#define ICH2_OFFSET 1595387
#define ICH3_OFFSET 1530838
#define ICH4_OFFSET 1608669
#define ICH5_OFFSET 1381606
#define ICH6_OFFSET 1594030
#define ICH7_OFFSET 3964451
#define ICH8_OFFSET 642579
#define ICH9_OFFSET 21529
#define ICH10_OFFSET 271193
#define ICH11_OFFSET 1538477
#define ICH12_OFFSET 1305357
#define ICH13_OFFSET 1408815
#define ICH14_OFFSET 1282273
#define ICH15_OFFSET 1877620

//SCALING Calibration
#define VCH1_SCALE 584.593689f
#define VCH2_SCALE 582.187622f
#define VCH3_SCALE 582.754822f

#define ICH1_SCALE 375.431213f
#define ICH2_SCALE 374.059326f
#define ICH3_SCALE 372.711212f
#define ICH4_SCALE 372.212799f
#define ICH5_SCALE 374.977997f
#define ICH6_SCALE 372.971832f
#define ICH7_SCALE 369.59903f
#define ICH8_SCALE 373.093323f
#define ICH9_SCALE 372.94754f
#define ICH10_SCALE 373.92395f
#define ICH11_SCALE 374.275665f
#define ICH12_SCALE 373.743561f
#define ICH13_SCALE 375.49646f
#define ICH14_SCALE 374.337921f
#define ICH15_SCALE 372.532654f

#endif
#if Calibration_Index == PMU195
// OFFSET Calibration

#define VCH1_OFFSET 203231
#define VCH2_OFFSET 720164
#define VCH3_OFFSET 688242
                    
#define ICH1_OFFSET 1495063
#define ICH2_OFFSET 1413980
#define ICH3_OFFSET 1447660
#define ICH4_OFFSET 1363636
#define ICH5_OFFSET 1476408
#define ICH6_OFFSET 1631488
#define ICH7_OFFSET 4102159
#define ICH8_OFFSET 874346
#define ICH9_OFFSET 306501
#define ICH10_OFFSET 266798
#define ICH11_OFFSET 1449927
#define ICH12_OFFSET 1508110
#define ICH13_OFFSET 1329396
#define ICH14_OFFSET 1340375
#define ICH15_OFFSET 2051055

//SCALING Calibration
#define VCH1_SCALE 586.663452f
#define VCH2_SCALE 588.371582f
#define VCH3_SCALE 583.226624f

#define ICH1_SCALE 374.955811f
#define ICH2_SCALE 373.411316f
#define ICH3_SCALE 374.972809f
#define ICH4_SCALE 372.592041f
#define ICH5_SCALE 373.948334f
#define ICH6_SCALE 373.416107f
#define ICH7_SCALE 371.788696f
#define ICH8_SCALE 372.114166f
#define ICH9_SCALE 371.775482f
#define ICH10_SCALE 371.766144f
#define ICH11_SCALE 372.958344f
#define ICH12_SCALE 374.024872f
#define ICH13_SCALE 373.745575f
#define ICH14_SCALE 373.318115f
#define ICH15_SCALE 372.726807f

#endif
#if Calibration_Index == PMU196
// OFFSET Calibration

#define VCH1_OFFSET 366671
#define VCH2_OFFSET 516640
#define VCH3_OFFSET 671281
                    
#define ICH1_OFFSET 1337629
#define ICH2_OFFSET 1506764
#define ICH3_OFFSET 1590660
#define ICH4_OFFSET 1540510
#define ICH5_OFFSET 1305359
#define ICH6_OFFSET 1536824
#define ICH7_OFFSET 3512808
#define ICH8_OFFSET 948782
#define ICH9_OFFSET 67528
#define ICH10_OFFSET 463193
#define ICH11_OFFSET 1210875
#define ICH12_OFFSET 1321903
#define ICH13_OFFSET 1007743
#define ICH14_OFFSET 1110366
#define ICH15_OFFSET 1486382

//SCALING Calibration
#define VCH1_SCALE 586.84021f
#define VCH2_SCALE 588.359558f
#define VCH3_SCALE 588.043579f

#define ICH1_SCALE 375.950867f
#define ICH2_SCALE 374.258392f
#define ICH3_SCALE 374.561066f
#define ICH4_SCALE 372.937469f
#define ICH5_SCALE 375.989899f
#define ICH6_SCALE 374.675598f
#define ICH7_SCALE 370.246979f
#define ICH8_SCALE 373.186829f
#define ICH9_SCALE 373.024597f
#define ICH10_SCALE 370.797791f
#define ICH11_SCALE 373.229492f
#define ICH12_SCALE 373.804108f
#define ICH13_SCALE 372.588989f
#define ICH14_SCALE 372.775543f
#define ICH15_SCALE 371.235565f

#endif
#if Calibration_Index == PMU197
// OFFSET Calibration

#define VCH1_OFFSET 983023
#define VCH2_OFFSET 1494637
#define VCH3_OFFSET 1429454
                    
#define ICH1_OFFSET 1410418
#define ICH2_OFFSET 1241860
#define ICH3_OFFSET 1423671
#define ICH4_OFFSET 1471002
#define ICH5_OFFSET 1868447
#define ICH6_OFFSET 1569106
#define ICH7_OFFSET 3745813
#define ICH8_OFFSET 760556
#define ICH9_OFFSET 60212
#define ICH10_OFFSET 80972
#define ICH11_OFFSET 1775345
#define ICH12_OFFSET 1611510
#define ICH13_OFFSET 1513784
#define ICH14_OFFSET 1713297
#define ICH15_OFFSET 1992702

//SCALING Calibration
#define VCH1_SCALE 589.38031f
#define VCH2_SCALE 584.357605f
#define VCH3_SCALE 589.129883f

#define ICH1_SCALE 373.301697f
#define ICH2_SCALE 374.602386f
#define ICH3_SCALE 372.907776f
#define ICH4_SCALE 373.59259f
#define ICH5_SCALE 374.089935f
#define ICH6_SCALE 372.270752f
#define ICH7_SCALE 371.174835f
#define ICH8_SCALE 372.680084f
#define ICH9_SCALE 371.715454f
#define ICH10_SCALE 372.844574f
#define ICH11_SCALE 372.925079f
#define ICH12_SCALE 373.757629f
#define ICH13_SCALE 373.388855f
#define ICH14_SCALE 372.586975f
#define ICH15_SCALE 373.109955f

#endif
#if Calibration_Index == PMU198
// OFFSET Calibration

#define VCH1_OFFSET 294929
#define VCH2_OFFSET 590160
#define VCH3_OFFSET 924676
                    
#define ICH1_OFFSET 1773916
#define ICH2_OFFSET 1524398
#define ICH3_OFFSET 1823694
#define ICH4_OFFSET 1497683
#define ICH5_OFFSET 1882360
#define ICH6_OFFSET 1440410
#define ICH7_OFFSET 3148612
#define ICH8_OFFSET 1274558
#define ICH9_OFFSET 66630
#define ICH10_OFFSET 472373
#define ICH11_OFFSET 1551097
#define ICH12_OFFSET 1468018
#define ICH13_OFFSET 1509046
#define ICH14_OFFSET 1173780
#define ICH15_OFFSET 1986076

//SCALING Calibration
#define VCH1_SCALE 585.720154f
#define VCH2_SCALE 584.961792f
#define VCH3_SCALE 587.379761f

#define ICH1_SCALE 374.573547f
#define ICH2_SCALE 375.352966f
#define ICH3_SCALE 373.659363f
#define ICH4_SCALE 373.718658f
#define ICH5_SCALE 374.905579f
#define ICH6_SCALE 372.31958f
#define ICH7_SCALE 371.927368f
#define ICH8_SCALE 372.926147f
#define ICH9_SCALE 370.601563f
#define ICH10_SCALE 370.844666f
#define ICH11_SCALE 370.68515f
#define ICH12_SCALE 371.909943f
#define ICH13_SCALE 371.872833f
#define ICH14_SCALE 372.023529f
#define ICH15_SCALE 372.462738f

#endif
#if Calibration_Index == PMU199
// OFFSET Calibration

#define VCH1_OFFSET 993047
#define VCH2_OFFSET 1335508
#define VCH3_OFFSET 1118397
                    
#define ICH1_OFFSET 1753261
#define ICH2_OFFSET 1510165
#define ICH3_OFFSET 1687918
#define ICH4_OFFSET 1775537
#define ICH5_OFFSET 1528012
#define ICH6_OFFSET 1564034
#define ICH7_OFFSET 3508433
#define ICH8_OFFSET 1372798
#define ICH9_OFFSET 152696
#define ICH10_OFFSET 346344
#define ICH11_OFFSET 1711536
#define ICH12_OFFSET 1721275
#define ICH13_OFFSET 1653245
#define ICH14_OFFSET 1649251
#define ICH15_OFFSET 2026838

//SCALING Calibration
#define VCH1_SCALE 586.516785f
#define VCH2_SCALE 584.374756f
#define VCH3_SCALE 587.483215f

#define ICH1_SCALE 374.644562f
#define ICH2_SCALE 374.558472f
#define ICH3_SCALE 373.08606f
#define ICH4_SCALE 373.091461f
#define ICH5_SCALE 375.455048f
#define ICH6_SCALE 372.851715f
#define ICH7_SCALE 371.309662f
#define ICH8_SCALE 373.234253f
#define ICH9_SCALE 372.47702f
#define ICH10_SCALE 373.394196f
#define ICH11_SCALE 373.497986f
#define ICH12_SCALE 373.841492f
#define ICH13_SCALE 373.680756f
#define ICH14_SCALE 372.274902f
#define ICH15_SCALE 373.170685f

#endif
#if Calibration_Index == PMU200
// OFFSET Calibration

#define VCH1_OFFSET 450220
#define VCH2_OFFSET 696263
#define VCH3_OFFSET 673683
                    
#define ICH1_OFFSET 1609429
#define ICH2_OFFSET 1192151
#define ICH3_OFFSET 1375022
#define ICH4_OFFSET 1449927
#define ICH5_OFFSET 1736205
#define ICH6_OFFSET 1533799
#define ICH7_OFFSET 3683083
#define ICH8_OFFSET 744685
#define ICH9_OFFSET 129678
#define ICH10_OFFSET 599004
#define ICH11_OFFSET 1302348
#define ICH12_OFFSET 1553490
#define ICH13_OFFSET 1305474
#define ICH14_OFFSET 1292112
#define ICH15_OFFSET 1398892

//SCALING Calibration
#define VCH1_SCALE 584.524902f
#define VCH2_SCALE 586.341492f
#define VCH3_SCALE 585.761292f

#define ICH1_SCALE 375.343018f
#define ICH2_SCALE 373.812958f
#define ICH3_SCALE 373.736877f
#define ICH4_SCALE 373.191742f
#define ICH5_SCALE 374.049561f
#define ICH6_SCALE 372.512665f
#define ICH7_SCALE 372.229309f
#define ICH8_SCALE 373.661774f
#define ICH9_SCALE 371.369354f
#define ICH10_SCALE 371.031006f
#define ICH11_SCALE 372.909546f
#define ICH12_SCALE 374.124725f
#define ICH13_SCALE 372.446716f
#define ICH14_SCALE 372.969788f
#define ICH15_SCALE 375.326202f

#endif

#if Calibration_Index == PMU201
// OFFSET Calibration

#define VCH1_OFFSET 620483
#define VCH2_OFFSET 1414264
#define VCH3_OFFSET 1315365
                    
#define ICH1_OFFSET 1361777
#define ICH2_OFFSET 1662163
#define ICH3_OFFSET 1413764
#define ICH4_OFFSET 1193074
#define ICH5_OFFSET 1505227
#define ICH6_OFFSET 1294818
#define ICH7_OFFSET 3754429
#define ICH8_OFFSET 826377
#define ICH9_OFFSET 83337
#define ICH10_OFFSET 154975
#define ICH11_OFFSET 1606519
#define ICH12_OFFSET 1465096
#define ICH13_OFFSET 1393511
#define ICH14_OFFSET 1309166
#define ICH15_OFFSET 2157791

//SCALING Calibration
#define VCH1_SCALE 583.272949f
#define VCH2_SCALE 584.748962f
#define VCH3_SCALE 585.347107f

#define ICH1_SCALE 375.738831f
#define ICH2_SCALE 374.120117f
#define ICH3_SCALE 372.832245f
#define ICH4_SCALE 372.237518f
#define ICH5_SCALE 375.2117f
#define ICH6_SCALE 373.214935f
#define ICH7_SCALE 369.808899f
#define ICH8_SCALE 372.948212f
#define ICH9_SCALE 373.476898f
#define ICH10_SCALE 372.708679f
#define ICH11_SCALE 371.476013f
#define ICH12_SCALE 372.974854f
#define ICH13_SCALE 374.085266f
#define ICH14_SCALE 373.33725f
#define ICH15_SCALE 374.039276f

#endif
#if Calibration_Index == PMU202
// OFFSET Calibration

#define VCH1_OFFSET 358632
#define VCH2_OFFSET 730846
#define VCH3_OFFSET 470741
                    
#define ICH1_OFFSET 1624436
#define ICH2_OFFSET 1510953
#define ICH3_OFFSET 1541108
#define ICH4_OFFSET 1348011
#define ICH5_OFFSET 1421979
#define ICH6_OFFSET 1324441
#define ICH7_OFFSET 3355322
#define ICH8_OFFSET 1221993
#define ICH9_OFFSET 234776
#define ICH10_OFFSET 152199
#define ICH11_OFFSET 2096286
#define ICH12_OFFSET 1742592
#define ICH13_OFFSET 1737097
#define ICH14_OFFSET 1636125
#define ICH15_OFFSET 2224982

//SCALING Calibration
#define VCH1_SCALE 585.790833f
#define VCH2_SCALE 585.38208f
#define VCH3_SCALE 582.58783f

#define ICH1_SCALE 374.54483f
#define ICH2_SCALE 373.308624f
#define ICH3_SCALE 373.356781f
#define ICH4_SCALE 373.24646f
#define ICH5_SCALE 373.746948f
#define ICH6_SCALE 372.790131f
#define ICH7_SCALE 372.919403f
#define ICH8_SCALE 373.527466f
#define ICH9_SCALE 370.598602f
#define ICH10_SCALE 372.662262f
#define ICH11_SCALE 372.642639f
#define ICH12_SCALE 373.767029f
#define ICH13_SCALE 372.712616f
#define ICH14_SCALE 372.627136f
#define ICH15_SCALE 373.625244f

#endif

#if Calibration_Index == PMU203
// OFFSET Calibration

#define VCH1_OFFSET 914388
#define VCH2_OFFSET 1223868
#define VCH3_OFFSET 1449558
                    
#define ICH1_OFFSET 1690008
#define ICH2_OFFSET 1599990
#define ICH3_OFFSET 1465666
#define ICH4_OFFSET 1589616
#define ICH5_OFFSET 1513552
#define ICH6_OFFSET 1504484
#define ICH7_OFFSET 3585747
#define ICH8_OFFSET 1304665
#define ICH9_OFFSET 221422
#define ICH10_OFFSET 664678
#define ICH11_OFFSET 1491650
#define ICH12_OFFSET 1369636
#define ICH13_OFFSET 1220676
#define ICH14_OFFSET 1454547
#define ICH15_OFFSET 1914576

//SCALING Calibration
#define VCH1_SCALE 588.036194f
#define VCH2_SCALE 583.693176f
#define VCH3_SCALE 587.406494f

#define ICH1_SCALE 374.512512f
#define ICH2_SCALE 374.958557f
#define ICH3_SCALE 374.164734f
#define ICH4_SCALE 374.242615f
#define ICH5_SCALE 374.670868f
#define ICH6_SCALE 371.345306f
#define ICH7_SCALE 371.740051f
#define ICH8_SCALE 371.537476f
#define ICH9_SCALE 373.553894f
#define ICH10_SCALE 370.108521f
#define ICH11_SCALE 373.514465f
#define ICH12_SCALE 374.231262f
#define ICH13_SCALE 372.969849f
#define ICH14_SCALE 372.118164f
#define ICH15_SCALE 374.683167f

#endif

#if Calibration_Index == PMU204
// OFFSET Calibration

#define VCH1_OFFSET 303668
#define VCH2_OFFSET 865352
#define VCH3_OFFSET 958041
                    
#define ICH1_OFFSET 1393642
#define ICH2_OFFSET 1259487
#define ICH3_OFFSET 1155141
#define ICH4_OFFSET 1337916
#define ICH5_OFFSET 1383231
#define ICH6_OFFSET 1377038
#define ICH7_OFFSET 3841682
#define ICH8_OFFSET 496198
#define ICH9_OFFSET 67555
#define ICH10_OFFSET 365434
#define ICH11_OFFSET 1754991
#define ICH12_OFFSET 1747068
#define ICH13_OFFSET 1681539
#define ICH14_OFFSET 1361024
#define ICH15_OFFSET 1817913

//SCALING Calibration
#define VCH1_SCALE 583.678467f
#define VCH2_SCALE 584.834961f
#define VCH3_SCALE 585.975403f

#define ICH1_SCALE 373.980896f
#define ICH2_SCALE 372.10675f
#define ICH3_SCALE 373.622498f
#define ICH4_SCALE 373.049713f
#define ICH5_SCALE 374.011353f
#define ICH6_SCALE 372.022339f
#define ICH7_SCALE 372.323242f
#define ICH8_SCALE 373.563385f
#define ICH9_SCALE 370.717468f
#define ICH10_SCALE 372.556793f
#define ICH11_SCALE 371.123657f
#define ICH12_SCALE 373.010437f
#define ICH13_SCALE 372.307343f
#define ICH14_SCALE 371.869751f
#define ICH15_SCALE 370.843567f

#endif

#if Calibration_Index == PMU205
// OFFSET Calibration

#define VCH1_OFFSET 914050
#define VCH2_OFFSET 1145913
#define VCH3_OFFSET 1035273
                    
#define ICH1_OFFSET 1959354
#define ICH2_OFFSET 1600185
#define ICH3_OFFSET 1840475
#define ICH4_OFFSET 1867962
#define ICH5_OFFSET 1941386
#define ICH6_OFFSET 1531764
#define ICH7_OFFSET 3752078
#define ICH8_OFFSET 1065611
#define ICH9_OFFSET 6153
#define ICH10_OFFSET 150678
#define ICH11_OFFSET 1379820
#define ICH12_OFFSET 1753089
#define ICH13_OFFSET 1660585
#define ICH14_OFFSET 1398774
#define ICH15_OFFSET 1799088

//SCALING Calibration
#define VCH1_SCALE 586.171875f
#define VCH2_SCALE 585.565186f
#define VCH3_SCALE 585.49823f

#define ICH1_SCALE 373.55896f
#define ICH2_SCALE 373.033234f
#define ICH3_SCALE 373.34021f
#define ICH4_SCALE 373.518585f
#define ICH5_SCALE 374.944763f
#define ICH6_SCALE 372.786713f
#define ICH7_SCALE 373.458008f
#define ICH8_SCALE 375.013855f
#define ICH9_SCALE 373.390564f
#define ICH10_SCALE 373.497467f
#define ICH11_SCALE 374.634155f
#define ICH12_SCALE 375.401428f
#define ICH13_SCALE 374.518188f
#define ICH14_SCALE 373.397827f
#define ICH15_SCALE 373.516693f

#endif

#if Calibration_Index == PMU206
// OFFSET Calibration

#define VCH1_OFFSET 567482
#define VCH2_OFFSET 884666
#define VCH3_OFFSET 1044041
                    
#define ICH1_OFFSET 1643507
#define ICH2_OFFSET 1681763
#define ICH3_OFFSET 1398841
#define ICH4_OFFSET 1283512
#define ICH5_OFFSET 1336864
#define ICH6_OFFSET 1549903
#define ICH7_OFFSET 3234913
#define ICH8_OFFSET 744561
#define ICH9_OFFSET 27529
#define ICH10_OFFSET 245049
#define ICH11_OFFSET 1919932
#define ICH12_OFFSET 1548657
#define ICH13_OFFSET 1380653
#define ICH14_OFFSET 1567242
#define ICH15_OFFSET 1734753

//SCALING Calibration
#define VCH1_SCALE 585.156494f
#define VCH2_SCALE 586.034241f
#define VCH3_SCALE 581.555542f

#define ICH1_SCALE 375.329559f
#define ICH2_SCALE 372.930573f
#define ICH3_SCALE 374.664978f
#define ICH4_SCALE 371.757202f
#define ICH5_SCALE 374.181763f
#define ICH6_SCALE 373.795746f
#define ICH7_SCALE 372.543213f
#define ICH8_SCALE 372.709381f
#define ICH9_SCALE 371.816315f
#define ICH10_SCALE 374.191956f
#define ICH11_SCALE 373.609497f
#define ICH12_SCALE 374.674927f
#define ICH13_SCALE 374.116608f
#define ICH14_SCALE 373.940399f
#define ICH15_SCALE 374.54071f

#endif

#if Calibration_Index == PMU207
// OFFSET Calibration

#define VCH1_OFFSET 73012
#define VCH2_OFFSET 298822
#define VCH3_OFFSET 39884
                    
#define ICH1_OFFSET 1496884
#define ICH2_OFFSET 1467374
#define ICH3_OFFSET 1641769
#define ICH4_OFFSET 1302501
#define ICH5_OFFSET 1498197
#define ICH6_OFFSET 1553149
#define ICH7_OFFSET 3407535
#define ICH8_OFFSET 1158647
#define ICH9_OFFSET 7289
#define ICH10_OFFSET 254086
#define ICH11_OFFSET 1875260
#define ICH12_OFFSET 1596883
#define ICH13_OFFSET 1462633
#define ICH14_OFFSET 1442327
#define ICH15_OFFSET 1722429

//SCALING Calibration
#define VCH1_SCALE 588.139771f
#define VCH2_SCALE 583.676392f
#define VCH3_SCALE 584.684875f

#define ICH1_SCALE 373.881104f
#define ICH2_SCALE 374.590515f
#define ICH3_SCALE 375.22168f
#define ICH4_SCALE 374.077698f
#define ICH5_SCALE 374.867676f
#define ICH6_SCALE 373.546051f
#define ICH7_SCALE 373.23288f
#define ICH8_SCALE 373.207611f
#define ICH9_SCALE 371.004425f
#define ICH10_SCALE 374.005127f
#define ICH11_SCALE 373.469696f
#define ICH12_SCALE 373.272278f
#define ICH13_SCALE 373.445618f
#define ICH14_SCALE 372.096619f
#define ICH15_SCALE 373.350159f

#endif

#if Calibration_Index == PMU208
// OFFSET Calibration

#define VCH1_OFFSET 530104
#define VCH2_OFFSET 579482
#define VCH3_OFFSET 600805
                    
#define ICH1_OFFSET 1297335
#define ICH2_OFFSET 1688439
#define ICH3_OFFSET 1383844
#define ICH4_OFFSET 1324978
#define ICH5_OFFSET 1471957
#define ICH6_OFFSET 1595762
#define ICH7_OFFSET 3845634
#define ICH8_OFFSET 595329
#define ICH9_OFFSET 227500
#define ICH10_OFFSET 379606
#define ICH11_OFFSET 1498308
#define ICH12_OFFSET 1506717
#define ICH13_OFFSET 1369459
#define ICH14_OFFSET 1279964
#define ICH15_OFFSET 1839634

//SCALING Calibration
#define VCH1_SCALE 589.487183f
#define VCH2_SCALE 584.655457f
#define VCH3_SCALE 584.76416f

#define ICH1_SCALE 373.179108f
#define ICH2_SCALE 373.631104f
#define ICH3_SCALE 373.667633f
#define ICH4_SCALE 373.490387f
#define ICH5_SCALE 374.442139f
#define ICH6_SCALE 372.963165f
#define ICH7_SCALE 371.693787f
#define ICH8_SCALE 372.484711f
#define ICH9_SCALE 373.217987f
#define ICH10_SCALE 372.753662f
#define ICH11_SCALE 371.59491f
#define ICH12_SCALE 372.798248f
#define ICH13_SCALE 374.085205f
#define ICH14_SCALE 373.608826f
#define ICH15_SCALE 374.294708f

#endif

#if Calibration_Index == PMU209
// OFFSET Calibration

#define VCH1_OFFSET 280028
#define VCH2_OFFSET 451834
#define VCH3_OFFSET 815907
                    
#define ICH1_OFFSET 1426922
#define ICH2_OFFSET 1153714
#define ICH3_OFFSET 1474916
#define ICH4_OFFSET 1421650
#define ICH5_OFFSET 1687463
#define ICH6_OFFSET 1446016
#define ICH7_OFFSET 3498911
#define ICH8_OFFSET 1335310
#define ICH9_OFFSET 170511
#define ICH10_OFFSET 517036
#define ICH11_OFFSET 1785237
#define ICH12_OFFSET 1631090
#define ICH13_OFFSET 1446151
#define ICH14_OFFSET 1466018
#define ICH15_OFFSET 1903485

//SCALING Calibration
#define VCH1_SCALE 584.777588f
#define VCH2_SCALE 586.942749f
#define VCH3_SCALE 587.436096f

#define ICH1_SCALE 374.687347f
#define ICH2_SCALE 376.187958f
#define ICH3_SCALE 374.014069f
#define ICH4_SCALE 373.10141f
#define ICH5_SCALE 376.32135f
#define ICH6_SCALE 373.692108f
#define ICH7_SCALE 371.885803f
#define ICH8_SCALE 374.383179f
#define ICH9_SCALE 373.65213f
#define ICH10_SCALE 371.433105f
#define ICH11_SCALE 372.845154f
#define ICH12_SCALE 373.448151f
#define ICH13_SCALE 373.718231f
#define ICH14_SCALE 373.134125f
#define ICH15_SCALE 373.590424f

#endif

#if Calibration_Index == PMU210
// OFFSET Calibration

#define VCH1_OFFSET 194904
#define VCH2_OFFSET 533039
#define VCH3_OFFSET 528260
                    
#define ICH1_OFFSET 1409147
#define ICH2_OFFSET 1339473
#define ICH3_OFFSET 1556656
#define ICH4_OFFSET 1228678
#define ICH5_OFFSET 1491817
#define ICH6_OFFSET 1450298
#define ICH7_OFFSET 3849450
#define ICH8_OFFSET 671705
#define ICH9_OFFSET 916077
#define ICH10_OFFSET 689287
#define ICH11_OFFSET 1274943
#define ICH12_OFFSET 1006357
#define ICH13_OFFSET 1134831
#define ICH14_OFFSET 1206238
#define ICH15_OFFSET 1552792

//SCALING Calibration
#define VCH1_SCALE 587.680786f
#define VCH2_SCALE 584.350037f
#define VCH3_SCALE 589.515198f

#define ICH1_SCALE 372.402802f
#define ICH2_SCALE 372.424652f
#define ICH3_SCALE 371.420013f
#define ICH4_SCALE 373.090332f
#define ICH5_SCALE 373.69458f
#define ICH6_SCALE 371.862823f
#define ICH7_SCALE 368.424286f
#define ICH8_SCALE 370.521698f
#define ICH9_SCALE 369.468536f
#define ICH10_SCALE 368.912598f
#define ICH11_SCALE 372.41095f
#define ICH12_SCALE 371.033783f
#define ICH13_SCALE 374.313995f
#define ICH14_SCALE 372.378387f
#define ICH15_SCALE 373.006012f

#endif

#if Calibration_Index == PMU211
// OFFSET Calibration

#define VCH1_OFFSET 757984
#define VCH2_OFFSET 1165311
#define VCH3_OFFSET 1378597
                    
#define ICH1_OFFSET 1652411
#define ICH2_OFFSET 1520254
#define ICH3_OFFSET 1730134
#define ICH4_OFFSET 1300054
#define ICH5_OFFSET 1538691
#define ICH6_OFFSET 1452201
#define ICH7_OFFSET 3827783
#define ICH8_OFFSET 972757
#define ICH9_OFFSET 1113942
#define ICH10_OFFSET -1341806
#define ICH11_OFFSET 1016373
#define ICH12_OFFSET 886066
#define ICH13_OFFSET 866881
#define ICH14_OFFSET 711865
#define ICH15_OFFSET 1481199

//SCALING Calibration
#define VCH1_SCALE 588.545776f
#define VCH2_SCALE 587.375549f
#define VCH3_SCALE 585.749268f

#define ICH1_SCALE 371.964569f
#define ICH2_SCALE 374.010742f
#define ICH3_SCALE 373.542664f
#define ICH4_SCALE 374.370148f
#define ICH5_SCALE 373.801575f
#define ICH6_SCALE 371.815308f
#define ICH7_SCALE 371.156525f
#define ICH8_SCALE 371.245758f
#define ICH9_SCALE 362.682617f
#define ICH10_SCALE 372.10083f
#define ICH11_SCALE 372.172852f
#define ICH12_SCALE 372.191925f
#define ICH13_SCALE 374.013519f
#define ICH14_SCALE 372.227722f
#define ICH15_SCALE 372.424774f

#endif

#if Calibration_Index == PMU212
// OFFSET Calibration

#define VCH1_OFFSET 167578
#define VCH2_OFFSET 71183
#define VCH3_OFFSET 358018
                    
#define ICH1_OFFSET 1514965
#define ICH2_OFFSET 1519301
#define ICH3_OFFSET 1380349
#define ICH4_OFFSET 1267328
#define ICH5_OFFSET 1150621
#define ICH6_OFFSET 1223578
#define ICH7_OFFSET 3690332
#define ICH8_OFFSET 598976
#define ICH9_OFFSET 298473
#define ICH10_OFFSET 390495
#define ICH11_OFFSET 1519740
#define ICH12_OFFSET 1503392
#define ICH13_OFFSET 1566218
#define ICH14_OFFSET 1262824
#define ICH15_OFFSET 1890056

//SCALING Calibration
#define VCH1_SCALE 588.722046f
#define VCH2_SCALE 586.182373f
#define VCH3_SCALE 585.557007f

#define ICH1_SCALE 372.945282f
#define ICH2_SCALE 373.648834f
#define ICH3_SCALE 374.380066f
#define ICH4_SCALE 373.193665f
#define ICH5_SCALE 374.788818f
#define ICH6_SCALE 373.084412f
#define ICH7_SCALE 371.276062f
#define ICH8_SCALE 372.269043f
#define ICH9_SCALE 374.379425f
#define ICH10_SCALE 371.88739f
#define ICH11_SCALE 373.226624f
#define ICH12_SCALE 372.572693f
#define ICH13_SCALE 373.710632f
#define ICH14_SCALE 373.688171f
#define ICH15_SCALE 374.378479f

#endif

#if Calibration_Index == PMU213
// OFFSET Calibration

#define VCH1_OFFSET 758398
#define VCH2_OFFSET 1304260
#define VCH3_OFFSET 1289913
                    
#define ICH1_OFFSET 1390314
#define ICH2_OFFSET 1282883
#define ICH3_OFFSET 1364286
#define ICH4_OFFSET 1293076
#define ICH5_OFFSET 1434510
#define ICH6_OFFSET 1320647
#define ICH7_OFFSET 3262636
#define ICH8_OFFSET 869603
#define ICH9_OFFSET 69776
#define ICH10_OFFSET 180329
#define ICH11_OFFSET 1556251
#define ICH12_OFFSET 1655587
#define ICH13_OFFSET 1759367
#define ICH14_OFFSET 1717367
#define ICH15_OFFSET 1789791

//SCALING Calibration
#define VCH1_SCALE 588.074097f
#define VCH2_SCALE 585.776672f
#define VCH3_SCALE 585.822998f

#define ICH1_SCALE 372.947449f
#define ICH2_SCALE 375.493378f
#define ICH3_SCALE 373.905426f
#define ICH4_SCALE 373.292877f
#define ICH5_SCALE 373.400726f
#define ICH6_SCALE 373.337433f
#define ICH7_SCALE 372.308136f
#define ICH8_SCALE 372.999603f
#define ICH9_SCALE 371.546326f
#define ICH10_SCALE 374.118866f
#define ICH11_SCALE 373.290466f
#define ICH12_SCALE 374.808472f
#define ICH13_SCALE 374.541931f
#define ICH14_SCALE 374.166077f
#define ICH15_SCALE 373.631073f

#endif

#if Calibration_Index == PMU214
// OFFSET Calibration

#define VCH1_OFFSET 457765
#define VCH2_OFFSET 880913
#define VCH3_OFFSET 550315
                    
#define ICH1_OFFSET 1628659
#define ICH2_OFFSET 1574232
#define ICH3_OFFSET 1654836
#define ICH4_OFFSET 1388257
#define ICH5_OFFSET 1571051
#define ICH6_OFFSET 1663958
#define ICH7_OFFSET 3692334
#define ICH8_OFFSET 752490
#define ICH9_OFFSET 16226
#define ICH10_OFFSET 268731
#define ICH11_OFFSET 1642679
#define ICH12_OFFSET 1609463
#define ICH13_OFFSET 1516696
#define ICH14_OFFSET 1523861
#define ICH15_OFFSET 1880811

//SCALING Calibration
#define VCH1_SCALE 585.305664f
#define VCH2_SCALE 583.305664f
#define VCH3_SCALE 587.100586f

#define ICH1_SCALE 374.542999f
#define ICH2_SCALE 373.861755f
#define ICH3_SCALE 373.49408f
#define ICH4_SCALE 370.893005f
#define ICH5_SCALE 374.007385f
#define ICH6_SCALE 373.998291f
#define ICH7_SCALE 369.701019f
#define ICH8_SCALE 371.434601f
#define ICH9_SCALE 372.742157f
#define ICH10_SCALE 372.3685f
#define ICH11_SCALE 374.173065f
#define ICH12_SCALE 375.152557f
#define ICH13_SCALE 374.161346f
#define ICH14_SCALE 374.209137f
#define ICH15_SCALE 374.583557f

#endif

#if Calibration_Index == PMU215
// OFFSET Calibration

#define VCH1_OFFSET 302312
#define VCH2_OFFSET 761162
#define VCH3_OFFSET 585238
                    
#define ICH1_OFFSET 1704200
#define ICH2_OFFSET 1649925
#define ICH3_OFFSET 1520845
#define ICH4_OFFSET 1454124
#define ICH5_OFFSET 1581073
#define ICH6_OFFSET 1669251
#define ICH7_OFFSET 3830335
#define ICH8_OFFSET 1204585
#define ICH9_OFFSET 353484
#define ICH10_OFFSET 183393
#define ICH11_OFFSET 2020471
#define ICH12_OFFSET 1729729
#define ICH13_OFFSET 1835246
#define ICH14_OFFSET 1666447
#define ICH15_OFFSET 2070327

//SCALING Calibration
#define VCH1_SCALE 588.54657f
#define VCH2_SCALE 585.900879f
#define VCH3_SCALE 590.782898f

#define ICH1_SCALE 372.828461f
#define ICH2_SCALE 372.217926f
#define ICH3_SCALE 372.732758f
#define ICH4_SCALE 373.613312f
#define ICH5_SCALE 372.238586f
#define ICH6_SCALE 373.332825f
#define ICH7_SCALE 369.765839f
#define ICH8_SCALE 373.346558f
#define ICH9_SCALE 371.740967f
#define ICH10_SCALE 372.671356f
#define ICH11_SCALE 372.825745f
#define ICH12_SCALE 375.451508f
#define ICH13_SCALE 374.437195f
#define ICH14_SCALE 373.297882f
#define ICH15_SCALE 373.42688f

#endif

#if Calibration_Index == PMU216
// OFFSET Calibration

#define VCH1_OFFSET 433526
#define VCH2_OFFSET 347457
#define VCH3_OFFSET 621752
                    
#define ICH1_OFFSET 1907708
#define ICH2_OFFSET 1872091
#define ICH3_OFFSET 1759240
#define ICH4_OFFSET 1452287
#define ICH5_OFFSET 1602593
#define ICH6_OFFSET 1723237
#define ICH7_OFFSET 3651953
#define ICH8_OFFSET 1244763
#define ICH9_OFFSET 95275
#define ICH10_OFFSET 334483
#define ICH11_OFFSET 1680121
#define ICH12_OFFSET 1793139
#define ICH13_OFFSET 1560115
#define ICH14_OFFSET 2049020
#define ICH15_OFFSET 2308349

//SCALING Calibration
#define VCH1_SCALE 585.765991f
#define VCH2_SCALE 587.440002f
#define VCH3_SCALE 583.236938f

#define ICH1_SCALE 375.153473f
#define ICH2_SCALE 374.26355f
#define ICH3_SCALE 374.720886f
#define ICH4_SCALE 372.605835f
#define ICH5_SCALE 373.576447f
#define ICH6_SCALE 373.051117f
#define ICH7_SCALE 372.352905f
#define ICH8_SCALE 373.770264f
#define ICH9_SCALE 371.873108f
#define ICH10_SCALE 373.338379f
#define ICH11_SCALE 373.87323f
#define ICH12_SCALE 374.937439f
#define ICH13_SCALE 373.960388f
#define ICH14_SCALE 374.255157f
#define ICH15_SCALE 373.635925f

#endif

#if Calibration_Index == PMU217
// OFFSET Calibration

#define VCH1_OFFSET 880634
#define VCH2_OFFSET 805695
#define VCH3_OFFSET 889368
                    
#define ICH1_OFFSET 1836087
#define ICH2_OFFSET 1953215
#define ICH3_OFFSET 1515055
#define ICH4_OFFSET 1841040
#define ICH5_OFFSET 1734170
#define ICH6_OFFSET 1514388
#define ICH7_OFFSET 3542702
#define ICH8_OFFSET 1150845
#define ICH9_OFFSET 38688
#define ICH10_OFFSET 47401
#define ICH11_OFFSET 1863068
#define ICH12_OFFSET 1886038
#define ICH13_OFFSET 1865605
#define ICH14_OFFSET 1482419
#define ICH15_OFFSET 2080352

//SCALING Calibration
#define VCH1_SCALE 586.802612f
#define VCH2_SCALE 588.948914f
#define VCH3_SCALE 585.929443f

#define ICH1_SCALE 374.373169f
#define ICH2_SCALE 370.569977f
#define ICH3_SCALE 374.385193f
#define ICH4_SCALE 371.585541f
#define ICH5_SCALE 373.071289f
#define ICH6_SCALE 373.757446f
#define ICH7_SCALE 369.822418f
#define ICH8_SCALE 371.237549f
#define ICH9_SCALE 371.620575f
#define ICH10_SCALE 372.671448f
#define ICH11_SCALE 372.11792f
#define ICH12_SCALE 373.262054f
#define ICH13_SCALE 372.933289f
#define ICH14_SCALE 372.110718f
#define ICH15_SCALE 371.721771f

#endif

#if Calibration_Index == PMU218
// OFFSET Calibration

#define VCH1_OFFSET 527803
#define VCH2_OFFSET 46070
#define VCH3_OFFSET 190384
                    
#define ICH1_OFFSET 1416533
#define ICH2_OFFSET 1799475
#define ICH3_OFFSET 1736009
#define ICH4_OFFSET 1380590
#define ICH5_OFFSET 1686912
#define ICH6_OFFSET 1841560
#define ICH7_OFFSET 3479151
#define ICH8_OFFSET 1168226
#define ICH9_OFFSET 58050
#define ICH10_OFFSET 58856
#define ICH11_OFFSET 1714569
#define ICH12_OFFSET 1281254
#define ICH13_OFFSET 1387119
#define ICH14_OFFSET 1460200
#define ICH15_OFFSET 2123781

//SCALING Calibration
#define VCH1_SCALE 585.231689f
#define VCH2_SCALE 587.284668f
#define VCH3_SCALE 587.509827f

#define ICH1_SCALE 375.868195f
#define ICH2_SCALE 374.347321f
#define ICH3_SCALE 372.722046f
#define ICH4_SCALE 373.17041f
#define ICH5_SCALE 374.379059f
#define ICH6_SCALE 373.700104f
#define ICH7_SCALE 371.856567f
#define ICH8_SCALE 373.112213f
#define ICH9_SCALE 372.147247f
#define ICH10_SCALE 373.015564f
#define ICH11_SCALE 373.784943f
#define ICH12_SCALE 373.890472f
#define ICH13_SCALE 373.393341f
#define ICH14_SCALE 372.462433f
#define ICH15_SCALE 371.874695f

#endif

#if Calibration_Index == PMU219
// OFFSET Calibration

#define VCH1_OFFSET 343686
#define VCH2_OFFSET 708011
#define VCH3_OFFSET 930265
                    
#define ICH1_OFFSET 1894386
#define ICH2_OFFSET 1597570
#define ICH3_OFFSET 1448422
#define ICH4_OFFSET 1466389
#define ICH5_OFFSET 1715888
#define ICH6_OFFSET 1645897
#define ICH7_OFFSET 4227830
#define ICH8_OFFSET 705455
#define ICH9_OFFSET 493973
#define ICH10_OFFSET 386954
#define ICH11_OFFSET 2251985
#define ICH12_OFFSET 2078501
#define ICH13_OFFSET 2157559
#define ICH14_OFFSET 2187555
#define ICH15_OFFSET 2559523

//SCALING Calibration
#define VCH1_SCALE 586.205444f
#define VCH2_SCALE 588.476379f
#define VCH3_SCALE 582.676514f

#define ICH1_SCALE 374.806335f
#define ICH2_SCALE 373.509003f
#define ICH3_SCALE 375.276825f
#define ICH4_SCALE 373.230927f
#define ICH5_SCALE 374.069611f
#define ICH6_SCALE 374.458405f
#define ICH7_SCALE 369.689484f
#define ICH8_SCALE 372.4552f
#define ICH9_SCALE 370.196869f
#define ICH10_SCALE 371.280273f
#define ICH11_SCALE 371.856293f
#define ICH12_SCALE 373.31842f
#define ICH13_SCALE 372.841431f
#define ICH14_SCALE 371.957062f
#define ICH15_SCALE 370.808289f

#endif

#if Calibration_Index == PMU220
// OFFSET Calibration

#define VCH1_OFFSET 1129445
#define VCH2_OFFSET 1533696
#define VCH3_OFFSET 1834952
                    
#define ICH1_OFFSET 1628121
#define ICH2_OFFSET 1706784
#define ICH3_OFFSET 1568346
#define ICH4_OFFSET 1564921
#define ICH5_OFFSET 1647318
#define ICH6_OFFSET 1366195
#define ICH7_OFFSET 3403347
#define ICH8_OFFSET 1169170
#define ICH9_OFFSET 89594
#define ICH10_OFFSET 219015
#define ICH11_OFFSET 1459781
#define ICH12_OFFSET 1660268
#define ICH13_OFFSET 1728014
#define ICH14_OFFSET 1714213
#define ICH15_OFFSET 1927675

//SCALING Calibration
#define VCH1_SCALE 585.373596f
#define VCH2_SCALE 586.391235f
#define VCH3_SCALE 581.747986f

#define ICH1_SCALE 373.434021f
#define ICH2_SCALE 373.38147f
#define ICH3_SCALE 374.690033f
#define ICH4_SCALE 372.281769f
#define ICH5_SCALE 373.638123f
#define ICH6_SCALE 373.679291f
#define ICH7_SCALE 373.361298f
#define ICH8_SCALE 370.870331f
#define ICH9_SCALE 371.398865f
#define ICH10_SCALE 374.403534f
#define ICH11_SCALE 373.15451f
#define ICH12_SCALE 373.402191f
#define ICH13_SCALE 373.471252f
#define ICH14_SCALE 373.038727f
#define ICH15_SCALE 373.999756f

#endif

#if Calibration_Index == PMU221
// OFFSET Calibration

#define VCH1_OFFSET 333257
#define VCH2_OFFSET 791402
#define VCH3_OFFSET 807736
                    
#define ICH1_OFFSET 1478850
#define ICH2_OFFSET 1650320
#define ICH3_OFFSET 1651050
#define ICH4_OFFSET 1338199
#define ICH5_OFFSET 1690478
#define ICH6_OFFSET 1429385
#define ICH7_OFFSET 3887567
#define ICH8_OFFSET 457799
#define ICH9_OFFSET 219688
#define ICH10_OFFSET 341694
#define ICH11_OFFSET 1625676
#define ICH12_OFFSET 1636001
#define ICH13_OFFSET 1643150
#define ICH14_OFFSET 1741492
#define ICH15_OFFSET 1860536

//SCALING Calibration
#define VCH1_SCALE 588.146179f
#define VCH2_SCALE 589.721863f
#define VCH3_SCALE 588.625854f

#define ICH1_SCALE 374.645111f
#define ICH2_SCALE 372.465332f
#define ICH3_SCALE 372.465332f
#define ICH4_SCALE 372.377289f
#define ICH5_SCALE 374.129974f
#define ICH6_SCALE 373.84375f
#define ICH7_SCALE 369.39447f
#define ICH8_SCALE 372.672455f
#define ICH9_SCALE 373.173065f
#define ICH10_SCALE 373.735138f
#define ICH11_SCALE 373.941467f
#define ICH12_SCALE 373.270782f
#define ICH13_SCALE 373.87384f
#define ICH14_SCALE 373.097137f
#define ICH15_SCALE 374.042114f

#endif

#if Calibration_Index == PMU222
// OFFSET Calibration

#define VCH1_OFFSET 890036
#define VCH2_OFFSET 873605
#define VCH3_OFFSET 974892
                    
#define ICH1_OFFSET 1630415
#define ICH2_OFFSET 1489858
#define ICH3_OFFSET 1589469
#define ICH4_OFFSET 1380428
#define ICH5_OFFSET 1470192
#define ICH6_OFFSET 1537264
#define ICH7_OFFSET 3737656
#define ICH8_OFFSET 803577
#define ICH9_OFFSET 77682
#define ICH10_OFFSET 339340
#define ICH11_OFFSET 1499734
#define ICH12_OFFSET 1491319
#define ICH13_OFFSET 1567436
#define ICH14_OFFSET 1832336
#define ICH15_OFFSET 1867418

//SCALING Calibration
#define VCH1_SCALE 588.786194f
#define VCH2_SCALE 586.953491f
#define VCH3_SCALE 588.830933f

#define ICH1_SCALE 375.496277f
#define ICH2_SCALE 374.734528f
#define ICH3_SCALE 373.369537f
#define ICH4_SCALE 372.74411f
#define ICH5_SCALE 374.992676f
#define ICH6_SCALE 373.735687f
#define ICH7_SCALE 370.307251f
#define ICH8_SCALE 374.406677f
#define ICH9_SCALE 373.057526f
#define ICH10_SCALE 371.994659f
#define ICH11_SCALE 371.338898f
#define ICH12_SCALE 373.238434f
#define ICH13_SCALE 373.590332f
#define ICH14_SCALE 372.105896f
#define ICH15_SCALE 372.923248f

#endif

#if Calibration_Index == PMU223
// OFFSET Calibration

#define VCH1_OFFSET 376165
#define VCH2_OFFSET 87874
#define VCH3_OFFSET 52428
                    
#define ICH1_OFFSET 1425080
#define ICH2_OFFSET 1475206
#define ICH3_OFFSET 1669868
#define ICH4_OFFSET 1602035
#define ICH5_OFFSET 1490913
#define ICH6_OFFSET 1488637
#define ICH7_OFFSET 4121234
#define ICH8_OFFSET 559693
#define ICH9_OFFSET 748109
#define ICH10_OFFSET 208735
#define ICH11_OFFSET 1511375
#define ICH12_OFFSET 1342704
#define ICH13_OFFSET 1306699
#define ICH14_OFFSET 1366486
#define ICH15_OFFSET 1906336

//SCALING Calibration
#define VCH1_SCALE 585.421814f
#define VCH2_SCALE 582.065918f
#define VCH3_SCALE 583.32135f

#define ICH1_SCALE 374.619598f
#define ICH2_SCALE 373.413177f
#define ICH3_SCALE 373.668213f
#define ICH4_SCALE 373.345856f
#define ICH5_SCALE 373.81601f
#define ICH6_SCALE 373.126862f
#define ICH7_SCALE 371.633423f
#define ICH8_SCALE 372.712982f
#define ICH9_SCALE 369.840973f
#define ICH10_SCALE 373.758179f
#define ICH11_SCALE 372.660309f
#define ICH12_SCALE 372.523773f
#define ICH13_SCALE 372.952301f
#define ICH14_SCALE 373.285156f
#define ICH15_SCALE 372.822418f

#endif

#if Calibration_Index == PMU224
// OFFSET Calibration

#define VCH1_OFFSET 724638
#define VCH2_OFFSET 873580
#define VCH3_OFFSET 1124370
                    
#define ICH1_OFFSET 1708464
#define ICH2_OFFSET 1401058
#define ICH3_OFFSET 1547139
#define ICH4_OFFSET 1520041
#define ICH5_OFFSET 1464250
#define ICH6_OFFSET 1316529
#define ICH7_OFFSET 3887973
#define ICH8_OFFSET 997483
#define ICH9_OFFSET 284292
#define ICH10_OFFSET 325771
#define ICH11_OFFSET 1823071
#define ICH12_OFFSET 1421994
#define ICH13_OFFSET 1506359
#define ICH14_OFFSET 1771335
#define ICH15_OFFSET 2274200

//SCALING Calibration
#define VCH1_SCALE 585.604187f
#define VCH2_SCALE 584.382874f
#define VCH3_SCALE 586.82074f

#define ICH1_SCALE 373.834991f
#define ICH2_SCALE 374.271515f
#define ICH3_SCALE 373.891235f
#define ICH4_SCALE 372.713654f
#define ICH5_SCALE 374.691315f
#define ICH6_SCALE 373.528168f
#define ICH7_SCALE 370.26767f
#define ICH8_SCALE 371.616058f
#define ICH9_SCALE 372.220001f
#define ICH10_SCALE 370.977142f
#define ICH11_SCALE 372.523438f
#define ICH12_SCALE 374.455444f
#define ICH13_SCALE 372.42865f
#define ICH14_SCALE 373.15033f
#define ICH15_SCALE 373.839905f

#endif

#if Calibration_Index == PMU225
// OFFSET Calibration

#define VCH1_OFFSET 1225714
#define VCH2_OFFSET 1452026
#define VCH3_OFFSET 1593508
                    
#define ICH1_OFFSET 1829673
#define ICH2_OFFSET 1709516
#define ICH3_OFFSET 1768990
#define ICH4_OFFSET 1646696
#define ICH5_OFFSET 1872837
#define ICH6_OFFSET 1677096
#define ICH7_OFFSET 3527220
#define ICH8_OFFSET 1188075
#define ICH9_OFFSET 524343
#define ICH10_OFFSET -163731
#define ICH11_OFFSET 1686063
#define ICH12_OFFSET 1594446
#define ICH13_OFFSET 1568191
#define ICH14_OFFSET 1739144
#define ICH15_OFFSET 2021919

//SCALING Calibration
#define VCH1_SCALE 586.917297f
#define VCH2_SCALE 585.651917f
#define VCH3_SCALE 584.80896f

#define ICH1_SCALE 374.696564f
#define ICH2_SCALE 374.510895f
#define ICH3_SCALE 373.989136f
#define ICH4_SCALE 373.60675f
#define ICH5_SCALE 374.385193f
#define ICH6_SCALE 374.2966f
#define ICH7_SCALE 372.988556f
#define ICH8_SCALE 373.613708f
#define ICH9_SCALE 372.199432f
#define ICH10_SCALE 373.652283f
#define ICH11_SCALE 372.846252f
#define ICH12_SCALE 373.592194f
#define ICH13_SCALE 372.218536f
#define ICH14_SCALE 372.68219f
#define ICH15_SCALE 372.693939f

#endif

#if Calibration_Index == PMU226
// OFFSET Calibration

#define VCH1_OFFSET 941949
#define VCH2_OFFSET 1244539
#define VCH3_OFFSET 1254311
                    
#define ICH1_OFFSET 1937499
#define ICH2_OFFSET 1542490
#define ICH3_OFFSET 1903332
#define ICH4_OFFSET 1808926
#define ICH5_OFFSET 1777302
#define ICH6_OFFSET 1784200
#define ICH7_OFFSET 3886413
#define ICH8_OFFSET 1260732
#define ICH9_OFFSET 70529
#define ICH10_OFFSET 179258
#define ICH11_OFFSET 1433742
#define ICH12_OFFSET 1608820
#define ICH13_OFFSET 1378388
#define ICH14_OFFSET 1406234
#define ICH15_OFFSET 1724795

//SCALING Calibration
#define VCH1_SCALE 584.486328f
#define VCH2_SCALE 586.415771f
#define VCH3_SCALE 586.371399f

#define ICH1_SCALE 374.683319f
#define ICH2_SCALE 374.463593f
#define ICH3_SCALE 373.161255f
#define ICH4_SCALE 372.479462f
#define ICH5_SCALE 374.206604f
#define ICH6_SCALE 372.402008f
#define ICH7_SCALE 369.290619f
#define ICH8_SCALE 372.265381f
#define ICH9_SCALE 373.3992f
#define ICH10_SCALE 372.803528f
#define ICH11_SCALE 371.076477f
#define ICH12_SCALE 370.719086f
#define ICH13_SCALE 374.406982f
#define ICH14_SCALE 371.850464f
#define ICH15_SCALE 371.781067f

#endif

#if Calibration_Index == PMU227
// OFFSET Calibration

#define VCH1_OFFSET 1022391
#define VCH2_OFFSET 888631
#define VCH3_OFFSET 1009947
                    
#define ICH1_OFFSET 1457126
#define ICH2_OFFSET 1366739
#define ICH3_OFFSET 1547398
#define ICH4_OFFSET 1697235
#define ICH5_OFFSET 1630693
#define ICH6_OFFSET 1113816
#define ICH7_OFFSET 3544542
#define ICH8_OFFSET 961181
#define ICH9_OFFSET 34384
#define ICH10_OFFSET 339351
#define ICH11_OFFSET 1430202
#define ICH12_OFFSET 1288361
#define ICH13_OFFSET 1452071
#define ICH14_OFFSET 1511021
#define ICH15_OFFSET 1767137

//SCALING Calibration
#define VCH1_SCALE 587.443481f
#define VCH2_SCALE 588.380981f
#define VCH3_SCALE 586.076904f

#define ICH1_SCALE 374.103882f
#define ICH2_SCALE 373.315613f
#define ICH3_SCALE 374.438721f
#define ICH4_SCALE 372.291992f
#define ICH5_SCALE 373.002808f
#define ICH6_SCALE 373.708221f
#define ICH7_SCALE 370.781738f
#define ICH8_SCALE 372.390564f
#define ICH9_SCALE 374.542908f
#define ICH10_SCALE 372.750458f
#define ICH11_SCALE 374.346985f
#define ICH12_SCALE 374.306885f
#define ICH13_SCALE 373.75412f
#define ICH14_SCALE 373.297607f
#define ICH15_SCALE 373.020386f

#endif

#if Calibration_Index == PMU228
// OFFSET Calibration

#define VCH1_OFFSET 986573
#define VCH2_OFFSET 1183477
#define VCH3_OFFSET 1332424
                    
#define ICH1_OFFSET 1554576
#define ICH2_OFFSET 1636850
#define ICH3_OFFSET 1511421
#define ICH4_OFFSET 1421151
#define ICH5_OFFSET 1712275
#define ICH6_OFFSET 1673527
#define ICH7_OFFSET 3411895
#define ICH8_OFFSET 1267050
#define ICH9_OFFSET 157930
#define ICH10_OFFSET 32284
#define ICH11_OFFSET 1710980
#define ICH12_OFFSET 1481652
#define ICH13_OFFSET 1605330
#define ICH14_OFFSET 1845032
#define ICH15_OFFSET 1962844

//SCALING Calibration
#define VCH1_SCALE 586.48175f
#define VCH2_SCALE 587.726074f
#define VCH3_SCALE 588.43219f

#define ICH1_SCALE 375.313751f
#define ICH2_SCALE 374.104584f
#define ICH3_SCALE 374.509735f
#define ICH4_SCALE 374.009247f
#define ICH5_SCALE 376.168182f
#define ICH6_SCALE 374.447815f
#define ICH7_SCALE 371.504028f
#define ICH8_SCALE 374.59729f
#define ICH9_SCALE 371.488556f
#define ICH10_SCALE 371.827362f
#define ICH11_SCALE 371.536896f
#define ICH12_SCALE 372.149811f
#define ICH13_SCALE 372.226501f
#define ICH14_SCALE 372.001556f
#define ICH15_SCALE 371.645844f

#endif

#if Calibration_Index == PMU229
// OFFSET Calibration

#define VCH1_OFFSET 118371
#define VCH2_OFFSET 522353
#define VCH3_OFFSET 590961
                    
#define ICH1_OFFSET 1739495
#define ICH2_OFFSET 1537805
#define ICH3_OFFSET 1685075
#define ICH4_OFFSET 1662259
#define ICH5_OFFSET 1592462
#define ICH6_OFFSET 1585169
#define ICH7_OFFSET 3891652
#define ICH8_OFFSET 936538
#define ICH9_OFFSET 66449
#define ICH10_OFFSET 129286
#define ICH11_OFFSET 1931663
#define ICH12_OFFSET 1754439
#define ICH13_OFFSET 1771237
#define ICH14_OFFSET 1473660
#define ICH15_OFFSET 2033319

//SCALING Calibration
#define VCH1_SCALE 584.715881f
#define VCH2_SCALE 585.255737f
#define VCH3_SCALE 585.591492f

#define ICH1_SCALE 373.688202f
#define ICH2_SCALE 375.187714f
#define ICH3_SCALE 373.593414f
#define ICH4_SCALE 374.505402f
#define ICH5_SCALE 375.604431f
#define ICH6_SCALE 371.960205f
#define ICH7_SCALE 372.022522f
#define ICH8_SCALE 373.739014f
#define ICH9_SCALE 373.561371f
#define ICH10_SCALE 374.443481f
#define ICH11_SCALE 415.427704f
#define ICH12_SCALE 414.48999f
#define ICH13_SCALE 373.575775f
#define ICH14_SCALE 374.78244f
#define ICH15_SCALE 374.113739f

#endif

#if Calibration_Index == PMU230
// OFFSET Calibration

#define VCH1_OFFSET 1039890
#define VCH2_OFFSET 1493018
#define VCH3_OFFSET 1531348
                    
#define ICH1_OFFSET 1623009
#define ICH2_OFFSET 1476668
#define ICH3_OFFSET 1702017
#define ICH4_OFFSET 1393090
#define ICH5_OFFSET 1559508
#define ICH6_OFFSET 1395435
#define ICH7_OFFSET 3275568
#define ICH8_OFFSET 943604
#define ICH9_OFFSET 175812
#define ICH10_OFFSET 390407
#define ICH11_OFFSET 1814742
#define ICH12_OFFSET 1661216
#define ICH13_OFFSET 1530412
#define ICH14_OFFSET 1476899
#define ICH15_OFFSET 1964294

//SCALING Calibration
#define VCH1_SCALE 587.187378f
#define VCH2_SCALE 583.934998f
#define VCH3_SCALE 589.124695f

#define ICH1_SCALE 375.202911f
#define ICH2_SCALE 376.121338f
#define ICH3_SCALE 373.480469f
#define ICH4_SCALE 374.30368f
#define ICH5_SCALE 377.153412f
#define ICH6_SCALE 372.641907f
#define ICH7_SCALE 373.653778f
#define ICH8_SCALE 375.071625f
#define ICH9_SCALE 373.423676f
#define ICH10_SCALE 374.091675f
#define ICH11_SCALE 374.513702f
#define ICH12_SCALE 374.699371f
#define ICH13_SCALE 374.521698f
#define ICH14_SCALE 372.791382f
#define ICH15_SCALE 373.687592f

#endif

#if Calibration_Index == PMU231
// OFFSET Calibration

#define VCH1_OFFSET 643299
#define VCH2_OFFSET 920122
#define VCH3_OFFSET 1133105
                    
#define ICH1_OFFSET 1349015
#define ICH2_OFFSET 1502773
#define ICH3_OFFSET 1444813
#define ICH4_OFFSET 1597319
#define ICH5_OFFSET 1433454
#define ICH6_OFFSET 1303762
#define ICH7_OFFSET 3193373
#define ICH8_OFFSET 846276
#define ICH9_OFFSET 541725
#define ICH10_OFFSET 6276
#define ICH11_OFFSET 1947782
#define ICH12_OFFSET 1667537
#define ICH13_OFFSET 1685726
#define ICH14_OFFSET 1573656
#define ICH15_OFFSET 2023222

//SCALING Calibration
#define VCH1_SCALE 588.058167f
#define VCH2_SCALE 584.629395f
#define VCH3_SCALE 586.823669f

#define ICH1_SCALE 373.90918f
#define ICH2_SCALE 374.103363f
#define ICH3_SCALE 373.27887f
#define ICH4_SCALE 372.997925f
#define ICH5_SCALE 373.684875f
#define ICH6_SCALE 373.653717f
#define ICH7_SCALE 371.833771f
#define ICH8_SCALE 372.030579f
#define ICH9_SCALE 375.075073f
#define ICH10_SCALE 372.499451f
#define ICH11_SCALE 373.356506f
#define ICH12_SCALE 374.156738f
#define ICH13_SCALE 372.001434f
#define ICH14_SCALE 372.772308f
#define ICH15_SCALE 372.755066f

#endif

#if Calibration_Index == PMU232
// OFFSET Calibration

#define VCH1_OFFSET 835800
#define VCH2_OFFSET 1256469
#define VCH3_OFFSET 1542336
                    
#define ICH1_OFFSET 1522798
#define ICH2_OFFSET 1498054
#define ICH3_OFFSET 1533683
#define ICH4_OFFSET 1343171
#define ICH5_OFFSET 1518165
#define ICH6_OFFSET 1623249
#define ICH7_OFFSET 3709475
#define ICH8_OFFSET 950118
#define ICH9_OFFSET 76369
#define ICH10_OFFSET 204785
#define ICH11_OFFSET 1306615
#define ICH12_OFFSET 1458167
#define ICH13_OFFSET 1595281
#define ICH14_OFFSET 1330246
#define ICH15_OFFSET 1945727

//SCALING Calibration
#define VCH1_SCALE 588.432373f
#define VCH2_SCALE 585.253967f
#define VCH3_SCALE 586.506104f

#define ICH1_SCALE 375.29184f
#define ICH2_SCALE 375.348877f
#define ICH3_SCALE 374.608429f
#define ICH4_SCALE 374.769836f
#define ICH5_SCALE 375.339539f
#define ICH6_SCALE 372.883636f
#define ICH7_SCALE 371.183777f
#define ICH8_SCALE 372.679291f
#define ICH9_SCALE 374.272583f
#define ICH10_SCALE 372.629791f
#define ICH11_SCALE 371.426849f
#define ICH12_SCALE 372.556915f
#define ICH13_SCALE 372.794617f
#define ICH14_SCALE 372.414246f
#define ICH15_SCALE 372.036041f

#endif

#if Calibration_Index == PMU233
// OFFSET Calibration

#define VCH1_OFFSET 555380
#define VCH2_OFFSET 624060
#define VCH3_OFFSET 653998
                    
#define ICH1_OFFSET 1574773
#define ICH2_OFFSET 1223017
#define ICH3_OFFSET 1206207
#define ICH4_OFFSET 1343856
#define ICH5_OFFSET 1476142
#define ICH6_OFFSET 1464537
#define ICH7_OFFSET 3301047
#define ICH8_OFFSET 1077496
#define ICH9_OFFSET 86781
#define ICH10_OFFSET 632801
#define ICH11_OFFSET 1448570
#define ICH12_OFFSET 1680097
#define ICH13_OFFSET 1522887
#define ICH14_OFFSET 1433886
#define ICH15_OFFSET 1960080

//SCALING Calibration
#define VCH1_SCALE 584.44043f
#define VCH2_SCALE 586.68689f
#define VCH3_SCALE 583.718872f

#define ICH1_SCALE 374.237793f
#define ICH2_SCALE 373.977661f
#define ICH3_SCALE 373.591278f
#define ICH4_SCALE 373.128174f
#define ICH5_SCALE 374.133759f
#define ICH6_SCALE 372.467804f
#define ICH7_SCALE 370.683685f
#define ICH8_SCALE 373.594849f
#define ICH9_SCALE 373.832855f
#define ICH10_SCALE 370.357452f
#define ICH11_SCALE 374.120392f
#define ICH12_SCALE 375.257996f
#define ICH13_SCALE 374.51825f
#define ICH14_SCALE 373.063812f
#define ICH15_SCALE 372.683807f

#endif

#if Calibration_Index == PMU234
// OFFSET Calibration

#define VCH1_OFFSET 711082
#define VCH2_OFFSET 922684
#define VCH3_OFFSET 1127417
                    
#define ICH1_OFFSET 1781943
#define ICH2_OFFSET 1723504
#define ICH3_OFFSET 1591384
#define ICH4_OFFSET 1435630
#define ICH5_OFFSET 1815630
#define ICH6_OFFSET 1789374
#define ICH7_OFFSET 4029495
#define ICH8_OFFSET 950666
#define ICH9_OFFSET 20664
#define ICH10_OFFSET 66124
#define ICH11_OFFSET 1649952
#define ICH12_OFFSET 1686580
#define ICH13_OFFSET 1475710
#define ICH14_OFFSET 1598835
#define ICH15_OFFSET 1913745

//SCALING Calibration
#define VCH1_SCALE 586.813477f
#define VCH2_SCALE 583.895142f
#define VCH3_SCALE 584.731384f

#define ICH1_SCALE 373.646088f
#define ICH2_SCALE 374.722656f
#define ICH3_SCALE 373.897675f
#define ICH4_SCALE 374.120575f
#define ICH5_SCALE 373.126648f
#define ICH6_SCALE 373.386322f
#define ICH7_SCALE 371.543579f
#define ICH8_SCALE 372.896423f
#define ICH9_SCALE 371.470612f
#define ICH10_SCALE 373.742676f
#define ICH11_SCALE 373.087097f
#define ICH12_SCALE 374.279572f
#define ICH13_SCALE 373.856201f
#define ICH14_SCALE 373.202972f
#define ICH15_SCALE 373.128479f

#endif

#if Calibration_Index == PMU235
// OFFSET Calibration

#define VCH1_OFFSET -697734
#define VCH2_OFFSET -151915
#define VCH3_OFFSET 235144
                    
#define ICH1_OFFSET 1839237
#define ICH2_OFFSET 1583436
#define ICH3_OFFSET 1655128
#define ICH4_OFFSET 1388687
#define ICH5_OFFSET 1678543
#define ICH6_OFFSET 1437130
#define ICH7_OFFSET 3348205
#define ICH8_OFFSET 1209286
#define ICH9_OFFSET -1038324
#define ICH10_OFFSET -1255328
#define ICH11_OFFSET 807363
#define ICH12_OFFSET 473494
#define ICH13_OFFSET 518786
#define ICH14_OFFSET 1069993
#define ICH15_OFFSET 1067283

//SCALING Calibration
#define VCH1_SCALE 585.203186f
#define VCH2_SCALE 587.15863f
#define VCH3_SCALE 585.731018f
                   
#define ICH1_SCALE 376.441193f
#define ICH2_SCALE 372.95224f
#define ICH3_SCALE 374.641296f
#define ICH4_SCALE 372.497253f
#define ICH5_SCALE 375.077148f
#define ICH6_SCALE 373.645874f
#define ICH7_SCALE 371.288635f
#define ICH8_SCALE 372.287628f
#define ICH9_SCALE 372.778534f
#define ICH10_SCALE 373.164948f
#define ICH11_SCALE 374.333954f
#define ICH12_SCALE 375.326782f
#define ICH13_SCALE 374.581757f
#define ICH14_SCALE 373.707275f
#define ICH15_SCALE 374.057617f

#endif

#if Calibration_Index == PMU236
// OFFSET Calibration

#define VCH1_OFFSET 433525
#define VCH2_OFFSET 775785
#define VCH3_OFFSET 831148
                    
#define ICH1_OFFSET 1469527
#define ICH2_OFFSET 1289478
#define ICH3_OFFSET 1323481
#define ICH4_OFFSET 1134922
#define ICH5_OFFSET 1599533
#define ICH6_OFFSET 1347847
#define ICH7_OFFSET 3405196
#define ICH8_OFFSET 663456
#define ICH9_OFFSET 140549
#define ICH10_OFFSET 44787
#define ICH11_OFFSET 1378462
#define ICH12_OFFSET 1592761
#define ICH13_OFFSET 1689513
#define ICH14_OFFSET 1554834
#define ICH15_OFFSET 1855816

//SCALING Calibration
#define VCH1_SCALE 588.093079f
#define VCH2_SCALE 585.492798f
#define VCH3_SCALE 587.490417f
                   
#define ICH1_SCALE 373.5495f
#define ICH2_SCALE 374.777222f
#define ICH3_SCALE 372.738129f
#define ICH4_SCALE 374.904877f
#define ICH5_SCALE 374.693024f
#define ICH6_SCALE 373.786865f
#define ICH7_SCALE 372.144135f
#define ICH8_SCALE 372.237885f
#define ICH9_SCALE 372.11734f
#define ICH10_SCALE 375.231598f
#define ICH11_SCALE 373.414856f
#define ICH12_SCALE 373.84903f
#define ICH13_SCALE 373.352753f
#define ICH14_SCALE 375.168488f
#define ICH15_SCALE 375.994049f

#endif

#if Calibration_Index == PMU237
// OFFSET Calibration

#define VCH1_OFFSET 460347
#define VCH2_OFFSET 31675
#define VCH3_OFFSET 60895
                    
#define ICH1_OFFSET 1470553
#define ICH2_OFFSET 1330915
#define ICH3_OFFSET 1355067
#define ICH4_OFFSET 1360462
#define ICH5_OFFSET 1470065
#define ICH6_OFFSET 1310937
#define ICH7_OFFSET 3665410
#define ICH8_OFFSET 1244024
#define ICH9_OFFSET 184472
#define ICH10_OFFSET 349239
#define ICH11_OFFSET 2016381
#define ICH12_OFFSET 1683947
#define ICH13_OFFSET 1631772
#define ICH14_OFFSET 1860963
#define ICH15_OFFSET 2384971

//SCALING Calibration
#define VCH1_SCALE 585.625854f
#define VCH2_SCALE 585.777405f
#define VCH3_SCALE 585.04425f

#define ICH1_SCALE 376.03125f
#define ICH2_SCALE 374.513f
#define ICH3_SCALE 374.428528f
#define ICH4_SCALE 373.723694f
#define ICH5_SCALE 375.006683f
#define ICH6_SCALE 374.464966f
#define ICH7_SCALE 372.669739f
#define ICH8_SCALE 374.443665f
#define ICH9_SCALE 371.267883f
#define ICH10_SCALE 373.186035f
#define ICH11_SCALE 373.093506f
#define ICH12_SCALE 373.636902f
#define ICH13_SCALE 373.843964f
#define ICH14_SCALE 373.113068f
#define ICH15_SCALE 372.196259f

#endif

#if Calibration_Index == PMU238
// OFFSET Calibration

#define VCH1_OFFSET 240463
#define VCH2_OFFSET 398686
#define VCH3_OFFSET 428172
                    
#define ICH1_OFFSET 1612716
#define ICH2_OFFSET 1368021
#define ICH3_OFFSET 1315884
#define ICH4_OFFSET 1461729
#define ICH5_OFFSET 1413943
#define ICH6_OFFSET 1266202
#define ICH7_OFFSET 2745267
#define ICH8_OFFSET 1202099
#define ICH9_OFFSET 826971
#define ICH10_OFFSET 58624
#define ICH11_OFFSET 2200869
#define ICH12_OFFSET 1575800
#define ICH13_OFFSET 1604739
#define ICH14_OFFSET 1803965
#define ICH15_OFFSET 1880756

//SCALING Calibration
#define VCH1_SCALE 585.590088f
#define VCH2_SCALE 584.705994f
#define VCH3_SCALE 586.103149f

#define ICH1_SCALE 374.018311f
#define ICH2_SCALE 374.76297f
#define ICH3_SCALE 371.991882f
#define ICH4_SCALE 372.994934f
#define ICH5_SCALE 375.091339f
#define ICH6_SCALE 371.417358f
#define ICH7_SCALE 371.032654f
#define ICH8_SCALE 373.246094f
#define ICH9_SCALE 373.82782f
#define ICH10_SCALE 373.397034f
#define ICH11_SCALE 373.855377f
#define ICH12_SCALE 374.921112f
#define ICH13_SCALE 374.439758f
#define ICH14_SCALE 374.222229f
#define ICH15_SCALE 374.104614f

#endif



#if Calibration_Index == PMU239
// OFFSET Calibration

#define VCH1_OFFSET 514090
#define VCH2_OFFSET 567691
#define VCH3_OFFSET 637459
                    
#define ICH1_OFFSET 1657434
#define ICH2_OFFSET 1399894
#define ICH3_OFFSET 1574175
#define ICH4_OFFSET 1193240
#define ICH5_OFFSET 1570147
#define ICH6_OFFSET 1310388
#define ICH7_OFFSET 3549941
#define ICH8_OFFSET 695414
#define ICH9_OFFSET 180843
#define ICH10_OFFSET 193065
#define ICH11_OFFSET 1434893
#define ICH12_OFFSET 1689184
#define ICH13_OFFSET 1437810
#define ICH14_OFFSET 1592910
#define ICH15_OFFSET 1815500

//SCALING Calibration
#define VCH1_SCALE 584.152039f
#define VCH2_SCALE 583.772278f
#define VCH3_SCALE 588.405334f

#define ICH1_SCALE 374.443726f
#define ICH2_SCALE 374.613556f
#define ICH3_SCALE 373.670258f
#define ICH4_SCALE 372.855896f
#define ICH5_SCALE 374.509979f
#define ICH6_SCALE 372.725555f
#define ICH7_SCALE 372.206207f
#define ICH8_SCALE 372.436066f
#define ICH9_SCALE 371.039246f
#define ICH10_SCALE 374.832001f
#define ICH11_SCALE 373.554382f
#define ICH12_SCALE 373.604156f
#define ICH13_SCALE 372.981934f
#define ICH14_SCALE 373.754456f
#define ICH15_SCALE 374.515076f

#endif

#if Calibration_Index == PMU240
// OFFSET Calibration

#define VCH1_OFFSET 431974
#define VCH2_OFFSET 644984
#define VCH3_OFFSET 812914
                    
#define ICH1_OFFSET 1490714
#define ICH2_OFFSET 1471176
#define ICH3_OFFSET 1466760
#define ICH4_OFFSET 1243396
#define ICH5_OFFSET 1491700
#define ICH6_OFFSET 1204325
#define ICH7_OFFSET 3214984
#define ICH8_OFFSET 960743
#define ICH9_OFFSET 24527
#define ICH10_OFFSET 273628
#define ICH11_OFFSET 1319638
#define ICH12_OFFSET 1430706
#define ICH13_OFFSET 1181784
#define ICH14_OFFSET 1482667
#define ICH15_OFFSET 1778467

//SCALING Calibration
#define VCH1_SCALE 587.553833f
#define VCH2_SCALE 589.308838f
#define VCH3_SCALE 587.875427f

#define ICH1_SCALE 374.739319f
#define ICH2_SCALE 374.607635f
#define ICH3_SCALE 373.132996f
#define ICH4_SCALE 372.26712f
#define ICH5_SCALE 375.100861f
#define ICH6_SCALE 372.285675f
#define ICH7_SCALE 370.753571f
#define ICH8_SCALE 372.376831f
#define ICH9_SCALE 373.417511f
#define ICH10_SCALE 372.575806f
#define ICH11_SCALE 374.656158f
#define ICH12_SCALE 376.528137f
#define ICH13_SCALE 374.568726f
#define ICH14_SCALE 375.177948f
#define ICH15_SCALE 375.025024f

#endif

#if Calibration_Index == PMU241
// OFFSET Calibration

#define VCH1_OFFSET 578093
#define VCH2_OFFSET 1327176
#define VCH3_OFFSET 1486190
                    
#define ICH1_OFFSET 1806280
#define ICH2_OFFSET 1402187
#define ICH3_OFFSET 1569831
#define ICH4_OFFSET 1643826
#define ICH5_OFFSET 1439489
#define ICH6_OFFSET 1545443
#define ICH7_OFFSET 3933866
#define ICH8_OFFSET 522372
#define ICH9_OFFSET 382356
#define ICH10_OFFSET 141055
#define ICH11_OFFSET 1915648
#define ICH12_OFFSET 1658062
#define ICH13_OFFSET 1853964
#define ICH14_OFFSET 1616674
#define ICH15_OFFSET 1808744

//SCALING Calibration
#define VCH1_SCALE 587.367249f
#define VCH2_SCALE 583.55188f
#define VCH3_SCALE 583.301453f

#define ICH1_SCALE 373.59964f
#define ICH2_SCALE 374.19989f
#define ICH3_SCALE 374.460846f
#define ICH4_SCALE 373.928192f
#define ICH5_SCALE 373.677338f
#define ICH6_SCALE 372.878357f
#define ICH7_SCALE 370.894806f
#define ICH8_SCALE 372.520599f
#define ICH9_SCALE 371.426758f
#define ICH10_SCALE 372.525604f
#define ICH11_SCALE 372.247467f
#define ICH12_SCALE 373.846008f
#define ICH13_SCALE 373.329407f
#define ICH14_SCALE 372.98172f
#define ICH15_SCALE 372.895111f

#endif

#if Calibration_Index == PMU242
// OFFSET Calibration

#define VCH1_OFFSET 310464
#define VCH2_OFFSET 384696
#define VCH3_OFFSET 90079
                    
#define ICH1_OFFSET 1519787
#define ICH2_OFFSET 1342915
#define ICH3_OFFSET 1574868
#define ICH4_OFFSET 1494850
#define ICH5_OFFSET 1503429
#define ICH6_OFFSET 1470808
#define ICH7_OFFSET 3091320
#define ICH8_OFFSET 1006867
#define ICH9_OFFSET 342562
#define ICH10_OFFSET 53875
#define ICH11_OFFSET 1908580
#define ICH12_OFFSET 1613732
#define ICH13_OFFSET 1888242
#define ICH14_OFFSET 1841210
#define ICH15_OFFSET 2290130

//SCALING Calibration
#define VCH1_SCALE 586.252502f
#define VCH2_SCALE 586.287659f
#define VCH3_SCALE 588.206238f

#define ICH1_SCALE 373.279266f
#define ICH2_SCALE 374.850128f
#define ICH3_SCALE 373.135773f
#define ICH4_SCALE 373.28653f
#define ICH5_SCALE 374.236908f
#define ICH6_SCALE 372.231323f
#define ICH7_SCALE 372.408844f
#define ICH8_SCALE 374.676727f
#define ICH9_SCALE 373.695435f
#define ICH10_SCALE 375.587189f
#define ICH11_SCALE 374.580475f
#define ICH12_SCALE 374.785553f
#define ICH13_SCALE 375.204926f
#define ICH14_SCALE 373.664673f
#define ICH15_SCALE 373.50415f

#endif

#if Calibration_Index == PMU243
// OFFSET Calibration

#define VCH1_OFFSET 179539
#define VCH2_OFFSET 15826
#define VCH3_OFFSET 353154
                    
#define ICH1_OFFSET 1620710
#define ICH2_OFFSET 1396979
#define ICH3_OFFSET 1484436
#define ICH4_OFFSET 1385084
#define ICH5_OFFSET 1809424
#define ICH6_OFFSET 1598356
#define ICH7_OFFSET 3588691
#define ICH8_OFFSET 994614
#define ICH9_OFFSET 42771
#define ICH10_OFFSET 188671
#define ICH11_OFFSET 1651431
#define ICH12_OFFSET 1684467
#define ICH13_OFFSET 1768385
#define ICH14_OFFSET 1830513
#define ICH15_OFFSET 2217725

//SCALING Calibration
#define VCH1_SCALE 588.02832f
#define VCH2_SCALE 584.256287f
#define VCH3_SCALE 586.650818f

#define ICH1_SCALE 373.910217f
#define ICH2_SCALE 373.415314f
#define ICH3_SCALE 373.559814f
#define ICH4_SCALE 372.418762f
#define ICH5_SCALE 373.646667f
#define ICH6_SCALE 372.983948f
#define ICH7_SCALE 371.188263f
#define ICH8_SCALE 371.668274f
#define ICH9_SCALE 370.568878f
#define ICH10_SCALE 372.450439f
#define ICH11_SCALE 371.53476f
#define ICH12_SCALE 373.012268f
#define ICH13_SCALE 372.717194f
#define ICH14_SCALE 371.909454f
#define ICH15_SCALE 372.025421f

#endif


#if Calibration_Index == PMU244
// OFFSET Calibration

#define VCH1_OFFSET 191243
#define VCH2_OFFSET 411967
#define VCH3_OFFSET 743347
                    
#define ICH1_OFFSET 1601252
#define ICH2_OFFSET 1352955
#define ICH3_OFFSET 1521267
#define ICH4_OFFSET 1360904
#define ICH5_OFFSET 1507245
#define ICH6_OFFSET 1356026
#define ICH7_OFFSET 3688579
#define ICH8_OFFSET 890625
#define ICH9_OFFSET 313609
#define ICH10_OFFSET 473694
#define ICH11_OFFSET 2163863
#define ICH12_OFFSET 1707852
#define ICH13_OFFSET 1661611
#define ICH14_OFFSET 1688344
#define ICH15_OFFSET 1955875

//SCALING Calibration
#define VCH1_SCALE 587.231018f
#define VCH2_SCALE 587.704285f
#define VCH3_SCALE 587.299133f

#define ICH1_SCALE 373.108551f
#define ICH2_SCALE 374.582916f
#define ICH3_SCALE 372.234406f
#define ICH4_SCALE 375.309143f
#define ICH5_SCALE 372.861603f
#define ICH6_SCALE 373.865082f
#define ICH7_SCALE 370.224976f
#define ICH8_SCALE 370.97113f
#define ICH9_SCALE 373.536224f
#define ICH10_SCALE 372.698669f
#define ICH11_SCALE 374.310425f
#define ICH12_SCALE 375.690948f
#define ICH13_SCALE 373.361664f
#define ICH14_SCALE 374.356689f
#define ICH15_SCALE 374.753998f

#endif

#if Calibration_Index == PMU15
// OFFSET Calibration

#define VCH1_OFFSET 0
#define VCH2_OFFSET 0
#define VCH3_OFFSET 0
                    
#define ICH1_OFFSET 0
#define ICH2_OFFSET 0
#define ICH3_OFFSET 0
#define ICH4_OFFSET 0
#define ICH5_OFFSET 0
#define ICH6_OFFSET 0
#define ICH7_OFFSET 0
#define ICH8_OFFSET 0
#define ICH9_OFFSET 0
#define ICH10_OFFSET 0
#define ICH11_OFFSET 0
#define ICH12_OFFSET 0
#define ICH13_OFFSET 0
#define ICH14_OFFSET 0
#define ICH15_OFFSET 0

//SCALING Calibration
#define VCH1_SCALE 1
#define VCH2_SCALE 1
#define VCH3_SCALE 1

#define ICH1_SCALE 1
#define ICH2_SCALE 1
#define ICH3_SCALE 1
#define ICH4_SCALE 1
#define ICH5_SCALE 1
#define ICH6_SCALE 1
#define ICH7_SCALE 1
#define ICH8_SCALE 1
#define ICH9_SCALE 1
#define ICH10_SCALE 1
#define ICH11_SCALE 1
#define ICH12_SCALE 1
#define ICH13_SCALE 1
#define ICH14_SCALE 1
#define ICH15_SCALE 1

#endif

#endif /* _CALIBRATION_H_ */
