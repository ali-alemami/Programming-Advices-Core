#include <iostream>
#include <vector>

using namespace std;

string JoinString(vector <string> vString, string Delim)
{
	string S1 = "";

	for (string& n : vString)
	{
		S1 += n + Delim;
	}

	S1 = S1.substr(0, S1.length() - Delim.length());

	return S1;
}

string JoinString(string arr[10], short ArrayLength, string Delim)
{
	string S1 = "";

	for (short i = 0; i < ArrayLength; i++)
	{
		S1 += arr[i] + Delim;
	}

	S1 = S1.substr(0, S1.length() - Delim.length());

	return S1;
}

int main()
{
	vector <string> vString = { "Mohammad", "Fadi", "Ali", "Maher" };
	string arr[] = { "Mohammad", "Fadi", "Ali", "Maher" };

	cout << "\nVector after join:\n";
	cout << JoinString(vString, ",");
	cout << endl;
	cout << "\nArray after join:\n";
	cout << JoinString(arr, 4, ",");

	system("pause>0");
}