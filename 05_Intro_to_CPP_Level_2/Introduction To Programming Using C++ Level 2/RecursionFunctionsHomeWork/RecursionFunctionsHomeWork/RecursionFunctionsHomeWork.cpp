#include <iostream>
using namespace std;

void PrintNumbers(int M, int N)
{
	if (M >= N)
	{
		cout << M << endl;
		PrintNumbers(M - 1, N);
	}
}

int MyPower(int base, int power)
{
	if (power == 0)
	{
		return 1;
	}
	else
	{
		return base * (MyPower(base, power - 1));
	}
}

int main()
{
	cout << MyPower(2, 4);

	return 0;
}