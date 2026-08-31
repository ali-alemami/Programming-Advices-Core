#include <iostream>
using namespace std;

void ReadNumbers(float& num1, float& num2)
{
	cout << "Enter number 1 ";
	cin >> num1;

	cout << "Enter number 2 ";
	cin >> num2;
}

float CalculateRectanlgeArea(float num1, float num2)
{
	return num1 * num2;
}

void PrintResult(float Area)
{
	cout << "\nrectangle area = " << Area << endl;
}

int main()
{
	float num1, num2;

	ReadNumbers(num1, num2);

	PrintResult(CalculateRectanlgeArea(num1, num2));

	return 0;
}