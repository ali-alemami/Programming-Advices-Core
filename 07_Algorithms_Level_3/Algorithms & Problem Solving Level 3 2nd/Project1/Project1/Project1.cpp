#include <iostream>
#include "MyStringLib.h"
#include "MyDateLib.h"

using namespace std;
using namespace MyStringLib;
using namespace MyDateLib;


enum enMainMenuOptions
{
	ShowClientListScreen = 1, AddNewClientScreen = 2,
	DeleteClientScreen = 3, UpdateClientScreen = 4,
	FindClientScreen = 5, Transactions = 6, ExitScreen = 7
};

void PerformMainMenuOptions(enMainMenuOptions MainMenuOptins);

short ReadMainMenuOption()
{
	short Option = 0;
	cout << "\nChoose what do you want to do? [1 to 7]? ";
	cin >> Option;
	return Option;
}

void ShowMainMenu()
{
	system("cls");
	cout << "================================";
	cout << "\n        Main Menu Screen      \n";
	cout << "================================";

	cout << "\n\n    [1] Show Client List.\n";
	cout << "    [2] Add New Client.\n";
	cout << "    [3] Delete Client.\n";
	cout << "    [4] Update Client.\n";
	cout << "    [5] Find Client.\n";
	cout << "    [6] Transactions.\n";
	cout << "    [7] Exit.\n";
	cout << "============================";
	
	PerformMainMenuOptions(enMainMenuOptions(ReadMainMenuOption()));
}

void GoBackToMainMenu()
{
	cout << "\n\nPrees any key to go back to the main menu...";
	system("pause>0");
	ShowMainMenu();
}

void ShowHeaderForAddNewClientScreen()
{
	cout << "----------------------------------";
	cout << "\n      Add New Clients Screen      \n";
	cout << "----------------------------------\n";
}

void ShowAddNewClientsScreen()
{
	ShowHeaderForAddNewClientScreen();
	AddNewClients();
}

void ShowHeaderForDeleteClientScreen()
{
	cout << "--------------------------------";
	cout << "\n      Delete Client Screen      \n";
	cout << "--------------------------------\n";
}

void ShowDeleteClientScreen()
{
	ShowHeaderForDeleteClientScreen();
	string AccountNumber = ReadAccountNumber();
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFile);
	DeleteClientByAccountNumber(AccountNumber, vClients);
}

void ShowHeaderForUpdateClientScreen()
{
	cout << "--------------------------------";
	cout << "\n      Update Client Screen      \n";
	cout << "--------------------------------\n";
}

void ShowUpdateClientScreen()
{
	ShowHeaderForUpdateClientScreen();
	string AccountNumber = ReadAccountNumber();
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFile);
	UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowHeaderForFindClientScreen()
{
	cout << "------------------------------";
	cout << "\n      Find Client Screen      \n";
	cout << "------------------------------\n";
}

void ShowFindClientScreen()
{
	ShowHeaderForFindClientScreen();
	vector <sClient> vClient = LoadClientsDataFromFile(ClientsFile);
	string AccountNumber = ReadAccountNumber();
	sClient Client;

	if (FindClientByAccountNumber(AccountNumber, vClient, Client))
		PrintClientRecord(Client);

	else
		cout << "\nClient With Account Number is not found!\n\n";

}

enum enTransactions { Depsit = 1, Withdraw = 2, TotalBalances = 3, MainMenu = 4 };

short ReadTransactionsMenuOption()
{
	short Option = 0;
	cout << "Choose what do you want to do? [1 to 4]? ";
	cin >> Option;
	return Option;
}

void PerformTransactionsMenuOption(enTransactions Transactions);

void ShowTransactionsMenuScreen()
{
	cout << "=====================================";
	cout << "\n      Transactions Menue Screen      \n";
	cout << "=====================================\n";

	cout << "    [1] Deposit.\n";
	cout << "    [2] Withdraw.\n";
	cout << "    [3] Total Balances.\n";
	cout << "    [4] Main Menu.\n";
	cout << "=====================================\n";

	PerformTransactionsMenuOption((enTransactions)ReadTransactionsMenuOption());
}

void GoBackToTransactionsScreen()
{
	cout << "\n\nPress any key to go back to the transactions screen...";
	system("pause");
	ShowTransactionsMenuScreen();
}

bool DepositToClient(string AccountNumber, vector <sClient>& vClients, float DepositAmount)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.AccoutBalance += DepositAmount;
			cout << "\nDone successfully, new balance is : " << C.AccoutBalance << endl;
			return true;
		}
	}
	return false;
}

void DepositProcess(string AccountNumber, vector <sClient>& vClients)
{
	sClient Client;

	PrintClientRecord(Client);

	float DepositAmount = 0;
	cout << "\nEnter Deposit Amount? ";
	cin >> DepositAmount;

	char Answer = 'n';
	cout << "\nAre YOU SURE!!!!!???? ";
	cin >> Answer;
	if (tolower(Answer) == 'y')
	{
		DepositToClient(AccountNumber, vClients, DepositAmount);
		SaveClientsDataToFile(ClientsFile, vClients);
	}
}

void ShowDepositScreen()
{
	cout << "--------------------------";
	cout << "\n      Deposit Screen      ";
	cout << "--------------------------\n";

	string AccountNumber = ReadAccountNumber();

	while (!ClientExistByAccountNumberInFile(ClientsFile, AccountNumber))
	{
		cout << "Client with Account Number " << AccountNumber << "Does Not exist!";
		AccountNumber = ReadAccountNumber();
	}
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFile);

	DepositProcess(AccountNumber, vClients);
}

void ShowExitScreen()
{
	cout << "------------------------";
	cout << "\n      Program Ends      \n";
	cout << "------------------------"  << endl;
}

void PerformTransactionsMenuOption(enTransactions Transactions)
{
	system("cls");
	switch (Transactions)
	{
	case Depsit:
		ShowDepositScreen();
		GoBackToTransactionsScreen();
		break;
	case Withdraw:
		break;
	case TotalBalances:
		break;
	case MainMenu:
		break;
	default:
		break;
	}
}

void PerformMainMenuOptions(enMainMenuOptions MainMenuOptins)
{
	system("cls");
	switch (MainMenuOptins)
	{
	case ShowClientListScreen:
		ShowAllClientsScreen();
		GoBackToMainMenu();
		break;

	case AddNewClientScreen:
		ShowAddNewClientsScreen();
		GoBackToMainMenu();
		break;

	case DeleteClientScreen:
		ShowDeleteClientScreen();
		GoBackToMainMenu();
		break;

	case UpdateClientScreen:
		ShowUpdateClientScreen();
		GoBackToMainMenu();
		break;

	case FindClientScreen:
		ShowFindClientScreen();
		GoBackToMainMenu();
		break;

	case Transactions:
		ShowTransactionsMenuScreen();
		GoBackToMainMenu();
		break;

	case ExitScreen:
		ShowExitScreen();
		break;

	default:
		ShowAllClientsScreen();
		GoBackToMainMenu();
		break;
	}
}

int main()
{
	ShowMainMenu();
	

	system("pause>0");
	return 0;
}