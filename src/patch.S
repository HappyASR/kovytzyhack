
#include "xxpacth_include.h"
.section .patch,"ax"

XXEXPORT_START(dumpy)

.file "src/patch/hook_MainInit.S"
.line 0
//warning界面函数

.file "src/patch/patch_checksum.S"
.line 0
//去掉游戏中的暗桩

.file "src/patch/patch_hook.S"
.line 0
//测试函数用
//$$PATCH16JMP16(0x952ca,Hook)
.file "src/patch/patch_scoretable.S"
.line 0
//外置A面人物分数表

.file "src/patch/patch_stagetable.S"
.line 0

//关卡总表PATCH

.file "src/patch/patch_checksum.S"
.line 1
	XXPATCH16(0x61e7c) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 2
	XXPATCH16(0x6221a) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 3
	XXPATCH16(0x626c4) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 4
	XXPATCH16(0x62926) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 5
	XXPATCH16(0x62b8c) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 6
	XXPATCH16(0x62d08) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 7
	XXPATCH16(0x62f34) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 8
	XXPATCH16(0x63084) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 9
	XXPATCH16(0x63150) .word 0x7200;

.file "src/patch/patch_scoretable.S"
.line 3
	XXPATCH16PTR16(0x663ce,ScoreTblB)
.file "src/patch/patch_scoretable.S"
.line 1
	XXPATCH16PTR16(0x66400,ScoreTblA)
//外置B面人物分数表

.file "src/patch/patch_checksum.S"
.line 42
	XXPATCH16(0x68bfc) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 10
	XXPATCH16(0x6ca36) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 11
	XXPATCH16(0x85134) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 12
	XXPATCH16(0x85c16) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 13
	XXPATCH16(0x8d116) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 14
	XXPATCH16(0x91c04) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 15
	XXPATCH16(0x973d2) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 16
	XXPATCH16(0x98744) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 17
	XXPATCH16(0x987b2) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 18
	XXPATCH16(0x98824) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 19
	XXPATCH16(0x98c4a) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 20
	XXPATCH16(0x98fa8) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 21
	XXPATCH16(0x9924e) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 22
	XXPATCH16(0x9bddc) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 23
	XXPATCH16(0x9cc4c) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 24
	XXPATCH16(0x9d804) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 25
	XXPATCH16(0x9d9bc) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 26
	XXPATCH16(0x9eeaa) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 27
	XXPATCH16(0x9fc1e) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 28
	XXPATCH16(0xa0698) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 29
	XXPATCH16(0xa0852) .word 0x7200;

.file "src/patch/hook_MainInit.S"
.line 1
	XXPATCH16JMP16(0xa0f12,PageMainMenu)

//titlepage界面函数
//$$PATCH16JMP16(0x98f36,TitlePage)
.file "src/patch/patch_checksum.S"
.line 30
	XXPATCH16(0xa0f62) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 31
	XXPATCH16(0xa4d80) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 32
	XXPATCH16(0xa543e) .word 0x7200;

.file "src/patch/patch_stagetable.S"
.line 2
	XXPATCH16PTR32(0xa58b6,StageTbl)

.file "src/patch/patch_stagetable.S"
.line 3
	XXPATCH16PTR32(0xa5be0,StageTbl)

.file "src/patch/patch_stagetable.S"
.line 4
	XXPATCH16PTR32(0xa62da,StageTbl)

.file "src/patch/patch_stagetable.S"
.line 5
	XXPATCH16PTR32(0xa65e2,StageTbl+4)

.file "src/patch/patch_stagetable.S"
.line 6
	XXPATCH16PTR32(0xa6600,StageTbl+4)

.file "src/patch/patch_stagetable.S"
.line 7
	XXPATCH16PTR32(0xa6994,StageTbl+28)

.file "src/patch/patch_checksum.S"
.line 33
	XXPATCH16(0xb2704) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 34
	XXPATCH16(0xb3090) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 35
	XXPATCH16(0xb3682) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 36
	XXPATCH16(0xb3d22) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 37
	XXPATCH16(0xb40b8) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 38
	XXPATCH16(0xb63e0) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 39
	XXPATCH16(0xb6730) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 40
	XXPATCH16(0xb77cc) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 41
	XXPATCH16(0xb8190) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 43
	XXPATCH16(0xb941c) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 44
	XXPATCH16(0xba1d4) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 45
	XXPATCH16(0xbc988) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 46
	XXPATCH16(0xbd7b6) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 47
	XXPATCH16(0xc1b12) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 48
	XXPATCH16(0xc4d08) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 49
	XXPATCH16(0xc5cfe) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 50
	XXPATCH16(0xc9938) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 51
	XXPATCH16(0xd3e50) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 52
	XXPATCH16(0xd91e2) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 53
	XXPATCH16(0xdd704) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 54
	XXPATCH16(0xdd79e) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 55
	XXPATCH16(0xde760) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 56
	XXPATCH16(0xe0962) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 57
	XXPATCH16(0xe09de) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 58
	XXPATCH16(0xe0dac) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 59
	XXPATCH16(0xe0e8e) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 60
	XXPATCH16(0xe0fb6) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 61
	XXPATCH16(0xe238e) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 62
	XXPATCH16(0xe2994) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 63
	XXPATCH16(0xe2b00) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 64
	XXPATCH16(0xe37e4) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 65
	XXPATCH16(0xe54c2) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 66
	XXPATCH16(0xe6746) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 67
	XXPATCH16(0xe7238) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 68
	XXPATCH16(0xe94e8) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 69
	XXPATCH16(0xea552) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 70
	XXPATCH16(0xeb118) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 71
	XXPATCH16(0xeb2ca) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 72
	XXPATCH16(0xec60a) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 73
	XXPATCH16(0xed782) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 74
	XXPATCH16(0xef9ca) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 75
	XXPATCH16(0xf0e76) .word 0x7200;

.file "src/patch/patch_checksum.S"
.line 76
	XXPATCH16(0xf7164) .word 0x7200;

.file __FILE__
.line __LINE__
XXEXPORT_END(dumpy)
.org 0x380000
XXEXPORT_START(ccode)
