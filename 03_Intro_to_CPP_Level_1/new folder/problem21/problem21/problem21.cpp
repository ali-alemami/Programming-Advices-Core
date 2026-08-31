#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	cout << "enter L;n";
	float L;
	cin >> L;
	const float pi = 3.14;
	float area = pow(L, 2) / (4 * pi);
	cout << floor(area) << endl;
	return 0;
}