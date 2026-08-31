#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	float number, power;
	cout << "enter the number\n";
	cin >> number;
	cout << "enter the power\n";
	cin >> power;
	cout << round(pow(number, power)) << endl;
	return 0;
}