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
	/*if (Sum == Number)
		return true;
	else
		return false;*/
	return Sum == Number;
}

void PrintResult(int Number)
{
	if (CheckPerfectNumber(Number))
		cout << Number << " is perfect nubmer!\n\n";
	else
		cout << Number << " is NOT perfect number :(\n\n";
}

int main()
{
	PrintResult(ReadPositiveNumber("Enter a number "));

	return 0;
}