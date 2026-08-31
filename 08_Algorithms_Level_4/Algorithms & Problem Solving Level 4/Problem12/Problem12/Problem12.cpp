#include <iostream>
using namespace std;

short ReadYear()
{
	short Year = 0;
	cout << "Enter a year? ";
	cin >> Year;
	cout << endl;
	return Year;
}

short ReadMonth()
{
	short Month = 0;
	cout << "Enter a Month? ";
	cin >> Month;
	cout << endl;
	return Month;
}

short ReadDay()
{
	short Day = 0;
	cout << "Enter a Day? ";
	cin >> Day;
	cout << endl;
	return Day;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
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

short NumberOfDaysSinceTheBeginningOfTheYear(short Day, short Month, short Year)
{
	short TotalDays = 0;

	for (short i = 1; i < Month; i++)
	{
		TotalDays += NumberOfDaysInAMonth(i, Year);
	}
	TotalDays += Day;

	return TotalDays;
}

struct sDate
{
	short Year,
		Month,
		Day;
};

sDate GetDateFromDayOrderOfAYear(short DayOrderOfAYear, short Year)
{
	sDate Date;

	short RemainingDays = DayOrderOfAYear;
	short DaysInAMonth = 0;

	Date.Year = Year;
	Date.Month = 1;

	while (true)
	{
		DaysInAMonth = NumberOfDaysInAMonth(Date.Month, Year);
		
		if (RemainingDays > DaysInAMonth)
		{
			RemainingDays -= DaysInAMonth;
			Date.Month++;
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}
	return Date;
}

sDate GetDateAfterAddingDaysToDate(short DaysToAdd, sDate Date)
{
	short DayOrder;

	DayOrder = NumberOfDaysSinceTheBeginningOfTheYear(Date.Day, Date.Month, Date.Year);

	
	int TotalDayOrder = DayOrder + DaysToAdd;

	while ((IsLeapYear(Date.Year) && TotalDayOrder >= 366) || (!IsLeapYear(Date.Year) && TotalDayOrder >= 365))
	{
		Date.Year++;
		Date.Month = 1;
		Date.Day = 1;

		if (IsLeapYear(Date.Year))
		{
			TotalDayOrder -= 366;
		}
		else
		{
			TotalDayOrder -= 365;
		}
	}

	return GetDateFromDayOrderOfAYear(TotalDayOrder, Date.Year);
}

short ReadNumber(string Message)
{
	short Number = 0;
	cout << Message;
	cin >> Number;
	return Number;
}

sDate ReadFullDate()
{
	sDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

sDate DateAddDays(short Days, sDate Date)
{
	short RemainingDays = Days +
		NumberOfDaysSinceTheBeginningOfTheYear(Date.Day, Date.Month, Date.Year);
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

int main()
{

	sDate Date = ReadFullDate();

	short DaysToAdd = ReadNumber("How many days to add? ");
	cout << endl;

	Date = DateAddDays(DaysToAdd, Date);

	cout << "Date after adding [" << DaysToAdd << "] days is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	return 0;
}