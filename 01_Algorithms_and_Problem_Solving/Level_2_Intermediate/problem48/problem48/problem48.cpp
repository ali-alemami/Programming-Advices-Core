#include <iostream>
using namespace std;

float GetFraction(float Number)
{
	return Number - int(Number);
}

float MyFloor(float Number)
{
	int intPart = int(Number);
	float Fraction = GetFraction(Number);

	if (abs(Fraction) > 0)
	{
		if (Number > 0)
			return intPart;

		else if (Number < 0)
			return --intPart;
	}
}


float MyFloor2(float Number)
{
	if (Number > 0)
		return int(Number);
	else
		return int(Number) - 1;
}

int main()
{
	cout << MyFloor(-10.3) << endl;
	cout << floor(-10.3) << endl;

	return 0;
}