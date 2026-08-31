#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadStrig()
{
	string S1 = "";
	cout << "Enter your string?\n";
	getline(cin, S1);
	return S1;
}

bool IsVowel(char Char1)
{
	Char1 = tolower(Char1);

	return ((Char1 == 'a') || (Char1 == 'e') || (Char1 == 'i') || (Char1 == 'o') || (Char1 == 'u'));
}

short CountVowelsInString(string S1)
{
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (IsVowel(S1[i]))
			Counter++;
	}
	return Counter;
}

int main()
{
	string S1 = ReadStrig();

	cout << "\nNumber of vowels is: " << CountVowelsInString(S1) << endl;

	system("pause>0");
}