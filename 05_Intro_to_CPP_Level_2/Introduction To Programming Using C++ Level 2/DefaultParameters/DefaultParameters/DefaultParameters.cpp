#include <iostream>
using namespace std;

int MySum(int a, int b, int c = 0, int d = 0)
{
	return a + b + c + d;
}

int main()
{
	cout << MySum(10, 20);
	cout << MySum(10, 20, 30);
	cout << MySum(1, 2, 3, 4);
}