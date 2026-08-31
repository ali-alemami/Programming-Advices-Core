#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string ReadString()
{
	string S1 = "";

	cout << "Enter the string\n";
	getline(cin, S1);
	return S1;
}

enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

int CountLetters(string S1, enWhatToCount WhatToCount = All)
{
	if (WhatToCount == enWhatToCount::All)
	{
		return S1.length();
	}

	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
		{
			Counter++;
		}

		if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
		{
			Counter++;
		}
	}

	return Counter;
}

short CapitalLettersCount(string S1)
{
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]))
		{
			Counter++;
		}
	}
	return Counter;
}

short SmallLetterCount(string S1)
{
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (islower(S1[i]))
		{
			Counter++;
		}
	}
	return Counter;
}

int main()
{
	string S1 = ReadString();

	cout << "String Length = " << S1.length() << endl;
	cout << "Capital Letters Count = " << CapitalLettersCount(S1) << endl;
	cout << "Small Letters Count = " << SmallLetterCount(S1) << endl;

	cout << "\n\n\nNew Method\n\n";

	cout << "String Length = " << CountLetters(S1) << endl;
	cout << "Capital Letters Count = " << CountLetters(S1, CapitalLetters) << endl;
	cout << "Capital Letters Count = " << CountLetters(S1, SmallLetters) << endl;


	system("pause>0");
}