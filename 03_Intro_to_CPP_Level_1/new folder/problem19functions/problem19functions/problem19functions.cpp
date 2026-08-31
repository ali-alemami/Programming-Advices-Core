#include <iostream>
using namespace std;
float AreaFunction(float d, float pi)
{
	return pi * pow(d, 2) / (4);
}
int main()
{
	float d, pi = 3.14;
	cout << "enter d\n";
	cin >> d;
	cout << "area = " << AreaFunction(d, pi);
}