#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game_type.h"
#include "game_func.h"

void api_delay(int frame){
	int i;
	if(!frame){
		while(1){
			ScreenUpdate_0018c492();
		}
	}else{
		for(i=0;i<frame;i++)
			ScreenUpdate_0018c492();
	}
	return;
}