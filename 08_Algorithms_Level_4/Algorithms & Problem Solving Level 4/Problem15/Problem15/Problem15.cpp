#include <iostream>
using namespace std;

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short ReadYear()
{
	short Year = 0;
	cout << "Enter a year? ";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month = 0;
	cout << "Enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadDay()
{
	short Day = 0;
	cout << "Enter a Day? ";
	cin >> Day;
	return Day;
}

struct sDate
{
	short Year,
		Month,
		Day;
};

sDate ReadFullDate()
{
	sDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
	{
		return 0;
	}

	short arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month - 1];
}

bool IsLastDayInAMonth(sDate Date)
{
	return Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year) ? true : false;
}

bool IsLastMonthInAYear(short Month)
{
	return (Month == 12);
}

int main()
{
	sDate Date = ReadFullDate();

	if (IsLastDayInAMonth(Date))
		cout << "\nYes, Day is Last day in Month\n";

	else
		cout << "\nNo, Day is NOT Last day in Month\n";

	if (IsLastMonthInAYear(Date.Month))
		cout << "\nYes, Month is Last day in Year\n";

	else
		cout << "\nNo, Month is NOT Last day in Year\n";
}