#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Enter the number ";
	cin >> Number;

	return Number;
}

int ReadPower()
{
	int Power;

	cout << "Enter the power ";
	cin >> Power;

	return Power;
}

int PowerOfNumber(int Power, int Number)
{
	if (Power == 0)
	{
		return 1;
	}

	int Result = Number;

	for (int i = 1; i < Power; i++)
	{
		Result *= Number;
	}
	return Result;
}

int main()
{

	cout << "Result = " << PowerOfNumber(ReadPower(), ReadNumber()) << endl;

	return 0;
}