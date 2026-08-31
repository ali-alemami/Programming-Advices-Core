#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>

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

vector <string> Split(string Line, string Seperator = "#//#")
{
	vector <string> vString;

	short pos = 0;
	string sWord = "";

	while ((pos = Line.find(Seperator)) != std::string::npos)
	{
		sWord = Line.substr(0, pos);

		if (sWord != "")
		{
			vString.push_back(sWord);
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
	vector <string> vString = Split(Line);
	sClient Client;

	Client.AccountNumber = vString[0];
	Client.PinCode = vString[1];
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.AccountBalance = stof(vString[4]);

	return Client;
}

vector <sClient> SaveFileToVector(string FileName)
{
	vector <sClient> vClient;

	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;

		while (getline(MyFile, Line))
		{
			vClient.push_back(ConvertLineToRecord(Line));
		}
		MyFile.close();
	}
	return vClient;
}

void PrintRecord(sClient Client)
{
	cout << "Account Number : " << Client.AccountNumber << endl;
	cout << "Pin Code       : " << Client.PinCode << endl;
	cout << "Name           : " << Client.Name << endl;
	cout << "Phone          : " << Client.Phone << endl;
	cout << "Account Balance: " << Client.AccountBalance << endl;
}

bool FindClientByAccountNumber(string AccountNumber, sClient& Client)
{
	vector <sClient> vClients = SaveFileToVector(File);

	for (sClient S : vClients)
	{
		if (S.AccountNumber == AccountNumber)
		{
			Client = S;
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

int main()
{
	string AccountNumber = ReadAccountNumber();
	sClient Client;

	if (FindClientByAccountNumber(AccountNumber, Client))
	{
		cout << "\nThe following are the client details:\n\n";
		PrintRecord(Client);
	}
	else
	{
		cout << "\nClient With Accout Number " << AccountNumber << " NOT Found!\n";
	}

	system("pause>0");
}