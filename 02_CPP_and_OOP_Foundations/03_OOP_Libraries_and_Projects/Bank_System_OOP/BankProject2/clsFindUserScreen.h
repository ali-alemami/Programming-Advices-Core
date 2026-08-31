#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsScreen.h"

using namespace std;

class clsFindUserScreen : protected clsScreen
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

	static void ShowFindUserScreen()
	{
		clsScreen::_DrawScreenHeader("\t   Find User Screen");

		string UserName = "";

		cout << "Enter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (!(clsUser::DoesUserExist(UserName)))
		{
			cout << "UserName is not found, choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		if (!User.IsEmpty())
		{
			cout << "\nUser Found.\n";
		}
		else
		{
			cout << "\nUser was not found.\n";
		}

		_PrintUser(User);
	}
};

