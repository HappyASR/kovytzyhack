#ifndef _USE_SIMPLE_TYPE_
#define _USE_SIMPLE_TYPE_
typedef unsigned char	BYTE;
typedef unsigned short	WORD;
typedef unsigned long	LONG;
#endif 

//ϵͳ���������չ�����

//����ϵͳHITS����������8�����ֱ�������Ƿ�������ROLE ID��ÿ����С0x52*12,˫�ֽ�
//HITS�����
#define KOVH_EXP_ADD_TBL_SIZE 41*12
//���ò���
#define KOVH_EXP_ADD_TBL0 0x30F82A
//�����ﲿ��
//����ǰ
#define KOVH_EXP_ADD_TBL1 0x30E9BA
//������
#define KOVH_EXP_ADD_TBL2 0x30ED92

//�����ﲿ�֣������󲻶�
#define KOVH_EXP_ADD_TBL3 0x30E5E2
//----------------------------------------------------------------------------------
//������������������
//ROLE_ID*100�ֽ�   ��������������25��
//������
#define COMM_ROLE_LEVEL_SCORE_TBL 0x30CEAA
//������
#define NEW_ROLE_LEVEL_SCORE_TBL 0x30D35A

//#define GetRoleId_Ptr 0x179A64

//#define GetRoleAttr_Ptr 0x179A80

//#define GetRolePtr_Ptr 0x179A52

//----------------------------------------------------------------------------------
//��ȡ/ʹ����Ʒ���Ʊ�ָ��,12��,ÿ�˴�С96*5BYTE
#define ITEM_LIMIT_TBL 0x13C1DC

#define ITEM_LIMIT_TBL_SIZE 96*5		//ÿ����

//----------------------------------------------------------------------------------
//ID��ش�������

//�Ի�����ʾ����
#define FUNC_SHOW_DIALOG 0x19C82A

#define OP_JSR 0x4EB9

#define OP_ID_REL_1	0x2F00		// move.l  d0, -(sp)