#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	cout << "enter r\n";
	float r;
	cin >> r;
	const float pi = 3.14;
	float area = pi * pow(r, 2);
	cout << ceil(area) << endl;

	return 0;
}