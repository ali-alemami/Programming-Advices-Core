#include <iostream>
#include <string>
#include<cctype>

using namespace std;

string ReadString()
{
	string S1 = "";
	cout << "Enter your string?\n";
	getline(cin, S1);
	return S1;
}

string UppercaseFirstLetterOfEachWord(string S1)
{
	bool isFirstLetter = true;

	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && isFirstLetter)
		{
			S1[i] = toupper(S1[i]);
		}
		isFirstLetter = (S1[i] == ' ' ? true : false);
	}
	return S1;
}

int main()
{
	string S1 = ReadString();
	S1 = UppercaseFirstLetterOfEachWord(S1);
	
	cout << S1 << endl;

	system("pause>0");
}