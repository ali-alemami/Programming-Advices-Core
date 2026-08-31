#include <iostream>
using namespace std;

struct stInfo
{
	int Days, Hours, Minutes, Seconds;
};

int ReadPositiveNumber(string Message)
{
	int Number;

	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number < 0);

	return Number;
}

stInfo ReadInfo()
{
	stInfo Info;

	Info.Days = ReadPositiveNumber   ("How many Days    ? ");
	Info.Hours = ReadPositiveNumber  ("How many Hours   ? ");
	Info.Minutes = ReadPositiveNumber("How many Minutes ? ");
	Info.Seconds = ReadPositiveNumber("How many Seconds ? ");

	return Info;
}

int ToSeconds(stInfo Info)
{
	

	int DaysToSeconds = Info.Days * 24 * 60 * 60;
	int HoursToSeconds = Info.Hours * 60 * 60;
	int MinitesToSeconds = Info.Minutes * 60;

	int TotalSeconds = DaysToSeconds + HoursToSeconds + MinitesToSeconds + Info.Seconds;

	return TotalSeconds;
}

int main()
{

	cout << "Total Seconds = " << ToSeconds(ReadInfo()) << endl;

	return 0;
}