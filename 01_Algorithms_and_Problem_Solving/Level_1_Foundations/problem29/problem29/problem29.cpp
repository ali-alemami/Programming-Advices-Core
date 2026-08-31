#include <iostream>
using namespace std;

enum enEvenOdd { Even = 1, Odd = 2, All = 3 };

int ReadNumber()
{
	int Number = 0;

	cout << "Enter a number ";
	cin >> Number;

	return Number;
}

enEvenOdd CheckEvenOdd(int Number)
{
	if (Number % 2 == 0)
	{
		return enEvenOdd::Even;
	}
	else
		return enEvenOdd::Odd;
}

int SumFrom1ToNFor(int Number)
{
	cout << "Sum even numbers from 1 to " << Number << " using for\n";
	int sum = 0;

	for (int i = 1; i <= Number; i++)
	{
		if (CheckEvenOdd(i) == enEvenOdd::Even)
		{
			sum += i;
		}
	}
	return sum;
}

int SumFrom1ToNWhile(int Number)
{
	cout << "Sum even numbers from 1 to " << Number << " using while\n";

	int sum = 0, counter = 1;

	while (counter <= Number)
	{
		if (CheckEvenOdd(counter) == enEvenOdd::Even)
		{
			sum += counter;
		}
		counter++;
	}
	return sum;
}

int SumFrom1ToNDoWhile(int Number)
{
	cout << "Sum even numbers from 1 to " << Number << " using do while\n";

	int sum = 0, counter = 1;

	do
	{
		if (CheckEvenOdd(counter) == enEvenOdd::Even)
		{
			sum += counter;
		}
		counter++;
	} while (counter <= Number);

	return sum;
}

int main()
{
	int Number = ReadNumber();

	cout << SumFrom1ToNFor(Number) << endl;
	cout << SumFrom1ToNWhile(Number) << endl;
	cout << SumFrom1ToNDoWhile(Number) << endl;

}