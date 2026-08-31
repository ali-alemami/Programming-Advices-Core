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

int CountDigitFrequency(int Number, int Digit)
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

void PrintNumbersFrequency(int Number)
{
	cout << endl;

	for (int i = 0; i <= 9; i++)
	{
		short DigitFrequency = CountDigitFrequency(Number, i);

		if (DigitFrequency > 0)
		{
			cout << "Digit " << i << " Frequency is "
				<< DigitFrequency << " Time(s)\n";
		}
	}
}

int main()
{
	int Number = ReadPositiveNumber("Enter the main Number");

	PrintNumbersFrequency(Number);

	return 0;
}