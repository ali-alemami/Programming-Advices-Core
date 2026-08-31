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

bool IsLastDayInMonth(sDate Date)
{
	return Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year);
}

bool IsLastMonthInYear(short Month)
{
	return Month == 12;
}

sDate IncreaseDateBy1(sDate Date)
{
	if (IsLastDayInMonth(Date) && IsLastMonthInYear(Date.Month))
	{
		Date.Year++;
		Date.Month = 1;
		Date.Day = 1;
	}
	else if (IsLastDayInMonth(Date))
	{
		Date.Month++;
		Date.Day = 1;
	}
	else
	{
		Date.Day++;
	}
	return Date;
}

sDate IncreaseDateByOneDay(sDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Year++;
			Date.Month = 1;
			Date.Day = 1;
		}
		else
		{
			Date.Month++;
			Date.Day = 1;
		}
	}
	else
	{
		Date.Day++;
	}
	return Date;
}

int main()
{
	sDate Date = ReadFullDate();

	Date = IncreaseDateBy1(Date);

	cout << "Date after adding one day is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	return 0;
}