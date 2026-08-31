#include <iostream>
#include <string>

using namespace std;

int main()
{
	string st1, st2, st3;


	cout << "please enter string 1\n";
	getline(cin, st1);

	cout << "\nplease enter string 2\n";
	cin >> st2;

	cout << "\nplease enter string 3\n";
	cin >> st3;

	cout << "**************************************\n";

	cout << "the length of string 1 is " << st1.length() << endl;
	cout << "characters 0, 2, 4, 7 are: " << st1[0] << " " << st1[2] << " " << st1[4] << " " << st1[7] << endl;
	cout << "concatenating string2 and string3 = " << st2 + st3 << endl;

	int multi = stoi(st2) * stoi(st3);
	cout << st2 << " * " << st3 << " = " << multi;

	return 0;
}