#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stBankUserInfo
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string PhoneNumber = "";
	int AccountBalance = 0;
};

int ReadNumber()
{
	int Number;
	cout << "How Many Users? ";
	cin >> Number;
	return Number;
}

stBankUserInfo ReadBankUserInfo(stBankUserInfo BankUserInfo)
{

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

string StoreStructInString(stBankUserInfo BankInfo, string Delim)
{
	string S1 = "";
	S1 += BankInfo.AccountNumber + Delim + BankInfo.PinCode +
		Delim + BankInfo.Name + Delim + BankInfo.PhoneNumber +
		Delim + to_string(BankInfo.AccountBalance);

	return S1;
}

vector <stBankUserInfo> StoreSructInVector(vector <stBankUserInfo> vBankInfo, stBankUserInfo BankUserInfo)
{
	vBankInfo.push_back(BankUserInfo);

	return vBankInfo;
}

//void StoreVectorInStruct(vector <stBankUserInfo> vBankInfo,
//	stBankUserInfo BankUserInfo, vector <stBankUserInfo> ::iterator iter)
//{
//
//	for (stBankUserInfo s : vBankInfo)
//	{
//		BankUserInfo = *iter;
//
//		iter++;
//	}
//}

void ReadAllUsers(int Number)
{
	stBankUserInfo BankUserInfo;
	vector <stBankUserInfo> vBankInfo;
	string S1 = "";

	for (int i = 0; i < Number; i++)
	{
		BankUserInfo = ReadBankUserInfo(BankUserInfo);
		StoreSructInVector(vBankInfo, BankUserInfo);

		S1 = StoreStructInString(BankUserInfo, "#//#");
		cout << S1 << endl;
		S1.clear();
	}
}

int main()
{
	ReadAllUsers(ReadNumber());

	system("pause>0");
}