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
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf("%0*d    ", 2, arr[i][j]);
		}
		cout << "\n";
	}
}

void Multiply2Matrices(int arr1[3][3], int arr2[3][3], int arrMult[3][3],
	short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arrMult[i][j] = arr1[i][j] * arr2[i][j];
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3], arr2[3][3], arrMult[3][3];

	FillMatrixWithRandomNumbers(arr1, 3, 3);
	FillMatrixWithRandomNumbers(arr2, 3, 3);

	cout << "\nMatrix1:\n";
	PrintMatrix(arr1, 3, 3);

	cout << "\nMatrix2:\n";
	PrintMatrix(arr2, 3, 3);

	Multiply2Matrices(arr1, arr2, arrMult, 3, 3);

	cout << "\nResults:\n";
	PrintMatrix(arrMult, 3, 3);

	system("pause>0");
}