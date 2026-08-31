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

int MaxInArray(int arr[100], int ArrayLength)
{
	int Max = 0;

	for (int i = 0; i < ArrayLength; i++)
	{
		if (arr[i] > Max)
			Max = arr[i];
	}

	return Max;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength;

	FillArrayWithRandomNumbers(arr, ArrayLength);

	cout << "\nArray Elements : ";
	PrintArray(arr, ArrayLength);

	cout << "\n\nMax number is " << MaxInArray(arr, ArrayLength) << endl;

	return 0;
}