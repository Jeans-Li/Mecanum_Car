/*
 * Cmd.c
 *
 *  Created on: Nov 1, 2021
 *      Author: Renge
 *      具体解释看cmd.h文件
 *
 */



#include "cmd.h"

int IgnoreCrossFlag = 0;

void ExecuteCmd(int CmdNum)//调整pid后的第二套命令
{
	if(CmdNum == 1)
	{
//		CarTurn(180);
		ToRound(10);
//			StopCross();
//			CarTurn(270);
	}



}


