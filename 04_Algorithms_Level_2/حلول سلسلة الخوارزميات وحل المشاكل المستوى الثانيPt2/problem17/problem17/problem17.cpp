#include <iostream>
using namespace std;

string ReadPassword()
{
	string Password = "";

	cout << "Enter a 3-Letter Password (all capital)\n ";
	cin >> Password;
	return Password;
}

bool Guess3LetterPassword(string Password)
{
	string word = "";
	int Counter = 0;

	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				Counter++;

				word += char(i);
				word += char(j);
				word += char(k);
				
				cout << "Trial [" << Counter << "] : " << word << endl;

				if (word == Password)
				{
					cout << "\n\nPassword is " << word << endl;
					cout << "Found after " << Counter << " Trial(s)\n\n";
					return true;
				}
				word = "";
				
			}
		}
	}
	return false;
}

int main()
{
	Guess3LetterPassword(ReadPassword());

	return 0;
}