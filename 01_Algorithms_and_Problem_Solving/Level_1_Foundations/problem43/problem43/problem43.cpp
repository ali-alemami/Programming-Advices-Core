#include <iostream>
using namespace std;

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

struct stTaskDuration
{
	int Days, Hours, Minutes, Seconds;
};

stTaskDuration SecondsToTaskDuration(int TotalSeconds)
{
	stTaskDuration TaskDuration;

	const int SecondsPerDay = 24 * 60 * 60;
	const int SecondsPerHour = 60 * 60;
	const int SecondsPerMinute = 60;

	TaskDuration.Days = floor(TotalSeconds / SecondsPerDay);
	int Remainder = TotalSeconds % SecondsPerDay;

	TaskDuration.Hours = floor(Remainder / SecondsPerHour);
	Remainder = Remainder % SecondsPerHour;

	TaskDuration.Minutes = floor(Remainder / SecondsPerMinute);
	Remainder = Remainder % SecondsPerMinute;

	TaskDuration.Seconds = Remainder;

	return TaskDuration;
}

void PrintTaskDuration(stTaskDuration TaskDuration)
{
	cout << TaskDuration.Days << ":" <<
		TaskDuration.Hours << ":" <<
		TaskDuration.Minutes << ":" <<
		TaskDuration.Seconds << endl;
}

int main()
{
	PrintTaskDuration(SecondsToTaskDuration(ReadPositiveNumber("Enter the number of Seconds ")));

	return 0;
}