#include <iostream>
using namespace std;
int main()
{
	int pin, counter = 1;
	cout << "Enter your PIN\n";
	cin >> pin;
	if (pin == 1234)
	{
		cout << "Your balance is 7500\n";
	}
	else
	{
		while (counter <= 2 && pin != 1234)
		{
			cout << "Wrong PIN\n";
			cout << "Enter your PIN\n";
			cin >> pin;
			if (pin == 1234)
			{
				cout << "Your balance is 7500\n";
				counter = 4;
			}
			else
			{
				counter++;
			}
		}
		while (counter == 3)
		{
			cout << "Wrong PIN\nCard is locked\n";
			counter++;
		}
	}
	return 0;
}