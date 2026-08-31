#include <iostream>
using namespace std;

float MySqrt(float Number)
{
	int M = Number / 2;

	for (int i = 1; i <= M; i++)
	{
		if (i * i == Number)
			return Number / i;
	}
}

float MySqrt2(float Number)
{
	return pow(Number, 0.5);
}

int main()
{
	cout << MySqrt2(25) << endl;
	cout << sqrt(25) << endl;

	return 0;
}