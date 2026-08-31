#include <iostream>
using namespace std;

enum enDay { Saturday = 1, Sunday = 2, Monday = 3,
	Tuesday = 4, Wednesday = 5, Thursday = 6,
	Friday = 7 };

int ReadNumber(string Message, int From, int To)
{
	int Number;

	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number < From || Number > To);

	return Number;
}

enDay ReadDayOfTheWeek()
{
	return enDay(ReadNumber("Enter a number between 1 and 7", 1, 7));
}

string WhichDayOfTheWeek(enDay Day)
{
	switch (Day)
	{
	case Saturday:
		return "Saturday";
		break;
	case Sunday:
		return "Sunday";
		break;
	case Monday:
		return "Monday";
		break;
	case Tuesday:
		return "Tuesday";
		break;
	case Wednesday:
		return "Wednesday";
		break;
	case Thursday:
		return "Thursday";
		break;
	case Friday:
		return "Friday";
		break;
	}
}

void PrintDay(string Day)
{
	cout << "It's " << Day << endl;
}

int main()
{
	PrintDay(WhichDayOfTheWeek(ReadDayOfTheWeek()));

	return 0;
}
