#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../game_type.h"
#include "../game_func.h"
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



const int Stage1MotionTbl[]= { //STAGE1 第一关 截江救阿斗
	0x1E2BFA, 0x1E379C, 0x1E37D4, 0x1E383E, 0x1E3850, 0x1E3766, 0x630000,
	0x1DD2BA, 0x1DD59C, 0x1DD78E, 0x1DD7EC, 0x1DD7FE, 0x1DD550, 0x3C0000,
	0x1DDA38, 0x1DDE54, 0x1DE556, 0x1DE558, 0x1DE56A, 0x1DDDCC, 0x630000,
	0x1DE6C0, 0x1DE94C, 0x1DEA56, 0x1DEA58, 0x1DEA6A, 0x1DE8FE, 0x280000,
	0x1DF09A, 0x1DF4A6, 0x1DF790, 0x1DF792, 0x1DF7A4, 0x1DF3B6, 0x210000,
	0x1DF8CC, 0x1DFCF8, 0x1DFE82, 0x1DFE84, 0x1DFEFA, 0x1DFCA0, 0x3C0000,
	0x1DFFBC, 0x1E026A, 0x1E03EC, 0x1E03EE, 0x1E0400, 0x1E021C, 0x280000,
	0x1E0576, 0x1E0840, 0x1E0952, 0x1E09BA, 0x1E09CC, 0x1E07C8, 0x2D012C,
	0x1E0ADC, 0x1E0D10, 0x1E0E7E, 0x1E0EDC, 0x1E0EEE, 0x1E0CCE, 0x2D012C,
	0x1E18AC, 0x1E1CA0, 0x1E1DA6, 0x1E1DA8, 0x1E1E1E, 0x1E1C24, 0x630000,
	0x1E20E4, 0x1E2320, 0x1E248C, 0x1E248E, 0x1E24A0, 0x1E22D4, 0x2D0000,
	0x1E260A, 0x1E2850, 0x1E2962, 0x1E2964, 0x1E2976, 0x1E2802, 0x2D0154,
	0x1E3A70, 0x1E3E06, 0x1E3E86, 0x1E3E88, 0x1E3F3E, 0x1E3DBE, 0x630000,
};

const int Stage2MotionTbl[]= { //第二关 定军斩夏侯
	0x1E848A, 0x1E8696, 0x1E8848, 0x1E884A, 0x1E885C, 0x1E864A, 0x630000,
	0x1F051C, 0x1F0ACA, 0x1F0F3A, 0x1F0F3C, 0x1F0F4E, 0x1F07AA, 0x630000,
	0x1EDEFC, 0x1EE208, 0x1EE362, 0x1EE364, 0x1EE376, 0x1EE1BC, 0x630000,
	0x1F32D2, 0x1F3A38, 0x1F3D7E, 0x1F3D92, 0x1F3DC0, 0x1F3590, 0x630190,
	0x1EE432, 0x1EF37A, 0x1EFA4A, 0x1EFA80, 0x1EFB30, 0x1EE6DE, 0x630000,
	0x1E9A58, 0x1EA36E, 0x1EA5AE, 0x1EA5C2, 0x1EA5C4, 0x1EA2BE, 0x630000,
	0x1EA676, 0x1EAAFA, 0x1EACA4, 0x1EACC0, 0x1EACD2, 0x1EA8F8, 0x630000,
	0x1ED350, 0x1ED638, 0x1ED772, 0x1ED7D2, 0x1ED7E4, 0x1ED5EA, 0x630000,
	0x1EC5DC, 0x1ECEAC, 0x1ED1B0, 0x1ED21A, 0x1ED29E, 0x1EC926, 0x630000,
	0x1F1000, 0x1F15B2, 0x1F1792, 0x1F17AE, 0x1F17DC, 0x1F1284, 0x630000,
	0x1EB326, 0x1EB678, 0x1EB80C, 0x1EB80E, 0x1EB820, 0x1EB59C, 0x630000,
	0x1EB9C4, 0x1EC10E, 0x1EC372, 0x1EC3C2, 0x1EC42A, 0x1EBC7E, 0x630000,
	0x1F2298, 0x1F2894, 0x1F2EDA, 0x1F2EDC, 0x1F2FD2, 0x1F251E, 0x630000,
	0x1EAD84, 0x1EB01E, 0x1EB1A8, 0x1EB208, 0x1EB21A, 0x1EAFD0, 0x630000,
	0x1E43F8, 0x1E4CE6, 0x1E54B2, 0x1E553E, 0x1E5550, 0x1E46B4, 0x630000,
	0x1E57F8, 0x1E5D76, 0x1E5EAE, 0x1E5ECA, 0x1E5EDC, 0x1E5A8C, 0x630190,
	0x1E60D6, 0x1E6422, 0x1E651E, 0x1E6520, 0x1E6532, 0x1E63D6, 0x1E0000,
	0x1E65E4, 0x1E6918, 0x1E6A32, 0x1E6A34, 0x1E6A46, 0x1E68C8, 0x630000,
	0x1E6C56, 0x1E6FE0, 0x1E7140, 0x1E7142, 0x1E7170, 0x1E6F54, 0x630000,
	0x1F19D0, 0x1F1C5C, 0x1F1C7A, 0x1F1C7C, 0x1F1C8E, 0x1F1C52, 0x630000,
	0x1F1DC0, 0x1F209E, 0x1F20BC, 0x1F20BE, 0x1F20D0, 0x1F2042, 0x630000,
	0x1E7A9E, 0x1E7F12, 0x1E812C, 0x1E812E, 0x1E8140, 0x1E7E9A, 0x630000,
	0x1E7332, 0x1E7538, 0x1E7638, 0x1E763A, 0x1E764C, 0x1E74EC, 0x630000,
	0x1E8C60, 0x1E8EC8, 0x1E901C, 0x1E901E, 0x1E9030, 0x1E8E7C, 0x630000,
	0x1E9434, 0x1E96E2, 0x1E97D6, 0x1E97D8, 0x1E97EA, 0x1E9696, 0x630000,
	0x1F3F90, 0x1F426E, 0x1F42EE, 0x1F42F0, 0x1F4302, 0x1F4220, 0x630000,
};

const int Stage3MotionTbl[]= { //第三关 威震汉中池
	0x1B1746, 0x1B1B1E, 0x1B1DA6, 0x1B1DA8, 0x1B1E20, 0x1B1A60, 0x630190,
	0x1B2066, 0x1B2832, 0x1B2BB4, 0x1B2BB6, 0x1B2BEA, 0x1B2426, 0x630000,
	0x1B2FFA, 0x1B3274, 0x1B340C, 0x1B340E, 0x1B3420, 0x1B3226, 0x630000,
	0x1B3604, 0x1B3A6E, 0x1B3D12, 0x1B3D7C, 0x1B3DB0, 0x1B3898, 0x630000,
	0x1B4422, 0x1B48BC, 0x1BA5C8, 0x1BA4DC, 0x1BA56A, 0x1B439A, 0x630190,
	0x1B5106, 0x1B58FC, 0x1B5DE0, 0x1B5DF4, 0x1B5E06, 0x1B582E, 0x630190,
	0x1B61AA, 0x1B64A2, 0x1B66DC, 0x1B66F0, 0x1B6702, 0x1B6454, 0x630000,
	0x1B6B92, 0x1B6FD2, 0x1B7258, 0x1B726C, 0x1B727E, 0x1B6F50, 0x630000,
	0x1B7486, 0x1B7726, 0x1B789E, 0x1B78A0, 0x1B78B2, 0x1B76DC, 0x630190,
	0x1B7A16, 0x1B7C50, 0x1B7E2A, 0x1B7E2C, 0x1B7E3E, 0x1B7BE4, 0x630190,
	0x1B809E, 0x1B8488, 0x1B8678, 0x1B867A, 0x1B868C, 0x1B8400, 0x630208,
	0x1B886A, 0x1B8B12, 0x1B8C92, 0x1B8C94, 0x1B8CA6, 0x1B8AC6, 0x6301B8,
	0x1B8EF0, 0x1B9134, 0x1B9338, 0x1B933A, 0x1B934C, 0x1B90E6, 0x630208,
	0x1B961C, 0x1B98FC, 0x1B9A1A, 0x1B9A1C, 0x1B9A2E, 0x1B98AE, 0x630208,
	0x1B9C82, 0x1B9F38, 0x1BA1AE, 0x1BA1B0, 0x1BA1C2, 0x1B9EEA, 0x630190,
	0x1BB674, 0x1BB942, 0x1BB9C2, 0x1BB9C4, 0x1BB9D6, 0x1BB8F4, 0x630000,
};

const int Stage4MotionTbl[]= { //第四关 大意失荆州
	0x1C5D76, 0x1C60AE, 0x1C6494, 0x1C6496, 0x1C64D8, 0x1C6060, 0x630000,
	0x1C544E, 0x1C573E, 0x1C5864, 0x1C5866, 0x1C5878, 0x1C56F0, 0x3C0000,
	0x1C45D8, 0x1C488A, 0x1C4A9E, 0x1C4AA0, 0x1C4AB2, 0x1C483C, 0x630000,
	0x1C38CC, 0x1C3BE2, 0x1C3E3E, 0x1C3E40, 0x1C3E52, 0x1C3B94, 0x3C01B8,
	0x1C4C88, 0x1C4FB6, 0x1C51DC, 0x1C51DE, 0x1C51F0, 0x1C4F68, 0x6301B8,
	0x1C86B8, 0x1C8A04, 0x1C8CD0, 0x1C8CD2, 0x1C8CE4, 0x1C89B6, 0x3C0258,
	0x1C757E, 0x1C786A, 0x1C7CE2, 0x1C7CE4, 0x1C7CF6, 0x1C781E, 0x630000,
	0x1C7F42, 0x1C8226, 0x1C8354, 0x1C8356, 0x1C8368, 0x1C81D8, 0x3C01B8,
	0x1C6722, 0x1C6A02, 0x1C6B6A, 0x1C6B6C, 0x1C6B7E, 0x1C69B4, 0x3C01B8,
	0x1C6D0A, 0x1C7044, 0x1C71CA, 0x1C71CC, 0x1C71DE, 0x1C6FF6, 0x3C0000,
	0x1C8DD8, 0x1C903E, 0x1C6B6A, 0x1C6B6C, 0x1C6B7E, 0x1C69B4, 0x3C0000,
	0x1C9204, 0x1C94C2, 0x1C9542, 0x1C9544, 0x1C9556, 0x1C9474, 0x630000,
};

const int Stage5MotionTbl[]= { //第五关 智破八阵图
	0x1BD6CE, 0x1BD70C, 0x1BD724, 0x1BD73C, 0x1BD762, 0x1BD6E6, 0x630000,
	0x1BC8D8, 0x1BD104, 0x1BD5B4, 0x1BD5D8, 0x1BD5EA, 0x1BCF70, 0x630000,
	0x1C1AEC, 0x1C2236, 0x1C25CA, 0x1C25CC, 0x1C2676, 0x1C1EE6, 0x630000,
	0x1BFED4, 0x1C01FA, 0x1C036C, 0x1C0390, 0x1C03A2, 0x1C01AC, 0x320000,
	0x1BE45C, 0x1BE79E, 0x1BEA26, 0x1BEA3C, 0x1BEA4E, 0x1BE752, 0x630000,
	0x1C08BC, 0x1C0BF8, 0x1C0F6A, 0x1C0FC0, 0x1C114C, 0x1C0BAC, 0x630000,
	0x1BDE4E, 0x1BE194, 0x1BE29C, 0x1BE29E, 0x1BE2B0, 0x1BE0A8, 0x2D01E0,
	0x1BBF4A, 0x1BC368, 0x1BC4D8, 0x1BC4DA, 0x1BC4EC, 0x1BC1A4, 0x2D01B8,
	0x1BD938, 0x1BDD14, 0x1BDE20, 0x1BDE22, 0x1BDE34, 0x1BDC28, 0x2D01E0,
	0x1C141C, 0x1C1572, 0x1BD5B4, 0x1BD5D8, 0x1C1590, 0x1C141A, 0x630000,
	0x1C16BE, 0x1C186C, 0x1BEA26, 0x1BEA3C, 0x1C187C, 0x1BE752, 0x630000,
	0x1C331A, 0x1C35D8, 0x1C3658, 0x1C365A, 0x1C366C, 0x1C358C, 0x630000,
};

const int Stage6MotionTbl[]= { //第六关 血战夺荆州
	0x1D8E10, 0x1D9330, 0x1D98E2, 0x1D98E4, 0x1D995A, 0x1D9262, 0x630000,
	0x1D9A40, 0x1D9CF6, 0x1D9E08, 0x1D9E0A, 0x1D9E1C, 0x1D9CA8, 0x2D01E0,
	0x1D9F00, 0x1DA1B4, 0x1DA2F6, 0x1DA2F8, 0x1DA30A, 0x1DA166, 0x2D01E0,
	0x1D6910, 0x1D6F5A, 0x1D754E, 0x1D7550, 0x1D7562, 0x1D6C30, 0x630000,
	0x1D82E2, 0x1D87BA, 0x1D8A2C, 0x1D8A2E, 0x1D8AB8, 0x1D85D0, 0x630000,
	0x1DADCA, 0x1DB652, 0x1DBD10, 0x1DBD12, 0x1DBD7C, 0x1DB1F0, 0x630000,
	0x1D504C, 0x1D5376, 0x1D5492, 0x1D5494, 0x1D54A6, 0x1D5328, 0x2D01F4,
	0x1D55B4, 0x1D5C7C, 0x1D611C, 0x1D611E, 0x1D6130, 0x1D59CE, 0x630000,
	0x1DC310, 0x1DC4A2, 0x1D98E2, 0x1D98E4, 0x1DC4C0, 0x1DC446, 0x630000,
	0x1D76D2, 0x1D78F0, 0x1D754E, 0x1D7550, 0x1D790E, 0x1D7894, 0x630000,
	0x1DBEC8, 0x1DC1C2, 0x1DBD10, 0x1DBD12, 0x1DC1E0, 0x1DC166, 0x630000,
	0x1DC6E4, 0x1DC99E, 0x1DCA1E, 0x1DCA20, 0x1DCA32, 0x1DC950, 0x630000,
};

const int Stage7MotionTbl[]= { //第七关 三国归一统
	0x1CADEA, 0x1CB4E2, 0x1CB916, 0x1CB918, 0x1CB982, 0x1CB404, 0x630000,
	0x1CE412, 0x1CEC20, 0x1CF3A0, 0x1CF3A2, 0x1CF3B4, 0x1CEA98, 0x630000,
	0x1CC726, 0x1CCCF4, 0x1CD5E2, 0x1CD5E4, 0x1CD5F6, 0x1CCA9E, 0x630000,
	0x1D3E2C, 0x1D43C4, 0x1D48E6, 0x1D48E8, 0x1D48FA, 0x1D420E, 0x630000,
	0x1D0C58, 0x1D13CA, 0x1D1E86, 0x1D1E88, 0x1D1E9A, 0x1D11B0, 0x630000,
	0x1CFB68, 0x1D0280, 0x1D08FC, 0x1D08FE, 0x1D0910, 0x1D00B0, 0x630000,
	0x1D1FA4, 0x1D2292, 0x1D2416, 0x1D2418, 0x1D242A, 0x1D2244, 0x2D0258,
	0x1D2504, 0x1D27CA, 0x1D28CC, 0x1D28CE, 0x1D28E0, 0x1D277C, 0x2D021C,
	0x1C96B8, 0x1C9AC0, 0x1C9BF8, 0x1C9BFA, 0x1C9C0C, 0x1C9A12, 0x2D01E0,
	0x1C9E8C, 0x1CA150, 0x1CA33E, 0x1CA340, 0x1CA352, 0x1CA10A, 0x2D01B8,
	0x1D2B0C, 0x1D3100, 0x1D32A6, 0x1D32A8, 0x1D32BA, 0x1D2DD2, 0x2D01E0,
	0x1CD636, 0x1CD9B2, 0x1CD5E2, 0x1CD5E4, 0x1CD5F6, 0x1CD964, 0x2D0000,
	0x1D4AE8, 0x1D4DA8, 0x1D4E28, 0x1D4E2A, 0x1D4E3C, 0x1D4D5A, 0x630000,
};

const int Stage8MotionTbl[]= { //第八关 武将对战魏延 曹丕
	0x1F58AA, 0x1F5B84, 0x1F5C02, 0x1F5C04, 0x1F5C16, 0x1F5B36, 0x630000,
	0x1F58AA, 0x1F5B84, 0x1F5C02, 0x1F5C04, 0x1F5C16, 0x1F5B36, 0x630000,
};

const int Stage9MotionTbl[]= { //第九关 武将对战曹操
	0x1F5F64, 0x1F622C, 0x1F6298, 0x1F629A, 0x1F62AC, 0x1F61DE, 0x630000,
};

const int Stage9MotionTbl[]= { //第十关 练习模式
	0x1F4C36, 0x1F4F72, 0x1F543C, 0x1F543E, 0x1F546C, 0x1F4F24, 0x630000，
};


int ST10F9(int Motion) {
	return (Stage10MotionTbl[Motion * 7 + 6] &0xFFFF);
}
int ST10F8(int Motion) {
	return (Stage10MotionTbl[Motion * 7 + 6] >>16);
}
void ST10F7(int Motion,int param_2) {
	FUNC32(Stage10MotionTbl[Motion * 7 + 5])(param_2);
	return;
}
void ST10F6(int Motion,int param_2) {
	FUNC32(Stage10MotionTbl[Motion * 7 + 4])(param_2);
	return;
}
void ST10F5(int Motion,int param_2) {
	FUNC32(Stage10MotionTbl[Motion * 7 + 3])(param_2);
	return;
}
void ST10F4(int Motion) {
	FUNC32(Stage10MotionTbl[Motion * 7 + 2])();
	return;
}
void ST10F3(int Motion) {
	FUNC32(Stage10MotionTbl[Motion * 7 + 1])();
	return;
}
void ST10F2(int Motion) {
	FUNC32(Stage10MotionTbl[Motion * 7])();
	return;
}
void ST10F1() {
	return;
}




int ST9F9(int Motion) {
	return (Stage9MotionTbl[Motion * 7 + 6] &0xFFFF);
}
int ST9F8(int Motion) {
	return (Stage9MotionTbl[Motion * 7 + 6] >>16);
}
void ST9F7(int Motion,int param_2) {
	FUNC32(Stage9MotionTbl[Motion * 7 + 5])(param_2);
	return;
}
void ST9F6(int Motion,int param_2) {
	FUNC32(Stage9MotionTbl[Motion * 7 + 4])(param_2);
	return;
}
void ST9F5(int Motion,int param_2) {
	FUNC32(Stage9MotionTbl[Motion * 7 + 3])(param_2);
	return;
}
void ST9F4(int Motion) {
	FUNC32(Stage9MotionTbl[Motion * 7 + 2])();
	return;
}
void ST9F3(int Motion) {
	FUNC32(Stage9MotionTbl[Motion * 7 + 1])();
	return;
}
void ST9F2(int Motion) {
	FUNC32(Stage9MotionTbl[Motion * 7])();
	return;
}
void ST9F1() {
	return;
}



int ST8F9(int Motion) {
	return (Stage8MotionTbl[Motion * 7 + 6] &0xFFFF);
}
int ST8F8(int Motion) {
	return (Stage8MotionTbl[Motion * 7 + 6] >>16);
}
void ST8F7(int Motion,int param_2) {
	FUNC32(Stage8MotionTbl[Motion * 7 + 5])(param_2);
	return;
}
void ST8F6(int Motion,int param_2) {
	FUNC32(Stage8MotionTbl[Motion * 7 + 4])(param_2);
	return;
}
void ST8F5(int Motion,int param_2) {
	FUNC32(Stage8MotionTbl[Motion * 7 + 3])(param_2);
	return;
}
void ST8F4(int Motion) {
	FUNC32(Stage8MotionTbl[Motion * 7 + 2])();
	return;
}
void ST8F3(int Motion) {
	FUNC32(Stage8MotionTbl[Motion * 7 + 1])();
	return;
}
void ST8F2(int Motion) {
	FUNC32(Stage8MotionTbl[Motion * 7])();
	return;
}
void ST8F1() {
	return;
}





int ST7F9(int Motion) {
	return (Stage7MotionTbl[Motion * 7 + 6] &0xFFFF);
}
int ST7F8(int Motion) {
	return (Stage7MotionTbl[Motion * 7 + 6] >>16);
}
void ST7F7(int Motion,int param_2) {
	FUNC32(Stage7MotionTbl[Motion * 7 + 5])(param_2);
	return;
}
void ST7F6(int Motion,int param_2) {
	FUNC32(Stage7MotionTbl[Motion * 7 + 4])(param_2);
	return;
}
void ST7F5(int Motion,int param_2) {
	FUNC32(Stage7MotionTbl[Motion * 7 + 3])(param_2);
	return;
}
void ST7F4(int Motion) {
	FUNC32(Stage7MotionTbl[Motion * 7 + 2])();
	return;
}
void ST7F3(int Motion) {
	FUNC32(Stage7MotionTbl[Motion * 7 + 1])();
	return;
}
void ST7F2(int Motion) {
	FUNC32(Stage7MotionTbl[Motion * 7])();
	return;
}
void ST7F1() {
	DU8(0x81b702) = 0;
	DU32(0x81bcdc) = 0xf0;
	DU8(0x81bd94) = 0xff;
	DU8(0x81bdbc) = 0xff;
	return;
}


int ST6F9(int Motion) {
	return (Stage6MotionTbl[Motion * 7 + 6] &0xFFFF);
}
int ST6F8(int Motion) {
	return (Stage6MotionTbl[Motion * 7 + 6] >>16);
}
void ST6F7(int Motion,int param_2) {
	FUNC32(Stage6MotionTbl[Motion * 7 + 5])(param_2);
	return;
}
void ST6F6(int Motion,int param_2) {
	FUNC32(Stage6MotionTbl[Motion * 7 + 4])(param_2);
	return;
}
void ST6F5(int Motion,int param_2) {
	FUNC32(Stage6MotionTbl[Motion * 7 + 3])(param_2);
	return;
}
void ST6F4(int Motion) {
	FUNC32(Stage6MotionTbl[Motion * 7 + 2])();
	return;
}
void ST6F3(int Motion) {
	FUNC32(Stage6MotionTbl[Motion * 7 + 1])();
	return;
}
void ST6F2(int Motion) {
	FUNC32(Stage6MotionTbl[Motion * 7])();
	return;
}
void ST6F1() {
	DU8(0x81bdbc) = 0xff;
	return;
}



int ST5F9(int Motion) {
	return (Stage5MotionTbl[Motion * 7 + 6] &0xFFFF);
}
int ST5F8(int Motion) {
	return (Stage5MotionTbl[Motion * 7 + 6] >>16);
}
void ST5F7(int Motion,int param_2) {
	FUNC32(Stage5MotionTbl[Motion * 7 + 5])(param_2);
	return;
}
void ST5F6(int Motion,int param_2) {
	FUNC32(Stage5MotionTbl[Motion * 7 + 4])(param_2);
	return;
}
void ST5F5(int Motion,int param_2) {
	FUNC32(Stage5MotionTbl[Motion * 7 + 3])(param_2);
	return;
}
void ST5F4(int Motion) {
	FUNC32(Stage5MotionTbl[Motion * 7 + 2])();
	return;
}
void ST5F3(int Motion) {
	FUNC32(Stage5MotionTbl[Motion * 7 + 1])();
	return;
}
void ST5F2(int Motion) {
	FUNC32(Stage5MotionTbl[Motion * 7])();
	return;
}
void ST5F1() {
	DU8(0x81bdbc) = 0xff;
	DU8(0x81bd20) = 0;
	DU8(0x81bd21) = 0;
	DU32(0x81bd70) = 0xb4;
	DU8(0x81bd6d) = 0;
	DU8(0x81bd6e) = 0;
	return;
}







int ST4F9(int Motion) {
	return (Stage4MotionTbl[Motion * 7 + 6] &0xFFFF);
}
int ST4F8(int Motion) {
	return (Stage4MotionTbl[Motion * 7 + 6] >>16);
}
void ST4F7(int Motion,int param_2) {
	FUNC32(Stage4MotionTbl[Motion * 7 + 5])(param_2);
	return;
}
void ST4F6(int Motion,int param_2) {
	FUNC32(Stage4MotionTbl[Motion * 7 + 4])(param_2);
	return;
}
void ST4F5(int Motion,int param_2) {
	FUNC32(Stage4MotionTbl[Motion * 7 + 3])(param_2);
	return;
}
void ST4F4(int Motion) {
	FUNC32(Stage4MotionTbl[Motion * 7 + 2])();
	return;
}
void ST4F3(int Motion) {
	FUNC32(Stage4MotionTbl[Motion * 7 + 1])();
	return;
}
void ST4F2(int Motion) {
	FUNC32(Stage4MotionTbl[Motion * 7])();
	return;
}
void ST4F1() {
	return;
}





int ST3F9(int Motion) {
	return (Stage3MotionTbl[Motion * 7 + 6] &0xFFFF);
}
int ST3F8(int Motion) {
	return (Stage3MotionTbl[Motion * 7 + 6] >>16);
}
void ST3F7(int Motion,int param_2) {
	FUNC32(Stage3MotionTbl[Motion * 7 + 5])(param_2);
	return;
}
void ST3F6(int Motion,int param_2) {
	FUNC32(Stage3MotionTbl[Motion * 7 + 4])(param_2);
	return;
}
void ST3F5(int Motion,int param_2) {
	FUNC32(Stage3MotionTbl[Motion * 7 + 3])(param_2);
	return;
}
void ST3F4(int Motion) {
	FUNC32(Stage3MotionTbl[Motion * 7 + 2])();
	return;
}
void ST3F3(int Motion) {
	FUNC32(Stage3MotionTbl[Motion * 7 + 1])();
	return;
}
void ST3F2(int Motion) {
	FUNC32(Stage3MotionTbl[Motion * 7])();
	return;
}
void ST3F1() {
	DU8(0x81b44e) = 0;
	return;
}

int ST2F9(int Motion) {
	return (Stage2MotionTbl[Motion * 7 + 6] &0xFFFF);
}
int ST2F8(int Motion) {
	return (Stage2MotionTbl[Motion * 7 + 6] >>16);
}
void ST2F7(int Motion,int param_2) {
	FUNC32(Stage2MotionTbl[Motion * 7 + 5])(param_2);
	return;
}
void ST2F6(int Motion,int param_2) {
	FUNC32(Stage2MotionTbl[Motion * 7 + 4])(param_2);
	return;
}
void ST2F5(int Motion,int param_2) {
	FUNC32(Stage2MotionTbl[Motion * 7 + 3])(param_2);
	return;
}
void ST2F4(int Motion) {
	FUNC32(Stage2MotionTbl[Motion * 7 + 2])();
	return;
}
void ST2F3(int Motion) {
	FUNC32(Stage2MotionTbl[Motion * 7 + 1])();
	return;
}
void ST2F2(int Motion) {
	FUNC32(Stage2MotionTbl[Motion * 7])();
	return;
}
void ST2F1() {
	DU8(0x81ba04) = 3;
	DU8(0x81b9dc) = 4;
	return;
}

int ST1F9(int Motion) {
	return (Stage1MotionTbl[Motion * 7 + 6] &0xFFFF);
}
int ST1F8(int Motion) {
	return (Stage1MotionTbl[Motion * 7 + 6] >>16);
}
void ST1F7(int Motion,int param_2) {
	FUNC32(Stage1MotionTbl[Motion * 7 + 5])(param_2);
	return;
}
void ST1F6(int Motion,int param_2) {
	FUNC32(Stage1MotionTbl[Motion * 7 + 4])(param_2);
	return;
}
void ST1F5(int Motion,int param_2) {
	FUNC32(Stage1MotionTbl[Motion * 7 + 3])(param_2);
	return;
}
void ST1F4(int Motion) {
	FUNC32(Stage1MotionTbl[Motion * 7 + 2])();
	return;
}
void ST1F3(int Motion) {
	FUNC32(Stage1MotionTbl[Motion * 7 + 1])();
	return;
}
void ST1F2(int Motion) {
	FUNC32(Stage1MotionTbl[Motion * 7])();
	return;
}
void ST1F1() {
	DU8(0x81b900) = 0;
	DU8(0x81b90a) = 0;
	return;
}

const int StageTbl[]= { //0x339CEA 关卡总表
	sizeof(Stage1MotionTbl)/28, (int)&ST1F1, (int)&ST1F2, (int)&ST1F3, (int)&ST1F4, (int)&ST1F5, (int)&ST1F6, (int)&ST1F7, 1, (int)&ST1F8, (int)&ST1F9,//第一关 截江救阿斗
	sizeof(Stage2MotionTbl)/28, (int)&ST2F1, (int)&ST2F2, (int)&ST2F3, (int)&ST2F4, (int)&ST2F5, (int)&ST2F6, (int)&ST2F7, 1, (int)&ST2F8, (int)&ST2F9,//第二关 定军斩夏侯
	sizeof(Stage3MotionTbl)/28, (int)&ST3F1, (int)&ST3F2, (int)&ST3F3, (int)&ST3F4, (int)&ST3F5, (int)&ST3F6, (int)&ST3F7, 1, (int)&ST3F8, (int)&ST3F9,//第三关 威震汉中池
	sizeof(Stage4MotionTbl)/28, (int)&ST4F1, (int)&ST4F2, (int)&ST4F3, (int)&ST4F4, (int)&ST4F5, (int)&ST4F6, (int)&ST4F7, 1, (int)&ST4F8, (int)&ST4F9,//第四关 大意失荆州
	sizeof(Stage5MotionTbl)/28, (int)&ST5F1, (int)&ST5F2, (int)&ST5F3, (int)&ST5F4, (int)&ST5F5, (int)&ST5F6, (int)&ST5F7, 1, (int)&ST5F8, (int)&ST5F9,//第五关 智破八阵图
	sizeof(Stage6MotionTbl)/28, (int)&ST6F1, (int)&ST6F2, (int)&ST6F3, (int)&ST6F4, (int)&ST6F5, (int)&ST6F6, (int)&ST6F7, 1, (int)&ST6F8, (int)&ST6F9,//第六关 血战夺荆州
	sizeof(Stage7MotionTbl)/28, (int)&ST7F1, (int)&ST7F2, (int)&ST7F3, (int)&ST7F4, (int)&ST7F5, (int)&ST7F6, (int)&ST7F7, 1, (int)&ST7F8, (int)&ST7F9,//第七关 三国归一统
	sizeof(Stage8MotionTbl)/28, (int)&ST8F1, (int)&ST8F2, (int)&ST8F3, (int)&ST8F4, (int)&ST8F5, (int)&ST8F6, (int)&ST8F7, 1, (int)&ST8F8, (int)&ST8F9,//武将对战用魏延
	sizeof(Stage9MotionTbl)/28, (int)&ST9F1, (int)&ST9F2, (int)&ST9F3, (int)&ST9F4, (int)&ST9F5, (int)&ST9F6, (int)&ST9F7, 1, (int)&ST9F8, (int)&ST9F9,//武将对战用曹操
	sizeof(Stage10MotionTbl)/28, (int)&ST10F1, (int)&ST10F2, (int)&ST10F3, (int)&ST10F4, (int)&ST10F5, (int)&ST10F6, (int)&ST10F7, 1, (int)&ST10F8, (int)&ST10F9,//练习模式
};