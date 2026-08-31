#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "MyFile.txt";

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	float AccountBalance;
};

vector <string> Split(string Line, string Delim = "#//#")
{
	vector <string> vString;
	short pos = 0;
	string S1;

	while ((pos = Line.find(Delim)) != std::string::npos)
	{
		S1 = Line.substr(0, pos);

		if (S1 != "")
		{
			vString.push_back(S1);
		}

		Line.erase(0, pos + Delim.length());
	}

	if (Line != "")
	{
		vString.push_back(Line);
	}

	return vString;
}

sClient SaveLineToRecord(string Line)
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

string t(short Number)
{
	string t = "";

	for (short i = 0; i < Number; ++i)
	{
		t += "\t";
	}
	return t;
}

void PrintHeader(short Number)
{
	cout << t(5) << "Client List (" << Number << ") Client(s).";

	cout << "\n\n________________________________________________________________________________________________________________________\n\n";
	cout << "| Account Number" << t(1) << "| Pin Code" << t(1) << "| Client Name" << t(3) << "| Phone" << t(3) << "| Balance";
	cout << "\n\n________________________________________________________________________________________________________________________\n\n";
}

void PrintClientInfo(sClient Client)
{
	cout << "|" << setw(5) << Client.AccountNumber
		<< t(3) << "|" << setw(5) << Client.PinCode
		<< t(2) << "|" << setw(18) << Client.Name
		<< t(2) << "|" << setw(10) << Client.Phone
		<< t(2) << "|" << setw(7) << Client.AccountBalance
		<< endl;
}

void PrintTableContent(string FileName)
{
	fstream MyFile;
	int Counter = 0;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line = "";

		while (getline(MyFile, Line))
		{
			PrintClientInfo(SaveLineToRecord(Line));
		}
		MyFile.close();
	}
}

void PrintTable()
{
	PrintHeader(3);
	PrintTableContent(ClientsFileName);
}

int main()
{
	PrintTable();

	system("pause>0");
}