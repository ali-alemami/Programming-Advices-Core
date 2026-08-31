#include <iostream>
#include <string>

using namespace std;

struct sClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	float AcoountBalance = 0;
};

sClient ConvertLineDataToRecord(string LineData, string Delim = "#//#")
{
	sClient Client;
	short pos = 0;

	pos = LineData.find(Delim);
	Client.AccountNumber = LineData.substr(0, pos);
	LineData.erase(0, pos + Delim.length());

	pos = LineData.find(Delim);
	Client.PinCode = LineData.substr(0, pos);
	LineData.erase(0, pos + Delim.length());

	pos = LineData.find(Delim);
	Client.Name = LineData.substr(0, pos);
	LineData.erase(0, pos + Delim.length());

	pos = LineData.find(Delim);;
	Client.Phone = LineData.substr(0, pos);
	LineData.erase(0, pos + Delim.length());

	pos = LineData.find(Delim);
	Client.AcoountBalance = stof(LineData.substr(0, pos));
	LineData.erase(0, pos + Delim.length());

	return Client;
}

void PrintsClient(sClient Client)
{
	cout << "\nAccount Number  : " << Client.AccountNumber << endl;
	cout << "Pin Code        : " << Client.PinCode << endl;
	cout << "Name            : " << Client.Name << endl;
	cout << "Phone           : " << Client.Phone << endl;
	cout << "Account Balance : " << Client.AcoountBalance << endl;
}

int main()
{
	string LineData = "A150#//#1234#//#Mohammad abu hadhoud#//#07999#//#5270.000000";

	cout << "\nLine Record is:\n";
	cout << LineData << endl;

	cout << "\n\nThe following is the extracted client record:\n\n";

	sClient Client;
	
	Client = ConvertLineDataToRecord(LineData);

	PrintsClient(Client);

	system("pause>0");
}