#ifndef EQUIPMENT_H_
#define EQUIPMENT_H_

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>

//װ��������
enum EquipmentType
{
	normal,
	attack,
	defense,
	alloy
};

//����װ������˽ṹ
typedef struct Equipment
{
	char name[81];
	int price;
	int type;
}Equipment;

/**��ȡװ������
*

 * ����equipment��ȡװ������

 * @param [in] 
	equipment		��Ҫ��ȡ���͵�װ����ַ

 * @param [out]
	int

 * @return 
	װ��������		
	
* @see  
	 ��������װ������ö��

 * @note

*/
int GetEquipmentType(const Equipment* equipment);

//������ͬ����װ��
void InitEquipment(Equipment* equipment, const char* name, int price);

const char* GetEquipmentName(const Equipment* equipment);

int GetEquipmentPrice(const Equipment* equipment);
void SetEquipmentName(Equipment* equipment, const char* name);
void SetEquipmentPrice(Equipment* equipment, int price);

#endif