#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../game_type.h"
#include "../game_func.h"
#include "../stage/stage.h"
#include "../game_api.h"


struct HeadInfo {
	char HeadPalID;
	int HeadPalPtr;
	short x;
	short y;
};

const char MidHeadPalID[] = {
	 0, 1, 2, 3, 4, 5, 6, 7, 10, 11,
	12,8,13,9,14,15,16,17,18,19,

};
const char MidHeadPicID[] = {
	 0, 1, 2, 3, 4, 5, 6, 7, 10, 11,
	12,8,13,9,14,15,16,17,18,19,

};

const char MidHeadFlag[] = {
	 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

};

const int MidHeadPalPtr[] = {
	0x26838a,0x2683ca,0x26844a,0x26848a,0x26850a,0x26860a,0x26864a,0x26858a,0x2685ca,0x26854a,
	0x2f28a2,0x26840a,0x2f2922,0x2684ca,0x2f29a2,0x2f2ae2,0x2f2a62,0x2f2a22,0x2f2aa2,0x2f29e2,

};
/*
const short MidHeadPosX[] = {
	0xff7b,0xff4e,0xff21,0xfef3,0xff7b,0xff4e,0xff21,0xfef3,0xff7b,0xff4e,
	0xff21,0xfef3,0xff7b,0xff4e,0xff21,0xfef3,0xff7b,0xff4e,0xff21,0xfef3,
};*/

const short MidHeadPosX[] = {
	0,45,90,135,180,225,270,315,360,405,
	0,45,90,135,180,225,270,315,360,405,

};
/*
const short MidHeadPosY[] = {
	0xffe9,0xffee,0xffee,0xffe9,0xffc5,0xffca,0xffca,0xffc5,0xffa1,0xffa6,
	0xffa6,0xffa1,0xff7d,0xff82,0xff82,0xff7d,0xff59,0xff5e,0xff5e,0xff59,
};
*/
const short MidHeadPosY[] = {
	138,138,138,138,138,138,138,138,138,138,
	168,168,168,168,168,168,168,168,168,168,

};

/*选择模式和选人*/
//编号0-编号19色盘给小头像使用
void PageSelectRole(int PlayerID) {
	int i,j;
	
	short local_2c[40];
	short local_34[4];
	short local_3c[4];
	int local_48;
	int Time;
	int iVar3;
	int Timer1;
	int Timer2;
	int local_38;
	int iVar11;


	api_arm(0x93,0x100);
	api_arm(0xb5,1);
	SetPal_0014c2da(2,26,0x2687ca);
	SetPal_0014c2da(2,27,0x2686ca);
	SetPal_0014c2da(2,31,0x2f2e62);
	if(!FUN_001873d6()) {
		if(!DU16(0x813534))
			SetPal_0014c2da(2,28,0x26870a);
		else
			SetPal_0014c2da(2,28,0x26870a);
	} else
		SetPal_0014c2da(2,28,0x2689ca);

	SetPal_0014c2da(2,29,0x26878a);
	for(i=0; i<20; i++) {
		SetPal_0014c2da(2,MidHeadPalID[i],MidHeadPalPtr[i]);
	}
	for(i=0; i<20; i++) {
		if(!MidHeadFlag[i]) {
			local_38=0x2fc1fa;//脚本地址
			iVar11 = 29;//框框色盘
		} else {
			local_38=0x2fc202;//脚本地址
			iVar11 = 31;//框框色盘
		}
		FUN_0016b922(MidHeadPosX[i]-133,MidHeadPosY[i]-23,0x12f,iVar11,0x2fc1fa,20,0,0x2fc21e);//画框框 
		FUN_0016b922(MidHeadPosX[i],MidHeadPosY[i],      
		             MidHeadPicID[i]+0x111,MidHeadPalID[i],local_38,
		             30,0,PU32(0x2fc21e));//最后参数是图片包地址
		 
	}
	//PlayEffect_0018fe24(FUN_0018fcf8(),0xf0,0,1,0x1f9a3a,0x2fc618,0);//跳动的NEW字

	
	
	
	
	
	
	api_delay(0x14);
	api_arm(0x75,0xf41);
	api_arm(0xb6,2);



api_delay(0);




























	//api_delay(0);
	// while(1) {
	// api_arm(0x75,0x211e);
	// api_arm(0x73,2);
	// if(!FUN_0019acf8())
	// break;
	// ScreenUpdate_0018c492();
	// }
	// api_arm(0x60,0x300);
	// api_arm(0x5e,0);

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
				api_arm(0x53,(i&0x7f|0x60)<<7|1);
				api_arm(0x51,0x2c3);
				FUN_0014c276(2,i + 0x14,0x2fda40);
				FUN_0014f2c4(3,(int)&ScreenUpdate_0018c492);
				return;
			}
		}
	}



	api_delay(0);







	return;
}
