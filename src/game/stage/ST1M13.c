#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../game_type.h"
#include "../game_func.h"
#include "stage.h"
#include "../game_api.h"
#include "../game_struct.h"
#include "../hook/hook.h"











void ST1M13Boss() {
	int EnemyID;
	RoroMem *RoroPtr;
	int rand;
	int CMD;

	DU16(0x81b936)=1;
	if(GetPlayerCnt_0017f474()<3 && !DU8(0x813536)) { //判断玩家数小于3，第一轮游戏
		EnemyID = CreatEnemy_00155894();
		BossMem[0].EnemyID = EnemyID;
		rand=rand_00150e52(0x400);
		rand=rand%4;
		SetEnemyData_00156024(EnemyID,PU32(0x3d17ce)[rand],764,272,0,1,(int)(rand==1));
		RoroPtr = GetRoroPtrByEnemyID_00159bd6(EnemyID);
		FUN_0015a154(RoroPtr,0);
		CMD = GetRoroActionDataPtr_001596de(RoroPtr,2,1);
		SetRoroActionByActionDataPtr_00159864(RoroPtr,CMD);
		RoroPtr->HP = 328;
		RoroPtr->field_0xf5 = 60;
		DrawBossInfo(RoroPtr);

		EnemyID = CreatEnemy_00155894();
		BossMem[1].EnemyID = EnemyID;
		rand=rand_00150e52(0x400);
		rand=rand%4;
		SetEnemyData_00156024(EnemyID,PU32(0x3d17ce)[rand],764,272,0,1,(int)(rand==1));
		RoroPtr = GetRoroPtrByEnemyID_00159bd6(EnemyID);
		FUN_0015a154(RoroPtr,0);
		CMD = GetRoroActionDataPtr_001596de(RoroPtr,2,1);
		SetRoroActionByActionDataPtr_00159864(RoroPtr,CMD);
		RoroPtr->HP = 328;
		RoroPtr->field_0xf5 = 60;
		DrawBossInfo(RoroPtr);

		EnemyID = CreatEnemy_00155894();
		BossMem[2].EnemyID = EnemyID;
		rand=rand_00150e52(0x400);
		rand=rand%4;
		SetEnemyData_00156024(EnemyID,PU32(0x3d17ce)[rand],764,272,0,1,(int)(rand==1));
		RoroPtr = GetRoroPtrByEnemyID_00159bd6(EnemyID);
		FUN_0015a154(RoroPtr,0);
		CMD = GetRoroActionDataPtr_001596de(RoroPtr,2,1);
		SetRoroActionByActionDataPtr_00159864(RoroPtr,CMD);
		RoroPtr->HP = 328;
		RoroPtr->field_0xf5 = 60;
		DrawBossInfo(RoroPtr);
		
		DU16(0x81b934) = 0;
		if(rand>1)
			DU16(0x81b936)=0;
		
	} else { //3-4人或者第二轮
		EnemyID = CreatEnemy_00155894();
		BossMem[0].EnemyID = EnemyID;
		SetEnemyData_00156024(EnemyID,0x10a3ea,764,272,0,1,0);
		RoroPtr = GetRoroPtrByEnemyID_00159bd6(EnemyID);
		FUN_0015a154(RoroPtr,0);
		CMD = GetRoroActionDataPtr_001596de(RoroPtr,2,1);
		SetRoroActionByActionDataPtr_00159864(RoroPtr,CMD);
		RoroPtr->HP = 320;
		RoroPtr->field_0xf5 = 60;
		DrawBossInfo(RoroPtr);

		EnemyID = CreatEnemy_00155894();
		BossMem[1].EnemyID = EnemyID;
		rand=rand_00150e52(0x400);
		if(rand<0x201) {
			SetEnemyData_00156024(EnemyID,0x366830,800,300,0,1,0);
			DU16(0x81b936) = 0;
		} else
			SetEnemyData_00156024(EnemyID,0x10a47e,800,300,0,1,1);
		RoroPtr = GetRoroPtrByEnemyID_00159bd6(EnemyID);
		CMD = GetRoroActionDataPtr_001596de(RoroPtr,2,1);
		SetRoroActionByActionDataPtr_00159864(RoroPtr,CMD);
		RoroPtr->HP = 320;
		RoroPtr->field_0xf5 = 60;
		DrawBossInfo(RoroPtr);
		DU16(0x81b934) = 1;
	}
	return;
}


void ST1M13F6(int RoleMem) {
	char bVar1;
	//Print(0,0,8,3,0,"ST1M13F6 a1=%d,%06X",RoleMem);
	bVar1 = *(char *)(*(int *)(RoleMem + 0xde) + 1);
	FUN_0017a936(RoleMem,(u16)bVar1 * 4 + (u16)bVar1 + 0x241,(u16)bVar1 * 2 + 0x9d,0,0,2,0x34);
	return;
}


void ST1M13F5(int param_1) {
	char *pbVar1;
	char bVar2;
	char *pbVar3;
	char bVar4;
	char *pbVar5;
	char bVar6;
	//Print(0,0,10,3,0,"ST1M13F5 a1=%d,%06X",param_1);
	FUN_001e3e9a(param_1,0x226,0x118);
	DU8(0x81b92e) += 1;
	if (DU16(0x81b934) == 0) {
		if (DU16(0x813536) == 0) {
			bVar6 = 7;
			pbVar5 = (char*)PU32(0x3d1844);
			bVar4 = 4;
			pbVar3 = (char*)PU32(0x3d1840);
			bVar2 = 3;
			pbVar1 = (char*)PU32(0x3d183c);
		} else {
			bVar6 = 3;
			pbVar5 = (char*)PU32(0x3d184e);
			bVar4 = 2;
			pbVar3 = (char*)PU32(0x3d184c);
			bVar2 = 1;
			pbVar1 = (char*)PU32(0x3d184b);
		}
		FUN_00193916(0x226,0x118,pbVar1,bVar2,pbVar3,bVar4,pbVar5,bVar6);

	} else {
		DU16(0x81b934) += -1;
	}
	return;
}



void ST1M13F4(int param_1) {
	//Print(0,0,12,3,0,"ST1M13F4 a1=%d,%06X",param_1);
	FUN_00192ef0(param_1);
	return;
}

void ST1M13F3() {
	return;
}


int ST1M13F2() {
	switch(DU8(0x81b92e)) {
	case 1:
		DU8(0x81b92e) = 5;
		break;
	case 4:
		DU8(0x81b92e) = 5;
		break;
	case 5:
		FUN_00159e3a();
		FUN_0019639c(0);
		FUN_00195434();
		FUN_00191d5e();
		FUN_001a61ee(1);
		FUN_001a6104(0x19);
		ExecFunc_0014f2c4(0x1a4,(int)&ScreenUpdate_0018c492);
		return 4;
	}
	return 0;
}

void ST1M13F1() {//_001e3a70
	int PalID;
	short ObjID;
	int i;

	FUN_0017ed26();//stop player control 0x8129b8=0 让玩家角色不能控制也不会挨打
	FUN_00159e3a();//让敌方不攻击 0x80dcda=0
	FUN_0017415c(0);//作用不明 0x81762=param_1
	FUN_001a6284(0x20);//根据GroupID播放音乐
	FUN_0017476e(1);//意义不明 0x812761 =param_1
	FUN_00176e7a(PU32(0x32e18c),1);//LoadMapBit
	FUN_00176e28(0);//arm 0xad,param_1
	PalID = LoadMapPal_00176c18(PU32(0x24574c));
	SetPal_0014ce68(2,0x15,PU32(0x24588c));//pal
	SetPal_0014ce68(2,0x14,PU32(0x2458cc));
	SetPal_0014ce68(2,0x13,PU32(0x24590c));
	FUN_00176fc0();//显示最底层背景
	FUN_00177738();//显示上一层背景
	FUN_00177302();//清空一些设置，比如地图移动范围
	for (i = 0; i < 4; i++) {
		ObjID = FUN_0016f530()&0xffff;
		FUN_0016f762(ObjID,PU32(0x3d0b40),i * 0x70,0,0,0);
		FUN_00171b16(ObjID,1,DU32(0x2ffbec));
		FUN_00171d16(ObjID,0x15);
		FUN_0016fc3e(ObjID,PalID);
	}
	FUN_00195420();//意义不明
	FUN_00191bf4();//意义不明
	api_bgpos(0x19f,0x78);
	api_bgrange(0x100,0x58,0x3f8,0x1e0);

	DU16(0x81b934) = 0;
	//FUN_001e3864();//这里创建了BOSS和血条等
	ST1M13Boss();
	if (DU16(0x81b934) == 0) {
		DU8(0x81b92e) = 0;
	} else {
		DU8(0x81b92e) = 2;
	}
	FUN_001e3852();//淡入
	ObjID = FUN_0016f530();
	FUN_0016f762(ObjID,PU32(0x3d0db4),0,0,0,0);
	FUN_0017f854(0x3c);//意义不明
	FUN_0017415c(1);//0x817262=param_1
	return;
}