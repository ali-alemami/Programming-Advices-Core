#include <iostream>
using namespace std;

int ReadNumberInRange(int From, int To)
{
	int Grade;

	do
	{
		cout << "Enter a number from 0 to 100 " << endl;
		cin >> Grade;

	} while (Grade < From || Grade > To);

	return Grade;
}

char GetMark(int Grade)
{
	if (Grade >= 90)
	{
		return 'A';
	}
	else if (Grade >= 80)
	{
		return 'B';
	}
	else if (Grade >= 70)
	{
		return 'C';
	}
	else if (Grade >= 60)
	{
		return 'D';
	}
	else if (Grade >= 50)
	{
		return 'E';
	}
	else
		return 'F';
}

int main()
{
	cout << GetMark(ReadNumberInRange(0, 100)) << endl;

	return 0;
}