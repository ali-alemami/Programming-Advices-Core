#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const string ClientsFile = "Clients.txt";

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	float AccoutBalance = 0;
	bool SetToDelete = false;
	bool SetToUpdate = false;
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

sClient ConvertStringToRecord(string Line)
{
	vector <string> vString = SplitString(Line);
	sClient Client;

	Client.AccountNumber = vString[0];
	Client.PinCode = vString[1];
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.AccoutBalance = stof(vString[4]);

	return Client;
}

vector <sClient> SaveFileInVector(string FileName)
{
	vector <sClient> vClients;

	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line = "";
		while (getline(MyFile, Line))
		{
			vClients.push_back(ConvertStringToRecord(Line));
		}
		MyFile.close();
	}
	return vClients;
}

bool FindClientByAccountNumber(vector <sClient> vClients, sClient& Client, string AccountNumber)
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

void PrintClient(sClient Client)
{
	cout << "\n\nThe following are the client details:\n\n";

	cout << "Accout Number  : " << Client.AccountNumber << endl;
	cout << "Pin Code       : " << Client.PinCode << endl;
	cout << "Name           : " << Client.Name << endl;
	cout << "Phone          : " << Client.Phone << endl;
	cout << "Account Balance: " << Client.AccoutBalance << endl;
}

//bool MarkClientForUpdate(vector <sClient>& vClients, string AccountNumber)
//{
//	for (sClient& C : vClients)
//	{
//		if (C.AccountNumber == AccountNumber)
//		{
//			C.SetToUpdate = true;
//			return true;
//		}
//	}
//	return false;
//}

sClient EnterClientInfo(sClient& C)
{
	cout << "Enter Pin Code? ";
	getline(cin >> ws, C.PinCode);
	cout << "Enter Name? ";
	getline(cin, C.Name);
	cout << "Enter Phone? ";
	getline(cin, C.Phone);
	cout << "Enter Account Balance? ";
	cin >> C.AccoutBalance;

	return C;
}

bool UpdateTheClient(vector <sClient>& vClients, string AccountNumber)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			EnterClientInfo(C);
			return true;
		}
	}
	return false;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
	string Line = "";
	Line += Client.AccountNumber + Seperator;
	Line += Client.PinCode + Seperator;
	Line += Client.Name + Seperator;
	Line += Client.Phone + Seperator;
	Line += to_string(Client.AccoutBalance);

	return Line;
}

void SaveVectorOnFile(string FileName, vector <sClient> vClient)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		for (sClient C : vClient)
		{
			MyFile << ConvertRecordToLine(C) << endl;
		}
	}
}

void UpdateClientByAccountNumber(vector <sClient>& vClients, string AccoutNumber)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(vClients, Client, AccoutNumber))
	{
		PrintClient(Client);

		cout << "\nAre you sure you want to update this client? y/n? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			UpdateTheClient(vClients, AccoutNumber);

			SaveVectorOnFile(ClientsFile, vClients);
			cout << "Client Updated Successfully.\n\n";
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccoutNumber << ") Not Found!\n\n";
	}
}

string ReadAccoutNumber()
{
	string AccountNumber = "";
	cout << "Enter Accout Number? ";
	cin >> AccountNumber;
	return AccountNumber;
}

int main()
{
	vector <sClient> vClients = SaveFileInVector(ClientsFile);
	string AccoutNumber = ReadAccoutNumber();

	UpdateClientByAccountNumber(vClients, AccoutNumber);

	system("pause>0");
}