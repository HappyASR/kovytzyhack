void arm_cmd(int CMD,int Param);
void pause();
void ST1M1F1();

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