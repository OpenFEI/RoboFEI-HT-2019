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
#define IMU_GYRO_X 1
#define IMU_GYRO_Y 2
#define IMU_GYRO_Z 3
#define IMU_ACCEL_X 4
#define IMU_ACCEL_Y 5
#define IMU_ACCEL_Z 6
#define IMU_COMPASS_X 7
#define IMU_COMPASS_Y 8
#define IMU_COMPASS_Z 9
#define IMU_EULER_X 10
#define IMU_EULER_Y 11
#define IMU_EULER_Z 12
#define IMU_QUAT_X 13
#define IMU_QUAT_Y 14
#define IMU_QUAT_Z 15
#define VISION_AREA_SEGMENT 16
#define VISION_BALL_X 17
#define VISION_BALL_Y 18
#define VISION_BALL_TAG 19
#define VISION_BALL_TIME 20
#define VISION_LAND_X 21
#define VISION_LAND_Y 22
#define VISION_LAND_TAG 23
#define VISION_LAND_TIME 24
#define VISION_RB01_TAG 25
#define VISION_RB01_X 26
#define VISION_RB01_Y 27
#define VISION_RB01_TIME 28
#define VISION_RB02_TAG 29
#define VISION_RB02_X 30
#define VISION_RB02_Y 31
#define VISION_RB02_TIME 32
#define VISION_RB03_TAG 33
#define VISION_RB03_X 34
#define VISION_RB03_Y 35
#define VISION_RB03_TIME 36
#define VISION_RB04_TAG 37
#define VISION_RB04_X 38
#define VISION_RB04_Y 39
#define VISION_RB04_TIME 40
#define VISION_RB05_TAG 41
#define VISION_RB05_X 42
#define VISION_RB05_Y 43
#define VISION_RB05_TIME 44
#define VISION_RB06_TAG 45
#define VISION_RB06_X 46
#define VISION_RB06_Y 47
#define VISION_RB06_TIME 48
#define VISION_RB07_TAG 49
#define VISION_RB07_X 50
#define VISION_RB07_Y 51
#define VISION_RB07_TIME 52
#define VISION_RB08_TAG 53
#define VISION_RB08_X 54
#define VISION_RB08_Y 55
#define VISION_RB08_TIME 56
#define VISION_RB09_TAG 57
#define VISION_RB09_X 58
#define VISION_RB09_Y 59
#define VISION_RB09_TIME 60
#define VISION_RB10_TAG 61
#define VISION_RB10_X 62
#define VISION_RB10_Y 63
#define VISION_RB10_TIME 64
#define VISION_RB11_TAG 65
#define VISION_RB11_X 66
#define VISION_RB11_Y 67
#define VISION_RB11_TIME 68
#define VISION_RB12_TAG 69
#define VISION_RB12_X 70
#define VISION_RB12_Y 71
#define VISION_RB12_TIME 72
#define VISION_RB13_TAG 73
#define VISION_RB13_X 74
#define VISION_RB13_Y 75
#define VISION_RB13_TIME 76
#define VISION_RB14_TAG 77
#define VISION_RB14_X 78
#define VISION_RB14_Y 79
#define VISION_RB14_TIME 80
#define VISION_RB15_TAG 81
#define VISION_RB15_X 82
#define VISION_RB15_Y 83
#define VISION_RB15_TIME 84
#define VISION_RB16_TAG 85
#define VISION_RB16_X 86
#define VISION_RB16_Y 87
#define VISION_RB16_TIME 88
#define VISION_RB17_TAG 89
#define VISION_RB17_X 90
#define VISION_RB17_Y 91
#define VISION_RB17_TIME 92
#define VISION_RB18_TAG 93
#define VISION_RB18_X 94
#define VISION_RB18_Y 95
#define VISION_RB18_TIME 96
#define VISION_RB19_TAG 97
#define VISION_RB19_X 98
#define VISION_RB19_Y 99
#define VISION_RB19_TIME 100
#define VISION_RB20_TAG 101
#define VISION_RB20_X 102
#define VISION_RB20_Y 103
#define VISION_RB20_TIME 104
#define VISION_RB21_TAG 105
#define VISION_RB21_X 106
#define VISION_RB21_Y 107
#define VISION_RB21_TIME 108
#define VISION_RB22_TAG 109
#define VISION_RB22_X 110
#define VISION_RB22_Y 111
#define VISION_RB22_TIME 112
#define VISION_TILT_DEG 113
#define VISION_PAN_DEG 114
#define CBR_COORDINATOR 115
#define CBR_RUN 116
#define LOCALIZATION_BALL_X 117
#define LOCALIZATION_BALL_Y 118
#define LOCALIZATION_RBT01_X 119
#define LOCALIZATION_RBT01_Y 120
#define LOCALIZATION_RBT02_X 121
#define LOCALIZATION_RBT02_Y 122
#define LOCALIZATION_RBT03_X 123
#define LOCALIZATION_RBT03_Y 124
#define LOCALIZATION_RBT04_X 125
#define LOCALIZATION_RBT04_Y 126
#define LOCALIZATION_RBT05_X 127
#define LOCALIZATION_RBT05_Y 128
#define LOCALIZATION_RBT06_X 129
#define LOCALIZATION_RBT06_Y 130
#define LOCALIZATION_RBT07_X 131
#define LOCALIZATION_RBT07_Y 132
#define LOCALIZATION_RBT08_X 133
#define LOCALIZATION_RBT08_Y 134
#define LOCALIZATION_RBT09_X 135
#define LOCALIZATION_RBT09_Y 136
#define LOCALIZATION_RBT10_X 137
#define LOCALIZATION_RBT10_Y 138
#define LOCALIZATION_RBT11_X 139
#define LOCALIZATION_RBT11_Y 140
#define LOCALIZATION_OPP01_X 141
#define LOCALIZATION_OPP01_Y 142
#define LOCALIZATION_OPP02_X 143
#define LOCALIZATION_OPP02_Y 144
#define LOCALIZATION_OPP03_X 145
#define LOCALIZATION_OPP03_Y 146
#define LOCALIZATION_OPP04_X 147
#define LOCALIZATION_OPP04_Y 148
#define LOCALIZATION_OPP05_X 149
#define LOCALIZATION_OPP05_Y 150
#define LOCALIZATION_OPP06_X 151
#define LOCALIZATION_OPP06_Y 152
#define LOCALIZATION_OPP07_X 153
#define LOCALIZATION_OPP07_Y 154
#define LOCALIZATION_OPP08_X 155
#define LOCALIZATION_OPP08_Y 156
#define LOCALIZATION_OPP09_X 157
#define LOCALIZATION_OPP09_Y 158
#define LOCALIZATION_OPP10_X 159
#define LOCALIZATION_OPP10_Y 160
#define LOCALIZATION_OPP11_X 161
#define LOCALIZATION_OPP11_Y 162
#define DECISION_RBT01_DIST_BALL 163
#define DECISION_RBT02_DIST_BALL 164
#define DECISION_RBT03_DIST_BALL 165
#define DECISION_RBT04_DIST_BALL 166
#define VISION_FIRST_GOALPOST 167
#define VISION_SECOND_GOALPOST 168
#define VISION_THIRD_GOALPOST 169
#define VISION_FOURTH_GOALPOST 170
#define fVISION_FIELD 171

//----global variables------------------------------------------------
extern int *mem ; //Variável que manipula memória compartilhada
extern float *memf ; //Variável que manipula memória compartilhada

//----Functions prototype---------------------------------------------
int* using_shared_memory(int); //Função que cria e acopla a memória compartilhada

void write_int(int* , int, int);

void write_float(int*, int, float);

int read_int(int*, int);

float read_float(int*, int);

