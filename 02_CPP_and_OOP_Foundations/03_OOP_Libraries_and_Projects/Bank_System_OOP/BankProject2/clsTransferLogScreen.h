#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsDate.h"

using namespace std;

class clsTransferLogScreen : protected clsScreen
{
private:

	static void _PrintTranferLogLine(clsBankClient::stTransferLogRecord TransferLogRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << TransferLogRecord.DateTime;
		cout << "| " << setw(10) << left << TransferLogRecord.SourceAccountNumber;
		cout << "| " << setw(10) << left << TransferLogRecord.DestinationAccountNumber;
		cout << "| " << setw(10) << left << TransferLogRecord.Amount;
		cout << "| " << setw(10) << left << TransferLogRecord.SourceAccountBalanceAfter;
		cout << "| " << setw(10) << left << TransferLogRecord.DestinationAccountBalanceAfter;
		cout << "| " << setw(10) << left << TransferLogRecord.UserName;
	}

public:

	static void ShowTransferLogScreen()
	{
		vector <clsBankClient::stTransferLogRecord>
			vTransferLogRecords = clsBankClient::GetTransferLogList();

		string Title = "    Transfer Log List Screen";
		string SubTitle = "\t    (" + to_string(vTransferLogRecords.size()) + ") Record(s).";

		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << "\t___________________________________________________";
		cout << "__________________________________________________\n\n";

		cout << setw(8) << left << "" << "| " << setw(30) << left << "Date/Time";
		cout << "| " << setw(10) << left << "s.Acc";
		cout << "| " << setw(10) << left << "d.Acc";
		cout << "| " << setw(10) << left << "Amount";
		cout << "| " << setw(10) << left << "s.Balance";
		cout << "| " << setw(10) << left << "d.Balance";
		cout << "| " << setw(10) << left << "User";

		cout << "\n\t___________________________________________________";
		cout << "__________________________________________________\n\n";

		if (vTransferLogRecords.size() == 0)
		{
			cout << "\n\n\t\t\t\t\tThere are no Transfer Logs available in the system!\n\n";
		}
		else
		{
			for (clsBankClient::stTransferLogRecord TransferLogRecord : vTransferLogRecords)
			{
				_PrintTranferLogLine(TransferLogRecord);
				cout << endl;
			}
		}
		cout << "\t___________________________________________________";
		cout << "__________________________________________________\n\n";
	}
};

