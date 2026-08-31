#include <iostream>
using namespace std;

int MySum(int a, int b)
{
	return a + b;
}

double MySum(double a, double b)
{
	return a + b;
}

int MySum(int a, int b, int c)
{
	return a + b + c;
}

int MySum(int a, int b, int c, int d)
{
	return a + b + c + d;
}

int main()
{
	cout << MySum(1.1, 2.1) << endl;
	cout << MySum(1, 2) << endl;
	cout << MySum(1, 2, 3) << endl;
	cout << MySum(1, 2, 3, 4) << endl;

}