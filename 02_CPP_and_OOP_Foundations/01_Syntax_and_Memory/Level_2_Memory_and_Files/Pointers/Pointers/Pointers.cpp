#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int b = 50;

	cout << "a value   = " << a << endl;
	cout << "a address = " << &a << endl;
	cout << "b address = " << &b << endl;

	int* p;

	p = &b;

	cout << "Pointer value = " << p << endl;
}