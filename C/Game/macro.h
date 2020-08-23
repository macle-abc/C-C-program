#ifndef MACRO_H_
#define MACRO_H_

//���ڱ���Ŀ��ʹ�õĺ�
#include <Windows.h>
#include <stdio.h>
#define PrintError(str) fprintf(stderr, "%s", str);
#include <time.h>

#define MYRAND ((double)(clock() % 1000) / 1000)

//�������������ı���ɫ
#define SET_CYAN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE)
#define SET_WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN | FOREGROUND_BLUE)
#define SET_RED SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED)
#define SET_GREEN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN)
#define SET_YELLOW SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN)


//Ӣ�۵ķ��������ή���ܵ����˺��ʡ�
//��ֵ��Ӧ̫��
#define C_IMMUNE 24.0

//���ڼ��㱩�����ʡ� ��ֵ��Ӧ̫��
#define C_CRIT_MONEY 40.0

//����װ��ʱ�����ԭʼ�۸�ı��ʡ�
#define C_SELL 0.6

//���Ե������һ���̶ȵ��˺�ʱ������ݴ��˺����յ���Ǯ����
#define C_RECEIVE 5

//����ϵ��
#define C_CRIT 1.5



#endif