#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:

	enum enMainMenuOptions { eClientsList = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eTransactions = 6, eManageUsers = 7,
		eLoginRegister = 8, eCurrencyExchange = 9, eLogout = 10 };

	static short _ReadMainMenuOption()
	{
		cout << setw(40) << left << "" << "Choose what do you want to do [1 to 10]? ";
		short Choice = clsInputValidate::ReadNumberBetween(1, 10);
		return Choice;
	}

	static void _ShowClientListScreen()
	{
		clsClientListScreen::ShowClientList();
	}

	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenu()
	{
		clsTransactionsScreen::ShowTransactionsMenu();
	}

	static void _ShowManageUsersScreen()
	{
		clsManageUsersScreen::ShowManageUsersMenu();
	}

	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}
	
	static void _ShowCurrencyExchangeMenu()
	{
		clsCurrencyExchangeScreen::ShowCurrencyExchangeMenu();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}

	static void _GoBackToMainMenu()
	{
		cout << "\n\n";
		cout << setw(8) << left << "" << "Press any key to go back to the main menu...";
		system("pause>0");
		ShowMainMenu();
	}

	static void _PerformMainMenuOptions(enMainMenuOptions MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case enMainMenuOptions::eClientsList:
			system("cls");
			_ShowClientListScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eAddNewClient:
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eTransactions:
			system("cls");
			_ShowTransactionsMenu();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eManageUsers:
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eLoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
		case enMainMenuOptions::eCurrencyExchange:
			system("cls");
			_ShowCurrencyExchangeMenu();
			_GoBackToMainMenu();
		case enMainMenuOptions::eLogout:
			system("cls");
			_Logout();
			break;
		}
	}

public:

	static void ShowMainMenu()
	{
		system("cls");
		clsScreen::_DrawScreenHeader("\t      Main Screen");

		cout << setw(40) << left << "" << "======================================\n";
		cout << setw(40) << left << "" << "\t       Main Menu\n";
		cout << setw(40) << left << "" << "======================================\n";
									 
		cout << setw(40) << left << "" << "[1] Show Client List.\n";
		cout << setw(40) << left << "" << "[2] Add New Client.\n";
		cout << setw(40) << left << "" << "[3] Delete Client.\n";
		cout << setw(40) << left << "" << "[4] Update Client Info.\n";
		cout << setw(40) << left << "" << "[5] Find Client.\n";
		cout << setw(40) << left << "" << "[6] Transactions.\n";
		cout << setw(40) << left << "" << "[7] Manage Users.\n";
		cout << setw(40) << left << "" << "[8] Login Register.\n";
		cout << setw(40) << left << "" << "[9] Currency Exchange.\n";
		cout << setw(40) << left << "" << "[10] Logout.\n";

		cout << setw(40) << left << "" << "======================================\n";
		
		_PerformMainMenuOptions((enMainMenuOptions)_ReadMainMenuOption());
	}
};
