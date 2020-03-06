#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game_type.h"
#include "game_func.h"
#include "stage/stage.h"
#include "game_api.h"
#include "pages/pages.h"





void SelectMode2(int PlayerID) {
	int iVar3;
	int i;
	int OBJ[4];
	int pos=0,old_pos=0,ctrl=1;
	int local_38;
	int iVar11;

	arm_cmd(0x43,2);
	DU16(0x80e04c) = 1;
	FUN_00151662(0,-1,0);
	FUN_0015162c(1,0x31,0x24);
	SetPal_0014ce68(1,0,PU32(0x251392));
	FUN_0016e3f6(1,0,4,PU32(0x2520a2),0x60,0,0,0xaf4);//画八卦台
	SetPal_0014ce68(2,0x1e,PU32(0x2f2d22));
	iVar3 = CreatSObj_0016f530();
	SetSObj_0016f762(iVar3,PU32(0x2fc580),0,0,0,0);//画背景动态火焰
	FUN_00171b16(iVar3,1,0);
	PalFadeIn_0014db72(2);
	ScreenUpdate_0018c492();

	SetPal_0014c2da(0,10,0x2f2d62);
	SetPal_0014c2da(0,0xb,0x2f2da2);
	SetPal_0014c2da(0,0xc,0x2f2de2);
	SetPal_0014c2da(0,0xd,0x2f2e22);
	SetPal_0014c2da(2,0x19,0x2fda40);
	SetPal_0014c2da(2,0x1b,0x2686ca);
	SetPal_0014c2da(2,0x1c,0x26870a);
	SetPal_0014c2da(2,0x1d,0x2557c8);
	SetPal_0014c2da(2,0x18,0x26894a);
	FUN_0016b922(0xff04,0,0x32,0x1c,0x2fc336,0x28,0,0x2fc21e);//左边的门动画
	FUN_0016b922(0x1d0,0,0x33,0x1c,0x2fc2ba,0x28,0,0x2fc21e);//右边的门动画
	api_delay(0x1a);//自己写的函数，用来刷新多少帧屏幕
	//Print(0,1,10,3,0,"QQ:100714928");
	//Print(0,1,12,3,0,"www.qq.com");
	for (i=0; i<4; i++) {//这里画3个模式的框框
		OBJ[i] = CreatSObj_0016f530();
		SetSObj_0016f762(OBJ[i],0x2fc6a8,140,35+i*48-23,0,0);
		FUN_00171b16(OBJ[i],1,10);
	}
	api_delay(0x18);
	Print(0,1,10,3,0,"QQ:100714928");
	Print(0,1,12,3,0,"www.qq.com");
	FUN_0016bb58(0x13,2,10,0,0,700);//一
	FUN_0016bb58(0x18,2,10,0,0,1230);//统
	FUN_0016bb58(0x1d,2,10,2,3,5);//中
	FUN_0016bb58(0x22,2,10,3,6,7);//原
	FUN_0016bb58(0x13,8,10,0,0,935);//武
	FUN_0016bb58(0x18,8,10,0,0,935);//将
	FUN_0016bb58(0x1d,8,10,2,1,0x16);//争
	FUN_0016bb58(0x22,8,10,0,0,4);//霸
	FUN_0016bb58(0x13,14,10,0,0,158);//网
	FUN_0016bb58(0x18,14,10,0,0,807);//络
	FUN_0016bb58(0x1d,14,10,0,3,0xd);//排
	FUN_0016bb58(0x22,14,10,0,8,0x14);//名
	FUN_0016bb58(0x13,20,10,0,0,700);//一
	FUN_0016bb58(0x18,20,10,0,0,1230);//统
	FUN_0016bb58(0x1d,20,10,0,3,0xd);//模
	FUN_0016bb58(0x22,20,10,0,8,0x14);//式

	FUN_0016b922(0xd3,200,0x12e,0x18,0x2fc1fa,300,0,0x2fc21e);//倒计时的字
	/*光标控制开始*/
	while(1) {
		if( ChkKeyPress_0014f962(PlayerID*9+2)) { //PRESS UP

			if(!pos)//光标变0了
				pos = 3;
			else
				pos -= 1;
			ctrl = 1;
		}
		if( ChkKeyPress_0014f962(PlayerID*9+3)) { //PRESS DOWN

			if(pos<3)//光标变0了
				pos += 1;
			else
				pos = 0;
			ctrl = 1;
		}
		if(ctrl) {
			switch(old_pos) {//把旧光标文字颜色变灰
			case 0:
				FUN_0016bb58(0x13,2,10,0,0,700);//一
				FUN_0016bb58(0x18,2,10,0,0,1230);//统
				FUN_0016bb58(0x1d,2,10,2,3,5);//中
				FUN_0016bb58(0x22,2,10,3,6,7);//原
				break;
			case 1:
				FUN_0016bb58(0x13,8,10,0,0,935);//武
				FUN_0016bb58(0x18,8,10,0,0,935);//将
				FUN_0016bb58(0x1d,8,10,2,1,0x16);//争
				FUN_0016bb58(0x22,8,10,0,0,4);//霸
				break;
			case 2:
				FUN_0016bb58(0x13,14,10,0,0,158);//网
				FUN_0016bb58(0x18,14,10,0,0,807);//络
				FUN_0016bb58(0x1d,14,10,0,3,0xd);//排
				FUN_0016bb58(0x22,14,10,0,8,0x14);//名
				break;
			case 3:
				FUN_0016bb58(0x13,20,10,0,0,700);//一
				FUN_0016bb58(0x18,20,10,0,0,1230);//统
				FUN_0016bb58(0x1d,20,10,0,3,0xd);//排
				FUN_0016bb58(0x22,20,10,0,8,0x14);//名
				break;
			}
			/*让未选中的框框停止动画？*/
			FUN_00171ae8(OBJ[old_pos],0x2fc628);
			FUN_00171b76(OBJ[old_pos],140,35+old_pos*48-23,0);

			switch(pos) {//把新光标文字颜色变亮
			case 0:
				FUN_0016bb58(0x13,2,11,0,0,700);//一
				FUN_0016bb58(0x18,2,11,0,0,1230);//统
				FUN_0016bb58(0x1d,2,11,2,3,5);//中
				FUN_0016bb58(0x22,2,11,3,6,7);//原
				break;
			case 1:
				FUN_0016bb58(0x13,8,11,0,0,935);//武
				FUN_0016bb58(0x18,8,11,0,0,935);//将
				FUN_0016bb58(0x1d,8,11,2,1,0x16);//争
				FUN_0016bb58(0x22,8,11,0,0,4);//霸
				break;
			case 2:
				FUN_0016bb58(0x13,14,11,0,0,158);//网
				FUN_0016bb58(0x18,14,11,0,0,807);//络
				FUN_0016bb58(0x1d,14,11,0,3,0xd);//排
				FUN_0016bb58(0x22,14,11,0,8,0x14);//名
				break;
			case 3:
				FUN_0016bb58(0x13,20,11,0,0,700);//一
				FUN_0016bb58(0x18,20,11,0,0,1230);//统
				FUN_0016bb58(0x1d,20,11,0,3,0xd);//排
				FUN_0016bb58(0x22,20,11,0,8,0x14);//名
				break;

			}
			/*让未选中的框框停止动画？*/
			FUN_00171ae8(OBJ[pos],0x2fc660);
			FUN_00171b76(OBJ[pos],140,35+pos*48-23,0);
			ctrl = 0;
			old_pos = pos;

		}
		if(ChkKeyPress_0014f962(PlayerID*9+6)) { //PRESS PUNCH
			PlaySound_001f6d34(0,200,0x7f,0);//播放一次音效
			FUN_00171ae8(OBJ[pos],0x2fc638);
			FUN_00171b76(OBJ[pos],140,35+pos*48-23,0);
			api_delay(0x1e);
			switch(pos) { //这里根据选择的模式来调整一些内存
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			}
			FUN_00152712();
			FUN_0015231a();
			DU16(0x80e04c) = 0;
			api_delay(0x12);
			for(i=0; i<4; i++)
				FUN_0016f6c2(OBJ[i]);//释放OBJ
			ScreenUpdate_0018c492();
			arm_cmd(0x93,0x100);
			arm_cmd(0xb5,1);
			SetPal_0014c2da(2,0x1a,0x2687ca);
			SetPal_0014c2da(2,0x1f,0x2f2e62);
			if(!FUN_001873d6()) {
				if(!DU16(0x813534)) {
					SetPal_0014c2da(2,0x1b,0x2686ca);
					local_38 = 0x26870a;
				} else {
					SetPal_0014c2da(2,0x1b,0x2686ca);
					local_38 = 0x2f2f22;
				}
			} else {
				SetPal_0014c2da(2,0x1b,0x2686ca);
				local_38 = 0x2689ca;
			}
			SetPal_0014c2da(2,0x1c,local_38);
			SetPal_0014c2da(2,0x1d,0x26878a);
			for(i=0; i<20; i++) {
				SetPal_0014c2da(2,DU8(0x13c3d9+i * 0x22),DU32(0x13c3e0+i*0x22));
			}
			for(i=0; i<20; i++) {
				if(!PU16(0x13c3da)[i*0x11]) {
					local_38=0x2fc1fa;
					iVar11 = 0x1d;
				} else {
					local_38=0x2fc202;
					iVar11=0x1f;
				}
				FUN_0016b922(0,8,i + 0x12f,iVar11,0x2fc1fa,
				             0x14,0,0x2fc21e);
				FUN_0016b922(-PU16(0x2fc1aa)[i*2],8 -PU16(0x2fc1ac)[i*2],
				             DU8(0x13c3d9 + i * 0x22)+0x111,DU8(0x13c3d9 + i * 0x22),local_38,
				             0x1e,0,PU32(0x2fc21e));
			}
			//PlayEffect_0018fe24(FUN_0018fcf8(),0xf0,0,1,0x1f9a3a,0x2fc618,0);//跳动的NEW字
			api_delay(0x14);
			arm_cmd(0x75,0xf41);
			arm_cmd(0xb6,2);
			return;
		}
		api_delay(1);
	}
	return;
}








/*选择模式和选人*/
void SelectMode(int PlayerID) {
	int i,j;
	short local_2c[20];
	short local_34[4];
	short local_3c[4];
	int local_48;
	int Time;
	int iVar3;
	int Timer1;
	int Timer2;


	if (FUN_001988d6()) {
		FUN_00173bb8();
	}
	arm_cmd(0x43,5);
	FUN_001f6e84(0xf,0);
	FUN_001f7008(0x14,0);
	DU16(0x80e04e) = 0;
	FUN_001952ca(1,5);//MUSIC初始化
	PlayMusic_00195310(4);
	DU8(0x803b87) = 1;
	//FUN_0016bc30(PlayerID);//这里是选模式
	SelectMode2(PlayerID);


	api_delay(0);
	while(1) {
		arm_cmd(0x75,0x211e);
		arm_cmd(0x73,2);
		if(!FUN_0019acf8())
			break;
		ScreenUpdate_0018c492();
	}
	arm_cmd(0x60,0x300);
	arm_cmd(0x5e,0);

	FUN_0016c8ee();
	DU16(0x80e04a) = 0;

	for(i=0; i<20; i++)
		local_2c[i]=0;
	for(i=0; i<4; i++) {
		local_34[i]=0;
		PU8(0x80e042)[i]=0xff;
		local_3c[i]=0xffff;
	}
	local_34[PlayerID]=1;
	local_3c[PlayerID]=0;
	local_2c[0]=1;

	FUN_0016ba00(PlayerID,0);
	FUN_00173cde(PlayerID);
	local_48 = 1;
	Time = 9;
	iVar3 = FUN_0016b922(0xd3,200,0x12e,0x18,PU32(0x2fc1fa),300,0,PU32(0x2fc21e));
	// Timer1 = CreatTimer_0014f178();
	// SetTimer_0014f236(Timer1,0x3c);
	// Timer2 = CreatTimer_0014f178();
	// SetTimer_0014f236(Timer2,3);

	for(i=0; i<4; i++) { //
		if(!local_34[i] && ChkKeyPress_0014f962(i*9+1) && FUN_00173c08(i)) {
			local_34[i] = 1;
			FUN_00173cde(i);
			for(j=0; j<20; j++) {
				if(!local_2c[j])
					break;
			}
			local_3c[i]=j;
			local_2c[j]=1;
			FUN_0016ba00(i,j);
			Time = 9;
		}
		if(local_34[i]) {
			if(ChkKeyPress_0014f962(i*9+6) || !Time) {
				local_34[i] = 2;
				FUN_0016b922( DU16(0x13c3e6 + local_3c[i]*0x22),DU16(0x13c3e8 + local_3c[i]*0x22),
				              0x5e,0x1d,0x2fc292,0x96+i,0,0x2fc21e);
				arm_cmd(0x53,(i&0x7f|0x60)<<7|1);
				arm_cmd(0x51,0x2c3);
				FUN_0014c276(2,i + 0x14,0x2fda40);
				FUN_0014f2c4(3,(int)&ScreenUpdate_0018c492);
				return;
			}
		}
	}



	api_delay(0);







	return;
}



/*投币后的开始界面函数*/
void TitlePage() {
	int PlayerID;

	FUN_001f6e84(0xf,0);
	FUN_001f7008(0x14,0);
	if (DU8(0x81352f) != 0) {
		PlaySound_001f6d34(0,0xc5,0x7f,0);//投币的声音
		DU8(0x81352f) = 0;
	}
	//PlayerID = FUN_00198c12();//这里是标题倒计时画面，返回值是一个操作的PlayerID
	PlayerID = PageStartGame();
	FUN_001a4a86();
	FUN_00196ab0();
	//FUN_0016d2e6(PlayerID);//选模式和选人函数
	SelectMode(PlayerID);
	DU8(0x81352c) = 0;
	FUN_00190cba();
	while (DU8(0x81352c) != 3) {
		if (DU8(0x81352c) == 0) {
			FightResult_001a66c2();
		} else {
			if (DU8(0x81352c) == 1) {
				FUN_00196b88();
			}
		}
	}
	FUN_0016d2f6();
	FUN_001a69a2();
	FUN_001f6e84(0xf,0);
	return;
}























void Hook(int a1,int a2,int a3,int a4,int a5) {
	Print(0,0,0,0,0,"a1=%d a2=%d a3=%d a4=%d a5=%d",a1,a2,a3,a4,a5);
	DU8(0x81b1e2)=100;
	return;
}













void _main() {
	DU8(0x803801) = 0;
	FUN_0014b88c();
	FUN_0018c582();
	FUN_001a4956();
	FUN_001975e8();
	PageCopyright();
	FUN_00173524();
	while(1) {
		while ( 1 ) {
			switch ( MainFSM_0081352b ) {
			case 0:
				OpenPage_00198794();
				break;
			case 1:
				continue;
			case 2:
				FUN_001a4a86();
				OpenPage_00198794();
				break;
			case 3:
				MainMenu_001a4960();
				break;
			case 4:
				MainMenu_001a4960();
				return;
			default:
				MainFSM_0081352b = 2;
				break;
			}
		}

	}
}
