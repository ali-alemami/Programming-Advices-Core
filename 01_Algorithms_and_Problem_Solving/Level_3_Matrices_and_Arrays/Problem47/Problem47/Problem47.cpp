#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	float AccountBalance;
};

sClient ReadClientInfo()
{
	sClient Client;

	cout << "Enter Account Number? ";
	getline(cin >> ws, Client.AccountNumber);

	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter Account Balance ? ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
	string S1 = "";

	S1 += Client.AccountNumber + Seperator;
	S1 += Client.PinCode + Seperator;
	S1 += Client.Name + Seperator;
	S1 += Client.Phone + Seperator;
	S1 += to_string(Client.AccountBalance);

	return S1;
}

void SaveLineToFile(string S1)
{
	fstream MyFile;

	MyFile.open("MyFile.txt", ios::app);

	if (MyFile.is_open())
	{
		MyFile << S1 << endl;

		MyFile.close();
	}
}

void AddClients()
{
	sClient Client;
	string S1 = "";
	char Another1 = 'Y';

	while (toupper(Another1) == 'Y')
	{
		system("cls");
		cout << "Adding New Client:\n\n";

		Client = ReadClientInfo();
		S1 = ConvertRecordToLine(Client);
		SaveLineToFile(S1);

		cout << "\n\nClient Added Successfully, do you want to add more clients? ";
		cin >> Another1;
		cout << endl;
	}
}

int main()
{
	AddClients();

	system("pause>0");
}