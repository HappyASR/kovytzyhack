#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../game_type.h"
#include "../game_func.h"
#include "../game_api.h"
#include "stage.h"





void ST1M4F6(int param_1){
	char bVar1;
	//Print(0,0,8,3,0,"ST1M2F6 a1=%X",param_1);
	bVar1 = *(char *)(*(int *)(param_1 + 0xde) + 1);
	FUN_0017a936(param_1,bVar1 * -5 + -10,bVar1 * 4 + bVar1 + 0xa0,0,0,2,4);//主角的出场动作
	return;
}


void ST1M4F5(){
	return;
}

void ST1M4F4(int param_1){
	FUN_00192ef0(param_1);
	return;
}

void ST1M4F3(){
	return;
}


int ST1M4F2() {
	int i;
	int iVar1;

	switch(ST1M2_Fsm_0081b8fe) {
	case 0:
		if (ExecRoRoCMD_00191fac()) {
			GoMessage_00196142(0,0x2ee,0xb4,6,0);
			ST1M2_Fsm_0081b8fe += 1;
		}
		break;
	case 1:
		SetTime_001a56e4(0xc);
		DU8(0x81b8ff) = 0;
		for(i=0; i<4; i++)
			PU8(0x81b904)[i] = 0;
		FUN_00179bac(0,8,0x1de56c);
		ST1M2_Fsm_0081b8fe += 1;
		break;
	case 2:
		SetTime_001a56e4(0xc);
		FUN_001961da();
		iVar1 = FUN_0017f474();
		if ((iVar1 <= DU8(0x81b8ff)) && (iVar1 != 0))
			ST1M2_Fsm_0081b8fe = 3;
		break;
	case 3:
		FUN_00179c70(0);
		FUN_00195434();
		FUN_00191d5e();
		api_delay(80);
		FUN_001a6104(5);//去6场景
		return 3;
	}
	return 0;

}
















void ST1M4F1() {

	int i;
	short OBJ;

	FUN_0017ed26();
	FUN_00159e3a();
	FUN_0017415c(0);
	FUN_001a6284(11);
	FUN_0017476e(1);
	LoadMapBit_00176e7a(0x32bb28,0);
	LoadMapBit_00176e7a(0x32dc30,1);
	LoadMapMask_00176e0e(0x339c60,0,0);

	FUN_00176fc0();
	FUN_00177738();
	FUN_00177302();
	FUN_00195420();
	FUN_00191bf4();

	LoadRoro_00191e7a(0x14382e,0);

	DU8(0x81b8fe) = 0;
	for(i=0; i<9; i++)
		ExecRoRoCMD_00191fac();//每运行一次执行一行FF脚本
	api_arm(0x68,0);
	api_arm(0x7d,0x20);
	FUN_0018c188();
	ScreenUpdate_0018c492();
	PalFade_0014d278(0);

	OBJ = CreatSObj_0016f530();
	SetSObj_0016f762(OBJ,0x3d0db4,0,0,0,0);

	api_arm(0x13,0);
	api_arm(0x36,0);
	api_arm(0x24,0x330);
	api_arm(0x58,0x100);

	FUN_0017f854(60);
	FUN_0017415c(1);

	return;
}