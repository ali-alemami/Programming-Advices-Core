#include <iostream>
using namespace std;
struct strInfo
{
	string FirstName;
	string LastName;
	int Age;
	string Phone;
};
void ReadInfo(strInfo& info)
{
	cout << "Enter your First Name\n";
	cin >> info.FirstName;

	cout << "Enter your Last Name\n";
	cin >> info.LastName;

	cout << "Enter you Age\n";
	cin >> info.Age;

	cout << "Enter your Phone\n";
	cin >> info.Phone;
}
void PrintInfo(strInfo& info)
{
	cout << endl << endl << "**************************************\n";
	cout << "First Name: " << info.FirstName << endl;
	cout << "Last Name: " << info.LastName << endl;
	cout << "Age  : " << info.Age << endl;
	cout << "Phone: " << info.Phone << endl;
	cout << "**************************************\n";

}
void ReadPersonsInfo(strInfo Persons[2])
{
	ReadInfo(Persons[0]);
	ReadInfo(Persons[1]);
}
void PrintPersonsInfo(strInfo Persons[2])
{
	PrintInfo(Persons[0]);
	PrintInfo(Persons[1]);
}
int main()
{
	strInfo Persons[2];
	ReadPersonsInfo(Persons);
	PrintPersonsInfo(Persons);
	return 0;
}