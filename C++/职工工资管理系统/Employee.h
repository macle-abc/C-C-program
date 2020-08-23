#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>
using std::string;

class Employee
{
private:
	string m_Name;//ְ������
	string m_Sex;//ְ���Ա�
	string m_Department;//ְ������
	string m_Salary;//ְ������
	string m_ID;//ְ������
	string m_Tel;//ְ���绰
	Employee * next;

	void rsetName();//��������
	void rsetSex();//�����Ա�
	void rsetID();//���蹤��
	void rsetTel();//����绰
	void rsetDepartment();//�������
	void rsetSalary();//���蹤��

	void QueryByID();//ͨ�����Ų���ְ����Ϣ
	void QueryByName();//ͨ����������ְ����Ϣ
	void QueryByDepartment();//ͨ�����Ҳ���ְ����Ϣ

	void DeleteByID(string ID);//ͨ�����Ų���ְ����Ϣ��ɾ��
	void DeleteByID();//ͨ�����Ų���ְ����Ϣ��ɾ��
	void DeleteByName();//ͨ����������ְ����Ϣ��ɾ��

	void ChangeByID(string ID); //ͨ�����Ų���ְ����Ϣ���޸�
	void ChangeByID();//ͨ�����Ų���ְ����Ϣ���޸�
	void ChangeByName();//ͨ����������ְ����Ϣ���޸�

	void swap(Employee * a, Employee * b);//����a��b��Ϣ
	Employee *partion(Employee *pBegin, Employee *pEnd);//�������
	void quick_sort(Employee *pBegin, Employee *pEnd);//��������
	Employee* sortList(Employee* head);//��������
	friend std::istream & operator >> (std::istream & is, Employee & e);//�������������
	friend std::ostream & operator << (std::ostream & os, Employee & e);//������������
	bool AsIdOrTel(string str);//�ж��ַ���str�ܷ�Ϊ���Ż�绰����
	bool AsSalary(string str);//�ж��ַ���str�ܷ�Ϊ������

public:
	Employee(string name = "Null", string sex = "Null", string ID = "0", string Tel = "0", string department = "Null", string salary = "0") :
		m_Name(name), m_Sex(sex), m_ID(ID), m_Tel(Tel), m_Department(department), m_Salary(salary) {}
	~Employee() {}

	void InputToFile();//����ְ����Ϣ���ļ�
	void Query();//��ѯְ����Ϣ
	void ChangeInfo();//�޸�ְ����Ϣ
	void DeleteInfo();//ɾ��ְ����Ϣ
	void DeleteAllInfo();//ɾ��ȫ����Ϣ
	void SortAndOutput();//�������
	void StatisticAndAverage();//�ֿ��ҽ���ͳ�ƣ���������ҵ�ƽ��ֵ
};

//**************Ա��������Ϣ�ṹ******************
class Node
{
public:
	string m_department;
	string m_number;
	string m_sum;
	Node * next;
	int isRepeat(Node * p, string department);//�ж��Ƿ��Ѵ�����ͬ�Ĳ���
	Node(string department = "Null", string number = "0", string sum = "0", Node * n = nullptr) : m_department(department), m_number(number), m_sum(sum), next(n) {}
};

#endif