#include <iostream>
using namespace std;

void Read3numbers(int& num1, int& num2, int& num3)
{
	cout << "Enter num1 ";
	cin >> num1;

	cout << "Enter num2 ";
	cin >> num2;

	cout << "Enter num3 ";
	cin >> num3;
}

int MaxOf3Numbers(int num1, int num2, int num3)
{
	if (num1 > num2)
	{
		if (num1 > num3)
		{
			return num1;
		}
		else return num3;
	}

	else if (num2 > num3)
	{
		return num2;
	}
	else return num3;
}

void PrintResult(int max)
{
	cout << "The max of the 3 numbers is " << max << endl;
}

int main()
{
	int num1, num2, num3;

	Read3numbers(num1, num2, num3);

	PrintResult(MaxOf3Numbers(num1, num2, num3));

	return 0;
}