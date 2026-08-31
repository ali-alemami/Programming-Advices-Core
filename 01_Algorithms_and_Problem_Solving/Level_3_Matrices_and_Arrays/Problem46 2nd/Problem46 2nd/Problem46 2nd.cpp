#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct sClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	float AccountBalance = 0;
};

vector <string> Split(string S1, string Delim)
{
	vector <string> vString;
	short pos = 0;
	string S2 = "";

	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		S2 = S1.substr(0, pos);

		if (S2 != "")
		{
			vString.push_back(S2);
		}

		S1.erase(0, pos + Delim.length());
	}

	if (S1 != "")
	{
		vString.push_back(S1);
	}

	return vString;
}

sClient ConvertLineToRecord(string S1, string Delim = "#//#")
{
	sClient Client;
	vector <string> vString = Split(S1, Delim);

	Client.AccountNumber = vString[0];
	Client.PinCode = vString[1];
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.AccountBalance = stof(vString[4]);

	return Client;
}

void PrintClient(sClient Client)
{
	cout << "\nAccount Number  : " << Client.AccountNumber << endl;
	cout << "Pin Code        : " << Client.PinCode << endl;
	cout << "Name            : " << Client.Name << endl;
	cout << "Phone           : " << Client.Phone << endl;
	cout << "Account Balance : " << Client.AccountBalance << endl;
}

int main()
{
	string stLine = "A150#//#1234#//#Mohammad abu hadhoud#//#07999#//#5270.000000";
	cout << "\nLine Record is:\n";
	cout << stLine << endl;

	cout << "\n\nThe following is the extracted client record:\n\n";

	sClient Client = ConvertLineToRecord(stLine);

	PrintClient(Client);

	system("pause>0");
}