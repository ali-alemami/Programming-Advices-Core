#include <iostream>
using namespace std;

enum enPrime { Prime = 1, NotPrime = 2 };

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

enPrime CheckPrime(int Number)
{
	int M = round(Number / 2);

	for (int i = 2; i <= M; i++)
	{
		if (Number % i == 0)
			return enPrime::NotPrime;
	}
	return enPrime::Prime;
}

void PrintResult(int Number)
{
	switch (CheckPrime(Number))
	{
	case enPrime::Prime:
		cout << "\n The number is prime";
		break;
	case enPrime::NotPrime:
		cout << "\n The number is not prime";
		break;
	}
}

int main()
{
	PrintResult(ReadPositiveNumber("Enter a number"));

	return 0;
}