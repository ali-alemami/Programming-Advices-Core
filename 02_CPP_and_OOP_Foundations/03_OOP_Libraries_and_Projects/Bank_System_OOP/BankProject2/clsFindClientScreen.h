#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindClientScreen : protected clsScreen
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

	static void ShowFindClientScreen()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("\t  Find Client Screen");

		string AccountNumber = "";

		cout << "Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!(clsBankClient::DoesClientExist(AccountNumber)))
		{
			cout << "Account Number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.IsEmpty())
		{
			cout << "\nClient Found.\n";
		}
		else
		{
			cout << "\nClient was not found.\n";
		}

		_PrintClient(Client);
	}
};

