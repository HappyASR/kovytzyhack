#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../game_type.h"
#include "../game_func.h"
#include "../game_api.h"
#include "stage.h"





void ST1M6F6(int param_1) {
	char bVar1;
	//Print(0,0,8,3,0,"ST1M2F6 a1=%X",param_1);
	if(DU8(0x81352b)!=2){
	bVar1 = *(char *)(*(int *)(param_1 + 0xde) + 1);
	FUN_0017a936(param_1,bVar1 * -5 + -10,bVar1 * 4 + bVar1 + 0xa0,0,0,2,4);//主角的出场动作
	}
	return;
}


void ST1M6F5() {
	return;
}

void ST1M6F4(int param_1) {
	int iVar1;
	
	FUN_00192ef0(param_1);
	if(DU16(0x81b90c)){
		iVar1 = FUN_00159bd6(param_1);
		if((((iVar1!=0) && (*(char *)(*(int *)(param_1 + 0xde) + 1)==0)) && (DU16(0x81b90c)=0, *(char *)(iVar1 + 0x152) == 6)) && (*(char *)(iVar1 + 0x153) == 4)){
			FUN_00169602(*(ushort *)(iVar1 + 0x14),*(ushort *)(iVar1 + 0x16),*(short *)(iVar1 + 0x17c),0x58,0,0);
		}
	}
	return;
}

void ST1M6F3() {
	return;
}


int ST1M6F2() {
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
		FUN_00179bac(0,10,0x1de56c);
		ST1M2_Fsm_0081b8fe += 1;
		break;
	case 2:
		SetTime_001a56e4(0xc);
		FUN_001dfb40();//这里需要判断是否有2人以上站在洞上
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
		DU8(0x81b900) = 6;
		FUN_001a6104(4);//去5场景
		return 3;
	case 4:
		FUN_0019639c(0);
		FUN_0017ed26();
		FUN_00159e3a();
		FUN_0017f538();
		FUN_001dfc1c();
		api_delay(80);
		FUN_001dfbb2();
		FUN_00195434();
		FUN_00191d5e();
		api_delay(46);
		FUN_001a6104(11);//去12场景
		return 3;
	}
	return 0;

}
















void ST1M6F1() {
	int Pal;
	int i;
	short OBJ;

	FUN_0017ed26();
	FUN_00159e3a();
	FUN_0017415c(0);
	FUN_001a6284(11);
	FUN_0017476e(1);
	LoadMapBit_00176e7a(0x32bbd0,0);
	LoadMapBit_00176e7a(0x32de44,1);
	LoadMapMask_00176e0e(0x339c60,0,0);
	FUN_001795a2(0x3d14fa,1);
	Pal = LoadMapPal_00176c18(0x24570c);
	FUN_00176fc0();
	FUN_00177738();
	FUN_00177302();
	DU8(0x81b909) = CreatSObj_0016f530();
	SetSObj_0016f762(DU8(0x81b909),0x3d08dc,0x24c,0x72,0,0);
	FUN_00171b16(DU8(0x81b909),1,1);
	SetSObjPal_0016fc3e(DU8(0x81b909),Pal);

	FUN_00195420();
	FUN_00191bf4();

	LoadRoro_00191e7a(0x143836,0);

	DU8(0x81b8fe) = 0;
	for(i=0; i<9; i++)
		ExecRoRoCMD_00191fac();//每运行一次执行一行FF脚本
	api_arm(0x68,0);
	api_arm(0x7d,0x20);
	FUN_0018c188();
	ScreenUpdate_0018c492();
	if(DU8(0x81352b)==2)
		FUN_0014d332();
	else
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