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
	short Month;
	cout << "Enter a month to check? ";
	cin >> Month;
	return Month;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
	{
		return 31;
	}

	else if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
	{
		return 30;
	}

	else if (IsLeapYear(Year))
	{
		return 29;
	}

	else
		return 28;
}

short NumberOfDaysInMonth2(short Month, short Year)
{
	if (Month < 1 || Month > 12)
	{
		return 0;
	}
	else if (Month == 2)
	{
		return IsLeapYear(Year) ? 29 : 28;
	}

	short arr31Days[7] = { 1,3,5,7,8,10,12 };

	for (short i = 0; i <= 6; i++)
	{
		if (arr31Days[i] == Month)
		{
			return 31;
		}
	}
	return 30;
}

short NumberOfHoursInMonth(short Month, short Year)
{
	return NumberOfDaysInMonth(Month, Year) * 24;
}

int NumberOfMinutesInMonth(short Month, short Year)
{
	return NumberOfHoursInMonth(Month, Year) * 60;
}

int NumberOfSecondsInMonth(short Month, short Year)
{
	return NumberOfMinutesInMonth(Month, Year) * 60;
}

int main()
{
	short Year = ReadYear(),
		Month = ReadMonth();

	cout << "Number of Days in Month [" << Month << "] is " << NumberOfDaysInMonth(Month, Year) << endl;
	cout << "Number of Hours in Month [" << Month << "] is " << NumberOfHoursInMonth(Month, Year) << endl;
	cout << "Number of Minutes in Month [" << Month << "] is " << NumberOfMinutesInMonth(Month, Year) << endl;
	cout << "Number of Seconds in Month [" << Month << "] is " << NumberOfSecondsInMonth(Month, Year) << endl;

	system("pause > 0");
	return 0;
}