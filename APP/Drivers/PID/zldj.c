//#include<Stepper.h>
//#include <stdio.h>
//#define KEY 2       //定义 key_1 I/O number is 2
//// 参考文件/*28BYJ-48.pdf该参数根据电机每一转的步数来修改*/
//int stepin = 0;
//int count = 1;
//
//int motorPin7 = 7; //定义电机连接引脚
//int motorPin6 = 6;
//int motorPin5 = 5;
//int motorPin4 = 4;
//
//float c,d,f;
//int b,i,e,g;
//const int TrigPin = 12;
//const int EchoPin = 13;
////const int U = 6;
//float distance=0.00;
//
////const int P=A0;//电位器输入引脚
//
//int sensorValue=0;//电位器电压值
//int outputValue=0;
//
//void setup()
//{
//	pinMode(motorPin7, OUTPUT);
//	pinMode(motorPin6, OUTPUT);
//	pinMode(motorPin5, OUTPUT);
//	pinMode(motorPin4, OUTPUT);
//	pinMode(TrigPin, OUTPUT);// 要检测引脚上输入的脉冲宽度，需要先设置为输入状态
//	pinMode(EchoPin, INPUT);
//	//Serial.println("Ultrasonic sensor:");
//	Serial.begin(9600);
//}
//
//
///**************************PID******************************/
//typedef struct
//{
//	float Target_value;  //目标值
//	float Current_value;  //当前值
//	float PWM;  //PWM
//	float Err;  //目前误差
//	float Last_Err;  //上一次误差
//	float Kp,Ki,Kd;  //比例常数，积分常数，微分常数
//	float output;  //PID输出，通常作为控制执行器的变量
//	float integral;  //积分值
//}PID_TypeDef;
//
//PID_TypeDef PID;  //定义结构体变量
//
//void PID_Init();
//float PID_operation(float value);
//
////初始化PID各项参数
//void PID_Init()
//{
//	PID.Target_value = 0.0;
//	PID.Current_value = 0.0;
//	PID.PWM = 0.0;
//	PID.Err = 0.0;
//	PID.Last_Err = 0.0;
//	PID.output = 0.0;
//	PID.integral = 0.0;
//	PID.Kp = 800.0;
//	PID.Ki = 0.0;
//	PID.Kd = 0.0;     //比例常数，积分常数，微分常数的调整非常重要，这里的参数是经过几次试验得出的经验参数
//}
////PID操作
//float PID_operation(float value)
//{
//	PID.Target_value = value;  //确定目标值
//	PID.Err = PID.Target_value - PID.Current_value;  //计算偏差量
//	PID.integral += PID.Err;  //计算和
//	PID.output = PID.Kp*PID.Err + PID.Ki*PID.integral + PID.Kd* (PID.Err-PID.Last_Err);  //PID运算
//	PID.Last_Err = PID.Err;  //将当前误差值存入上一误差值
//	PID.PWM = PID.output;  //将当前值更新为PID的输出值
//	PID.Current_value=PID.Current_value+PID.PWM;
//	return PID.PWM;  //返回当前值
//}
//
///*************************ceju*********************************/
//int juli()
//{
//	// 产生一个10us的高脉冲去触发TrigPin
//	digitalWrite(TrigPin, LOW);
//	delayMicroseconds(2);
//	digitalWrite(TrigPin, HIGH);
//	delayMicroseconds(10);
//	digitalWrite(TrigPin, LOW);
//	// 检测脉冲宽度，并计算出距离
//	//delayMicroseconds(2);
//	distance = pulseIn(EchoPin, HIGH) / 58.30;
//	return distance;
//}
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//void PWM(float c)
//{
//	if(c>=0)
//	{
//		if(c>=1024)//zhengzhuan
//		{
//			digitalWrite(motorPin5, HIGH);
//			digitalWrite(motorPin4, HIGH);
//			digitalWrite(motorPin7, LOW);
//			digitalWrite(motorPin6, LOW);
//			sensorValue = 1023;
//		}
//		if(c<1024&&c>=500)
//		{
//			digitalWrite(motorPin5, HIGH);
//			digitalWrite(motorPin4, HIGH);
//			digitalWrite(motorPin7, LOW);
//			digitalWrite(motorPin6, LOW);
//			sensorValue = c;
//		}
//		if(c<500&&c>=0)
//		{
//			digitalWrite(motorPin5, HIGH);
//			digitalWrite(motorPin4, HIGH);
//			digitalWrite(motorPin7, LOW);
//			digitalWrite(motorPin6, LOW);
//			sensorValue = 500;
//		}
//		outputValue = map(sensorValue,0,1023,0,255);
//		analogWrite(4,outputValue);
//		Serial.print("outputValue:");
//		Serial.print(outputValue);
//		Serial.println();
//		//delay(100);
//	}
//	/////////////////////////////////////////////////////////////////////////////////////
//	/*  if(c=0)//tingzhi
//  {
//    digitalWrite(motorPin5, LOW);
//    digitalWrite(motorPin4, LOW);
//    digitalWrite(motorPin7, LOW);
//    digitalWrite(motorPin6, LOW);
//    sensorValue = 0;
//  }*/
//	////////////////////////////////////////////////////////////////////////////////////
//	else
//	{
//		if(c<=-1024)//fanzhuan
//		{
//			digitalWrite(motorPin7, HIGH);
//			digitalWrite(motorPin6, HIGH);
//			digitalWrite(motorPin5, LOW);
//			digitalWrite(motorPin4, LOW);
//			sensorValue = 1023;
//		}
//		if(c>-1024&&c<=-500)
//		{
//			digitalWrite(motorPin7, HIGH);
//			digitalWrite(motorPin6, HIGH);
//			digitalWrite(motorPin5, LOW);
//			digitalWrite(motorPin4, LOW);
//			sensorValue = -c;
//		}
//		if(c>-500&&c<0)
//		{
//			digitalWrite(motorPin7, HIGH);
//			digitalWrite(motorPin6, HIGH);
//			digitalWrite(motorPin5, LOW);
//			digitalWrite(motorPin4, LOW);
//			sensorValue = 500;
//		}
//		outputValue = map(sensorValue,0,1023,0,255);
//		analogWrite(6,outputValue);
//		Serial.print("outputValue:");
//		Serial.print(outputValue);
//		Serial.println();
//		//delay(100);
//	}
//}
//
//
//void loop()
//{
//	//freopen("E:\\PID_output.txt","w",stdout);  //重定向输出到文件
//	PID_Init();  //PID初始化
//	for(int i=1; i<=100; i++)
//	{
//		juli();
//		Serial.print("sensor:");
//		Serial.print(distance);
//		Serial.println();
//		PID.Current_value = distance;//实际值
//		//d = 10.0;
//		//PID.Target_value = 10.0;
//
//		Serial.print("PIDzhi:");
//		Serial.print(PID_operation(15.0));
//		c=PID.PWM;
//		//Serial.print("     ");
//		//Serial.print("piancha:");
//		//Serial.print(PID.Target_value - PID.Current_value);
//		Serial.println();
//		/*if(c>=0)
//                {
//                  c = 2000*(PID.Target_value - PID.Current_value)/PID.Target_value;
//                }
//                else if(c<0)
//                {
//                  c = 10000*(PID.Target_value - PID.Current_value)/PID.Target_value;
//                }*/
//		//Serial.print("c:");
//		//Serial.print(c);
//		//Serial.println();
//		PWM(c);
//	}
//}
