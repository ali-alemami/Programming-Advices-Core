#include <iostream>
using namespace std;
void MySumProcedure()
{
	int number1, number2;
	cout << "please enter number1?\n";
	cin >> number1;

	cout << "please enter numbe2?\n";
	cin >> number2;

	cout << "***************************\n";
	cout << number1 + number2 << endl;
}

int MySumFunction()
{
	int number1, number2;
	cout << "please enter number1?\n";
	cin >> number1;

	cout << "please enter numbe2?\n";
		cin >> number2;


	int num1 = 10, num2 = 20;
	return num1 + num2;
}
int main()
{
	MySumProcedure();
	cout << MySumFunction() << endl;
	return 0;
}