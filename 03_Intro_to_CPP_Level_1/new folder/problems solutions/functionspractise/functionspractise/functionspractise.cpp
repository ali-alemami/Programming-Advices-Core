#include <iostream>
using namespace std;

void MySumProcedures()
{
	int num1, num2;

	cout << "enter number1\n";
	cin >> num1;

	cout << "\nenter number2\n";
	cin >> num2;

	cout << "\n****************************************\n";

	cout << num1 + num2;
}

int MySumFunction0()
{
	int num1, num2;

	cout << "enter number1\n";
	cin >> num1;

	cout << "\nenter number2\n";
	cin >> num2;

	cout << "\n****************************************\n";

	return num1 + num2;
}


int main()
{
	MySumProcedures();
	cout << MySumFunction0();

	return 0;
}