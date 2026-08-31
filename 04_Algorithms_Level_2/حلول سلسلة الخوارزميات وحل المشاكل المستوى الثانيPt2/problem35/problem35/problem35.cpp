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

int FindNumberPositionInArray(int arr[100], int ArrayLength, int NumberToSearch)
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
	return FindNumberPositionInArray(arr, ArrayLength, NumberToSearch) != -1;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength = ReadPositiveNumber("How many elements?");

	FillArrayWithRandomNumbers(arr, ArrayLength);
	PrintArray(arr, ArrayLength);

	int NumberToSearch = ReadPositiveNumber("Enter the number you are looking for");

	cout << "The Number you are looking for is " << NumberToSearch << endl;

	if (IsNumberInArray(arr, ArrayLength, NumberToSearch))
		cout << "Yes, The Number is found ;-)\n\n";
	else
		cout << "No, The Number is NOT found :o\n\n";

	return 0;
}