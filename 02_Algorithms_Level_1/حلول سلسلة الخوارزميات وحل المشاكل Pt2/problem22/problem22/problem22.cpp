#include <iostream>
using namespace std;

void ReadAB(float& A, float& B)
{
	cout << "Enter a ";
	cin >> A;

	cout << "Enter b ";
	cin >> B;
}

float CircleAreaInIsoscelesTriangle(float A, float B)
{
	const float PI = 22.0 / 7;

	float Area = PI * (pow(B, 2) / 4) * ((2 * A - B) / (2 * A + B));

	return Area;
}

void PrintResult(float Area)
{
	cout << "Area of the circle = " << Area << endl;
}

int main()
{
	float A, B;

	ReadAB(A, B);

	PrintResult(CircleAreaInIsoscelesTriangle(A, B));

	return 0;
}