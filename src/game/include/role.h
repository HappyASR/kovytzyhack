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

//��������
#define FLAG_ROLE 0
#define FLAG_SOLDIER 1
#define FLAG_BOSS 2

//��ѡ�������
#define ROLE_COMM 0
#define ROLE_NEW 1

//RETָ�붨��
#define FUNC_RET1 0x1AF7F6
#define FUNC_RET2 0x1AF7F8
#define FUNC_RET3 0x1AF7FA
#define FUNC_RET4 0x1AF7FC
#define FUNC_RET5 0x1AF7FE

//ROLE����ṹ��
typedef struct{

		BYTE	FlagRole;					//��������
		BYTE	RoleId;						//����ID
		BYTE	RoleAttr;					//�����������
		BYTE	Fix20;						//�̶�ֵ0x20
		BYTE	Fix40;						//�̶�ֵ0x40
		BYTE	Fix00;						//����

		LONG	FuncRet1;					//RET����ָ�룬��ͬ
		LONG	FuncRet2;
		LONG	FuncRet3;
		LONG	FuncRet4;


		const BYTE* pAction;//const void* pAction;		//���ﶯ���ű�ָ��
		const WORD *SpCaning_Index;			//���ﱻ���⹥���ķ�Ӧ������

		LONG	FuncRet5;					//RET����ָ��


		const BYTE	*Damage3_Tbl;				//����TYPE3��������,0xd
		const WORD	*Damage3_Exp_Tbl;			//TYPE3����ֵ��

		const BYTE	*Damage6_Tbl;				//����TYPE6��������0x55
		const WORD	*Damage6_Exp_Tbl;			//TYPE6����ֵ��

		const WORD	**Pal_Array;					//��ɫָ���ָ��
		const KovInputElem *input;					//ָ������ṹ�������ָ��
		const void	**Pic_Array;					//ͼƬ�ṹ����
		const WORD	*Origin_Array;					//ͼ�����ԭ������

		const WORD	*Coll_Index_Array;			//��ײ�ж���������������
		const CollDataElem	*Coll_Data_Array;			//��ײ�ж�����
		LONG	Base_Index;					//
		WORD	Rorolife;					//ROLEʱΪO

		WORD	Unknow_off_50;				//δ֪����
		WORD	Unknow_off_52;
		WORD	Unknow_off_54;
		WORD	Unknow_off_56;
		WORD	Unknow_off_58;
		WORD	Unknow_off_5A;
		WORD	Unknow_off_5C;
		WORD	Unknow_off_5E;
		WORD	CaningSound3;					//���£������ܴ�����ID
		WORD	CaningSound2;
		WORD	CaningSound1;
		WORD	CaningSound0;

		const BYTE	*Damage3_Ratio_Tbl;			//TYPE3��������
		const BYTE	*Damage6_Ratio_Tbl;			//TYPE6��������

		WORD	Unknow_off_70;
		LONG	AI_Assign;
		WORD	Unknow_off_76;
		LONG	New_Pic_Array;				//��ͼָ��
		LONG	Func_List;					//ĳ������

		const BYTE **Cancel_Action_Array;				//����ȡ�����ָ��
		LONG	Unknow_off_84;
		LONG	AI_Relate;					//ROLE��Ϊ��
		LONG	Unknow_off_8C;
		LONG	Unknow_off_90;

}Role_Struc;


