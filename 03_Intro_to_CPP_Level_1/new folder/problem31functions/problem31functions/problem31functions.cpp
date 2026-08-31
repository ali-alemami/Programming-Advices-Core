#include <iostream>
using namespace std;
void Power2PROCEDURE()
{
	cout << "Enter a number\n";
	int number;
	cin >> number;
	int number1 = pow(number, 2);
	int number2 = pow(number, 3);
	int number3 = pow(number, 4);
	cout << number1 << endl << number2 << endl << number3 << endl;
	
}
int main()
{
	Power2PROCEDURE();
	return 0;
}