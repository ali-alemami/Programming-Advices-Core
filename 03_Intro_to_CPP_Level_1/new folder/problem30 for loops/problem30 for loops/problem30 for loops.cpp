#include <iostream>
using namespace std;
void ReadNumber(int& number)
{
	cout << "Enter a number\n";
	cin >> number;
	for (number; number <= 0;)
	{
		cout << "Please enter a positive number\n";
		cin >> number;
	}
}
void CalculateFactorial(int number, int& sum)
{
	sum = 1;
	for (number; number >= 1; number--)
	{
		sum *= number;
	}
}
int main(int number, int sum)
{
	ReadNumber(number);
	CalculateFactorial(number, sum);
	cout << "Factorial is " << sum << endl;
}
