#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../game_type.h"
#include "../game_func.h"
#include "../stage/stage.h"
#include "../game_api.h"



/*投币开始界面*/
int PageStartGame() {
	int iVar1;
	int iVar2;
	int D2=0;
	int Timer1;
	int D4=9;



	InitFnt_0015280a();
	FUN_0016d2fc();
	FUN_00151662(0,-1,0);
	FUN_00197080();//绘制背景动态界面
	FUN_0015231a();//绘制Credit标签
	iVar1 = CreatSObj_0016f530();
	SetSObj_0016f762(iVar1,PU32(0x31bb5c),400,0xb0,0,0);//倒计时数字
	FUN_00171d16(iVar1,0xb0);
	FUN_00171b16(iVar1,1,500);
	iVar2 = CreatSObj_0016f530();
	SetSObj_0016f762(iVar2,PU32(0x31bbe4),0,0,0,0);//PRESS START BUTTON
	FUN_00171d16(iVar2,0x55);
	SetSObjPal_0016fc3e(iVar2,0x11);
	FUN_00171966(iVar2);
	FUN_00171b16(iVar2,1,500);
	SetPal_0014ce68(2,0x1e,PU32(0x25c62c));
	SetPal_0014ce68(2,0x1d,PU32(0x26e8a2));
	SetFntPal_00152b92();
	FUN_0014db72(0);//淡入
	// FUN_0019892c();//return
	FUN_0014f2c4(0x3c,(int*)&ScreenUpdate_0018c492);

	Timer1 = CreatTimer_0014f178();
	SetTimer_0014f236(Timer1,0x50);
	while(D4>0) {
		SetTimer_0014f236(Timer1,0x50);
		D4 += -1;

		FUN_00171d16(iVar1,D4 + 0xa7);//这是切换倒计时的数字显示
		if(!D4) {
			PlaySound_001f6d34(0,6,0xff,0);
		} else {
			PlaySound_001f6d34(0,5,0xff,0);
		}
		while(ChkTimer_0014f224(Timer1)!=0) {
			ScreenUpdate_0018c492();
			if( ChkKeyPress_0014f962(1)) { //如果按下了1P开始键
				if(FUN_00173c08(0)) {
					D2 = 0;
					FUN_001873b0();
					FreeTimer_0014f1c6(Timer1);
					FUN_00152736();
					FUN_00152712();
					FUN_0016f3be();
					FUN_0015418e();
					FUN_0014d5a6();
					ScreenUpdate_0018c492();
					return D2;
				}
			} else if( ChkKeyPress_0014f962(9)) { //如果按下了2P开始键
				if(FUN_00173c08(1)) {
					D2 = 1;
					FUN_001873b0();
					FreeTimer_0014f1c6(Timer1);
					FUN_00152736();
					FUN_00152712();
					FUN_0016f3be();
					FUN_0015418e();
					FUN_0014d5a6();
					ScreenUpdate_0018c492();
					return D2;
				}
			} else if( ChkKeyPress_0014f962(17)) { //如果按下了3P开始键
				if(FUN_00173c08(3)) {
					D2 = 3;
					FUN_001873b0();
					FreeTimer_0014f1c6(Timer1);
					FUN_00152736();
					FUN_00152712();
					FUN_0016f3be();
					FUN_0015418e();
					FUN_0014d5a6();
					ScreenUpdate_0018c492();
					return D2;
				}
			} else if( ChkKeyPress_0014f962(25)) { //如果按下了4P开始键
				if(FUN_00173c08(3)) {
					D2 = 3;
					FUN_001873b0();
					FreeTimer_0014f1c6(Timer1);
					FUN_00152736();
					FUN_00152712();
					FUN_0016f3be();
					FUN_0015418e();
					FUN_0014d5a6();
					ScreenUpdate_0018c492();
					return D2;
				}
			}

		}
		if (D4 <= 0)
			break;



	}


	FUN_001873b0();
	FreeTimer_0014f1c6(Timer1);
	FUN_00152736();
	FUN_00152712();
	FUN_0016f3be();
	FUN_0015418e();
	FUN_0014d5a6();
	ScreenUpdate_0018c492();
	return D2;
}