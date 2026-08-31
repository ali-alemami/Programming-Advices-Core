#include <iostream>
using namespace std;

float ReadNumber()
{
	float Number = 0;

	cout << "Enter a number? ";
	cin >> Number;
	return Number;
}

float MyRoundFunction(float Number)
{
	if (Number > 0)
	{
		if (Number + 0.5 >= int(Number) + 1)
			return ceil(Number);
		else
			return floor(Number);
	}
	else if (Number < 0)
	{
		if (Number - 0.5 <= int(Number) - 1)
			return floor(Number);
		else
			return ceil(Number);
	}
	else
		return Number;
}

int main()
{
	float Number = ReadNumber();

	cout << "\nMy Round Result " << MyRoundFunction(Number) << endl << endl;
	cout << "C++ Round Result " << round(Number) << endl << endl;

	return 0;
}