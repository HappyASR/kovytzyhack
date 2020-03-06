#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../game_type.h"
#include "../game_func.h"
#include "../stage/stage.h"
#include "../game_api.h"




/*warning界面*/
void PageCopyright() {
	int i;
	FUN_001527fc();
	FUN_0015294e(0,0,0,0x38,0x1c);
	FUN_0015294e(1,0,0,0xe,7);
	FUN_0014d5a6();
	FUN_0014e96c();
	FUN_0014be5e();
	Print_00153452(0,50,27,3,0,"V201");
	//DrawLine_001a0eb8(8,6,0x26,5);
	for(i=1; i<6; i++)
		Print_00153452(0,1,3*i,3,i,"FNT%d ABCabc123",i);
	for(i=9; i<11; i++)
		Print_00153452(0,1,17+3*(i-8),3,i,"FNT%d ABCabc123",i);


	FUN_00152b92();
	FUN_0014ce68(0,5,DU16(0x243520));
	FUN_0014d278(0);
	FUN_00173524();
	FUN_0014f236( FUN_0014f178(),300);
	while(1) {
		ScreenUpdate_0018c492();
	}
	return;
}