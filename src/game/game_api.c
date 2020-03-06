#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game_type.h"
#include "game_func.h"


//用来刷新屏幕，参数frame为0时无限循环，否则刷新指定次数屏幕*/
//游戏时间是每秒80frame
void api_delay(int frame){
	int i;
	if(!frame){
		while(1){
			ScreenUpdate_0018c492();
		}
	}else{
		for(i=0;i<frame;i++)
			ScreenUpdate_0018c492();
	}
	return;
}

/*向ARM芯片发送命令*/
//@@参数1 CMD 命令编号
//@@参数2 Param 命令参数
void api_arm(int CMD,int Param) {
	DU16(0x81b274) = ((DU16(0x81b270) >> 8) | DU16(0x81b270)) ^ Param;
	DU16(0x500000)=DU16(0x81b274);
	DU16(0x81b272) = ((DU16(0x81b270) >> 8) ^ CMD) | DU16(0x81b270);
	DU16(0x500002)=DU16(0x81b272);
	FUN_0019adcc();
	return;
}