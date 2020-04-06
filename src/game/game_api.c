#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game_type.h"
#include "game_func.h"
#include "game_struct.h"
#include "hook/hook.h"

void api_return(){
	return;
}

/*强制写色盘*/
void api_wpal_tile(int PalID,int PalPtr){
	int i;
	//api_print(0,0,0,3,0,"%02d",PalID);
	for(i=0;i<16;i++){
		DU16(0xa01000 + PalID*16 + i*2) = DU16(PalPtr + i*2);
	}
	return;
}

//用来刷新屏幕，参数frame为0时无限循环，否则刷新指定次数屏幕*/
//游戏时间是每秒80frame
void api_delay(int frame) {
	int i;
	if(!frame) {
		while(1) {
			ScreenUpdate_0018c492();
		}
	} else {
		for(i=0; i<frame; i++)
			ScreenUpdate_0018c492();
	}
	return;
}




int api_getarm(int CMD,int Param){
	DU16(0x81b274) = ((DU16(0x81b270) >> 8) | DU16(0x81b270)) ^ Param;
	DU16(0x500000)=DU16(0x81b274);
	DU16(0x81b272) = ((DU16(0x81b270) >> 8) ^ CMD) | DU16(0x81b270);
	DU16(0x500002)=DU16(0x81b272);

	return FUN_0019acf8();
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

/*设置场景的边界范围*/
void api_bgrange(int min_x,int min_y,int max_x,int max_y) {
	api_arm(0x13,min_x);//0x10000088 = min_x
	api_arm(0x36,min_y);//0x1000008C = min_y
	api_arm(0x24,max_x);//0x10000090 = max_x
	api_arm(0x58,max_y);//0x10000094 = max_y
	return;
}

/*设置场景的当前坐标*/
void api_bgpos(int x,int y) {
	api_arm(0x68,x);//0x10000078 = x
	api_arm(0x7d,y);	//0x1000007C = y
	return;
}









