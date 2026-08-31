#include <iostream>
#include <string>

using namespace std;

struct stBankUserInfo
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string PhoneNumber = "";
	float AccountBalance = 0;
}; 

stBankUserInfo ReadBankUserInfo()
{
	stBankUserInfo BankUserInfo;

	cout << "\nEnter Client Data:\n\n";

	cout << "Enter Account Number? ";
	cin >> BankUserInfo.AccountNumber;

	cout << "Enter PinCode? ";
	cin >> BankUserInfo.PinCode;

	cout << "Enter Name? ";

	getline(cin.ignore(), BankUserInfo.Name);

	cout << "Enter Phone? ";
	cin >> BankUserInfo.PhoneNumber;

	cout << "Enter Account Balance? ";
	cin >> BankUserInfo.AccountBalance;

	return BankUserInfo;
}

string StructToLine(stBankUserInfo BankInfo, string Delim)
{
	string S1 = "";

	S1 += BankInfo.AccountNumber + Delim +
		  BankInfo.PinCode + Delim +
		  BankInfo.Name + Delim +
		  BankInfo.PhoneNumber + Delim +
		  to_string(BankInfo.AccountBalance);

	return S1;
}

int main()
{
	stBankUserInfo BankUserInfo;

	BankUserInfo = ReadBankUserInfo();

	string S1 = StructToLine(BankUserInfo, "#//#");

	cout << S1 << endl;

	system("pause>0");
}