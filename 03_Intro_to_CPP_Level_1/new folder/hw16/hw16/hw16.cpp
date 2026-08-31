#include <iostream>
using namespace std;
int x = 71;
void procedure1()
{
	int x = 15;
	cout << "the local value of x in procedure1 is: " << x << endl;
}

int main()
{
	int x = 23;
	x = 13;
	cout << "the local value of x in main is: " << x << endl;
	procedure1();



	::x = 44;
	::x++;
	cout << ::x;
}
