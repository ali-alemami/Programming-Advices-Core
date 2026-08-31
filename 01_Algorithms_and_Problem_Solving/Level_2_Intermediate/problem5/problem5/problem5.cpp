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

void PrintReversedNumber(int Number)
{
	int M = 10;

	while(true)
	{
		int Remainder = M / 10;
		int Digit = (Number % M) / Remainder;

		if (Digit < 1)
			break;

		cout << Digit << endl;
		M *= 10;
	}
}

int main()
{
	PrintReversedNumber(ReadPositiveNumber("Enter a number"));

	return 0;
}