#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;

class clsClientListScreen : protected clsScreen
{

private:

	static void _PrintClientRecoredLine(clsBankClient Client)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(25) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(12) << left << Client.AccountBalance;
	}

public:

	static void ShowClientList()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pClientList))
		{
			return;
		}

		vector <clsBankClient> vClients = clsBankClient::GetClientList();

		string Title = "\t  Client List Screen";
		string SubTitle = "\t   (" + to_string(vClients.size()) + ") Client(s).";

		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << "\t___________________________________________________";
		cout << "__________________________________________________\n\n";


		cout << setw(8) << left << "" << "| " << left << setw(15) << "Account Number";
		cout << "| " << setw(25) << left << "Client Name";
		cout << "| " << setw(12) << left << "Phone";
		cout << "| " << setw(20) << left << "Email";
		cout << "| " << setw(10) << left << "Pin Code";
		cout << "| " << setw(12) << left << "Balance";

		cout << "\n\t___________________________________________________";
		cout << "__________________________________________________\n\n";

		if (vClients.size() == 0)
		{
			cout << "\n\n\t\t\t\t\tThere are no clients available in the system!\n\n";
		}
		else
		{
			for (clsBankClient Client : vClients)
			{
				_PrintClientRecoredLine(Client);
				cout << endl;
			}
		}

		cout << "\t___________________________________________________";
		cout << "__________________________________________________";
	}
};