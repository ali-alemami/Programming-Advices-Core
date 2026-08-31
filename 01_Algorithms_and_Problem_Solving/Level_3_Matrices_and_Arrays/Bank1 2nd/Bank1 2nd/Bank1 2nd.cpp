#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

void ShowMainMenu();

enum enMainMenuOption
{
	eListClients = 1, eAddNewClient = 2,
	eDeleteClient = 3, eUpdateClient = 4,
	eFindClient = 5, eExit = 6
};

void GoBackToMainMenu()
{
	cout << "\n\nPress any key to go back to the main menu...";
	system("pause>0");
	ShowMainMenu();
}

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string PhoneNumber;
	float AccountBalance = 0;
	bool SetToDelete = false;
};

vector <string> SplitString(string S1, string Delimeter)
{
	vector <string> vString;
	short pos = 0;
	string sWord = "";

	while ((pos = S1.find(Delimeter)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);

		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		S1.erase(0, pos + Delimeter.length());
	}

	if (S1 != "")
	{
		vString.push_back(S1);
	}
	return vString;
}

sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector <string> vClientData;
	vClientData = SplitString(Line, Seperator);

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.PhoneNumber = vClientData[3];
	Client.AccountBalance = stof(vClientData[4]);

	return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
	string stClientRecord = "";

	stClientRecord = Client.AccountNumber + Seperator;
	stClientRecord = Client.PinCode + Seperator;
	stClientRecord = Client.Name + Seperator;
	stClientRecord = Client.PhoneNumber + Seperator;
	stClientRecord = to_string(Client.AccountBalance);
	return stClientRecord;
}

vector <sClient> LoadClientsDataFromFile(string FileName)
{
	vector <sClient> vClientS;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line = "";
		sClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			vClientS.push_back(Client);
		}
		MyFile.close();
	}
	return vClientS;
}

void PrintClientRecordLine(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.PhoneNumber;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowAllClientsScreen()
{
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	if (vClients.size() == 0)
	{
		cout << "\t\t\t\tNo Client Are Available in the system!";
	}
	else
	{
		for (sClient Client : vClients)
		{
			PrintClientRecordLine(Client);
			cout << endl;
		}
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

}

bool ClientExistByAccountNumber(string AccountNumber, string FileName)
{
	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line = "";
		sClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);

			if (AccountNumber == Client.AccountNumber)
			{
				MyFile.close();
				return true;
			}
		}
		MyFile.close();
	}
	return false;
}

sClient ReadNewClient()
{
	sClient Client;

	cout << "Enter Account Number? ";
	getline(cin >> ws, Client.AccountNumber);

	while (ClientExistByAccountNumber(Client.AccountNumber, ClientsFileName))
	{
		cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
		getline(cin >> ws, Client.AccountNumber);
	}

	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.PhoneNumber);

	cout << "Enter Account Balance? ";
	cin >> Client.AccountBalance;

	return Client;
}

void AddDataLineToFile(string FileName, string Line)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile >> Line;
		MyFile.close();

	}
}

void AddNewClient()
{
	sClient Client;
	Client = ReadNewClient();
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddNewClients()
{
	char AddMore = 'Y';

	do
	{
		cout << "Adding New Client\n\n";
		AddNewClient();

		cout << "Client Added Successfully, Do you want to add more clients? Y/N? ";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');
}

void ShowAddNewClientsScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tAdd New Clients Screen";
	cout << "\n-----------------------------------\n";

	AddNewClients();
}

string ReadClientAccountNumber()
{
	string AccountNumber = "";
	cout << "\nPlease enter AccountNumber? ";
	cin >> AccountNumber;
	return AccountNumber;
}

bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
{
	for (sClient C : vClients)
	{
		if (AccountNumber == C.AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

void PrintClientCard(sClient Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "-----------------------------------";

	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code     : " << Client.PinCode;
	cout << "\nName         : " << Client.Name;
	cout << "\nPhone        : " << Client.PhoneNumber;
	cout << "\nAccount Balance: " << Client.AccountBalance;

	cout << "\n-----------------------------------\n";
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient> vClients)
{
	for (sClient C : vClients)
	{
		if (AccountNumber == C.AccountNumber)
		{
			C.SetToDelete = true;
			return true;
		}
	}
	return false;
}

void SaveClientsDataToFile(string FileName, vector <sClient> vClients)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		for (sClient Client : vClients)
		{
			if (Client.SetToDelete == false)
			{
				MyFile << ConvertRecordToLine(Client) << endl;
			}
		}
		MyFile.close();
	}

}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

		cout << "Are you sure you want to delete this client? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
			SaveClientsDataToFile(ClientsFileName, vClients);

			vClients = LoadClientsDataFromFile(ClientsFileName);

			cout << "Client Deleted Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}
}

void ShowDeleteClientScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tDelete Client Screen";
	cout << "\n-----------------------------------\n";

	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, vClients);
}

sClient ChangeClientRecord(string AccountNumber)
{
	sClient Client;

	Client.AccountNumber = AccountNumber;

	cout << "\n\nEnter PinCode? ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.PhoneNumber);

	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;

	return Client;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient> vClients)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);
		cout << "Are you sure you want to update this client? y/n? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			for (sClient& C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientRecord(AccountNumber);
					break;
				}
			}
			SaveClientsDataToFile(ClientsFileName, vClients);

			cout << "Client updated successfully.";
			return true;
		}
	}
}

void ShowUpdateClientScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tUpdate Client Screen";
	cout << "\n-----------------------------------\n";

	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowFindClientScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tUpdate Client Screen";
	cout << "\n-----------------------------------\n";

	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	sClient Client;

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);
	}
	else
	{
		cout << "\nClient with account number " << AccountNumber << " is not found!";
	}
}

void ShowEndScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tUpdate Client Screen";
	cout << "\n-----------------------------------\n";
}

void PerformMainMenuOption(enMainMenuOption MainMenuOption)
{
	switch (MainMenuOption)
	{
	case enMainMenuOption::eListClients:
	{
		system("cls");
		ShowAllClientsScreen();
		GoBackToMainMenu();
		break;
	}
	case enMainMenuOption::eAddNewClient:
	{
		system("cls");
		ShowAddNewClientsScreen();
		GoBackToMainMenu();
		break;
	}
	case enMainMenuOption::eDeleteClient:
	{
		system("cls");
		ShowDeleteClientScreen();
		GoBackToMainMenu();
		break;
	}
	case enMainMenuOption::eUpdateClient:
	{
		system("cls");
		ShowUpdateClientScreen();
		GoBackToMainMenu();
		break;
	}
	case enMainMenuOption::eFindClient:
	{
		system("cls");
		ShowFindClientScreen();
		GoBackToMainMenu();
		break;
	}
	case enMainMenuOption::eExit:
	{
		system("cls");
		ShowEndScreen();
		GoBackToMainMenu();
		break;
	}
	default:
		break;
	}
}

short ReadMainMenuOption()
{
	cout << "Choose what do you want to do? [1 to 6]? ";
	short Choice = 0;
	cin >> Choice;
	return Choice;
}

void ShowMainMenu()
{
	system("cls");
	cout << "==============================================\n";
	cout << "\t\tMain Menu Screen\n";
	cout << "==============================================\n";
	cout << "\t[1] Show Client List\n";
	cout << "\t[2] Add New Client\n";
	cout << "\t[3] Delete Client\n";
	cout << "\t[4] Update Client\n";
	cout << "\t[5] Find Client\n";
	cout << "\t[6] Exit\n";
	cout << "==============================================\n";

	PerformMainMenuOption((enMainMenuOption)ReadMainMenuOption());
}

int main()
{
	ShowMainMenu();
	system("pause>0");
	return 0; 
}