#include <iostream>
#include <vector>
#include <string>

using namespace std;

string ReadString(string Message)
{
	string Sentence = "";

	cout << Message << endl;
	getline(cin, Sentence);
	return Sentence;
}

void PrintFirstLetterOfEachWord(string Sentence)
{
	cout << Sentence.at(0) << endl;
	
	for (short i = 0; i < Sentence.length(); i++)
	{
		if (Sentence[i] == ' ')
		{
			cout << Sentence[i + 1] << endl;
		}
	}
}

void PrintFirstLetterOfEachWord2(string S1)
{
	bool isFirstLetter = true;

	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && isFirstLetter)
		{
			cout << S1[i] << endl;
		}
		isFirstLetter = (S1[i] == ' ' ? true : false);
	}
}

int main()
{
	string Sentence = ReadString("\nEnter your string?\n");

	cout << "\n\nFirst letters of this string:\n";

	PrintFirstLetterOfEachWord2(Sentence);

	system("pause>0");
}