#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;

	return RandNumber;
}

void FillArrayWithRandomNumbers(int arr[100], int& ArrayLength)
{
	cout << "Enter elements number\n";
	cin >> ArrayLength;

	for (int i = 0; i < ArrayLength; i++)
	{
		arr[i] = RandomNumber(0, 100);
	}
}

void PrintArray(int arr[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << arr[i] << " ";
	}
}

void CopyArray(int arrSource[100], int arrDestination[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		arrDestination[i] = arrSource[i];
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength, arr2[100];

	FillArrayWithRandomNumbers(arr, ArrayLength);

	CopyArray(arr, arr2, ArrayLength);

	PrintArray(arr, ArrayLength);
	cout << "\n\n";

	cout << "Array 2 After copy \n";
	PrintArray(arr2, ArrayLength);

	return 0;
}