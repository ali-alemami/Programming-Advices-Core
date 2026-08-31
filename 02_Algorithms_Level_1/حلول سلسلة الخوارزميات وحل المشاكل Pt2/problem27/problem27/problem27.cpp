#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Enter a Number ";
	cin >> Number;

	return Number;
}

void PrintFromNTo1(int Number)
{
	for (int i = Number; i >= 1; i--)
	{
		cout << i << endl;
	}
}

void PrintFromNTo1While(int Number)
{
	int i = Number;

	while (i >= 1)
	{
		cout << i << endl;
		i--;
	}
}

void PrintFromNTo1DoWhile(int Number)
{
	int i = Number;

	do
	{
		cout << i << endl;
		i--;
	} while (i >= 1);
}

int main()
{
	PrintFromNTo1DoWhile(ReadNumber());

	return 0;
}