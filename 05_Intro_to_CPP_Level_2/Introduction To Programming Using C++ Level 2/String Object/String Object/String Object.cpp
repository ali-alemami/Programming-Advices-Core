#include <iostream>
using namespace std;

int main()
{
	string S1 = "My Name is Ali, I Love Programming.";

	cout << S1.length() << endl;

	cout << S1.at(11) << endl;

	S1.append(" Very Much.");
	cout << S1 << endl;

	S1.insert(13, " Ali");
	cout << S1 << endl;

	cout << S1.substr(11, 3) << endl;

	S1.push_back('X');
	cout << S1 << endl;
	
	S1.pop_back();
	cout << S1 << endl;

	cout << S1.find("Ali") << endl;

	cout << S1.find("nani!!!") << endl;

	if (S1.find("nani!!!") == S1.npos)
	{
		cout << "not found\n";
	}

	S1.clear();

	cout << S1 << endl;

	return 0;
}