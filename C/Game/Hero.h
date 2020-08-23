#ifndef HERO_H_
#define HERO_H_

#include "AlloyEquipment.h"
#define type Equipment*
#include "array.h"

//Ӣ�۽ṹ
typedef struct Hero
{
	char name[81];
	int health;
	int physicalDamage;
	int magicalDamage;
	int money;
	int physicalDefense;
	int magicalDefense;
	array equipment;
}Hero;


/**��ʼ��Ӣ��
 *

 * ���ڳ�ʼ��Ӣ��

 * @param [in] 
	hero		Ӣ�۽ṹ��ַ
	name		Ӣ����
	money		��Ǯ
	health		����ֵ
	physicalDamage	������
	magicalDamage	ħ������
	physicalDefense	�������
	magicalDefense	ħ������

 * @param [out] 
	��

 * @return 
	��

 * @note   

*/
void InitHero(Hero* hero,
	const char* name, int money, int health,
	int physicalDamage, int magicalDamage,
	int physicalDefense, int magicalDefense);

/**���½���Ӣ��

 *

 * ���½���Ӣ����Ϣ

 * @param [in]
	hero		Ӣ�۽ṹ
	name		�µ�����
	money		��Ǯ
	reset_equip	�Ƿ��ؽ�װ��
	equip		�ؽ�װ���ĵ�ַ�ṹ

 * @param [out] 
	��

 * @return 
	��

 * @note   

*/
void ResetHero(Hero* hero, const char* name, int money,	int reset_equip, Equipment* equip);
void DestroyHero(Hero* hero);

const char* GetHeroName(const Hero* hero);
int GetHeroHealth(const Hero* hero);
int GetHeroPhysicalDamage(const Hero* hero);
int GetHeroMagicalDamage(const Hero* hero);
int GetHeroPhysicalDefense(const Hero* hero);
int GetHeroMagicalDefense(const Hero* hero);
int GetHeroEquipmentNumber(const Hero* hero); 
int GetHeroMoney(const Hero* hero);
Equipment* GetHeroEquipmentByIndex(const Hero* hero, int index);
int GetHeroRealPhysicalDamage(const Hero* hero);
int GetHeroRealMagicalDamage(const Hero* hero);
int GetHeroRealPhysicalDefense(const Hero* hero);
int GetHeroRealMagicalDefense(const Hero* hero);
double GetHeroCritChance(const Hero* hero);

//�ж�Ӣ���Ƿ���
int HeroIsAlive(const Hero* hero);

void PrintHeroInfo(const Hero* hero);

int HeroBuyEquipment(Hero* hero, Equipment* equip);

int HeroSellEquipment(Hero* hero, int index);


/**�ϳ���װ��

 *

 * ���ݹ���װ���ͷ���װ���ϳ�

 * @param [in] 
	hero					Ӣ�۽ṹ
	attackEquipmentIndex	����װ���±�
	defenseEquipmentIndex	����װ���±�


 * @param [out]
	int

 * @return 
	�ɹ�����1��ʧ�ܷ���0

 * @note   
	�����±�����ϸ��Ӧװ������

*/
int HeroSynthesiEquipment(Hero* hero, int attackEquipmentIndex, int defenseEquipmentIndex);


int HeroAttack(Hero* me, Hero* that);
int HeroRecover(Hero* hero);

#endif