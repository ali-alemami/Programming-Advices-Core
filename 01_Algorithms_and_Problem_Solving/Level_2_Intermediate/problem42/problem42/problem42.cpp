#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}

void FillArrayWithRandomNumbers(int arr[100], int& ArrayLength)
{
	cout << "How many elements? ";
	cin >> ArrayLength;

	for (int i = 0; i < ArrayLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int arr[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

bool IsOdd(int Number)
{
	if (Number % 2 != 0)
		return true;
	else
		return false;
}

int CountOddNumbersInArray(int arr[100], int ArrayLength)
{
	int Counter = 0;

	for (int i = 0; i < ArrayLength; i++)
	{
		if (IsOdd(arr[i]))
		{
			Counter++;
		}
	}
	return Counter;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength = 0;

	FillArrayWithRandomNumbers(arr, ArrayLength);
	PrintArray(arr, ArrayLength);

	cout << "\n\nOdd number count is " << CountOddNumbersInArray(arr, ArrayLength) << endl << endl;

	return 0;
}