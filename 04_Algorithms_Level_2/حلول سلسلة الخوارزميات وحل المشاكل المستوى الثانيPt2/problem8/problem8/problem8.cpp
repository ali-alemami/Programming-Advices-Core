#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

int DigitFrequency(int Number, int Digit)
{
	int Remainder = 0, Counter = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;

		if (Remainder == Digit)
			Counter++;
	}
	return Counter;
}

int main()
{
	int Number = ReadPositiveNumber("Enter the main number");
	short Digit = ReadPositiveNumber("Enter one digit to check");

	cout << "\nDigit Frequency is " << DigitFrequency(Number, Digit) << " Time(s).\n\n";

	return 0;
}