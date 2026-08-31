#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Enter a number ";
	cin >> Number;

	return Number;
}

enum enEvenOdd { Even = 1, Odd = 2 };

enEvenOdd CheckEvenOdd(int Number)
{
	if (Number % 2 == 0)
		return Even;
	else
		return Odd;
}

int PrintOddNumbersFrom1ToNFor(int Number)
{
	int sum = 0;
	cout << "Print from 1 to n using for \n";
	for (int i = 1; i <= Number; i++)
	{
		if (CheckEvenOdd(i) == Odd)
		{
			cout << i << endl;
			sum += i;
		}
	}
	return sum;
}

int PrintOddNumbersFrom1ToNDoWhile(int Number)
{
	cout << "Print from 1 to n using do while \n";

	int counter = 1, sum = 0;

	do
	{
		if (CheckEvenOdd(counter) == Odd) 
		{
			cout << counter << endl;
			sum += counter;
		}
		
		counter++;
	} while (counter <= Number);

	return sum;
}

int PrintOddNumbersFrom1ToNWhile(int Number)
{
	cout << "Print from 1 to n using while \n";

	int counter = 1, sum = 0;

	while (counter <= Number)
	{
		if (CheckEvenOdd(counter) == Odd)
		{
			cout << counter << endl;
			sum += counter;
		}
		
		counter++;
	}
	return sum;
}

int main()
{
	int counter = ReadNumber();

	cout << PrintOddNumbersFrom1ToNFor(counter) << endl;
	cout << PrintOddNumbersFrom1ToNDoWhile(counter) << endl;
	cout << PrintOddNumbersFrom1ToNWhile(counter) << endl;

	return 0;

}