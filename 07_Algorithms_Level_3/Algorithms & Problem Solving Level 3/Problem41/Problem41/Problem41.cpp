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

vector <string> split(string S1, string Delim)
{
	vector <string> vString;

	string sWord = "";
	short pos = 0;

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

string ReverseString(string S1)
{
	vector <string> vString;
	string S2 = "";

	vString = split(S1, " ");

	vector <string> ::iterator iter = vString.end();

	while (iter != vString.begin())
	{
		--iter;

		S2 += *iter + " ";
	}
	S2 = S2.substr(0, S2.length() - 1);

	return S2;
}

int main()
{
	string S1 = ReadString();

	S1 = ReverseString(S1);

	cout << S1 << endl;

	system("pause>0");
}