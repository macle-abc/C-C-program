#pragma once

#include "genlib.h"
#include "..//UI/UIAssistance.h"
#include "..//Lib/error.h"
#include <string.h>
typedef struct Student
{
	unsigned int m_id;//ѧ��
	string m_name;//����
	unsigned int m_class;//�༶
	string m_major;//רҵ
	char m_sex;//�Ա�
}Student;

//#include <stdio.h>
#define __list_t Student
#include "list.h"

void CopyStu(Student* des, const Student* src);
void DestructStu(Student* stu);

void ReadFileToStuList(const char* path, Student_list* stuList);
void WriteFileFromStuList(const char* path, const Student_list* stuList, const char* mode);

Student_list_iterator CompareStu(Student * data1, const Student* data2);

