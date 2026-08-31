#include <iostream>

using namespace std;

short ReadYear()
{
	short Year = 0;
	cout << "Enter a year to Check? ";
	cin >> Year;
	return Year;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDaysInYear(short Year)
{
	return IsLeapYear(Year) ? 366 : 365;
}

int NumberOfHoursInYear(short Year)
{
	return NumberOfDaysInYear(Year) * 24;
}

int NumberOfMinutesInYear(short Year)
{
	return NumberOfHoursInYear(Year) * 60;
}

int NumberOfSecondsInYear(short Year)
{
	return NumberOfMinutesInYear(Year) * 60;
}

int main()
{
	short Year = ReadYear();

	cout << "Number Of Days in year " << Year << " is "
		<< NumberOfDaysInYear(Year) << endl;

	cout << "Number Of Hours in year " << Year << " is "
		<< NumberOfHoursInYear(Year) << endl;

	cout << "Number Of Minutes in year " << Year << " is "
		<< NumberOfMinutesInYear(Year) << endl;

	cout << "Number Of Seconds in year " << Year << " is "
		<< NumberOfSecondsInYear(Year) << endl;

	system("pause > 0");
	return 0;
}
