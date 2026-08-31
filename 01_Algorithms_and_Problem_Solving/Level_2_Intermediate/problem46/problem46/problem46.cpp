#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;
	cout << "Enter a number? ";
	cin >> Number;

	return Number;
}

int Myabs(int Number)
{
	if (Number < 0)
		return Number * -1;
	else
		return Number;
}

int main()
{
	int Number = ReadNumber();

	cout << "\n\nMy abs Result " << Myabs(Number) << endl;
	cout << "\n\nC++ abs Result " << abs(Number) << endl;

	return 0;
}