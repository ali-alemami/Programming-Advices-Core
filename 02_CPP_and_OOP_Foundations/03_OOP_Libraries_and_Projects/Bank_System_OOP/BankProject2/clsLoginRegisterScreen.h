#pragma once

#include <iostream>
#include "clsScreen.h"
#include <fstream>
#include <vector>
#include "clsUser.h"
#include <string>
#include "clsString.h"

using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{
private:

	static void _PrintLoginRegisterLine(clsUser::stLoginRegisterRecord LoginRegisterList)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << LoginRegisterList.DateTime;
		cout << "| " << setw(20) << left << LoginRegisterList.UserName;
		cout << "| " << setw(20) << left << LoginRegisterList.Password;
		cout << "| " << setw(20) << left << LoginRegisterList.Permissions;
	}

public:

	static void ShowLoginRegisterScreen()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;
		}

		vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecords = clsUser::GetLoginRegisterList();

		string Title = "Login Register List Screen";
		string SubTitle = "(" + to_string(vLoginRegisterRecords.size()) + ") Record(s).";

		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << "\t___________________________________________________";
		cout << "__________________________________________________\n\n";


		cout << setw(8) << left << "" << "| " << setw(30) << left << "Date/Time";
		cout << "| " << setw(20) << left << "UserName";
		cout << "| " << setw(20) << left << "Password";
		cout << "| " << setw(20) << left << "Permissions";

		cout << "\n\t___________________________________________________";
		cout << "__________________________________________________\n\n";

		if (vLoginRegisterRecords.size() == 0)
		{
			cout << "\n\n\t\t\t\t\tThere are no Login Registers available in the system!\n\n";
		}
		else
		{
			for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecords)
			{
				_PrintLoginRegisterLine(Record);
				cout << endl;
			}
		}
		cout << "\t___________________________________________________";
		cout << "__________________________________________________";
	}
};

