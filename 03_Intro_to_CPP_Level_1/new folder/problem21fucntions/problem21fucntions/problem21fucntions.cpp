#include <iostream>
using namespace std;
float AreaFunction(float l,float pi)
{
	return pow(l, 2) / (4 * pi);
}
int main()
{
	cout << "enter l\n";
	float l, pi = 3.14;
	cin >> l;
	cout << "area = " << AreaFunction(l, pi);
	return 0;

}