#include <iostream>
#include <cctype>

using namespace std;

char ReadCharacter()
{
	char Char1 = ' ';
	cout << "Enter a character\n";
	cin >> Char1;
	return Char1;
}

bool CheckVowelCharacter(char Char1)
{
	string VowelCharacters = "aeiou";

	for (short i = 0; i < VowelCharacters.length(); i++)
	{
		if (tolower(Char1) == tolower(VowelCharacters[i]))
		{
			return true;
		}
	}
	return false;
}

bool IsVowel(char Char1)
{
	Char1 = tolower(Char1);

	return ((Char1 == 'a') || (Char1 == 'e') || (Char1 == 'i') || (Char1 == 'o') || (Char1 == 'u'));
}

int main()
{
	char Char1 = ReadCharacter();

	IsVowel(Char1) ?
		cout << "\nYES Letter \'" << Char1 << "\' is a vowel\n\n" : cout << "NO Letter \' " << Char1 << "\' is NOT a vowel\n\n";

	system("pause>0");
}