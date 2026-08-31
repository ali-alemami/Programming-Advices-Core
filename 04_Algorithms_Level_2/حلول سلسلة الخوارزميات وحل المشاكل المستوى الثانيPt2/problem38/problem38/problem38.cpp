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

void AddArrayElement(int arr[100], int &ArrayLength, int Number)
{
	ArrayLength++;
	arr[ArrayLength - 1] = Number;
}

bool CheckOddNumber(int Number)
{
	return Number % 2 != 0;
}

void CopyArrayOddNumbersUsingAddArrayElements(int arr[100], int ArrayLength, int arr2[100], int& Array2Length)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		if (CheckOddNumber(arr[i]))
		{
			AddArrayElement(arr2, Array2Length, arr[i]);
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength = 0, arr2[100], Array2Length = 0;

	FillArrayWithRandomNumbers(arr, ArrayLength);

	CopyArrayOddNumbersUsingAddArrayElements(arr, ArrayLength, arr2, Array2Length);

	PrintArray(arr, ArrayLength);
	PrintArray(arr2, Array2Length);

	return 0;
}