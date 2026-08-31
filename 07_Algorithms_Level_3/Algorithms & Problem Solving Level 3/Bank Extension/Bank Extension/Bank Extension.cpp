#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

void ShowMainMenuScreen();
void ShowTransactionsMenuScreen();

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance = 0;
	bool SetToDelete = false;
};

enum enMainMenuOptions
{
	eClientList = 1, eAddNewClient = 2,
	eDeleteClient = 3, eUpdateClient = 4,
	eFindClient = 5, eShowTransactionMenu = 6, eExit = 7
};

enum enTransactionMenuOptions
{
	eDeposit = 1, eWithdraw = 2,
	eShowTotalBalances = 3, eShowMainMenu = 4
};

vector <string> SplitString(string S1, string Delim = "#//#")
{
	vector <string> vString;
	short pos = 0;
	string sWord = "";

	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1);
	}
	return vString;
}

sClient ConvertLineToRecord(string Line)
{
	sClient Client;
	vector <string> vString = SplitString(Line);

	Client.AccountNumber = vString[0];
	Client.PinCode = vString[1];
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.AccountBalance = stof(vString[4]);
	return Client;
}

vector <sClient> LoadClientsDataFromFile(string FileName)
{
	vector <sClient> vClients;

	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line = "";
		sClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return vClients;
}

void PrintClientInfoInLine(sClient Client)
{
	cout << "| " << left << setw(15) << Client.AccountNumber;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(30) << Client.Name;
	cout << "| " << left << setw(15) << Client.Phone;
	cout << "| " << left << setw(20) << Client.AccountBalance;
}

void ShowClientListScreen()
{
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	if (vClients.size() == 0)
	{
		cout << "\n\nThere is no Clients in the system at the moment.\n\n";
	}
	else
	{
		cout << "\n\t\t\tClient List (" << vClients.size() << ") Client(s).";
		cout << "\n\n______________________________________________________________________________________________________\n\n";
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(30) << "Client Name";
		cout << "| " << left << setw(15) << "Phone";
		cout << "| " << left << setw(20) << "Balnce";
		cout << "\n\n______________________________________________________________________________________________________\n\n";

		for (sClient C : vClients)
		{
			PrintClientInfoInLine(C);
			cout << endl;
		}
		cout << "\n\n______________________________________________________________________________________________________\n\n";
	}
}

bool DoesNumberExistByAccountNumber(string AccountNumber, vector <sClient> vCLients)
{
	for (sClient C : vCLients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			return true;
		}
	}
	return false;
}

sClient EnterClientInfo(sClient& Client)
{
	cout << "\nEnter Pin Code? ";
	getline(cin >> ws, Client.PinCode);

	cout << "\nEnter Name? ";
	getline(cin, Client.Name);

	cout << "\nEnter Phone? ";
	getline(cin, Client.Phone);

	cout << "\nEnter Account Balance? ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToLine(sClient Client, string Delim = "#//#")
{
	string Line = Client.AccountNumber + Delim;
	Line += Client.PinCode + Delim;
	Line += Client.Name + Delim;
	Line += Client.Phone + Delim;
	Line += to_string(Client.AccountBalance);
	return Line;
}

void AddDataLineToFile(string FileName, string Line)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << Line << endl;
	}
	MyFile.close();
}

void AddNewClient()
{
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	sClient Client;
	cout << "\nAdding New Client:\n\n";

	cout << "Enter Account Number? ";
	getline(cin >> ws, Client.AccountNumber);

	while (DoesNumberExistByAccountNumber(Client.AccountNumber, vClients))
	{
		cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
		getline(cin >> ws, Client.AccountNumber);
	}

	Client = EnterClientInfo(Client);

	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddNewClients()
{
	char Answer = 'y';
	do
	{
		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add another client? ";
		cin >> Answer;

	} while (tolower(Answer) == 'y');
}

void ShowAddNewClientScreen()
{
	cout << "\n\n-------------------------------\n\n";
	cout << "\tAdd New Clients Screen";
	cout << "\n\n-------------------------------\n";
	AddNewClients();
}

string ReadAccountNumber()
{
	string AccountNumber = "";
	cout << "Enter Account Number? ";
	getline(cin >> ws, AccountNumber);
	return AccountNumber;
}

bool MarkClientForDeletion(string AccountNumber, vector <sClient>& vClients)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.SetToDelete = true;
			return true;
		}
	}
	return false;
}

bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
{
	for (sClient C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

void PrintClientInfo(sClient Client)
{
	cout << "------------------------------\n";
	cout << "Account Number: " << Client.AccountNumber << endl;
	cout << "Pin Code      : " << Client.PinCode << endl;
	cout << "Name          : " << Client.Name << endl;
	cout << "Phone         : " << Client.Phone << endl;
	cout << "Account Balance: " << Client.AccountBalance << endl << endl;
	cout << "------------------------------\n";
}

void SaveClientsDataToFile(string FileName, vector <sClient> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		for (sClient C : vClients)
		{
			string Line = "";

			if (C.SetToDelete == false)
			{
				Line = ConvertRecordToLine(C);
				MyFile << Line << endl;
			}
		}
		MyFile.close();
	}
}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
	sClient Client;
	char Answer = 'y';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		cout << "\n\nThe following are the client details:\n\n";
		PrintClientInfo(Client);

		cout << "Are you sure you want to delete this client? y/n? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			MarkClientForDeletion(AccountNumber, vClients);
			SaveClientsDataToFile(ClientsFileName, vClients);

			cout << "\nClient was Deleted Successfully.\n";

			vClients = LoadClientsDataFromFile(ClientsFileName);
			return true;
		}
		else
		{
			cout << "\n\nClient was Not Deleted.\n\n";
			return false;
		}
	}
	else
	{
		cout << "\n\nThis Account Number Doesn't exist.\n\n";
		return false;
	}
}

void ShowDeleteClientScreen()
{
	cout << "\n\n-------------------------------\n\n";
	cout << "\tDelete Client Screen";
	cout << "\n\n-------------------------------\n";

	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, vClients);
}

bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
	sClient Client;
	char Answer = 'y';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		cout << "\n\nThe following are the client details:\n\n";
		PrintClientInfo(Client);

		cout << "Are you sure you want to update this client? y/n? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			for (sClient& C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					EnterClientInfo(C);
					break;
				}
			}
			SaveClientsDataToFile(ClientsFileName, vClients);
			cout << "\nClient was updated Successfully.\n";

			return true;
		}
		else
		{
			cout << "\n\nClient was Not updated.\n\n";
			return false;
		}
	}
	else
	{
		cout << "\n\nThis Account Number Doesn't exist.\n\n";
		return false;
	}
}

void ShowUpdateClientScreen()
{
	cout << "\n\n-------------------------------\n\n";
	cout << "\tUpdate Client Screen";
	cout << "\n\n-------------------------------\n";

	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadAccountNumber();
	UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowFindClientScreen()
{
	cout << "\n\n-------------------------------\n\n";
	cout << "\tFind Client Screen";
	cout << "\n\n-------------------------------\n";
	string AccountNumber = ReadAccountNumber();
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	sClient Client;

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		cout << "\nThe following are the client details:\n";
		PrintClientInfo(Client);
	}
	else
	{
		cout << "\nThis Account Number does Not exist.\n\n";
	}
}

void GoBackToTransactionMenu()
{
	cout << "Press any key to go back to transaction menu...";
	system("pause>0");
	ShowTransactionsMenuScreen();
}

void PrintClientBalanceInLine(sClient Client)
{
	cout << "| " << left << setw(15) << Client.AccountNumber;
	cout << "| " << left << setw(30) << Client.Name;
	cout << "| " << left << setw(20) << Client.AccountBalance;
}

void ShowTotalBalancesScreen()
{
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	if (vClients.size() == 0)
	{
		cout << "\n\nThere is no Clients in the system at the moment.\n\n";
	}
	else
	{
		cout << "\n\t\t\tClient List (" << vClients.size() << ") Client(s).";
		cout << "\n\n______________________________________________________________________________________________________\n\n";
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(30) << "Client Name";
		cout << "| " << left << setw(20) << "Balnce";
		cout << "\n\n______________________________________________________________________________________________________\n\n";
	}
	double Balance = 0;

	for (sClient C : vClients)
	{
		PrintClientBalanceInLine(C);
		Balance += C.AccountBalance;
		cout << endl;
	}
	cout << "\n\n______________________________________________________________________________________________________\n\n";
	cout << "\t\t\t\t\tTotal Balances = " << Balance << endl;
}

bool SaveNewAccountBalance(sClient Client, vector <sClient>& vClients)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == Client.AccountNumber)
		{
			C.AccountBalance = Client.AccountBalance;
			return true;
		}
	}
	return false;
}

/*void DepositOrWithdrawClient(string AccountNumber, vector <sClient>& vClients, enTransactionMenuOptions DepositOrWithdraw)
{
	sClient Client;

	while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		cout << "Client with [" << AccountNumber << "] does not exist.\n\n";
		cout << "Enter Account Number? ";
		getline(cin >> ws, AccountNumber);
	}
	cout << "\nThe following are the client details:\n";
	PrintClientInfo(Client);

	double Amount = 0;
	cout << "Enter Deposit Amount?";
	cin >> Amount;

	char Answer = 'y';
	cout << "Are you sure you want to perform this transaction? y/n? ";
	cin >> Answer;

	if (tolower(Answer) == 'y' && DepositOrWithdraw == eDeposit)
	{
		Client.AccountBalance += Amount;
		SaveNewAccountBalance(Client, vClients);
		cout << "Done Successfully, new balance is " << Client.AccountBalance << endl;
		SaveClientsDataToFile(ClientsFileName, vClients);

	}
	else if (tolower(Answer) == 'y' && DepositOrWithdraw == eWithdraw)
	{
		while (Amount > Client.AccountBalance)
		{
			cout << "\nAmount Exceedes the balance, you can withdraw up to : " << Client.AccountBalance << endl;
			cout << "Enter another amount? ";
			cin >> Amount;
			cout << "Are you sure you want to perform this transaction? y/n? ";
			cin >> Answer;
		}
		Client.AccountBalance -= Amount;
		SaveNewAccountBalance(Client, vClients);
		cout << "Done Successfully, new balance is " << Client.AccountBalance << endl;
		SaveClientsDataToFile(ClientsFileName, vClients);
	}
	
}*/

bool DeposintBalanceToClientByAccountNumber(string AccountNumber, vector <sClient>& vClients, double Amount)
{
	char Answer = 'y';
	cout << "Are you sure you want to perform this transaction? y/n? ";
	cin >> Answer;

	if (tolower(Answer) == 'y')
	{
		for (sClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.AccountBalance += Amount;
				SaveClientsDataToFile(ClientsFileName, vClients);
				cout << "Dont Successfully, new balance is: " << C.AccountBalance << endl;
				return true;
			}
		}
	}
	return false;
}

void ShowDepositScreen()
{
	cout << "\n\n-------------------------------\n\n";
	cout << "\tDeposit Screen";
	cout << "\n\n-------------------------------\n";

	sClient Client;
	string AccountNumber = ReadAccountNumber();
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	
	while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		cout << "\nClient with [" << AccountNumber << "] does not exit.\n";
		AccountNumber = ReadAccountNumber();
	}
	PrintClientInfo(Client);

	double Amount = 0;
	cout << "\nEnter deposit amount? ";
	cin >> Amount;

	DeposintBalanceToClientByAccountNumber(AccountNumber, vClients, Amount);
}

void ShowWithdrawScreen()
{
	cout << "\n\n-------------------------------\n\n";
	cout << "\tWithdraw Screen";
	cout << "\n\n-------------------------------\n";

	sClient Client;
	string AccountNumber = ReadAccountNumber();
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	
	if (!FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		cout << "\nClient with [" << AccountNumber << "] does not exit.\n";
		AccountNumber = ReadAccountNumber();
	}
	PrintClientInfo(Client);

	double Amount;
	cout << "Enter the amount you want to withdraw? ";
	cin >> Amount;

	while (Amount > Client.AccountBalance)
	{
		cout << "\nAmount exceeds the balance, you can withdraw up to: " << Client.AccountBalance << endl;
		cout << "Enter Withdraw Amount? ";
		cin >> Amount;
	}

	DeposintBalanceToClientByAccountNumber(AccountNumber, vClients, Amount * -1);
}

void GoBackToTheMainMenu()
{
	cout << "Press any key to go back to the main menu...";
	system("pause>0");
	ShowMainMenuScreen();
}

void ChoseTransactionOption(enTransactionMenuOptions TransactionMenuOptions)
{
	switch (TransactionMenuOptions)
	{
	case eDeposit:
		system("cls");
		ShowDepositScreen();
		GoBackToTransactionMenu();
		break;

	case eWithdraw:
		system("cls");
		ShowWithdrawScreen();
		GoBackToTransactionMenu();
		break;

	case eShowTotalBalances:
		system("cls");
		ShowTotalBalancesScreen();
		GoBackToTransactionMenu();
		break;

	case eShowMainMenu:
		ShowMainMenuScreen();
	}
}

short ReadTransactionMenuOption()
{
	short Answer = 0;
	cout << "Choose what do you want to do? [1 to 4]? ";
	cin >> Answer;
	return Answer;
}

void ShowTransactionsMenuScreen()
{
	system("cls");
	cout << "==============================\n\n";
	cout << "\tTransactions Menu Screen\n\n";
	cout << "==============================\n\n";

	cout << "[1] Deposit.\n";
	cout << "[2] Withdraw.\n";
	cout << "[3] Total Balances.\n";
	cout << "[4] Main Menu.\n";

	ChoseTransactionOption(enTransactionMenuOptions(ReadTransactionMenuOption()));
}

void ShowExitScreen()
{
	cout << "\n\n-------------------------------\n\n";
	cout << "\tProgram ends";
	cout << "\n\n-------------------------------\n";
}

void ChooseMainMenuOption(enMainMenuOptions MainMenuOption)
{
	switch (MainMenuOption)
	{
	case eClientList:
		system("cls");
		ShowClientListScreen();
		GoBackToTheMainMenu();
		break;

	case eAddNewClient:
		system("cls");
		ShowAddNewClientScreen();
		GoBackToTheMainMenu();
		break;

	case eDeleteClient:
		system("cls");
		ShowDeleteClientScreen();
		GoBackToTheMainMenu();
		break;

	case eUpdateClient:
		system("cls");
		ShowUpdateClientScreen();
		GoBackToTheMainMenu();
		break;

	case eFindClient:
		system("cls");
		ShowFindClientScreen();
		GoBackToTheMainMenu();
		break;

	case eShowTransactionMenu:
		system("cls");
		ShowTransactionsMenuScreen();
		break;

	case eExit:
		system("cls");
		ShowExitScreen();
		break;

	default:
		system("cls");
		ShowExitScreen();
		break;
	}
}

short ReadMainMenuOption()
{
	short Option = 0;
	cout << "Choose what do you want to do? [1 to 7]? ";
	cin >> Option;
	return Option;
}

void ShowMainMenuScreen()
{
	system("cls");
	cout << "==============================\n\n";
	cout << "\tMain Menu Screen\n\n";
	cout << "==============================\n\n";

	cout << "[1] Show Client List.\n";
	cout << "[2] Add New Client.\n";
	cout << "[3] Delete Client.\n";
	cout << "[4] Update Client Info.\n";
	cout << "[5] Find Client.\n";
	cout << "[6] Transactions.\n";
	cout << "[7] Exit.\n\n";
	cout << "==============================\n\n";

	ChooseMainMenuOption(enMainMenuOptions(ReadMainMenuOption()));
}

int main()
{
	ShowMainMenuScreen();

	return 0;
}