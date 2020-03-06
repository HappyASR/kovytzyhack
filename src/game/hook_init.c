#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game_type.h"
#include "game_func.h"
#include "stage/stage.h"
#include "game_api.h"
#include "pages/pages.h"
















/*投币后的开始界面函数*/
void TitlePage() {
	int PlayerID;

	FUN_001f6e84(0xf,0);
	FUN_001f7008(0x14,0);
	if (DU8(0x81352f) != 0) {
		PlaySound_001f6d34(0,0xc5,0x7f,0);//投币的声音
		DU8(0x81352f) = 0;
	}
	//PlayerID = FUN_00198c12();//这里是标题倒计时画面，返回值是一个操作的PlayerID
	PlayerID = PageStartGame();
	FUN_001a4a86();
	FUN_00196ab0();
	//FUN_0016d2e6(PlayerID);//选模式和选人函数
	PageSelectMode(PlayerID);
	PageSelectRole(PlayerID);
	DU8(0x81352c) = 0;
	FUN_00190cba();
	while (DU8(0x81352c) != 3) {
		if (DU8(0x81352c) == 0) {
			FightResult_001a66c2();
		} else {
			if (DU8(0x81352c) == 1) {
				FUN_00196b88();
			}
		}
	}
	FUN_0016d2f6();
	FUN_001a69a2();
	FUN_001f6e84(0xf,0);
	return;
}























void Hook(int a1,int a2,int a3,int a4,int a5) {
	Print(0,0,0,0,0,"a1=%d a2=%d a3=%d a4=%d a5=%d",a1,a2,a3,a4,a5);
	DU8(0x81b1e2)=100;
	return;
}













void _main() {
	DU8(0x803801) = 0;
	FUN_0014b88c();
	FUN_0018c582();
	FUN_001a4956();
	FUN_001975e8();
	PageCopyright();
	FUN_00173524();
	while(1) {
		while ( 1 ) {
			switch ( MainFSM_0081352b ) {
			case 0:
				OpenPage_00198794();
				break;
			case 1:
				continue;
			case 2:
				FUN_001a4a86();
				OpenPage_00198794();
				break;
			case 3:
				MainMenu_001a4960();
				break;
			case 4:
				MainMenu_001a4960();
				return;
			default:
				MainFSM_0081352b = 2;
				break;
			}
		}

	}
}
