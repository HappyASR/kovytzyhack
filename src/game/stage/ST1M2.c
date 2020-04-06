#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../game_type.h"
#include "../game_func.h"

#include "../game_api.h"
#include "../game_struct.h"
#include "../hook/hook.h"
#include "stage.h"



struct RoroConfig {
	int CMDPtr;//刷兵指针
	int DropPtr;//掉落指针
	char DropNum;//掉落数量
	char Fix0;
	short FleeTime;//逃跑时间
	int FuncPtr;//执行函数
};

// FF 04
// 03 ACTION TYPE
// 01 ACTION ID
// 00 13 05 84 ROROPTR
// 02 5D POS X
// 00 F6 POS Y
// 00 00 FIX 0
// 00 01 RORO NUMBER






const int ST1M2BG1_1[]= {
	0x00,0x00,0x00,0x00,0x00,0x25,0x20,0xA2,0x02,0x00,0x00,0x00,0x0A,0xF4,0x00,0x00,0x00,0x25,0x08,0x52,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x02,0x00,0x00,0x00,0x00,0x25,0x20,0xA2,0x02,0x00,0x00,0x00,0x0A,0xF4,0x00,0x00,0x00,0x25,0x08,0x52,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};














void testfunc(char a1,char a2) {
	Print(0,4,10,0,0,"a1=%d a2=%d",a1,a2);
	return;
}

const char ST1M2RoRoCMD1[] = {
	0xFF,0x14,0x00,0x00,
	0xFF,0x11,0x03,0x00,
	0xFF,0x04,0x03,0x01,0x00,0x13,0x05,0x84,0x02,0x5D,0x00,0xF6,0x00,0x00,0x00,0x01,
	0xFF,0x04,0x03,0x01,0x00,0x13,0x05,0x84,0x02,0x5D,0x01,0x1E,0x00,0x00,0x00,0x01,
	0xFF,0x08,0x01,0x00,
	//0xFF,0x0c,0x66,0x77,0x00,0x48,0x35,0x30,//0x483530 testfunc(0x66,0x77);
	0xff,0x16,0x00,0x00,
};

const int ST1M2RoRoCMD222[]={
	0xff140000,
	0xff110300,
	0xff040301,0x00131584,0x025d00f6,0x00000008,
	0xff080100,
	0xff160000,
};

const char ST1M2RoRoCMD3[] = {
	0xFF,0x14,0x00,0x00,//0x81b1c1=param_1,0x81b1c2=param_2
	0xFF,0x11,0x03,0x00,//0x81b1ce=param_1 AI?
	0xFF,0x04,0x03,0x01,0x00,0x13,0x05,0x84,0x02,0x5D,0x00,0xF6,0x00,0x00,0x00,0x01,//ActionType_1,ActionID_1,RoroPtr_4,x_2,y_2,z_2,RoroDirect_1,RoroCnt_1
	0xFF,0x04,0x03,0x01,0x00,0x13,0x05,0x84,0x02,0x5D,0x01,0x1E,0x00,0x00,0x00,0x01,
	0xFF,0x04,0x03,0x01,0x00,0x13,0x05,0x84,0x02,0x5D,0x01,0x46,0x00,0x00,0x00,0x01,
	0xFF,0x11,0x01,0x00,//0x81b1ce=param_1 AI?
	0xFF,0x04,0x00,0x04,0x00,0x11,0x39,0xE4,0x02,0xC1,0x01,0x0A,0x00,0x00,0x00,0x01,
	0xFF,0x04,0x00,0x04,0x00,0x11,0x39,0xE4,0x02,0xC1,0x01,0x32,0x00,0x00,0x00,0x01,
	0xFF,0x04,0x00,0x04,0x00,0x11,0x39,0xE4,0x02,0xC1,0x01,0x5A,0x00,0x00,0x00,0x01,
	0xFF,0x08,0x01,0x00,//剩下1个兵再继续执行
	0xFF,0x14,0x01,0x1E,//
	0xFF,0x11,0x00,0x00,//设置AI
	0xFF,0x04,0x01,0x00,0x00,0x11,0x11,0xAA,0x03,0x77,0x01,0x1C,0x00,0x00,0x00,0x01,//1个枪兵
	0xFF,0x04,0x01,0x00,0x00,0x11,0x39,0xE4,0x03,0x77,0x01,0x1C,0x00,0x00,0x00,0x02,//2个刀兵
	0xFF,0x08,0x01,0x00,//剩下1个兵再继续执行
	0xFF,0x04,0x01,0x00,0x00,0x11,0x39,0xE4,0x04,0x0A,0x01,0x8E,0x00,0x00,0x00,0x01,//1个枪兵
	0xFF,0x04,0x01,0x00,0x00,0x11,0x11,0xAA,0x04,0x0A,0x01,0x8E,0x00,0x00,0x00,0x02,//2个刀兵
	0xFF,0x08,0x00,0x00,//剩下0个兵再继续执行
	0xFF,0x16,0x00,0x00,//结束刷兵
};

const char ST1M2RoRoCMD2[] = {
	0xFF,0x14,0x00,0x00,
	0xFF,0x11,0x03,0x00,
	0xFF,0x04,0x03,0x01,0x00,0x13,0x05,0x84,0x02,0x5D,0x00,0xF6,0x00,0x00,0x00,0x01,
	0xFF,0x04,0x03,0x01,0x00,0x13,0x05,0x84,0x02,0x5D,0x01,0x1E,0x00,0x00,0x00,0x01,
	0xFF,0x04,0x03,0x01,0x00,0x13,0x05,0x84,0x02,0x5D,0x01,0x46,0x00,0x00,0x00,0x01,
	0xFF,0x11,0x01,0x00,
	0xFF,0x04,0x00,0x04,0x00,0x11,0x39,0xE4,0x02,0xC1,0x01,0x0A,0x00,0x00,0x00,0x01,
	0xFF,0x04,0x00,0x04,0x00,0x11,0x39,0xE4,0x02,0xC1,0x01,0x32,0x00,0x00,0x00,0x01,
	0xFF,0x04,0x00,0x04,0x00,0x11,0x39,0xE4,0x02,0xC1,0x01,0x5A,0x00,0x00,0x00,0x01,
	0xFF,0x08,0x01,0x00,
	0xFF,0x14,0x01,0x1E,
	0xFF,0x11,0x00,0x00,
	0xFF,0x04,0x01,0x00,0x00,0x11,0x11,0xAA,0x03,0x77,0x01,0x1C,0x00,0x00,0x00,0x01,
	0xFF,0x04,0x01,0x00,0x00,0x11,0x39,0xE4,0x03,0x77,0x01,0x1C,0x00,0x00,0x00,0x03,
	0xFF,0x08,0x01,0x00,
	0xFF,0x04,0x01,0x00,0x00,0x11,0x39,0xE4,0x04,0x0A,0x01,0x8E,0x00,0x00,0x00,0x01,
	0xFF,0x11,0x01,0x00,
	0xFF,0x04,0x01,0x00,0x00,0x11,0x11,0xAA,0x04,0x0A,0x01,0x8E,0x00,0x00,0x00,0x03,
	0xFF,0x08,0x03,0x00,
	0xFF,0x11,0x00,0x00,
	0xFF,0x09,0x02,0x00,
	0xFF,0x04,0x01,0x00,0x00,0x11,0x11,0xAA,0x04,0x0A,0x01,0x8E,0x00,0x00,0x00,0x01,
	0xFF,0x08,0x03,0x00,
	0xFF,0x04,0x01,0x00,0x00,0x11,0x11,0xAA,0x03,0x77,0x01,0x1C,0x00,0x00,0x00,0x01,
	0xFF,0x08,0x03,0x00,
	0xFF,0x0A,0x00,0x00,
	0xFF,0x08,0x00,0x00,
	0xFF,0x16,0x00,0x00,
};

const char ST1M2RoroDrop1[] = {
	0,5,0,7,0,0,0,0,0,0,0
};

const char ST1M2RoroDrop2[] = {
	0,5,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0
};

void ST1M2RoroFunc1() {
	return;
}

void ST1M2RoroFunc2() {
	return;
}

const struct RoroConfig ST1M2Roro[] = {
	{(int)&ST1M2RoRoCMD1,(int)&ST1M2RoroDrop1,sizeof(ST1M2RoroDrop1),0,18000,(int)&ST1M2RoroFunc1},//1-2人
	{(int)&ST1M2RoRoCMD2,(int)&ST1M2RoroDrop2,sizeof(ST1M2RoroDrop2),0,18000,(int)&ST1M2RoroFunc2},//3-4人
};

const int ST1M2RoroPtr[] = {
	(int)&ST1M2Roro[0],//1-2人刷兵
	(int)&ST1M2Roro[1],//3-4人刷兵
};

void ST1M2F6(int param_1) {
	char bVar1;
	//Print(0,0,8,3,0,"ST1M2F6 a1=%X",param_1);
	bVar1 = *(char *)(*(int *)(param_1 + 0xde) + 1);
	FUN_0017a936(param_1,bVar1 * 4 + bVar1 + 420,bVar1 * 4 + 283,0xFF20,0,1,0);//主角的出场动作
	return;
}

void ST1M2F5() {
	return;
}

void ST1M2F4(int param_1) {
	FUN_00192ef0(param_1);
	return;
}

void ST1M2F3() {
	return;
}

int ST1M2F2() {
	int iVar1;
	int i;

	switch(ST1M2_Fsm_0081b8fe) {
	case 0:

		if (ExecRoRoCMD_00191fac()) {//这里判断小兵是否清理完毕
			GoMessage_00196142(0,0x3dc,0x181,6,0);//GO箭头提示
			ST1M2_Fsm_0081b8fe += 1;
		}
		break;
	case 1:
		SetTime_001a56e4(12);//把时间设置到12秒
		FUN_0019639c(0);
		DU8(0x81b8ff) = 0;
		for(i=0; i<4; i++)
			PU8(0x81b904)[i] = 0;
		FUN_00179bac(0,1,0x1dd07a);
		if (DU8(0x81b908) != 0) {//这里判断2个喷火机关是否都打掉了
			GoMessage_00196142(1,0x35d,0x113,6,0);
			FUN_00179bac(1,2,0x1dd13a);//
			DU8(0x81b908) = 0;
		}
		ST1M2_Fsm_0081b8fe += 1;
		break;
	case 2:
		SetTime_001a56e4(20);//把时间设置到20秒
		if ((DU8(0x81b908)) && (!DU8(0x81b8ff))) {
			GoMessage_00196142(1,0x35d,0x113,6,0);
			FUN_00179bac(1,3,0x1dd13a);
			DU8(0x81b908) = 0;
		}
		FUN_001961da();
		iVar1 = FUN_0017f474();
		if ((iVar1 <= DU8(0x81b8ff)) && (iVar1 != 0))
			ST1M2_Fsm_0081b8fe = 3;
		break;
	case 3:
		FUN_00179c70(0);
		FUN_00179c70(1);
		FUN_00195434();//释放定时器
		FUN_00191d5e();//释放定时器
		api_delay(80);//延时1秒

		return 3;//返回3就是结束场景 返回4就结束关卡
	}
	return 0;
}














void ST1M2F1() {
	int PalID;
	int i;
	short OBJ;



	FUN_0017ed26();
	FUN_00159e3a();
	FUN_0017415c(0);
	FUN_001a6284(10);
	FUN_0017476e(1);
	LoadMapBit_00176e7a(0x32ba10,0);
	LoadMapBit_00176e7a(0x32d840,1);
	FUN_001795a2(PU32(0x3d14a0),2);//创建那两个喷火的机关
	LoadMapMask_00176e0e(0x338dfa,0,0);
	PalID = LoadMapPal_00176c18(0x24574c);
	FUN_00176fc0();
	FUN_00177738();
	FUN_00177302();
	for(i=0; i<4; i++) {
		OBJ = FUN_0016f530();
		SetSObj_0016f762(OBJ,0x3d0b40,i * 0x70,0,0,0);
		FUN_00171b16(OBJ,1,DU32(0x2ffbec));
		FUN_00171d16(OBJ,26);
		SetSObjPal_0016fc3e(OBJ,PalID);
	}
	FUN_00195420();
	FUN_00191bf4();


	//FUN_00191e7a(PU32(0x14384e),0);	//载入小兵配置
	LoadRoro_00191e7a((int)&ST1M2RoroPtr,0);

	DU8(0x81b8fe) = 0;
	for(i=0; i<9; i++)
		ExecRoRoCMD_00191fac();//每运行一次执行一行FF脚本

	api_bgpos(0x150,0x78);//设置场景当前坐标

	FUN_0018c188();
	ScreenUpdate_0018c492();
	PalFade_0014d278(0);
	FUN_00163138(0);

	api_bgrange(0x150,0x58,0x3f8,0x1e0);//设置场景边界

	OBJ = FUN_0016f530();
	FUN_0016f762(OBJ,0x3d0db4,0,0,0,0);
	FUN_0017f854(0);
	FUN_0017415c(1);
	DU8(0x81b901) = 0;
	DU8(0x81b908) = 0;
	FUN_00153976(0,6,6,0x2439b4,0,0,5,45,0,0,1,1);

	return;
}