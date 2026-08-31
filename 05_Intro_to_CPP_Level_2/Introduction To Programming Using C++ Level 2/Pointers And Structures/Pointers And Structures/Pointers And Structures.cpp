#include <iostream>
using namespace std;

struct stEmployee
{
	string Name;
	float Salary;
};

int main()
{
	stEmployee Employee, * ptr;

	Employee.Name = "ALI ALI";
	Employee.Salary = 500;

	cout << Employee.Name << endl;
	cout << Employee.Salary << endl;

	cout << endl;

	ptr = &Employee;


	cout << ptr->Name << endl;
	cout << ptr->Salary << endl;

	return 0;
}