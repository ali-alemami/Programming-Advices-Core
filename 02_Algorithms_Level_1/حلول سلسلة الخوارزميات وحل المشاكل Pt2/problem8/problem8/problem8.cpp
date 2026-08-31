#include <iostream>
using namespace std;

enum enMark { Pass = 1, Fail = 2 };

int ReadNumber()
{
	int Number;

	cout << "Enter a mark ";
	cin >> Number;

	return Number;
}

enMark CheckMark(int Mark)
{
	if (Mark >= 50)
	{
		return enMark::Pass;
	}
	else
	{
		return enMark::Fail;
	}
}

void PrintMark(int Mark)
{
	if (CheckMark(Mark) == enMark::Pass)
	{
		cout << "PASS";
	}
	else
		cout << "FAIL";
}

int main()
{
	PrintMark(ReadNumber());

	return 0;
}