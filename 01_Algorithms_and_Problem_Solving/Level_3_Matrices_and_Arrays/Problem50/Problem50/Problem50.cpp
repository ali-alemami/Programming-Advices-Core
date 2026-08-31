#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

const string File = "Clients.txt";

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	float AccountBalance;
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

sClient ConvertLineToRecord(string Line)
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
			vClients.push_back(ConvertLineToRecord(Line));
		}
		MyFile.close();
	}
	return vClients;
}

vector <sClient> vClients = SaveFileInVector(File);

string ReadAccountNumber()
{
	string AccountNumber = "";
	cout << "Enter Account Number? ";
	cin >> AccountNumber;
	return AccountNumber;
}

bool FindClientByAccountNumber(string AccountNumber, sClient& Client)
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

void PrintRecord(sClient Client)
{
	cout << "Accout Number  : " << Client.AccountNumber << endl;
	cout << "Pin Code       : " << Client.PinCode << "\n";
	cout << "Name           : " << Client.Name << "\n";
	cout << "Phone          : " << Client.Phone << "\n";
	cout << "Account Balance: " << Client.AccountBalance << "\n";
}

void DeleteTheClient(sClient Client, string AccountNumber)
{
	vector <sClient>::iterator iter = vClients.begin();

	for (sClient& C : vClients)
	{
		if (C.AccountNumber == Client.AccountNumber)
		{
			vClients.erase(iter);
			break;
		}
		iter++;
	}
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

void SaveRecordToFile(string FileName)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		for (sClient& C : vClients)
		{
			MyFile << ConvertRecordToLine(C) << endl;
		}
		MyFile.close();
	}
}

void DeleteClientByAccountNumber()
{
	string AccountNumber = ReadAccountNumber();
	sClient Client;

	if (!FindClientByAccountNumber(AccountNumber, Client))
	{
		cout << "\nclient with account number (" << AccountNumber << ") not found!\n\n";
	}
	else
	{
		cout << "\nthe following are the client details:\n\n";
		PrintRecord(Client);

		char Answer = 'n';
		cout << "\nare you sure you want to delete this client? y/n? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			DeleteTheClient(Client, AccountNumber);
			SaveRecordToFile(File);
			cout << "\n\nClient Deleted Successfully.\n\n";
		}
	}
}

int main()
{
	DeleteClientByAccountNumber();

	system("pause>0");
}