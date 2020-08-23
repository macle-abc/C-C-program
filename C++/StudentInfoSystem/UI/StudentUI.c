#include "StudentUI.h"

extern DataSystem dataSystem;
StudentUI studentUI = { 1, 1 };
void allStuUIClose()
{
	studentUI.m_addRecordUIVisible = 0;
	studentUI.m_editVisible = 0;
	studentUI.m_mvUIVisible = 0;
	studentUI.m_removeRecordUIVisible = 0;
	studentUI.m_setUIVisible = 0;
}
void setStuUIVisible(whichStu which)
{
	switch (which)
	{
	case addStu:
		studentUI.m_addRecordUIVisible = 1;
		break;
	case rmStu:
		studentUI.m_removeRecordUIVisible = 1;
		break;
	case mvStu:
		studentUI.m_mvUIVisible = 1;
		break;
	case setStu:
		studentUI.m_setUIVisible = 1;
		break;
	case textStu:
		studentUI.m_editVisible = 1;
		break;
	default:
		break;
	}
}
void initStuUI()
{
	studentUI.m_addRecordUIVisible = 0;
	studentUI.m_editVisible = 0;
	studentUI.m_mvUIVisible = 0;
	studentUI.m_removeRecordUIVisible = 0;
	studentUI.m_setUIVisible = 0;
	mystring_init(&studentUI.m_edit.m_srcData);
	studentUI.m_init = 1;
	mystring_init(&studentUI.m_text);
}

void studentUIDisplay()
{
	if (studentUI.m_addRecordUIVisible)
		StudentUIDrawAddUI();
	if (studentUI.m_removeRecordUIVisible)
		StudentUIDrawRmUI();
	if (studentUI.m_mvUIVisible)
		StudentUIDrawMvUI();
	if (studentUI.m_setUIVisible)
		StudentUIDrawSetUI();
	if (studentUI.m_editVisible)
	{
		//StudentUIDrawAddUI();
		//ʵʩ����
	//	readFile("../DataSystem/Data/StudentTable.txt", &studentUI.m_text, &studentUI.m_edit);
		DrawEditor(TextStringWidth("�����γ���Ϣ") + 1, 1.0, 7.5, 5.5, &studentUI.m_edit);
	}
}

void StudentUIDrawAddUI()
{
//	extern mainUI mainui;
//	mainui.m_LabelVisible = FALSE;
	//TextStringWidth("�����γ���Ϣ") + 1, 1.0, 7.5, 5.5
	double x = TextStringWidth("�����γ���Ϣ") + 1;
	double y = 6.0;
	double w = 7;
	double h = GetFontHeight() + 0.4;
	static char buff[][1024] = { "", "", "", "", "" };
	char label[][1024] = { "ѧ��(8λ����):", "����:", "�༶(9λ����):", "רҵ:", "�Ա�(��:M Ů:W):" };
	int i = 0;
	for (; i != 5; ++i)
	{
		SetPenColor("Brown");
		drawLabel(x - h / 2 - TextStringWidth("��"), (y -= h * 1.2) + h * 0.7, label[i]);
		if (textbox(GenUIID(i), x + 0.8, y, w, h, buff[i], 1024))
			;
	}	
	if (button(GenUIID(0), x + w / 2, y -= h * 1.2 + h * 0.7, w / 2, h, "���"))
	{
		Student temp;
		temp.m_name = malloc(1024);
		temp.m_major = malloc(1024);
		sscanf(buff[0], "%u", &temp.m_id);
		sscanf(buff[1], "%s", temp.m_name);
		sscanf(buff[2], "%u", &temp.m_class);
		sscanf(buff[3], "%s", temp.m_major);
		sscanf(buff[4], "%c", &temp.m_sex);
		ReadFileToDataSystem();
		AddStudentRecord(&temp);
		free(temp.m_name);
		free(temp.m_major);
		studentUI.m_editVisible = 1;
		WriteFileFromStuList("../DataSystem/Data/StudentTable.txt", &dataSystem.m_studentTable, "w");
		ReadFileToEditor("../DataSystem/Data/StudentTable.txt", &studentUI.m_text, &studentUI.m_edit);
		studentUI.m_addRecordUIVisible = 0;
	}
	/*
	SetPenColor("Brown");
	drawLabel(x - h / 2 - TextStringWidth("��"), (y -= h * 1.2) + h * 0.7, "ѧ��");
	if (textbox(GenUIID(0), x, y, w, h, buff[3], 1024))
//		sprintf(results, "Text edit result is: %s+%s", firstName, lastName);

	SetPenColor("Brown");
	drawLabel(x - h / 2 - TextStringWidth("��"), (y -= h * 1.2) + h * 0.7, "����");
	if (textbox(GenUIID(0), x, y, w, h, buff[2], 1024))
	//	sprintf(results, "Text edit result is: %s+%s", firstName, lastName);

	SetPenColor("Gray");
	drawLabel(x, y -= h * 1.2, "�༶");

	//y = winheight/2;
	if (textbox(GenUIID(0), x, y -= h * 1.8, w, h, buff[1], 1024))
	{
		//double value; sscanf(numstr, "%lf", &value);
		//sprintf(newnum, "Represented value is: %.20f", value);
	}
	SetPenColor("Gray");
	drawLabel(x, y -= h * 1.2, "רҵ");
	button(GenUIID(0), 0, 0, 0, 0, "���");
	*/
}

void StudentUIDrawRmUI()
{
	double x = TextStringWidth("�����γ���Ϣ") + 1;
	double y = 6.0;
	double w = 7;
	double h = GetFontHeight() + 0.4;
	static char buff[][1024] = { "", ""};
//	char label[][1024] = { "ѧ��(8λ����):", "����:", "�༶(9λ����):", "רҵ:", "�Ա�(��:M Ů:W):" };
	unsigned tempId = 0;
	if (button(GenUIID(0), x + w / 2, y -= h * 1.2 + h * 0.7, w / 4, h, "ͨ��ѧ������ɾ��"))
	{
		ReadFileToDataSystem();
		RemoveStudentRecord(RemoveStudentByName, buff[0]);
		//��ʾ���
		WriteFileFromStuList("../DataSystem/Data/StudentTable.txt", &dataSystem.m_studentTable, "w");
		ReadFileToEditor("../DataSystem/Data/StudentTable.txt", &studentUI.m_text, &studentUI.m_edit);
		setStuUIVisible(textStu);
		studentUI.m_removeRecordUIVisible = 0;
	}
	SetPenColor("Brown");
	drawLabel(x - h / 2 - TextStringWidth("��") , (y -= h * 1.2) + h * 0.7 - 0.2, "����������");
	if (textbox(GenUIID(0), x + 0.8, y, w, h, buff[0], 1024))
		;
	if (button(GenUIID(0), x + w / 2, y -= h * 1.2 + h * 0.7, w / 4, h, "ͨ��ѧ��ѧ��ɾ��"))
	{
		ReadFileToDataSystem();
		sscanf(buff[1], "%u", &tempId);
		RemoveStudentRecord(RemoveStudentById, &tempId);
		//��ʾ���
		WriteFileFromStuList("../DataSystem/Data/StudentTable.txt", &dataSystem.m_studentTable, "w");
		ReadFileToEditor("../DataSystem/Data/StudentTable.txt", &studentUI.m_text, &studentUI.m_edit);
		setStuUIVisible(textStu);
		studentUI.m_removeRecordUIVisible = 0;
	}
	SetPenColor("Brown");
	drawLabel(x - h / 2 - TextStringWidth("��"), (y -= h * 1.2) + h * 0.7 - 0.2, "������ѧ��");
	if (textbox(GenUIID(0), x + 0.8, y, w, h, buff[1], 1024))
		;
}

void StudentUIDrawMvUI()
{
	double x = TextStringWidth("�����γ���Ϣ") + 1;
	double y = 6.0;
	double w = 7;
	double h = GetFontHeight() + 0.4;
	static char buff[][1024] = { "", "", "", "", "", "" };
	char label[][1024] = { "ԭʼѧ��:", "��ѧ��(8λ����)", "����", "�༶(9λ����)", "רҵ", "�Ա�"};
	int i = 0;
	unsigned oldId = 0;
	for (; i != 6; ++i)
	{
		SetPenColor("Brown");
		drawLabel(x - h / 2 - TextStringWidth("��"), (y -= h * 1.2) + h * 0.7, label[i]);
		if (textbox(GenUIID(i), x + 0.8, y, w, h, buff[i], 1024))
			;
	}
	if (button(GenUIID(0), x + w / 2, y -= h * 1.2 + h * 0.7, w / 2, h, "�޸�"))
	{
		Student temp;
		temp.m_name = malloc(1024);
		temp.m_major = malloc(1024);
		sscanf(buff[0], "%u", &oldId);
		sscanf(buff[1], "%u", &temp.m_id);
		sscanf(buff[2], "%s", temp.m_name);
		sscanf(buff[3], "%u", &temp.m_class);
		sscanf(buff[4], "%s", temp.m_major);
		sscanf(buff[5], "%c", &temp.m_sex);
		ReadFileToDataSystem();
		ModifyStudentRecord(ModifyStudentById, &oldId, &temp);
		free(temp.m_name);
		free(temp.m_major);
		studentUI.m_editVisible = 1;
		WriteFileFromStuList("../DataSystem/Data/StudentTable.txt", &dataSystem.m_studentTable, "w");
		ReadFileToEditor("../DataSystem/Data/StudentTable.txt", &studentUI.m_text, &studentUI.m_edit);
		studentUI.m_mvUIVisible = 0;
	}
}

void StudentUIDrawSetUI()
{
	double x = TextStringWidth("�����γ���Ϣ") + 1;
	double y = 6.0;
	double w = 7;
	double h = GetFontHeight() + 0.4;
	static char buff[][1024] = { "", "", ""};
	char label[][1024] = { "ѧ��(8λ����):", "�γ̺�", "����"};
	int i = 0;
	unsigned uid = 0;
	char cId[1024] = { 0 };
	double scoure = 0.0;
	for (; i != 3; ++i)
	{
		SetPenColor("Brown");
		drawLabel(x - h / 2 - TextStringWidth("��"), (y -= h * 1.2) + h * 0.7, label[i]);
		if (textbox(GenUIID(i), x + 0.8, y, w, h, buff[i], 1024))
			;
	}
	if (button(GenUIID(0), x + w / 2, y -= h * 1.2 + h * 0.7, w / 2, h, "����"))
	{
		sscanf(buff[0], "%u", &uid);
		sscanf(buff[1], "%s", &cId);
		sscanf(buff[2], "%lf", &scoure);
		ReadFileToDataSystem();
		AddOptCourseRecord(uid, cId, scoure);
		studentUI.m_editVisible = 1;
		WriteFileFromOptCourseList("../DataSystem/Data/OptCourseTable.txt", &dataSystem.m_optCourseTable, "w");
		ReadFileToEditor("../DataSystem/Data/OptCourseTable.txt", &studentUI.m_text, &studentUI.m_edit);
		studentUI.m_setUIVisible = 0;
	}
}
