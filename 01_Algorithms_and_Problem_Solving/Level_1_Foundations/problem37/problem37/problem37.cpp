#include <iostream>
#include <string>

using namespace std;

int ReadNumber(string Message)
{
	int Number = 0;

	cout << Message << endl;
	cin >> Number;

	return Number;
}

int SumNumbers()
{
	int Number = 0, Sum = 0, Counter = 1;

	do
	{
		Number = ReadNumber("Enter number " + to_string(Counter));

		if (Number == -99)
			break;

		Sum += Number;
		Counter++;

	} while (Number != -99);

	return Sum;
}

int main()
{
	cout << "\nResult = " << SumNumbers() << endl;

	return 0;
}