#include <iostream>
#include <vector>
#include <string>

using namespace std;

string JoinString(vector <string> vString, string Delim)
{
	string Word = "";

	for (string& n : vString)
	{
		Word += n + Delim;
	}
	Word = Word.substr(0, Word.length() - Delim.length());

	return Word;
}

int main()
{
	vector <string> vString = { "Mohammad", "Fadi", "Ali", "Maher" };

	cout << "\nVector after join:\n";
	string S1 = JoinString(vString, "###");

	cout << S1;

	system("pause>0");
}