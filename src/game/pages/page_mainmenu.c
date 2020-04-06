#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../game_type.h"
#include "../game_func.h"
#include "../stage/stage.h"
#include "../game_api.h"

struct Menu {
	int	*Str;	//菜单文本地址
	int *Func;	//菜单程序地址
};


//200
void TestFunc() {
	int x,y;
	InitFnt_0015280a();//5*6

	SetPal_0014c2da(0,0xb,0x2f2da2);

	for(y=0; y<9; y++) {

		for(x=0; x<18; x++)
			FUN_0016bb58(x*3,y*3,11,0,0,y*18+x+162*0);//原19*26+n


	}

	
	return;
}


/*调试菜单界面*/
void PageMainMenu() {
	int i;
	int move=1;//是否移动了光标
	int pos=0;
	int pos_old=0;//光标位置
	struct Menu MenuList[17];
	/*菜单列表*/
	MenuList[0].Str = (int *)"TEST KENSOU";
	//MenuList[0].Func = (int*)0x1a4284;//背景图查看
	//MenuList[0].Func = (int*)0x1a44b4;//背景OBJ图查看
	//MenuList[0].Func = (int*)0x1893ba;//STAFF
	MenuList[0].Func = (int*)0x1a52c2;
	MenuList[1].Str = (int *)"TEST SOUND";
	MenuList[1].Func = (int *)0x1a1276;
	MenuList[2].Str = (int *)"TEST ROLE";
	MenuList[2].Func = (int *)0x1a1a50;
	MenuList[3].Str = (int *)"TEST RORO";
	MenuList[3].Func = (int *)0x1a24a2;
	MenuList[4].Str = (int *)"TEST OFFICER";
	MenuList[4].Func = (int *)0x1a2f68;
	MenuList[5].Str = (int *)"TEST SYSOBJ";
	MenuList[5].Func = (int *)0x1a3a2e;
	MenuList[6].Str = (int *)"TEST FOOD";
	MenuList[6].Func = (int *)0x1a17da;
	MenuList[7].Str = (int *)"TEST WEAPON";
	MenuList[7].Func = (int *)0x1a1944;
	MenuList[8].Str = (int *)"CLEAR SYSTEM RAM";
	MenuList[8].Func = (int *)0x1a3d30;
	MenuList[9].Str = (int *)"TEST SIGNATURE";
	MenuList[9].Func = (int *)0x1a3cc4;
	MenuList[10].Str = (int *)"TEST DIALOG";
	MenuList[10].Func = (int *)0x1a3f30;
	MenuList[11].Str = (int *)"TEST STORY";
	MenuList[11].Func = (int *)0x1a418e;
	MenuList[12].Str = (int *)"TEST OVER";
	MenuList[12].Func = (int *)0x1a4756;
	MenuList[13].Str = (int *)"TEST OVER1";
	MenuList[13].Func = (int *)0x1a47a0;
	MenuList[14].Str = (int *)"TEST RANK";
	MenuList[14].Func = (int *)0x1a47f0;
	MenuList[15].Str = (int *)"TEST ASIC27";
	MenuList[15].Func = (int *)0x1a488c;
	MenuList[16].Str = (int *)"EXIT";
	MenuList[16].Func = (int *)0;

	FUN_0015280a();
	FUN_0015270a();

	while(1) {
		FUN_0015280a();
		FUN_00152b1e();
		Print_00152cbc(0,10,0,4,9,"---MAIN_MENU---");
		for(i=0; i<17; i++) {
			Print_00153452(0,12,6+i,0,0,"  %s",MenuList[i].Str);
		}

		while(!ChkKeyPress_0014f962(1)) { //只要不按1P的开始键就不离开

			if(ChkKeyPress_0014f962(2)) { //如果按了1P的UP键
				PlaySound_001f6d34(0,200,0x7f,0);//播放一次音效
				pos_old = pos;
				pos--;
				move = 1;
				if(pos<0)
					pos = 16;//让光标去最下面一行
			}
			if(ChkKeyPress_0014f962(3)) { //如果按了1P的DOWN键
				PlaySound_001f6d34(0,200,0x7f,0);//播放一次音效
				pos_old = pos;
				pos++;
				move = 1;//
				if(pos>=17)
					pos = 0;//让光标去最上面一行
			}
			if(move) {

				Print_00153452(0,12,6+pos_old,0,0,"  %s",MenuList[pos_old].Str);//把旧光标位置恢复颜色
				Print_00153452(0,12,6+pos,1,0,"* %s",MenuList[pos].Str);//把新光标位置变颜色
				move = 0;
			}

		}
		if(pos==16)//如果是选了退出
			break;
		FUN_00152712();
		Print_00153452(0,10,0,1,3,"-%s-",MenuList[pos].Str);//在屏幕顶上显示当前光标的名字
		FUNC32(MenuList[pos].Func)();//执行对应光标的函数
	}

	MainFSM_0081352b = 2;
	return;
}