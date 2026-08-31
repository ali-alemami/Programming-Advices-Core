#include <iostream>
#include <string>
using namespace std;
int main()
{
	string string1, string2, string3;

	cout << "pleae enter string1\n";
	getline(cin, string1);
	
	cout << "please enter string2\n";
	cin >> string2;
	
	cout << "please enter string3\n";
	cin >> string3;



	cout << "************************************\n";
	cout << "the length of string1 is " << string1.length() << endl;
	cout << string1[0] << endl << string1[2] << endl << string1[5] << endl;
	cout << string2 + string3 << endl;
	int sum = stoi(string2) * stoi(string3);
	cout << sum << endl;
}