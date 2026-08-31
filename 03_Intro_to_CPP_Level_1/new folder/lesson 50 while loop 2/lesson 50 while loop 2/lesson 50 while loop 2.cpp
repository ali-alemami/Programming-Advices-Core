#include<iostream>
using namespace std;
int main()
{
	cout << "Plz enter a positive number\n";
	double x;
	cin >> x;
	while (x <= 0)
	{
		cout << "Wrong number, Plz enter a positive number\n";
		cin >> x;
	}
	cout << "Your number is " << x << endl;
	return 0;	
}