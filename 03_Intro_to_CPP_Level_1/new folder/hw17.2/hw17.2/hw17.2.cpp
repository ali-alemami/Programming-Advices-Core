#include <iostream>
#include <string>
using namespace std;
struct strinfo
{
	string name;
	int age;
	string country;
	string city;
	float monthlysalary;
	float yearlysalary;
	char gender;
	bool married;
};

void readinfo(strinfo &info)
{
	cout << "enter your name\n";
	getline(cin, info.name);

	cout << "enter your age\n";
	cin >> info.age;

	cout << "chose your country\n";
	cin >> info.country;

	cout << "chose a city\n";
	cin >> info.city;

	cout << "add your monthly salary\n";
	cin >> info.monthlysalary;

	cout << "what's your gender?\n";
	cin >> info.gender;

	cout << "are you married?\n";
	cin >> info.married;
}
void printinfo(strinfo& info)
{
	cout << endl << "*****************************\n";
	cout << "Name: " << info.name << endl;
	cout << "Age : " << info.age << endl;
	cout << "City: " << info.city<< endl;
	cout << "Country: " << info.country << endl;
	cout << "MonthlySalary: " << info.monthlysalary << endl;
	cout << "YearlySalary: " << info.monthlysalary * 12 << endl;
	cout << "Gender: " << info.gender << endl;
	cout << "Married: " << info.married << endl;
	cout << "*****************************\n";

}
int main()
{
	strinfo mycard;
	readinfo(mycard);
	printinfo(mycard);
	
	return 0;
}