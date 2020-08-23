#pragma once

#include "genlib.h"
#include "../DataSystem/Student.h"
#include "..//DataSystem/DataSystem.h"
#include "..//UI/SearchAssistance.h"
#include <math.h>

typedef bool (*ConditionStu)(const void* data1,const void* data2);
void AddStudentRecord(const Student* data);//ʹ��ǰȷ��dataSystemȫ�ֱ����õ���ʼ��
int RemoveStudentRecord(ConditionStu condition, const void * con); //con����Ϊ�����ĵ�ַ, dataSystemȫ�ֱ�����Ҫ�õ���ʼ��
int ModifyStudentRecord(ConditionStu condition, const void * con, Student* data);//conΪ������ַ dataSystem��Ҫ��ʼ��
int AddOptCourseRecord(unsigned stuId, string courseId,double score);//dataSystem��Ҫ��ʼ��
bool RemoveStudentById(const void * data1, const void * data2);
bool RemoveStudentByName(const void * data1, const void * data2);
bool ModifyStudentById(const void * data1, const void * data2);

