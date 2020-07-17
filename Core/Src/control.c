/*
 * control.c
 *
 *  Created on: 2020/07/15
 *      Author: tamod
 */

#include "control.h"
#include "tim.h"
#include "math.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif
#ifndef constrain(amt,low,high)
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#endif

static float PosCmd, PosRes, PosErr, PosErrInt; //[rad]
static float VelCmd, VelRes, VelErr, VelErrInt, VelResInt; //[rad/s]
static float CurCmd; //,CurRes,CurErr,CurErrInt;//[A]
//static float PosICmd, PosIRes; //[rad・s]
static float AccelerationRef, CurrentRef, VoltageRef;
//const float dt = 0.0001; //[sec]
static float TimeNow; //[sec]
#define ONEREVCNT 72//cnt/rev
#define POSERRINT_LIMIT 1.0//[rad・s]
static float vel_pos_gain=0;
const float RADPERCNT = -2.0 * M_PI / ONEREVCNT; //[rad/cnt]
static float Kp_p = Kp_p_DEFAULT, Ki_p = Ki_p_DEFAULT, Kd_p = Kd_p_DEFAULT;

void get_time() { //wake only once in control loop
//	static uint32_t loopcounter;
//	loopcounter++;
//	TimeNow = loopcounter * dt_major;
	TimeNow = HAL_GetTick() * 0.001f;
}
void get_pos() {
	PosRes = Enc_Read() * RADPERCNT;
}
void get_vel() {
	static float PosLast = 0.0f, TimeLast = 0.0f; //　過去位置，過去時間

	float dtheta = PosRes - PosLast;
	float spendtime = TimeNow - TimeLast;

	if (abs(dtheta) > M_PI) { //　±180度以上
		VelRes = dtheta / spendtime; //　速度更新
		PosLast = PosRes; //　位置更新
		TimeLast = TimeNow; //　過去時間更新
	} else if (spendtime > 1) { //　1秒たっても半回転してない時
		VelRes = 0.0; //　停止と判断
		PosLast = PosRes; //　位置更新
		TimeLast = TimeNow; //　過去時間更新
	}
}

void control() {
	get_time(); //　時刻更新
	get_pos(); //　位置更新
	get_vel(); //　速度更新

//	PosCmd = M_PI * sinf(TimeNow * M_PI_4); //8sで±180度
//	VelCmd = M_PI * M_PI_4 * cosf(TimeNow * M_PI_4);
//	PosCmd = TimeNow;
//	PosCmd=100.0;
//	VelCmd = 10;

	//　位置制御モード
	PosErr = PosCmd - PosRes; //　位置偏差
	if (abs(PosErr) < M_PI)  //残り半周以内なら
		VelCmd = PosErr * vel_pos_gain; //　残角度に比例した速度

	VelErr = VelCmd - VelRes; //　速度偏差
	PosErrInt += PosErr * dt_major; // 積分成分
	if (abs(PosErrInt) > POSERRINT_LIMIT) //　積分成分の範囲内強制
		PosErrInt = constrain(PosErrInt, -POSERRINT_LIMIT, POSERRINT_LIMIT);

	AccelerationRef = Kp_p * PosErr + Kd_p * VelErr + Ki_p * PosErrInt;
//	static const float Acceleration2Current = Mn / Ktn;
//	CurrentRef = AccelerationRef * Acceleration2Current;
//	CurCmd = CurrentRef;
	VoltageRef = AccelerationRef;//CurCmd * Rn;
	Duty_Out(constrain(VoltageRef / 12, -0.9, 0.9));
//	Duty_Out(0.3);
//	setMotorVoltage(VoltageRef);
}
float get_vel_cmd() {
	return VelCmd;
}
