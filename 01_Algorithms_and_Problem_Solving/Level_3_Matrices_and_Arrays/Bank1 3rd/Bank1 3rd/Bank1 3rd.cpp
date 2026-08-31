#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>


using namespace std;

const string ClientsFileName = "Clients.txt";

void ShowMainMenue();

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	float AccountBalance = 0;
	bool SetToDelete = false;
};

enum enMainMenuOptions
{
	eListClients = 1, eAddNewClient = 2,
	eDeleteClient = 3, eUpdateClient = 4,
	eFindClient = 5, eExit = 6
};

vector <string> SplitString(string S1, string Delim)
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

sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector <string> vString = SplitString(Line, Seperator);

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

void PrintClientRecordLine(sClient Client)
{
	cout << "| " << left << setw(15) << Client.AccountNumber;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(40) << Client.Name;
	cout << "| " << left << setw(12) << Client.Phone;
	cout << "| " << left << setw(12) << Client.AccountBalance;
}

void ShowClientListScreen()
{
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	cout << "\n\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n\n___________________________________________________________________\n\n";
	cout << left << setw(15) << "| Account Number";
	cout << left << setw(10) << "| Pin Code";
	cout << left << setw(40) << "| Name";
	cout << left << setw(12) << "| Phone";
	cout << left << setw(12) << "| Balance";
	cout << "\n\n___________________________________________________________________\n\n";

	if (vClients.size() == 0)
	{
		cout << "\t\t\t\tNo Clients Avaialable in the system!";
	}
	else
	{
		for (sClient C : vClients)
		{
			PrintClientRecordLine(C);
			cout << endl;
		}
	}
	cout << "\n\n___________________________________________________________________\n\n";
}

bool ClientExistsByAccountNumber(string AccountNumber, string ClientsFileName)
{
	vector <sClient> vClients;

	fstream MyFile;
	MyFile.open(ClientsFileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		sClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			if (AccountNumber == Client.AccountNumber)
			{
				return true;
			}
		}
		MyFile.close();
	}
	return false;
}

sClient EnterClientInfo(sClient& Client)
{
	cout << "Enter Pin Code? ";
	getline(cin, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter Account Balance? ";
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

void SaveClientsDataToFile(string FileName, vector <sClient> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		string Line = "";

		for (sClient C : vClients)
		{
			if (C.SetToDelete == false)
			{
				Line = ConvertRecordToLine(C);
				MyFile << Line << endl;
			}
		}
		MyFile.close();
	}
}

sClient ReadNewClient()
{
	sClient Client;
	cout << "Enter Account Number? ";
	getline(cin >> ws, Client.AccountNumber);

	while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
	{
		cout << "Client With [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
		getline(cin >> ws, Client.AccountNumber);
	}

	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;

	return Client;
}

void AddDataLineToFile(string FileName, string DataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << DataLine << endl;
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
	char Answer = 'y';
	do
	{
		cout << "Adding New Client:\n\n";

		AddNewClient();
		cout << "Client Added Successfully, Do you want to add another clients? Y/N? ";
		cin >> Answer;
	} while (Answer == 'y' || Answer == 'Y');
}

void ShowAddNewClientsScreen()
{
	cout << "\n\n------------------------------\n\n";
	cout << "\t\tAdd New Clients Screen";
	cout << "\n\n------------------------------\n\n";

	AddNewClients();
}

string ReadClientAccountNumber()
{
	string AccountNumber = "";
	cout << "\nPlease enter Account Number? ";
	cin >> AccountNumber;
	return AccountNumber;
}

bool FindClientByAccountNumber(string AccountNubmer, vector <sClient> vClients, sClient& Client)
{
	for (sClient C : vClients)
	{
		if (C.AccountNumber == AccountNubmer)
		{
			Client = C;
			return true;
		}
	}
	return false;
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

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
	sClient Client;
	char Answer = 'y';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientRecordLine(Client);

		cout << "Are you sure you want to delete this client? Y/N? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			MarkClientForDeletion(AccountNumber, vClients);
			SaveClientsDataToFile(ClientsFileName, vClients);

			//Refresh Clients
			vClients = LoadClientsDataFromFile(ClientsFileName);

			cout << "\n\nClient Deleted Successfully.";
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
	cout << "\n\n------------------------------\n\n";
	cout << "\t\tDelete Client Screen";
	cout << "\n\n------------------------------\n\n";

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
	getline(cin, Client.Phone);

	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;
	return Client;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient> vClients)
{
	sClient Client;
	char Answer = 'y';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientRecordLine(Client);

		cout << "Are you sure you want to update this client? Y/N? ";
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

			cout << "\n\nClient Updated Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}

}

void ShowUpdateClientScreen()
{
	cout << "\n\n------------------------------\n\n";
	cout << "\t\tUpdate Client Screen";
	cout << "\n\n------------------------------\n\n";

	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowFindClientScreen()
{
	cout << "\n\n------------------------------\n\n";
	cout << "\t\tFind Client Screen";
	cout << "\n\n------------------------------\n\n";

	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	sClient Client;

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientRecordLine(Client);
	}
	else
	{
		cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
	}
}

void ShowEndScreen()
{
	cout << "\n\n------------------------------\n\n";
	cout << "\t\tProgram Ends";
	cout << "\n\n------------------------------\n\n";
}

short ReadMainMenuOption()
{
	cout << "Choose what do you want to do? [1 to 6]? ";
	short Choice = 0;
	cin >> Choice;

	return Choice;
}

void GoBackToMainMenu()
{
	cout << "\n\nPress any key to go back to Main Menue...";
	system("pause>0");
	ShowMainMenue();
}

void PerformMainMenuOptions(enMainMenuOptions MainMenuOptions)
{
	switch (MainMenuOptions)
	{
	case eListClients:
		system("cls");
		ShowClientListScreen();
		GoBackToMainMenu();
		break;

	case eAddNewClient:
		system("cls");
		ShowAddNewClientsScreen();
		GoBackToMainMenu();
		break;

	case eDeleteClient:
		system("cls");
		ShowDeleteClientScreen();
		GoBackToMainMenu();
		break;

	case eUpdateClient:
		system("cls");
		ShowUpdateClientScreen();
		GoBackToMainMenu();
		break;

	case eFindClient:
		system("cls");
		ShowFindClientScreen();
		GoBackToMainMenu();
		break;

	case eExit:
		system("cls");
		ShowEndScreen();
		break;
	}
}

void ShowMainMenue()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t\tMain Menue Screen\n";
	cout << "===========================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Exit.\n";
	cout << "===========================================\n";
	PerformMainMenuOptions((enMainMenuOptions)ReadMainMenuOption());
}

int main()
{
	ShowMainMenue();
	system("pause>0");
	return 0;
}