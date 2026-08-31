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
	cout << "Enter your Age\n";
	cin >> info.Age;
	cout << "Enter your Phone\n";
	cin >> info.Phone;
}

void PrintInfo(strInfo info)
{
	cout << "**************************************\n";
	cout << "First Name: " << info.FirstName << endl;
	cout << "Last Name: " << info.LastName << endl;
	cout << "Age: " << info.Age << endl;
	cout << "Phone: " << info.Phone << endl;
	cout << "**************************************\n";
}

void ReadAllInfo(strInfo persons[100], int& x)
{
	cout << "How many cards do you want?\n";
	cin >> x;
	for (int counter = 0; counter <= x-1; counter++)
	{
		cout << "Please enter person's " << counter + 1 << " info:\n";
		ReadInfo(persons[counter]);
	}
}

void PrintAllInfo(strInfo persons[100], int x)
{
	for (int counter = 0; counter <= x-1; counter++)
	{
		cout << "Person's " << counter + 1 << "info:\n";
		PrintInfo(persons[counter]);
	}
}

int main()
{
	strInfo persons[100];
	int x;

	ReadAllInfo(persons, x);
	PrintAllInfo(persons, x);

	return 0;
}