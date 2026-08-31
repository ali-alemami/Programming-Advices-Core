#include <iostream>
using namespace std;
float AreaFunction(float a, float d)
{
	return a * sqrt(pow(d, 2) - pow(a, 2));
}
int main()
{
	float a, d;
	cout << "enter a\n";
	cin >> a;

	cout << "enter d\n";
	cin >> d;
	cout << "area = " << AreaFunction(a,d);
	return 0;

}