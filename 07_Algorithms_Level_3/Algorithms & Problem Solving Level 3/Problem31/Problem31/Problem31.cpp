#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string ReadString()
{
	string S1 = "";
	cout << "Enter your string?\n";
	getline(cin, S1);
	return S1;
}

char ReadChar()
{
	char Char1 = ' ';
	cout << "Enter a character?\n";
	cin >> Char1;
	return Char1;
}

short CountCharacterInString(string S1, char Char1)
{
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] == Char1)
		{
			Counter++;
		}
	}
	return Counter;
}

short CountCharacterInString_CaseUnsinsitive(string S1, char Char1)
{
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (tolower(S1[i]) == tolower(Char1))
		{
			Counter++;
		}
	}
	return Counter;
}

int main()
{
	string S1 = ReadString();
	char Char1 = ReadChar();

	cout << "\nLetter \'" << Char1 << "\' Count = " <<
		CountCharacterInString(S1, Char1) << endl;
	

	cout << "\nLetter \'" << char(tolower(Char1)) <<
		"\' Or \' " << char(toupper(Char1)) <<
		"\' Count = " << CountCharacterInString_CaseUnsinsitive(S1, Char1) <<
		endl;

	system("pause>0");
}
