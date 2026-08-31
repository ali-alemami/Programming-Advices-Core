#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsUtil.h"

using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{
	
private:

	static void _PrintClientBalanceLine(clsBankClient Client)
	{
		cout << setw(24) << left << "" << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(30) << Client.FullName();
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}

public:

	static void ShowTotalBalances()
	{
		vector < clsBankClient> vClients = clsBankClient::GetClientList();

		string Title = "\t Total Balances Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << "\n\t\t_____________________________________";
		cout << "_______________________________________\n\n";


		cout << setw(24) << left << "" << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(30) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";

		cout << "\n\t\t_____________________________________";
		cout << "_______________________________________\n\n";

		double TotalBalances = clsBankClient::GetTotalBalances();

		if (vClients.size() == 0)
		{
			cout << "\n\n\t\t\t\tThere are no clients available in the system!\n\n";
		}
		else
		{
			for (clsBankClient Client : vClients)
			{
				_PrintClientBalanceLine(Client);
				cout << endl;
			}
		}
		cout << "\n\t\t_____________________________________";
		cout << "_______________________________________\n\n";

		cout << "\t\t\t\t\tTotal Balances = " << TotalBalances << endl;
		cout << "\t\t\t\t\t" << clsUtil::NumberToText(TotalBalances) << endl;
	}
};

