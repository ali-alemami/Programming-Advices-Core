#include <iostream>
using namespace std;

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

bool IsLeapYear(short Year)
{
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	short arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month - 1];
}

short NumberOfDaysSinceTheBeginningOfTheYear(short Day, short Month, short Year)
{
	short TotalDays = 0;

	for (short i = 1; i < Month; i++)

		TotalDays += NumberOfDaysInAMonth(i, Year);

	TotalDays += Day;

	return TotalDays;
}

int main()
{
	short Day = ReadDay();
	cout << endl;
	short Month = ReadMonth();
	cout << endl;
	short Year = ReadYear();
	
	
	
	cout << "\nNumber of days since the beginning of the year is "
		<< NumberOfDaysSinceTheBeginningOfTheYear(Day, Month, Year) << endl;
}