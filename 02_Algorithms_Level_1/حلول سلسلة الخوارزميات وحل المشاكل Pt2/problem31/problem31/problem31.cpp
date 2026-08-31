#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;

	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

void PowerOf2_3_4(int Number)
{
	int pow2 = Number * Number;
	int pow3 = pow2 * Number;
	int pow4 = pow3 * Number;

	cout << pow2 << endl << pow3 << endl << pow4 << endl;
}

int main()
{
	PowerOf2_3_4(ReadPositiveNumber("Enter a positive number "));

	return 0;
}