#include <iostream>
using namespace std;

enum enNumberType { Odd = 1, Even = 2 };

int ReadNumber()
{
	int Number;

	cout << "Enter a number ";
	cin >> Number;

	return Number;
}

enNumberType CheckNumber(int Number)
{
	int Result = Number % 2;

	if (Result == 0)
		return enNumberType::Even;
	else
		return enNumberType::Odd;
}

void PrintNumber(enNumberType NumberType)
{
	if (NumberType == enNumberType::Even)
	{
		cout << "\n The number is even\n";
	}
	else
		cout << "\n The number is odd\n";
}

int main()
{
	PrintNumber(CheckNumber(ReadNumber()));

	return 0;
}