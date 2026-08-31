#include <iostream>
using namespace std;
int main()
{
	string Name, City, Country; short unsigned int Age; float MonthlySalary; unsigned char Gender; bool isMarried;
	cout << "Pleas Enter Your Name: \n";
	cin >> Name;

	cout << "Please Enter YOUR Age: \n";
	cin >> Age;

	cout << "Please Choose A City: \n";
	cin >> City;

	cout << "Please Select A Country: \n";
	cin >> Country;

	cout << "please Add Your Monthly Salary: \n";
	cin >> MonthlySalary;

	cout << "What Is Your Gender M/F? \n";
	cin >> Gender;

	cout << "Are You Married? 1/0 \n";
	cin >> isMarried;


	cout << "*********************************************\n";
	cout << "Name: " << Name << "\n";
	cout << "Age  : " << Age << "\n";
	cout << "City: " << City << "\n";
	cout << "Country: " << Country << "\n";
	cout << "Monthly Salary: " << MonthlySalary << "\n";
	cout << "Yearly Salary: " << MonthlySalary * 12 << "\n";
	cout << "Gender: " << Gender << "\n";
	cout << "Married: " << isMarried << "\n";
	cout << "*********************************************\n\n\n\n\n";



	return 0;

}