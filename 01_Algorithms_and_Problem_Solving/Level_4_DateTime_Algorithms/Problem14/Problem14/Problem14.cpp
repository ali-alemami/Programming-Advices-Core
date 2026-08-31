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

bool IsDate1EqualsDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? (Date1.Day == Date2.Day ? true : false) : false) : false);
}

int main()
{
	sDate Date1 = ReadFullDate();
	cout << endl;
	sDate Date2 = ReadFullDate();

	if (IsDate1EqualsDate2(Date1, Date2))
	{
		cout << "\nYes, Date1 is equal to Date2\n";
	}
	else
	{
		cout << "\nNo, Date1 is NOT equal to Date2\n";
	}

	return 0;
}