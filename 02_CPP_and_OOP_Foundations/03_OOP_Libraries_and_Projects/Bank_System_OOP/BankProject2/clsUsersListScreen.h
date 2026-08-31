#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "iomanip"

using namespace std;

class clsUsersListScreen : protected clsScreen
{
private:

	static void _PrintUserRecordLine(clsUser User)
	{
		cout << setw(8) << left << "" << "| " << setw(10) << left << User.UserName;
		cout << "| " << setw(25) << left << User.FullName();
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(12) << left << User.Password;
		cout << "| " << setw(5) << left << User.Permissions;
	}

public:

	static void ShowUsersListScreen()
	{
		vector <clsUser> vUsers = clsUser::GetUsersList();

		string Title = "\t      Users List";
		string SubTitle = "\t      (" + to_string(vUsers.size()) + ") User(s).";

		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << "\t________________________________________________________";
			cout << "_________________________________________________\n\n";

		cout << setw(8) << left << "" << "| " << setw(10) << left << "UserName";
		cout << "| " << setw(25) << left << "Full Name";
		cout << "| " << setw(12) << left << "Phone";
		cout << "| " << setw(20) << left << "Email";
		cout << "| " << setw(12) << left << "Password";
		cout << "| " << setw(5) << left << "Persmissions\n";

		cout << "\t________________________________________________________";
		cout << "_________________________________________________\n\n";

		if (vUsers.size() == 0)
		{
			cout << "\n\n\t\t\t\t\tThere are no users available in the system!\n\n";
		}
		for (clsUser User : vUsers)
		{
			_PrintUserRecordLine(User);
			cout << endl;
		}

		cout << "\t________________________________________________________";
		cout << "_________________________________________________";
	}
};

