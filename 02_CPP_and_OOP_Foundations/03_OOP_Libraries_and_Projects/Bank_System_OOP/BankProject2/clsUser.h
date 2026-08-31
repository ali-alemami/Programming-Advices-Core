#pragma once

#include <iostream>
#include "clsPerson.h"
#include <fstream>
#include "clsString.h"
#include <vector>
#include <string>
#include "clsDate.h"
#include "clsBankClient.h"
#include "clsUtil.h"

using namespace std;

class clsUser : public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _UserName;
	string _Password;
	int _Permissions;

	bool _MarkedForDeletion = false;

	static clsUser _ConvertLineToUserObject(string Line)
	{
		vector <string> vUser = clsString::Split(Line, "#//#");
		
		return clsUser(enMode::UpdateMode, vUser[0], vUser[1], vUser[2],
			vUser[3], vUser[4], clsUtil::DecryptText(vUser[5], 5), stoi(vUser[6]));
	}

	static string _ConvertUserObjectToLine(clsUser User, string Separator = "#//#")
	{
		string DataLine = "";

		DataLine += User.FirstName + Separator;
		DataLine += User.LastName + Separator;
		DataLine += User.Email + Separator;
		DataLine += User.Phone + Separator;
		DataLine += User.UserName + Separator;
		DataLine += clsUtil::EncryptText(User.Password, 5) + Separator;
		DataLine += to_string(User.Permissions);
		
		return DataLine;
	}

	static vector <clsUser> _LoadUsersDataFromFile()
	{
		vector <clsUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);

				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return vUsers;
	}

	static void _SaveUsersDataToFile(vector <clsUser> vUsers)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);

		if (MyFile.is_open())
		{
			string DataLine = "";

			for (clsUser User : vUsers)
			{
				if (User.MarkedForDeletion() == false)
				{
					DataLine = _ConvertUserObjectToLine(User);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	
	void _Update()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser& User : vUsers)
		{
			if (User.UserName == _UserName)
			{
				User = *this;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
	}

	static void _AddDataLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	string _ConvertLoginRecordToLine(string Separator = "#//#")
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateTimeString() + Separator;
		LoginRecord += UserName + Separator;
		LoginRecord += clsUtil::EncryptText(Password, 5) + Separator;
		LoginRecord += to_string(Permissions);
		return LoginRecord;
	}

	struct stLoginRegisterRecord;
	static stLoginRegisterRecord _ConvertLineToLoginRegisterRecord(string Line)
	{
		stLoginRegisterRecord LoginRegisterRecord;
		vector <string> vLoginRegister = clsString::Split(Line, "#//#");

		LoginRegisterRecord.DateTime = vLoginRegister[0];
		LoginRegisterRecord.UserName = vLoginRegister[1];
		LoginRegisterRecord.Password = clsUtil::DecryptText(vLoginRegister[2], 5);
		LoginRegisterRecord.Permissions = stoi(vLoginRegister[3]);

		return LoginRegisterRecord;
	}

public:

	enum enPermissions { pAll = -1, pClientList = 1, pAddNewClient = 2,
		pDeleteClient = 4, pUpdateClient = 8, pFindClient = 16,
		pTransactions = 32, pManageUsers = 64, pLoginRegister = 128, pCurrencyExchange = 256 };

	struct stLoginRegisterRecord
	{
		string DateTime;
		string UserName;
		string Password;
		int Permissions;
	};

	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string UserName, string Password, int Permissions)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}

	bool MarkedForDeletion()
	{
		return _MarkedForDeletion;
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	string GetUserName()
	{
		return _UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}
	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	int GetPersmissions()
	{
		return _Permissions;
	}
	__declspec(property(get = GetPersmissions, put = SetPermissions)) int Permissions;

	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);

				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}
	static clsUser Find(string UserName, string Password)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);

				if (User.UserName == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static bool DoesUserExist(string UserName)
	{
		clsUser User = Find(UserName);
		return (!User.IsEmpty());
	}

	enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 2, svFailedUserExist = 3 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsUser::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResults::svFailedEmptyObject;
			}
		}

		case clsUser::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
		}

		case clsUser::AddNewMode:
		{
			if (IsEmpty())
				return enSaveResults::svFailedEmptyObject;

			else if (DoesUserExist(_UserName))
				return enSaveResults::svFailedUserExist;

			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
		}
		}
	}

	static clsUser _GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	bool Delete()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser& User : vUsers)
		{
			if (User.UserName == this->UserName)
			{
				User._MarkedForDeletion = true;

				_SaveUsersDataToFile(vUsers);
				*this = _GetEmptyUserObject();

				return true;
			}
		}
		return false;
	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	bool CheckAccessPermission(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::pAll)
			return true;

		if ((this->Permissions & Permission) == Permission)
			return true;
		else
			return false;
	}

	void RegisterLogin()
	{
		string stDataLine = _ConvertLoginRecordToLine();

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

	static vector <stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector <stLoginRegisterRecord> vLoginRegister;

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";
			stLoginRegisterRecord LoginRegistRecord;

			while (getline(MyFile, Line))
			{
				LoginRegistRecord = _ConvertLineToLoginRegisterRecord(Line);
				vLoginRegister.push_back(LoginRegistRecord);
			}
			MyFile.close();
		}
		return vLoginRegister;
	}
};