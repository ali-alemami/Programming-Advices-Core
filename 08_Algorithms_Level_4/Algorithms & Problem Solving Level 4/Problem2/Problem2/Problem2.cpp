#include <iostream>

using namespace std;

short ReadYear()
{
	short Year = 0;
	cout << "Enter a year to check? ";
	cin >> Year;
	return Year;
}

bool IsLeapYear(short Year)
{
	if (Year % 400 == 0)
	{
		return true;
	}
	else if (Year % 4 == 0 && Year % 100 != 0)
	{
		return true;
	}
	else
		return false;
}

bool IsLeapYear2(short Year)
{
	if (Year % 400 == 0)
	{
		return true;
	}
	else if (Year % 100 == 0)
	{
		return false;
	}
	else if (Year % 4 == 0)
	{
		return true;
	}
	else
		return false;
}

bool IsLeapYear3(short Year)
{
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

int main()
{
	short Year = ReadYear();

	if (IsLeapYear(Year))
		cout << "/nYes, Year " << Year << " is a Leap Year.";
	else
		cout << "/nNo, Year " << Year << " is NOT a Leap Year.";

	system("pause > 0");
	return 0;
}