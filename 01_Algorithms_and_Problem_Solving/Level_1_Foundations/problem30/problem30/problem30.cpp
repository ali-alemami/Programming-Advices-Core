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

int Factorial(int Number)
{
	int Factorial = 1;

	for (int i = 1; i <= Number; i++)
	{
		Factorial *= i;
	}
	return Factorial;
}

void PrintResult(int Number)
{
	cout << "Factorial of the number " << Number << " is " << Factorial(Number) << endl;
}

int main()
{
	PrintResult(ReadPositiveNumber("Enter a number"));

	return 0;
}