#ifndef HEROWORLD_H_
#define HEROWORLD_H_
#include "Hero.h"
#include "macro.h"
#include "ui.h"
#include <conio.h>
typedef struct HeroWorld
{
	Hero player;
	Hero enemy;
	int gameNumber;
	int roundNumber;
	int score;
	array inventory;
}HeroWorld;

void InitHeroWorld(HeroWorld* heroWorld, const char* playerName, const char* enemyName);
void DestroyHeroWorld(HeroWorld* heroWorld);

void SaveHeroWorld(const HeroWorld* heroWorld);
void LoadHeroWorld(HeroWorld* heroWorld);
int GetHeroWorldGameNumber(const HeroWorld* heroWorld);
int GetHeroWorldRoundNumber(const HeroWorld* heroWorld);
int GetHeroWorldScore(const HeroWorld* heroWorld);
Equipment* GetHeroWorldInventory(const HeroWorld* heroWorld, int index);
void PrintHeroWorldInventory(const HeroWorld* heroWorld);
void PrintHeroWorldFinal(HeroWorld* heroWorld);


//ÿ����Ϸ�Ļغ�ѭ��
int HeroWorldRoundLoop(HeroWorld* heroWorld);
//ÿ����Ϸ��ѭ��
void HeroWorldGameLoop(HeroWorld* heroWorld);

#endif