#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
	string S1 = "";
	cout << "Enter string\n";
	getline(cin, S1);
	return S1;
}

string RemovePunctInString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		if (ispunct(S1[i]) != 0)
		{
			S1.erase(i, 1);
			i--;
		}
	}
	return S1;
}

string RemovePunctInString2(string S1)
{
	string S2 = "";

	for (short i = 0; i < S1.length(); i++)
	{
		if (!ispunct(S1[i]))
		{
			S2 += S1[i];
		}
	}

	return S2;
}

int main()
{
	string S1 = ReadString();

	cout << "Original string:\n";
	cout << S1 << endl;

	cout << "\nPuncts removed:\n";
	cout << RemovePunctInString2(S1) << endl;

	system("pause>0");
}