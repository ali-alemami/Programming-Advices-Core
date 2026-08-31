#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	}while (Number <= 0);
	
	return Number;
}

int SumOfDigits(int Number)
{
	int Sum = 0, Remainder = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		Sum += Remainder;
	}
	return Sum;
}

int main()
{
	cout <<"Sum of digits = "
		<< SumOfDigits(ReadPositiveNumber("Enter a number")) << endl;

	return 0;
}