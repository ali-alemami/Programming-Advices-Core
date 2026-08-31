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

int SumArray(int arr[100], int ArrayLength)
{
	int Sum = 0;

	for (int i = 0; i < ArrayLength; i++)
	{
		Sum += arr[i];
	}

	return Sum;
}

float AvgOfArray(int arr[100], int ArrayLength)
{
	return (float) SumArray(arr, ArrayLength) / ArrayLength;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength;

	FillArrayWithRandomNumbers(arr, ArrayLength);
	PrintArray(arr, ArrayLength);
	cout << "\n\n";

	cout << "Average is " << AvgOfArray(arr, ArrayLength);

	return 0;
}