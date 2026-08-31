#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
	string S1 = "";
	cout << "Enter your string?\n";
	getline(cin, S1);
	return S1;
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
	{
		cout << S1 << endl;
	}
}

int main()
{
	string S1 = ReadString();

	PrintEachWordInString(S1);

	system("pause>0");
}