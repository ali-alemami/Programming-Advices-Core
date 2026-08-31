#include <iostream>
using namespace std;

float ReadSquareLength()
{
	float S;

	cout << "Enter square length ";
	cin >> S;

	return S;
}

float CircleAreaBySquareLength(float S)
{
	const float PI = 22.0 / 7;

	float Area = PI * pow((S / 2), 2);

	return Area;
}

void PrintResult(float Area)
{
	cout << "Area of the circle = " << Area << endl;
}

int main()
{
	PrintResult(CircleAreaBySquareLength(ReadSquareLength()));

	return 0;
}