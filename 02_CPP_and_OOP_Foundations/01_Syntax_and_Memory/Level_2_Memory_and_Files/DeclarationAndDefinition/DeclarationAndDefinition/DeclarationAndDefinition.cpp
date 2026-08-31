#include <iostream>
using namespace std;

int ReadNumber();

int main()
{
	int Number = ReadNumber();

	cout << "Number = " << Number << endl;
}


int ReadNumber()
{
	int Number = 0;

	cout << "Enter a number? ";
	cin >> Number;
	return Number;
}