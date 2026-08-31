#include <iostream>
using namespace std;
float AreaFunction(float r,float pi=3.14)
{
	return pi * pow(r, 2);
}
int main()
{
	float r, pi = 3.14;
	cout << "enter r\n";
	cin >> r;
	cout << "area = " << AreaFunction(r,pi);
	return 0;
}