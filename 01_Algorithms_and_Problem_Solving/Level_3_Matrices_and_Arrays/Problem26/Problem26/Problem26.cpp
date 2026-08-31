#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
	string S1 = "";
	cout << "Enter the string\n";
	getline(cin, S1);
	return S1;
}

string UppercaseTheWholeString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = toupper(S1[i]);
	}
	return S1;
}

string LowerCaseTheWholeString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}
	return S1;
}

int main()
{
	string S1 = ReadString();

	cout << S1 << endl;

	cout << endl;
	S1 = UppercaseTheWholeString(S1);
	cout << S1 << endl;

	cout << endl;
	S1 = LowerCaseTheWholeString(S1);
	cout << S1 << endl;

	system("pause>0");
}