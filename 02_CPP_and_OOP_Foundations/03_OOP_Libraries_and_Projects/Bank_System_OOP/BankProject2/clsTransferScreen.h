#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsTransferScreen : protected clsScreen
{
private:

	static string _ReadAccountNumber()
	{
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::DoesClientExist(AccountNumber))
		{
			cout << "\nAccount Number doesn't exist, choose anther one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static float _ReadTransferAmount(clsBankClient SourceClient)
	{
		float Amount;

		cout << "Enter transfer amount: ";
		Amount = clsInputValidate::ReadNumber<float>();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount exceeds the avaialable balance, choose another amount: ";
			Amount = clsInputValidate::ReadNumber<float>();
		}

		return Amount;
	}

	static void _PrintShortClientCard(clsBankClient Client)
	{
		cout << "\nClient Card:\n";
		cout << "____________________\n\n";

		cout << "Full Name  :" << Client.FullName();
		cout << "\nAcc. Number: " << Client.AccountNumber();
		cout << "\nBalance    : " << Client.AccountBalance;
		cout << "\n____________________\n\n";
	}
	
public:

	static void ShowTransferScreen()
	{
		clsScreen::_DrawScreenHeader("\t    Transfer Screen");

		cout << "\nEnter Account Number to transfer from: ";
		string AccountNumber1 = _ReadAccountNumber();

		clsBankClient Client1 = clsBankClient::Find(AccountNumber1);
		_PrintShortClientCard(Client1);

		cout << "Enter Account Number to transfer to: ";
		string AccountNumber2 = clsInputValidate::ReadString();

		while (!clsBankClient::DoesClientExist(AccountNumber2) || AccountNumber1 == AccountNumber2)
		{
			if (AccountNumber1 == AccountNumber2)
			{
				cout << "\nEnter different Account Number.\n";
				AccountNumber2 = clsInputValidate::ReadString();
				continue;
			}
			cout << "\nAccount Number doesn't exist, choose anther one: ";
			AccountNumber2 = clsInputValidate::ReadString();
		}

		clsBankClient Client2 = clsBankClient::Find(AccountNumber2);
		_PrintShortClientCard(Client2);

		float Amount = _ReadTransferAmount(Client1);

		cout << "\nAre you sure you want to perform this operation? ";
		char Answer = 'N';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (Client1.Transfer(Client2, Amount, CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully.\n";

				_PrintShortClientCard(Client1);
				_PrintShortClientCard(Client2);
			}
			else
				cout << "\nTransfer failed.\n";
		}
		else
			cout << "\nOperation was cancelled.\n";
	}
};

