#include <iostream>
using namespace std;

float GetFraction(float Number)
{
	return Number - int(Number);
}

float MyRound(int Number)
{
	int intPart = int(Number);

	float Fraction = GetFraction(Number);

	if (abs(Fraction) >= 0.5)
	{
		if (Number > 0)
		{
			return ++Number;
		}
		if (Number < 0)
		{
			return --Number;
		}
	}
	else
		return Number;
}

int main()
{
	cout << MyRound(-6.7) << endl;
	cout << round(-6.7) << endl;

	return 0;
}