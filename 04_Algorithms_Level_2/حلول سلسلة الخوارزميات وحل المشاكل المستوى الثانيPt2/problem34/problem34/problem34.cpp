#include<iostream>
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
	cout << endl;
}

int FindNumberPositionInArray(int arr[100], int ArrayLength, int Number)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		if (arr[i] == Number)
		{
			cout << "The Number you are looking for is " << Number << endl;
			cout << "The Number found at position " << i << endl;
			cout << "The Number found order is " << i + 1 << endl;
			return 0;
		}
	}
	cout << "The Number you are looking for is : " << Number << endl;
	cout << "The Number is not found :(\n";
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength = ReadPositiveNumber("How many elements in the array?");

	FillArrayWithRandomNumbers(arr, ArrayLength);
	PrintArray(arr, ArrayLength);

	int NumberToSearch = ReadPositiveNumber("Enter the number you are looking for");

	FindNumberPositionInArray(arr, ArrayLength, NumberToSearch);

	return 0;
}