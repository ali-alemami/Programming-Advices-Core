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

bool InverCharCase(char C1)
{
	return isupper(C1) ? tolower(C1) : toupper(C1);
}

string InvertAllLettersCaseInString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = InverCharCase(S1[i]);
	}
	return S1;
}

int main()
{
	string S1 = ReadString();

	S1 = InvertAllLettersCaseInString(S1);

	cout << endl << S1 << endl;

	system("pause>0");
}