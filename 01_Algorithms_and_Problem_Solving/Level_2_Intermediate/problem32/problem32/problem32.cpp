#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}

void FillArrayWithRandomNumbers(int arr[100], int ArrayLength)
{
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
	cout << endl << endl;
}

void ReverseArray(int arr[100], int ArrayLength, int arr2[100])
{
	for (int i = 0; i < ArrayLength; i++)
	{
		arr2[i] = arr[ArrayLength - 1 - i];
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength = ReadPositiveNumber("How many elements?");
	int arr2[100];

	FillArrayWithRandomNumbers(arr, ArrayLength);
	cout << "Array 1 elements :\n";
	PrintArray(arr, ArrayLength);

	ReverseArray(arr, ArrayLength, arr2);

	cout << "Array 2 elements after copy :\n";
	PrintArray(arr2, ArrayLength);

	return 0;
}