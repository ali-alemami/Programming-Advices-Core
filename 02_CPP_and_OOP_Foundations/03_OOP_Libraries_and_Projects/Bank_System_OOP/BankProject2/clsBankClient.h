#pragma once

#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include <iomanip>

class clsBankClient : public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2, DeleteMode = 3 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

	bool _MarkedForDeletion = false;

	static clsBankClient _ConvertLineToClientObject(string Line)
	{
		vector <string> vClient = clsString::Split(Line, "#//#");

		return clsBankClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2],
			vClient[3], vClient[4], vClient[5], stof(vClient[6]));
	}

	static string _ConverClientObjectToLine(clsBankClient Client, string Separator = "#//#")
	{
		string DataLine = "";

		DataLine = Client.FirstName + Separator;
		DataLine += Client.LastName + Separator;
		DataLine += Client.Email + Separator;
		DataLine += Client.Phone + Separator;
		DataLine += Client.AccountNumber() + Separator;
		DataLine += Client.PinCode + Separator;
		DataLine += to_string(Client.AccountBalance);

		return DataLine;
	}

	static vector <clsBankClient> _LoadClientsDataFromFile()
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		
		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				vClients.push_back(_ConvertLineToClientObject(Line));
			}
			MyFile.close();
		}
		return vClients;
	}

	static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open())
		{
			string DataLine = "";

			for (clsBankClient Client : vClients)
			{
				if (Client.MarkForDeletion() == false)
				{
					DataLine = _ConverClientObjectToLine(Client);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	
	void _Update()
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if(C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientsDataToFile(vClients);
	}

	void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConverClientObjectToLine(*this));
	}

	string _CreateTransferLogLine(clsBankClient DestinationClient,
		float Amount, string UserName, string Separator = "#//#")
	{
		string TransferLogLine = "";
		TransferLogLine += clsDate::GetSystemDateTimeString() + Separator;
		TransferLogLine += this->AccountNumber() + Separator;
		TransferLogLine += DestinationClient.AccountNumber() + Separator;
		TransferLogLine += to_string(Amount) + Separator;
		TransferLogLine += to_string(this->AccountBalance) + Separator;
		TransferLogLine += to_string(DestinationClient.AccountBalance) + Separator;
		TransferLogLine += UserName;
		return TransferLogLine;
	}

	void _CreateTransferLog(clsBankClient DestinationClient, float Amount, string UserName)
	{
		string Line = _CreateTransferLogLine(DestinationClient, Amount, UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}
	}

	struct stTransferLogRecord;
	static stTransferLogRecord _ConvertLineToTransferLogRecord(string Line)
	{
		stTransferLogRecord TransferRecord;
		vector <string> vTransferLogRecord = clsString::Split(Line, "#//#");

		TransferRecord.DateTime = vTransferLogRecord[0];
		TransferRecord.SourceAccountNumber = vTransferLogRecord[1];
		TransferRecord.DestinationAccountNumber = vTransferLogRecord[2];
		TransferRecord.Amount = stof(vTransferLogRecord[3]);
		TransferRecord.SourceAccountBalanceAfter = stof(vTransferLogRecord[4]);
		TransferRecord.DestinationAccountBalanceAfter = stof(vTransferLogRecord[5]);
		TransferRecord.UserName = vTransferLogRecord[6];
		return TransferRecord;
	}

public:

	struct stTransferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		float Amount;
		float SourceAccountBalanceAfter;
		float DestinationAccountBalanceAfter;
		string UserName;
	};

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber, string PinCode, float AccountBalance)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}

	bool MarkForDeletion()
	{
		return _MarkedForDeletion;
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	_declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	_declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool DoesClientExist(string AccountNumber)
	{
		clsBankClient Client = Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1, svFailedAccountNumberExist = 2 };
	
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsBankClient::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResults::svFailedEmptyObject;
			}
		}

		case clsBankClient::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
		}

		case clsBankClient::AddNewMode:
		{
			if (IsEmpty())
				return enSaveResults::svFailedEmptyObject;

			else if (DoesClientExist(this->AccountNumber()))
				return enSaveResults::svFailedAccountNumberExist;

			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
		}

		case clsBankClient::DeleteMode:
		{
			Delete();
			*this = _GetEmptyClientObject();
			return enSaveResults::svSucceeded;
		}
		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDeletion = true;

				_SaveClientsDataToFile(vClients);
				*this = _GetEmptyClientObject();

				return true;
			}
		}
		return false;
	}

	static vector <clsBankClient> GetClientList()
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances()
	{
		double TotalBalances = 0;

		vector <clsBankClient> vClients = _LoadClientsDataFromFile();

		for (clsBankClient Client : vClients)
		{
			TotalBalances += Client.AccountBalance;
		}
		return TotalBalances;
	}

	void Deposit(float Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool WithDraw(float Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		_AccountBalance -= Amount;
		Save();
		return true;
	}

	bool Transfer(clsBankClient& DestinationClient, float Amount, string UserName)
	{
		if (Amount > this->AccountBalance)
		{
			return false;
		}
		
		WithDraw(Amount);
		DestinationClient.Deposit(Amount);
		_CreateTransferLog(DestinationClient, Amount, UserName);
		return true;
	}

	static vector <stTransferLogRecord> GetTransferLogList()
	{
		vector <stTransferLogRecord> vTransferLoginRecords;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";
			stTransferLogRecord TransferLoginRecord;

			while (getline(MyFile, Line))
			{
				TransferLoginRecord = _ConvertLineToTransferLogRecord(Line);
				vTransferLoginRecords.push_back(TransferLoginRecord);
			}
			MyFile.close();
		}
		return vTransferLoginRecords;
	}
};

