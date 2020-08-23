#pragma once

#include "genlib.h"
#include "..//Lib/error.h"
#include <stdio.h>
#include <string.h>
typedef struct Couse
{
	string m_cId;//�γ̺�
	string m_cName;//�γ���
	string m_teacher;//��ʦ��
}Course;


//#include <stdio.h>
#define __list_t  Course
#include "list.h"

void DestructCourse(Course* cou);
void CopyCourse(Course* des, const Course* src);
void ReadFileToCouList(const char* path, Course_list* courseList);
void WriteFileFromCouList(const char* path, const Course_list* courseList, const char* mode);
Course* CompareCou(Course* data1, const Course* data2);
