#include <iostream>
using namespace std;
float AreaFunction(float a, float b, float c, float pi)
{
	float p = (a + b + c) / 2;
	return pi * (pow(a * b * c / (4 * sqrt(p * (p - a) * (p - b) * (p - c))), 2));
}
int main()
{
	float a, b, c, pi = 3.14;
	cout << "enter a\n";
	cin >> a;
	cout << "enter b\n";
	cin >> b;
	cout << "enter c\n";
	cin >> c;
	cout << "area = " << AreaFunction(a, b, c, pi);
	return 0;
}
