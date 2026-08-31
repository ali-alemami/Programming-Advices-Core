#include <iostream>
using namespace std;

float ReadL()
{
	float L;

	cout << "Enter the circle l ";
	cin >> L;

	return L;
}

float CircleAreaByL(float L)
{
	const float PI = 22.0 / 7;

	float Area = pow(L, 2) / (4 * PI);

	return Area;
}

void PrintResult(float Area)
{
	cout << "Area of the circle = " << Area << endl;
}

int main()
{
	PrintResult(CircleAreaByL(ReadL()));

	return 0;
}