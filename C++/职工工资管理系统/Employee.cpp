#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include "Employee.h"

using std::stringstream;
using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::string;
using std::ios;
using std::ofstream;
using std::ifstream;
using std::endl;

//****************�ж��ַ���str�ܷ�Ϊ���Ż�绰��****************//
inline bool Employee::AsIdOrTel(string str)//�ж��ַ���str�ܷ�Ϊ���Ż�绰����
{
	for (int i = 0; i < str.size(); ++i)
		if (str[i] < '0' || str[i] > '9')
			return false;
	return true;
}

//****************�ж��ַ���str�ܷ���Ϊ������****************//
inline bool Employee::AsSalary(string str)
{
	int numPointSign = 0;
	if (str[0] == '-' || str[0] == '.' || str[0] < '0' || str[0] > '9')
		return false;
	for (int i = 1; i < str.size(); ++i)
	{
		if (str[i] == '.')
			++numPointSign;
		else if (str[i] < '0' || str[i] > '9')
			return false;
		if (numPointSign > 1)
			return false;
	}
	return true;
}

//****************�������������****************//
inline istream & operator >> (istream & is, Employee & e)
{
	e.rsetName();
	e.rsetSex();
	e.rsetDepartment();
	e.rsetID();
	e.rsetSalary();
	e.rsetTel();
	return is;
}

//****************������������****************//
inline ostream & operator << (ostream & os, Employee & e)
{
	os << "����: " << e.m_Name
		<< "	�Ա�: " << e.m_Sex << "\n"
		<< "����: " << e.m_Department
		<< "	����: " << e.m_ID << "\n"
		<< "����: " << e.m_Salary
		<< "	�绰: " << e.m_Tel << endl;
	return os;
}

//****************����ְ������****************//
inline void Employee::rsetName()
{
	cout << "������ְ������: ";
	getline(cin, m_Name);
}

//****************����ְ���Ա�****************//
inline void Employee::rsetSex()
{
	cout << "������ְ���Ա�: ";
	getline(cin, m_Sex);
}

//****************����ְ������****************//
inline void Employee::rsetID()
{
	cout << "������ְ������(����Ϊ6λ����): ";
	getline(cin, m_ID);
	while (!AsIdOrTel(m_ID) || m_ID.size() != (unsigned)6)//�ж������Ƿ���ȷ
	{
		cout << "�������!����������: ";
		getline(cin, m_ID);
	}
}

//****************����ְ���绰****************//
inline void Employee::rsetTel()
{
	cout << "������ְ���绰: ";
	getline(cin, m_Tel);
	while (!AsIdOrTel(m_Tel))
	{
		cout << "�������!�绰��������!����������: ";
		getline(cin, m_Tel);
	}
}

//****************����ְ������****************//
inline void Employee::rsetDepartment()
{
	cout << "������ְ������: ";
	getline(cin, m_Department);
}

//****************����ְ������****************//
inline void Employee::rsetSalary()
{
	cout << "������ְ������: ";
	getline(cin, m_Salary);
	while (!AsSalary(m_Salary))
	{
		cout << "�������!������������!����������: ";
		getline(cin, m_Salary);
	}
}

//*****************�ж��������Ƿ����str����******************//
inline int Node::isRepeat(struct Node * p, string str)
{
	int flag = 0;
	if (p->m_department == str)
		flag = 1;
	else
	{
		while (p->next)
		{
			p = p->next;
			if (p->m_department == str)
			{
				flag = 1;
				break;
			}
		}
		if (p->m_department == str)
		{
			flag = 1;
		}
	}
	return flag;
}

//*****************����a b����******************//
inline void Employee::swap(Employee * a, Employee * b) {
	Employee * temp = new Employee;
	temp->m_Department = a->m_Department;
	temp->m_ID = a->m_ID;
	temp->m_Name = a->m_Name;
	temp->m_Salary = a->m_Salary;
	temp->m_Sex = a->m_Sex;
	temp->m_Tel = a->m_Tel;
	a->m_Department = b->m_Department;
	a->m_ID = b->m_ID;
	a->m_Name = b->m_Name;
	a->m_Salary = b->m_Salary;
	a->m_Sex = b->m_Sex;
	a->m_Tel = b->m_Tel;
	b->m_Department = temp->m_Department;
	b->m_ID = temp->m_ID;
	b->m_Name = temp->m_Name;
	b->m_Salary = temp->m_Salary;
	b->m_Sex = temp->m_Sex;
	b->m_Tel = temp->m_Tel;
}

//*****************������******************//
inline Employee * Employee::partion(Employee *pBegin, Employee *pEnd) {
	if (pBegin == pEnd || pBegin->next == pEnd)    return pBegin;
	string key = pBegin->m_Salary;    //ѡ��pBegin��Ϊ��׼Ԫ��
	Employee *p = pBegin, *q = pBegin;
	double keynumber = 0.0;
	double qsalary = 0.0;
	stringstream translate;
	while (q != pEnd) {   //��pBegin��ʼ������һ�α���
		translate << q->m_Salary;
		translate >> qsalary;
		translate.clear();
		translate << key;
		translate >> keynumber;
		translate.clear();
		if (qsalary > keynumber) {
			p = p->next;
			swap(p, q);
		}
		q = q->next;
	}
	swap(p, pBegin);
	return p;
}

//*****************�����������******************//
inline void Employee::quick_sort(Employee *pBegin, Employee *pEnd) {
	if (pBegin == pEnd || pBegin->next == pEnd)    return;
	Employee *mid = partion(pBegin, pEnd);
	quick_sort(pBegin, mid);
	quick_sort(mid->next, pEnd);
}

//*****************��������******************//
inline Employee* Employee::sortList(Employee* head) {
	if (head == NULL || head->next == NULL)    return head;
	quick_sort(head, NULL);
	return head;
}

//****************���ݹ��ž�ȷ����ְ����Ϣ******************//
void Employee::QueryByID()
{
	ifstream ifile;
	int finish = 0;
	string ID;
	cout << "�������ѯ��ְ������(����Ϊ6λ����): ";
	getline(cin, ID);
	while (!AsIdOrTel(ID) || ID.size() != (unsigned)6)//�ж������Ƿ���ȷ
	{
		cout << "�������!����������: ";
		getline(cin, ID);
	}
	ifile.open("ְ����Ϣ��.txt", ios::in);
	char name[80];
	char department[80];
	char sex[80];
	char Id[80];
	char salary[80];
	char Tel[80];
	//****************��ȡ�ļ���Ϣ����****************//
	while (ifile.peek() != EOF)
	{
		ifile.getline(name, 80);
		ifile.getline(sex, 80);
		ifile.getline(department, 80);
		ifile.getline(Id, 80);
		ifile.getline(salary, 80);
		ifile.getline(Tel, 80);
		this->m_Name = name;
		this->m_Sex = sex;
		this->m_Department = department;
		this->m_ID = Id;
		this->m_Salary = salary;
		this->m_Tel = Tel;
		if (ID == this->m_ID)//������ͬ�����
		{
			++finish;
			cout << *this;
			break;
		}
	}
	if (!finish)
		cout << "��ѯʧ��!���ܸù���û��¼��!" << endl;
	ifile.close();
	cout << "�������ز�ѯ�˵�" << endl;
}

//****************��������ģ������ְ����Ϣ******************//
void Employee::QueryByName()
{
	ifstream ifile;
	int finish = 0;
	string name;
	cout << "������ְ������: ";
	getline(cin, name);
	ifile.open("ְ����Ϣ��.txt", ios::in);
	char tname[80];
	char department[80];
	char sex[80];
	char Id[80];
	char salary[80];
	char Tel[80];
	//****************��ȡ�ļ���Ϣ����****************//
	while (ifile.peek() != EOF)
	{
		ifile.getline(tname, 80);
		ifile.getline(sex, 80);
		ifile.getline(department, 80);
		ifile.getline(Id, 80);
		ifile.getline(salary, 80);
		ifile.getline(Tel, 80);
		this->m_Name = tname;
		this->m_Sex = sex;
		this->m_Department = department;
		this->m_ID = Id;
		this->m_Salary = salary;
		this->m_Tel = Tel;
		if (this->m_Name.find(name) != string::npos)//������ͬ�����ؼ��������
		{
			++finish;
			cout << *this << endl;
		}
	}
	if (!finish)
		cout << "��ѯʧ��!���ܸ�����û��¼��!" << endl;
	ifile.close();
	cout << "�������ز�ѯ�˵�" << endl;
}

//*****************���ݲ���ģ������ְ����Ϣ******************//
void Employee::QueryByDepartment()
{
	ifstream ifile;
	int finish = 0;
	string department;
	cout << "������ְ������: ";
	getline(cin, department);
	ifile.open("ְ����Ϣ��.txt", ios::in);
	char name[80];
	char tdepartment[80];
	char sex[80];
	char Id[80];
	char salary[80];
	char Tel[80];
	//****************��ȡ�ļ���Ϣ����****************//
	while (ifile.peek() != EOF)
	{
		ifile.getline(name, 80);
		ifile.getline(sex, 80);
		ifile.getline(tdepartment, 80);
		ifile.getline(Id, 80);
		ifile.getline(salary, 80);
		ifile.getline(Tel, 80);
		this->m_Name = name;
		this->m_Sex = sex;
		this->m_Department = tdepartment;
		this->m_ID = Id;
		this->m_Salary = salary;
		this->m_Tel = Tel;
		if (this->m_Department.find(department) != string::npos)//���ڿ�����ͬ�ؼ��������
		{
			++finish;
			cout << *this << endl;
		}
	}
	if (!finish)
		cout << "��ѯʧ��!���ܸÿ���û��¼��!" << endl;
	ifile.close();
	cout << "�������ز�ѯ�˵�" << endl;
}

//*****************��ְ����Ϣд���ļ�******************//
void Employee::InputToFile()
{
	ofstream ofile;
	string select = "y";
	ofile.open("ְ����Ϣ��.txt", ios::app);
	cout << "��ʼ����ְ����Ϣ!" << endl;
	ifstream ifile;
	Employee * pte = new Employee;
	char name[80];	
	char tdepartment[80];
	char sex[80];
	char Id[80];
	char salary[80];
	char Tel[80];
	while (toupper(select[0]) == 'Y')
	{
		trans : cin >> *this;
		Employee * head;
		Employee * temp = new Employee;
		head = temp;
		//****************��ȡ�ļ���Ϣ����****************//
		ifile.open("ְ����Ϣ��.txt", ios::in);
		ifile.getline(name, 80);
		ifile.getline(sex, 80);
		ifile.getline(tdepartment, 80);
		ifile.getline(Id, 80);
		ifile.getline(salary, 80);
		ifile.getline(Tel, 80);
		temp->m_Name = name;
		temp->m_Sex = sex;
		temp->m_Department = tdepartment;
		temp->m_ID = Id;
		temp->m_Salary = salary;
		temp->m_Tel = Tel;
		while (ifile.peek() != EOF)
		{
			temp->next = new Employee;
			temp = temp->next;
			ifile.getline(name, 80);
			ifile.getline(sex, 80);
			ifile.getline(tdepartment, 80);
			ifile.getline(Id, 80);
			ifile.getline(salary, 80);
			ifile.getline(Tel, 80);
			temp->m_Name = name;
			temp->m_Sex = sex;
			temp->m_Department = tdepartment;
			temp->m_ID = Id;
			temp->m_Salary = salary;
			temp->m_Tel = Tel;
		}
		temp->next = nullptr;
		ifile.close();
		temp = head;
		//****************�ж��Ƿ������ͬ���ţ���֤���빤��Ψһ****************//
		while (temp->next)
		{
			if (temp->m_ID == this->m_ID)
			{
				cout << "������ͬ����,����������ְ����Ϣ: " << endl;
				goto trans;
				}
			temp = temp->next;
		}
		if (temp->m_ID == this->m_ID)
		{
			cout << "������ͬ����,����������ְ����Ϣ: " << endl;
			
			goto trans;
		}

		//*****************д���ļ�����*****************//
		ofile << this->m_Name << endl;
		ofile << this->m_Sex << endl;
		ofile << this->m_Department << endl;
		ofile << this->m_ID << endl;
		ofile << this->m_Salary << endl;
		ofile << this->m_Tel << endl;
		cout << "�Ƿ����?(��������y��Y,��������n��N) ";
		getline(cin, select);
		//****************������*****************//
		while (select.size() != (unsigned)1 || (select[0] != 'n' && select[0] != 'N' && select[0] != 'y' && select[0] != 'Y'))
		{
			cout << "�������!����������: ";
			getline(cin, select);
		}
	}
	ofile.close();
	cout << "�����������˵�" << endl << endl;
}

//*****************���Ҳ˵�******************//
void Employee::Query()
{
	cout << "1).����ְ�����ž�ȷ����ְ����Ϣ\n"
		<< "2).����ְ������ģ������ְ����Ϣ\n"
		<< "3).����ְ������ģ������ְ����Ϣ\n"
		<< "4).�������˵�" << endl;
	char select[80] = { 0 };
	cout << "����������ѡ��: ";
	cin.getline(select, 80);
	//*****************������****************//
	while (select[1] != '\0' || select[0] < '1' || select[0] > '4')
	{
		cout << "�������!����������: ";
		cin.getline(select, 80);
	}
	while (select[0] > '0' && select[0] < '4')
	{
		switch (select[0])
		{
		case '1':
			QueryByID();
			break;
		case '2':
			QueryByName();
			break;
		case '3':
			QueryByDepartment();
			break;
		default:
			break;
		}
		cout << "\n1).����ְ�����ž�ȷ����ְ����Ϣ\n"
			<< "2).����ְ������ģ������ְ����Ϣ\n"
			<< "3).����ְ������ģ������ְ����Ϣ\n"
			<< "4).�������˵�" << endl;
		cout << "����������ѡ��: ";
		cin.getline(select, 80);
		while (select[1] != '\0' || select[0] < '1' || select[0] > '4')
		{
			cout << "�������!����������: ";
			cin.getline(select, 80);
		}
	}
	cout << "�����������˵�" << endl << endl;
}

//*****************ͨ����������ְ����Ϣ��ɾ��*****************//
void Employee::DeleteByName()
{
	ifstream ifile;
	ifile.open("ְ����Ϣ��.txt", ios::in);
	string Name;
	cout << "��������Ҫɾ����ְ������: ";
	getline(cin, Name);
	char name[80];
	char department[80];
	char sex[80];
	char Id[80];
	char salary[80];
	char Tel[80];
	int finish = 0;
	Employee * head;
	Employee * temp = new Employee;
	head = temp;
	//*****************��ȡ�ļ�����***************//
	ifile.getline(name, 80);
	ifile.getline(sex, 80);
	ifile.getline(department, 80);
	ifile.getline(Id, 80);
	ifile.getline(salary, 80);
	ifile.getline(Tel, 80);
	temp->m_Name = name;
	temp->m_Sex = sex;
	temp->m_Department = department;
	temp->m_ID = Id;
	temp->m_Salary = salary;
	temp->m_Tel = Tel;
	while (ifile.peek() != EOF)
	{
		temp->next = new Employee;
		temp = temp->next;
		ifile.getline(name, 80);
		ifile.getline(sex, 80);
		ifile.getline(department, 80);
		ifile.getline(Id, 80);
		ifile.getline(salary, 80);
		ifile.getline(Tel, 80);
		temp->m_Name = name;
		temp->m_Sex = sex;
		temp->m_Department = department;
		temp->m_ID = Id;
		temp->m_Salary = salary;
		temp->m_Tel = Tel;
	}
	temp->next = nullptr;
	temp = head;
	ifile.close();
	//*****************д���ļ�ǰ�ж��Ƿ�ɾ����Ϣ�Ƿ���Ч****************//
	if (temp->m_Department == "Null" || temp->m_Department == "")
	{
		cout << "û������ְ����Ϣ�޷�ɾ��!" << endl << "��������ɾ���˵�" << endl << endl;
		return;
	}
	int number = 0;//��¼���û������������ͬ��ְ����
	Employee * tempToSave = new Employee;//��¼��ͬ������ְ����Ϣ
	Employee * HeadTempSave = tempToSave;
	//*****************��¼��ͬ������ְ����Ϣ*****************//
	while (temp->next)
	{
		if (temp->m_Name == Name)
		{
			++number;
			*tempToSave = *temp;
			tempToSave->next = new Employee;
			tempToSave = tempToSave->next;
		}
		temp = temp->next;
	}
	if (temp->m_Name == Name)
	{
		++number;
		*tempToSave = *temp;
		tempToSave->next = new Employee;
		tempToSave = tempToSave->next;
	}
	tempToSave->next = nullptr;
	tempToSave = HeadTempSave;
	temp = head;
	//*****************�ж��û�����������Ƿ���Ч****************//
	if (number == 0)//�������û����������
		cout << "û�������������ְ����Ϣ!" << endl << "��������ɾ���˵�" << endl << endl;
	else if (number == 1)//������һ�����û������������ͬ��ְ��
	{
		//*****************д���ļ�ǰ�ж��Ƿ�ɾ����Ϣ�Ƿ���Ч****************//
		if (temp->m_Department == "Null" || temp->m_Department == "")
		{
			cout << "û������ְ����Ϣ�޷�ɾ��!" << endl << "��������ɾ���˵�" << endl << endl;
			return;
		}
		Employee * ptemp = nullptr;
		//*****************ɾ��ְ����Ϣ****************//
		if (temp->m_Name == Name)
		{
			head = temp->next;
			delete temp;
			++finish;
		}
		else
		{
			while (temp->next)
			{
				if (temp->next->m_Name == Name)
				{
					ptemp = temp->next;
					temp->next = temp->next->next;
					delete ptemp;
					++finish;
					break;
				}
				temp = temp->next;
			}
			if (temp->m_Name == Name)
			{
				temp->next = nullptr;
			}
		}
		temp = head;
		ofstream ofile;
		//*****************д���ļ�****************//
		ofile.open("ְ����Ϣ��.txt", ios::out);
		if (!finish)
		{
			cout << "û������ְ����Ϣ�޷�ɾ��!" << endl << "��������ɾ���˵�" << endl << endl;
			return;
		}
		if (!head)
		{
			cout << "��Ϣɾ���ɹ�!" << endl;
			cout << "��������ɾ���˵�" << endl << endl;
			return;
		}
		while (temp->next)
		{
			ofile << temp->m_Name << endl;
			ofile << temp->m_Sex << endl;
			ofile << temp->m_Department << endl;
			ofile << temp->m_ID << endl;
			ofile << temp->m_Salary << endl;
			ofile << temp->m_Tel << endl;
			temp = temp->next;
		}
		ofile << temp->m_Name << endl;
		ofile << temp->m_Sex << endl;
		ofile << temp->m_Department << endl;
		ofile << temp->m_ID << endl;
		ofile << temp->m_Salary << endl;
		ofile << temp->m_Tel << endl;
		ofile.close();
		cout << "��Ϣɾ���ɹ�!" << endl << "��������ɾ���˵�" << endl << endl;
	}
	else//���ڶ�����û������������ͬ��ְ��
	{
		cout << "����" << number << "����ͬ������ְ��!" << endl;
		//��ӡ��ͬ������ְ����Ϣ
		while (tempToSave->next)
		{
			cout << *tempToSave << endl;
			tempToSave = tempToSave->next;
		}
		tempToSave = HeadTempSave;
		cout <<	"1).ɾ��������ȫ��ְ����Ϣ\n2).���빤�ž�ȷɾ����������ְ����Ϣ" << endl;
		cout << "����������ѡ��: ";
		char select[80];
		string SelectId;
		cin.getline(select, 80);
		//*****************������****************//
		while (select[1] != '\0' || select[0] < '1' || select[0] > '2')
		{
			cout << "�������!����������: ";
			cin.getline(select, 80);
		}
		switch (select[0])
		{
			case '1':
			{
				//*****************д���ļ�ǰ�ж��Ƿ�ɾ����Ϣ�Ƿ���Ч****************//
				if (temp->m_Department == "Null" || temp->m_Department == "")
				{
					cout << "û������ְ����Ϣ�޷�ɾ��!" << endl << "��������ɾ���˵�" << endl << endl;
					return;
				}
				Employee * ptemp = new Employee;//����ɾ���������ְ����Ϣ
				Employee * HeadPtemp = ptemp;
				//*****************ɾ��ְ����Ϣ****************//
				while (temp->next)
				{
					if (temp->m_Name != Name)
					{
						++finish;
						*ptemp = *temp;
						ptemp->next = new Employee;
						ptemp = ptemp->next;
					}
					temp = temp->next;
				}
				if (temp->m_Name != Name)
				{
					++finish;
					*ptemp = *temp;
					ptemp->next = new Employee;
					ptemp = ptemp->next;
				}
				ptemp->next = nullptr;
				ptemp = HeadPtemp;
				temp = head;
				ofstream ofile;
				//*****************д���ļ�****************//
				ofile.open("ְ����Ϣ��.txt", ios::out);
				if (!finish)
				{
					cout << "û������ְ����Ϣ�޷�ɾ��!" << endl << "��������ɾ���˵�" << endl << endl;
					return;
				}
				if (!HeadPtemp)
				{
					cout << "��Ϣɾ���ɹ�!" << endl;
					cout << "�������ز�ѯ�˵�" << endl << endl;
					return;
				}

				while (ptemp->next)
				{
					ofile << ptemp->m_Name << endl;
					ofile << ptemp->m_Sex << endl;
					ofile << ptemp->m_Department << endl;
					ofile << ptemp->m_ID << endl;
					ofile << ptemp->m_Salary << endl;
					ofile << ptemp->m_Tel << endl;
					ptemp = ptemp->next;
				}
				ofile.close();
				cout << "��Ϣɾ���ɹ�!" << endl;
				cout << "��������ɾ���˵�" << endl << endl;
			}
				break;
			case '2':
			{
				cout << "�����빤�ž�ȷɾ����������ְ����Ϣ" << endl;
				string ID;
				cout << "��������Ҫɾ��ְ����Ϣ��ְ������(����Ϊ6λ����) ";
				l:getline(cin, ID);
				int Idnumber = 0;//��¼�������빤�ŵ�ְ����
				//*****************������****************//
				while (!AsIdOrTel(ID) || ID.size() != (unsigned)6)
				{
					cout << "�������!����������: ";
					getline(cin, ID);
				}
				while (tempToSave->next)
				{
					if (tempToSave->m_ID == ID)
					{
						++Idnumber;
					}
					tempToSave = tempToSave->next;
				}
				tempToSave = HeadTempSave;
				if (Idnumber)
					DeleteByID(ID);
				else//��ʾ���Ų�Ϊ����������ͬ������һ��ְ������
				{
					cout << "������Ĺ��Ų�Ϊ����������ͬ������һ��ְ������!" << endl;
					cout << "����������:";
					goto l;//��ת���������빤��
				}
			}
				break;
			default:
				break;
		}
		
	}
}

//****************ͨ�����Ų���ְ����Ϣ��ɾ��****************//
void Employee::DeleteByID(string ID)//���ذ汾:����ɾ���˵��д��ݽ����Ĺ���
{
	ifstream ifile;
	ifile.open("ְ����Ϣ��.txt", ios::in);
	char name[80];
	char department[80];
	char sex[80];
	char Id[80];
	char salary[80];
	char Tel[80];
	int finish = 0;
	Employee * head;
	Employee * temp = new Employee;
	head = temp;
	//*****************��ȡ�ļ�����***************//
	ifile.getline(name, 80);
	ifile.getline(sex, 80);
	ifile.getline(department, 80);
	ifile.getline(Id, 80);
	ifile.getline(salary, 80);
	ifile.getline(Tel, 80);
	temp->m_Name = name;
	temp->m_Sex = sex;
	temp->m_Department = department;
	temp->m_ID = Id;
	temp->m_Salary = salary;
	temp->m_Tel = Tel;
	while (ifile.peek() != EOF)
	{
		temp->next = new Employee;
		temp = temp->next;
		ifile.getline(name, 80);
		ifile.getline(sex, 80);
		ifile.getline(department, 80);
		ifile.getline(Id, 80);
		ifile.getline(salary, 80);
		ifile.getline(Tel, 80);
		temp->m_Name = name;
		temp->m_Sex = sex;
		temp->m_Department = department;
		temp->m_ID = Id;
		temp->m_Salary = salary;
		temp->m_Tel = Tel;
	}
	temp->next = nullptr;
	temp = head;
	//*****************д���ļ�ǰ�ж��Ƿ�ɾ����Ϣ�Ƿ���Ч****************//
	if (temp->m_Department == "Null" || temp->m_Department == "")
	{
		cout << "û������ְ����Ϣ�޷�ɾ��!" << endl << "��������ɾ���˵�" << endl << endl;
		return;
	}
	Employee * ptemp = nullptr;
	//*****************ɾ��ְ����Ϣ****************//
	if (temp->m_ID == ID)
	{
		head = temp->next;
		delete temp;
		++finish;
	}
	else
	{
		while (temp->next)
		{
			if (temp->next->m_ID == ID)
			{
				ptemp = temp->next;
				temp->next = temp->next->next;
				delete ptemp;
				++finish;
				break;
			}
			temp = temp->next;
		}
		if (temp->m_ID == ID)
		{
			temp->next = nullptr;
		}
	}
	temp = head;
	ifile.close();
	ofstream ofile;
	//*****************д���ļ�****************//
	ofile.open("ְ����Ϣ��.txt", ios::out);
	if (!finish)
	{
		cout << "û������ְ����Ϣ�޷�ɾ��!" << endl << "��������ɾ���˵�" << endl << endl;
		return;
	}
	if (!head)
	{
		cout << "��Ϣɾ���ɹ�!" << endl;
		cout << "��������ɾ���˵�" << endl << endl;
		return;
	}

	while (temp->next)
	{
		ofile << temp->m_Name << endl;
		ofile << temp->m_Sex << endl;
		ofile << temp->m_Department << endl;
		ofile << temp->m_ID << endl;
		ofile << temp->m_Salary << endl;
		ofile << temp->m_Tel << endl;
		temp = temp->next;
	}
	ofile << temp->m_Name << endl;
	ofile << temp->m_Sex << endl;
	ofile << temp->m_Department << endl;
	ofile << temp->m_ID << endl;
	ofile << temp->m_Salary << endl;
	ofile << temp->m_Tel << endl;
	ofile.close();
	cout << "��Ϣɾ���ɹ�!" << endl;
	cout << "��������ɾ���˵�" << endl << endl;
}
//********ͨ�����Ų���ְ����Ϣ��ɾ��********//
void Employee::DeleteByID()
{
	ifstream ifile;
	ifile.open("ְ����Ϣ��.txt", ios::in);
	string ID;
	cout << "��������Ҫɾ����ְ������(����Ϊ6λ����): ";
	getline(cin, ID);
	//*****************������****************//
	while (!AsIdOrTel(ID) || ID.size() != (unsigned)6)
	{
		cout << "�������!����������: ";
		getline(cin, ID);
	}
	char name[80];
	char department[80];
	char sex[80];
	char Id[80];
	char salary[80];
	char Tel[80];
	int finish = 0;
	Employee * head;
	Employee * temp = new Employee;
	head = temp;
	//*****************��ȡ�ļ�����***************//
	ifile.getline(name, 80);
	ifile.getline(sex, 80);
	ifile.getline(department, 80);
	ifile.getline(Id, 80);
	ifile.getline(salary, 80);
	ifile.getline(Tel, 80);
	temp->m_Name = name;
	temp->m_Sex = sex;
	temp->m_Department = department;
	temp->m_ID = Id;
	temp->m_Salary = salary;
	temp->m_Tel = Tel;
	while (ifile.peek() != EOF)
	{
		temp->next = new Employee;
		temp = temp->next;
		ifile.getline(name, 80);
		ifile.getline(sex, 80);
		ifile.getline(department, 80);
		ifile.getline(Id, 80);
		ifile.getline(salary, 80);
		ifile.getline(Tel, 80);
		temp->m_Name = name;
		temp->m_Sex = sex;
		temp->m_Department = department;
		temp->m_ID = Id;
		temp->m_Salary = salary;
		temp->m_Tel = Tel;
	}
	temp->next = nullptr;
	temp = head;
	//*****************д���ļ�ǰ�ж��Ƿ�ɾ����Ϣ�Ƿ���Ч****************//
	if (temp->m_Department == "Null" || temp->m_Department == "")
	{
		cout << "û������ְ����Ϣ�޷�ɾ��!" << endl << "��������ɾ���˵�" << endl << endl;
		return;
	}
	Employee * ptemp = nullptr;
	//*****************ɾ��ְ����Ϣ****************//
	if (temp->m_ID == ID)
	{
		head = temp->next;
		delete temp;
		++finish;
	}
	else
	{
		while (temp->next)
		{
			if (temp->next->m_ID == ID)
			{
				ptemp = temp->next;
				temp->next = temp->next->next;
				delete ptemp;
				++finish;
				break;
			}
			temp = temp->next;
		}
		if (temp->m_ID == ID)
		{
			temp->next = nullptr;
		}
	}
	temp = head;
	ifile.close();
	ofstream ofile;
	//*****************д���ļ�****************//
	ofile.open("ְ����Ϣ��.txt", ios::out);
	if (!finish)
	{
		cout << "û������ְ����Ϣ�޷�ɾ��!" << endl << "��������ɾ���˵�" << endl << endl;
		return;
	}
	if (!head)
	{
		cout << "��Ϣɾ���ɹ�!" << endl;
		cout << "��������ɾ���˵�" << endl << endl;
		return;
	}

	while (temp->next)
	{
		ofile << temp->m_Name << endl;
		ofile << temp->m_Sex << endl;
		ofile << temp->m_Department << endl;
		ofile << temp->m_ID << endl;
		ofile << temp->m_Salary << endl;
		ofile << temp->m_Tel << endl;
		temp = temp->next;
	}
	ofile << temp->m_Name << endl;
	ofile << temp->m_Sex << endl;
	ofile << temp->m_Department << endl;
	ofile << temp->m_ID << endl;
	ofile << temp->m_Salary << endl;
	ofile << temp->m_Tel << endl;
	ofile.close();
	cout << "��Ϣɾ���ɹ�!" << endl ;
	cout << "��������ɾ���˵�" << endl << endl;
}

//*****************ɾ��ȫ��ְ����Ϣ******************//
void Employee::DeleteAllInfo()
{
	if (!remove("ְ����Ϣ��.txt"))
		cout << "�ļ�ɾ���ɹ�!" << endl;
	else
		cout << "�ļ�ɾ��ʧ��!(����û������ְ����Ϣ!)" << endl;
	cout << "�����������˵�" << endl << endl;
}

//***************���빤�Ų���ְ����Ϣ���޸�****************//
void Employee::ChangeByID()
{
	ifstream ifile;
	ifile.open("ְ����Ϣ��.txt", ios::in);
	string ID;
	cout << "��������Ҫ�޸�ְ����Ϣ��ְ������(����Ϊ6λ����) ";
	getline(cin, ID);
	//*****************������****************//
	while (!AsIdOrTel(ID) || ID.size() != (unsigned)6)
	{
		cout << "�������!����������: ";
		getline(cin, ID);
	}
	char name[80];
	char department[80];
	char sex[80];
	char Id[80];
	char salary[80];
	char Tel[80];
	int finish = 0;
	Employee * head;
	Employee * temp = new Employee;
	head = temp;
	//*****************��ȡ�ļ�����****************//
	ifile.getline(name, 80);
	ifile.getline(sex, 80);
	ifile.getline(department, 80);
	ifile.getline(Id, 80);
	ifile.getline(salary, 80);
	ifile.getline(Tel, 80);
	temp->m_Name = name;
	temp->m_Sex = sex;
	temp->m_Department = department;
	temp->m_ID = Id;
	temp->m_Salary = salary;
	temp->m_Tel = Tel;
	while (ifile.peek() != EOF)
	{
		temp->next = new Employee;
		temp = temp->next;
		ifile.getline(name, 80);
		ifile.getline(sex, 80);
		ifile.getline(department, 80);
		ifile.getline(Id, 80);
		ifile.getline(salary, 80);
		ifile.getline(Tel, 80);
		temp->m_Name = name;
		temp->m_Sex = sex;
		temp->m_Department = department;
		temp->m_ID = Id;
		temp->m_Salary = salary;
		temp->m_Tel = Tel;
	}
	ifile.close();
	temp->next = nullptr;
	temp = head;
	int finishnum = 0;
	//*****************�ж�д���ļ�ǰ�޸���Ϣ�Ƿ���Ч****************//
	if (temp->m_Department == "Null" || temp->m_Department == "")
	{
		cout << "û������ְ����Ϣ�޷��޸�!" << endl << "���������޸Ĳ˵�" << endl << endl;
		return;
	}
	cout << "�����������޸ĵ�ְ����Ϣ\n";	
	this->rsetName();
	this->rsetSex();
	this->rsetDepartment();
	this->m_ID = ID;
	this->rsetSalary();
	this->rsetTel();
	//*****************�޸Ĳ���****************//
	if (this->m_ID == temp->m_ID)
	{
		temp->m_ID = this->m_ID;
		temp->m_Department = this->m_Department;
		temp->m_Name = this->m_Name;
		temp->m_Salary = this->m_Salary;
		temp->m_Sex = this->m_Sex;
		temp->m_Tel = this->m_Tel;
		++finishnum;
	}
	else
	{
		while (temp->next)
		{

			if (this->m_ID == temp->m_ID)
			{
				temp->m_ID = this->m_ID;
				temp->m_Department = this->m_Department;
				temp->m_Name = this->m_Name;
				temp->m_Salary = this->m_Salary;
				temp->m_Sex = this->m_Sex;
				temp->m_Tel = this->m_Tel;
				++finishnum;
				break;
			}
			temp = temp->next;
		}
		if (this->m_ID == temp->m_ID)
		{
			temp->m_ID = this->m_ID;
			temp->m_Department = this->m_Department;
			temp->m_Name = this->m_Name;
			temp->m_Salary = this->m_Salary;
			temp->m_Sex = this->m_Sex;
			temp->m_Tel = this->m_Tel;
			++finishnum;
		}
	}
	temp = head;
	if (!finishnum)
	{
		cout << "û������ְ����Ϣ�޷��޸�!" << endl << "���������޸Ĳ˵�" << endl << endl;
		return;
	}
	ofstream ofile;
	//*****************д���ļ�****************//
	ofile.open("ְ����Ϣ��.txt", ios::out);
	while (temp->next)
	{
		ofile << temp->m_Name << endl;
		ofile << temp->m_Sex << endl;
		ofile << temp->m_Department << endl;
		ofile << temp->m_ID << endl;
		ofile << temp->m_Salary << endl;
		ofile << temp->m_Tel << endl;
		temp = temp->next;
	}
	ofile << temp->m_Name << endl;
	ofile << temp->m_Sex << endl;
	ofile << temp->m_Department << endl;
	ofile << temp->m_ID << endl;
	ofile << temp->m_Salary << endl;
	ofile << temp->m_Tel << endl;
	ofile.close();
	cout << "��Ϣ�޸ĳɹ�!" << endl;
	cout << "���������޸Ĳ˵�" << endl << endl;
}

//*****************ͨ����������ְ����Ϣ���޸�****************//
void Employee::ChangeByName()
{
	ifstream ifile;
	ifile.open("ְ����Ϣ��.txt", ios::in);
	string Name;
	cout << "��������Ҫ�޸ĵ�ְ������: ";
	getline(cin, Name);
	char name[80];
	char department[80];
	char sex[80];
	char Id[80];
	char salary[80];
	char Tel[80];
	int finish = 0;
	Employee * head;
	Employee * temp = new Employee;
	head = temp;
	//*****************��ȡ�ļ�����***************//
	ifile.getline(name, 80);
	ifile.getline(sex, 80);
	ifile.getline(department, 80);
	ifile.getline(Id, 80);
	ifile.getline(salary, 80);
	ifile.getline(Tel, 80);
	temp->m_Name = name;
	temp->m_Sex = sex;
	temp->m_Department = department;
	temp->m_ID = Id;
	temp->m_Salary = salary;
	temp->m_Tel = Tel;
	while (ifile.peek() != EOF)
	{
		temp->next = new Employee;
		temp = temp->next;
		ifile.getline(name, 80);
		ifile.getline(sex, 80);
		ifile.getline(department, 80);
		ifile.getline(Id, 80);
		ifile.getline(salary, 80);
		ifile.getline(Tel, 80);
		temp->m_Name = name;
		temp->m_Sex = sex;
		temp->m_Department = department;
		temp->m_ID = Id;
		temp->m_Salary = salary;
		temp->m_Tel = Tel;
	}
	temp->next = nullptr;
	temp = head;
	ifile.close();
	//*****************д���ļ�ǰ�ж��Ƿ�ɾ����Ϣ�Ƿ���Ч****************//
	if (temp->m_Department == "Null" || temp->m_Department == "")
	{
		cout << "û������ְ����Ϣ�޷��޸�!" << endl << "���������޸Ĳ˵�" << endl << endl;
		return;
	}
	int number = 0;//��¼�������û�����������ͬ��ְ����
	Employee * tempToSave = new Employee;//��¼������ͬ��ְ����Ϣ
	Employee * HeadTempSave = tempToSave;
	//��¼������ͬ��ְ����Ϣ
	while (temp->next)
	{
		if (temp->m_Name == Name)
		{
			++number;
			*tempToSave = *temp;
			tempToSave->next = new Employee;
			tempToSave = tempToSave->next;
		}
		temp = temp->next;
	}
	if (temp->m_Name == Name)
	{
		++number;
		*tempToSave = *temp;
		tempToSave->next = new Employee;
		tempToSave = tempToSave->next;
	}
	tempToSave->next = nullptr;
	tempToSave = HeadTempSave;
	temp = head;
	if (number == 0)//���������û������������ͬ��ְ����Ϣ
		cout << "û�������������ְ����Ϣ!" << endl << "���������޸Ĳ˵�" << endl << endl;
	else if (number == 1)//������һ�����û������������ͬ��ְ��
	{
		cout << "�����������޸ĵ�ְ����Ϣ\n";
		this->rsetName();
		this->rsetSex();
		this->rsetDepartment();
		this->rsetSalary();
		this->rsetTel();
		//*****************д���ļ�ǰ�ж��Ƿ�ɾ����Ϣ�Ƿ���Ч****************//
		if (temp->m_Department == "Null" || temp->m_Department == "")
		{
			cout << "û������ְ����Ϣ�޷��޸�!" << endl << "���������޸Ĳ˵�" << endl << endl;
			return;
		}
		Employee * ptemp = nullptr;
		//*****************�޸�ְ����Ϣ****************//
		if (temp->m_Name == Name)
		{
			temp->m_Department = this->m_Department;
			temp->m_Name = this->m_Name;
			temp->m_Salary = this->m_Salary;
			temp->m_Sex = this->m_Sex;
			temp->m_Tel = this->m_Tel;
			++finish;
		}
		else
		{
			while (temp->next)
			{
				if (temp->m_Name == Name)
				{
					temp->m_Department = this->m_Department;
					temp->m_Name =  this->m_Name;
					temp->m_Salary = this->m_Salary;
					temp->m_Sex = this->m_Sex;
					temp->m_Tel = this->m_Tel;
					++finish;
					break;
				}
				temp = temp->next;
			}
			if (temp->m_Name == Name)
			{
				temp->m_Department = this->m_Department;
				temp->m_Name = this->m_Name;
				temp->m_Salary = this->m_Salary;
				temp->m_Sex = this->m_Sex;
				temp->m_Tel = this->m_Tel;
				++finish;
			}
		}
		temp = head;
		ofstream ofile;
		//*****************д���ļ�****************//
		ofile.open("ְ����Ϣ��.txt", ios::out);
		if (!finish)
		{
			cout << "û������ְ����Ϣ�޷��޸�!" << endl << "���������޸Ĳ˵�" << endl << endl;
			return;
		}
		if (!head)
		{
			cout << "��Ϣ�޸ĳɹ�!" << endl;
			cout << "���������޸Ĳ˵�" << endl << endl;
			return;
		}
		while (temp->next)
		{
			ofile << temp->m_Name << endl;
			ofile << temp->m_Sex << endl;
			ofile << temp->m_Department << endl;
			ofile << temp->m_ID << endl;
			ofile << temp->m_Salary << endl;
			ofile << temp->m_Tel << endl;
			temp = temp->next;
		}
		ofile << temp->m_Name << endl;
		ofile << temp->m_Sex << endl;
		ofile << temp->m_Department << endl;
		ofile << temp->m_ID << endl;
		ofile << temp->m_Salary << endl;
		ofile << temp->m_Tel << endl;
		ofile.close();
		cout << "��Ϣ�޸ĳɹ�!" << endl << "���������޸Ĳ˵�" << endl << endl;
	}
	else//���ڶ������û������������ͬ��ְ����Ϣ
	{
		cout << "����" << number << "����ͬ������ְ��!" << endl;
		while (tempToSave->next)
		{
			cout << *tempToSave << endl;
			tempToSave = tempToSave->next;
		}
		tempToSave = HeadTempSave;
		cout << "�����빤�ž�ȷ�޸ĸ�������ְ����Ϣ" << endl;
		string ID;
		cout << "��������Ҫ�޸�ְ����Ϣ��ְ������(����Ϊ6λ����) ";
		l:getline(cin, ID);
		int Idnumber = 0;
		//*****************������****************//
		while (!AsIdOrTel(ID) || ID.size() != (unsigned)6)
		{
			cout << "�������!����������: ";
			getline(cin, ID);
		}
		while (tempToSave->next)
		{
			if (tempToSave->m_ID == ID)
			{
				++Idnumber;
			}
			tempToSave = tempToSave->next;
		}
		tempToSave = HeadTempSave;
		if (Idnumber)
			ChangeByID(ID);
		else
		{
			cout << "������Ĺ��Ų�Ϊ����������ͬ������һ��ְ������!" << endl;
			cout << "����������:";
			goto l;//��ת����������
		}
	}
}

//****************ͨ����������ְ����Ϣ���޸�****************//
void Employee::ChangeByID(string ID)//���ذ汾:�����޸Ĳ˵��д��ݵĹ���
{
	ifstream ifile;
	ifile.open("ְ����Ϣ��.txt", ios::in);
	char name[80];
	char department[80];
	char sex[80];
	char Id[80];
	char salary[80];
	char Tel[80];
	int finish = 0;
	Employee * head;
	Employee * temp = new Employee;
	head = temp;
	//*****************��ȡ�ļ�����****************//
	ifile.getline(name, 80);
	ifile.getline(sex, 80);
	ifile.getline(department, 80);
	ifile.getline(Id, 80);
	ifile.getline(salary, 80);
	ifile.getline(Tel, 80);
	temp->m_Name = name;
	temp->m_Sex = sex;
	temp->m_Department = department;
	temp->m_ID = Id;
	temp->m_Salary = salary;
	temp->m_Tel = Tel;
	while (ifile.peek() != EOF)
	{
		temp->next = new Employee;
		temp = temp->next;
		ifile.getline(name, 80);
		ifile.getline(sex, 80);
		ifile.getline(department, 80);
		ifile.getline(Id, 80);
		ifile.getline(salary, 80);
		ifile.getline(Tel, 80);
		temp->m_Name = name;
		temp->m_Sex = sex;
		temp->m_Department = department;
		temp->m_ID = Id;
		temp->m_Salary = salary;
		temp->m_Tel = Tel;
	}
	ifile.close();
	temp->next = nullptr;
	temp = head;
	int finishnum = 0;
	cout << "�����������޸ĵ�ְ����Ϣ\n";
	this->rsetName();
	this->rsetSex();
	this->rsetDepartment();
	this->m_ID = ID;
	this->rsetSalary();
	this->rsetTel();
	//*****************�ж�д���ļ�ǰ�޸���Ϣ�Ƿ���Ч****************//
	if (temp->m_Department == "Null" || temp->m_Department == "")
	{
		cout << "û������ְ����Ϣ�޷��޸�!" << endl << "���������޸Ĳ˵�" << endl << endl;
		return;
	}
	//*****************�޸Ĳ���****************//
	if (this->m_ID == temp->m_ID)
	{
		temp->m_ID = this->m_ID;
		temp->m_Department = this->m_Department;
		temp->m_Name = this->m_Name;
		temp->m_Salary = this->m_Salary;
		temp->m_Sex = this->m_Sex;
		temp->m_Tel = this->m_Tel;
		++finishnum;
	}
	else
	{
		while (temp->next)
		{

			if (this->m_ID == temp->m_ID)
			{
				temp->m_ID = this->m_ID;
				temp->m_Department = this->m_Department;
				temp->m_Name = this->m_Name;
				temp->m_Salary = this->m_Salary;
				temp->m_Sex = this->m_Sex;
				temp->m_Tel = this->m_Tel;
				++finishnum;
				break;
			}
			temp = temp->next;
		}
		if (this->m_ID == temp->m_ID)
		{
			temp->m_ID = this->m_ID;
			temp->m_Department = this->m_Department;
			temp->m_Name = this->m_Name;
			temp->m_Salary = this->m_Salary;
			temp->m_Sex = this->m_Sex;
			temp->m_Tel = this->m_Tel;
			++finishnum;
		}
	}
	temp = head;
	if (!finishnum)
	{
		cout << "û������ְ����Ϣ�޷��޸�!" << endl << "���������޸Ĳ˵�" << endl << endl;
		return;
	}
	ofstream ofile;
	//*****************д���ļ�****************//
	ofile.open("ְ����Ϣ��.txt", ios::out);
	while (temp->next)
	{
		ofile << temp->m_Name << endl;
		ofile << temp->m_Sex << endl;
		ofile << temp->m_Department << endl;
		ofile << temp->m_ID << endl;
		ofile << temp->m_Salary << endl;
		ofile << temp->m_Tel << endl;
		temp = temp->next;
	}
	ofile << temp->m_Name << endl;
	ofile << temp->m_Sex << endl;
	ofile << temp->m_Department << endl;
	ofile << temp->m_ID << endl;
	ofile << temp->m_Salary << endl;
	ofile << temp->m_Tel << endl;
	ofile.close();
	cout << "��Ϣ�޸ĳɹ�!" << endl;
	cout << "���������޸Ĳ˵�" << endl << endl;
}

//*****************�޸�ְ����Ϣ�˵�******************//
void Employee::ChangeInfo()
{
	cout << "1).����ְ�������޸�ְ����Ϣ\n"
		<< "2).����ְ�������޸�ְ����Ϣ\n"
		<< "3).�������˵�" << endl;
	char select[80] = { 0 };
	cout << "����������ѡ��: ";
	cin.getline(select, 80);
	//*****************������****************//
	while (select[1] != '\0' || select[0] < '1' || select[0] > '3')
	{
		cout << "�������!����������: ";
		cin.getline(select, 80);
	}
	while (select[0] > '0' && select[0] < '3')
	{
		switch (select[0])
		{
		case '1':
			ChangeByID();
			break;
		case '2':
			ChangeByName();
			break;
		default:
			break;
		}
		cout << "1).����ְ�������޸�ְ����Ϣ\n"
			<< "2).����ְ�������޸�ְ����Ϣ\n"
			<< "3).�������˵�" << endl;
		cout << "����������ѡ��: ";
		cin.getline(select, 80);
		while (select[1] != '\0' || select[0] < '1' || select[0] > '3')
		{
			cout << "�������!����������: ";
			cin.getline(select, 80);
		}
	}
	cout << "�����������˵�" << endl << endl;
}

//*****************ɾ��ְ����Ϣ�˵�******************//
void Employee::DeleteInfo()
{
	cout << "1).����ְ������ɾ��ְ����Ϣ\n"
		<< "2).����ְ������ɾ��ְ����Ϣ\n"
		<< "3).�������˵�" << endl;
	char select[80] = { 0 };
	cout << "����������ѡ��: ";
	cin.getline(select, 80);
	//*****************������****************//
	while (select[1] != '\0' || select[0] < '1' || select[0] > '3')
	{
		cout << "�������!����������: ";
		cin.getline(select, 80);
	}
	while (select[0] > '0' && select[0] < '3')
	{
		switch (select[0])
		{
		case '1':
			DeleteByID();
			break;
		case '2':
			DeleteByName();
			break;
		default:
			break;
		}
		cout << "1).����ְ������ɾ��ְ����Ϣ\n"
			<< "2).����ְ������ɾ��ְ����Ϣ\n"
			<< "3).�������˵�" << endl;
		cout << "����������ѡ��: ";
		cin.getline(select, 80);
		while (select[1] != '\0' || select[0] < '1' || select[0] > '3')
		{
			cout << "�������!����������: ";
			cin.getline(select, 80);
		}
	}
	cout << "�����������˵�" << endl << endl;
}

//*****************���ݹ����������******************//
void Employee::SortAndOutput()
{
	ifstream ifile;
	//*****************��ȡ�ļ�����****************//
	ifile.open("ְ����Ϣ��.txt", ios::in);
	char name[80];
	char department[80];
	char sex[80];
	char Id[80];
	char salary[80];
	char Tel[80];
	int finish = 0;
	Employee * head;
	Employee * temp = new Employee;
	head = temp;
	ifile.getline(name, 80);
	ifile.getline(sex, 80);
	ifile.getline(department, 80);
	ifile.getline(Id, 80);
	ifile.getline(salary, 80);
	ifile.getline(Tel, 80);
	temp->m_Name = name;
	temp->m_Sex = sex;
	temp->m_Department = department;
	temp->m_ID = Id;
	temp->m_Salary = salary;
	temp->m_Tel = Tel;
	while (ifile.peek() != EOF)
	{
		temp->next = new Employee;
		temp = temp->next;
		ifile.getline(name, 80);
		ifile.getline(sex, 80);
		ifile.getline(department, 80);
		ifile.getline(Id, 80);
		ifile.getline(salary, 80);
		ifile.getline(Tel, 80);
		temp->m_Name = name;
		temp->m_Sex = sex;
		temp->m_Department = department;
		temp->m_ID = Id;
		temp->m_Salary = salary;
		temp->m_Tel = Tel;
	}
	temp->next = nullptr;
	ifile.close();
	temp = head;
	head = sortList(temp);//����ְ����Ϣ
	temp = head;
	//*****************���ǰ�ж������Ƿ���Ч******************//
	if (temp->m_Department == "Null" || temp->m_Department == "")
	{
		cout << "û������ְ����Ϣ�޷�����!" << endl << "�����������˵�" << endl << endl;
		return;
	}
	cout << "������Ϊ: \n";
	while (temp->next)
	{
		cout << *temp << endl;
		temp = temp->next;
	}
	if (temp->m_Department == "Null" || temp->m_Department == "")
		return;
	cout << *temp;
	cout << "�����������˵�" << endl << endl;
}

//*****************���ݿ�����������ҹ���ƽ��ֵ******************//
void Employee::StatisticAndAverage()
{
	ifstream ifile;
	//******************��ȡ�ļ�����*****************//
	ifile.open("ְ����Ϣ��.txt", ios::in);
	char name[80];
	char department[80];
	char sex[80];
	char Id[80];
	char salary[80];
	char Tel[80];
	int finish = 0;
	Employee * head;
	Employee * temp = new Employee;
	head = temp;
	ifile.getline(name, 80);
	ifile.getline(sex, 80);
	ifile.getline(department, 80);
	ifile.getline(Id, 80);
	ifile.getline(salary, 80);
	ifile.getline(Tel, 80);
	temp->m_Name = name;
	temp->m_Sex = sex;
	temp->m_Department = department;
	temp->m_ID = Id;
	temp->m_Salary = salary;
	temp->m_Tel = Tel;
	while (ifile.peek() != EOF)
	{
		temp->next = new Employee;
		temp = temp->next;
		ifile.getline(name, 80);
		ifile.getline(sex, 80);
		ifile.getline(department, 80);
		ifile.getline(Id, 80);
		ifile.getline(salary, 80);
		ifile.getline(Tel, 80);
		temp->m_Name = name;
		temp->m_Sex = sex;
		temp->m_Department = department;
		temp->m_ID = Id;
		temp->m_Salary = salary;
		temp->m_Tel = Tel;
	}
	temp->next = nullptr;
	ifile.close();
	temp = head;
	Node * p = new Node;
	Node * nhead = p;
	double number = 0.0;
	double psum = 0.0;
	double tsum = 0.0;
	stringstream translate;
	//******************ͳ�Ƹ����������������ܺ�*****************//
	while (temp->next)
	{
		if (p->isRepeat(p, temp->m_Department))//������ͬ����ʱ
		{
			//******************string������double���ͻ���ת��*****************//
			translate << p->m_number;
			translate >> number;
			++number;//�ÿ���ְ����������
			translate.clear();
			translate << number;
			translate >> p->m_number;
			translate.clear();
			translate << p->m_sum;
			translate >> psum;
			translate.clear();
			translate << temp->m_Salary;
			translate >> tsum;
			translate.clear();
			psum += tsum;//ͳ�Ƹÿ��ҹ����ܼ�
			translate << psum;
			translate >> p->m_sum;
			translate.clear();
		}
		else
		{
			p->m_department = temp->m_Department;//�����¿���
			translate << p->m_number;
			translate >> number;
			++number;
			translate.clear();
			translate << number;
			translate >> p->m_number;
			translate.clear();
			translate << p->m_sum;
			translate >> psum;
			translate.clear();
			translate << temp->m_Salary;
			translate >> tsum;
			translate.clear();
			psum += tsum;
			translate << psum;
			translate >> p->m_sum;
			translate.clear();
			p->next = new Node;
			p = p->next;
		}
		temp = temp->next;
	}
	//*****************������ĩβδ��������ݽ�����ͬ����******************//
	if (p->isRepeat(p, temp->m_Department))
	{
		translate << p->m_number;
		translate >> number;
		translate.clear();
		++number;
		translate << number;
		translate >> p->m_number;
		translate.clear();
		translate << p->m_sum;
		translate >> psum;
		translate.clear();
		translate << temp->m_Salary;
		translate >> tsum;
		translate.clear();
		psum += tsum;
		translate << psum;
		translate >> p->m_sum;
		translate.clear();
	}
	else
	{
		p->m_department = temp->m_Department;
		translate << p->m_number;
		translate >> number;
		translate.clear();
		++number;
		translate << number;
		translate >> p->m_number;
		translate.clear();
		translate << p->m_sum;
		translate >> psum;
		translate.clear();
		translate << temp->m_Salary;
		translate >> tsum;
		translate.clear();
		psum += tsum;
		translate << psum;
		translate >> p->m_sum;
		translate.clear();
		p->next = new Node;
		p = p->next;
	}
	p = nhead;
	//*****************���ǰ�ж��Ƿ����ְ����Ϣ******************//
	if (temp->m_Department == "Null" || temp->m_Department == "")
	{
		cout << "û������ְ����Ϣ�޷����!" << endl << "�����������˵�" << endl << endl;
		return;
	}
	while (p->next)
	{
		translate << p->m_sum;
		translate >> psum;
		translate.clear();
		translate << p->m_number;
		translate >> number;
		translate.clear();
		cout << p->m_department << "���ҵ�ƽ������Ϊ: " << (double)psum / number << endl;
		p = p->next;
	}
	cout << "�����������˵�" << endl << endl;
}