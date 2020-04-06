typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned int    dword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned short    ushort;
typedef unsigned short    word;
typedef struct RoroMem RoroMem, *PRoroMem;

typedef struct Role_Struc Role_Struc, *PRole_Struc;

typedef uchar BYTE;

typedef ulong LONG;

typedef ushort WORD;

typedef struct KovInputElem KovInputElem, *PKovInputElem;

typedef struct CollDataElem CollDataElem, *PCollDataElem;

typedef struct InputInsElem InputInsElem, *PInputInsElem;


struct BG_ImgList {
	u16 width;//图片宽
	u16 height;//图片高
	u32 TilesPtr;//拼图数据指针
	u32 DisplayMode;//图片显示模式 翻转:0x40
	u32 Fix00;
};

//图片包结构体
struct BG_ImgPack {
	u32 ImgPal;//图片包整体色盘,一般为0
	u32 ImgListPtr;//图片列表指针
	u16 ImgCnt;//图片数量 sizeof(ImgListPtr/10)
};

struct BG_ImgUseInfo {
	s16 x;//图片坐标
	s16 y;//图片坐标
	u32 IMG;//图片包指针
	u8 N;//图片ID
	u8 Fix_09;
	u16 Fix_0a;
	u16 TileBase;//Tile起始编号
	u16 Fix_0e;
	u32 PalPtr;//色盘指针
	u32 Fix_14;
	u32 Fix_18;
};


struct TileInfo {
	char state;
	char row;
	char field_0x2;
	char unk;
	short change;
	short *tileptr;
};

struct BossInfo {
	int RoroStatus;
	int RoroUseID;
	int EnemyID;
	int HeadOBJPtr[4];
	int NameOBJPtr[4];
	int DisplayID;
	int DisplayID2;
	int Lifes;
	int HPBarUse;
	int HPNowpos;
	short HPChangeVal;
	int HPTilesPtr;
	int Bit;
	short HPTiles[112];
};






//BitMapLayer 1
//0x81284e 
//4 BitMapDataPtr






//OBJMEM 0x80e322 156 * 80

//rolemem 0x8114f4 438*4

//PlayerMem 0x811bcc 732*4  +0x0A=Score  +0x2ba=level
//PlayerRoleMem 0x8114f4 438*4
//BossMem 0x813544 706*2
//EnemyMem 0x80cf1e 438*8


struct RoroMem {//0x80cf1e 438*2
    undefined field_0x0;
    undefined field_0x1;
    short LiveTime;
    char Active;
    char FrameDelay;
    char unknow6;
    char field_0x7;
    short x;
    short y;
    short Pic_x;
    short Pic_y;
    short field_0x10;
    short field_0x12;
    short x2;
    short y2;
    short _p5;
    char Calc_x;
    char Calc_y;
    char unknow28;
    char ColorNum;
    int ScriptOffset;
    undefined field_0x22;
    undefined field_0x23;
    undefined field_0x24;
    undefined field_0x25;
    int Orgin_Array;
    int Coll_Index_Array;
    undefined field_0x2e;
    undefined field_0x2f;
    undefined field_0x30;
    undefined field_0x31;
    undefined field_0x32;
    undefined field_0x33;
    short ScriptCnt;
    short field_0x36;
    int FuncRet5;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    undefined field_0x40;
    undefined field_0x41;
    undefined field_0x42;
    undefined field_0x43;
    undefined field_0x44;
    undefined field_0x45;
    char ActType;
    char ActID;
    struct Role_Struc * RoroRom;
    struct Role_Struc * RoroRom2;
    char * Pic_Array;
    char PalID;
    char ScriptPalID;
    int Pal;
    int Base_Index;
    ushort HP; /* Created by retype action */
    short DisplayUse;
    undefined field_0x62;
    undefined field_0x63;
    undefined field_0x64;
    undefined field_0x65;
    undefined field_0x66;
    undefined field_0x67;
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    undefined field_0x70;
    undefined field_0x71;
    undefined field_0x72;
    undefined field_0x73;
    undefined field_0x74;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;
    undefined field_0x78;
    undefined field_0x79;
    undefined field_0x7a;
    undefined field_0x7b;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    undefined field_0x80;
    undefined field_0x81;
    undefined field_0x82;
    undefined field_0x83;
    undefined field_0x84;
    undefined field_0x85;
    undefined field_0x86;
    undefined field_0x87;
    undefined field_0x88;
    undefined field_0x89;
    undefined field_0x8a;
    undefined field_0x8b;
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    undefined field_0x90;
    undefined field_0x91;
    undefined field_0x92;
    undefined field_0x93;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
    undefined field_0x98;
    undefined field_0x99;
    undefined field_0x9a;
    undefined field_0x9b;
    undefined field_0x9c;
    undefined field_0x9d;
    undefined field_0x9e;
    undefined field_0x9f;
    undefined field_0xa0;
    undefined field_0xa1;
    undefined field_0xa2;
    undefined field_0xa3;
    undefined field_0xa4;
    undefined field_0xa5;
    undefined field_0xa6;
    undefined field_0xa7;
    undefined field_0xa8;
    undefined field_0xa9;
    undefined field_0xaa;
    undefined field_0xab;
    undefined field_0xac;
    undefined field_0xad;
    undefined field_0xae;
    undefined field_0xaf;
    undefined field_0xb0;
    undefined field_0xb1;
    undefined field_0xb2;
    undefined field_0xb3;
    undefined field_0xb4;
    undefined field_0xb5;
    undefined field_0xb6;
    undefined field_0xb7;
    undefined field_0xb8;
    undefined field_0xb9;
    undefined field_0xba;
    undefined field_0xbb;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    undefined field_0xc0;
    undefined field_0xc1;
    undefined field_0xc2;
    undefined field_0xc3;
    undefined field_0xc4;
    undefined field_0xc5;
    undefined field_0xc6;
    undefined field_0xc7;
    undefined field_0xc8;
    undefined field_0xc9;
    undefined field_0xca;
    undefined field_0xcb;
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
    undefined field_0xd0;
    undefined field_0xd1;
    char Zmode;
    undefined field_0xd3;
    char Color;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    undefined field_0xd8;
    undefined field_0xd9;
    undefined field_0xda;
    undefined field_0xdb;
    undefined field_0xdc;
    undefined field_0xdd;
    int PlayerMemPtr;
    undefined field_0xe2;
    undefined field_0xe3;
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    undefined field_0xe8;
    undefined field_0xe9;
    undefined field_0xea;
    undefined field_0xeb;
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    undefined field_0xf0;
    undefined field_0xf1;
    undefined field_0xf2;
    undefined field_0xf3;
    undefined field_0xf4;
    undefined field_0xf5;
    undefined field_0xf6;
    undefined field_0xf7;
    undefined field_0xf8;
    undefined field_0xf9;
    undefined field_0xfa;
    undefined field_0xfb;
    undefined field_0xfc;
    undefined field_0xfd;
    short SoundOffset;
    char Script_z;
    char RoroUseID; /* Created by retype action */
    undefined field_0x102;
    char PalFadeID;
    undefined field_0x104;
    undefined field_0x105;
    undefined field_0x106;
    undefined field_0x107;
    undefined field_0x108;
    char ScriptTurnCnt;
    short ScriptTurnOffset;
    undefined field_0x10c;
    undefined field_0x10d;
    char ZoomMin;
    char ZoomMax;
    undefined field_0x110;
    undefined field_0x111;
    int ItemPtr;
    undefined field_0x116;
    undefined field_0x117;
    undefined field_0x118;
    undefined field_0x119;
    int field_0x11a;
    undefined field_0x11e;
    undefined field_0x11f;
    undefined field_0x120;
    undefined field_0x121;
    undefined field_0x122;
    undefined field_0x123;
    undefined field_0x124;
    undefined field_0x125;
    undefined field_0x126;
    undefined field_0x127;
    undefined field_0x128;
    undefined field_0x129;
    undefined field_0x12a;
    undefined field_0x12b;
    undefined field_0x12c;
    undefined field_0x12d;
    undefined field_0x12e;
    undefined field_0x12f;
    undefined field_0x130;
    undefined field_0x131;
    undefined field_0x132;
    undefined field_0x133;
    undefined field_0x134;
    undefined field_0x135;
    undefined field_0x136;
    undefined field_0x137;
    short Fix_z;
    undefined field_0x13a;
    char PowerCnt;
    short PowerTime;
    undefined field_0x13e;
    undefined field_0x13f;
    char isUnmatched;
    undefined field_0x141;
    undefined field_0x142;
    undefined field_0x143;
    undefined field_0x144;
    undefined field_0x145;
    undefined field_0x146;
    undefined field_0x147;
    undefined field_0x148;
    undefined field_0x149;
    undefined field_0x14a;
    undefined field_0x14b;
    short field_0x14c;
    int unknow_334;
    undefined field_0x152;
    undefined field_0x153;
    undefined field_0x154;
    undefined field_0x155;
    undefined field_0x156;
    undefined field_0x157;
    undefined field_0x158;
    undefined field_0x159;
    undefined field_0x15a;
    undefined field_0x15b;
    undefined field_0x15c;
    undefined field_0x15d;
    undefined field_0x15e;
    undefined field_0x15f;
    undefined field_0x160;
    undefined field_0x161;
    undefined field_0x162;
    undefined field_0x163;
    undefined field_0x164;
    undefined field_0x165;
    undefined field_0x166;
    char Frame;
    undefined field_0x168;
    undefined field_0x169;
    undefined field_0x16a;
    undefined field_0x16b;
    undefined field_0x16c;
    undefined field_0x16d;
    undefined field_0x16e;
    undefined field_0x16f;
    undefined field_0x170;
    undefined field_0x171;
    undefined field_0x172;
    undefined field_0x173;
    undefined field_0x174;
    undefined field_0x175;
    undefined field_0x176;
    char Hit;
    undefined field_0x178;
    undefined field_0x179;
    undefined field_0x17a;
    undefined field_0x17b;
    undefined field_0x17c;
    undefined field_0x17d;
    undefined UseItem;
    undefined field_0x17f;
    undefined field_0x180;
    undefined field_0x181;
    undefined field_0x182;
    undefined field_0x183;
    undefined field_0x184;
    undefined field_0x185;
    undefined field_0x186;
    undefined field_0x187;
    undefined field_0x188;
    undefined field_0x189;
    undefined field_0x18a;
    undefined field_0x18b;
    undefined field_0x18c;
    undefined field_0x18d;
    undefined field_0x18e;
    undefined field_0x18f;
    undefined field_0x190;
    undefined field_0x191;
    undefined field_0x192;
    undefined field_0x193;
    undefined field_0x194;
    undefined field_0x195;
    undefined field_0x196;
    undefined field_0x197;
    undefined field_0x198;
    undefined field_0x199;
    char AAA;
    undefined field_0x19b;
    undefined field_0x19c;
    undefined field_0x19d;
    undefined field_0x19e;
    undefined field_0x19f;
    undefined field_0x1a0;
    undefined field_0x1a1;
    undefined field_0x1a2;
    undefined field_0x1a3;
    undefined field_0x1a4;
    undefined field_0x1a5;
    undefined field_0x1a6;
    undefined field_0x1a7;
    undefined field_0x1a8;
    undefined field_0x1a9;
    undefined field_0x1aa;
    undefined field_0x1ab;
    undefined field_0x1ac;
    undefined field_0x1ad;
    undefined field_0x1ae;
    undefined field_0x1af;
    undefined field_0x1b0;
    undefined field_0x1b1;
    undefined field_0x1b2;
    undefined field_0x1b3;
    undefined field_0x1b4;
    undefined field_0x1b5;
};

struct InputInsElem {
    ushort KeyInput;
    ushort Unknown;
    ushort Option;
};

struct Role_Struc {
    BYTE FlagRole;
    BYTE RoleId;
    BYTE RoleAttr;
    BYTE Fix20;
    BYTE Fix40;
    BYTE Fix00;
    int FuncRet1;
    LONG FuncRet2;
    LONG FuncRet3;
    LONG FuncRet4;
    BYTE * pAction;
    WORD * SpCaning_Index;
    LONG FuncRet5;
    BYTE * Damage3_Tbl;
    WORD * Damage3_Exp_Tbl;
    BYTE * Damage6_Tbl;
    WORD * Damage6_Exp_Tbl;
    WORD * * Pal_Array;
    struct KovInputElem * input;
    void * * Pic_Array;
    WORD * Origin_Array;
    WORD * Coll_Index_Array;
    struct CollDataElem * Coll_Data_Array;
    LONG Base_Index;
    WORD HP;
    WORD Unknow_off_50;
    WORD Unknow_off_52;
    WORD Unknow_off_54;
    WORD Unknow_off_56;
    WORD Unknow_off_58;
    WORD Unknow_off_5A;
    WORD Unknow_off_5C;
    WORD Unknow_off_5E;
    WORD CaningSound3;
    WORD CaningSound2;
    WORD CaningSound1;
    WORD CaningSound0;
    BYTE * Damage3_Ratio_Tbl;
    BYTE * Damage6_Ratio_Tbl;
    WORD Unknow_off_70;
    LONG AI_Assign;
    WORD Unknow_off_76;
    LONG New_Pic_Array;
    LONG Func_List;
    BYTE * * Cancel_Action_Array;
    LONG Unknow_off_84;
    LONG AI_Relate;
    LONG Unknow_off_8C;
    LONG Unknow_off_90;
};

struct CollDataElem {
    BYTE yAxis;
    BYTE yHeight;
    BYTE collAttr1;
    BYTE zHeight1;
    WORD xAxis;
    BYTE collAttr2;
    BYTE zHeight2;
    WORD Width;
};

struct KovInputElem {
    struct InputInsElem * Ins;
    ushort FixVal32;
    ushort ActionId;
    ushort Option;
};

