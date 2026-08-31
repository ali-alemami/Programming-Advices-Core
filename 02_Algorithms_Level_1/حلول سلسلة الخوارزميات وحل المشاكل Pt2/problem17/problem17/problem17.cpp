#include <iostream>
using namespace std;

void ReadNumbers(float& num1, float& num2)
{
	cout << "Enter the triangle height ";
	cin >> num1;

	cout << "Enter the trianlge base ";
	cin >> num2;
}

float CalculateTriangleArea(float num1, float num2)
{
	float Area = .5 * num1 * num2;

	return Area;
}

void PrintResult(float Area)
{
	cout << "The area of the triangle = " << Area << endl;
}

int main()
{
	float num1, num2;

	ReadNumbers(num1, num2);
	
	PrintResult(CalculateTriangleArea(num1, num2));

	return 0;
}