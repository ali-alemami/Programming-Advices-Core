#include <iostream>
using namespace std;

float ReadR()
{
	float r;

	cout << "Enter the circle r ";
	cin >> r;

	return r;
}

float CalculateCircleArea(float r)
{
	const float PI = 22.0 / 7;

	float Area = PI * pow(r, 2);

	return Area;
}

void PrintResult(float Area)
{
	cout << "Circle Area = " << Area << endl;
}

int main()
{

	PrintResult(CalculateCircleArea(ReadR()));

	return 0;
}