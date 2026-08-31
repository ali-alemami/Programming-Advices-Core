#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsInputValidate.h"
#include "Global.h"
#include "clsUser.h"
#include "clsUtil.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{
private:

	static void _Login()
	{
		bool LoginFailed = false;
		
		string UserName, Password;
		short Counter = 3;

		do
		{
			if (LoginFailed)
			{
				Counter--;
				cout << "\nInvalid UserName/Password.\n";
				cout << "You have " << Counter << " Trial(s) to login.\n\n";
			}

			if (Counter == 0)
			{
				LockedSystem = true;
				cout << "\nYou are locked after 3 failed trials.";
				return;
			}

			cout << "Enter UserName: ";
			UserName = clsInputValidate::ReadString();

			cout << "\nEnter Password: ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.clsUser::RegisterLogin();
		clsMainScreen::ShowMainMenu();
	}

public:

	static void ShowLoginScreen()
	{
		system("cls");
		clsScreen::_DrawScreenHeader("\t     Login Screen");

		_Login();
	}
};

