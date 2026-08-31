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

short SearchForAccountNumber(vector <sClient> vClient, string AccountNumber)
{
	vClient = SaveFileToVector(File);

	short Number = 0;

	for (sClient Client : vClient)
	{
		++Number;

		if (AccountNumber == Client.AccountNumber)
		{
			return Number;
		}
	}
	return 0;
}

void PrintRecord(sClient Client)
{
	cout << "Account Number : " << Client.AccountNumber << endl;
	cout << "Pin Code       : " << Client.PinCode << endl;
	cout << "Name           : " << Client.Name << endl;
	cout << "Phone          : " << Client.Phone << endl;
	cout << "Account Balance: " << Client.AccountBalance << endl;
}

string ReadAccountNumber()
{
	string AccoutNumber = "";

	cout << "Enter Account Number? ";
	cin >> AccoutNumber;

	return AccoutNumber;
}

void PrintClientByAccountNumber()
{
	string AccountNumber = ReadAccountNumber();

	vector <sClient> vClient = SaveFileToVector(File);
	short Number = 0;

	if ((Number = SearchForAccountNumber(vClient, AccountNumber)))
	{
		cout << "\nThe following are the client details:\n\n";

		PrintRecord(vClient[Number - 1]);
	}
	else
	{
		cout << "\nClient With Account Number (" << AccountNumber << ") NOT Found!\n\n";
	}
}

int main()
{
	PrintClientByAccountNumber();

	system("pause>0");
}