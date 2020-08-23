#pragma once

#include "graphics.h"
#include "genlib.h"
#include "..//DataSystem/DataSystem.h"
#include "..//Lib/error.h"
#include "..//Lib/check.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef bool(*ConditionSearch)(const void* data, const void* conVal);
bool SearchStudentByName(const void* data, const void * conVal);
bool SearchStudentById(const void* data, const void * conVal);
bool SearchStudentByClass(const void* data, const void* conVal);
bool SearchStudentByMajor(const void* data, const void* conVal);

bool SearchCoureById(const void* data, const void* conVal);
bool SearchCourseByName(const void* data, const void* conVal);
bool SearchCourseByTeacher(const void* data, const void* conVal);

bool SearchOptCorseByStudentId(const void* data, const void* conVal);
bool SearchOptCourseByCourseId(const void* data, const void* conVal);
bool SearchOptCourseByScore(const void* data, const void* conVal);
//�жϺ��� �������� �жϺ����е��ж�ֵ
void FindAndSave(ConditionSearch condition, DataType dataType, const void* conVal);//����ᴢ����һ��ȫ�ֵ�result�У�ÿ�β�ѯ��ˢ�½��
void CollectData();
bool FuzzySearch(const char* des, const char* src);
