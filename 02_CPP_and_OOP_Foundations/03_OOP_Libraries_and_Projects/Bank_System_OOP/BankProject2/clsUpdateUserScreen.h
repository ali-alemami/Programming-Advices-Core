#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;

class clsUpdateUserScreen : protected clsScreen
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
			if (User.Permissions == 255)
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

	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\t  Update User Screen");

		string UserName = "";
		cout << "\nEnter user account number: ";

		UserName = clsInputValidate::ReadString();

		while (!clsUser::DoesUserExist(UserName))
		{
			cout << "\nUser Number is not found, choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		_PrintUser(User);

		cout << "\nUpdate User Info:\n";
		cout << "\n____________________\n";

		_ReadUserInfo(User);

		clsUser::enSaveResults SaveResult;

		SaveResult = User.Save();

		switch (SaveResult)
		{
		case clsUser::svFailedEmptyObject:
		{
			cout << "\nError user was not saved because it's empty.";
			break;
		}
		case clsUser::svSucceeded:
		{
			cout << "\nUser updated successfully.";
			_PrintUser(User);
			break;
		}
		}
	}
};

