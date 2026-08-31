#include <iostream>
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
			printf(" %0*d   ", 2, arr[i][j]);
		}
		cout << "\n";
	}
}

bool AreTheMatricesTypical(int arr1[3][3], int arr2[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (arr1[i][j] != arr2[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	FillMatrixWithRandomNumbers(Matrix2, 3, 3);

	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	if (AreTheMatricesTypical(Matrix1, Matrix2, 3, 3))
	{
		cout << "\nYes: matrices are typical.\n";
	}
	else
	{
		cout << "\nYes: matrices are NOT typical.\n";
	}
	system("pause>0");
}