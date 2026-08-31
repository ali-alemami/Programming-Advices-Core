#include <iostream>
using namespace std;
float AreaFunction(float a, float b)
{
	
	return  a * b;
}
int main()
{
	float a, b;
	cout << "enter a and b\n";
	cin >> a;
	cin >> b;
	cout << "area = " << AreaFunction(a, b);
}