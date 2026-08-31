#include <iostream>
using namespace std;

void AddArrayELement(int arr[100], int& ArrayLength, int Number)
{
	ArrayLength++;
	arr[ArrayLength - 1] = Number;
}

int FindNumberInArray(int arr[100], int ArrayLength, int NumberToSearch)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		if (arr[i] == NumberToSearch)
		{
			return NumberToSearch;
		}
	}
	return -1;
}

bool IsNumberInArray(int arr[100], int ArrayLength, int NumberToSearch)
{
	return FindNumberInArray(arr, ArrayLength, NumberToSearch) != -1;
}

void CopyArrayDistinctELements(int arr[100], int ArrayLength, int arr2[100], int& Array2Length)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		if (!IsNumberInArray(arr2, ArrayLength, arr[i]))
		{
			AddArrayELement(arr2, Array2Length, arr[i]);
		}
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

int main()
{
	int arr[] = { 10,10,10,50,50,70,70,70,70,90 };
	int ArrayLength = 10;

	int arr2[100], Array2Length = 0;

	CopyArrayDistinctELements(arr, ArrayLength, arr2, Array2Length);

	PrintArray(arr, ArrayLength);

	PrintArray(arr2, Array2Length);

	return 0;
}