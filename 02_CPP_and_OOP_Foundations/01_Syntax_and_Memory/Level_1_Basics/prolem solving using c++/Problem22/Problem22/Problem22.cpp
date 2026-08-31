#include <iostream>
using namespace std;
int main()
{
	cout << "please enter a and b to calculate the circle area\n";
	float a, b;
	cin >> a;
	cin >> b;
	const float pi = 3.14;
	cout << (pi * b * b / 4) * ((2 * a - b) / (2 * a + b));
		return 0;
}