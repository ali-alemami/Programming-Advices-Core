#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
	string S1 = "";
	cout << "Enter your string?\n";
	getline(cin, S1);
	return S1;
}

void PrintEachWordInString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ')
		{
			cout << S1[i];
		}
		if (S1[i] == ' ' && S1[i + 1] != ' ')
		{
			cout << "\n";
		}
	}
}

int main()
{
	string S1 = ReadString();

	PrintEachWordInString(S1);

	system("pause>0");
}