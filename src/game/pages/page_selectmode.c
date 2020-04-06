#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../game_type.h"
#include "../game_func.h"
#include "../stage/stage.h"
#include "../game_api.h"



/*选择游戏模式界面*/
void PageSelectMode(int PlayerID) {
	int iVar3;
	int i;
	int OBJ[4];
	int pos=0,old_pos=0,ctrl=1;
	int a1,a2;

	
	if (FUN_001988d6()) {
		FUN_00173bb8();
	}
	api_arm(0x43,5);
	FUN_001f6e84(0xf,0);
	FUN_001f7008(0x14,0);
	DU16(0x80e04e) = 0;
	FUN_001952ca(1,5);//MUSIC初始化
	PlayMusic_00195310(4);
	DU8(0x803b87) = 1;
	api_arm(0x43,2);
	DU16(0x80e04c) = 1;
	FUN_00151662(0,-1,0);
	FUN_0015162c(1,0x31,0x24);
	SetPal_0014ce68(1,0,PU32(0x251392));
	FUN_0016e3f6(1,0,4,PU32(0x2520a2),0x60,0,0,0xaf4);//画八卦台
	SetPal_0014ce68(2,0x1e,PU32(0x2f2d22));
	iVar3 = CreatSObj_0016f530();
	SetSObj_0016f762(iVar3,PU32(0x2fc580),0,0,0,0);//画背景动态火焰
	FUN_00171b16(iVar3,1,0);
	PalFadeIn_0014db72(2);
	ScreenUpdate_0018c492();

	SetPal_0014c2da(0,10,0x2f2d62);
	SetPal_0014c2da(0,0xb,0x2f2da2);
	SetPal_0014c2da(0,0xc,0x2f2de2);
	SetPal_0014c2da(0,0xd,0x2f2e22);
	SetPal_0014c2da(2,0x19,0x2fda40);
	SetPal_0014c2da(2,0x1b,0x2686ca);
	SetPal_0014c2da(2,0x1c,0x26870a);
	SetPal_0014c2da(2,0x1d,0x2557c8);
	SetPal_0014c2da(2,0x18,0x26894a);
	a1 =FUN_0016b922(0xff04,0,0x32,0x1c,0x2fc336,0x28,0,0x2fc21e);//左边的门动画
	a2 =FUN_0016b922(0x1d0,0,0x33,0x1c,0x2fc2ba,0x28,0,0x2fc21e);//右边的门动画
	api_delay(0x1a);//自己写的函数，用来刷新多少帧屏幕
	//Print(0,1,10,3,0,"QQ:100714928");
	//Print(0,1,12,3,0,"www.qq.com");
	for (i=0; i<4; i++) {//这里画3个模式的框框
		OBJ[i] = CreatSObj_0016f530();
		SetSObj_0016f762(OBJ[i],0x2fc6a8,140,35+i*48-23,0,0);
		FUN_00171b16(OBJ[i],1,10);
	}
	api_delay(0x18);
	Print(0,1,10,3,0,"QQ:100714928");
	Print(0,1,12,3,0,"www.qq.com");
	FUN_0016bb58(0x13,2,10,0,0,700);//一
	FUN_0016bb58(0x18,2,10,0,0,1230);//统
	FUN_0016bb58(0x1d,2,10,2,3,5);//中
	FUN_0016bb58(0x22,2,10,3,6,7);//原
	FUN_0016bb58(0x13,8,10,0,0,935);//武
	FUN_0016bb58(0x18,8,10,0,0,935);//将
	FUN_0016bb58(0x1d,8,10,2,1,0x16);//争
	FUN_0016bb58(0x22,8,10,0,0,4);//霸
	FUN_0016bb58(0x13,14,10,0,0,158);//网
	FUN_0016bb58(0x18,14,10,0,0,807);//络
	FUN_0016bb58(0x1d,14,10,0,3,0xd);//排
	FUN_0016bb58(0x22,14,10,0,8,0x14);//名
	FUN_0016bb58(0x13,20,10,0,0,700);//一
	FUN_0016bb58(0x18,20,10,0,0,1230);//统
	FUN_0016bb58(0x1d,20,10,0,3,0xd);//模
	FUN_0016bb58(0x22,20,10,0,8,0x14);//式

	FUN_0016b922(0xd3,200,0x12e,0x18,0x2fc1fa,300,0,0x2fc21e);//倒计时的字
	/*光标控制开始*/
	while(1) {
		if( ChkKeyPress_0014f962(PlayerID*9+2)) { //PRESS UP

			if(!pos)//光标变0了
				pos = 3;
			else
				pos -= 1;
			ctrl = 1;
		}
		if( ChkKeyPress_0014f962(PlayerID*9+3)) { //PRESS DOWN

			if(pos<3)//光标变0了
				pos += 1;
			else
				pos = 0;
			ctrl = 1;
		}
		if(ctrl) {
			switch(old_pos) {//把旧光标文字颜色变灰
			case 0:
				FUN_0016bb58(0x13,2,10,0,0,700);//一
				FUN_0016bb58(0x18,2,10,0,0,1230);//统
				FUN_0016bb58(0x1d,2,10,2,3,5);//中
				FUN_0016bb58(0x22,2,10,3,6,7);//原
				break;
			case 1:
				FUN_0016bb58(0x13,8,10,0,0,935);//武
				FUN_0016bb58(0x18,8,10,0,0,935);//将
				FUN_0016bb58(0x1d,8,10,2,1,0x16);//争
				FUN_0016bb58(0x22,8,10,0,0,4);//霸
				break;
			case 2:
				FUN_0016bb58(0x13,14,10,0,0,158);//网
				FUN_0016bb58(0x18,14,10,0,0,807);//络
				FUN_0016bb58(0x1d,14,10,0,3,0xd);//排
				FUN_0016bb58(0x22,14,10,0,8,0x14);//名
				break;
			case 3:
				FUN_0016bb58(0x13,20,10,0,0,700);//一
				FUN_0016bb58(0x18,20,10,0,0,1230);//统
				FUN_0016bb58(0x1d,20,10,0,3,0xd);//排
				FUN_0016bb58(0x22,20,10,0,8,0x14);//名
				break;
			}
			/*让未选中的框框停止动画？*/
			FUN_00171ae8(OBJ[old_pos],0x2fc628);
			FUN_00171b76(OBJ[old_pos],140,35+old_pos*48-23,0);

			switch(pos) {//把新光标文字颜色变亮
			case 0:
				FUN_0016bb58(0x13,2,11,0,0,700);//一
				FUN_0016bb58(0x18,2,11,0,0,1230);//统
				FUN_0016bb58(0x1d,2,11,2,3,5);//中
				FUN_0016bb58(0x22,2,11,3,6,7);//原
				break;
			case 1:
				FUN_0016bb58(0x13,8,11,0,0,935);//武
				FUN_0016bb58(0x18,8,11,0,0,935);//将
				FUN_0016bb58(0x1d,8,11,2,1,0x16);//争
				FUN_0016bb58(0x22,8,11,0,0,4);//霸
				break;
			case 2:
				FUN_0016bb58(0x13,14,11,0,0,158);//网
				FUN_0016bb58(0x18,14,11,0,0,807);//络
				FUN_0016bb58(0x1d,14,11,0,3,0xd);//排
				FUN_0016bb58(0x22,14,11,0,8,0x14);//名
				break;
			case 3:
				FUN_0016bb58(0x13,20,11,0,0,700);//一
				FUN_0016bb58(0x18,20,11,0,0,1230);//统
				FUN_0016bb58(0x1d,20,11,0,3,0xd);//排
				FUN_0016bb58(0x22,20,11,0,8,0x14);//名
				break;

			}
			/*让未选中的框框停止动画？*/
			FUN_00171ae8(OBJ[pos],0x2fc660);
			FUN_00171b76(OBJ[pos],140,35+pos*48-23,0);
			ctrl = 0;
			old_pos = pos;

		}
		if(ChkKeyPress_0014f962(PlayerID*9+6)) { //PRESS PUNCH
			PlaySound_001f6d34(0,200,0x7f,0);//播放一次音效
			FUN_00171ae8(OBJ[pos],0x2fc638);
			FUN_00171b76(OBJ[pos],140,35+pos*48-23,0);
			api_delay(0x1e);
			switch(pos) { //这里根据选择的模式来调整一些内存
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			}
			FUN_00152712();//让模式选择的文字消失
			FUN_0015231a();
			DU16(0x80e04c) = 0;
			api_delay(16);
			for(i=0; i<4; i++)
				FUN_0016f6c2(OBJ[i]);//释放OBJ
			FUN_0016f6c2(a1);//销毁左边的门
			FUN_0016f6c2(a2);//销毁右边的门
			ScreenUpdate_0018c492();

			return;
		}
		api_delay(1);
	}
	return;
}
