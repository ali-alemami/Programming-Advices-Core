#include <iostream>
#include <string>
#include <cctype>

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

short DayOrderOfWeek(short Day, short Month, short Year)
{
	short a = (14 - Month) / 2;
	short y = Year - a;
	short m = Month + (12 * a) - 2;

	short d = (Day + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}

string DayShortName(short DayOrderOfWeek)
{
	string arr[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return arr[DayOrderOfWeek];
}

string MonthShortName(short Month)
{
	string arr[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	return arr[Month - 1];
}

short DaysInMonth(short Year, short Month)
{
	short arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month - 1];
}

void PrintMonthCalendar(short Month, short Year)
{
	cout << "\n\n_______________" << MonthShortName(Month) << "_______________\n\n";

	for (short i = 0; i <= 6; i++)
	{
		cout << DayShortName(i) << "  ";
	}
	cout << endl;

	for (short j = 1, i = 0, k = 1; j <= DaysInMonth(Year, Month); j++, k++)
	{
		if (i == DayOrderOfWeek(1, Month, Year))
		{
			if (j < 10)
			{
				cout << " " << j << "   ";
			}
			else
			{
				cout << j << "   ";
			}
		}
		else
		{
			i++;
			j--;
			cout << "     ";
		}
		if (k % 7 == 0)
		{
			cout << endl;
		}
	}

}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	PrintMonthCalendar(Month, Year);

	system("pause>0");
	return 0;
}