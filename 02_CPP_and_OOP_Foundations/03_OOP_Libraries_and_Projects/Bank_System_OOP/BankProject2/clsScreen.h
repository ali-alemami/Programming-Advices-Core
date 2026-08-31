#pragma once

#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{
private:

	static void _PrintDateScreen()
	{
		cout << "\t\t\t\t\tUser: " << CurrentUser.UserName << endl;
		cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate());
		cout << "\n\n";
	}

protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\n\t\t\t\t\t______________________________________";

		cout << "\n\n\t\t\t\t\t  " << Title;

		if (SubTitle != "")
		{
			cout << "\n\n\t\t\t\t\t  " << SubTitle;
		}

		cout << "\n\t\t\t\t\t______________________________________\n\n";

		_PrintDateScreen();
	}

	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			_DrawScreenHeader("\t    Access Denied!");
			return false;
		}
		else
			return true;
	}
};