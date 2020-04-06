#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../game_type.h"
#include "../game_func.h"
#include "../game_api.h"
#include "stage.h"





void ST1M10F6(int param_1) {
	char bVar1;
	//Print(0,0,8,3,0,"ST1M2F6 a1=%X",param_1);
	
	bVar1 = *(char *)(*(int *)(param_1 + 0xde) + 1);
	if(DU8(0x81b900!=10))
		FUN_0017a936(param_1,bVar1 * 4 + bVar1+0x241,bVar1 * 2 +  0x9d,0,(int)(DU8(0x81b900)==10),2,0x34);//主角的出场动作
	else
		FUN_0017a936(param_1,bVar1 * -2 + 0x400,bVar1 * 2 +  0x18b,0,(int)(DU8(0x81b900)==10),2,0x36);//主角的出场动作
	return;
}


void ST1M10F5() {
	return;
}

void ST1M10F4(int param_1) {
	int iVar1;
	
	FUN_00192ef0(param_1);
	if(DU16(0x81b90e)){
		iVar1 = FUN_00159bd6(param_1);
		if((((iVar1!=0) && (*(char *)(*(int *)(param_1 + 0x48) + 1)==40)) && (DU16(0x81b90e)=0, *(char *)(iVar1 + 0x152) == 6)) && (*(char *)(iVar1 + 0x153) == 10)){
			FUN_00169602(*(ushort *)(iVar1 + 0x14),*(ushort *)(iVar1 + 0x16),*(short *)(iVar1 + 0x17c),0x51,0,0);
		}
	}
	return;
}

void ST1M10F3() {
	return;
}


int ST1M10F2() {



	api_arm(0x6a,0x0f);
	FUN_0019acf8();//这个是取ARM的返回值

	switch(ST1M2_Fsm_0081b8fe) {
	case 0:
		if (ExecRoRoCMD_00191fac()) {
			ST1M2_Fsm_0081b8fe += 1;
		}
		break;
	case 1:
		ST1M2_Fsm_0081b8fe += 1;
		break;
	case 2:
		FUN_001e0f8a();
		LoadRoro_00191e7a(0x143876,1);
		ST1M2_Fsm_0081b8fe += 1;
		break;
	case 3:
		ExecRoRoCMD_00191fac();
		break;
	case 4:
		FUN_00179c70(0);
		FUN_00159e3a();
		FUN_0019639c(0);
		FUN_00195434();
		FUN_00191d5e();
		api_delay(420);
		return 4;
	}
	return 0;

}
















void ST1M10F1() {

	int i;
	short OBJ;
	short PalID;

	FUN_0017ed26();
	FUN_00159e3a();
	FUN_0017415c(0);
	FUN_001a6284(20);
	FUN_0017476e(1);

	LoadMapBit_00176e7a(0x32e18c,1);
	if(DU8(0x81b900)==10)
		FUN_001795a2(0x3d156a,2);
	else
		FUN_001795a2(0x3d1552,2);
	FUN_00176e28(0);

	PalID = LoadMapPal_00176c18(0x24574c);
	LoadMapPal_00176c18(0x269810);
	SetFadePal_0014ce68(2,0x15,0x24588c);
	SetFadePal_0014ce68(2,0x14,0x2458cc);
	SetFadePal_0014ce68(2,0x13,0x24590c);
	FUN_00176fc0();
	FUN_00177738();
	FUN_00177302();

	for (i = 0; i < 4; i++) {
		OBJ = FUN_0016f530()&0xffff;
		FUN_0016f762(OBJ,0x3d0b40,i * 0x70,0,0,0);
		FUN_00171b16(OBJ,1,DU32(0x2ffbec));
		FUN_00171d16(OBJ,0x15);
		FUN_0016fc3e(OBJ,PalID);
	}

	FUN_00195420();
	FUN_00191bf4();

	LoadRoro_00191e7a(0x143876,0);

	DU8(0x81b8fe) = 0;
	if(DU8(0x81b900)==10)
		api_bgpos(0x220,0xe0);
	else
		api_bgpos(0x100,0x78);
	FUN_0018c188();
	ScreenUpdate_0018c492();
	PalFade_0014d278(0);

	api_bgrange(0x100,0x58,0x3f8,0x1e0);
	OBJ = CreatSObj_0016f530();
	SetSObj_0016f762(OBJ,0x3d0db4,0,0,0,0);

	if(DU8(0x81b900)==10)
		FUN_0017f854(60);


	FUN_0017415c(1);
	api_arm(0x60,0xf00);
	api_arm(0x5e,0);
	DU16(0x81b90e)=1;


	return;
}