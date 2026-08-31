#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	cout << "please enter the diagonal then the side area of the rectangle\n";
	float a, d;
	cin >> a;
	cin >> d;
	float area = a * sqrt(pow(d, 2) - pow(a, 2));
	cout << area << endl;
	return 0;
}