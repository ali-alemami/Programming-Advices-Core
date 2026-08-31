#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
private:

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

	static void ShowDeleteUserScreen()
	{
		clsScreen::_DrawScreenHeader("\t  Delete User Screen");

		string UserName = "";
		cout << "\nEnter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::DoesUserExist(UserName))
		{
			cout << "\nUserName is not found, choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		_PrintUser(User);

		cout << "\nAre you sure you want to delete this user y/n? ";
		char Answer = clsInputValidate::ReadNumber<char>();

		if (Answer == 'y' || Answer == 'Y')
		{
			if (User.Delete())
				cout << "\nUser deleted successfully.\n";
			else
				cout << "\nError User was not deleted.\n";
		}
		else
			cout << "\nUser is not deleted.\n";
	}
};

