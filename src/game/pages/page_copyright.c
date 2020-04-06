#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../game_type.h"
#include "../game_func.h"
#include "../stage/stage.h"
#include "../game_api.h"



//新版权页
void NewCopyRight() {
	int v1,v2;
	
	FUN_0015280a();//初始化内存
	SetSystemFontPal_00152b1e();//设置系统字体色盘
	LoadMusicByGroupID_001952ca(0,4);
	//FUN_0014bf0a();//
	//PlayMusicByID_00195310(0);
	//FUN_001515aa(1,0,0);
	//FUN_0014c4c0(2,0xf,0x26a7aa);//载入色盘
	//FUN_00196e14(0,0xf,0x31b74c,0,6,0);//frame,palid,cmd,layer,FrameRate,display //火焰背景
	//api_delay(60);//延迟1秒
	PlaySound_001f6d34(0,1,255,0);
	SetFadePal_0014ce68(2,0x16,0x269a8c);
	v1=FUN_00196d8e(3,0x16,0x31b514,0,0,0);

	//api_delay(20);
	PalFadeIn_0014db72(1);
	api_delay(60);
	FreeOBJ_0016f6c2(v1);
	//FreeOBJ_0016f6c2(v2);
	api_delay(1);
	FUN_0014bf0a();//free Fadepal
	SetFadePal_0014ce68(2,0x16,0x269dcc);
	FUN_0014d332();
	v2=FUN_00196d8e(0,0x16,0x31b844,0,0,0);



	api_delay(0);
	FUN_001a0f12();//执行原版CopyRight.
	return;
}



/*warning界面*/
void PageCopyright() {
	int i;
	FUN_001527fc();
	FUN_0015294e(0,0,0,0x38,0x1c);
	FUN_0015294e(1,0,0,0xe,7);
	FUN_0014d5a6();
	FUN_0014e96c();
	FUN_0014be5e();
	Print_00153452(0,50,27,3,0,"V201");
	//DrawLine_001a0eb8(8,6,0x26,5);
	for(i=1; i<6; i++)
		Print_00153452(0,1,3*i,3,i,"FNT%d ABCabc123",i);
	for(i=9; i<11; i++)
		Print_00153452(0,1,17+3*(i-8),3,i,"FNT%d ABCabc123",i);


	FUN_00152b92();
	FUN_0014ce68(0,5,DU16(0x243520));
	FUN_0014d278(0);
	FUN_00173524();
	FUN_0014f236( FUN_0014f178(),300);
	while(1) {
		ScreenUpdate_0018c492();
	}
	return;
}