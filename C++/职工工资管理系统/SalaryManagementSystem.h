#ifndef SALARYMANAGEMENTSYSTEM_H_
#define SALARYMANAGEMENTSYSTEM_H_

#include "Employee.h"

//���ʹ���ϵͳ��
class SalaryManagementSystem
{
private:
	Employee person;
public:
	SalaryManagementSystem(string name = "Null", string sex = "Null", string ID = "0", string Tel = "0", string department = "Null", string salary = "0");
	~SalaryManagementSystem() {}
};

#endif