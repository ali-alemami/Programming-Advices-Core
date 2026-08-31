#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	cout << "enter a number\n";
	float number;
	cin >> number;
	cout << round(pow(number, 2)) << endl;
	cout << round(pow(number, 3)) << endl;
	cout << round(pow(number, 4)) << endl;
	return 0;
}