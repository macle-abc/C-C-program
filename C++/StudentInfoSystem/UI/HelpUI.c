#include "HelpUI.h"

void ShowAbout()
{
	MessageBox((HWND)0, (LPCSTR)About(), (LPCSTR)"����", (UINT)64);
}

void ShowApproach()
{
	MessageBox((HWND)0, (LPCSTR)Approach(), (LPCSTR)"ʹ�÷���", (UINT)64);
}
