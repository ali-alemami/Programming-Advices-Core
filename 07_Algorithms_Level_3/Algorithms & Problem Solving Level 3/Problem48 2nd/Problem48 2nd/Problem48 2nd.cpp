#include <iostream>
#include <fstream>
#include <string>
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

vector <string> Split(string Line, string Seperator = "#//#")
{
	vector <string> vString;
	short pos = 0;
	string S1 = "";

	while ((pos = Line.find(Seperator)) != std::string::npos)
	{
		S1 = Line.substr(0, pos);

		if (S1 != "")
		{
			vString.push_back(S1);
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

void PrintRecord(sClient Client)
{
	cout << "| " << setw(17) << left << Client.AccountNumber;
	cout << "| " << setw(11) << left << Client.PinCode;
	cout << "| " << setw(38) << left << Client.Name;
	cout << "| " << setw(15) << left << Client.Phone;
	cout << "| " << setw(15) << left << Client.AccountBalance << endl;
}

vector <sClient> SaveFileToVector(string FileName)
{
	vector <sClient> vClient;
	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line = "";

		while (getline(MyFile, Line))
		{
			vClient.push_back(ConvertLineToRecord(Line));
		}
		MyFile.close();
	}
	return vClient;
}

void PrintTable()
{
	vector <sClient> vClient = SaveFileToVector(File);

	cout << "\t\t\t\t\tClient List (" << vClient.size() << ") Client(s).\n\n";

	cout << "________________________________________________________________________________________________________________________\n\n";
	cout << "| Account Number   | Pin Code   | Client Name\t\t\t\t| Phone\t\t | Balance\n\n";
	cout << "________________________________________________________________________________________________________________________\n\n";

	for (sClient Record : vClient)
	{
		PrintRecord(Record);
	}
	cout << "\n\n________________________________________________________________________________________________________________________\n\n";
}

int main()
{
	PrintTable();

	system("pause>0");
}