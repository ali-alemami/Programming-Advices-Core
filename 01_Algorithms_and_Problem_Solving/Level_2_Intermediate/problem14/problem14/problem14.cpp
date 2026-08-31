#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

void PrintInvertedLetterPattern(int Number)
{
	cout << "\n";

	for (int i = Number; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << char(i + 64);
		}
		cout << endl;
	}
}

void PrintInvertedLetterPattern2(int Number)
{
	cout << "\n";

	for (int i = 65 + Number - 1; i >= 65; i--)
	{
		for (int j = 1; j <= Number - (65 + Number - 1 - i); j++)
		{
			cout << char(i);
		}
		cout << endl;
	}
}

int main()
{
	PrintInvertedLetterPattern2(ReadPositiveNumber("Enter a number"));

	return 0;
}