#include <iostream>
#include <string>
#include <vector>

using namespace std;

string LowerCaseString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}
	return S1;
}

vector <string> Split(string S1, string Delim)
{
	vector <string> vString;

	short pos = 0;
	string sWord = "";

	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);

		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}

	if (S1 != "")
	{
		vString.push_back(S1);
	}
	return vString;
}

string JoinString(vector <string> vString, string Delim)
{
	string S1 = "";

	for (string& n : vString)
	{
		S1 += n + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
}

string ReplaceWordInString(string S1, string StringToReplace, string ReplaceTo, bool CaseSensitive = true)
{
	vector <string> vString = Split(S1, " ");

	for (string& n : vString)
	{
		if (CaseSensitive)
		{
			if (n == StringToReplace)
			{
				n = ReplaceTo;
			}
		}
		else
		{
			if (LowerCaseString(n) == LowerCaseString(StringToReplace))
			{
				n = ReplaceTo;
			}
		}
	}
	
	return JoinString(vString, " ");
}

int main()
{
	string S1 = "Welcome to Jordan , jordan is a nice country";
	string StringToReplace = "jordan";
	string ReplaceTo = "USA";

	cout << "\nOriginal string:\n";
	cout << S1 << endl;

	cout << "\n\nReplace with match case:\n";
	cout << ReplaceWordInString(S1, StringToReplace, ReplaceTo) << endl;

	cout << "\n\nReplace with dont match case:\n";
	cout << ReplaceWordInString(S1, StringToReplace, ReplaceTo, false);

	system("pause>0");
}