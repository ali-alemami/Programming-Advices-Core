#include <iostream>
using namespace std;

void ReadNumbers(int& num1, int& num2, int& num3)
{
	cout << "Enter number1 ";
	cin >> num1;

	cout << "Enter number2 ";
	cin >> num2;

	cout << "Enter number3 ";
	cin >> num3;
}

int CalculateSum(int num1, int num2, int num3)
{
	return num1 + num2 + num3;
}

void PrintResult(int Result)
{
	cout << "The sum of the 3 number is " << Result << endl;
}

int main()
{
	int num1, num2, num3;

	ReadNumbers(num1, num2, num3);
	PrintResult(CalculateSum(num1, num2, num3));

	return 0;
}