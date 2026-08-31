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

void ReadArray(int arr[100], int& ArrayLength)
{
	cout << "\nEnter Number of elements\n";
	cin >> ArrayLength;

	cout << "\nEnter array elements\n";

	for (int i = 0; i < ArrayLength; i++)
	{
		cout << "Element [" << i + 1 << "] : ";
		cin >> arr[i];
	}
	cout << endl;
}

void PrintArray(int arr[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int TimesRepeated(int arr[100], int ArrayLength, int NumberToCheck)
{
	int Counter = 0;

	for (int i = 0; i <= ArrayLength - 1; i++)
	{
		if (arr[i] == NumberToCheck)
			Counter++;
	}
	return Counter;
}

int main()
{
	int arr[100], ArrayLength, NumberToCheck;

	ReadArray(arr, ArrayLength);

	cout << "Original Array : ";
	PrintArray(arr, ArrayLength);

	NumberToCheck = ReadPositiveNumber("Enter the number you want to check");

	cout << endl << NumberToCheck << " is repeated " <<
		TimesRepeated(arr, ArrayLength, NumberToCheck) << " Time(s)\n\n";

	return 0;
}