#include <iostream>

using namespace std;

short ReadYear()
{
	short Year = 0;
	cout << "Enter a year to check? ";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month = 0;
	cout << "Enter a month? ";
	cin >> Month;
	return Month;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
	{
		return 0;
	}

	if (Month == 2) return IsLeapYear(Year) ? 29 : 28;

	else return ((Month <= 7 && Month % 2 != 0) || (Month >= 7 && Month % 2 == 0)) ? 31 : 30;
}

short NumberOfDaysInMonth2(short Month, short Year)
{
	if (Month < 1 || Month > 12)
	{
		return 0;
	}

	short NumberOfDays[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month];
}

int main()
{
	short Year = ReadYear(),
		Month = ReadMonth();

	cout << NumberOfDaysInMonth(Month, Year) << endl;

	system("pause > 0");
	return 0;
}