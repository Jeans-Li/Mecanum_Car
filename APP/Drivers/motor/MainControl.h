/*
 * MainControl.h
 *
 *  Created on: Nov 4, 2021
 *      Author: Renge
 */

#ifndef DRIVERS_MOTOR_MAINCONTROL_H_
#define DRIVERS_MOTOR_MAINCONTROL_H_

#include "app_main.h"
#include "math.h"

void ToRound(int direction ,float r, float A,float B ,float C ,float D);
void TurnLeftRound(float r);
void InitRev(void);
int RoundLim( float R);

#endif /* DRIVERS_MOTOR_MAINCONTROL_H_ */
