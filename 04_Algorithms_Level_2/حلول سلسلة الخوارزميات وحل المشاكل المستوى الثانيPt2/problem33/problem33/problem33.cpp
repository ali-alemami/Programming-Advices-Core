#include <iostream>
using namespace std;

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

enum enCharacterType { SmallLetter = 1, CapitalLetter = 2,
	SpecialCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}

char GetCharacter(enCharacterType CharType)
{
	switch (CharType)
	{
	case SmallLetter:
		return char(RandomNumber(97, 122));

	case CapitalLetter:
		return char(RandomNumber(65, 90));

	case SpecialCharacter:
		return char(RandomNumber(35, 46));

	case Digit:
		return char(RandomNumber(47, 56));
	}
}

string GetWord(enCharacterType CharType)
{
	string Word = "";
	Word += GetCharacter(CharType);
	Word += GetCharacter(CharType);
	Word += GetCharacter(CharType);
	Word += GetCharacter(CharType);

	return Word;
}

string GenerateKey(enCharacterType CharType, int KeyLength)
{
	string Key = "";

	for (int i = 1; i <= KeyLength; i++)
	{
		Key = Key + GetWord(CharType) + "-";
	}
	Key += "\b ";

	return Key;
}

void FillArrayWithLetters(string arr[100], string Key)
{
	for (int i = 0; i < size(Key); i++)
	{
		arr[i] = Key[i];
	}
}

void PrintArray(string arr[100], string Key)
{
	for (int i = 0; i < size(Key); i++)
	{
		cout << arr[i];
	}
	cout << endl;
}

void GenerateKeysInArray(int NumberOfKeys, string arr[100], string& Key)
{
	for (int i = 1; i <= NumberOfKeys; i++)
	{
		Key = GenerateKey(enCharacterType::CapitalLetter, 4);

		FillArrayWithLetters(arr, Key);
		
		cout << "Array [" << i << "] : ";
		PrintArray(arr, Key);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int NumberOfKeys = ReadPositiveNumber("How many arrays ?");
	string arr[100];
	string Key;

	GenerateKeysInArray(NumberOfKeys, arr, Key);

	return 0;
}