#ifndef DEFENSEEQUIPMENT_H_
#define DEFENSEEQUIPMENT_H_

#define _CRT_SECURE_NO_WARNINGS
#include "Equipment.h"

//����װ��
typedef struct DefenseEquipment
{
	Equipment equipment;
	int physicalDefense;
	int magicDefense;
}DefenseEquipment;

/**��ʼ������װ��

 *

 * ���ڳ�ʼ������װ��

 * @param [in] 
    defenseEquipment ����װ���ĵ�ַ
    name             װ����
    price            �۸�
    physicalDefense  �������
    magicDefense     ħ������

 * @param [out] 
    ��

 * @return 
    ��

 * @note   
    name ��Ҫ��������

*/
void InitDefenseEquipment(DefenseEquipment* defenseEquipment, const char* name,
	int price, int physicalDefense, int magicDefense);

//ͬ����װ��
int GetDefenseEquipmentPhysical(const DefenseEquipment* defenseEquipment);

//ͬ����װ��
int GetDefenseEquipmentMagic(const DefenseEquipment* defenseEquipment);
#endif