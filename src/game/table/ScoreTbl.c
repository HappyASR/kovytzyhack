

/*角色的HIT分数表,所有数字乘以100就是实际分数*/
const short ScoreTblA[] = {//0x30e4e2
	//A人物1
	0, 0, 0, 0, 0, 0, 0, 0, 0, 120, 500, 600, 1000, 1200, 1300, 1500, 1600, 1700, 1800, 2000, 2100, 1000, 1000, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
	//A人物2
	0, 0, 0, 0, 0, 0, 0, 200, 1800, 2800, 3000, 3200, 1000, 1000, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
	//A人物3
	0, 0, 0, 0, 0, 0, 30, 120, 180, 600, 2600, 3800, 3900, 4000, 1000, 1000, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
	//A人物4
	0, 0, 0, 0, 0, 0, 80, 120, 1600, 2800, 3000, 3100, 3200, 1000, 1000, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
	//A人物5
	0, 0, 0, 0, 0, 0, 0, 50, 800, 1600, 2000, 2100, 2200, 2300, 1000, 1000, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
	//A人物6
	0, 0, 0, 0, 0, 50, 600, 1500, 3000, 3200, 3300, 1000, 1000, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
	//A人物7
	0, 0, 0, 0, 0, 0, 0, 90, 800, 1200, 1400, 1800, 2000, 2200, 2400, 2500, 1000, 1000, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
	//A人物8
	0, 0, 0, 0, 0, 0, 0, 30, 60, 90, 120, 240, 500, 600, 1200, 1800, 2000, 3000, 3800, 4800, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	//A人物9
	0, 0, 0, 0, 50, 120, 900, 2500, 2600, 2700, 2800, 3000, 3200, 3600, 3800, 1000, 1000, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
	//A人物10
	0, 0, 0, 0, 30, 280, 1200, 2200, 2400, 2800, 3200, 3800, 1000, 1000, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
	//A人物11
	0, 0, 0, 0, 0, 0, 50, 100, 500, 1200, 2000, 3000, 3600, 3800, 4200, 4300, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
	//A人物12
	0, 0, 0, 0, 50, 160, 1800, 2200, 2400, 2500, 2600, 1000, 1000, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
};

const short ScoreTblB[] = {//0x30eaba
	0, 0, 0, 0, 10, 20, 30, 40, 50, 60, 125, 150, 250, 350, 450, 550, 750, 950, 1150, 1550, 2100, 2000, 1000, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 200,
	0, 0, 0, 0, 0, 0, 0, 200, 1800, 2800, 3000, 3200, 1000, 1000, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
	0, 0, 0, 0, 10, 15, 15, 30, 45, 150, 750, 1900, 1950, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 200,
	0, 0, 0, 0, 0, 0, 80, 120, 1600, 2800, 3000, 3100, 3200, 1000, 1000, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
	0, 0, 0, 0, 10, 15, 25, 35, 45, 55, 65, 75, 85, 95, 505, 1000, 1000, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	0, 0, 0, 10, 20, 30, 400, 750, 1000, 2000, 2000, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	0, 0, 0, 0, 10, 20, 40, 90, 200, 300, 350, 450, 500, 750, 1000, 1150, 1300, 1450, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	0, 0, 0, 0, 10, 10, 10, 15, 30, 45, 60, 120, 250, 300, 600, 900, 1000, 1500, 2000, 3000, 3000, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	0, 0, 0, 0, 25, 60, 450, 1250, 1300, 1350, 1400, 1500, 1600, 1800, 1900, 500, 500, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	0, 0, 0, 0, 15, 140, 600, 1100, 1200, 1400, 1600, 1900, 500, 500, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	0, 0, 0, 0, 10, 20, 25, 50, 250, 2400, 1000, 1500, 1800, 1900, 2100, 2200, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	0, 0, 0, 10, 25, 80, 900, 1100, 1200, 1500, 1800, 1500, 1500, 1500, 1500, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
};