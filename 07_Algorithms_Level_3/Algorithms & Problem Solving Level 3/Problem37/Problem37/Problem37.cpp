#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
	string S1 = "";
	cout << "Enter your string?\n";
	getline(cin, S1);
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

void PrintVector(vector <string> vString)
{
	for (string& n : vString)
	{
		cout << n << endl;
	}
}

int main()
{
	string S1 = ReadString();

	vector <string> vString = Split(S1, " ");

	cout << "\nTokens = " << vString.size() << endl;

	PrintVector(vString);

	system("pause>0");
}