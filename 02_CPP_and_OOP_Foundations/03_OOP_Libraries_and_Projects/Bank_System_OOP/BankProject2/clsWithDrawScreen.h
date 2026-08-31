#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h";

using namespace std;

class clsWithDrawScreen : protected clsScreen
{

private:

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "Enter Account Number? ";
		AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n____________________";
		cout << "\nFirst Name   : " << Client.FirstName;
		cout << "\nLast Name    : " << Client.LastName;
		cout << "\nFull Name    : " << Client.FullName();
		cout << "\nEmail        : " << Client.Email;
		cout << "\nPhone        : " << Client.Phone;
		cout << "\nAcc. Number  : " << Client.AccountNumber();
		cout << "\nPin Code     : " << Client.PinCode;
		cout << "\nBalance      : " << Client.AccountBalance;
		cout << "\n____________________\n";
	}
	
public:

	static void ShowWithDrawScreen()
	{
		clsScreen::_DrawScreenHeader("\t    Withdraw Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::DoesClientExist(AccountNumber))
		{
			cout << "\nClient With [" << AccountNumber << "] Doesn't exist.\n\n";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		float WithdrawAmount = 0;
		cout << "\nEnter Withdraw amount? ";
		WithdrawAmount = clsInputValidate::ReadNumber<float>();

		cout << "\nAre you sure you want to perform this transaction? ";
		char Answer = 'N';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (Client.WithDraw(WithdrawAmount))
			{
				cout << "\nAmount Withdrew Successfully.\n";
				cout << "\nNew Balance Is: " << Client.AccountBalance << endl;
			}
			else
			{
				cout << "\nCannot withdraw, insuffecient balance!";
			}
		}
		else
			cout << "\nOperation was cancelled.\n";
	}
};

