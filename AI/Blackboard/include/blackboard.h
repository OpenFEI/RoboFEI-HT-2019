/*--------------------------------------------------------------------

******************************************************************************
* @file blackboard.h
* @author Isaac Jesus da Silva - ROBOFEI-HT - FEI
* @version V0.0.0
* @created 07/04/2014
* @Modified 15/05/2014
* @e-mail isaac25silva@yahoo.com.br
* @brief Main header black board
****************************************************************************

Arquivo de cabeçalho contendo as funções e definições do black board

/--------------------------------------------------------------------*/

//---- Definições da memória compartilhada------------------------------
//---- TIPO INT------------------------------
#define PLANNING_COMMAND 0
#define PLANNING_PARAMETER_VEL 1
#define PLANNING_PARAMETER_ANGLE 2
#define IMU_STATE 3
#define IMU_RESET 4
#define CONTROL_ACTION 13
#define CONTROL_HEIGHT_A 14
#define CONTROL_HEIGHT_B 15
#define CONTROL_HEIGHT_C 16
#define DECISION_ACTION_A 17
#define DECISION_ACTION_B 18
#define DECISION_STATE 19
#define DECISION_POSITION_A 20
#define DECISION_POSITION_B 21
#define DECISION_POSITION_C 22
#define DECISION_BALL_POS 23
#define DECISION_OPP1_POS 24
#define DECISION_OPP2_POS 25
#define DECISION_OPP3_POS 26
#define COM_ACTION_ROBOT1 27
#define COM_ACTION_ROBOT2 28
#define COM_ACTION_ROBOT3 29
#define COM_STATE_ROBOT1 30
#define COM_STATE_ROBOT2 31
#define COM_STATE_ROBOT3 32
#define COM_POS_ROBOT1 33
#define COM_POS_ROBOT2 34
#define COM_POS_ROBOT3 35
#define COM_POS_BALL_ROBOT1 36
#define COM_POS_BALL_ROBOT2 37
#define COM_POS_BALL_ROBOT3 38
#define COM_POS_OPP_A_ROBOT1 39
#define COM_POS_OPP_A_ROBOT2 40
#define COM_POS_OPP_A_ROBOT3 41
#define COM_POS_OPP_A_ROBOT4 42
#define COM_POS_OPP_B_ROBOT1 43
#define COM_POS_OPP_B_ROBOT2 44
#define COM_POS_OPP_B_ROBOT3 45
#define COM_POS_OPP_B_ROBOT4 46
#define COM_POS_OPP_C_ROBOT1 47
#define COM_POS_OPP_C_ROBOT2 48
#define COM_POS_OPP_C_ROBOT3 49
#define COM_POS_OPP_C_ROBOT4 50
#define COM_REFEREE 51
#define LOCALIZATION_X 52
#define LOCALIZATION_Y 53
#define LOCALIZATION_THETA 54
#define VISION_LOST 57
#define DECISION_SEARCH_ON 58
#define DECISION_ACTION_VISION 59
#define VISION_MOTOR1_GOAL 60
#define VISION_MOTOR2_GOAL 61
#define VISION_SEARCH_GOAL 62
#define VISION_LOST_GOAL 63
#define VISION_STATE 64
#define ROBOT_NUMBER 65
#define VISION_pos_servo1 66
#define VISION_pos_servo2 67
#define COM_POS_ORIENT_QUALIT_ROBOT_A 68
#define COM_POS_DIST_QUALIT_ROBOT_A 69
#define COM_POS_ORIENT_QUALIT_ROBOT_B 70
#define COM_POS_DIST_QUALIT_ROBOT_B 71
#define COM_POS_ORIENT_QUALIT_ROBOT_C 72
#define COM_POS_DIST_QUALIT_ROBOT_C 73
#define VISION_DELTA_ORIENT 74
#define LOCALIZATION_FIND_ROBOT 75
#define RECEIVED_ROBOT_SENDING 76
#define RECEIVED_QUAL_ORIENT 77
#define RECEIVED_QUAL_DIST 78
#define RECEIVED_ROBOT_SEEN 79
#define CONTROL_MESSAGES 80
#define ASKED_QUALIT_DIRECT 81
#define ASKED_QUALIT_DISTANCE 82
#define ASKED_RELATED_ROBOT 83
#define CONTROL_MOVING 84
#define ROBOT_VIEW_ROTATE 100
#define CONTROL_WORKING 101
#define VISION_WORKING 102
#define LOCALIZATION_WORKING 103
#define DECISION_WORKING 104
#define IMU_WORKING 105
#define VOLTAGE 106
#define DECISION_LOCALIZATION 107
#define iVISION_FIELD 108

//---- TIPO FLOAT------------------------------
#define IMU_GYRO_X 0
#define IMU_GYRO_Y 1
#define IMU_GYRO_Z 2
#define IMU_ACCEL_X 3
#define IMU_ACCEL_Y 4
#define IMU_ACCEL_Z 5
#define IMU_COMPASS_X 6
#define IMU_COMPASS_Y 7
#define IMU_COMPASS_Z 8
#define IMU_EULER_X 9
#define IMU_EULER_Y 10
#define IMU_EULER_Z 11
#define IMU_QUAT_X 12
#define IMU_QUAT_Y 13
#define IMU_QUAT_Z 14
#define VISION_AREA_SEGMENT 15
#define VISION_BALL_X 16
#define VISION_BALL_Y 17
#define VISION_BALL_TAG 18
#define VISION_BALL_TIME 19
#define VISION_BALL_MOV 20
#define VISION_LAND_X 21
#define VISION_LAND_Y 22
#define VISION_LAND_TAG 23
#define VISION_LAND_TIME 24
#define VISION_LAND_MOV 25
#define VISION_RB01_TAG 26
#define VISION_RB01_X 27
#define VISION_RB01_Y 28
#define VISION_RB01_TIME 29
#define VISION_RB01_MOV 30
#define VISION_RB02_TAG 31
#define VISION_RB02_X 32
#define VISION_RB02_Y 33
#define VISION_RB02_TIME 34
#define VISION_RB02_MOV 35
#define VISION_RB03_TAG 36
#define VISION_RB03_X 37
#define VISION_RB03_Y 38
#define VISION_RB03_TIME 39
#define VISION_RB03_MOV 40
#define VISION_RB04_TAG 41
#define VISION_RB04_X 42
#define VISION_RB04_Y 43
#define VISION_RB04_TIME 44
#define VISION_RB04_MOV 45
#define VISION_RB05_TAG 46
#define VISION_RB05_X 47
#define VISION_RB05_Y 48
#define VISION_RB05_TIME 49
#define VISION_RB05_MOV 50
#define VISION_RB06_TAG 51
#define VISION_RB06_X 52
#define VISION_RB06_Y 53
#define VISION_RB06_TIME 54
#define VISION_RB06_MOV 55
#define VISION_RB07_TAG 56
#define VISION_RB07_X 57
#define VISION_RB07_Y 58
#define VISION_RB07_TIME 59
#define VISION_RB07_MOV 60
#define VISION_RB08_TAG 61
#define VISION_RB08_X 62
#define VISION_RB08_Y 63
#define VISION_RB08_TIME 64
#define VISION_RB08_MOV 65
#define VISION_RB09_TAG 66
#define VISION_RB09_X 67
#define VISION_RB09_Y 68
#define VISION_RB09_TIME 69
#define VISION_RB09_MOV 70
#define VISION_RB10_TAG 71
#define VISION_RB10_X 72
#define VISION_RB10_Y 73
#define VISION_RB10_TIME 74
#define VISION_RB10_MOV 75
#define VISION_RB11_TAG 76
#define VISION_RB11_X 77
#define VISION_RB11_Y 78
#define VISION_RB11_TIME 79
#define VISION_RB11_MOV 80
#define VISION_RB12_TAG 81
#define VISION_RB12_X 82
#define VISION_RB12_Y 83
#define VISION_RB12_TIME 84
#define VISION_RB12_MOV 85
#define VISION_RB13_TAG 86
#define VISION_RB13_X 87
#define VISION_RB13_Y 88
#define VISION_RB13_TIME 89
#define VISION_RB13_MOV 90
#define VISION_RB14_TAG 91
#define VISION_RB14_X 92
#define VISION_RB14_Y 93
#define VISION_RB14_TIME 94
#define VISION_RB14_MOV 95
#define VISION_RB15_TAG 96
#define VISION_RB15_X 97
#define VISION_RB15_Y 98
#define VISION_RB15_TIME 99
#define VISION_RB15_MOV 100
#define VISION_RB16_TAG 101
#define VISION_RB16_X 102
#define VISION_RB16_Y 103
#define VISION_RB16_TIME 104
#define VISION_RB16_MOV 105
#define VISION_RB17_TAG 106
#define VISION_RB17_X 107
#define VISION_RB17_Y 108
#define VISION_RB17_TIME 109
#define VISION_RB17_MOV 110
#define VISION_RB18_TAG 111
#define VISION_RB18_X 112
#define VISION_RB18_Y 113
#define VISION_RB18_TIME 114
#define VISION_RB18_MOV 115
#define VISION_RB19_TAG 116
#define VISION_RB19_X 117
#define VISION_RB19_Y 118
#define VISION_RB19_TIME 119
#define VISION_RB19_MOV 120
#define VISION_RB20_TAG 121
#define VISION_RB20_X 122
#define VISION_RB20_Y 123
#define VISION_RB20_TIME 124
#define VISION_RB20_MOV 125
#define VISION_RB21_TAG 126
#define VISION_RB21_X 127
#define VISION_RB21_Y 128
#define VISION_RB21_TIME 129
#define VISION_RB21_MOV 130
#define VISUAL_MEMORY_AL_01_X 131
#define VISUAL_MEMORY_AL_01_Y 132
#define VISUAL_MEMORY_AL_01_MAX_VEL 133
#define VISUAL_MEMORY_AL_02_X 134
#define VISUAL_MEMORY_AL_02_Y 135
#define VISUAL_MEMORY_AL_02_MAX_VEL 136
#define VISUAL_MEMORY_AL_03_X 137
#define VISUAL_MEMORY_AL_03_Y 138
#define VISUAL_MEMORY_AL_03_MAX_VEL 139
#define VISUAL_MEMORY_AL_04_X 140
#define VISUAL_MEMORY_AL_04_Y 141
#define VISUAL_MEMORY_AL_04_MAX_VEL 142
#define VISUAL_MEMORY_AL_05_X 143
#define VISUAL_MEMORY_AL_05_Y 144
#define VISUAL_MEMORY_AL_05_MAX_VEL 145
#define VISUAL_MEMORY_AL_06_X 146
#define VISUAL_MEMORY_AL_06_Y 147
#define VISUAL_MEMORY_AL_06_MAX_VEL 148
#define VISUAL_MEMORY_AL_07_X 149
#define VISUAL_MEMORY_AL_07_Y 150
#define VISUAL_MEMORY_AL_07_MAX_VEL 151
#define VISUAL_MEMORY_AL_08_X 152
#define VISUAL_MEMORY_AL_08_Y 153
#define VISUAL_MEMORY_AL_08_MAX_VEL 154
#define VISUAL_MEMORY_AL_09_X 155
#define VISUAL_MEMORY_AL_09_Y 156
#define VISUAL_MEMORY_AL_09_MAX_VEL 157
#define VISUAL_MEMORY_AL_10_X 158
#define VISUAL_MEMORY_AL_10_Y 159
#define VISUAL_MEMORY_AL_10_MAX_VEL 160
#define VISUAL_MEMORY_OP_01_X 161
#define VISUAL_MEMORY_OP_01_Y 162
#define VISUAL_MEMORY_OP_01_MAX_VEL 163
#define VISUAL_MEMORY_OP_02_X 164
#define VISUAL_MEMORY_OP_02_Y 165
#define VISUAL_MEMORY_OP_02_MAX_VEL 166
#define VISUAL_MEMORY_OP_03_X 167
#define VISUAL_MEMORY_OP_03_Y 168
#define VISUAL_MEMORY_OP_03_MAX_VEL 169
#define VISUAL_MEMORY_OP_04_X 170
#define VISUAL_MEMORY_OP_04_Y 171
#define VISUAL_MEMORY_OP_04_MAX_VEL 172
#define VISUAL_MEMORY_OP_05_X 173
#define VISUAL_MEMORY_OP_05_Y 174
#define VISUAL_MEMORY_OP_05_MAX_VEL 175
#define VISUAL_MEMORY_OP_06_X 176
#define VISUAL_MEMORY_OP_06_Y 177
#define VISUAL_MEMORY_OP_06_MAX_VEL 178
#define VISUAL_MEMORY_OP_07_X 179
#define VISUAL_MEMORY_OP_07_Y 180
#define VISUAL_MEMORY_OP_07_MAX_VEL 181
#define VISUAL_MEMORY_OP_08_X 182
#define VISUAL_MEMORY_OP_08_Y 183
#define VISUAL_MEMORY_OP_08_MAX_VEL 184
#define VISUAL_MEMORY_OP_09_X 185
#define VISUAL_MEMORY_OP_09_Y 186
#define VISUAL_MEMORY_OP_09_MAX_VEL 187
#define VISUAL_MEMORY_OP_10_X 188
#define VISUAL_MEMORY_OP_10_Y 189
#define VISUAL_MEMORY_OP_10_MAX_VEL 190
#define VISUAL_MEMORY_OP_11_X 191
#define VISUAL_MEMORY_OP_11_Y 192
#define VISUAL_MEMORY_OP_11_MAX_VEL 193
#define VISION_TILT_DEG 194
#define VISION_PAN_DEG 195
#define CBR_COORDINATOR 196
#define CBR_RUN 197
#define LOCALIZATION_BALL_X 198
#define LOCALIZATION_BALL_Y 199
#define LOCALIZATION_RBT01_X 200
#define LOCALIZATION_RBT01_Y 201
#define LOCALIZATION_RBT02_X 202
#define LOCALIZATION_RBT02_Y 203
#define LOCALIZATION_RBT03_X 204
#define LOCALIZATION_RBT03_Y 205
#define LOCALIZATION_RBT04_X 206
#define LOCALIZATION_RBT04_Y 207
#define LOCALIZATION_RBT05_X 208
#define LOCALIZATION_RBT05_Y 209
#define LOCALIZATION_RBT06_X 210
#define LOCALIZATION_RBT06_Y 211
#define LOCALIZATION_RBT07_X 212
#define LOCALIZATION_RBT07_Y 213
#define LOCALIZATION_RBT08_X 214
#define LOCALIZATION_RBT08_Y 215
#define LOCALIZATION_RBT09_X 216
#define LOCALIZATION_RBT09_Y 217
#define LOCALIZATION_RBT10_X 218
#define LOCALIZATION_RBT10_Y 219
#define LOCALIZATION_RBT11_X 220
#define LOCALIZATION_RBT11_Y 221
#define LOCALIZATION_OPP01_X 222
#define LOCALIZATION_OPP01_Y 223
#define LOCALIZATION_OPP02_X 224
#define LOCALIZATION_OPP02_Y 225
#define LOCALIZATION_OPP03_X 226
#define LOCALIZATION_OPP03_Y 227
#define LOCALIZATION_OPP04_X 228
#define LOCALIZATION_OPP04_Y 229
#define LOCALIZATION_OPP05_X 230
#define LOCALIZATION_OPP05_Y 231
#define LOCALIZATION_OPP06_X 232
#define LOCALIZATION_OPP06_Y 233
#define LOCALIZATION_OPP07_X 234
#define LOCALIZATION_OPP07_Y 235
#define LOCALIZATION_OPP08_X 236
#define LOCALIZATION_OPP08_Y 237
#define LOCALIZATION_OPP09_X 238
#define LOCALIZATION_OPP09_Y 239
#define LOCALIZATION_OPP10_X 240
#define LOCALIZATION_OPP10_Y 241
#define LOCALIZATION_OPP11_X 242
#define LOCALIZATION_OPP11_Y 243
#define DECISION_RBT01_DIST_BALL 244
#define DECISION_RBT02_DIST_BALL 245
#define DECISION_RBT03_DIST_BALL 246
#define DECISION_RBT04_DIST_BALL 247
#define VISION_FIRST_GOALPOST 248
#define VISION_SECOND_GOALPOST 249
#define VISION_THIRD_GOALPOST 250
#define VISION_FOURTH_GOALPOST 251
#define fVISION_FIELD 252

//----global variables------------------------------------------------
extern int *mem ; //Variável que manipula memória compartilhada
extern float *memf ; //Variável que manipula memória compartilhada

//----Functions prototype---------------------------------------------
int* using_shared_memory(int); //Função que cria e acopla a memória compartilhada

void write_int(int* , int, int);

void write_float(int*, int, float);

int read_int(int*, int);

float read_float(int*, int);
