#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
	string S1 = "";
	cout << "Enter your string\n";
	getline(cin, S1);
	return S1;
}

string LowerCaseString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}
	return S1;
}

string ReplaceWordInString(string S1, string OldWord, string NewWord, bool CaseSensitive = true)
{
	short pos = 0;

	if (CaseSensitive)
	{
		while ((pos = S1.find(OldWord)) != std::string::npos)
		{
			S1.erase(pos, OldWord.length());
			S1.insert(pos, NewWord);
		}

		return S1;
	}
	else
	{
		string LCS1 = LowerCaseString(S1);
		OldWord = LowerCaseString(OldWord);

		while ((pos = LCS1.find(OldWord)) != std::string::npos)
		{
			LCS1.erase(pos, OldWord.length());
			LCS1.insert(pos, NewWord);

			S1.erase(pos, OldWord.length());
			S1.insert(pos, NewWord);
		}

		return S1;
	}
}

int main()
{
	//string S1 = ReadString();

	string S2 = "Welcome to Jordan, Jordan is a nice country";
	string StringToReplace = "jordan";
	string ReplaceTo = "USA";

	cout << "\nOrigignal string:\n" << S2 << endl;

	cout << "\n\nReplace with match case:\n";
	cout << ReplaceWordInString(S2, StringToReplace, ReplaceTo) << endl;

	cout << "\nReplace without match case:\n";
	cout << ReplaceWordInString(S2, StringToReplace, ReplaceTo, false) << endl;
	cout << S1 << endl;

	system("pause>0");
}