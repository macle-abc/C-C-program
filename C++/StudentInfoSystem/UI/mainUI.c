#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stddef.h>

#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

#include "imgui.h"
#include "mainUIData.h"
#define DEMO_MENU
#define DEMO_BUTTON
#define DEMO_ROTATE
#define DEMO_EDITBOX

/***************************************************************
 VisualStudio 2010 �û�ע�⣺
    ��Character Set����Ϊ Use Multibyte Character Set
	����������ʾ������
***************************************************************/
// ��ת��ʱ��
#define MY_ROTATE_TIMER  1
// ȫ�ֱ���
double winwidth, winheight;   // ���ڳߴ�

// ����������provided in libgraphics
void DisplayClear(void); 

// �û�����ʾ����
void display(void); 

// �û����ַ��¼���Ӧ����
void CharEventProcess(char ch)
{
	uiGetChar(ch); // GUI�ַ�����
	display(); //ˢ����ʾ
}

// �û��ļ����¼���Ӧ����
void KeyboardEventProcess(int key, int event)
{
	uiGetKeyboard(key,event); // GUI��ȡ����
	display(); // ˢ����ʾ
}

// �û�������¼���Ӧ����
void MouseEventProcess(int x, int y, int button, int event)
{
	uiGetMouse(x,y,button,event); //GUI��ȡ���
	display(); // ˢ����ʾ
}


extern void startTimer(int id, int timeinterval);
// �û��ļ�ʱ��ʱ����Ӧ����
void TimerEventProcess(int timerID)
{
	display();
}
// �û����������
// ����ʼ��ִ��һ��
void Main() 
{
#ifdef ABC_DEBUG
	 extern void test();
#endif
	 // ��ʼ�����ں�ͼ��ϵͳ
	SetWindowTitle("ѧ����Ϣ����ϵͳ");
	//SetWindowSize(10, 10); // ��λ - Ӣ��
	//SetWindowSize(15, 10);
	//SetWindowSize(10, 20);  // �����Ļ�ߴ粻�����򰴱�����С
    InitGraphics();
	InitAllUI();
	// ��ô��ڳߴ�
	winwidth = GetWindowWidth();
	winheight = GetWindowHeight();

	registerCharEvent(CharEventProcess); // �ַ�
	registerKeyboardEvent(KeyboardEventProcess);// ����
	registerMouseEvent(MouseEventProcess);      // ���
	registerTimerEvent(TimerEventProcess);      // ��ʱ��
	startTimer(MY_ROTATE_TIMER, 50);
	// �򿪿���̨���������������Ϣ�����ڵ���
#ifdef ABC_DEBUG
	InitConsole(); 
	test();
#endif
}

extern MainUI mainUI;
extern SortUI sortUI;
extern SearchUI searchUI;
extern CourseUI courseUI;
extern StudentUI studentUI;
extern FileUI fileUI;

void display()
{
	// ����
	DisplayClear();	
	MainUIDisplay();
	fileUIDisplay();
	studentUIDisplay();
	CourseUIDisplay();
	SearchUIDisplay();
	SortUIDisplay();
}


