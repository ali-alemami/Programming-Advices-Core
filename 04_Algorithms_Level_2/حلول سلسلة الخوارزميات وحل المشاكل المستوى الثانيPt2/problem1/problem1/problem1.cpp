#include <iostream>
using namespace std;

void PrintTitle()
{
	cout << "\t\t\t\t     Multiplication Table From 1 to 10\n\n";
}

void PrintHeader()
{
	PrintTitle();

	cout << "\t\t";
	cout << "       ";

	for (int i = 1; i <= 10; i++)
	{
		cout << i << "\t";
	}
	cout << "\n";
	cout << "\t\t__________________________________________________________________________________\n";
}

string ColumnSeperator(int i)
{
	if (i < 10)
		return "   |  ";
	else
		return "  |  ";
}

void PrintMultiplicationTable()
{
	PrintHeader();

	for (int i = 1; i <= 10; i++)
	{
		cout << "\t\t";
		cout << i << ColumnSeperator(i);

		for (int j = 1; j <= 10; j++)
		{
			cout << i * j << "\t";
		}
		cout << endl;
	}
}

int main()
{
	PrintMultiplicationTable();

	return 0;
}