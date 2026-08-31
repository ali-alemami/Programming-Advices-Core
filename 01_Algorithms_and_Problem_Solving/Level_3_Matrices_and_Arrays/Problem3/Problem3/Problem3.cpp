#include <iostream>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "    ";
		}
		cout << "\n";
	}
}

int RowSum(int arr[3][3], short RowNumber, short Cols)
{
	int Sum = 0;

	for (short i = 0; i < Cols; i++)
	{
		Sum += arr[RowNumber][i];
	}
	return Sum;
}

void PrintEachRowSum(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		cout << "Row " << i + 1 << " Sum = " << RowSum(arr, i, Cols) << "\n";
	}
}

void FillArrayWithMatrixRowSum(int arrSum[3], int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		arrSum[i] = RowSum(arr, i, Cols);
	}
}

void PrintArray(int arr[3], int ArrayLength)
{
	for (short i = 0; i < ArrayLength; i++)
	{
		cout << setw(3) << arr[i] << "    ";
	}
	cout << "\n";
}

int main()
{
	int arr[3][3], arrSum[3];

	FillMatrixWithRandomNumbers(arr, 3, 3);

	cout << "The following is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);

	cout << "The following are the sum of each row in the matrix:\n";
	PrintEachRowSum(arr, 3, 3);

	cout << "\nThe following is an array with 3x3 matrix sum:\n";
	FillArrayWithMatrixRowSum(arrSum, arr, 3, 3);
	PrintArray(arrSum, 3);

	system("pause>0");
}