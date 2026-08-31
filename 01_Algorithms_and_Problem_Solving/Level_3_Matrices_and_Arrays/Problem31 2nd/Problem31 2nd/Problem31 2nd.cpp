#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
	string S1 = "";
	cout << "Enter your string\n";
	getline(cin, S1);
	return S1;
}

char ReadChar()
{
	char Char1 = ' ';
	cout << "Enter a character\n";
	cin >> Char1;
	return Char1;
}

short CountCharacterInString(string S1, char Char1, bool MatchCase = true)
{
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (MatchCase)
		{
			if (S1[i] == Char1)
				Counter++;
		}
		else
		{
			if (tolower(S1[i]) == tolower(Char1))
				Counter++;
		}
	}
	return Counter;
}

char InvertLetterCase(char Char1)
{
	return isupper(Char1) ? tolower(Char1) : toupper(Char1);
}

int main()
{
	string S1 = ReadString();
	char Char1 = ReadChar();

	cout << "\nLetter " << Char1 << " count = " <<
		CountCharacterInString(S1, Char1) << endl << endl;



	cout << "Letter " << Char1 << " or " <<
		InvertLetterCase(Char1) <<
		" count = " << CountCharacterInString(S1, Char1, false);

	system("pause>0");
}