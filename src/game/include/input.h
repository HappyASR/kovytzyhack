#ifndef _USE_SIMPLE_TYPE_
#define _USE_SIMPLE_TYPE_
typedef unsigned char	BYTE;
typedef unsigned short	WORD;
typedef unsigned long	LONG;
#endif 

#define INPUT_INS_END 0x4000	//输入指令流结束标志
#define INP_INS_END   0x4000
#define INP_UP 1				//上
#define INP_DOWN 2				//下
#define INP_LEFT 3				//左
#define INP_RIGHT 4				//右
#define INP_A 0x81				//A
#define INP_B 0x82				//B
#define INP_C 0x84				//C
#define INP_D 0x88				//D
#define INP_UNKNOW1 0x14		//

#define OPT_BURST_HYPER 0x901A			//爆气超杀参数
#define OPT_COMM_HYPER 0x900A			//普通超杀参数
#define OPT_BURST_SUPER 0x9012			//爆气必杀参数
#define OPT_COMM_SUPER	0x9002			//普通必杀参数
#define OPT_AIR_SUPER 0x3820			//空中必杀参数
  

//输入指令序列结构

 /*
struct InputInsElem{
	unsigned short KeyInput;					//输入方向或按键
	unsigned short Unknown;					//未知
	unsigned short Option;					//参数，结束符或输入DELAY
};
*/

typedef struct{
	unsigned short KeyInput;					//输入方向或按键
	unsigned short Unknown;					//未知
	unsigned short Option;					//参数，结束符或输入DELAY
}InputInsElem;


//KOV人物招式输入结构
/*
struct KovInputElem{

	struct InputInsElem *Ins;			//输入指令流
	unsigned short FixVal32;					//固定值0x32
	unsigned short ActionId;					//动作ID
	unsigned short Option;					//必杀，超杀，可否空中等
};
*/

typedef struct{
	InputInsElem *Ins;	
	unsigned short FixVal32;
	unsigned short ActionId;
	unsigned short Option;
}KovInputElem;

//输入结构宏
#define InputElem(ptr,actid,opt) {ptr,0x32,actid,opt};

//输入指令流宏
#define InsElem(key,unk,opt) {key,unk,opt};