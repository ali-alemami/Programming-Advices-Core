#include <iostream>
using namespace std;

void MyFun()
{
	static int Number = 1;

	cout << Number << endl;
	Number++;
}

int main()
{
	MyFun();
	MyFun();
	MyFun();

	return 0;
}