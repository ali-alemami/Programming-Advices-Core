#include <iostream>
using namespace std;
int main()
{
	int userbalance = 7500;
	int ATMpin;
	cout << "Enter PIN\n";
	cin >> ATMpin;
	if (ATMpin == 1234)
	{
		cout << "Your Balance is " << userbalance << endl;
	}
	else
	{
		cout << "Wrong PIN\n";
	}
	return 0;
}

