#include <iostream>
using namespace std;
float AreaFunction(float a, float b, float pi)
{
	return pi * (pow(b, 2) / 4) * ((2 * a - b) / (2 * a + b));


}
int main()
{
	float a, b, pi = 3.14;
	cout << "enter a\n";
	cin >> a;

	cout << "enter b\n";
	cin >> b;

	cout << "area = " << AreaFunction(a, b, pi);
	return 0;
}