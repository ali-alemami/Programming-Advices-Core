//#include <iostream>
//using namespace std;
//
//enum enCharType { SmallLetter = 1, CapitalLetter = 2,
//	SpecialCharacter = 3, Digit = 4 };
//
//int ReadPositiveNumber(string Message)
//{
//	int Number = 0;
//	do
//	{
//		cout << Message << endl;
//		cin >> Number;
//	} while (Number <= 0);
//	return Number;
//}
//
//int RandomNumber(int From, int To)
//{
//	int RandNumber = rand() % (To - From + 1) + From;
//	return RandNumber;
//}
//
//char GetRandomCharacter(enCharType CharType)
//{
//	switch (CharType)
//	{
//	case SmallLetter:
//		return char(RandomNumber(97, 122));
//
//	case CapitalLetter:
//		return char(RandomNumber(65, 90));
//
//	case SpecialCharacter:
//		return char(RandomNumber(36, 47));
//
//	case Digit:
//		return char(RandomNumber(48, 57));
//	}
//}
//
//string GenerateWord(enCharType CharType, short Length)
//{
//	string Word = "";
//
//	for (int i = 1; i <= Length; i++)
//	{
//		Word += GetRandomCharacter(CapitalLetter);
//	}
//	return Word;
//}
//
//string GenerateKey()
//{
//	string Key = "";
//
//	Key = GenerateWord(CapitalLetter, 4) + "-";
//	Key = Key + GenerateWord(CapitalLetter, 4) + "-";
//	Key = Key + GenerateWord(CapitalLetter, 4) + "-";
//	Key = Key + GenerateWord(CapitalLetter, 4);
//
//	return Key;
//}
//
//void FillArrayWithKeys(string arr[100], int ArraysNumber)
//{
//	for (int i = 0; i < ArraysNumber; i++)
//	{
//		arr[i] = GenerateKey();
//	}
//}
//
//void PrintStringArray(string arr[100], int ArraysNumber)
//{
//	for (int i = 0; i < ArraysNumber; i++)
//	{
//		cout << "Array [" << i + 1 << "] : ";
//		cout << arr[i] << endl;
//	}
//}
//
//int main()
//{
//	srand((unsigned)time(NULL));
//
//	string arr[100];
//	int ArraysNumber = ReadPositiveNumber("How many Keys?");;
//
//	FillArrayWithKeys(arr, ArraysNumber);
//	PrintStringArray(arr, ArraysNumber);
//
//	return 0;
//}

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

enum enCharype { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}

char GetRandomCharacter(enCharype CharType)
{
	switch (CharType)
	{
	case SmallLetter:
		return char(RandomNumber(97, 122));

	case CapitalLetter:
		return char(RandomNumber(65, 90))
			;
	case SpecialCharacter:
		return char(RandomNumber(36, 47));

	case Digit:
		return char(RandomNumber(48, 57));
	}
}

string GenerateWord(enCharype CharType, short WordLength)
{
	string Word = "";

	for (int i = 1; i <= WordLength; i++)
	{
		Word += GetRandomCharacter(CharType);
	}
	return Word;
}

string GenerateKey()
{
	string Key = "";

	Key = GenerateWord(enCharype::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharype::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharype::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharype::CapitalLetter, 4);

	return Key;
}

void FillArrayWithKeys(string arr[100], int NumberOfArrays)
{
	for (int i = 0; i < NumberOfArrays; i++)
	{
		arr[i] = GenerateKey();
	}
}

void PrintStringArray(string arr[100], int NumberOfArrays)
{
	for (int i = 0; i < NumberOfArrays; i++)
	{
		cout << "Array [" << i + 1 << "] : ";
		cout << arr[i] << "\n";
	}
	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	string arr[100];
	int NumberOfArrays = ReadPositiveNumber("How Many Keys Do You Want To Generate?");

	FillArrayWithKeys(arr, NumberOfArrays);
	PrintStringArray(arr, NumberOfArrays);

	return 0;
}


//both are the same;