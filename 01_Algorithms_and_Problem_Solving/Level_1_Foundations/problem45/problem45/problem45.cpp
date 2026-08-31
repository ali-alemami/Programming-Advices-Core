#include <iostream>
using namespace std;

enum enMonthOfTheYear { Jan = 1, Feb = 2, Mar = 3,
	Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8,
	Sep = 9, Oct = 10, Nov = 11, Dec = 12 };

int ReadNumberInRange(string Message, int From, int To)
{
	int Number;

	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number < From || Number > To);

	return Number;
}

enMonthOfTheYear ReadMonthOfTheYear()
{
	return enMonthOfTheYear(ReadNumberInRange("Enter a number between 1 and 12", 1, 12));
}

string GetMonthOfTheYear(enMonthOfTheYear MonthOfTheYear)
{
	switch (MonthOfTheYear)
	{
	case Jan:
		return "January";
		break;
	case Feb:
		return "February";
		break;
	case Mar:
		return "March";
		break;
	case Apr:
		return "April";
		break;
	case May:
		return "May";
		break;
	case Jun:
		return "June";
		break;
	case Jul:
		return "July";
		break;
	case Aug:
		return "Auguest";
		break;
	case Sep:
		return "September";
		break;
	case Oct:
		return "October";
		break;
	case Nov:
		return "November";
		break;
	case Dec:
		return "December";
		break;
	}
}

int main()
{
	cout << GetMonthOfTheYear(ReadMonthOfTheYear());

	return 0;
}