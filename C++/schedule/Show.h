#pragma once
#include "Schedule.h"
#include <Windows.h>
#include <cstdio>
extern HANDLE hstdout;
void printXY(short x, short y, const string& str);
void ShowFunctionalArea(); //չʾ������
void ShowStatusBar(const Schedule& schedule); //չʾ״̬��
void ShowOptionArea(); //չʾѡ����
void ShowProcessStatusArea(const Schedule& schedule); //չʾ����״̬��Ϣ
void ShowInterface(const Schedule& schedule); //all
void ShowResource(const Schedule& schedule);
void Location(int x, int y);

