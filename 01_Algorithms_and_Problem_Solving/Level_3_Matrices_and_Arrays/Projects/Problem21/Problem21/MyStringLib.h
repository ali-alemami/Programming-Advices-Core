#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

namespace MyStringLib
{
	string ReadString()
	{
		string Word;
		cout << "Enter your String?\n";;
		getline(cin, Word);
		return Word;
	}

	void PrintFirstLetterInEachWord(string S1)
	{
		bool IsFirstLetter = true;

		cout << "\nFirst letters of this string:\n";

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
				cout << S1[i] << endl;

			IsFirstLetter = (S1[i] == ' ') ? true : false;
		}
	}

	string UpperCaseFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
				S1[i] = toupper(S1[i]);

			IsFirstLetter = (S1[i] == ' ') ? true : false;
		}
		return S1;
	}

	string LowerCaseFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
				S1[i] = tolower(S1[i]);

			IsFirstLetter = (S1[i] == ' ') ? true : false;
		}
		return S1;
	}

	string UpperAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
			S1[i] = toupper(S1[i]);

		return S1;
	}

	string LowerAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
			S1[i] = tolower(S1[i]);

		return S1;
	}

	char ReadChar()
	{
		char S1;
		cout << "Enter a Character?\n";
		cin >> S1;
		return S1;
	}

	char InvertCharacterCase(char Ch1)
	{
		return isupper(Ch1) ? tolower(Ch1) : toupper(Ch1);
	}

	string InvertAllStringLettersCase(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertCharacterCase(S1[i]);
		}
		return S1;
	}

	short CapitalLettersCounter(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
				Counter++;
		}
		return Counter;
	}

	short SmallLettersCounter(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
				Counter++;
		}
		return Counter;
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 2 };

	short CountLetters(string S1, enWhatToCount WhatToCount = All)
	{
		if (WhatToCount == All)
		{
			return S1.length();
		}

		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (WhatToCount == SmallLetters && islower(S1[i]))
				Counter++;
			else if (WhatToCount == CapitalLetters && isupper(S1[i]))
				Counter++;
		}
		return Counter;
	}

	short CountCharInString(string S1, char Ch1, bool MatchCase = true)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == Ch1)
					Counter++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(Ch1))
					Counter++;
			}
		}
		return Counter;
	}

	bool IsVowel(char Ch1)
	{
		Ch1 = tolower(Ch1);

		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
	}

	short CountVowels(string S1)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1[i]))
				Counter++;
		}
		return Counter;
	}

	void PrintAllVowelsInString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1[i]))
				cout << S1[i] << "  ";
		}
	}

	void PrintEachWordInString(string S1)
	{
		string delim = " ";

		short pos = 0;
		string sWord = "";

		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				cout << sWord << endl;
			}
			S1.erase(0, pos + delim.length());
		}
		if (S1 != "")
			cout << S1 << endl;
	}

	short CountEachWordInString(string S1)
	{
		short Counter = 0;
		string delim = " ";

		short pos = 0;
		string sWord = "";

		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
				Counter++;

			S1.erase(0, pos + delim.length());
		}
		if (S1 != "")
			Counter++;

		return Counter;
	}

	vector <string> SplitString(string S1, string Delim = " ")
	{
		vector <string> vString;

		short pos = 0;
		string sWord = "";
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
				vString.push_back(sWord);

			S1.erase(0, pos + Delim.length());
		}
		if (S1 != "")
			vString.push_back(S1);
		return vString;
	}

	string JoinString(vector <string> vString, string Delim = " ")
	{
		string S1 = "";
		for (string& s : vString)
		{
			S1 += s + Delim;
		}
		return S1.substr(0, S1.length() - Delim.length());
	}

	string JoinString(string arr[], short ArrayLength, string Delim = " ")
	{
		string S1 = "";
		for (short i = 0; i < ArrayLength; i++)
		{
			S1 += arr[i] + Delim;
		}
		return S1.substr(0, S1.length() - Delim.length());
	}

	void PrintVector(vector <string> vString)
	{
		for (string& s : vString)
		{
			cout << s << endl;
		}
	}

	string TrimLeft(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return "";
	}

	string TrimRight(string S1)
	{
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}
		return "";
	}

	string Trim(string S1)
	{
		return TrimRight(TrimLeft(S1));
	}

	string ReverseWordsInString(string S1)
	{
		vector <string> vString;
		string S2 = "";

		vString = SplitString(S1);

		vector <string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;

			S2 += *iter + " ";
		}
		return S2.substr(0, S2.length() - 1);
	}

	string ReplaceWordInString(string S1, string OldWord, string NewWord)
	{
		short pos = S1.find(OldWord);

		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, OldWord.length(), NewWord);
			pos = S1.find(OldWord);
		}
		return S1;
	}

	string ReplaceWordInStringUsingSplit(string S1, string OldWord, string NewWord, bool MatchCase = true)
	{
		vector <string> vString = SplitString(S1, " ");

		for (string& s : vString)
		{
			if (MatchCase)
			{
				if (s == OldWord)
				{
					s = NewWord;
				}
			}
			else
			{
				if (LowerAllString(s) == LowerAllString(OldWord))
				{
					s = NewWord;
				}
			}
		}
		return JoinString(vString, " ");
	}

	string RemovePunctuations(string S1)
	{
		string S2 = "";
		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
		}
		return S2;
	}

	struct sClient
	{
		string AccountNumber;
		string PinCode;
		string Name;
		string PhoneNumber;
		float AccoutBalance = 0;
		bool MarkForDelete = false;
	};

	sClient ReadNewClient()
	{
		sClient Client;

		cout << "Enter Account Number? ";
		getline(cin >> ws, Client.AccountNumber);

		cout << "Enter PinCode? ";
		getline(cin, Client.PinCode);

		cout << "Enter Name? ";
		getline(cin, Client.Name);

		cout << "Enter Phone Number? ";
		getline(cin, Client.PhoneNumber);

		cout << "Enter Account Balance? ";
		cin >> Client.AccoutBalance;

		return Client;
	}

	string ConvertRecordToLine(sClient Client, string Separator = "#//#")
	{
		string stClientRecord = "";

		stClientRecord += Client.AccountNumber + Separator;
		stClientRecord += Client.PinCode + Separator;
		stClientRecord += Client.Name + Separator;
		stClientRecord += Client.PhoneNumber + Separator;
		stClientRecord += to_string(Client.AccoutBalance);

		return stClientRecord;

	}

	sClient ConvertLineToRecord(string S1, string Separator = "#//#")
	{
		vector <string> vClientData;
		vClientData = SplitString(S1, Separator);

		sClient Client;

		Client.AccountNumber = vClientData[0];
		Client.PinCode = vClientData[1];
		Client.Name = vClientData[2];
		Client.PhoneNumber = vClientData[3];
		Client.AccoutBalance = stof(vClientData[4]);

		return Client;
	}

	void PrintClientRecord(sClient Client)
	{
		cout << "The following are the client details:\n\n";

		cout << "Accout Number: " << Client.AccountNumber << "\n";
		cout << "Pin Code     : " << Client.PinCode << "\n";
		cout << "Name         : " << Client.Name << "\n";
		cout << "Phone Number : " << Client.PhoneNumber << "\n";
		cout << "Account Balance: " << Client.AccoutBalance << endl;
	}

	void AddDataLineToFile(string FileName, string stDataLine)
	{
		fstream MyFile;

		MyFile.open(FileName, ios::in | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

	void AddNewClient()
	{
		sClient Client = ReadNewClient();

		AddDataLineToFile(ClientsFile, ConvertRecordToLine(Client));
	}

	void AddNewClients()
	{
		char Answer = 'y';
		do
		{
			system("cls");
			cout << "Adding New Client:\n\n";
			AddNewClient();
			cout << "\nClient Added Successfully, do you want to add more clients (y/n)?  ";
			cin >> Answer;
		} while (tolower(Answer) == 'y');
	}

	vector <sClient> LoadClientsDataFromFile(string FileName)
	{
		vector <sClient> vClients;
		fstream MyFile;
		MyFile.open(FileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				vClients.push_back(ConvertLineToRecord(Line));
			}
			MyFile.close();
		}
		return vClients;
	}

	void PrintClientRecordInLine(sClient Client)
	{
		cout << " | " << left << setw(16) << Client.AccountNumber;
		cout << " | " << left << setw(10) << Client.PinCode;
		cout << " | " << left << setw(21) << Client.Name;
		cout << " | " << left << setw(13) << Client.PhoneNumber;
		cout << " | " << left << setw(11) << Client.AccoutBalance;
	}

	void ShowAllClients(vector <sClient> vClients)
	{
		cout << "\n\t\t\t\tClients List (" << vClients.size() - 1 << ") Client(s).s\n\n";

		cout << "______________________________________________________________________________________________\n\n";
		cout << " | " << left << setw(16) << "Account Number";
		cout << " | " << left << setw(10) << "Pin Code";
		cout << " | " << left << setw(21) << "Client Name";
		cout << " | " << left << setw(13) << "Phone";
		cout << " | " << left << setw(11) << "Account Balance\n";
		cout << "______________________________________________________________________________________________\n\n";

		for (sClient Client : vClients)
		{
			PrintClientRecordInLine(Client);
			cout << endl;
		}
		cout << "______________________________________________________________________________________________\n\n";
	}

	string ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "Enter Account Number? ";
		getline(cin >> ws, AccountNumber);
		return AccountNumber;
	}

	bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
	{
		for (sClient C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				Client = C;
				return true;
			}
		}
		return false;
	}

	bool MarkAccountForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
	{
		for (sClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.MarkForDelete = true;
				return true;
			}
		}
		return false;
	}

	vector <sClient> SaveClientsDataToFile(string FileName, vector <sClient> vClients)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out);

		string DataLine;

		if (MyFile.is_open())
		{
			for (sClient C : vClients)
			{
				if (!C.MarkForDelete)
				{
					DataLine = ConvertRecordToLine(C);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
		return vClients;
	}

	bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
	{
		sClient Client;

		if (FindClientByAccountNumber(AccountNumber, vClients, Client))
		{
			char Answer = 'n';
			cout << endl;

			PrintClientRecord(Client);
			
			cout << "\nAre you sure you want to delete this client? y/n ? ";
			cin >> Answer;

			if (tolower(Answer) == 'y')
			{
				MarkAccountForDeleteByAccountNumber(AccountNumber, vClients);
				SaveClientsDataToFile(ClientsFile, vClients);

				vector <sClient> vClients = LoadClientsDataFromFile(ClientsFile);

				cout << "\nClient Was deleted successfully\n\n";
				return true;
			}
		}
		else
		{
			cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n\n";
			return false;
		}
	}

	sClient ChangeClientRecord(string AccountNumber)
	{
		sClient Client;
		Client.AccountNumber = AccountNumber;

		cout << "Enter PinCode? ";
		getline(cin >> ws, Client.PinCode);

		cout << "Enter Name? ";
		getline(cin, Client.Name);

		cout << "Enter Phone? ";
		getline(cin, Client.PhoneNumber);

		cout << "Enter Account Balance? ";
		cin >> Client.AccoutBalance;

		return Client;
	}

	bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
	{
		sClient Client;

		if (FindClientByAccountNumber(AccountNumber, vClients, Client))
		{
			cout << endl;
			PrintClientRecord(Client);

			char Answer = 'n';
			cout << "\nAre you sure you want to update this client? y/n ? ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				for (sClient& C : vClients)
				{
					if (C.AccountNumber == AccountNumber)
					{
						C = ChangeClientRecord(C.AccountNumber);
						break;
					}
				}

				SaveClientsDataToFile(ClientsFile, vClients);
				cout << "\n\nClient was Updated Successfully.\n\n";
				return true;
			}
		}
		else
		{
			cout << "\n\nClient with Account Number (" << AccountNumber << ") is Not Found!\n\n";
			return false;
		}
	}
}