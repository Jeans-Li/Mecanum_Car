///*
// * PID_Firmed_Dis.c
// *
// *  Created on: Oct 29, 2021
// *      Author: Renge
// */
//
//#include "PID_Firmed_Dis.h"
//
//
//PID_TypeDef PID;
//
//
//
////初始化PID各项参数
//void PID_Init()
//{
//	PID.Target_value = 0.0;
//	PID.Current_value = 0.0;
//        PID.PWM = 0.0;
//	PID.Err = 0.0;
//	PID.Last_Err = 0.0;
//	PID.output = 0.0;
//	PID.integral = 0.0;
//	PID.Kp = 800.0;
//	PID.Ki = 0.0;
//	PID.Kd = 0.0;     //比例常数，积分常数，微分常数的调整非常重要，这里的参数是经过几次试验得出的经验参数
//}
//
//float PID_operation(float value)
//{
//	PID.Target_value = value;  //确定目标值
//	PID.Err = PID.Target_value - PID.Current_value;  //计算偏差量
//	PID.integral += PID.Err;  //计算和
//	PID.output = PID.Kp*PID.Err + PID.Ki*PID.integral + PID.Kd* (PID.Err-PID.Last_Err);  //PID运算
//	PID.Last_Err = PID.Err;  //将当前误差值存入上一误差值
//	PID.PWM = PID.output;  //将当前值更新为PID的输出值
////        PID.Current_value=PID.Current_value+PID.PWM;
//	return PID.PWM;  //返回当前值
//}
//
////void FirmedDis_Loop()
