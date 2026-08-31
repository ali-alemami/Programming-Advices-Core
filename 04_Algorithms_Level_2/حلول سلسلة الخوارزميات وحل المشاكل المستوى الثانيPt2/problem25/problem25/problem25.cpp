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

int MinNumberInArray(int arr[100], int ArrayLength)
{
	int Min = arr[0];

	for (int i = 0; i < ArrayLength; i++)
	{
		if (arr[i] < Min)
			Min = arr[i];
	}
	return Min;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength;

	FillArrayWithRandomNumbers(arr, ArrayLength);
	PrintArray(arr, ArrayLength);

	cout << "\n\nMin number is " <<
		MinNumberInArray(arr, ArrayLength) << endl;

	return 0;
}