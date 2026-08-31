#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

void ReadClientInfo(clsBankClient& Client)
{
	cout << "\nEnter FirstName: ";
	Client.FirstName = clsInputValidate::ReadString();

	cout << "\nEnter LastName: ";
	Client.LastName = clsInputValidate::ReadString();

	cout << "\nEnter Email: ";
	Client.Email = clsInputValidate::ReadString();

	cout << "\nEnter Phone: ";
	Client.Phone = clsInputValidate::ReadString();

	cout << "\nEnter PinCode: ";
	Client.PinCode = clsInputValidate::ReadString();

	cout << "\nEnter Account Balance: ";
	Client.AccountBalance = clsInputValidate::ReadFloatNumber();
}

void UpdateClient()
{
	string AccountNumber = "";

	cout << "Enter client Account Number: ";
	AccountNumber = clsInputValidate::ReadString();

	while (!clsBankClient::DoesClientExist(AccountNumber))
	{
		cout << "\nAccount Number is not found, choose another one: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient Client1 = clsBankClient::Find(AccountNumber);

	cout << "\nClient Card:\n";
	Client1.Print();

	cout << "\n\nUpdate Client Info:";
	cout << "\n_____________________\n";

	ReadClientInfo(Client1);

	clsBankClient::enSaveResults SaveResult;
	SaveResult = Client1.Save();

	switch (SaveResult)
	{
	case clsBankClient::svFailedEmptyObject:
		cout << "\nError account was not saved because it's empty";
		break;
	case clsBankClient::svSucceeded:
		cout << "\nAccount Updated Successfully\n";
		Client1.Print();
		break;
	}
}

void AddNewClient()
{
	string AccountNumber = "";

	cout << "\nPlease Enter Account Number: ";
	AccountNumber = clsInputValidate::ReadString();

	while (clsBankClient::DoesClientExist(AccountNumber))
	{
		cout << "\nAccount Number is already used, choose another one: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

	ReadClientInfo(NewClient);

	clsBankClient::enSaveResults SaveResult;
	SaveResult = NewClient.Save();

	switch (SaveResult)
	{
	case clsBankClient::svFailedEmptyObject:

		cout << "\nErroe account was not saved because it's empty";
		break;

	case clsBankClient::svSucceeded:

		cout << "\nAccount Added Successfully\n";
		break;

	case clsBankClient::svFailedAccountNumberExists:

		cout << "\nError account was not saved because account number is used!\n";
		break;
	}
}

int main()
{
	AddNewClient();

	system("pause>0");
	return 0;
}