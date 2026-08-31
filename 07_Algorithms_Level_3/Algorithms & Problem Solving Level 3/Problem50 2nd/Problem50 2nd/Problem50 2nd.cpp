//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//const string File = "Clients.txt";
//
//struct sClient
//{
//	string AccountNumber;
//	string PinCode;
//	string Name;
//	string Phone;
//	float AccountBalance = 0;
//	bool SetToDelete = false;
//};
//
//vector <string> SplitString(string Line, string Seperator = "#//#")
//{
//	vector <string> vString;
//
//	short pos = 0;
//	string sword = "";
//
//	while ((pos = Line.find(Seperator)) != std::string::npos)
//	{
//		sword = Line.substr(0, pos);
//
//		if (sword != "")
//		{
//			vString.push_back(sword);
//		}
//		Line.erase(0, pos + Seperator.length());
//	}
//	if (Line != "")
//	{
//		vString.push_back(Line);
//	}
//	return vString;
//}
//
//sClient ConvertLineToRecord(string Line)
//{
//	vector <string> vString = SplitString(Line);
//	sClient Client;
//
//	Client.AccountNumber = vString[0];
//	Client.PinCode = vString[1];
//	Client.Name = vString[2];
//	Client.Phone = vString[3];
//	Client.AccountBalance = stof(vString[4]);
//
//	return Client;
//}
//
//vector <sClient> SaveFileInVector(string FileName)
//{
//	vector <sClient> vClients;
//
//	fstream MyFile;
//
//	MyFile.open(FileName, ios::in);
//
//	if (MyFile.is_open())
//	{
//		string Line = "";
//
//		while (getline(MyFile, Line))
//		{
//			vClients.push_back(ConvertLineToRecord(Line));
//		}
//		MyFile.close();
//	}
//	return vClients;
//}
//
//string ReadAccountNumber()
//{
//	string AccountNumber = "";
//	cout << "Enter Account Number? ";
//	cin >> AccountNumber;
//	return AccountNumber;
//}
//
//bool FindClientByAccountNumber(vector <sClient> vClients, sClient& Client, string AccountNumber)
//{
//	for (sClient C : vClients)
//	{
//		if (C.AccountNumber == AccountNumber)
//		{
//			Client = C;
//			return true;
//		}
//	}
//	return false;
//}
//
//bool MarkClientForDeleteByAccountNumber(vector <sClient>& vClients, string AccountNumber)
//{
//	for (sClient& C : vClients)
//	{
//		if (C.AccountNumber == AccountNumber)
//		{
//			C.SetToDelete = true;
//			return true;
//		}
//	}
//	return false;
//}
//
//string ConvertRecordToFile(sClient Client, string Seperator = "#//#")
//{
//	string Line = "";
//	Line += Client.AccountNumber + Seperator;
//	Line += Client.PinCode + Seperator;
//	Line += Client.Name + Seperator;
//	Line += Client.Phone + Seperator;
//	Line += to_string(Client.AccountBalance);
//
//	return Line;
//}
//
//void SaveClientsDataToFile(string FileName, vector <sClient> vClients)
//{
//	fstream MyFile;
//	MyFile.open(FileName, ios::out);
//
//	if (MyFile.is_open())
//	{
//		for (sClient C : vClients)
//		{
//			if (C.SetToDelete == false)
//			{
//				MyFile << ConvertRecordToFile(C) << endl;
//			}
//		}
//	}
//	MyFile.close();
//}
//
//void PrintClient(sClient Client)
//{
//	cout << "Account Number : " << Client.AccountNumber << endl;
//	cout << "Pin Code       : " << Client.PinCode << endl;
//	cout << "Name           : " << Client.Name << endl;
//	cout << "Phone          : " << Client.Phone << endl;
//	cout << "Account Balance: " << Client.AccountBalance << endl;
//}
//
//bool DeleteClientByAccountNumber(vector <sClient> vClients, string AccountNumber)
//{
//	sClient Client;
//	char Answer = 'n';
//
//	if (FindClientByAccountNumber(vClients, Client, AccountNumber))
//	{
//		PrintClient(Client);
//
//		cout << "\nAre you sure you want to delete this client? (y/n)? ";
//		cin >> Answer;
//
//		if (toupper(Answer) == 'Y')
//		{
//			MarkClientForDeleteByAccountNumber(vClients, AccountNumber);
//			SaveClientsDataToFile(File, vClients);
//
//			vClients = SaveFileInVector(File);
//
//			cout << "Client Deleted Successfully.\n\n";
//			return true;
//		}
//	}
//	else
//	{
//		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n\n";
//		return false;
//	}
//}
//
//int main()
//{
//	vector <sClient> vClients = SaveFileInVector(File);
//	string AccountNumber = ReadAccountNumber();
//
//	DeleteClientByAccountNumber(vClients, AccountNumber);
//
//	system("pause>0");
//}

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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

string ReadAccountNumber()
{
	string AccoutNumber = "";
	cout << "Enter Accout Number? ";
	cin >> AccoutNumber;
	return AccoutNumber;
}

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

void PrintClient(sClient Client)
{
	cout << "\nThe following are the client details:\n";

	cout << "Accout Number   : " << Client.AccountNumber << endl;
	cout << "Pin Code        : " << Client.PinCode << endl;
	cout << "Name            : " << Client.Name << endl;
	cout << "Phone           : " << Client.Phone << endl;
	cout << "Accout Balance  : " << Client.AccountBalance << endl;
}

bool FindClientByAccoutNumber(vector <sClient> vClients, sClient& Client, string AccoutNumber)
{
	for (sClient C : vClients)
	{
		if (C.AccountNumber == AccoutNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

bool MarkClientForDeletion(vector <sClient>& vClients, string AccoutNumber)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccoutNumber)
		{
			C.SetToDelete = true;
			return true;
		}
	}
	return false;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{ 
	string stClientRecord = "";
	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);
	return stClientRecord;
}

void SaveClientsDataToFile(string FileName, vector <sClient> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		for (sClient C : vClients)
		{
			if (C.SetToDelete == false)
			{
				MyFile << ConvertRecordToLine(C) << endl;
			}
		}
		MyFile.close();
	}
}

bool DeleteClientByAccountNumber(vector <sClient> vClients, string AccountNumber)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccoutNumber(vClients, Client, AccountNumber))
	{
		PrintClient(Client);
		
		cout << "\nAre you sure you want to delete this client? y/n? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			MarkClientForDeletion(vClients, AccountNumber);
			SaveClientsDataToFile(ClientsFile, vClients);

			vClients = SaveFileInVector(ClientsFile);
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

int main()
{
	vector <sClient> vClients = SaveFileInVector(ClientsFile);
	string AccoutNumber = ReadAccountNumber();

	DeleteClientByAccountNumber(vClients, AccoutNumber);

	system("pause>0");
}