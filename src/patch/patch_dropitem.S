
//hook基本按键 增加BC键扔道具
//XXPATCH16JMP16(0x7d81c,ChkPlayerInput)
XXPATCH16(0x7df2a) jsr ChkMove;
XXPATCH16(0x7dd54) jsr ChkMove;

//XXPATCH16JMP16(0x60d10,hook_eatitem)
//hook道具拾取时候的判断，根据扔出道具的数量来拾取
XXPATCH16(0x69c7c) .word 0x2f0b;
XXPATCH16(0x69c80) jsr EatItem;
XXPATCH16(0x69c9a) .word 0x2f0b;
XXPATCH16(0x69c9e) jsr EatItem;



 
