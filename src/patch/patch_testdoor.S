//第一关出场刷兵脚本调用门测试
XXPATCH16(0x2cf530)
.byte	0xFF,0x14,0x00,0x00;|
.byte	0xFF,0x11,0x03,0x00;|设置AI
.byte	0xFF,0x04,0x03,0x01,0x00,0x13,0x05,0x84,0x02,0x5D,0x00,0xF6,0x00,0x00,0x00,0x01;|刷一只弓箭手
.byte	0xFF,0x08,0x00,0x00;|循环判断场上小兵剩余0
.byte	0xFF,0x0c,0x01,0x00;|门的ID和门坐标ID
.long	SetDoorByID;|调用函数
.byte	0xff,0x16,0x00,0x00;|刷兵脚本结束

//第一关第四场景调用门测试
XXPATCH16(0x2cefe6)
.byte	0xFF,0x14,0x00,0x00;|
.byte	0xFF,0x11,0x03,0x00;|设置AI
.byte	0xFF,0x04,0x03,0x01,0x00,0x13,0x05,0x84,0x02,0x5D,0x00,0xF6,0x00,0x00,0x00,0x01;|刷一只弓箭手
.byte	0xFF,0x08,0x00,0x00;|循环判断场上小兵剩余0
.byte	0xFF,0x0c,0x01,0x01;|门的ID和门坐标ID
.long	SetDoorByID;|调用函数
.byte	0xff,0x16,0x00,0x00;|刷兵脚本结束
