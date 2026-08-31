#include <iostream>
using namespace std;

string ReadPinCode(string Message)
{
	string Pin;

	cout << Message << endl;
	cin >> Pin;

	return Pin;
}

bool Login()
{
	string Pin;

	do
	{
		Pin = ReadPinCode("Enter PIN code");
		if (Pin != "1234")
		{
			cout << "Wrong PIN\n";
			system("color 4F");
		}

	} while (Pin != "1234");

	return true;
}

int main()
{
	if(Login())
	{
		system("color 2F");
		cout << "Your balance is " << 7500 << endl;
	}

	return 0;
}