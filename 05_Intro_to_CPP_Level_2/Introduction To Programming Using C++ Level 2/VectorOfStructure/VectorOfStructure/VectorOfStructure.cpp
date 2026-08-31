#include <iostream>
#include <vector>

using namespace std;

struct stEmployee
{
	string FirstName = "";
	string LastName = "";
	float Salary = 0;
};

int main()
{
	vector <stEmployee> vEmployees;

	stEmployee TempEmployee;

	TempEmployee.FirstName = "Mohammad";
	TempEmployee.LastName = "Abu Hadhoud";
	TempEmployee.Salary = 5000;
	vEmployees.push_back(TempEmployee);

	TempEmployee.FirstName = "Ali";
	TempEmployee.LastName = "ali";
	TempEmployee.Salary = 300;
	vEmployees.push_back(TempEmployee);

	TempEmployee.FirstName = "sarah";
	TempEmployee.LastName = "ahmad";
	TempEmployee.Salary = 1000;
	vEmployees.push_back(TempEmployee);

	for (stEmployee &Employee : vEmployees)
	{
		cout << Employee.FirstName << endl;
		cout << Employee.LastName << endl;
		cout << Employee.Salary << endl << endl;
	}

	return 0;
}