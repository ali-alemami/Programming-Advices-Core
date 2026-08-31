#include <iostream>
using namespace std;
struct strinfo
{
	string firstname;
	string lastname;
	int age;
	string phone;
};
void readinfo(strinfo &info)
{
	cout << "enter your first name\n";
	cin >> info.firstname;

	cout << "enter your last name\n";
	cin >> info.lastname;

	cout << "enter your age\n";
	cin >> info.age;

	cout << "enter your phone\n";
	cin >> info.phone;
}
void printinfo(strinfo& info)
{
	cout << "*****************************\n";
	cout << "FirstName: " << info.firstname << endl;
	cout << "LastName: " << info.lastname << endl;
	cout << "Age: " << info.age << endl;
	cout << "Phone: " << info.phone << endl;
	cout << "*****************************\n";

}
int main()
{
	strinfo person1info;
	readinfo(person1info);
	printinfo(person1info);
	
	return 0;
}