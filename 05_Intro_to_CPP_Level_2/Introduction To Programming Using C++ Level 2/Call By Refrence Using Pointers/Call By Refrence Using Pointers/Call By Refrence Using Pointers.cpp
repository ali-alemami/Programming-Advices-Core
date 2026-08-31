#include <iostream>
using namespace std;

void Swap(int* n1, int* n2)
{
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

int main()
{
	int a = 1, b = 2;

	cout << a << endl;
	cout << b << endl << endl;

	Swap(&a, &b);

	cout << a << endl;
	cout << b << endl;

	return 0;
}