#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct stEmployee
{
	string FirstName = "";
	string LastName = "";
	float Salary = 0;
};

void ReadVectorStructElements(vector <stEmployee>& vEmployees)
{
	stEmployee TempEmployee;
	char AddElement = 'y';
	int Counter = 1;

	while (AddElement == 'Y' || AddElement == 'y')
	{
		printf("Element %0*d:\n\n", 2, Counter);
		Counter++;

		cout << "Enter the first name?\n";
		cin >> TempEmployee.FirstName;

		cout << "Enter the last name?\n";
		getline(cin.ignore(), TempEmployee.LastName);

		cout << "Enter the salary?\n";
		cin >> TempEmployee.Salary;

		vEmployees.push_back(TempEmployee);

		cout << "\n Do You Want To Add Another Element (Y/N) ? ";
		cin >> AddElement;
	}
}

void PrintVectorStructElements(vector <stEmployee>& vEmployees)
{
	for (stEmployee& Employee : vEmployees)
	{
		cout << "First Name: " << Employee.FirstName << endl;
		cout << "Last Name : " << Employee.LastName << endl;
		cout << "Salary    : " << Employee.Salary << endl << endl;
	}
}

int main()
{
	vector <stEmployee> vEmployees;

	ReadVectorStructElements(vEmployees);
	PrintVectorStructElements(vEmployees);

	return 0;
}