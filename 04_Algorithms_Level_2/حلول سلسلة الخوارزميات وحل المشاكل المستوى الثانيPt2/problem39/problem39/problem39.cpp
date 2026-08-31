#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}

void FillArrayWithRandomNumbers(int arr[100], int& ArrayLength)
{
	cout << "How many elements? ";
	cin >> ArrayLength;

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

void AddArrayELement(int arr[100], int& ArrayLength, int Number)
{
	ArrayLength++;
	arr[ArrayLength - 1] = Number;
}

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

enPrimeNotPrime CheckPrime(int Number)
{
	int M = floor(Number / 2);

	for (int i = 2; i <= M; i++)
	{
		if (Number % i == 0)
			return enPrimeNotPrime::NotPrime;
	}
	return enPrimeNotPrime::Prime;
}

void CopyArrayPrimeNumbers(int arr[100], int ArrayLength, int arr2[100], int &Array2Length)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		if (CheckPrime(arr[i]) == enPrimeNotPrime::Prime)
		{
			AddArrayELement(arr2, Array2Length, arr[i]);
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength = 0, arr2[100], Array2Length = 0;

	FillArrayWithRandomNumbers(arr, ArrayLength);

	CopyArrayPrimeNumbers(arr, ArrayLength, arr2, Array2Length);

	cout << "\nArray 1 elements :\n";
	PrintArray(arr, ArrayLength);

	cout << "\nArray 2 Prime Numbers :\n";
	PrintArray(arr2, Array2Length);

	cout << endl;

	return 0;
}