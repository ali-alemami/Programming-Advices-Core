#include <iostream>
#include <string>

using namespace std;

enum enNumberType { Prime = 1, NotPrime = 2 };

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

enNumberType CheckPrime(int Number)
{
	int M = round(Number / 2);

	for (int i = 2; i <= M; i++)
	{
		if (Number % i == 0)
		{
			return enNumberType::NotPrime;
		}
	}
	return enNumberType::Prime;
}

void PrintPrimeNumbersFrom1ToN(int Number)
{
	cout << "\n Prime Numbers From 1 to " + to_string(Number) + " are\n";

	for (int i = 1; i <= Number; i++)
	{
		if (CheckPrime(i) == enNumberType::Prime)
		{
			cout << i << endl;
		}
	}
}

int main()
{
	PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("Enter N:"));

	return 0;
}