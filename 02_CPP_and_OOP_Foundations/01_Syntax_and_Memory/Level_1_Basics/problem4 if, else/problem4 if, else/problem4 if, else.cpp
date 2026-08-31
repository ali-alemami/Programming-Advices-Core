#include <iostream>
using namespace std;
int main()
{
	int Age;
	bool DriverLicense;
	cout << "Enter your Age\n";
	cin >> Age;

	cout << "Do you have driver license? (type 1 if you have and 0 if u don't)\n";
	cin >> DriverLicense;

	if (Age > 21 && DriverLicense == true)
	{
		cout << "Hired\n";
	}
	else
	{
		cout << "Rejected\n";
	}
}