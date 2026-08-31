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

int EvenCount(int arr[100], int ArrayLength)
{
	int Counter = 0;

	for (int i = 0; i < ArrayLength; i++)
	{
		if (arr[i] % 2 == 0)
			Counter++;
	}
	return Counter;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength = 0;


	FillArrayWithRandomNumbers(arr, ArrayLength);
	cout << endl;
	PrintArray(arr, ArrayLength);

	cout << "\n\nEven numbers count is : " << EvenCount(arr, ArrayLength) << endl << endl;
	
	return 0;
}