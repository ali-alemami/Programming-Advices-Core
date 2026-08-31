#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
	string S1 = "";
	cout << "Enter your string\n";
	getline(cin, S1);
	return S1;
}

string TrimRight(string S1)
{
	for (short i = S1.length() - 1; i >= 0; i--)
	{
		if (S1[i] != ' ')
		{
			return S1;
		}

		while (S1[i] == ' ')
		{
			S1.erase(i, 1);
		}
	}
	return S1;
}

string TrimLeft(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ')
		{
			return S1;
		}
		while (S1[i] == ' ')
		{
			S1.erase(i, 1);
		}
	}
	return S1;
}

string Trim(string S1)
{
	S1 = TrimRight(S1);
	S1 = TrimLeft(S1);

	return S1;
}

int main()
{
	string S1 = ReadString();

	S1 = Trim(S1);

	cout << S1 << endl;
}