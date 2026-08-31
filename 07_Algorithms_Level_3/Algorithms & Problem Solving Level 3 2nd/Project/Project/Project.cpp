#include <iostream>
#include <fstream>
#include <string>

#include "MyStringLib.h"
#include "MyDateLib.h"

using namespace std;
using namespace MyStringLib;
using namespace MyDateLib;


enum enMainMenuOptions
{
	eShowClientList = 1, eAddNewClient = 2,
	eDeleteClient = 3, eUpdateClient = 4,
	eFindClient = 5, eTransactions = 6, eManageUsers = 7, eLogOut = 8
};

enum enTransactions { eDepsit = 1, eWithdraw = 2, eTotalBalances = 3, eMainMenu = 4 };

enum enManageUsersOptions {eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenu2 = 6};

enum enMainMenuPermissions {
	eAll = -1, pClientList = 1, pAddNewClient = 2,
	pDeleteClient = 4, pUpdateClient = 8, pFindClient = 16,
	pTransaction = 32, pManageUsers = 64
};

void PerformMainMenuOptions(enMainMenuOptions MainMenuOptins);
void PerformTransactionsMenuOption(enTransactions eTransactions);
void PerformManageUsersMenuOption(enManageUsersOptions ManageUsersOptions);

short ReadMainMenuOption()
{
	short Option = 0;
	cout << "\nChoose what do you want to do? [1 to 8]? ";
	cin >> Option;
	return Option;
}

void ShowMainMenu()
{
	system("cls");
	cout << "================================";
	cout << "\n        Main Menu Screen      \n";
	cout << "================================\n";
	cout << "    [1] Show Client List.\n";
	cout << "    [2] Add New Client.\n";
	cout << "    [3] Delete Client.\n";
	cout << "    [4] Update Client.\n";
	cout << "    [5] Find Client.\n";
	cout << "    [6] Transactions.\n";
	cout << "    [7] Manage Users.\n";
	cout << "    [8] Logout.\n";
	cout << "============================";

	PerformMainMenuOptions(enMainMenuOptions(ReadMainMenuOption()));
}

void GoBackToMainMenu()
{
	cout << "\n\nPrees any key to go back to the main menu...";
	system("pause>0");
	ShowMainMenu();
}

void ShowHeaderForAddNewClientScreen()
{
	cout << "----------------------------------";
	cout << "\n      Add New Clients Screen      \n";
	cout << "----------------------------------\n";
}

void ShowAddNewClientsScreen()
{
	if (!CheckAccessPermission(enMainMenuPermissions::pAddNewClient))
	{
		cout << "\n\nAccess Denied.\n\n";
		GoBackToMainMenu();
		return;
	}
	ShowHeaderForAddNewClientScreen();
	AddNewClients();
}

void ShowHeaderForDeleteClientScreen()
{
	cout << "--------------------------------";
	cout << "\n      Delete Client Screen      \n";
	cout << "--------------------------------\n";
}

void ShowDeleteClientScreen()
{
	if (!CheckAccessPermission(enMainMenuPermissions::pDeleteClient))
	{
		cout << "\n\nAccess Denied.\n\n";
		GoBackToMainMenu();
		return;
	}
	ShowHeaderForDeleteClientScreen();
	string AccountNumber = ReadAccountNumber();
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFile);
	DeleteClientByAccountNumber(AccountNumber, vClients);
}

void ShowHeaderForUpdateClientScreen()
{
	cout << "--------------------------------";
	cout << "\n      Update Client Screen      \n";
	cout << "--------------------------------\n";
}

void ShowUpdateClientScreen()
{
	if (!CheckAccessPermission(enMainMenuPermissions::pUpdateClient))
	{
		cout << "\n\nAccess Denied.\n\n";
		GoBackToMainMenu();
		return;
	}
	ShowHeaderForUpdateClientScreen();
	string AccountNumber = ReadAccountNumber();
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFile);
	UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowHeaderForFindClientScreen()
{
	cout << "------------------------------";
	cout << "\n      Find Client Screen      \n";
	cout << "------------------------------\n";
}

void ShowFindClientScreen()
{
	if (!CheckAccessPermission(enMainMenuPermissions::pFindClient))
	{
		cout << "\n\nAccess Denied.\n\n";
		GoBackToMainMenu();
		return;
	}
	ShowHeaderForFindClientScreen();
	vector <sClient> vClient = LoadClientsDataFromFile(ClientsFile);
	string AccountNumber = ReadAccountNumber();
	sClient Client;

	if (FindClientByAccountNumber(AccountNumber, vClient, Client))
		PrintClientRecord(Client);

	else
		cout << "\nClient With Account Number is not found!\n\n";

}

short ReadTransactionsMenuOption()
{
	short Option = 0;
	cout << "Choose what do you want to do? [1 to 4]? ";
	cin >> Option;
	return Option;
}

void ShowTransactionsMenuScreen()
{
	if (!CheckAccessPermission(enMainMenuPermissions::pTransaction))
	{
		cout << "\n\nAccess Denied.\n\n";
		GoBackToMainMenu();
		return;
	}
	system("cls");
	cout << "=====================================";
	cout << "\n      Transactions Menue Screen      \n";
	cout << "=====================================\n";

	cout << "    [1] Deposit.\n";
	cout << "    [2] Withdraw.\n";
	cout << "    [3] Total Balances.\n";
	cout << "    [4] Main Menu.\n";
	cout << "=====================================\n";

	PerformTransactionsMenuOption((enTransactions)ReadTransactionsMenuOption());
}

void GoBackToTransactionsScreen()
{
	cout << "\n\nPress any key to go back to the transactions screen...";
	system("pause>0");
	ShowTransactionsMenuScreen();
}

bool DepositToClient(string AccountNumber, vector <sClient>& vClients, float DepositAmount)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.AccoutBalance += DepositAmount;
			cout << "\nDone successfully, new balance is : " << C.AccoutBalance << endl;
			return true;
		}
	}
	return false;
}

bool DepositBalanceToClientByAccountNumber(string AccountNumber, float Amount, vector <sClient>& vClients, bool Deposit = false)
{
	char Answer = 'n';
	cout << "\nAre you sure you want to perform this transaction? ";
	cin >> Answer;

	if (tolower(Answer) == 'y')
	{
		for (sClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.AccoutBalance += Amount;
				SaveClientsDataToFile(ClientsFile, vClients);
				cout << "\nDone successfully, new balance is : " << C.AccoutBalance << endl;
				return true;
			}
		}
	}
	return false;
}

void ShowDepositScreen()
{
	cout << "--------------------------";
	cout << "\n      Deposit Screen      ";
	cout << "\n--------------------------\n";

	string AccountNumber = ReadAccountNumber();
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFile);
	sClient Client;

	while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		cout << "Client with Account Number " << AccountNumber << "Does Not exist!";
		AccountNumber = ReadAccountNumber();
	}

	PrintClientRecord(Client);

	float Amount = 0;
	cout << "\nEnter Amount? ";
	cin >> Amount;

	DepositBalanceToClientByAccountNumber(AccountNumber, Amount, vClients);
}

void ShowExitScreen()
{
	cout << "------------------------";
	cout << "\n      Program Ends      \n";
	cout << "------------------------" << endl;
}

void PrintClientBalance(sClient Client)
{
	cout << " | " << left << setw(16) << Client.AccountNumber;
	cout << " | " << left << setw(21) << Client.Name;
	cout << " | " << left << setw(11) << Client.AccoutBalance;
}

void ShowTotalBalanceScreen()
{
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFile);

	if (vClients.size() == 0)
		cout << "\n\nNo Clients are in the system\n\n";

	cout << "\n\t\t\t\tClients List (" << vClients.size() - 1 << ") Client(s).\n\n";

	cout << "______________________________________________________________________________________________\n\n";
	cout << " | " << left << setw(16) << "Account Number";
	cout << " | " << left << setw(21) << "Client Name";
	cout << " | " << left << setw(11) << "Account Balance\n";
	cout << "______________________________________________________________________________________________\n\n";


	float Counter = 0;
	for (sClient s : vClients)
	{
		PrintClientBalance(s);
		Counter += s.AccoutBalance;
		cout << endl;
	}
	cout << "Total Balances = " << Counter << endl;
}

void ShowWithDrawScreen()
{
	cout << "---------------------------";
	cout << "\n      Withdraw Screen      ";
	cout << "\n---------------------------\n";

	string AccountNumber = ReadAccountNumber();
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFile);
	sClient Client;

	while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		cout << "Client with Account Number " << AccountNumber << "Does Not exist!";
		AccountNumber = ReadAccountNumber();
	}

	PrintClientRecord(Client);

	float Amount = 0;
	cout << "\nEnter Amount? ";
	cin >> Amount;

	while (Amount > Client.AccoutBalance)
	{
		cout << "\nAmount Exceeds Account Balance, you can withdraw up to: " << Client.AccoutBalance << endl;
		cout << "Withdraw another amount: ";
		cin >> Amount;
	}

	DepositBalanceToClientByAccountNumber(AccountNumber, Amount * -1, vClients);
}

/// <summary>
/// 
/// </summary>

sUser CurrentUser;

bool CheckAccessPermission(enMainMenuPermissions Permission)
{
	if (CurrentUser.Permission == enMainMenuPermissions::eAll)
		return true;

	if ((Permission & CurrentUser.Permission) == Permission)
		return true;

	else
		return false;
}

struct sUser
{
	string Name;
	string PassWord;
	short Permissions = 0;
	bool MarkForDeletion = false;
};

sUser ConvertUserLineToRecord(string S1, string Separator = "#//#")
{
	vector <string> vUserData = SplitString(S1, Separator);

	sUser User;

	User.Name = vUserData[0];
	User.PassWord = vUserData[1];
	User.Permissions = stoi(vUserData[2]);

	return User;
}

vector <sUser> LoadUsersDataFromFile(string FileName)
{
	vector <sUser> vUsers;

	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line = "";
		while (getline(MyFile, Line))
		{
			vUsers.push_back(ConvertUserLineToRecord(Line));
		}
		MyFile.close();
	}
	return vUsers;
}

void ReadLogInInfo(string& UserName, string& PassWord)
{
	cout << "Enter Username? ";
	getline(cin >> ws, UserName);
	cout << "Enter Password? ";
	getline(cin, PassWord);
}

bool VerifyLogin(vector <sUser> vUsers)
{
	string UserName, PassWord;
	ReadLogInInfo(UserName, PassWord);

	for (sUser U : vUsers)
	{
		if (U.Name == UserName && U.PassWord == PassWord)
		{
			Permission = U.Permissions;
			return true;
		}
	}
	return false;
}

bool FindUserByUserNameAndPassword(string UserName, string Password, sUser& User)
{
	vector <sUser> vUsers = LoadUsersDataFromFile(UserName);

	for (sUser U : vUsers)
	{
		if (UserName == U.Name && Password == U.PassWord)
		{
			User = U;
			return true;
		}
	}
	return false;
}

bool LoadUserInfo(string UserName, string Password)
{
	if (FindUserByUserNameAndPassword(UserName, Password, CurrentUser))
		return true;
	else
		return false;
}

void LogIn()
{
	bool LoginFailed = false;
	string UserName, Password;
	do
	{
		system("cls");
		cout << "------------------------\n";
		cout << "      Login Screen      \n";
		cout << "------------------------\n";

		if (LoginFailed)
			cout << "Invalid Username/Password!\n";

		cout << "Enter Username? ";
		cin >> UserName;
		cout << "Enter Password? ";
		cin >> Password;

		LoginFailed = !LoadUserInfo(UserName, Password);
	} while (LoginFailed);

	ShowMainMenu();
}

short ReadManageUsersMenuOption()
{
	short Option = 0;
	cout << "Choose what do you want to do? [1 to 6]? ";
	cin >> Option;
	return Option;
}

void ShowManageUsersMenuScreen()
{
	if (!CheckAccessPermission(enMainMenuPermissions::pManageUsers))
	{
		cout << "\n\nAccess Denied.\n\n";
		GoBackToMainMenu();
		return;
	}
	system("cls");
	cout << "====================================\n";
	cout << "      Manage Users Menu Screen      \n";
	cout << "====================================\n";
	cout << "    [1] List Users.\n";
	cout << "    [2] Add New User.\n";
	cout << "    [3] Delete User.\n";
	cout << "    [4] Update User.\n";
	cout << "    [5] Find User.\n";
	cout << "    [6] Main Menu.\n";
	cout << "====================================\n";

	PerformManageUsersMenuOption((enManageUsersOptions)ReadManageUsersMenuOption());
}

void GoBackToManageUsersMenu()
{
	cout << "\n\nPress any key to go back to Manage Users Menu...";
	system("pause>0");
	ShowManageUsersMenuScreen();
}

void PrintUserRecordInLine(sUser User)
{
	cout << " | " << left << setw(16) << User.Name;
	cout << " | " << left << setw(10) << User.PassWord;
	cout << " | " << left << setw(12) << User.Permissions;
}

void ShowUsersList()
{
	vector <sUser> vUsers = LoadUsersDataFromFile(UsersFile);

	if (vUsers.size() == 0)
	{
		cout << "\nNo Users are in the system\n";
	}
	else
	{
		cout << "\n\t\t\t\tUsers List (" << vUsers.size() << ") User(s).\n\n";

		cout << "______________________________________________________________________________________________\n\n";
		cout << " | " << left << setw(16) << "User Name";
		cout << " | " << left << setw(10) << "Password";
		cout << " | " << left << setw(12) << "Permissions\n";
		cout << "______________________________________________________________________________________________\n\n";

		if (vUsers.size() == 0)
		{
			cout << "\nNo Clients are in the system.\n";
		}
		else
		{
			for (sUser U : vUsers)
			{
				PrintUserRecordInLine(U);
				cout << endl;
			}
		}
		cout << "______________________________________________________________________________________________\n\n";
	}
}

bool UserExistByUserName(string FileName, string UserName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line = "";
		sUser User;
		while (getline(MyFile, Line))
		{
			User = ConvertUserLineToRecord(Line);

			if (UserName == User.Name)
			{
				MyFile.close();
				return true;
			}
		}
		MyFile.close();
	}
	return false;
}

short ReadPermissionsToSet(sUser User)
{
	short Permissions = 0;
	char Answer = 'n';

	cout << "\nDo you want to give full access? y/n? ";
	cin >> Answer;
	if (tolower(Answer) == 'y')
	{
		return -1;
	}

	cout << "\nDo you want to give access to:\n";

	cout << "\nShow Client List? y/n? ";
	cin >> Answer;
	if (tolower(Answer) == 'y')
	{
		Permissions += enMainMenuPermissions::pClientList;
	}
	cout << "\nAdd New Client? y/n? ";
	cin >> Answer;
	if (tolower(Answer) == 'y')
	{
		Permissions += enMainMenuPermissions::pAddNewClient;
	}
	cout << "\nDelete Client? y/n? ";
	cin >> Answer;
	if (tolower(Answer) == 'y')
	{
		Permissions += enMainMenuPermissions::pDeleteClient;
	}
	cout << "\nUpdate Client? y/n? ";
	cin >> Answer;
	if (tolower(Answer) == 'y')
	{
		Permissions += enMainMenuPermissions::pUpdateClient;
	}
	cout << "\nFind Client? y/n? ";
	cin >> Answer;
	if (tolower(Answer) == 'y')
	{
		Permissions += enMainMenuPermissions::pFindClient;
	}
	cout << "\nTransactions? y/n? ";
	cin >> Answer;
	if (tolower(Answer) == 'y')
	{
		Permissions += enMainMenuPermissions::pTransaction;
	}
	cout << "\nManage Users? y/n? ";
	cin >> Answer;
	if (tolower(Answer) == 'y')
	{
		Permissions += enMainMenuPermissions::pManageUsers;
	}
	return Permissions;
}

sUser ReadNewUser()
{
	sUser User;

	cout << "Enter Username? ";
	getline(cin >> ws, User.Name);

	while (UserExistByUserName(UsersFile, User.Name))
	{
		cout << "\nUser with [" << User.Name << "] already exists, Enter another Username? ";
		getline(cin, User.Name);
	}
	cout << "Enter Password? ";
	getline(cin, User.PassWord);

	User.Permissions = ReadPermissionsToSet(User);
	return User;
}

string ConvertUserRecordToLine(sUser User, string Separator = "#//#")
{
	string Line = "";
	Line += User.Name + Separator;
	Line += User.PassWord + Separator;
	Line += to_string(User.Permissions);
	return Line;
}

void AddNewUser()
{
	sUser User = ReadNewUser(); 

	AddDataLineToFile(UsersFile, ConvertUserRecordToLine(User));
}

void AddNewUsers()
{
	char Answer = 'n';
	do
	{
		cout << "Adding new User:\n\n";
		AddNewUser();
		cout << "\nUser Added Successfully, do you want to add more Users (y/n)?  ";
		cin >> Answer;
	} while (tolower(Answer) == 'y');
}

void ShowAddNewUsersScreen()
{
	cout << "-------------------------------\n";
	cout << "      Add New User Screen      \n";
	cout << "-------------------------------\n";
	AddNewUsers();
}

string ReadUserName()
{
	string UserName = "";
	cout << "\nEnter Username? ";
	getline(cin >> ws, UserName);
	return UserName;
}

bool FindUserByUserName(string UserName, vector <sUser> vUsers, sUser& User)
{
	for (sUser U : vUsers)
	{
		if (U.Name == UserName)
		{
			User = U;
			return true;
		}
	}
	return false;
}

void PrintUserCard(sUser User)
{
	cout << "\nThe following are the user details:\n";
	cout << "----------------------------------------\n";
	cout << "Username    : " << User.Name << endl;
	cout << "Password    : " << User.PassWord << endl;
	cout << "Permissions : " << User.Permissions << endl;
	cout << "----------------------------------------\n";
}

bool MarkClientForDeletion(string UserName, vector <sUser>& vUsers)
{
	for (sUser& U : vUsers)
	{
		if (U.Name == UserName)
		{
			U.MarkForDeletion = true;
			return true;
		}
	}
	return false;
}

void SaveUsersDataToFile(string FileName, vector <sUser> vUsers)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		string Line = "";
		for (sUser U : vUsers)
		{
			if(!U.MarkForDeletion)
			{
				Line = ConvertUserRecordToLine(U);
				MyFile << Line << endl;
			}
		}
		MyFile.close();
	}
}

bool DeleteUserByUserName(string UserName, vector <sUser>& vUsers)
{
	if (UserName == "Admin")
	{
		cout << "\nYou can't Delete this user.\n\n";
		return false;
	}
	sUser User;
	if (FindUserByUserName(UserName, vUsers, User))
	{
		PrintUserCard(User);

		char Answer = 'n';
		cout << "Are you sure you want to Delete this user? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			MarkClientForDeletion(UserName, vUsers);
			SaveUsersDataToFile(UsersFile, vUsers);
			cout << "\nUser was Deleted Successfully.\n\n";
			vUsers = LoadUsersDataFromFile(UsersFile);
			return true;
		}
	}
	else
	{
		cout << "\nUser with Username (" << UserName << ") is Not Found!\n\n";
		return false;
	}
}

void ShowDeleteUserScreen()
{
	cout << "-------------------------------\n";
	cout << "      Delete Users Screen      \n";
	cout << "-------------------------------\n";

	vector <sUser> vUsers = LoadUsersDataFromFile(UsersFile);
	string UserName = ReadUserName();
	
	DeleteUserByUserName(UserName, vUsers);
}

sUser ChangeUserRecord(string UserName)
{
	sUser User;

	User.Name = UserName;
	cout << "\nEnter password? ";
	getline(cin >> ws, User.PassWord);
	User.Permissions = ReadPermissionsToSet(User);

	return User;
}

bool UpdateUserByUserName(string UserName, vector <sUser>& vUsers)
{
	sUser User;
	if (FindUserByUserName(UserName, vUsers, User))
	{
		PrintUserCard(User);
		char Answer = 'n';
		cout << "Are you sure you want to Update this user? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			for (sUser& U : vUsers)
			{
				if (U.Name == UserName)
				{
					U = ChangeUserRecord(UserName);
					break;
				}
			}
			SaveUsersDataToFile(UsersFile, vUsers);
			cout << "\nUser was Updated Successfully.\n\n";
			return true;
		}
	}
	else
	{
		cout << "\nUser with Account Number (" << UserName << ") is Not Found!\n\n";
		return false;
	}
}

void ShowUpdateUserScreen()
{
	cout << "-------------------------------\n";
	cout << "      Update Users Screen      \n";
	cout << "-------------------------------\n";

	vector <sUser> vUsers = LoadUsersDataFromFile(UsersFile);
	string UserName = ReadUserName();

	UpdateUserByUserName(UserName, vUsers);
}

void ShowFindUserScreen()
{
	cout << "----------------------------\n";
	cout << "      Find User Screen      \n";
	cout << "----------------------------\n";

	string UserName = ReadUserName();
	vector <sUser> vUsers = LoadUsersDataFromFile(UsersFile);
	sUser User;
	if (FindUserByUserName(UserName, vUsers, User))
	{
		PrintUserCard(User);
	}
	else
	{
		cout << "\nUser Does Not Exist!\n\n";
	}
}

void PerformManageUsersMenuOption(enManageUsersOptions ManageUsersOptions)
{
	system("cls");
	switch (ManageUsersOptions)
	{
	case eListUsers:
		ShowUsersList();
		GoBackToManageUsersMenu();
		break;

	case eAddNewUser:
		ShowAddNewUsersScreen();
		GoBackToManageUsersMenu();
		break;

	case eDeleteUser:
		ShowDeleteUserScreen();
		GoBackToManageUsersMenu();
		break;

	case eUpdateUser:
		ShowUpdateUserScreen();
		GoBackToManageUsersMenu();
		break;

	case eFindUser:
		ShowFindUserScreen();
		GoBackToManageUsersMenu();
		break;

	case eMainMenu2:
		ShowMainMenu();
		break;

	default:
		ShowMainMenu();
		break;
	}
}

void PerformTransactionsMenuOption(enTransactions eTransactions)
{
	system("cls");
	switch (eTransactions)
	{
	case eDepsit:
		ShowDepositScreen();
		GoBackToTransactionsScreen();
		break;

	case eWithdraw:
		ShowWithDrawScreen();
		GoBackToTransactionsScreen();
		break;

	case eTotalBalances:
		ShowTotalBalanceScreen();
		GoBackToTransactionsScreen();
		break;

	case eMainMenu:
		ShowMainMenu();
		break;

	default:
		ShowMainMenu();
		break;
	}
}

void PerformMainMenuOptions(enMainMenuOptions MainMenuOptins)
{
	system("cls");
	switch (MainMenuOptins)
	{
	case eShowClientList:
		ShowAllClientsScreen();
		GoBackToMainMenu();
		break;

	case eAddNewClient:
		ShowAddNewClientsScreen();
		GoBackToMainMenu();
		break;

	case eDeleteClient:
		ShowDeleteClientScreen();
		GoBackToMainMenu();
		break;

	case eUpdateClient:
		ShowUpdateClientScreen();
		GoBackToMainMenu();
		break;

	case eFindClient:
		ShowFindClientScreen();
		GoBackToMainMenu();
		break;

	case eTransactions:
		ShowTransactionsMenuScreen();
		break;

	case eManageUsers:
		ShowManageUsersMenuScreen();
		break;

	case eLogOut:
		LogIn();
		break;

	default:
		ShowExitScreen();
		break;
	}
}

int main()
{
	LogIn();

	system("pause>0");
	return 0;
}