#pragma once

#include <iostream>
#include "clsPerson.h";

using namespace std;

class clsEmployee : public clsPerson
{
private:

	string _Title,
		_Department;
	float _Salary;

public:

	clsEmployee(int ID, string FirstName, string LastName, string Email, string Phone, string Title, string Department, float Salary)
		: clsPerson(ID, FirstName, LastName, Email, Phone)
	{
		_Title = Title;
		_Department = Department;
		_Salary = Salary;
	}

	void Print()
	{
		cout << "\nInfo:";
		cout << "\n___________________";
		cout << "\nID       : " << GetID();
		cout << "\nFirstName: " << GetFirstName();
		cout << "\nLastName : " << GetLastName();
		cout << "\nFull Name: " << FullName();
		cout << "\nEmail    : " << GetEmail();
		cout << "\nPhone    : " << GetPhone();
		cout << "\n___________________\n";

		cout << "\nHi, I'm the override function\n";
	}

};

