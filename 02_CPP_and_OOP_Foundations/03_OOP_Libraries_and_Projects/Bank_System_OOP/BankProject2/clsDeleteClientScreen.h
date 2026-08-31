#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
	
private:

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

	static void ShowDeleteClientScreen()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("\t Delete Client Screen");


		string AccountNumber = "";
		cout << "\nEnter client account number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::DoesClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		cout << "\nAre you sure you want to delete this client y/n? ";
		char Answer = clsInputValidate::ReadNumber<char>();

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client.Delete())
				cout << "\nClient deleted successfully.\n";
			else
				cout << "\nError Client was not deleted.\n";
		}
		else
			cout << "\nClient is not deleted.\n";
	}
};

