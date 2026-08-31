#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;
	cout << "\nPlease enter a number? ";
	cin >> Number;
	return Number;
}

void PrintArray(int arr[100], int arrLength)
{ 
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

void AddArrayElement(int arr[100], int& ArrayLength, int Number)
{
	ArrayLength++;
	arr[ArrayLength - 1] = Number;
}

void InputUserNumbersInArray(int arr[100], int& ArrayLength)
{
	bool addMore = true;
	do
	{
		AddArrayElement(arr, ArrayLength, ReadNumber());

		cout << "\nDo you want to add more numbers? [0]:No, [1]:Yes?  ";
		cin >> addMore;

	} while (addMore == true);
}

int main()
{
	int arr[100], ArrayLength = 0;

	InputUserNumbersInArray(arr, ArrayLength);
	cout << "\n\nArray length = " << ArrayLength << endl;

	cout << "\nArray elements : ";
	PrintArray(arr, ArrayLength);

	return 0;
}