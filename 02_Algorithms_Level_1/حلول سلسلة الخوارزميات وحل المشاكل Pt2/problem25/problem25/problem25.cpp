#include <iostream>
using namespace std;

int ReadAge()
{
	int Age;

	cout << "Enter your age ";
	cin >> Age;

	return Age;
}

bool ValidateNumberInRange(int Number, int From, int To)
{
	return(Number >= From && Number <= To);
}

int ReadUntilAgeBetween(int From, int To)
{
	int Age = 0;
	do
	{
		Age = ReadAge();
	} while (!ValidateNumberInRange(Age, 18, 45));

	return Age;
}

void PrintResult(int Age)
{
	cout << Age << "\n is a valid age " << endl;
}

int main()
{
	PrintResult(ReadUntilAgeBetween(18, 45));

	return 0;
}

