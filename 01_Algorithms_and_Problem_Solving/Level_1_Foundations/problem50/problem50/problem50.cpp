#include <iostream>
using namespace std;

string ReadPinCode()
{
	string PinCode;

	cout << "Enter PIN\n";
	cin >> PinCode;

	return PinCode;
}

bool Login()
{
	string PinCode;
	int Counter = 3;
	do
	{
		PinCode = ReadPinCode();

		if (PinCode == "1234")
		{
			return true;
		}
		else
		{
			cout << "Wrong PIN\n";
			cout << --Counter << " try(s) left\n";
			system("color 4F");
		}

	} while (Counter >= 1 && PinCode != "1234");

	return false;
}

int main()
{
	if (Login())
	{
		system("color 2F");
		cout << "\n\n your balance is " << 7500 << endl;
	}
	else
	{
		cout << "\n\n Congrats!!!\n your card is blocked\n\n";
	}
	return 0;
}