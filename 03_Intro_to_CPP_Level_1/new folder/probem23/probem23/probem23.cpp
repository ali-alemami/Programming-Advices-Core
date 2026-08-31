#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	cout << "enter a,b,c\n";
	float a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	const float pi = 3.14;
	float p = (a + b + c) / 2;
	float area = pi * (pow((a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c))), 2));
	cout << round(area) << endl;
	return 0;

}