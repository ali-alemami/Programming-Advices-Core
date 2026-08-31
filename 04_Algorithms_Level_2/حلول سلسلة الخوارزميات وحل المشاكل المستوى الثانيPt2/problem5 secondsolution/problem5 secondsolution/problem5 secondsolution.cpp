#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number = 0;

	cout << Message << endl;
	cin >> Number;

	return Number;
}

void PrintReversedNumber(int Number)
{
	while (Number > 0)
	{
		int Remainder = Number % 10;
		Number /= 10;
		cout << Remainder << endl;
	}
}

int main()
{
	PrintReversedNumber(ReadPositiveNumber("Enter a number"));

	return 0;
}