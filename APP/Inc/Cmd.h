/*
 * Cmd.h
 *
 *  Created on: Nov 1, 2021
 *      Author: Renge
 *      说明，cmd.c是命令集合，内有执行cmd的命令表，根据蓝牙不同的命令进行不同的操作。
 *      	//	if(cmd_flag != btcmd_num)
	//	{
	//		if(btcmd_num == 997)
	//		{//选择红外或蓝牙控制
	//			do_cmd(num[2]);
	//			cmd_flag = btcmd_num;
	//		}
	//		else{//蓝牙控制
	//			do_cmd(btcmd_num);
	//			cmd_flag = btcmd_num;//设置命令标志位防止反复执行命令。
	//		}
	//	}
 *
 */

#ifndef INC_CMD_H_
#define INC_CMD_H_


void ExecuteCmd(int CmdNum);

#endif /* INC_CMD_H_ */
