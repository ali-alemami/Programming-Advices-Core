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
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
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

void Sum2arrays(int arr[100], int arr2[100], int arr3[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		arr3[i] = arr[i] + arr2[i];
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arr2[100], arr3[100],
		ArrayLength = ReadPositiveNumber("How many elements\n");

	FillArrayWithRandomNumbers(arr, ArrayLength);
	FillArrayWithRandomNumbers(arr2, ArrayLength);

	Sum2arrays(arr, arr2, arr3, ArrayLength);


	cout << "Array 1 elements :\n";
	PrintArray(arr, ArrayLength);

	cout << "Array 2 elements :\n";
	PrintArray(arr2, ArrayLength);

	cout << "Array 3 elements :\n";
	PrintArray(arr3, ArrayLength);

	return 0;
}