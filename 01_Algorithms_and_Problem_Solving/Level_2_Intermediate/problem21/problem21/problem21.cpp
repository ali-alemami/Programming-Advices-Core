#include <iostream>
using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter = 2,
	SpecialCharacter = 3, Digit = 4 };

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

int RandomNumber(int From ,int To)
{
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

char GetRandomCharacter(enCharType CharType)
{
	switch (CharType)
	{
	case SmallLetter:
		return char(RandomNumber(97, 122));

	case CapitalLetter:
		return char(RandomNumber(65, 90));

	case SpecialCharacter:
		return char(RandomNumber(33, 47));

	case Digit:
		return char(RandomNumber(48, 57));
	}
}

string GenerateWord(enCharType CharType, short Length)
{
	string Word = "";

	for (int i = 1; i <= Length; i++)
	{
		Word += GetRandomCharacter(CharType);
	}
	return Word;
}

string GenerateKey(enCharType CharType, short Length)
{
	string Key = "";

	for (int i = 1; i <= Length; i++)
	{
		Key += GenerateWord(CharType, 4) + "-";
	}
	Key += "\b ";
	return Key;
}

void GenerateKeys(enCharType CharTyp, int NumberOfKeys)
{
	for (int i = 1; i <= NumberOfKeys; i++)
	{
		cout << "Key [" << i << "] : " 
			<< GenerateKey(CharTyp, 4) << endl;
	}
	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	GenerateKeys(Digit, ReadPositiveNumber("How Many Keys ?"));

	return 0;
}