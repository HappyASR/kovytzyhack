#ifndef _USE_SIMPLE_TYPE_
#define _USE_SIMPLE_TYPE_
typedef unsigned char	BYTE;
typedef unsigned short	WORD;
typedef unsigned long	LONG;
#endif 

#define INPUT_INS_END 0x4000	//����ָ����������־
#define INP_INS_END   0x4000
#define INP_UP 1				//��
#define INP_DOWN 2				//��
#define INP_LEFT 3				//��
#define INP_RIGHT 4				//��
#define INP_A 0x81				//A
#define INP_B 0x82				//B
#define INP_C 0x84				//C
#define INP_D 0x88				//D
#define INP_UNKNOW1 0x14		//

#define OPT_BURST_HYPER 0x901A			//������ɱ����
#define OPT_COMM_HYPER 0x900A			//��ͨ��ɱ����
#define OPT_BURST_SUPER 0x9012			//������ɱ����
#define OPT_COMM_SUPER	0x9002			//��ͨ��ɱ����
#define OPT_AIR_SUPER 0x3820			//���б�ɱ����
  

//����ָ�����нṹ

 /*
struct InputInsElem{
	unsigned short KeyInput;					//���뷽��򰴼�
	unsigned short Unknown;					//δ֪
	unsigned short Option;					//������������������DELAY
};
*/

typedef struct{
	unsigned short KeyInput;					//���뷽��򰴼�
	unsigned short Unknown;					//δ֪
	unsigned short Option;					//������������������DELAY
}InputInsElem;


//KOV������ʽ����ṹ
/*
struct KovInputElem{

	struct InputInsElem *Ins;			//����ָ����
	unsigned short FixVal32;					//�̶�ֵ0x32
	unsigned short ActionId;					//����ID
	unsigned short Option;					//��ɱ����ɱ���ɷ���е�
};
*/

typedef struct{
	InputInsElem *Ins;	
	unsigned short FixVal32;
	unsigned short ActionId;
	unsigned short Option;
}KovInputElem;

//����ṹ��
#define InputElem(ptr,actid,opt) {ptr,0x32,actid,opt};

//����ָ������
#define InsElem(key,unk,opt) {key,unk,opt};