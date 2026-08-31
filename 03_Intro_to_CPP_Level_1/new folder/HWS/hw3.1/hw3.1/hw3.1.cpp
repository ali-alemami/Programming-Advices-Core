#include <iostream>
using namespace std;
short int main()
{
	string Name = "Ali Al-emame.";
	unsigned short int Age = 19;
	string City = "Zarqa.";
	string Country = "Jordan.";
	float MonthlySalary = 5000;
	unsigned char Gender = 'M';
	bool isMarried = true;



	cout << "*************************************\n";
	cout << "Name: " << Name << "\n";
	cout << "Age : " << Age << " Years.\n";
	cout << "City: " << City << "\n";
	cout << "Country: " << Country << "\n";
	cout << "Monthly Salary: " << MonthlySalary << "\n";
	cout << "Yearly Salary: " << MonthlySalary * 12 << "\n";
	cout << "Gender: " << Gender << "\n";
	cout << "Married: " << isMarried << endl;
	cout<< "*************************************\n";
	return 0;

}