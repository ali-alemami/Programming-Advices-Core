#include <iostream>
#include <string>
using namespace std;
int main()
{
	int number;
	string name;
	string country;
	cout << "enter student number\n";
	cin >> number;

	cout << "enter student name\n";
	cin.ignore(1, '\n');
	getline(cin, name);

	cout << "enter student country\n";
	cin >> country;

	cout << endl << "number: " << number << endl;
	cout << "name: " << name << endl;
	cout << "country: " << country << endl;
	return 0;

}