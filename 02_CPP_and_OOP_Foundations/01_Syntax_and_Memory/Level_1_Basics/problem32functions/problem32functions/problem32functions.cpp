#include <iostream>
using namespace std;
int MyFunction(int number,int m)
{
	
	return pow(number, m);
}
int main()
{
	int number, m;
	cout << "enter the number\n";
	cin >> number;

	cout << "enter the power\n";
	cin >> m;

	cout << MyFunction(number,m);
	return 0;

}