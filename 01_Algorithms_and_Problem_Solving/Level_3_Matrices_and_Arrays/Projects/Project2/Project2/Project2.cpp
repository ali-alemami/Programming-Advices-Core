#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

struct stClient
{
	string AccountNumber;
	string PinCode;
	string ClientName;
	string PhoneNumber;
	float AccountBalance = 0;
};

const string ClientsFile = "Clients.txt";

stClient CurrentClient;

enum enAtmMainMenuOptions
{
	eQucikWithdraw = 1, eNormalWithdraw = 2,
	eDeposit = 3, eCheckBalance = 4,
	eLogOut = 5
};

void AtmMainMenuScreen();
void Login();
void ShowQuickWithDrawScreen();
void ShowNormalWithDrawScreen();

vector <string> SplitString(string S1, string Separator = "#//#")
{
	vector <string> vString;
	short pos = 0;
	string sWord = "";
	while ((pos = S1.find(Separator)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Separator.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1);
	}
	return vString;
}

stClient ConvertClientLineToRecord(string Line)
{
	vector <string> vString = SplitString(Line);
	stClient Client;

	Client.AccountNumber = vString[0];
	Client.PinCode = vString[1];
	Client.ClientName = vString[2];
	Client.PhoneNumber = vString[3];
	Client.AccountBalance = stof(vString[4]);
	return Client;
}

vector <stClient> LoadClientsDataFromFile(string FileName)
{
	vector <stClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line = "";
		stClient Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertClientLineToRecord(Line);
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return vClients;
}

bool FindClientByAccountNumberAndPinCode(string AccountNumber, string PinCode, stClient& Client)
{
	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFile);

	for (stClient C : vClients)
	{
		if (C.AccountNumber == AccountNumber && C.PinCode == PinCode)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

bool LoadClientInfo(string AccoutNumber, string PinCode)
{
	if (FindClientByAccountNumberAndPinCode(AccoutNumber, PinCode, CurrentClient))
		return true;
	else
		return false;
}

short ReadAtmMainMenuOption()
{
	short Option = 0;
	cout << "Choose what do you want to do? [1 to 5]? ";
	cin >> Option;
	return Option;
}

void GoBackToTheMainMenu()
{
	cout << "\n\nPress any key to go back to the main mene...";
	system("pause>0");
	AtmMainMenuScreen();
}

void CheckBalanceScreen()
{
	
	cout << "================================\n";
	cout << "      Check Balance Screen      \n";
	cout << "================================\n";
	cout << "Your Balance is " << CurrentClient.AccountBalance << endl;
}

string ConvertClientRecordToLine(stClient Client, string Separator = "#//#")
{
	string stDataLine = "";
	stDataLine += Client.AccountNumber + Separator;
	stDataLine += Client.PinCode + Separator;
	stDataLine += Client.ClientName + Separator;
	stDataLine += Client.PhoneNumber + Separator;
	stDataLine += to_string(Client.AccountBalance) + Separator;
	return stDataLine;
}

void SaveClientsDataToFile(string FileName, vector <stClient> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		string Line = "";
		for (stClient& C : vClients)
		{
			Line = ConvertClientRecordToLine(C);
			MyFile << Line << endl;
		}
		MyFile.close();
	}
}

bool DepositBalanceToClientByAccountNumber(string AccountNumber, float Amount, vector <stClient>& vClients)
{
	char Answer = 'n';
	cout << "\nAre you sure you want to perform this transaction? y/n? ";
	cin >> Answer;

	if(tolower(Answer) == 'y')
	{
		for (stClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.AccountBalance += Amount;
				SaveClientsDataToFile(ClientsFile, vClients);
				return true;
			}
		}
	}
	return false;
}

short ReadQucikWithDrawOption()
{
	short Answer = 0;
	while (Answer < 1 || Answer > 9)
	{
		cout << "Choose what to do from [1] to [9]? ";
		cin >> Answer;
	}
	
	return Answer;
}

short GetQuickWithDrawAmount(short QuickWithDrawAmount)
{
	switch (QuickWithDrawAmount)
	{
	case 1:
		return 20;
	case 2:
		return 50;
	case 3:
		return 100;
	case 4:
		return 200;
	case 5:
		return 400;
	case 6:
		return 600;
	case 7:
		return 800;
	case 8:
		return 100;
	default:
		return 0;
	}
}

void PerformQuickWithDrawOption(short QuickWithDrawOption)
{
	if (QuickWithDrawOption == 9)
	{
		return;
	}

	short WithDrawAmount = GetQuickWithDrawAmount(QuickWithDrawOption);

	if (WithDrawAmount > CurrentClient.AccountBalance)
	{
		cout << "\nAmount Exceeds your balance, make another choice.\n";
		cout << "press any key to continue...";
		system("pause>0");
		ShowQuickWithDrawScreen();
		return;
	}
	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFile);
	DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, WithDrawAmount * -1, vClients);
	CurrentClient.AccountBalance -= WithDrawAmount;
}

void ShowQuickWithDrawScreen()
{
	system("cls");
	cout << "==========================\n";
	cout << "      Quick WithDraw      \n";
	cout << "==========================\n";
	cout << "    " << left << setw(10) << "[1] 20" << left << setw(10) << "[2] 50" << endl;
	cout << "    " << left << setw(10) << "[3] 100" << left << setw(10) << "[4] 200" << endl;
	cout << "    " << left << setw(10) << "[5] 400" << left << setw(10) << "[6] 600" << endl;
	cout << "    " << left << setw(10) << "[7] 800" << left << setw(10) << "[8] 1000" << endl;
	cout << "    " << left << setw(10) << "[9] Exit" << endl;
	cout << "==========================\n";
	cout << "Your Balance is " << CurrentClient.AccountBalance << endl;

	PerformQuickWithDrawOption(ReadQucikWithDrawOption());
}

void DepositProcess(float Amount)
{
	char Answer = 'n';
	cout << "\nAre you sure you want to perform this transaction? ";
	cin >> Answer;

	if (tolower(Answer) == 'y')
	{
		vector <stClient> vClients = LoadClientsDataFromFile(ClientsFile);
		DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, Amount, vClients);
		CurrentClient.AccountBalance += Amount;
	}
}

int ReadWithDrawAmount()
{
	int Amount = 0;
	cout << "\nEnter an amount multiple of 5's ? ";
	cin >> Amount;

	while (Amount % 5 != 0)
	{
		cout << "\nEnter an amount multiple of 5's ? ";
		cin >> Amount;
	}
	return Amount;
}

void PerformNormalWithDraw()
{
	short WithDrawAmount = ReadWithDrawAmount();

	if (WithDrawAmount > CurrentClient.AccountBalance)
	{
		cout << "\nAmount Exceeds your balance\n";
		cout << "Press any key to continue...";
		system("pause>0");
		ShowNormalWithDrawScreen();
	}
	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFile);
	DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, WithDrawAmount * -1, vClients);
	CurrentClient.AccountBalance -= WithDrawAmount;
}

void ShowNormalWithDrawScreen()
{

	system("cls");
	cout << "==================================\n";
	cout << "      Normal WithDraw Screen      \n";
	cout << "==================================\n";

	PerformNormalWithDraw();
}

int ReadDepositAmount()
{
	int Amount = 0;
	cout << "Enter a Positive Deposit Amount? ";
	cin >> Amount;
	return Amount;
}

void PerformDeposit()
{
	int DepositAmount = ReadDepositAmount();

	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFile);
	DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, DepositAmount, vClients);
	CurrentClient.AccountBalance += DepositAmount;
}

void ShowDepositScreen()
{
	cout << "==========================\n";
	cout << "      Deposit Screen      \n";
	cout << "==========================\n";
	
	PerformDeposit();
}

void PerformAtmMainMenuOption(enAtmMainMenuOptions Options)
{
	switch (Options)
	{
	case eQucikWithdraw:
		system("cls");
		ShowQuickWithDrawScreen();
		GoBackToTheMainMenu();
		break;

	case eNormalWithdraw:
		system("cls");
		ShowNormalWithDrawScreen();
		GoBackToTheMainMenu();
		break;

	case eDeposit:
		system("cls");
		ShowDepositScreen();
		GoBackToTheMainMenu();
		break;

	case eCheckBalance:
		system("cls");
		CheckBalanceScreen();
		GoBackToTheMainMenu();
		break;

	case eLogOut:
		Login();
		break;

	default:
		AtmMainMenuScreen();
		break;
	}
}

void AtmMainMenuScreen()
{
	system("cls");
	cout << "================================\n";
	cout << "      ATM Main Menu Screen      \n";
	cout << "================================\n";
	cout << "    [1] Quick Withdraw.\n";
	cout << "    [2] Normal Withdraw.\n";
	cout << "    [3] Deposit.\n";
	cout << "    [4] Check Balance.\n";
	cout << "    [5] Logout.\n";
	cout << "================================\n";
	PerformAtmMainMenuOption((enAtmMainMenuOptions)(ReadAtmMainMenuOption()));
}

void Login()
{
	string AccountNumber, PinCode;
	bool LoginFailed = false;
	do
	{
		system("cls");
		cout << "------------------------\n";
		cout << "      Login Screen      \n";
		cout << "------------------------\n";
		if (LoginFailed)
		{
			cout << "Invalid Account Number/PinCode\n";
		}
		cout << "Enter Account Number? ";
		getline(cin >> ws, AccountNumber);
		cout << "Enter Pin? ";
		getline(cin, PinCode);

		LoginFailed = !LoadClientInfo(AccountNumber, PinCode);

	} while (LoginFailed);

	AtmMainMenuScreen();
}

int main()
{
	Login();

	system("pause>0");
	return 0;
}