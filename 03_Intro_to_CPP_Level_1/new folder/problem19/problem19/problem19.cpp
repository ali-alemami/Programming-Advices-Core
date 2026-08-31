#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	cout << "enter the diameter\n";
	float d;
	cin >> d;
	const float pi = 3.14;
	float area = pi * pow(d,2) / 4;
	cout << ceil(area) << endl;
	return 0;
}