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

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

void FillArrayFrom1ToNumber(int arr[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
		arr[i] = i + 1;
}

void Swap(int& A, int& B)
{
	int temp;

	temp = A;
	A = B;
	B = temp;
}

void ShufleArray(int arr[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		Swap(arr[RandomNumber(0, ArrayLength - 1)], arr[RandomNumber(0, ArrayLength - 1)]);
	}
	cout << endl;
}

void PrintArray(int arr[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100],
		ArrayLength = ReadPositiveNumber("How many elements?");

	FillArrayFrom1ToNumber(arr, ArrayLength);

	cout << "\nArray elements before shufle :\n";
	PrintArray(arr, ArrayLength);

	ShufleArray(arr, ArrayLength);

	cout << "\nArray elements after shufle :\n";
	PrintArray(arr, ArrayLength);

	cout << endl << endl;

	return 0;

}