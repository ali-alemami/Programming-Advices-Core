#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Enter a number ";
	cin >> Number;

	return Number;
}

void PrintFrom1ToNFor(int Number)
{
	for (int i = 1; i <= Number; i++)
	{
		cout << i << endl;
	}
}

void PrintFrom1ToNWhile(int Number)
{
	int i = 1;
	
	while (i <= Number)
	{
		cout << i << endl;
		i++;
	}
}

void PrintFrom1ToNDoWhile(int Number)
{
	int i = 1;

	do
	{
		cout << i << endl;
		i++;
	} while (i <= Number);
}

int main()
{
	PrintFrom1ToNDoWhile(ReadNumber());

	return 0;
}