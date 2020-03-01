#ifndef _USE_SIMPLE_TYPE_
#define _USE_SIMPLE_TYPE_
typedef unsigned char	BYTE;
typedef unsigned short	WORD;
typedef unsigned long	LONG;
#endif 

#include "input.h"
#include "action.h"
#include "collision.h"
#include "pal.h"

//人物类型
#define FLAG_ROLE 0
#define FLAG_SOLDIER 1
#define FLAG_BOSS 2

//可选人物表里
#define ROLE_COMM 0
#define ROLE_NEW 1

//RET指针定义
#define FUNC_RET1 0x1AF7F6
#define FUNC_RET2 0x1AF7F8
#define FUNC_RET3 0x1AF7FA
#define FUNC_RET4 0x1AF7FC
#define FUNC_RET5 0x1AF7FE

//ROLE人物结构体
typedef struct{

		BYTE	FlagRole;					//人物类型
		BYTE	RoleId;						//人物ID
		BYTE	RoleAttr;					//人物表里属性
		BYTE	Fix20;						//固定值0x20
		BYTE	Fix40;						//固定值0x40
		BYTE	Fix00;						//保留

		LONG	FuncRet1;					//RET函数指针，下同
		LONG	FuncRet2;
		LONG	FuncRet3;
		LONG	FuncRet4;


		const BYTE* pAction;//const void* pAction;		//人物动作脚本指针
		const WORD *SpCaning_Index;			//人物被特殊攻击的反应索引表

		LONG	FuncRet5;					//RET函数指针


		const BYTE	*Damage3_Tbl;				//动作TYPE3攻击力表,0xd
		const WORD	*Damage3_Exp_Tbl;			//TYPE3经验值表

		const BYTE	*Damage6_Tbl;				//动作TYPE6攻击力表0x55
		const WORD	*Damage6_Exp_Tbl;			//TYPE6经验值表

		const WORD	**Pal_Array;					//颜色指针表指针
		const KovInputElem *input;					//指向输入结构体数组的指针
		const void	**Pic_Array;					//图片结构数组
		const WORD	*Origin_Array;					//图像对齐原点数据

		const WORD	*Coll_Index_Array;			//碰撞判定数据索引和数量
		const CollDataElem	*Coll_Data_Array;			//碰撞判定数据
		LONG	Base_Index;					//
		WORD	Rorolife;					//ROLE时为O

		WORD	Unknow_off_50;				//未知数据
		WORD	Unknow_off_52;
		WORD	Unknow_off_54;
		WORD	Unknow_off_56;
		WORD	Unknow_off_58;
		WORD	Unknow_off_5A;
		WORD	Unknow_off_5C;
		WORD	Unknow_off_5E;
		WORD	CaningSound3;					//以下，人物受创声音ID
		WORD	CaningSound2;
		WORD	CaningSound1;
		WORD	CaningSound0;

		const BYTE	*Damage3_Ratio_Tbl;			//TYPE3攻击比率
		const BYTE	*Damage6_Ratio_Tbl;			//TYPE6攻击比率

		WORD	Unknow_off_70;
		LONG	AI_Assign;
		WORD	Unknow_off_76;
		LONG	New_Pic_Array;				//新图指针
		LONG	Func_List;					//某函数表

		const BYTE **Cancel_Action_Array;				//动作取消相关指针
		LONG	Unknow_off_84;
		LONG	AI_Relate;					//ROLE是为空
		LONG	Unknow_off_8C;
		LONG	Unknow_off_90;

}Role_Struc;


