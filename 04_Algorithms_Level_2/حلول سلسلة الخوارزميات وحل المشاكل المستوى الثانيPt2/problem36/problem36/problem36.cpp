#include <iostream>
using namespace std;

void FillArray(int arr[100], int& ArrayLength)
{
	int Answer = 0, Number;

	do
	{
		cout << "\nPlease enter a number?  ";
		cin >> Number;

		cout << "\nDo you want to add more numbers? [0]:No, [1]:Yes?  ";
		cin >> Answer;

		ArrayLength++;
		arr[ArrayLength - 1] = Number;
	} while (Answer == 1);
}

void PrintArray(int arr[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[100], ArrayLength = 0;

	FillArray(arr, ArrayLength);

	cout << "\nArray length: " << ArrayLength << endl;
	cout << "\nArray elements: ";
	PrintArray(arr, ArrayLength);

	return 0;
}