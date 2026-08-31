#include <iostream>
using namespace std;

enum enPassFail { Pass = 1, Fail = 2 };

void ReadNumbers(int& num1, int& num2, int& num3)
{
	cout << "Enter number 1 ";
	cin >> num1;

	cout << "Enter number 2 ";
	cin >> num2;

	cout << "Enter number 3 ";
	cin >> num3;
}

int Sum3Numbers(int num1, int num2, int num3)
{
	int Result = num1 + num2 + num3;

	return Result;
}

float CalcualteAverage(int num1, int num2, int num3)
{
	return (float)Sum3Numbers(num1, num2, num3) / 3;
}

enPassFail CheckAverage(float avg)
{
	if (avg >= 50)
	{
		return enPassFail::Pass;
	}
	else
		return enPassFail::Fail;
}

void PrintResult(float avg)
{
	cout << "Your average is: " << avg << endl;

	if (CheckAverage(avg) == enPassFail::Pass)
	{
		cout << "PASS";
	}
	else
	{
		cout << "FAIL";
	}
}

int main()
{
	int num1, num2, num3;

	ReadNumbers(num1, num2, num3);

	PrintResult(CalcualteAverage(num1, num2, num3));

	return 0;
}