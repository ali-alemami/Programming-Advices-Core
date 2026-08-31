#include <iostream>
using namespace std;

float ReadNumber()
{
	float Number;

	cout << "Enter the diameter ";
	cin >> Number;

	return Number;
}

float CalcualteCircleAreaByDiameter(float Number)
{
	const float PI = 22.0 / 7;

	float Area = (PI * pow(Number, 2)) / 4;

	return Area;
}

void PrintResult(float Area)
{
	cout << "Area of the circle = " << Area << endl;
}

int main()
{
	PrintResult(CalcualteCircleAreaByDiameter(ReadNumber()));

	return 0;
}