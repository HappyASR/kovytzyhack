#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../game_type.h"
#include "../game_func.h"
#include "../game_api.h"
#include "../game_struct.h"
#include "hook.h"

#define P1_PRESS DU8(0x811be7)


char GetCurItem(int PlayerID) {
	return DU8(gRoleMem[PlayerID].ItemPtr +0x66 +DU8(gRoleMem[PlayerID].ItemPtr + 0x8c )*2);
}













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


	/*添加内容结束*/
	while ((DU8(0x81b259) & 0x10) != 0)
		FUN_00198894();

	return 0;
}