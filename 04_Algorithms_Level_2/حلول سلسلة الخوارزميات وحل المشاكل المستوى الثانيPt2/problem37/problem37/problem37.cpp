#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;
	cout << "Enter a number\n";
	cin >> Number;
	return Number;
}

void AddArrayElement(int arr[100], int& ArrayLength, int Number)
{
	ArrayLength++;
	arr[ArrayLength - 1] = Number;
}

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}

void FillArrayWithRandomNumbers(int arr[100], int& ArrayLength)
{
	cout << "How many elements in the array?  ";
	cin >> ArrayLength;

	for (int i = 0; i < ArrayLength; i++)
		arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << arr[i] << " ";
	}
}

void CopyArrayUsingAddArrrayElement(int arr[100], int ArrayLength, int arr2[100], int& Array2Length)
{
	for (int i = 0; i < ArrayLength; i++)
		AddArrayElement(arr2, Array2Length, arr[i]);
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arr2[100], ArrayLength, Array2Length = 0;

	FillArrayWithRandomNumbers(arr, ArrayLength);

	cout << "\nArray elements :\n";
	PrintArray(arr, ArrayLength);

	CopyArrayUsingAddArrrayElement(arr, ArrayLength, arr2, Array2Length);

	cout << "\n\nArray 2 elements after copy :\n";
	PrintArray(arr2, Array2Length);

	cout << endl << endl;

	return 0;
}