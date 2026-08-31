#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

class clsDepositScreen : protected clsScreen
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

	static void ShowDepositScreen()
	{
		clsScreen::_DrawScreenHeader("\t    Deposit Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::DoesClientExist(AccountNumber))
		{
			cout << "\nClient With [" << AccountNumber << "] Doesn't exist.\n\n";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		float DepositAmount = 0;
		cout << "\nEnter deposit amount? ";
		DepositAmount = clsInputValidate::ReadNumber<float>();

		cout << "\nAre you sure you want to perform this transaction? ";
		char Answer = 'N';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Client.Deposit(DepositAmount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance Is: " << Client.AccountBalance << endl;
		}
		else
			cout << "\nOperation was cancelled.\n";
	}
};

