#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game_type.h"
#include "game_func.h"
#include "game_api.h"
#include "game_struct.h"


//10 = red
//14 = yellow
//15 = blue white
//0x16 = orange
//0x20 = black

struct TileInfo {
	char state;
	char row;
	char field_0x2;
	char unk;
	short change;
	short *tileptr;
};

static int BossHPRow[2]= {0,0};

void ChangeBossHpBar(struct TileInfo *off) {
	int i;
	short Pal[8]= {
		0x0040,
		0x7bda,
		0x5000,
		0xffe0,//扣血颜色
		0x0200,
		0x801f,//血条底色
		0x00da,
		0x02df
	};
	int Boss = 0x80cf1e;
	
	Pal[5] = 0xffe0 - BossHPRow[0] * 0x200 ;
	Pal[3] = Pal[5] -0x8000 ;

	if (off->change != 0) {//判断是否要扣血
		if (off->change < 0) {//扣血
			if (off->field_0x2 == 0) {//如果bit位是0
				off->field_0x2 = 8;//切换bit到8
				off->tileptr = off->tileptr + -2;//tile地址-4
				off->row = off->row - 1;//hp-1
				if (off->row == 0 && BossHPRow[0]!=0) {//如果已经扣血到最左边了并且BOSS还有血条
					//A3=0x905628;
					for(i=0; i<15; i++) {//200/8=25 填充血条中间
						//DU32(A3) = 0;
						off->tileptr += 2;
						DU16(off->tileptr) = 0xC55C+1;
						//DU8(A3+3) &= 0xc1;
						//DU8(A3+3) ^= 20;
						
					}
					DU16(0xa01140+10) = DU16(0xa01140+6);
					DU16(0xa01140+6) = 0xffe0 - 0x50*BossHPRow[0];//修改血条色盘
					BossHPRow[0] += -1;
					//off->tileptr = off->tileptr + -0x80;//切换到上一行
					//off->tileptr = off->tileptr + 50;//最右边
					off->row = 15;//块=45
					
				}
			}
			off->field_0x2 = off->field_0x2 + -1;//bit位-1
			*off->tileptr = (DU16(0x813542) - (ushort)(byte)off->field_0x2) + 9;//切换tilenum
			off->change = off->change + 1;//change+1
			Print(0,10,21,1,0,"LIFE=%02d HP=%04d    ",BossHPRow[0]-1,DU16(Boss+94)*100);
		} else {//加血
			if (off->field_0x2 == 8) {//bit=8
				off->field_0x2 = 0;//bit=0
				off->tileptr = off->tileptr + 2;//tile地址+4
				off->row = off->row + 1;//hp+1
				if (off->row == 16) {//如果到最右边了
					//off->tileptr = off->tileptr + 0x80;//切换到下一行
					off->tileptr = off->tileptr + -50-4;//最左边
					off->row = 1;//切换到最左边
				}
			}
			off->field_0x2 = off->field_0x2 + 1;//bit+1
			*off->tileptr = (DU16(0x813542) - (ushort)(byte)off->field_0x2) + 9;//切换tilenum
			off->change = off->change + -1;//change-1
		}
	}
	return;
}





/*
void ChangeBossHpBar(struct TileInfo *off) {
	if (off->change != 0) {//判断是否要扣血
		if (off->change < 0) {//判断是扣血还是加血
			if (off->field_0x2 == 0) {//如果bit位是0
				off->field_0x2 = 8;//切换bit到8
				off->tileptr = off->tileptr + -2;//tile地址-4
				off->row = off->row - 1;//hp-1
				if (off->row == 0) {//如果已经扣血到最左边了
					off->tileptr = off->tileptr + -0x80;//切换到上一行
					off->tileptr = off->tileptr + 0x5a;//最右边
					off->row = 45;//块=45
				}
			}
			off->field_0x2 = off->field_0x2 + -1;//bit位-1
			*off->tileptr = (DU16(0x813542) - (ushort)(byte)off->field_0x2) + 9;//切换tilenum
			off->change = off->change + 1;//change+1
		} else {
			if (off->field_0x2 == 8) {//bit=8
				off->field_0x2 = 0;//bit=0
				off->tileptr = off->tileptr + 2;//tile地址+4
				off->row = off->row + 1;//hp+1
				if (off->row == 46) {//如果到最右边了
					off->tileptr = off->tileptr + 0x80;//切换到下一行
					off->tileptr = off->tileptr + -0x5a;//最左边
					off->row = 1;//切换到最左边
				}
			}
			off->field_0x2 = off->field_0x2 + 1;//bit+1
			*off->tileptr = (DU16(0x813542) - (ushort)(byte)off->field_0x2) + 9;//切换tilenum
			off->change = off->change + -1;//change-1
		}
	}
	return;
}
*/




void CreatBossHpBar(int RoroID,RoroMem *Boss) {
	int i,j,row;
	int A3,A2;
	int N,FNT;
	short Pal[8]= {
		0x0040,
		0x7bda,
		0x5000,
		0xffe0,//扣血颜色
		0x0200,
		0x801f,//血条底色
		0x00da,
		0x02df
	};

	//Print(0,4,8,0,0,"a1=%02d a2=%06X HP=%03d BOSSID=%02d",RoroID,Boss,Boss->MaxHP,Boss->RoroRom2->RoleId);

	if(!DU8(0x803b86)) {
		if(Boss->MaxHP < 721)
			DU16(0x813b14) = 21;
		else
			DU16(0x813b14) = 20;
	} else {
		if(Boss->MaxHP < 721)
			DU16(0x813b14) = 25;
		else
			DU16(0x813b14) = 24;
	}

	A2 = 0x813544 + RoroID * 706;
	N = Boss->RoroRom2->RoleId;

	// if(!RoroID) {
	// if(FUN_001a5776())
	// SetPal_0014c2da(0,10,PU32(0x303914)[Boss->RoroRom2->RoleId]);
	// DU8(0x813ac8) = SetFadePal_0014ce68(0,10,PU32(0x303914)[Boss->RoroRom2->RoleId]);
	// }

	// FUN_00153c76(DU16(A2+0x2ae),0,(DU16(0x813b14)+RoroID * -2) * 8,0x25aeb4,N,0,0,8,0x631ddc,0x10,0x10,0,0);

	// if(FUN_00196796()==1) {
	// FUN_00153c76(DU16(A2+0x2b8),0x18,(DU16(0x813b14)+RoroID * -2) * 8,0x25aeb4,N+62,0,0,4,0x631ddc,0x10,0x10,0,0);
	// } else {
	// FUN_00153c76(DU16(A2+0x2b8),0x18,(DU16(0x813b14)+RoroID * -2) * 8,0x25aeb4,N+30,0,0,4,0x631ddc,0x10,0x10,0,0);
	// }
	FUN_001544fe(DU16(A2+0x2ac),2);
	//PU8(0x80bad7)[DU16(A2+0x2ac)*0x14] = 2;
	//DU8(0x80ceea) = 1;
	row = (Boss->MaxHP+119)/120;
	//Print(0,4,9,0,0,"ROW=%01d ID=%02d",row,DU16(A2+0x2ac));
	DU8(0x8137ee) = row;
	DU8(0x8137ef) = row;
	N=Boss->MaxHP;



	/*下面开始绘制血条*/
	BossHPRow[RoroID] = (Boss->MaxHP+119)/120;
	A3 = A2 + 0 * 0xe0; //0x813544+0xe0?
	A3 += 10;
	DU32(A3) = 0;
	DU16(A3) = 0xC55C;//血条左边框
	DU8(A3+3) &= 0xc1;
	DU8(A3+3) ^= 20;
	A3 += 4;
	

	//Pal[5] = 0xffe0 - BossHPRow[RoroID] * 0x20 ;
	//Pal[3] = Pal[5] -0x8000 ;
	api_wpal_tile(20,Pal);//载入BOSS用血条
	//SetPal_0014c2da(0,20,Pal);
	for(i=0; i<15; i++) {//200/8=25 填充血条中间
		DU32(A3) = 0;
		DU16(A3) = 0xC55C+1;
		DU8(A3+3) &= 0xc1;
		DU8(A3+3) ^= 20;
		A3 += 4;
	}
	Print(0,4,15,0,0,"%d",i);
	
	DU32(A3) = 0;//清空tile
	DU16(A3) = DU16(0x813542) + 10;//血条右边
	DU8(A3+3) &= 0xc1;
	DU8(A3+3) ^= 20;

	DU8(A2+1) = i;//row=25
	DU32(A2+6) = (DU16(0x813b14) + RoroID * -2 + 1)*0x100 + 0x904024;//ptr
	FNT = FUN_0016e098(A2+10);//从这里开始复制
	FUN_0016e0fa(FNT,0,i+2,1,DU32(A2+6),0);//复制TILE到显卡
	DU8(A2+2) = 8;//bit=8
	DU32(A2+6) += i*4;//ptr到25
	DU16(A2+4) = 0;//change=0
	DU8(0x813aca) = 1;//?
	DU8(A2) = 2;//state=2
	Print(0,10,21,1,0,"LIFE=%02d HP=%04d    ",BossHPRow[0]-1,Boss->MaxHP*100);
	return;
}



// void CreatBossHpBar(int RoroID,RoroMem *Boss) {
// int i,j,row;
// int A3,A2;
// int N,FNT;

// Print(0,4,8,0,0,"a1=%02d a2=%06X HP=%03d BOSSID=%02d",RoroID,Boss,Boss->MaxHP,Boss->RoroRom2->RoleId);

// if(!DU8(0x803b86)) {
// if(Boss->MaxHP < 721)
// DU16(0x813b14) = 21;
// else
// DU16(0x813b14) = 20;
// }else {
// if(Boss->MaxHP < 721)
// DU16(0x813b14) = 25;
// else
// DU16(0x813b14) = 24;
// }

// A2 = 0x813544 + RoroID * 706;
// N = Boss->RoroRom2->RoleId;

// if(!RoroID){
// if(FUN_001a5776())
// SetPal_0014c2da(0,10,PU32(0x303914)[Boss->RoroRom2->RoleId]);
// DU8(0x813ac8) = SetFadePal_0014ce68(0,10,PU32(0x303914)[Boss->RoroRom2->RoleId]);
// }

// FUN_00153c76(DU16(A2+0x2ae),0,(DU16(0x813b14)+RoroID * -2) * 8,0x25aeb4,N,0,0,8,0x631ddc,0x10,0x10,0,0);

// if(FUN_00196796()==1){
// FUN_00153c76(DU16(A2+0x2b8),0x18,(DU16(0x813b14)+RoroID * -2) * 8,0x25aeb4,N+62,0,0,4,0x631ddc,0x10,0x10,0,0);
// }else{
// FUN_00153c76(DU16(A2+0x2b8),0x18,(DU16(0x813b14)+RoroID * -2) * 8,0x25aeb4,N+30,0,0,4,0x631ddc,0x10,0x10,0,0);
// }
// FUN_001544fe(N+1,2);

// row = (Boss->MaxHP+0x167)/0x168;
// Print(0,4,9,0,0,"ROW=%01d",row);
// DU8(0x8137ee) = row;
// DU8(0x8137ef) = row;
// N=Boss->MaxHP;


// for(i=0; i<row; i++) {
// A3 = A2 + i * 0xe0;

// DU32(A3+10) = 0;
// DU16(A3+10) = DU16(0x813542);
// DU8(A3+13) &= 0xc1;
// DU8(A3+13) ^= 10;

// A3 += 14;

// if(N < 360) {
// for(j=0; j<N/8; j++) {
// if(N<0)
// N += 7;
// DU32(A3) = 0;
// DU16(A3) = DU16(0x813542)+1;
// DU8(A3+3) &= 0xc1;
// DU8(A3+3) ^= 10;
// A3 += 4;
// }
// N=0;
// } else {
// for(j=0; j<45; j++) {
// DU32(A3) = 0;
// DU16(A3) = DU16(0x813542) + 1;
// DU8(A3+3) &= 0xc1;
// DU8(A3+3) ^= 10;
// A3 += 4;
// }
// N -= 0x168;
// }
// DU8(A2+1) = j;
// DU32(A3) = 0;
// DU16(A3) = DU16(0x813542) + 10;
// DU8(A3+3) &= 0xc1;
// DU8(A3+3) ^= 10;
// DU32(A2+6) = (DU16(0x813b14) + RoroID * -2 + i)*0x100 + 0x904024;
// FNT = FUN_0016e098(A2+i*0xe0+10);
// FUN_0016e0fa(FNT,0,j+2,1,DU32(A2+6),0);
// DU8(A2+2) = 8;
// DU32(A2+6) += j*4;
// DU16(A2+4) = 0;



// }
// DU8(0x813aca) = 1;
// DU8(A2) = 2;


// return;
// }

