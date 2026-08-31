#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithDrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen
{
	
private:

	enum enTransactionsMenuOptions { eDeposit = 1, eWithdraw = 2,
		eTotalBalances = 3, eTransfer = 4, eTransferLog = 5, eMainMenu = 6};

	static short _ReadTransactionsMenuOption()
	{
		cout << setw(40) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadNumberBetween<short>(1, 6);
		return Choice;
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithDrawScreen::ShowWithDrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _GoBackToTransactionsMenu()
	{
		cout << "\n\n";
		cout << setw(8) << left << "" << "Press any key to go back to the transactions menu...";
		system("pause>0");
		ShowTransactionsMenu();
	}

	static void _PerformTransactionsMuneOptions(enTransactionsMenuOptions TransactionsMenuOption)
	{
		switch (TransactionsMenuOption)
		{
		case enTransactionsMenuOptions::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenu();
			break;
		case enTransactionsMenuOptions::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenu();
			break;
		case enTransactionsMenuOptions::eTotalBalances:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenu();
			break;
		case enTransactionsMenuOptions::eTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenu();
		case enTransactionsMenuOptions::eTransferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenu();
		case clsTransactionsScreen::eMainMenu:
			break;
		}
	}
	
public:

	static void ShowTransactionsMenu()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pTransactions))
		{
			return;
		}

		system("cls");
		clsScreen::_DrawScreenHeader("\t   Transactions Screen");

		cout << setw(40) << left << "" << "======================================\n";
		cout << setw(40) << left << "" << "\t    Transactions Menu\n";
		cout << setw(40) << left << "" << "======================================\n";

		cout << setw(40) << left << "" << "[1] Deposit.\n";
		cout << setw(40) << left << "" << "[2] Withdraw.\n";
		cout << setw(40) << left << "" << "[3] Total Balances.\n";
		cout << setw(40) << left << "" << "[4] Transfer.\n";
		cout << setw(40) << left << "" << "[5] Transfer Log.\n";
		cout << setw(40) << left << "" << "[6] Main Menu.\n";

		cout << setw(40) << left << "" << "======================================\n";

		_PerformTransactionsMuneOptions((enTransactionsMenuOptions)_ReadTransactionsMenuOption());
	}
};

