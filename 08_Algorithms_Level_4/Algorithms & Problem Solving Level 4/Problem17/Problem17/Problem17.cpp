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
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
	return Month == 12;
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

short NumberOfDaysSinceTheBegingOfTheYear(sDate Date)
{
	short DayOrder = 0;

	for (short i = 1; i < Date.Month; i++)
	{
		DayOrder += NumberOfDaysInAMonth(i, Date.Year);
	}
	DayOrder += Date.Day;
	return DayOrder;
}

sDate DateAddDays(short DaysToAdd, sDate Date)
{
	short RemainingDays = DaysToAdd + NumberOfDaysSinceTheBegingOfTheYear(Date);

	short MonthDays = 0;
	Date.Month = 1;

	while (true)
	{
		MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;

			if (Date.Month > 12)
			{
				Date.Year++;
				Date.Month = 1;
			}
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}
	return Date;
}

short DifferenceBetween2Dates(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
	if (Date1.Year == Date2.Year)
	{
		short DateDiff = NumberOfDaysSinceTheBegingOfTheYear(Date2) - NumberOfDaysSinceTheBegingOfTheYear(Date1);
		return (IncludeEndDay) ? DateDiff + 1 : DateDiff;
	}

	short i = 1;

	sDate Date = Date1;

	while (!((Date2.Year == Date.Year) && (Date2.Month == Date.Month) && (Date2.Day == Date.Day)))
	{
		Date = DateAddDays(i, Date1);
		i++;
	}
	--i;

	return (IncludeEndDay) ? i + 1 : i;
}

////////////////////

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true :
		((Date1.Year == Date2.Year) ?
			(Date1.Month < Date2.Month ? true :
				(Date1.Month == Date2.Month ?
					(Date1.Day < Date2.Day) :
					false)) : false);
}

int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;

	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Date1 = IncreaseDateByOneDay(Date1);
		Days++;
	}
	return IncludeEndDay ? ++Days : Days;
}

int main()
{
	sDate Date1 = ReadFullDate();
	cout << endl;
	sDate Date2 = ReadFullDate();

	cout << "\nDifference is: " << GetDifferenceInDays(Date1, Date2) << " Day(s)\n";
	cout << "\nDifference (Including end day) is: " << GetDifferenceInDays(Date1, Date2, true) << " Day(s).\n";

	system("pause>0");
	return 0;
}