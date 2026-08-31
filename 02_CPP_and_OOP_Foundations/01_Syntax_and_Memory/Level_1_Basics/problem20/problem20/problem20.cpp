#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	cout << "enter A\n";
	float A;
	cin >> A;
	const float pi = 3.14;
	float area = pi * pow(A / 2, 2);
	cout << ceil(area) << endl;
	return 0;

}