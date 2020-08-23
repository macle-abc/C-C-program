#include "SearchUI.h"

extern DataSystem searchResult;
extern DataSystem dataSystem;
SearchUI searchUI;

void InitSearchUI()
{
	AllSearchUIClose();
	InitDataSystem(&searchResult);
	mystring_init(&searchUI.m_textData);
	mystring_init(&searchUI.m_editor.m_srcData);
}

void AllSearchUIClose()
{
	searchUI.m_courseUIVisible = 0;
	searchUI.m_collectUIVisible = 0;
	searchUI.m_scoreUIVisible = 0;
	searchUI.m_studentUIVisible = 0;
	searchUI.m_editorUIVisible = 0;
}

void SetSearchMemberUIVisible(whichSea which)
{
	switch (which)
	{
	case courseSearch:
		searchUI.m_courseUIVisible = 1;
		break;
	case collectSearch:
		searchUI.m_collectUIVisible = 1;
		break;
	case scoreSearch:
		searchUI.m_scoreUIVisible = 1;
		break;
	case studentSearch:
		searchUI.m_studentUIVisible = 1;
		break;
	case editorSearch:
		searchUI.m_editorUIVisible = 1;
		break;
	default:
		break;
	}
}

void SearchUIDisplay()
{
	if (searchUI.m_courseUIVisible)
		SearchCourseUIDisplay();
	if (searchUI.m_collectUIVisible)
		SearchCollectUIDisplay();
	if (searchUI.m_scoreUIVisible)
		SearchScoreUIDisplay();
	if (searchUI.m_studentUIVisible)
		SearchStudentUIDisplay();
	if (searchUI.m_editorUIVisible)
		SearchEditorUIDisplay();
}

void SearchStudentUIDisplay()
{
	double x = TextStringWidth("�����γ���Ϣ") + 1;
	double y = 6.5;
	double w = 7.0;
	double h = GetFontHeight() + 0.2;
	static char buff[][1024] = { "", "", "", "" };
	//	char label[][1024] = { "ѧ��(8λ����):", "����:", "�༶(9λ����):", "רҵ:", "�Ա�(��:M Ů:W):" };
	char major[1024] = { 0 };
	char name[1024] = { 0 };
	unsigned id = 0;
	unsigned class = 0;
	if (button(GenUIID(0), x + w / 2, y -= h * 1.2 + h * 0.7, w / 4, h, "ͨ���༶�Ų�ѯ"))
	{
		ReadFileToDataSystem();
		CHECK_AND_PROMPT("�༶�ŷǷ�!ӦΪ9λ����!", buff[0], 9);
		/*if (!check(buff[0], 9))
		{
			MessageBox(NULL, "�༶�ŷǷ�!ӦΪ9λ����!", "�������!", MB_ICONHAND);
			return;
		}*/
		sscanf(buff[0], "%u", &class);
		//��ʾ���
		FindAndSave(SearchStudentByClass, student, &class);
		WriteFileFromStuList("../DataSystem/Data/stuResult.txt", &searchResult.m_studentTable, "w");
		ReadFileToEditor("../DataSystem/Data/stuResult.txt", &searchUI.m_textData, &searchUI.m_editor);
		searchUI.m_editorUIVisible = 1;
		searchUI.m_studentUIVisible = 0;
	}
	SetPenColor("Brown");
	drawLabel(x - h / 2 - TextStringWidth("��"), (y -= h * 1.2) + h * 0.7 - 0.2, "������༶��");
	if (textbox(GenUIID(0), x + 0.8, y, w, h, buff[0], 1024))
		;
	if (button(GenUIID(0), x + w / 2, y -= h * 1.2 + h * 0.7, w / 4, h, "ͨ��ѧ��������ѯ"))
	{
		ReadFileToDataSystem();
		CHECK_AND_PROMPT("��������!��Ӧ����10���ַ�", buff[1], 10);
		/*if (!check(buff[1], 10))
		{
			MessageBox(NULL, "��������!��Ӧ����10���ַ�", "�������!", MB_ICONHAND);
			return;
		}*/
		sscanf(buff[1], "%s", name);
		//��ʾ���
		FindAndSave(SearchStudentByName, student, name);
		WriteFileFromStuList("../DataSystem/Data/stuResult.txt", &searchResult.m_studentTable, "w");
		ReadFileToEditor("../DataSystem/Data/stuResult.txt", &searchUI.m_textData, &searchUI.m_editor);
		searchUI.m_editorUIVisible = 1;
		searchUI.m_studentUIVisible = 0;
	}
	SetPenColor("Brown");
	drawLabel(x - h / 2 - TextStringWidth("��"), (y -= h * 1.2) + h * 0.7 - 0.2, "������ѧ������");
	if (textbox(GenUIID(0), x + 0.8, y, w, h, buff[1], 1024))
		;
	if (button(GenUIID(0), x + w / 2, y -= h * 1.2 + h * 0.7, w / 4, h, "ͨ��ѧ��ѧ�Ų�ѯ"))
	{
		ReadFileToDataSystem();
		CHECK_AND_PROMPT("ѧ�ŷǷ�!ӦΪ8λ����", buff[2], 8);
	/*	if (!check(buff[2], 8))
		{
			MessageBox(NULL, "ѧ�ŷǷ�!ӦΪ8λ����!", "�������!", MB_ICONHAND);
			return;
		}*/
		sscanf(buff[2], "%u", &id);
		//��ʾ���
		FindAndSave(SearchStudentById, student, &id);
		WriteFileFromStuList("../DataSystem/Data/stuResult.txt", &searchResult.m_studentTable, "w");
		ReadFileToEditor("../DataSystem/Data/stuResult.txt", &searchUI.m_textData, &searchUI.m_editor);
		searchUI.m_editorUIVisible = 1;
		searchUI.m_studentUIVisible = 0;
	}
	SetPenColor("Brown");
	drawLabel(x - h / 2 - TextStringWidth("��"), (y -= h * 1.2) + h * 0.7 - 0.2, "������ѧ��ѧ��");
	if (textbox(GenUIID(0), x + 0.8, y, w, h, buff[2], 1024))
		;
	if (button(GenUIID(0), x + w / 2, y -= h * 1.2 + h * 0.7, w / 4, h, "ͨ��רҵ��ѯ"))
	{
		ReadFileToDataSystem();
		CHECK_AND_PROMPT("רҵ����!��Ӧ����10���ַ�", buff[3], 10);
	/*	if (!check(buff[3], 10))
		{
			MessageBox(NULL, "רҵ����!��Ӧ����10���ַ�", "�������!", MB_ICONHAND);
			return;
		}*/
		sscanf(buff[3], "%s", major);
		//��ʾ���
		FindAndSave(SearchStudentByMajor,  student, major);
		WriteFileFromStuList("../DataSystem/Data/stuResult.txt", &searchResult.m_studentTable, "w");
		ReadFileToEditor("../DataSystem/Data/stuResult.txt", &searchUI.m_textData, &searchUI.m_editor);
		searchUI.m_editorUIVisible = 1;
		searchUI.m_studentUIVisible = 0;
	}
	SetPenColor("Brown");
	drawLabel(x - h / 2 - TextStringWidth("��"), (y -= h * 1.2) + h * 0.7 - 0.2, "������רҵ");
	if (textbox(GenUIID(0), x + 0.8, y, w, h, buff[3], 1024))
		;
}

void SearchCourseUIDisplay()
{
	double x = TextStringWidth("�����γ���Ϣ") + 1;
	double y = 6.5;
	double w = 7.0;
	double h = GetFontHeight() + 0.2;
	static char buff[][1024] = { "", "", ""};
	char cId[1024] = { 0 };
	char cName[1024] = { 0 };
	char cTea[1024] = { 0 };
	if (button(GenUIID(0), x + w / 2, y -= h * 1.2 + h * 0.7, w / 4, h, "ͨ���γ�����ѯ"))
	{
		ReadFileToDataSystem();
		CHECK_AND_PROMPT("�γ�������!��Ӧ����10���ַ�", buff[0], 10);
		//if (!check(buff[0], 10))
		//{
		//	MessageBox(NULL, "�γ�������!��Ӧ����10���ַ�", "�������!", MB_ICONHAND);
		//	return;
		//}
		sscanf(buff[0], "%s", cName);
		//��ʾ���
		FindAndSave(SearchCourseByName, course, cName);
		WriteFileFromCouList("../DataSystem/Data/couResult.txt", &searchResult.m_courseTable, "w");
		ReadFileToEditor("../DataSystem/Data/couResult.txt", &searchUI.m_textData, &searchUI.m_editor);
		searchUI.m_editorUIVisible = 1;
		searchUI.m_courseUIVisible = 0;
	}
	SetPenColor("Brown");
	drawLabel(x - h / 2 - TextStringWidth("��"), (y -= h * 1.2) + h * 0.7 - 0.2, "������γ���");
	if (textbox(GenUIID(0), x + 0.8, y, w, h, buff[0], 1024))
		;
	if (button(GenUIID(0), x + w / 2, y -= h * 1.2 + h * 0.7, w / 4, h, "ͨ���γ̺Ų�ѯ"))
	{
		ReadFileToDataSystem();
		CHECK_AND_PROMPT("�γ̺Ź���!��Ӧ����10���ַ�", buff[1], 10);
	/*	if (!check(buff[1], 10))
		{
			MessageBox(NULL, "�γ̺Ź���!��Ӧ����10���ַ�", "�������!", MB_ICONHAND);
			return;
		}*/
		sscanf(buff[1], "%s", cId);
		//��ʾ���
		FindAndSave(SearchCoureById, course, cName);
		WriteFileFromCouList("../DataSystem/Data/couResult.txt", &searchResult.m_courseTable, "w");
		ReadFileToEditor("../DataSystem/Data/couResult.txt", &searchUI.m_textData, &searchUI.m_editor);
		searchUI.m_editorUIVisible = 1;
		searchUI.m_courseUIVisible = 0;
	}
	SetPenColor("Brown");
	drawLabel(x - h / 2 - TextStringWidth("��"), (y -= h * 1.2) + h * 0.7 - 0.2, "������γ̺�");
	if (textbox(GenUIID(0), x + 0.8, y, w, h, buff[1], 1024))
		;
	if (button(GenUIID(0), x + w / 2, y -= h * 1.2 + h * 0.7, w / 4, h, "ͨ����ʦ����ѯ"))
	{
		ReadFileToDataSystem();
		CHECK_AND_PROMPT("��ʦ������!��Ӧ����10���ַ�", buff[2], 10);
	/*	if (!check(buff[2], 10))
		{
			MessageBox(NULL, "��ʦ������!��Ӧ����10���ַ�", "�������!", MB_ICONHAND);
			return;
		}*/
		sscanf(buff[2], "%s", cTea);
		//��ʾ���
		FindAndSave(SearchCourseByTeacher, course, cName);
		WriteFileFromCouList("../DataSystem/Data/couResult.txt", &searchResult.m_courseTable, "w");
		ReadFileToEditor("../DataSystem/Data/couResult.txt", &searchUI.m_textData, &searchUI.m_editor);
		searchUI.m_editorUIVisible = 1;
		searchUI.m_courseUIVisible = 0;
	}
	SetPenColor("Brown");
	drawLabel(x - h / 2 - TextStringWidth("��"), (y -= h * 1.2) + h * 0.7 - 0.2, "�������ʦ��");
	if (textbox(GenUIID(0), x + 0.8, y, w, h, buff[2], 1024))
		;
}

void SearchScoreUIDisplay()
{
	double x = TextStringWidth("�����γ���Ϣ") + 1;
	double y = 6.5;
	double w = 7.0;
	double h = GetFontHeight() + 0.2;
	static char buff[][1024] = { "", "", "" };
	char cId[1024] = { 0 };
	unsigned sid = 0;
	double score = 0.0;
	if (button(GenUIID(0), x + w / 2, y -= h * 1.2 + h * 0.7, w / 4, h, "ͨ���γ�����ѯ"))
	{
		ReadFileToDataSystem();
		CHECK_AND_PROMPT("�γ�������!��Ӧ����10���ַ�", buff[0], 10);
	/*	if (!check(buff[0], 10))
		{
			MessageBox(NULL, "�γ�������!��Ӧ����10���ַ�", "�������!", MB_ICONHAND);
			return;
		}*/
		sscanf(buff[0], "%s", cId);
		//��ʾ���
		FindAndSave(SearchOptCourseByCourseId, optCourse, cId);
		WriteFileFromOptCourseList("../DataSystem/Data/optResult.txt", &searchResult.m_optCourseTable, "w");
		ReadFileToEditor("../DataSystem/Data/optResult.txt", &searchUI.m_textData, &searchUI.m_editor);
		searchUI.m_editorUIVisible = 1;
		searchUI.m_scoreUIVisible = 0;
	}
	SetPenColor("Brown");
	drawLabel(x - h / 2 - TextStringWidth("��"), (y -= h * 1.2) + h * 0.7 - 0.2, "������γ���");
	if (textbox(GenUIID(0), x + 0.8, y, w, h, buff[0], 1024))
		;
	if (button(GenUIID(0), x + w / 2, y -= h * 1.2 + h * 0.7, w / 4, h, "ͨ��ѧ�Ų�ѯ"))
	{
		ReadFileToDataSystem();
		CHECK_AND_PROMPT("ѧ�ŷǷ�!ӦΪ8λ����", buff[1], 8);
	/*	if (!check(buff[1], 8))
		{
			MessageBox(NULL, "ѧ�ŷǷ�!ӦΪ8λ����", "�������!", MB_ICONHAND);
			return;
		}*/
		sscanf(buff[1], "%u", &sid);
		//��ʾ���
		FindAndSave(SearchOptCorseByStudentId, optCourse, &sid);
		WriteFileFromOptCourseList("../DataSystem/Data/optResult.txt", &searchResult.m_optCourseTable, "w");
		ReadFileToEditor("../DataSystem/Data/optResult.txt", &searchUI.m_textData, &searchUI.m_editor);
		searchUI.m_editorUIVisible = 1;
		searchUI.m_scoreUIVisible = 0;
	}
	SetPenColor("Brown");
	drawLabel(x - h / 2 - TextStringWidth("��"), (y -= h * 1.2) + h * 0.7 - 0.2, "������ѧ��");
	if (textbox(GenUIID(0), x + 0.8, y, w, h, buff[1], 1024))
		;
	if (button(GenUIID(0), x + w / 2, y -= h * 1.2 + h * 0.7, w / 4, h, "ͨ��������ѯ"))
	{
		ReadFileToDataSystem();
		CHECK_AND_PROMPT("�����Ƿ�!ӦΪ0.00-100.00֮��", buff[2], 7);
	/*	if (!check(buff[2], 7))
		{
			MessageBox(NULL, "�����Ƿ�!ӦΪ0.00��100.00֮��", "�������!", MB_ICONHAND);
			return;
		}*/
		sscanf(buff[2], "%lf", &score);
		//��ʾ���
		FindAndSave(SearchOptCourseByScore, score, &score);
		WriteFileFromOptCourseList("../DataSystem/Data/optResult.txt", &searchResult.m_optCourseTable, "w");
		ReadFileToEditor("../DataSystem/Data/optResult.txt", &searchUI.m_textData, &searchUI.m_editor);
		searchUI.m_editorUIVisible = 1;
		searchUI.m_scoreUIVisible = 0;
	}
	SetPenColor("Brown");
	drawLabel(x - h / 2 - TextStringWidth("��"), (y -= h * 1.2) + h * 0.7 - 0.2, "���������");
	if (textbox(GenUIID(0), x + 0.8, y, w, h, buff[2], 1024))
		;
}

void SearchCollectUIDisplay()
{	
	CollectData();
	PrintfDataSystemToString(&dataSystem, &searchUI.m_editor.m_srcData);
	if (searchUI.m_editor.m_srcData.size(&searchUI.m_editor.m_srcData) == 0)
	{
		fprintf(stderr, "No data!");
		error;
		return;
	}
	SplitLine(searchUI.m_editor.m_srcData.c_str(&searchUI.m_editor.m_srcData), &searchUI.m_editor.m_formateData, &searchUI.m_editor.m_lines);
	searchUI.m_collectUIVisible = 0;
	searchUI.m_editorUIVisible = 1;
}

void SearchEditorUIDisplay()
{
	DrawEditor(TextStringWidth("�����γ���Ϣ") + 1, 1.0, 7.5, 5.5, &searchUI.m_editor);
}
