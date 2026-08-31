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

	cout << endl;

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
	cout << "\n\n";
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

void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int ArrayLength, int& ArrayDestinationLength)
{
	int Counter = 0;

	for (int i = 0; i < ArrayLength; i++)
	{
		if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
		{
			arrDestination[Counter] = arrSource[i];
			Counter++;
		}
	}
	ArrayDestinationLength = Counter;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arr2[100],
		ArrayLength, Array2Length = 0;

	FillArrayWithRandomNumbers(arr, ArrayLength);

	CopyPrimeNumbers(arr, arr2, ArrayLength, Array2Length);

	cout << "Array 1 elements \n";
	PrintArray(arr, ArrayLength);

	cout << "Prime numbers in array 2 \n";
	PrintArray(arr2, Array2Length);

	return 0;
}