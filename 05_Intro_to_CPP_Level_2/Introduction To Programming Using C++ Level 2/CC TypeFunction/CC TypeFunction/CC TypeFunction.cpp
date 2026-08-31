#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	char x;
	char y;

	x = tolower('A');
	y = toupper('a');

	cout << x << endl;
	cout << y << endl;

	cout << isupper('A') << endl;;
	cout << islower('a') << endl;

	cout << isdigit('9') << endl;

	cout << ispunct(';') << endl;

	return 0;
}