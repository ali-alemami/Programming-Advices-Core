#include <iostream>
using namespace std;

void ReadTriangleInfo(float& A, float& B, float& C)
{
	cout << "Enter a ";
	cin >> A;

	cout << "Enter b ";
	cin >> B;

	cout << "Enter c ";
	cin >> C;
}

float CircleAreaInATriangle(float A, float B, float C)
{
	const float P = (A + B + C) / 2;
	const double PI = 3.141592653589793238462643383279502884197;

	float Area = PI * pow((A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C))), 2);

	return Area;
}

void PrintResult(float Area)
{
	cout << "Area of the circle is " << Area << endl;
}

int main()
{
	float A, B, C;

	ReadTriangleInfo(A, B, C);

	PrintResult(CircleAreaInATriangle(A, B, C));

	return 0;
}