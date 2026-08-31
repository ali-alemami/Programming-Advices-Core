#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

const string ClientsFile = "Clients.txt";

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	float AccountBalance = 0;
	bool SetToDelete = false;
};

vector <string> SplitString(string Line, string Seperator = "#//#")
{
	vector <string> vString;

	short pos = 0;
	string sword = "";

	while ((pos = Line.find(Seperator)) != std::string::npos)
	{
		sword = Line.substr(0, pos);
		if (sword != "")
		{
			vString.push_back(sword);
		}
		Line.erase(0, pos + Seperator.length());
	}
	if (Line != "")
	{
		vString.push_back(Line);
	}
	return vString;
}

sClient ConverLineToRecord(string Line)
{
	vector <string> vString = SplitString(Line);
	sClient Client;

	Client.AccountNumber = vString[0];
	Client.PinCode = vString[1];
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.AccountBalance = stof(vString[4]);

	return Client;
}

vector <sClient> LoadClientsFromFile(string FileName)
{
	vector <sClient> vClients;

	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line = "";

		while (getline(MyFile, Line))
		{
			vClients.push_back(ConverLineToRecord(Line));
		}
		MyFile.close();
	}
	return vClients;
}

void ShowHeaderOfClientListScreen(vector <sClient> vClients)
{
	cout << "\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n\n______________________________________________________________________________________________________________\n\n";
	cout << "| " << setw(15) << left << "Accout Number";
	cout << "| " << setw(10) << left << "Pin Code";
	cout << "| " << setw(40) << left << "Client Name";
	cout << "| " << setw(14) << left << "Phone";
	cout << "| " << setw(9) << left << "Balance";
	cout << "\n\n______________________________________________________________________________________________________________\n\n";
}

void ShowContentOfClientListScreen(vector <sClient> vClients)
{
	for (sClient Client : vClients)
	{
		cout << "| " << setw(15) << left << Client.AccountNumber;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(40) << left << Client.Name;
		cout << "| " << setw(14) << left << Client.Phone;
		cout << "| " << setw(9) << left << Client.AccountBalance;
		cout << endl;
	}
}

void ShowClientListScreen(vector <sClient> vClients)
{
	system("cls");
	ShowHeaderOfClientListScreen(vClients);
	ShowContentOfClientListScreen(vClients);
	cout << "\n\n______________________________________________________________________________________________________________\n\n\n\n";

	cout << "Press any key to go back to the main menu...";
	system("pause>0");
}
/// <summary>
/// 
/// </summary>
void ShowHeaderOfAddNewClientScreen()
{
	cout << "\n\n----------------------------------------\n\n";
	cout << "         Add New Clients Screen         ";
	cout << "\n\n----------------------------------------\n\n";
}

sClient AddNewClient(vector <sClient> vClients)
{
	sClient Client;
	bool Equal = false;

	cout << "Enter Account Number? ";
	do
	{
		getline(cin >> ws, Client.AccountNumber);

		for (sClient& C : vClients)
		{
			if (Equal = (C.AccountNumber == Client.AccountNumber))
			{
				cout << "Client with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
				break;
			}
		}
	} while (Equal == true);
	
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

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
	string Line = "";
	Line += Client.AccountNumber + Seperator;
	Line += Client.PinCode + Seperator;
	Line += Client.Name + Seperator;
	Line += Client.Phone + Seperator;
	Line += to_string(Client.AccountBalance);
	return Line;
}

void AddClientToFile(string FileName, sClient Client)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << endl << ConvertRecordToLine(Client);
		MyFile.close();
	}
}

void ShowAddNewClientScreen(vector <sClient>& vClients)
{
	char Answer = false;
	do
	{
		system("cls");
		ShowHeaderOfAddNewClientScreen();
		cout << "Adding New Client:\n\n";
		sClient Client = AddNewClient(vClients);
		AddClientToFile(ClientsFile, Client);
		vClients = LoadClientsFromFile(ClientsFile);

		cout << "Client Added Successfully, do you want to add more clients? Y/N? ";
		cin >> Answer;
	} while (tolower(Answer) == 'y');

	cout << "\n\n\nPress any key to go back to the main menu...";
	system("pause>0");
}
/// <summary>
/// 
/// </summary>
/// <returns></returns>
void ShowHeaderOfDeleteClientsScreen()
{
	cout << "\n\n----------------------------------------\n\n";
	cout << "             Delete Clients Screen    ";
	cout << "\n\n----------------------------------------\n\n";
}

bool FindClientByAccountNumber(vector <sClient> vClients, sClient& Client, string AccountNumber)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

string ReadAccountNumber()
{
	string AccountNumber = "";
	cout << "Enter Account Number? ";
	cin >> AccountNumber;
	return AccountNumber;
}

bool MarkClientForDeletion(vector <sClient>& vClients, string AccountNumber)
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

void SaveVectorInFile(string FileName, vector <sClient> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		for (sClient& C : vClients)
		{
			if (C.SetToDelete == false)
			{
				MyFile << ConvertRecordToLine(C) << endl;
			}
		}
	}
}

void PrintClient(sClient Client)
{
	cout << "\n\nThe following are the client details:\n";
	cout << "----------------------------------------\n";
	cout << "Account Number : " << Client.AccountNumber << "\n";
	cout << "Pin Code       : " << Client.PinCode << "\n";
	cout << "Name           : " << Client.Name << "\n";
	cout << "Phone          : " << Client.Phone << "\n";
	cout << "Account Balance: " << Client.AccountBalance << endl;
	cout << "----------------------------------------\n\n\n";
}

void ShowDeleteClientScreen(vector <sClient>& vClients)
{
	system("cls");

	ShowHeaderOfDeleteClientsScreen();

	sClient Client;
	string AccountNumber = ReadAccountNumber();
	char Answer = 'n';

	if (!FindClientByAccountNumber(vClients, Client, AccountNumber))
	{
		cout << "Client with Account Number (" << AccountNumber << ") Not Found!\n\n";
		cout << "Press any key to go ack to the main menu...";
		system("pause>0");
	}
	else
	{
		PrintClient(Client);

		cout << "Are you sure you want to delete this client? Y/N? ";
		cin >> Answer;
		
		if (tolower(Answer) == 'y')
		{
			MarkClientForDeletion(vClients, AccountNumber);
			SaveVectorInFile(ClientsFile, vClients);

			vClients = LoadClientsFromFile(ClientsFile);

			cout << "\n\n\nClient Deleted Successfully.\n\n";
			cout << "Press any key to go ack to the main menu...";
			system("pause>0");
		}
		else
		{
			cout << "\n\n\nClient was Not Deleted.\n\n";
			cout << "Press any key to go ack to the main menu...";
			system("pause>0");
		}
	}

}

/// <summary>
/// </summary>
/// <returns></returns>
/// 
void ShowHeaderOfUpdateClientInfoScreen()
{
	cout << "\n\n----------------------------------------\n\n";
	cout << "           Update Client Info Screen    ";
	cout << "\n\n----------------------------------------\n\n";
}

sClient EnterClientInfo(sClient& Client)
{
	cout << "Enter Pin Code? ";
	getline(cin >> ws, Client.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client.Name);
	cout << "Enter Phone? ";
	getline(cin, Client.Phone);
	cout << "Enter Balance? ";
	cin >> Client.AccountBalance;

	return Client;
}

void ShowUpdateClientInfoScreen(vector <sClient>& vClients)
{
	system("cls");

	ShowHeaderOfUpdateClientInfoScreen();

	string AccountNumber = ReadAccountNumber();
	sClient Client;
	char Answer = 'n';

	if (!FindClientByAccountNumber(vClients, Client, AccountNumber))
	{
		cout << "Client with Account Number (" << AccountNumber << ") Not Found!\n\n";
		cout << "Press any key to go ack to the main menu...";
		system("pause>0");
	}
	else
	{
		PrintClient(Client);

		cout << "Are you sure you want to Update this client? Y/N? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			for (sClient& C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					EnterClientInfo(C);
					SaveVectorInFile(ClientsFile, vClients);
					cout << "\n\n\nClient Updated Successfully.\n\n\n";
					cout << "Press any key to go ack to the main menu...";
					system("pause>0");
				}
			}
		}
		else
		{
			cout << "\n\n\nClient was Not Updated.\n\n";
			cout << "Press any key to go ack to the main menu...";
			system("pause>0");
		}
	}

}

/// <summary>
/// </summary>
/// <returns></returns>
/// 
void ShowHeaderOfFindClientScreen()
{
	cout << "\n\n----------------------------------------\n\n";
	cout << "               Find Client Screen    ";
	cout << "\n\n----------------------------------------\n\n";
}

void ShowFindClientScreen(vector <sClient> vClients)
{
	system("cls");

	ShowHeaderOfFindClientScreen();

	string AccountNumber = ReadAccountNumber();
	sClient Client;

	if (!FindClientByAccountNumber(vClients, Client, AccountNumber))
	{
		cout << "Client with Account Number (" << AccountNumber << ") Not Found!\n\n";
		cout << "Press any key to go ack to the main menu...";
		system("pause>0");
	}
	else
	{
		PrintClient(Client);
		cout << "\n\n\nPress any key to go ack to the main menu...";
		system("pause>0");
	}
}

/// <summary>
/// </summary>
/// <returns></returns>

void ShowMainMenuScreen()
{
	cout << "========================================\n\n";
	cout << "            Main Menu Screen";
	cout << "\n\n========================================\n\n";

	cout << "    [1] Show Client List.\n";
	cout << "    [2] Add New Client.\n";
	cout << "    [3] Delete Client.\n";
	cout << "    [4] Update Client Info.\n";
	cout << "    [5] Find Client.\n";
	cout << "    [6] Exit.\n";
	cout << "\n\n========================================\n\n";
}

void EndProgram()
{
	system("cls");
	cout << "\n\n----------------------------------------\n\n";
	cout << "             Program Ends :0    ";
	cout << "\n\n----------------------------------------\n\n";
	system("pause>0");
}

void MainMenuScreen()
{
	vector <sClient> vClients = LoadClientsFromFile(ClientsFile);

	short Answer = 1;

	while (Answer >= 1 && Answer <= 5)
	{
		system("cls");

		ShowMainMenuScreen();

		cout << "Chose what do you want to do? [1 to 6]? ";
		cin >> Answer;

		switch (Answer)
		{
		case 1:
			ShowClientListScreen(vClients);
			continue;
		case 2:
			ShowAddNewClientScreen(vClients);
			continue;
		case 3:
			ShowDeleteClientScreen(vClients);
			continue;
		case 4:
			ShowUpdateClientInfoScreen(vClients);
			continue;
		case 5:
			ShowFindClientScreen(vClients);
			continue;
		case 6:
			EndProgram();
			break;
		default:
			EndProgram();
			break;
		}
	}
}

int main()
{
	MainMenuScreen();

	system("pause>0");
}