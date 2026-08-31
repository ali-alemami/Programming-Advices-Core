#include <iostream>
using namespace std;

void ReadNumbers(int& num1, int& num2)
{
	cout << "Enter number 1 ";
	cin >> num1;

	cout << "Enter number 2 ";
	cin >> num2;
}

void Swap2Numbers(int& num1, int& num2)
{
	int temp;

	temp = num1;
	num1 = num2;
	num2 = temp;
}

void PrintResult(int num1, int num2)
{
	cout << "number 1 = " << num1 << endl;
	cout << "number 2 = " << num2 << endl;
}

int main()
{
	int num1, num2;

	ReadNumbers(num1, num2);

	PrintResult(num1, num2);

	Swap2Numbers(num1, num2);
	PrintResult(num1, num2);

	return 0;
}