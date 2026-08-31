#pragma once

#include <iostream>
#include "clsEmployee.h";

using namespace std;

class clsDeveloper : public clsEmployee
{
private:

	string _MainProgrammingLanguage;

public:

	clsDeveloper(int ID, string FirstName, string LastName,
		string Email, string Phone, string Title, string Department,
		float Salary, string MainProgrammingLanguage)
		: clsEmployee(ID, FirstName, LastName, Email, Phone, Title, Department, Salary)
	{
		_MainProgrammingLanguage = MainProgrammingLanguage;
	}

	void SetMainProgrammingLaguage(string MainProgrammingLanguage)
	{
		_MainProgrammingLanguage = MainProgrammingLanguage;
	}
	string GetMainProgrammingLanguage()
	{
		return _MainProgrammingLanguage;
	}

	void Print()
	{
		clsEmployee::Print();
		cout << "pLanguage: " << _MainProgrammingLanguage << endl;
	}
};
