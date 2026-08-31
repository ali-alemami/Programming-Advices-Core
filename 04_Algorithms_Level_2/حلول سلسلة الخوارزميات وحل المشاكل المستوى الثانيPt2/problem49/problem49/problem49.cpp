#include <iostream>
using namespace std;

float GetFraction(float Number)
{
	return Number - int(Number);
}

float MyCeil(float Number)
{
	float Fraction = GetFraction(Number);

	if (abs(Fraction) > 0)
	{
		if (Number > 0)
		{
			return int(Number) + 1;
		}
		else
			return int(Number);
	}
	else
		return Number;
	
}

int main()
{
	cout << MyCeil(-10.2) << endl;
	cout << ceil(-10.2) << endl;
	return 0;
}