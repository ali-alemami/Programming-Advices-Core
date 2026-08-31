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

void ReadArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << "Element [" << i + 1 << "] : ";
		cin >> arr[i];
	}
	cout << endl;
}

int CheckRepeatedNumber(int arr[100], int Length)
{
	int Counter = 0;

	int Number = ReadPositiveNumber("Enter the number you want to check ");

	for (int i = 0; i < Length; i++)
	{
		if (arr[i] == Number)
			Counter++;
	}
	return Counter;
}

void PrintArray(int arr[100], int Length)
{
	cout << "Original Array : ";
	for (int i = 0; i < Length; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	int Number = ReadPositiveNumber("Enter Array elements");
	int arr[100];

	ReadArray(arr, Number);

	cout << "Number is repeated " <<
		CheckRepeatedNumber(arr, Number) << " Time(s)\n\n";

	PrintArray(arr, Number);

	return 0;
}