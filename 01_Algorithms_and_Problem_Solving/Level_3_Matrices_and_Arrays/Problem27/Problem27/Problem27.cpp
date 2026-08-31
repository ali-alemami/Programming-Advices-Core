#include <iostream>
#include <cctype>

using namespace std;

char ReadChar()
{
	char C1 = ' ';

	cout << "Enter the character\n";
	cin >> C1;
	return C1;
}

char InvertCharacter(char C1)
{
	if (C1 == toupper(C1))
		return tolower(C1);
	else
		return toupper(C1);
}

char InvertCharacter2(char C1)
{
	return isupper(C1) ? tolower(C1) : toupper(C1);
}

int main()

{
	char C1 = ReadChar();

	C1 = InvertCharacter2(C1);

	cout << C1 << endl;

	system("pause>0");
}