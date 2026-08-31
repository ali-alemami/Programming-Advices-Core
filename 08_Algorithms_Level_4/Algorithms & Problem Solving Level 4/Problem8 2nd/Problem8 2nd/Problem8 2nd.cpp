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
	cout << "Enter a month? ";
	cin >> Month;
	return Month;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Year, short Month)
{
	short arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month - 1];
}

short DayOrderOfWeek(short Day, short Month, short Year)
{
	short a = (14 - Month) / 12;
	short y = Year - a;
	short m = Month + (12 * a) - 2;

	short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}

string MonthShortName(short Month)
{
	string arr[12] = { "Jan", "Feb", "Mar",
		"Apr", "May", "Jun",
		"Jul", "Aug", "Sep",
		"Oct", "Nov", "Dec" };

	return arr[Month - 1];
}

void PrintMonthCalendar(short Year, short Month)
{
	int current = DayOrderOfWeek(1, Month, Year);

	int DaysInAMonth = NumberOfDaysInAMonth(Year, Month);

	printf("____________%s____________\n\n", MonthShortName(Month).c_str());

	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	short i = 0;

	for (i = 0; i < current; i++)
	{
		printf("     ");
	}

	for (int j = 1; j <= DaysInAMonth; j++)
	{
		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}
	printf("\n___________________________\n");
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	PrintMonthCalendar(Year, Month);

	return 0;
}