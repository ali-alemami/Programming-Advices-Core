#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsManageUsersScreen : protected clsScreen
{

private:

	enum enManageUsersOptions { eUsersList = 1, eAddNewUser = 2,
		eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenu = 6 };


	static short _ReadManageUsersOption()
	{
		cout << setw(40) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choose = clsInputValidate::ReadNumberBetween<short>(1, 6);
		return Choose;
	}

	static void _ShowUsersListScreen()
	{
		clsUsersListScreen::ShowUsersListScreen();
	}

	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _GoBackToManageUsersMenu()
	{
		cout << "\n\n";
		cout << setw(8) << left << "" << "Press any key to go back to the manage users menu...";
		system("pause>0");
		ShowManageUsersMenu();
	}   

	static void _PerformManageUsersOptions(enManageUsersOptions ManageUsersOption)
	{
		switch (ManageUsersOption)
		{
		case enManageUsersOptions::eUsersList:
			system("cls");
			_ShowUsersListScreen();
			_GoBackToManageUsersMenu();
			break;
		case enManageUsersOptions::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenu();
			break;
		case enManageUsersOptions::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenu();
			break;
		case enManageUsersOptions::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenu();
			break;
		case enManageUsersOptions::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenu();
			break;
		case enManageUsersOptions::eMainMenu:
			break;
		}
	}

public:

	static void ShowManageUsersMenu()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}

		system("cls");
		clsScreen::_DrawScreenHeader("\t   Manage Users Screen");

		cout << setw(40) << left << "" << "======================================\n";
		cout << setw(40) << left << "" << "\t   Manage Users Menu\n";
		cout << setw(40) << left << "" << "======================================\n";

		cout << setw(40) << left << "" << "[1] List Users.\n";
		cout << setw(40) << left << "" << "[2] Add New User.\n";
		cout << setw(40) << left << "" << "[3] Delete User.\n";
		cout << setw(40) << left << "" << "[4] Update User.\n";
		cout << setw(40) << left << "" << "[5] Find User.\n";
		cout << setw(40) << left << "" << "[6] Main Menu.\n";

		cout << setw(40) << left << "" << "======================================\n";

		_PerformManageUsersOptions((enManageUsersOptions)_ReadManageUsersOption());
	}
};