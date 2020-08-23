#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "Employee.h"
#include "SalaryManagementSystem.h"

using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::string;
using std::ios;
using std::ofstream;
using std::ifstream;
using std::endl;

SalaryManagementSystem::SalaryManagementSystem(string name, string sex, string ID, string Tel, string department, string salary) : person(name, sex, ID, Tel, department, salary)
{
	cout << "******************��ӭ����ְ�����ʹ���ϵͳ**********************\n"
		<< "*1).����ְ����Ϣ				2).��ѯְ����Ϣ*\n"
		<< "*3).�޸�ְ����Ϣ				4).ɾ��ְ����Ϣ*\n"
		<< "*5).���ݹ��ʶ�ְ����Ϣ�������		        6).ɾ��ȫ����Ϣ*\n"
		<< "*7).��������ҵ�ƽ������			8).�˳�����ϵͳ*\n"
		<< "****************************************************************\n"
		<< "����������ѡ��: ";

	char select[80] = { 0 };
	cin.getline(select, 80);
	while (select[1] != '\0' || select[0] < '1' || select[0] > '8')//��������Ƿ���ȷ
	{
		cout << "�������!����������: ";
		cin.getline(select, 80);
	}
	while (select[0] > '0' && select[0] < '8')
	{
		switch (select[0])
		{
		case '1':
			person.InputToFile();
			break;
		case '2':
			person.Query();
			break;
		case '3':
			person.ChangeInfo();
			break;
		case '4':
			person.DeleteInfo();
			break;
		case '5':
			person.SortAndOutput();
			break;
		case '6':
			person.DeleteAllInfo();
			break;
		case '7':
			person.StatisticAndAverage();
			break;
		default:
			break;
		}
		cout << "****************************************************************\n"
			<< "*1).����ְ����Ϣ				2).��ѯְ����Ϣ*\n"
			<< "*3).�޸�ְ����Ϣ				4).ɾ��ְ����Ϣ*\n"
			<< "*5).���ݹ��ʶ�ְ����Ϣ�������		        6).ɾ��ȫ����Ϣ*\n"
			<< "*7).��������ҵ�ƽ������			8).�˳�����ϵͳ*\n"
			<< "****************************************************************\n"
			<< "����������ѡ��: ";
		cin.getline(select, 80);
		while (select[1] != '\0' || select[0] < '1' || select[0] > '8')
		{
			cout << "�������!����������: ";
			cin.getline(select, 80);
		}
	}
	cout << "�ټ�!(ְ�����ʹ���ϵͳ����3���ֺ�رգ�)";
	Sleep(3000);//�ӳ��˳�ʱ��
}