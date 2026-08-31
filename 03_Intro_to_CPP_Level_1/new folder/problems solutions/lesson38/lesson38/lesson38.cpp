#include <iostream>
using namespace std;

struct strinfo
{
	string FirstName;
	string LastName;
	int Age;
	string PhoneNumber;
};

void ReadInfo(strinfo& info)
{
	cout << "enter fname\n";
	cin >> info.FirstName;

	cout << "enter lastname\n";
	cin >> info.LastName;

	cout << "enter age\n";
	cin >> info.Age;

	cout << "enter phone\n";
	cin >> info.PhoneNumber;

}
void PrintInfo(strinfo info)
{
	cout << info.FirstName << endl;
	cout << info.LastName << endl;
	cout << info.Age << endl;
	cout << info.PhoneNumber << endl;
}

int main()
{

	strinfo person1;
	ReadInfo(person1);
	PrintInfo(person1);

	return 0;
}