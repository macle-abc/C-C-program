#ifndef ALLOYEQUIPMENT_H_
#define ALLOYEQUIPMENT_H_
#define _CRT_SECURE_NO_WARNINGS

#include "AttackEquipment.h"
#include "DefenseEquipment.h"

//�Ͻ�װ��(����װ��+����װ��)�ں�
typedef struct AlloyeEquipment
{
	AttackEquipment attackEquipment;
	DefenseEquipment defenseEquipment;

}AlloyeEquipment;

/**��ʼ���Ͻ�װ��

 *

 * ���ڳ�ʼ���Ͻ�װ��

 * @param [in] 
    alloyeEquipment �Ͻ�װ���ṹ�ĵ�ַ 
    attackEquipment ���ںϳɵĹ���װ���ṹ�ĵ�ַ
    defenseEquipment ���ںϳɵķ���װ���ṹ�ĵ�ַ
    
 * @param [out] 
    �� 

 * @return 
    ��


 * @note   
    ���ںϳɵĹ���װ����������Լ�������

*/
void InitAlloyeEquipment(AlloyeEquipment* alloyeEquipment,
 const AttackEquipment* attackEquipment,
	const DefenseEquipment* defenseEquipment);

#endif
