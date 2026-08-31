#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsAddNewClientScreen : protected clsScreen
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

	static void ShowAddNewClientScreen()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("\t Add New Client Screen");

		string AccountNumber = "";
		cout << "\nEnter client account number: ";

		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::DoesClientExist(AccountNumber))
		{
			cout << "\nAccount number is already in use, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::svFailedEmptyObject:
		{
			cout << "\nError account was not saved because it's empty.\n";
			break;
		}
		case clsBankClient::svSucceeded:
		{
			cout << "\nAccount added succesffuly.\n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::svFailedAccountNumberExist:
		{
			cout << "\nError account was not saved because account number is used\n";
			break;
		}
		}
	}
};

