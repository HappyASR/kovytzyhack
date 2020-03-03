#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game_type.h"
#include "game_func.h"


void TitlePage()
{
    //FUN_001f6e84(0xf,0);
    //FUN_001f7008(0x14,0);
    if (!DU8(0x0081352f) ) 
	{
        //FUN_001f6d34(0,0xc5,0x7f,0);
        DU8(0x0081352f) = 0;
    }
    //FUN_001a4a86();
    //FUN_00196ab0();
    //FUN_0016d2e6(FUN_00198c12());	
}





void PageWarning()
{
	int i;
    FUN_001527fc();
    FUN_0015294e(0,0,0,0x38,0x1c);
    FUN_0015294e(1,0,0,0xe,7);
    FUN_0014d5a6();
    FUN_0014e96c();
	FUN_0014be5e();
	Print_00153452(0,50,27,3,0,"V201");	
	//DrawLine_001a0eb8(8,6,0x26,5);
	for(i=1;i<6;i++)
		Print_00153452(0,1,3*i,3,i,"FNT%d ABCabc123",i);
	for(i=9;i<11;i++)
		Print_00153452(0,1,17+3*(i-8),3,i,"FNT%d ABCabc123",i);

	
	FUN_00152b92();
	FUN_0014ce68(0,5,DU16(0x243520));
	FUN_0014d278(0);
	FUN_00173524();
	FUN_0014f236( FUN_0014f178(),300);
	while(1){
		ScreenUpdate_0018c492();
	}
}




void _main()
{
    DU8(0x803801) = 0;
    FUN_0014b88c();
    FUN_0018c582();
    FUN_001a4956();
    FUN_001975e8();
	PageWarning();		 
	FUN_00173524(); 
	while(1)
	{	
		while ( 1 )
		{
			switch ( MainFSM_0081352b )
			{
			  case 0:
				TitlePage();
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
