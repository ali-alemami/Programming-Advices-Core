#include <iostream>
using namespace std;

void FillArray(int arr[100], int& ArrayLength)
{
	ArrayLength = 6;

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 30;
	arr[4] = 20;
	arr[5] = 10;
}

void PrintArray(int arr[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

bool IsArrayPalidnrome(int arr[100], int ArrayLength)
{
	int M = floor(ArrayLength / 2);

	for (int i = 0; i <= M; i++)
	{
		if (arr[i] != arr[ArrayLength - 1 - i])
			return false;
	}
	return true;
}

int main()
{
	int arr[100], ArrayLength = 0;

	FillArray(arr, ArrayLength);

	cout << "Array elements :\n";
	PrintArray(arr, ArrayLength);

	if (IsArrayPalidnrome(arr, ArrayLength))
		cout << "\n\nYes, Array is palindrome\n\n";
	else
		cout << "\n\nNo, Array is NOT palindrome\n\n";
	
	return 0;
}