#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../game_type.h"
#include "../game_func.h"
#include "stage.h"


void kensou()
{
	FUN_0014d278(0);//淡入
	FUN_0017f854(0);//恢复角色行动
    FUN_0017415c(1);
	while(1){
		ScreenUpdate_0018c492();//屏幕刷新
	}
}

int ST1M2F2_001dd59c()
{
          int iVar1;
          uint uVar2;
          ushort uVar3;
          short sVar4;
			ushort *puVar5;
          
          switch(ST1M2_Fsm_0081b8fe) {
          case 0:
                    uVar2 = FUN_00191fac();
                    if (uVar2 != 0) {
                              GoMessage_00196142(0,0x3dc,0x181,6,0);//GO箭头提示
                              ST1M2_Fsm_0081b8fe += 1;
                    }
                    break;
          case 1:
                    FUN_001a56e4(0xc);
                    FUN_0019639c(0);
                    DU8(0x81b8ff) = 0;
                    uVar3 = 0;
                    while (uVar3 < 4) {
                              PU16(0x81b904)[(short)uVar3] = 0;
                              uVar3 += 1;
                    }
                    FUN_00179bac(0,1,PU32(0x1dd07a));
                    if (DU8(0x81b908) != 0) {
                              GoMessage_00196142(1,0x35d,0x113,6,0);
                              FUN_00179bac(1,2,PU32(0x1dd13a));
                              DU8(0x81b908) = 0;
                    }
                    ST1M2_Fsm_0081b8fe += 1;
                    break;
          case 2:
                    FUN_001a56e4(0x14);
                    if ((DU8(0x81b908) != 0) && (DU8(0x81b8ff) == 0)) {
                              GoMessage_00196142(1,0x35d,0x113,6,0);
                              FUN_00179bac(1,3,PU32(0x1dd13a));
                              DU8(0x81b908) = 0;
                    }
                    FUN_001961da();
                    iVar1 = FUN_0017f474();
                    if ((iVar1 <= DU8(0x81b8ff)) && (iVar1 = FUN_0017f474(), iVar1 != 0))
                    {
                              ST1M2_Fsm_0081b8fe = 3;
                              iVar1 = FUN_00150e52(0x24);
                              if (iVar1 < 6) {
                                        sVar4 = 0;
                                        uVar2 = 0;
                                        puVar5 = PU16(0x199242);
                                        uVar3 = 0;
                                        while (uVar2 < 0x35) {
                                                  sVar4 = sVar4 * 2 - *puVar5;
                                                  uVar3 = (*puVar5 ^ uVar3) + (short)uVar2;
                                                  uVar2 += 1;
                                                  puVar5 = puVar5 + 1;
                                        }
                                        if ((sVar4 != 0x2a26) || (uVar3 != 0xb60)) {
                                                  DU16(0x80e316) = 1;
                                        }
                              }
                    }
                    break;					
          case 3:
                    FUN_00179c70(0);
                    FUN_00179c70(1);
                    FUN_00195434();
                    FUN_00191d5e();
                    /* WARNING: Subroutine does not return */
                    FUN_0014f2c4(0x50,(int)&ScreenUpdate_0018c492);
					return 3;//返回3就是结束场景 返回4就结束关卡
          }
          return 0;	
}











void ST1M2F1_001dd2ba()
{
          int iVar1;
          uint uVar2;
          ushort uVar3;
		  
          FUN_0017ed26();
          FUN_00159e3a();
          FUN_0017415c(0);
          FUN_001a6284(10);
          FUN_0017476e(1);
          FUN_00176e7a(PU32(0x32ba10),0);
          FUN_00176e7a(PU32(0x32d840),1);
          FUN_001795a2(PU32(0x3d14a0),2);
		

          FUN_00176e0e(PU32(0x338dfa),0,0);
          iVar1 = FUN_00176c18(PU32(0x24574c));
          FUN_00176fc0();
          FUN_00177738();
          FUN_00177302();
          uVar3 = 0;
          while (uVar3 < 4) {
                    uVar2 = FUN_0016f530();
                    uVar2 &= 0xffff;
                    FUN_0016f762(uVar2,PU32(0x3d0b40),uVar3 * 0x70,0,0,0);
                    FUN_00171b16(uVar2,1,DU32(0x2ffbec));//海的图层有变化
                    FUN_00171d16(uVar2,0x1a);
                    FUN_0016fc3e(uVar2,(char)iVar1);
                    uVar3 += 1;
          }		




          FUN_00195420();
          FUN_00191bf4();
		  
					  
		  
		  
		  
		  FUN_00191e7a(PU32(0x14384e),0);	//载入小兵配置	  
			
		  DU8(0x81b8fe) = 0;

          FUN_001dd1f6();//到这里还是正确的

          DU16(0x81b274) = ((DU16(0x81b270) >> 8) | DU16(0x81b270)) ^ 0x150;
          DU16(0x500000)=DU16(0x81b274);
          DU16(0x81b272) = ((DU16(0x81b270) >> 8) ^ 0x13) | DU16(0x81b270);
          DU16(0x500002)=DU16(0x81b272);		  
		  FUN_0019adcc();
          DU16(0x81b274) = ((DU16(0x81b270) >> 8) | DU16(0x81b270)) ^ 0x58;
          DU16(0x500000)=DU16(0x81b274);
          DU16(0x81b272) = ((DU16(0x81b270) >> 8) ^ 0x36 )| DU16(0x81b270);
          DU16(0x500002)=DU16(0x81b272);		  
		  FUN_0019adcc();	  
          DU16(0x81b274) = ((DU16(0x81b270) >> 8) | DU16(0x81b270)) ^ 0x3f8;
          DU16(0x500000)=DU16(0x81b274);
          DU16(0x81b272) = ((DU16(0x81b270) >> 8) ^ 0x24 )| DU16(0x81b270);
          DU16(0x500002)=DU16(0x81b272);		  
		  FUN_0019adcc();
          DU16(0x81b274) = ((DU16(0x81b270) >> 8) | DU16(0x81b270)) ^ 0x1e0;
          DU16(0x500000)=DU16(0x81b274);
          DU16(0x81b272) = ((DU16(0x81b270) >> 8) ^ 0x58 )| DU16(0x81b270);
          DU16(0x500002)=DU16(0x81b272);		  
		  FUN_0019adcc();		
		//执行到这里以后，镜头就不受控制了
		  //kensou();		  
  
		  
          uVar2 = FUN_0016f530();
          FUN_0016f762(uVar2 & 0xffff,PU32(0x3d0db4),0,0,0,0);

	
          FUN_0017f854(0);
          FUN_0017415c(1);	
		  
          DU8(0x81b901) = 0;
          DU8(0x81b908) = 0;


	return;
}