#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../game_type.h"
#include "../game_func.h"
#include "../game_api.h"
#include "../game_struct.h"
#include "hook.h"



int EatItem(RoroMem *param_1,int OBJMem) {
	//Print(0,6,10,0,0,"%X",OBJMem);

	char *pcVar1;
	int iVar2;
	int iVar3;
	char cVar4;
	ushort uVar5;
	byte *pbVar6;
	ushort local_6;
	int param_2 = (int)DU8(OBJMem+0x7e);
	int itemcnt = (int)DU8(OBJMem+0x72);

	uVar5 = ( (0x15 < param_2) || (param_2==2) || (param_2==6) || (param_2==0x12) || (param_2==0x14));
	iVar2 = param_1->ItemPtr;
	if (*(char *)(iVar2 + 0x8a + (int)(short)uVar5) == 0) {
		*(undefined *)(iVar2 + 0x8c + (int)(short)uVar5) = 0;
	}
	pbVar6 = (byte *)((uint)uVar5 * 0x12 + iVar2 + 0x66);
	local_6 = (ushort)*(byte *)(iVar2 + 0x8a + (int)(short)uVar5);
	while (local_6 != 0) {
		if ((uint)*pbVar6 == param_2) {
			if(itemcnt!=0) {
				if (PU8(0x2ea436)[(short)(ushort)*pbVar6] < pbVar6[1]+itemcnt) {
					return 0;
				}
				pbVar6[1] = pbVar6[1] + itemcnt;
				DU8(OBJMem+0x72)=0;
			} else {
				if (PU8(0x2ea436)[(short)(ushort)*pbVar6] <= pbVar6[1]) {
					return 0;
				}
				pbVar6[1] = pbVar6[1] + 1;
			}

			return (uint)pbVar6[1];
		}
		pbVar6 = pbVar6 + 2;
		local_6 = local_6 - 1;
	}
	if (*(char *)(iVar2 + 0x8a + (int)(short)uVar5) == 8) {
		return 0;
	}
	if ((*(byte *)(iVar2 + 0x8a) | *(byte *)(iVar2 + 0x8b)) == 0) {
		*(char *)(iVar2 + 0x96) = 0x15 < (int)param_2;
	}
	*(undefined *)
	((uint)uVar5 * 0x12 + iVar2 + (uint)*(byte *)(iVar2 + 0x8a + (int)(short)uVar5) * 2 +
	 0x66) = (char)param_2;
	if ((DU8( 0x813534 )== 0) || ((int)param_2 < 0x36)) {
		iVar3 = (uint)uVar5 * 0x12 + iVar2 +
		        (uint)*(byte *)(iVar2 + 0x8a + (int)(short)uVar5) * 2;
		cVar4 = PU8(0x2ef884)[param_2];
		if(itemcnt!=0) {
			cVar4 = itemcnt;
			DU8(OBJMem+0x72)=0;
		}
	} else {
		if (8 < PU8(0x2ef884)[param_2] * 2) {
			*(undefined *)
			((uint)uVar5 * 0x12 + iVar2 +
			 (uint)*(byte *)(iVar2 + 0x8a + (int)(short)uVar5) * 2 + 0x67) = 9;
			pcVar1 = (char *)(iVar2 + 0x8a + (int)(short)uVar5);
			*pcVar1 = *pcVar1 + 1;
			FUN_00160f06(param_1);
			return 1;
		}
		iVar3 = (uint)uVar5 * 0x12 + iVar2 +
		        (uint)*(byte *)(iVar2 + 0x8a + (int)(short)uVar5) * 2;
		cVar4 = PU8(0x2ef884)[param_2] * 2;
		if(itemcnt!=0) {
			cVar4 = itemcnt;
			DU8(OBJMem+0x72)=0;
		}
	}
	*(char *)(iVar3 + 0x67) = cVar4;

	pcVar1 = (char *)(iVar2 + 0x8a + (int)(short)uVar5);
	*pcVar1 = *pcVar1 + 1;
	FUN_00160f06(param_1);

	return cVar4;
}




void CreatItem(short x,short y,short z,int ItemID,int ItemCnt,int xFlip) {
	int OBJID;
	int DropID;
	if(ItemID!=0) {
		OBJID = CreatObj_0016f530();
		DropID = FUN_00169570();
		PU8(0x80dfa4)[DropID] = OBJID;
		SetObjBaseData_0016f762(OBJID,0x2efb00,x,y,z,xFlip);
		SetOBJScript_00171ae8(OBJID,PU32(0x2efb70)[ItemID]);
		SetObjPicID_00171d16(OBJID,PU16(0x2efeca)[ItemID]);
		SetObjPalID_0016fc3e(OBJID,PU8(0x2efcf0)[ItemID]);
		DU8(0x80e322+OBJID*0x9c+0x72) = ItemCnt;
		FUN_00171d56(OBJID,ItemID);
		FUN_00171f6a(OBJID,0);
		FUN_0016fc88(OBJID,0x1695b4);
	}
	return;
}



void DropItem(int PlayerID) {
	int itemcnt;
	if(DU8(gRoleMem[PlayerID].ItemPtr +0x96)==0) { //第一页
		gRoleMem[PlayerID].UseItem = DU8(gRoleMem[PlayerID].ItemPtr +0x66 +DU8(gRoleMem[PlayerID].ItemPtr + 0x8c )*2);
		itemcnt = DU8(gRoleMem[PlayerID].ItemPtr +0x66 +DU8(gRoleMem[PlayerID].ItemPtr + 0x8c )*2 + 1);
	} else {
		gRoleMem[PlayerID].UseItem = DU8(gRoleMem[PlayerID].ItemPtr +0x66+0x12 +DU8(gRoleMem[PlayerID].ItemPtr + 0x8c+1 )*2);
		itemcnt = DU8(gRoleMem[PlayerID].ItemPtr +0x66+0x12 +DU8(gRoleMem[PlayerID].ItemPtr + 0x8c+1 )*2 + 1);
	}
	if(gRoleMem[PlayerID].UseItem!=0 && gRoleMem[PlayerID].UseItem!=0x34 && gRoleMem[PlayerID].UseItem!=0x35 ) {
		//让道具出现在角色面前
		CreatItem(gRoleMem[PlayerID].x +70+ ((gRoleMem[PlayerID].Zmode >> 6) & 1)*-140,gRoleMem[PlayerID].y,0,gRoleMem[PlayerID].UseItem,itemcnt,((gRoleMem[PlayerID].Zmode >> 6) & 1));
		//道具栏里删除对应道具
		FUN_00160c5e((int)&gRoleMem[PlayerID],gRoleMem[PlayerID].UseItem );
		PlaySound_001f6d34(0,76,255,1);
	}


}

void ChkMove(RoroMem *Role) {
	int PlayerID = ((int)Role - 0x8114f4)/438;
	if(DU8(Role->PlayerMemPtr+0x1b)==3 && DU8(gRoleMem[PlayerID].ItemPtr)==0 ) { //BC并且不能打开道具栏
		Role->field_0xe2=0;
		ExecRoleAction_0017ef5c(Role, SetRoleAction_0017edd8(Role,2,0x1e));
		DropItem(PlayerID);


		return;
	}
	FUN_00182b06(Role);
}


/*


void ChkPlayerInput(RoroMem *Role) {
	int iVar6=0,iVar7=0,iVar2,iVar1;
	int KeyA,KeyB,KeyC;
	int ActType,ActID,Zmode;

	if(DU8(0x8129b8)==0) {
		if((Role->field_0x110 & 0x20) == 0) {
			if(Role->PlayerMemPtr==0)
				return;
			iVar7 = FUN_00174166(Role->PlayerMemPtr);
			return;
		}
	}
	if(Role->field_0x104 == -0x7e)
		return;
	if(Role->field_0x104 == -0x80)
		return;
	if(Role->field_0x104 == -0x7f)
		FUN_001615aa(Role->PlayerMemPtr);
	else {
		FUN_0017424a(Role->PlayerMemPtr);
		FUN_0016166e(Role->PlayerMemPtr);
	}
	//以上是处理按键输入的内存

	//下面开始处理根据按键指令发招
	//KeyA&0x40 = HOLD_UP
	//KeyA&0x20 = HOLD_DOWN
	//KeyA&0x10 = HOLD_LEFT
	//KeyA&0x08 = HOLD_RIGHT
	KeyA = DU8(Role->PlayerMemPtr+0x1a);//KEYA检测方向+ABC的组合键是否同时按下，松开清零
	KeyB = DU8(Role->PlayerMemPtr+0x1b);//KEYB只检测ABC按键的PRESS值，用完就清零
	KeyC = DU8(Role->PlayerMemPtr+0x262);
	ActType = Role->ActType;
	ActID = Role->ActID;
	Zmode = Role->Zmode;

	Print(0,6,10,0,0,"A");

	//首先判断KEYA有按键被按住，或者C D键有被按下
	if( (KeyA!=0) || ((KeyC & 0x80)!=0) || (( KeyC & 0x40) != 0)) {
		if( FUN_0018a9f6(Role)!=0) {  //这里进行招式输入流判断，判断如果符合招式表的招式就直接出招式后返回
			if(Role->field_0x11a!=0) {
				FUN_0017e872(Role,0);
			}
			ExecRoleAction_0017ef5c(Role, SetRoleAction_0017edd8(Role,6,Role->field_0x14c));//这里根据输入的招式调取角色的SKILL动作
			FUN_00189dde(Role);
			return ;
		}

		if( (ActType == 3) && (ActID < 5) && ((Zmode & 0x38) == 0 && FUN_00186b3e()==0) ) {
			if(ActID == 0) {
				if((Zmode&0x40)==0) {//判断角色面朝方向
					if((KeyA&0x10)!=0) {//HOLD_LEFT
						FUN_00181ddc(Role);
						Role->field_0xe2=0;
						return;
					}
				} else {
					if((KeyA&0x08)!=0) {//HOLD_RIGHT
						FUN_00181ddc(Role);
						Role->field_0xe2=0;
						return;
					}
				}
			}

			//判断AB同时按下，HP大于8，其他条件可能是招式能否取消之类的判断
			if( ((KeyB&4)!=0) && ((KeyB&2)!=0) && (Role->HP > 8 && (DU8(0x81352c)!=1 && ((Role->field_0xd3&4)==0) ) )  ) {
				iVar7 = GetRoleActionOff_0017eee6(Role,3,9);//获取AB扣血的动作指针
				if(iVar7==0)
					return;
				ExecRoleAction_0017ef5c(Role,iVar7);//执行动作
				Role->HP += -8;//让角色HP-8
				FUN_00175c88(Role->PlayerMemPtr,-8);//传给画血条的变动值
				Role->field_0xe2=0;
				return;
			}
		}

		if( ((Role->field_0x18e & 0x60)!=0) && ((KeyB&4)!=0) ) { //按了A键
			if( (Role->field_0x18e & 0x60)!=0x20 ) {
				Role->field_0x18e &= 0xf7;
				return;
			}
			if( (ActType==3) && (ActID==7) ) {//如果在66A的话
				ExecRoleAction_0017ef5c(Role, SetRoleAction_0017edd8(Role,3,0));//执行第一下A的动作
				return;
			}
			Role->field_0x18e ^= 8;
			if((Role->field_0x195 & 0x80) ==0)
				return;
			Role->field_0x18e &= 0x9f;
			Role->field_0x18e ^= 0x40;
			return;
		}
	}


	if((ActType != 2) && ((Role->field_0x188 & 0x40)==0) ) {
		if ((ActType==8) && ( (ActID==0x17) && ((KeyB&4)!=0)) ) {//如果在防御成功以后按了A
			iVar7 = GetRoleActionOff_0017eee6(Role,3,12);//获取防御反击动作指针
			if(iVar7==0)
				return;
			ExecRoleAction_0017ef5c(Role,iVar7);//执行动作
			return;
		}

		if (Role->unknow6 != 0) {
			Role->field_0xe2 = 0;
			Role->field_0xec = -0x30;
			return;
		}

		if(ActType != 3)
			return;

		if( ((Zmode & 0x40)!=0) && ((KeyB&8) != 0) )
			Role->Zmode &= 0xbf;

		if( (Role->Zmode & 0x40) !=0 )
			return;

		if((KeyB&0x10)==0)
			return;

		Role->Zmode ^= 0x40;
		return;
	}

	//if(KeyB == 5)
	//ExecRoleAction_0017ef5c(Role, SetRoleAction_0017edd8(Role,2,1));//



	//这里是举起石头后判断按了A B C D任意键都扔掉石头
	if ( Role->field_0x11a != 0  && (((KeyB&4)!=0) || ((KeyB&2)!=0) || ((KeyC&0x80)!=0) || ((KeyC&0x40)!=0)) ) {
		ExecRoleAction_0017ef5c(Role, SetRoleAction_0017edd8(Role,2,0x2b));//扔石头的动作
		FUN_0017d44c(Role);
		Role->field_0xe2 = 0;
		return;
	}

	if(ActType == 2) { //在地面动作中
		if( (Zmode & 0x38) == 0 ) //在地面
			iVar6 = 1;
		else if((Zmode & 0x38)==0x20)//在下蹲
			iVar7 = 1;
	}

	if (iVar6) { //在地面
		if(ActID==0x16) return;
		if(ActID==0x1f) return;
		if(ActID==0x38) return;
		if(ActID==0x39) return;
		if(ActID==0x16) return;
		if(ActID==0x2b) return;
	}

	if (iVar6) { //在地面
		if( (Role->PowerCnt!=0) && (Role->PowerTime==0) ) { //判断有气，并且不在曝气状态
			if( ( (KeyB&4)==0) || (((KeyB&2)==0) || (((KeyC&0x80)==0))) ) { //检查ABC没有同时按的话
				if( ((KeyB&2)!=0) && ((KeyC&0x80)!=0) && ((KeyC&0x40) !=0) && Role->PowerCnt == 3 && Role->RoroRom->RoleAttr == 0 ) { //BCD同时按了，并且有3个能量，并且是A面人物
					if(FUN_0019905c()==0) { //这里不知道干啥 获取0x81b26a的值
						FUN_0017d600(Role);//执行BCD曝气
						return;
					}
				}
			} else { //这里就是ABC同时按住的情况下
				if(FUN_0019905c()==0) { //获取0x81b26a的值
					FUN_0017fba2(Role);//执行ABC曝气
					return;
				}
			}
		}

		//判断AB使用的条件，HP大于8，AB同时按
		if( ((KeyB&4)!=0) && ((KeyB&2)!=0) && ((Role->HP>8) && ((Role->field_0xd3&4)==0)) ) {
			if( (DU8(0x81352c)!=1) && (FUN_00186b3e()==0)) {
				iVar7 = GetRoleActionOff_0017eee6(Role,3,9);//获取AB扣血的动作指针
				if(iVar7==0)
					return;
				ExecRoleAction_0017ef5c(Role,iVar7);//执行动作
				Role->HP += -8;//让角色HP-8
				FUN_00175c88(Role->PlayerMemPtr,-8);//传给画血条的变动值
				Role->field_0xe2=0;
				return;
			}
		}


		//判断C被按住，并且按住左或者右
		if( ( (KeyC&0x80)!=0)  && (((KeyA&0x10)!=0) || ((KeyA&8)!=0)) && (ActID!=0x3a) ) {
			FUN_0015ff24(Role);
			ExecRoleAction_0017ef5c(Role, SetRoleAction_0017edd8(Role,2,0x3a));//执行格挡动作
			Role->field_0xe2 =0;
			return;
		}


		iVar1 = 1;
	}

	if(iVar7) { //在下蹲中

		if(((KeyC&0x80)!=0)) {
			iVar1 = 1;
			ExecRoleAction_0017ef5c(Role, SetRoleAction_0017edd8(Role,2,1));//执行站立动作
		}
	}

	if( ((KeyC&0x40)!=0) && (FUN_00160242(Role,Role->ItemPtr)!=0) ) { //按了D键，直接执行放道具
		Role->field_0xe2=0;
		return;
	}

	if((iVar1!=0) && (FUN_001607a6(Role)!=0)) {
		Role->field_0xe2=0;
		if( (KeyA&1)==0 )//如果没按C键
			return;
		if( FUN_00182b06(Role)==0) return;//这里检测跑步和下蹲
		FUN_00181ddc(Role);
		return;
	}

	if( (KeyC&0x20)!=0 )//不知道是啥
		return;

	//判断能否追地，并且按了A
	if( ((KeyB&4)!=0) && ((FUN_0017d4d4(Role)!=0) && ((Role->field_0xd3&4)==0))) {
		iVar7 = GetRoleActionOff_0017eee6(Role,3,10);//获取追地的动作指针
		if(iVar7==0)
			return;
		ExecRoleAction_0017ef5c(Role,iVar7);//执行动作
		Role->field_0xe2 = 0;
		Role->field_0x154 = -1;
		Role->field_0x155 = 0;
		return;
	}

	if( ((KeyA!=0) || (ActType!=2)) || ((Role->field_0xd3&4)!=0) ) {
		Role->field_0xec = -0x30;
		while (Role->field_0xec != 0) {
			if( (KeyB&4)!=0 ) { //按了A键，普通攻击
				Role->field_0xe2 = 0;
				FUN_00182e08(Role);
				return;
			}

			if( (KeyB&2) == 0 ) { //按了B键

				if( ActType!=2 || (((Zmode&0x38) !=0) && ((Zmode&0x38)!=0x20)) ) {
					Role->field_0xe2=0;
					return;
				}
				if(KeyA==0)
					return;
				if(ActID==0x17)
					return;
				iVar6 = (ActID == 0x3a);
			} else {

				Role->field_0xe2 = 0;
				if((Zmode&0x38)==0x20) {
					Role->Zmode &= 199;
					FUN_00181ddc(Role);
					return;
				}
				if(FUN_0017f2fe(Role)) {
					FUN_0018208e(Role);
					return;
				}
				iVar6 = (iVar6==0);





			}
			if(!iVar6)
				FUN_00182b06(Role);//下蹲或者移动
			return;
		}
	}


	if(ActID==1)
		iVar7 = 0;
	else {
		if(ActID==0x24) {
			Role->field_0xe2=0;
			return;
		}
		iVar7 = 0x23;
	}

	ExecRoleAction_0017ef5c(Role, SetRoleAction_0017edd8(Role,2,iVar7));
	Role->field_0xe2=0;
	return;


}

*/










/*	if (((Role->ActType == 3) && (Role->ActID < 5)) && ((_uVar6 = 0, (Role->Zmode & 0x38) == 0 && (_uVar6 = FUN_00186b3e(), _uVar6 == 0)))) {
		if(Role->ActID == 0) {
			_uVar6 == 0;
			if((Role->Zmode & 0x40)==0) {
				if(((DU8(Role->PlayerMemPtr + 0x1a) & 0x10)!=0)) {
					iVar7 = FUN_00181ddc((int)Role);
					Role->field_0xe2 = 0;
					return iVar7;
				}
			} else {
				if(((DU8(Role->PlayerMemPtr + 0x1a) & 8)!=0)) {
					iVar7 = FUN_00181ddc((int)Role);
					Role->field_0xe2 = 0;
					return iVar7;
				}
			}
		}

		if(((DU8(Role->PlayerMemPtr + 0x1b) & 4)!=0) && ((DU8(Role->PlayerMemPtr + 0x1b) & 2)!=0) && ((Role->HP > 8)) && (DU8(0x81352c)!=1) && ((Role->field_0xd3 & 4)==0) ) {
			iVar7 = GetRoleActionOff_0017eee6((int)Role,3,9);//AB扣血动作

			if(iVar7==0)
				return 0;
			ExecRoleAction_0017ef5c((int)Role,iVar7);
			Role->HP += -8;
			iVar7 = FUN_00175c88(Role->PlayerMemPtr,-8);
			Role->field_0xe2 = 0;
			return iVar7;
		}
	}
*/















/*


	if( (KeyB & 4)!=0) { //按了A
		Role->field_0xe2 = 0;
		iVar7 = FUN_00182e08(Role);//执行A的动作的第一下
		return iVar7;
	}

	if( (KeyB & 2) !=0 ) {
		Role->field_0xe2 = 0;
		if( (Zmode & 0x38)==0x20 ) {
			Role->Zmode &= 199;
			iVar7 = FUN_00181ddc(Role);
			return iVar7;
		}
		iVar7 = FUN_0017f2fe(Role);
		if(iVar7 != 0) {
			iVar7 = FUN_0018208e(Role);
			return iVar7;
		}
		iVar12 = !iVar12;
		if(!iVar12)
			iVar7 = FUN_00182b06(Role);

	}





*/





/*


	if((Role->ActType == 2) && ((Role->field_0x188 & 0x40)==0) ){
		if( (Role->ActType==8) && ((Role->ActID==0x17) && ((DU8(Role->PlayerMemPtr + 0x1b) & 4)!=0)) ){
			iVar7 = GetRoleActionOff_0017eee6((int)Role,3,12);
			if(iVar7!=0){
				iVar7 = ExecRoleAction_0017ef5c((int)Role,iVar7);
				return iVar7;
			}
		}

	}


*/




