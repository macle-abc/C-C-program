
#include "genlib.h"
#include <string.h>
typedef struct Student
{
	unsigned int m_id;//ѧ��
	string m_name;//����
	unsigned int m_class;//�༶
	string m_major;//רҵ
	char m_sex;//�Ա�
}Student;
/*
typedef struct{
	...
}your_type;
#define __list_t	your_type
*/

#define __list_t Student

#include "__list_h.h"
#include "__list_c.h"

void CopyStu(Student* des, const Student* src)
{
	des->m_class = src->m_class;
	des->m_id = src->m_id;
	des->m_sex = src->m_sex;
	des->m_major = (string)malloc(strlen(src->m_major) + 1);
	strcpy(des->m_major, src->m_major);
	des->m_name = (string)malloc(strlen(src->m_name) + 1);
	strcpy(des->m_name, src->m_name);
}

void DestructStu(Student* stu)
{
	free(stu->m_major);
	free(stu->m_name);
}