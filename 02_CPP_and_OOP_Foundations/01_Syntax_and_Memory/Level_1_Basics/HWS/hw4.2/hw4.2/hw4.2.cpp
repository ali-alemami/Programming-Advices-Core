#include<iostream>
using namespace std;

short int main()
{
	short int a, b, c;
	cout << "please add the first number\n";
	cin >> a;

	cout << "please ass the second number\n";
	cin >> b;

	cout << "please ass the third number\n";
	cin >> c;


	cout << endl << endl;
	cout << a << " +\n";
	cout << b << " +\n";
	cout << c << "\n";
	cout << "_____________________________________\n\n";
	cout << "total = " << a + b + c << endl;

	return 0;

}