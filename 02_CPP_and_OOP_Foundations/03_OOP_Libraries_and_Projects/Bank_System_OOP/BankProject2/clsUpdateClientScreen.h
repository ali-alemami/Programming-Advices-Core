#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen
{
private:

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter your First Name: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter your Last Name: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter your Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter your Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter your PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter your Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadNumber<float>();
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

	static void ShowUpdateClientScreen()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pUpdateClient))
		{
			return;
		}

		_DrawScreenHeader("\t Update Client Screen");

		string AccountNumber = "";
		cout << "\nEnter client account number: ";

		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::DoesClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		cout << "\nUpdate Client Info:\n";
		cout << "\n____________________\n";

		_ReadClientInfo(Client);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = Client.Save();

		switch (SaveResult)
		{
		case clsBankClient::svFailedEmptyObject:
		{
			cout << "\nError account was not saved because it's empty.";
			break;
		}
		case clsBankClient::svSucceeded:
		{
			cout << "\nAccout updated successfully.";
			_PrintClient(Client);
			break;
		}
		}
	}
};

