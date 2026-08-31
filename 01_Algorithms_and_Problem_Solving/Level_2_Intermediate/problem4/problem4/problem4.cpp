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

bool CheckPerfectNumber(int Number)
{
	int Sum = 0, M = floor(Number / 2);

	for (int i = 1; i <= M; i++)
	{
		if (Number % i == 0)
			Sum += i;
	}
	return Sum == Number;
}

void PerfectNumber1ToN(int Number)
{
	cout << endl;
	for (int i = 1; i <= Number; i++)
	{
		if (CheckPerfectNumber(i))
			cout << i << endl;
	}
}

int main()
{
	PerfectNumber1ToN(ReadPositiveNumber("Enter a number"));

	return 0;
}