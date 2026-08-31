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

string ReplaceWords(string S1, string OldWord, string NewWord)
{
	short pos = 0;

	while ((pos = S1.find(OldWord)) != std::string::npos)
	{
		S1.replace(pos, OldWord.length(), NewWord);
	}

	return S1;
}

int main()
{
	string S1 = ReadString();

	S1 = ReplaceWords(S1, "Jordan", "USA");

	cout << endl << S1 << endl;

	system("pause>0");
}