#include <iostream>
#include <vector>

using namespace std;

void ReadVectorElements(vector <int> &vNumbers)
{
	char AddMore = 'y';
	int Number = 0;

	do
	{
		cout << "Add Vector Element: ";
		cin >> Number;

		vNumbers.push_back(Number);

		cout << "\nDo you want to add more numbers (Y/N) ? ";
		cin >> AddMore;
		cout << endl;
	} while (AddMore == 'Y' || AddMore == 'y');
}

void PrintVectorElements(vector <int> &vNumbers)
{
	for (int &Number : vNumbers)
	{
		cout << Number << " ";
	}
	cout << endl;
}

int main()
{
	vector <int> vNumbers;
	ReadVectorElements(vNumbers);
	PrintVectorElements(vNumbers);

	return 0;
}