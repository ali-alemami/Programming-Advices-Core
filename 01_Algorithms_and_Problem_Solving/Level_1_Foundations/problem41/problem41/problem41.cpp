#include <iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
	int Number;

	cout << Message << endl;
	cin >> Number;

	return Number;
}

float HourstoDays(float NumberOfHours)
{
	float NumberOfDays;

	NumberOfDays = NumberOfHours / 24;

	return NumberOfDays;
}

float DaysToWeeks(float NumberOfDays)
{
	float NumberOfWeeks;

	NumberOfWeeks = NumberOfDays / 7;

	return NumberOfWeeks;
}

int main()
{
	float NumberOfHours = ReadPositiveNumber("Enter the number of hours ");
	float NumberOfDays = HourstoDays(NumberOfHours);
	float NumberOfWeeks = DaysToWeeks(NumberOfDays);

	cout << "Total hours = " << NumberOfHours << " hours " << endl;
	cout << "Total of days  = " << NumberOfDays << " days " << endl;
	cout << "Total weeks = " << NumberOfWeeks << " weeks " << endl;

	return 0;
}