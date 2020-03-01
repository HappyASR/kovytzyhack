#ifndef _USE_SIMPLE_TYPE_
#define _USE_SIMPLE_TYPE_
typedef unsigned char	BYTE;
typedef unsigned short	WORD;
typedef unsigned long	LONG;
#endif 

//系统调用相关扩展表包含

//乱世系统HITS分数增量表，8个，分表里人物，是否爆气，按ROLE ID，每个大小0x52*12,双字节
//HITS数相关
#define KOVH_EXP_ADD_TBL_SIZE 41*12
//公用部分
#define KOVH_EXP_ADD_TBL0 0x30F82A
//里人物部分
//爆气前
#define KOVH_EXP_ADD_TBL1 0x30E9BA
//爆气后
#define KOVH_EXP_ADD_TBL2 0x30ED92

//表人物部分，爆气后不读
#define KOVH_EXP_ADD_TBL3 0x30E5E2
//----------------------------------------------------------------------------------
//乱世人物升级分数表
//ROLE_ID*100字节   人物升级分数表，25级
//表人物
#define COMM_ROLE_LEVEL_SCORE_TBL 0x30CEAA
//里人物
#define NEW_ROLE_LEVEL_SCORE_TBL 0x30D35A

//#define GetRoleId_Ptr 0x179A64

//#define GetRoleAttr_Ptr 0x179A80

//#define GetRolePtr_Ptr 0x179A52

//----------------------------------------------------------------------------------
//捡取/使用物品限制表指针,12个,每人大小96*5BYTE
#define ITEM_LIMIT_TBL 0x13C1DC

#define ITEM_LIMIT_TBL_SIZE 96*5		//每个人

//----------------------------------------------------------------------------------
//ID相关代码搜索

//对话框显示程序
#define FUNC_SHOW_DIALOG 0x19C82A

#define OP_JSR 0x4EB9

#define OP_ID_REL_1	0x2F00		// move.l  d0, -(sp)