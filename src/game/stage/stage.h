


struct BitMapMaskInfo {
	short width;//宽
	short height;//高
	char unknow1;//08
	char unknow2;//08
	int dataptr;//数据指针
};

typedef struct {
	int MotionAmount;	//场景数量
	int Func1;			//关卡初始化函数，在整个关卡载入时执行
	int Func2;			//执行场景函数1
	int Func3;			//执行场景函数2
	int Func4;			//执行场景函数3
	int Func5;			//执行场景函数4
	int Func6;			//执行场景函数5
	int Func7;			//执行场景函数6
	int Fix1;			//未知1
	int Func8;			//获取场景时间值
	int Func9;			//未知0
} StageFunction;

typedef struct {

	int Func1;			//场景初始化函数
	int Func2;			//场景函数2
	int Func3;			//场景函数3
	int Func4;			//场景函数4
	int Func5;			//场景函数5
	int Func6;			//场景函数6
	short Time;			//场景时间
	short Fix0;			//未知0

} MotionFunction;

extern void ST1M0F1();
extern void ST1M0F1();
extern int ST1M0F2();
extern void ST1M0F3();
extern void ST1M0F4(int param_1);
extern void ST1M0F5();
extern void ST1M0F6(int param_1);



extern void ST1M2F1();
extern int ST1M2F2();
extern void ST1M2F3();
extern void ST1M2F4(int param_1);
extern void ST1M2F5();
extern void ST1M2F6(int param_1);

extern void ST1M4F1();
extern int ST1M4F2();
extern void ST1M4F3();
extern void ST1M4F4(int param_1);
extern void ST1M4F5();
extern void ST1M4F6(int param_1);

//ST1M6
extern void ST1M6F1();
extern int ST1M6F2();
extern void ST1M6F3();
extern void ST1M6F4(int param_1);
extern void ST1M6F5();
extern void ST1M6F6(int param_1);

//ST1M13
extern void ST1M13F1();
extern int ST1M13F2();
extern void ST1M13F3();
extern void ST1M13F4(int param_1);
extern void ST1M13F5();
extern void ST1M13F6(int param_1);







