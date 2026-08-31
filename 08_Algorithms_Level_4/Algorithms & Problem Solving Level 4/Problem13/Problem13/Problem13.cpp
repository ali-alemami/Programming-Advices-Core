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

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	short arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month - 1];
}

short NumberOfDaysSinceTheBeginningOfTheYear(short Day, short Month, short Year)
{
	short RemainingDays = 0;

	for (short i = 1; i < Month; i++)
	{
		RemainingDays += NumberOfDaysInAMonth(i, Year);
	}
	RemainingDays += Day;

	return RemainingDays;
}

bool MaxDate(sDate Date1, sDate Date2)
{
	if (Date1.Year > Date2.Year)
	{
		return false;
	}
	else if (Date1.Year < Date2.Year)
	{
		return true;
	}
	else if (NumberOfDaysSinceTheBeginningOfTheYear(Date1.Day, Date1.Month, Date1.Year) >
		NumberOfDaysSinceTheBeginningOfTheYear(Date2.Day, Date2.Month, Date2.Year))
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ?
		(Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ?
			Date1.Day < Date2.Day : false)) : false);
}

int main()
{
	sDate Date1 = ReadFullDate();
	cout << endl;
	sDate Date2 = ReadFullDate();

	if (MaxDate(Date1, Date2))
	{
		cout << "Yes, Date 1 is less than date 2\n";
	}
	else
	{
		cout << "No, Date 1 is NOT less than date2\n";
	}
}