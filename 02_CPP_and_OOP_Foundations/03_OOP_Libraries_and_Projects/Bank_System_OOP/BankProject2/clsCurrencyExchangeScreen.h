#pragma once

#include "iostream"
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeScreen : protected clsScreen
{
private:

	enum enCurrencyExchangeMenuOptions { eCurrenciesList = 1,
		eFindCurrency = 2, eUpdateRate = 3,
		eCurrencyCalculator = 4, eMainMenu = 5 };

	static short _ReadCurrencyExchangeMenuOption()
	{
		cout << setw(40) << left << "" << "Choose what do you want to do [1 to 5]? ";
		short Choice = clsInputValidate::ReadNumberBetween<short>(1, 5);
		return Choice;
	}

	static void _ShowCurrenciesListScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrenciesScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrenciesScreen()
	{
		clsUpdateRateScreen::ShowUpdateRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _GoBackToCurrencyExchangeMenu()
	{
		cout << "\n\n";
		cout << setw(8) << left << "" << "Press any key to go back to the currency exchange menu...";
		system("pause>0");
		ShowCurrencyExchangeMenu();
	}

	static void _PerformCurrencyExchangeMenuOptions(enCurrencyExchangeMenuOptions CurrencyExchangeMenuOption)
	{
		switch (CurrencyExchangeMenuOption)
		{
		case clsCurrencyExchangeScreen::eCurrenciesList:
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		case clsCurrencyExchangeScreen::eFindCurrency:
			system("cls");
			_ShowFindCurrenciesScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		case clsCurrencyExchangeScreen::eUpdateRate:
			system("cls");
			_ShowUpdateCurrenciesScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		case clsCurrencyExchangeScreen::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		case clsCurrencyExchangeScreen::eMainMenu:
			break;
		}
	}

public:

	static void ShowCurrencyExchangeMenu()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
		{
			return;
		}

		system("cls");
		clsScreen::_DrawScreenHeader("\tCurrency Exchange Screen");

		cout << setw(40) << left << "" << "======================================\n";
		cout << setw(40) << left << "" << "\tCurrency Exchange Menu\n";
		cout << setw(40) << left << "" << "======================================\n";

		cout << setw(40) << left << "" << "[1] Currencies List.\n";
		cout << setw(40) << left << "" << "[2] Find Currency.\n";
		cout << setw(40) << left << "" << "[3] Update Rate.\n";
		cout << setw(40) << left << "" << "[4] Currency Calculator.\n";
		cout << setw(40) << left << "" << "[5] Main Menu.\n";

		cout << setw(40) << left << "" << "======================================\n";

		_PerformCurrencyExchangeMenuOptions((enCurrencyExchangeMenuOptions)_ReadCurrencyExchangeMenuOption());
	}
};

