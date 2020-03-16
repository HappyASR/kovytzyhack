#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../game_type.h"
#include "../game_func.h"
#include "../game_api.h"
#include "../game_struct.h"
#include "hook.h"




/*屏幕刷新*/
int ScreenUpdate() {
	int i;

	FUN_0016a562();
	FUN_0014c0aa();
	FUN_00175848();
	if (DU32(0x813526)) {
		FUNC32(DU32(0x813526))();
	}
	FUN_0016a788();
	FUN_00190868();
	FUN_00154722();
	if (DU8(0x81352b) == 2) {
		FUN_001911f0();
		FUN_0016b990();
	}
	FUN_00198894();

	/*以下是自己添加的内容*/
	/*改变BOSS血条颜色*/
	for(i=0; i<3; i++) {
		
		if(!DU8(0x80cf1e + i*438 + 0xd4)){
			BossMem[i].HPBarUse = 0;
		}
		if(BossMem[i].HPBarUse) {
			api_wpal_tile((i+2)*2,(int)&BossHPPal[BossMem[i].Lifes-1]);
		}
	}

	/*添加内容结束*/
	while ((DU8(0x81b259) & 0x10) != 0)
		FUN_00198894();

	return 0;
}