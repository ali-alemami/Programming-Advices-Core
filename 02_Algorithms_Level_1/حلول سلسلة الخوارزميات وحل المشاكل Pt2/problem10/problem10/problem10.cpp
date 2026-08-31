#include <iostream>>
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

int SumOf3Numbers(int num1, int num2, int num3)
{
	return num1 + num2 + num3;
}

float CalculateAvg(int num1, int num2, int num3)
{
	return (float)SumOf3Numbers(num1, num2, num3) / 3;
}

void PrintResult(float avg)
{
	cout << "The average is " << avg << endl;
}

int main()
{
	int num1, num2, num3;

	ReadNumbers(num1, num2, num3);
	PrintResult(CalculateAvg(num1, num2, num3));

	return 0;
}