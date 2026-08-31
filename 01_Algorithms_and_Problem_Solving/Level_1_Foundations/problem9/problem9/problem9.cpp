#include <iostream>
#include <string>
using namespace std;

int ReadNumber()
{
	int Num;

	cout << "Enter a number ";
	cin >> Num;

	return Num;
}

int CalculateSum(int Num1, int Num2, int Num3)
{
	int Result = Num1 + Num2 + Num3;

	return Result;
}

void PrintResult(int Result)
{
	cout << "The sum of the numbers is " << Result << endl;
}

int main()
{
	PrintResult(CalculateSum(ReadNumber(), ReadNumber(), ReadNumber()));

	return 0;
}