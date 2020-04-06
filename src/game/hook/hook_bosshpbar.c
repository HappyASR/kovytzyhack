#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../game_type.h"
#include "../game_func.h"
#include "../game_api.h"
#include "../game_struct.h"
#include "hook.h"


struct BossInfo BossMem[3];

const u16 BossHPTiles[16]={
	0xC551,
	0xC546,
	0xC53B,
	0xC530,
	0xC525,
	0xC51A,
	0xC50F,
	0xC504,
	0xC551,
	0xC546,
	0xC53B,
	0xC530,
	0xC525,
	0xC51A,
	0xC50F,
	0xC504,	
};


const u16 BossHPPal[8][16]= {
	//                 ,,,扣血颜色,,    底色,,,,
	{0x0040,0x7bda,0x5000,0x8000,0x0200,0xfc00,0x00da,0x02df,0x0040,0x7bda,0x5000,0x8000,0x0200,0xfc00,0x00da,0x02df},//第一层 刷子黑 背景红
	{0x0040,0x7bda,0x5000,0xfc00,0x0200,0xfe00,0x00da,0x02df,0x0040,0x7bda,0x5000,0x8000,0x0200,0xfc00,0x00da,0x02df},//第二层 刷子红 背景橙
	{0x0040,0x7bda,0x5000,0xfe00,0x0200,0xffe0,0x00da,0x02df,0x0040,0x7bda,0x5000,0x8000,0x0200,0xfc00,0x00da,0x02df},//第三层 刷子橙 背景黄
	{0x0040,0x7bda,0x5000,0xffe0,0x0200,0x83e0,0x00da,0x02df,0x0040,0x7bda,0x5000,0x8000,0x0200,0xfc00,0x00da,0x02df},//第四层 刷子黄 背景绿
	{0x0040,0x7bda,0x5000,0x83e0,0x0200,0x823f,0x00da,0x02df,0x0040,0x7bda,0x5000,0x8000,0x0200,0xfc00,0x00da,0x02df},//第五层 刷子绿 背景蓝
	{0x0040,0x7bda,0x5000,0x823f,0x0200,0xc21f,0x00da,0x02df,0x0040,0x7bda,0x5000,0x8000,0x0200,0xfc00,0x00da,0x02df},//第六层 刷子蓝 背景紫
	{0x0040,0x7bda,0x5000,0xc21f,0x0200,0xc210,0x00da,0x02df,0x0040,0x7bda,0x5000,0x8000,0x0200,0xfc00,0x00da,0x02df},//第七层 刷子紫 背景灰
	{0x0040,0x7bda,0x5000,0xc210,0x0200,0xffff,0x00da,0x02df,0x0040,0x7bda,0x5000,0x8000,0x0200,0xfc00,0x00da,0x02df} //第八层 刷子灰 背景白
};



void ClearBossInfo(int RoroUseID) {
	int i;
	int off;
	off = 0x904024 + (21+ RoroUseID * -2)*0x100;
	for(i=0; i<128; i++) {

		DU32(off) = 0;
		off += 4;
	}
	FUN_0014cdb6(DU8(0x813ac8));
	FUN_00154458(BossMem[RoroUseID].DisplayID);
	FUN_00154458(BossMem[RoroUseID].DisplayID2);

	BossMem[RoroUseID].HPBarUse = 0;
	BossMem[RoroUseID].RoroStatus = 0;
	return;
}

int ChkBossUse() {
	int i;
	for(i=0; i<2; i++) {
		if(DU8(0x813544+i*706)==0)
			return i;
	}
	return 2;
}

void DrawBossHPBar(int RoroUseID,RoroMem *RoroPtr) {
	int i;

	BossMem[RoroUseID].EnemyID = ((int)RoroPtr - 0x80cf1e) / 0x1b6;
	if(RoroPtr->HP <= BOSS_HP_BAR_SIZE)
		BossMem[RoroUseID].Lifes = 0;
	else {
		if(RoroPtr->HP % BOSS_HP_BAR_SIZE ==0)
			BossMem[RoroUseID].Lifes = RoroPtr->HP/BOSS_HP_BAR_SIZE -1;
		else
			BossMem[RoroUseID].Lifes = RoroPtr->HP/BOSS_HP_BAR_SIZE;
	}
	//Print(0,4,8+RoroUseID,0,0,"%X",BossMem[i].Lifes);

	BossMem[RoroUseID].HPTiles[0] = 0;
	BossMem[RoroUseID].HPTiles[1] = 0;
	BossMem[RoroUseID].HPTiles[0] = 0xC55C;
	BossMem[RoroUseID].HPTiles[1] &= 0xC1;
	switch(RoroUseID) {
	case 0:
		BossMem[RoroUseID].HPTiles[1] ^= BOSS0_HP_PALID;
		break;
	case 1:
		BossMem[RoroUseID].HPTiles[1] ^= BOSS1_HP_PALID;
		break;
	case 2:
		BossMem[RoroUseID].HPTiles[1] ^= BOSS2_HP_PALID;
		break;
	}

	for(i=0; i<BOSS_HP_BAR_SIZE/8; i++) {
		BossMem[RoroUseID].HPTiles[i*2+2] = 0;
		BossMem[RoroUseID].HPTiles[i*2+3] = 0;
		if(i >= (RoroPtr->HP % BOSS_HP_BAR_SIZE) / 8 && RoroPtr->HP % BOSS_HP_BAR_SIZE != 0)
			BossMem[RoroUseID].HPTiles[i*2+2] = BossHPTiles[BossMem[RoroUseID].Lifes]+9;
		else
			BossMem[RoroUseID].HPTiles[i*2+2] = BossHPTiles[BossMem[RoroUseID].Lifes]+1;
		BossMem[RoroUseID].HPTiles[i*2+3] &= 0xC1;
		switch(RoroUseID) {
		case 0:
			BossMem[RoroUseID].HPTiles[i*2+3] ^= BOSS0_HP_PALID;
			break;
		case 1:
			BossMem[RoroUseID].HPTiles[i*2+3] ^= BOSS1_HP_PALID;
			break;
		case 2:
			BossMem[RoroUseID].HPTiles[i*2+3] ^= BOSS2_HP_PALID;
			break;
		}
	}

	BossMem[RoroUseID].HPTiles[i*2+2] = 0;
	BossMem[RoroUseID].HPTiles[i*2+3] = 0;
	BossMem[RoroUseID].HPTiles[i*2+2] = 0xC55C+10;
	BossMem[RoroUseID].HPTiles[i*2+3] &= 0xC1;
	switch(RoroUseID) {
	case 0:
		BossMem[RoroUseID].HPTiles[i*2+3] ^= BOSS0_HP_PALID;
		break;
	case 1:
		BossMem[RoroUseID].HPTiles[i*2+3] ^= BOSS1_HP_PALID;
		break;
	case 2:
		BossMem[RoroUseID].HPTiles[i*2+3] ^= BOSS2_HP_PALID;
		break;
	}

	BossMem[RoroUseID].HPBarUse = 2;
	BossMem[RoroUseID].RoroStatus = 2;
	if(RoroPtr->HP%BOSS_HP_BAR_SIZE == 0)
		BossMem[RoroUseID].HPNowpos =  BOSS_HP_BAR_SIZE/8;
	else
		BossMem[RoroUseID].HPNowpos = (RoroPtr->HP % BOSS_HP_BAR_SIZE)/8;
	BossMem[RoroUseID].HPChangeVal = 0;
	BossMem[RoroUseID].Bit = 8;
	BossMem[RoroUseID].HPTilesPtr = (21 + RoroUseID * -2 + 1)*0x100 + 0x904024;
	Print(0,10,21-RoroUseID*2,1,0,"LIFE=%02d",BossMem[RoroUseID].Lifes);
	Print(0,18,21-RoroUseID*2,1,0,"HP=%d      ",RoroPtr->HP * 100);
	FUN_0016e0fa(FUN_0016e098(BossMem[RoroUseID].HPTiles),0,i+2,1,BossMem[RoroUseID].HPTilesPtr,0);
	BossMem[RoroUseID].HPTilesPtr += BossMem[RoroUseID].HPNowpos * 4;


	return;

}



void ChangeBossHpBar(int RoroUseID) {
	int i;
	RoroMem *RoroPtr;

	if(BossMem[RoroUseID].HPChangeVal != 0) {
		if(BossMem[RoroUseID].HPChangeVal<0) {
			if(BossMem[RoroUseID].Bit ==0) {
				BossMem[RoroUseID].Bit = 8;
				BossMem[RoroUseID].HPTilesPtr += -4;
				BossMem[RoroUseID].HPNowpos += -1;
				if(BossMem[RoroUseID].HPNowpos==0 && BossMem[RoroUseID].Lifes!=0) {
					BossMem[RoroUseID].Lifes += -1;
					for(i=0; i<BOSS_HP_BAR_SIZE/8; i++) {
						BossMem[RoroUseID].HPTilesPtr += 4;
						DU16(BossMem[RoroUseID].HPTilesPtr) = BossHPTiles[BossMem[RoroUseID].Lifes]+1;
					}
					
					BossMem[RoroUseID].HPNowpos = BOSS_HP_BAR_SIZE/8;
				}
			}
			BossMem[RoroUseID].Bit += -1;
			DU16(BossMem[RoroUseID].HPTilesPtr) = BossHPTiles[BossMem[RoroUseID].Lifes] + 9 - BossMem[RoroUseID].Bit;
			BossMem[RoroUseID].HPChangeVal += 1;
			

		} else {
			if(BossMem[RoroUseID].Bit ==8) {
				BossMem[RoroUseID].Bit = 0;
				BossMem[RoroUseID].HPTilesPtr += 4;
				BossMem[RoroUseID].HPNowpos += 1;
				if(BossMem[RoroUseID].HPNowpos == BOSS_HP_BAR_SIZE/8 + 1) {
					BossMem[RoroUseID].HPTilesPtr -= (BOSS_HP_BAR_SIZE/8-1) * 4;
					BossMem[RoroUseID].Lifes += 1;
					for(i=0; i<BOSS_HP_BAR_SIZE/8; i++) {
						BossMem[RoroUseID].HPTilesPtr += 4;
						DU16(BossMem[RoroUseID].HPTilesPtr) = BossHPTiles[BossMem[RoroUseID].Lifes]+9;						
					}
					
					BossMem[RoroUseID].HPNowpos = 1;
					BossMem[RoroUseID].HPTilesPtr -= (BOSS_HP_BAR_SIZE/8-1) * 4;
				}

			}
			BossMem[RoroUseID].Bit += 1;
			DU16(BossMem[RoroUseID].HPTilesPtr) = BossHPTiles[BossMem[RoroUseID].Lifes] + 9 - BossMem[RoroUseID].Bit;
			BossMem[RoroUseID].HPChangeVal += -1;
		}
		RoroPtr = GetRoroPtrByEnemyID_00159bd6(BossMem[RoroUseID].EnemyID);
		if(BossMem[RoroUseID].HPBarUse) {
			Print(0,10,21-RoroUseID*2,1,0,"LIFE=%02d",BossMem[RoroUseID].Lifes);
			Print(0,18,21-RoroUseID*2,1,0,"HP=%d      ",RoroPtr->HP * 100);
		} else {
			Print(0,10,21-RoroUseID*2,1,0,"              ");
			Print(0,18,21-RoroUseID*2,1,0,"              ");
		}

	}


	return;
}



void ChangeBossHP(int RoroUseID,short param_2) {
	FUN_0018c35e();
	BossMem[RoroUseID].HPChangeVal += param_2;
	FUN_0018c374();
}


void ChkBossHP() {
	int i;
	DU8(0x813ac9) += 1;
	if(DU8(0x813aca)<=DU8(0x813ac9)) {
		DU8(0x813ac9)=0;
		for(i=0; i<3; i++) {
			if(BossMem[i].HPBarUse==2)
				ChangeBossHpBar(i);
		}
	}
	return;
}

void DrawBossHead(int RoroUseID,RoroMem *RoroPtr) {



	BossMem[RoroUseID].RoroStatus = 1;
	BossMem[RoroUseID].DisplayID = FUN_0015420a();
	FUN_0015424e(BossMem[RoroUseID].DisplayID,(int*)&BossMem[RoroUseID].HeadOBJPtr,0x7fff);
	BossMem[RoroUseID].DisplayID2 = FUN_0015420a();
	FUN_0015424e(BossMem[RoroUseID].DisplayID2,(int*)&BossMem[RoroUseID].NameOBJPtr,0x7fff);

	if(RoroUseID==0) {
		if(FUN_001a5776())
			SetPal_0014c2da(0,10,PU32(0x303914)[RoroPtr->RoroRom2->RoleId]);
		DU8(0x813ac8) = SetFadePal_0014ce68(0,10,PU32(0x303914)[RoroPtr->RoroRom2->RoleId]);
	}
	FUN_00153c76((int)&BossMem[RoroUseID].HeadOBJPtr,0,(21+RoroUseID * -2) * 8,0x25aeb4,RoroPtr->RoroRom2->RoleId,0,0,8,0x631ddc,0x10,0x10,0,0);

	FUN_00153c76((int)&BossMem[RoroUseID].NameOBJPtr,0x18,(21+RoroUseID * -2) * 8,0x25aeb4,RoroPtr->RoroRom2->RoleId+62,0,0,4,0x631ddc,0x10,0x10,0,0);

	FUN_001544fe(BossMem[RoroUseID].DisplayID,2);
	FUN_001544fe(BossMem[RoroUseID].DisplayID2,2);

	return;
}



void DrawBossInfo(RoroMem *RoroPtr) {
	int RoroUseID;

	if(DU8(0x81352b)!=2 && !(RoroPtr->Color & 0x20)) {
		SetMotionTime_001a5708(99);
		RoroUseID = ChkBossUse();
		if(ChkBossUse()<2)
			RoroPtr->RoroUseID = RoroUse_0018f1c8();
		RoroPtr->RoroUseID = RoroUseID;
		DrawBossHead(RoroUseID,RoroPtr);
		DrawBossHPBar(RoroUseID,RoroPtr);
		RoroPtr->Color ^= 0x20;
	}
	return;
}
