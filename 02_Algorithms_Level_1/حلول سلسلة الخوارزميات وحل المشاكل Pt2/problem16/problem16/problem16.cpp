#include <iostream>
using namespace std;

void ReadNumbers(float& A, float& D)
{
	cout << "Enter the side length ";
	cin >> A;

	cout << "Enter the diagonal length ";
	cin >> D;
}

float RectangleAreaBySideAndDiagonal(float A, float D)
{
	float Area = A * sqrt(pow(D, 2) - pow(A, 2));
	return Area;
}

void PrintResult(float Area)
{
	cout << "Rectanglr Area = " << Area << endl;
}

int main()
{
	float Num1, Num2;

	ReadNumbers(Num1, Num2);

	PrintResult(RectangleAreaBySideAndDiagonal(Num1, Num2));

	return 0;
}