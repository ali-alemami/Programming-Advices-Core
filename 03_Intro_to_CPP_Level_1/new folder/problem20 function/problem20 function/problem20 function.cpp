#include<iostream>
using namespace std;
float AreaFunction(float a,float pi)
{
	return pi * (pow(a / 2, 2));
}
int main()
{
	float a, pi = 3.14;
	cout << "enter a\n";
	cin >> a;
	cout << "area = " << AreaFunction(a, pi);
}