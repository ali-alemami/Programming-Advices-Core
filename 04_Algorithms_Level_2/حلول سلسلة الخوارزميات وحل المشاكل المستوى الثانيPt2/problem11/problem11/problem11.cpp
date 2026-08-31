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

int ReverseNumber(int Number)
{
	int Remainder = 0, Number2 = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		Number2 = (Number2 * 10) + Remainder;
	}
	return Number2;
}

bool CheckPalindrome(int Number)
{
	return Number == ReverseNumber(Number);
}

void PrintResult(int Number)
{
	if (CheckPalindrome(Number))
		cout << "\n Number is Palindrome\n";
	else
		cout << "\n Number is NOT Palindrome\n";
}

int main()
{
	PrintResult(ReadPositiveNumber("Enter a number"));

	return 0;
}