#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	cout << "enter a then b\n";
	float a, b;
	cin >> a;
	cin >> b;
	const float pi = 3.14;
	float area = pi * pow(b, 2) / 4 * ((2 * a - b) / (2 * a + b));
	cout << floor(area) << endl;
	return 0;

}