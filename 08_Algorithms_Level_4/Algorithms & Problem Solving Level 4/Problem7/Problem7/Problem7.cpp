#include <iostream>

using namespace std;

int ReadYear()
{
	int Year = 0;
	cout << "Enter a year? ";
	cin >> Year;
	return Year;
}

int ReadMonth()
{
	int Month = 0;
	cout << "Enter a month? ";
	cin >> Month;
	return Month;
}

int ReadDay()
{
	int Day = 0;
	cout << "Enter a day? ";
	cin >> Day;
	return Day;
}

int CalculateDayOrder(int Day, int Month, int Year)
{
	int a = (14 - Month) / 12;
	int y = Year - a;
	int m = Month + 12 * a - 2;

	int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}

string DayNumberToName(short DayNumber)
{
	string arr[7] = { "Sunday", "Monday", "Tuesday", "Wednsday", "Thursday", "Friday", "Saturday" };
	return arr[DayNumber];
}

void PrintInfo(int Day, int Month, int Year)
{
	cout << "Date      : " << Day << "/" << Month << "/" << Year << endl;
	cout << "Day Order : " << CalculateDayOrder(Day, Month, Year) << endl;
	cout << "Day Name  : " << DayNumberToName(CalculateDayOrder(Day, Month, Year)) << endl;
}

int main()
{
	int Year = ReadYear(),
		Month = ReadMonth(),
		Day = ReadDay();

	PrintInfo(Day, Month, Year);

	system("pause > 0");
	return 0;
}