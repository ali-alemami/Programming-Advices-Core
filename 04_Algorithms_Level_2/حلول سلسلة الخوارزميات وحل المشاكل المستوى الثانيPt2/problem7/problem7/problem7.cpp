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

int ReversedNumber(int Number)
{
	int ReversedNumber = 0, Remainder = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		ReversedNumber = (ReversedNumber * 10) + Remainder;
	}
	return ReversedNumber;
}

int main()
{
	cout << ReversedNumber(ReadPositiveNumber("Enter a number"));

	return 0;
}