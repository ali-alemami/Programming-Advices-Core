#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{
private:

	static void _ReadUserPermissions(clsUser& User)
	{
		User.Permissions = 0;

		cout << "\nEnter Permissions:\n";
		
		cout << "\nDo you want to give full access? y/n? ";
		char Answer = clsInputValidate::ReadNumber<char>();

		if (Answer == 'Y' || Answer == 'y')
		{
			User.Permissions = -1;
		}
		else
		{
			cout << "\nDo you want to give access to:\n";
			
			cout << "\nShow Client List. y/n? ";
			Answer = clsInputValidate::ReadNumber<char>();
			if (Answer == 'Y' || Answer == 'y')
			{
				User.Permissions += clsUser::enPermissions::pClientList;
			}
			cout << "\nAdd New Client. y/n? ";
			Answer = clsInputValidate::ReadNumber<char>();
			if (Answer == 'Y' || Answer == 'y')
			{
				User.Permissions += clsUser::enPermissions::pAddNewClient;
			}
			cout << "\nDelete Client. y/n? ";
			Answer = clsInputValidate::ReadNumber<char>();
			if (Answer == 'Y' || Answer == 'y')
			{
				User.Permissions += clsUser::enPermissions::pDeleteClient;
			}
			cout << "\nUpdate Client. y/n? ";
			Answer = clsInputValidate::ReadNumber<char>();
			if (Answer == 'Y' || Answer == 'y')
			{
				User.Permissions += clsUser::enPermissions::pUpdateClient;
			}
			cout << "\nFind Client. y/n? ";
			Answer = clsInputValidate::ReadNumber<char>();

			if (Answer == 'Y' || Answer == 'y')
			{
				User.Permissions += clsUser::enPermissions::pFindClient;
			}
			cout << "\nTransactions. y/n? ";
			Answer = clsInputValidate::ReadNumber<char>();

			if (Answer == 'Y' || Answer == 'y')
			{
				User.Permissions += clsUser::enPermissions::pTransactions;
			}
			cout << "\nManage Users. y/n? ";
			Answer = clsInputValidate::ReadNumber<char>();
			if (Answer == 'Y' || Answer == 'y')
			{
				User.Permissions += clsUser::enPermissions::pManageUsers;
			}
			cout << "\nLogin Registers. y/n? ";
			Answer = clsInputValidate::ReadNumber<char>();
			if (Answer == 'Y' || Answer == 'y')
			{
				User.Permissions += clsUser::enPermissions::pLoginRegister;
			}
			cout << "\nCurrency Exchange. y/n? ";
			Answer = clsInputValidate::ReadNumber<char>();
			if (Answer == 'Y' || Answer == 'y')
			{
				User.Permissions += clsUser::enPermissions::pCurrencyExchange;
			}
			if (User.Permissions == 511)
				User.Permissions = -1;
		}
	}

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter your First Name: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter your Last Name: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter your Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter your Phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter your Password: ";
		User.Password = clsInputValidate::ReadString();

		_ReadUserPermissions(User);
	}

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n_________________________";
		cout << "\nFirst Name      : " << User.FirstName;
		cout << "\nLast Name       : " << User.LastName;
		cout << "\nFull Name       : " << User.FullName();
		cout << "\nEmail           : " << User.Email;
		cout << "\nPhone           : " << User.Phone;
		cout << "\nUserName        : " << User.UserName;
		cout << "\nPassword        : " << User.Password;
		cout << "\nPermissions     : " << User.Permissions;
		cout << "\n_________________________\n";
	}
	
public:

	static void ShowAddNewUserScreen()
	{
		clsScreen::_DrawScreenHeader("\t  Add New User Screen");

		string UserName = "";
		cout << "\nEnter UserName: ";

		UserName = clsInputValidate::ReadString();

		while (clsUser::DoesUserExist(UserName))
		{
			cout << "\nUserName is already in use, choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::_GetAddNewUserObject(UserName);

		_ReadUserInfo(NewUser);

		clsUser::enSaveResults SaveResult;

		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUser::svFailedEmptyObject:
		{
			cout << "\nError user was not saves because it's empty.\n";
			break;
		}
		case clsUser::svSucceeded:
		{
			cout << "\nUser added successfully\n";
			_PrintUser(NewUser);
			break;
		}
		case clsUser::svFailedUserExist:
		{
			cout << "\nError account was not saves because username is used\n";
			break;
		}
		}
	}
};