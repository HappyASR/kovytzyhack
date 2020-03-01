#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game_type.h"
#include "game_func.h"






void _hook(int a1)
{
	Print(0,2,8,3,0,"          ");
	Print(0,2,8,3,0,"A1=%06X",a1);//0x813544 10字节的结构体
}

void _DrawTileFnt(int param_1,char param_2,uint param_3,char param_4,int param_5,char param_6)
{
	//Print_00153452(0,2,8,3,0,"                                                  ");
	//Print_00153452(0,2,8,3,0,"a1=%06X a2=%d a3=%d a4=%06X a5=%06X a6=%d",param_1,param_2,param_3,param_4,param_5,param_6);
	
	//JOIN IN : 2,0,19,2,
	//BOSS1 905624
	//投币提示 1,0,19,2,904074,0
	//INSERT COIN：0,0,19,2,905A04,0
	//
          int iVar1;
          
          iVar1 = param_1 * 0xe;
          PU16(0x80e156)[param_1 * 7] = param_3;
          PU8(0x80e154)[iVar1] = param_4;
		  DU32(0x80e15c+iVar1) = param_5;
          PU8(0x80e153)[iVar1] = PU8(0x80e153)[iVar1] & 0xbf;
          PU8(0x80e153)[iVar1] = PU8(0x80e153)[iVar1] | (char)((param_2 & 1) << 6);
          PU8(0x80e153)[iVar1] = PU8(0x80e153)[iVar1] & 0xdf;
          PU8(0x80e153)[iVar1] = PU8(0x80e153)[iVar1] | (char)((param_6 & 1) << 5);
          PU8(0x80e152)[iVar1] = 2;
          return;
	
	
	
	
	

}


void _CreatBossHpBar(int a1,int BossMem)
{

	Print(0,2,8,3,0,"                                                  ");
	Print(0,2,8,3,0,"a1=%d,a2=%06X",a1,BossMem);


	return;
}