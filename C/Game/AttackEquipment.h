#ifndef ATTACKEQUIPMENT_H_
#define ATTACKEQUIPMENT_H_
#include "Equipment.h"

//����װ��
typedef struct AttackEquipment
{
	Equipment equipment;
	int physicalDamage;
	int magicDamage;
}AttackEquipment;

/**��ʼ������װ��

 *

 * ���ڳ�ʼ������װ��

 * @param [in] 
    attackEquipment ����װ���ṹ��ַ
    name            װ����
    price           �۸�
    physicalDamage  ������
    magicDamage     ħ������

 * @param [out] 
    ��

 * @return 
    ��

 * @note   
    name ��Ҫ��������

*/
void InitAttackEquipment(AttackEquipment* attackEquipment, const char* name,
	int price, int physicalDamage, int magicDamage);

/**��ȡ����װ��������

 *

 * ���ڻ�ȡ����װ��������

 * @param [in] 
    attackEquipment ��Ҫ��ȡ������װ��

 * @param [out] 
    int

 * @return 
    ����װ����������ֵ


 * @note 

*/
int GetAttackEquipmentPhysicalDamage(const AttackEquipment* attackEquipment);

/**��ȡ����װ��ħ������

 *

 * ���ڻ�ȡ����װ��ħ������

 * @param [in] 
    attackEquipment ��Ҫ��ȡ������װ��

 * @param [out] 
    int

 * @return 
    ����װ����ħ������ֵ


 * @note 

*/
int GetAttackEquipmentMagicDamage(const AttackEquipment* attackEquipment);

#endif