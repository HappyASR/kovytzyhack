

//hook_bosshpbar.c
#define BOSS_HP_BAR_SIZE 320
#define BOSS0_HP_PALID 10
#define BOSS1_HP_PALID 10
#define BOSS2_HP_PALID 10

extern int ChkBossUse();
extern void DrawBossHPBar(int RoroUseID,RoroMem *RoroPtr);
extern void ChangeBossHpBar(int RoroUseID);
extern void ChangeBossHP(int RoroUseID,short param_2);
extern void ChkBossHP();
extern void DrawBossHead(int RoroUseID,RoroMem *RoroPtr);
extern void DrawBossInfo(RoroMem *RoroPtr);

extern const u16 BossHPPal[8][16];
extern struct BossInfo BossMem[];