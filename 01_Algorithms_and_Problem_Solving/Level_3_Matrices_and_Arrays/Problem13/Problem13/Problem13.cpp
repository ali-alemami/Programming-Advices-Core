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
			printf(" %0*d   ", 1, arr[i][j]);
		}
		cout << "\n";
	}
}

bool IsTheMatrixIdentity(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j)
			{
				if (arr[i][j] != 1)
					return false;
			}
			else
			{
				if (arr[i][j] != 0)
					return false;
			}
		}
	}
	return true;
}

bool IsTheMatrixIdentity2(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && arr[i][j] != 1)
				return false;

			else if (i != j && arr[i][j] != 0)
				return false;
		}
	}
	return true;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];

	int Matrix2[3][3] = { {1,0,0},
						  {0,1,0},
						  {0,0,1} };

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix2, 3, 3);

	if (IsTheMatrixIdentity2(Matrix2, 3, 3))
	{
		cout << "\nMatrix is identity.\n";
	}
	else
	{
		cout << "\nMatrix is NOT identity.\n";
	}

	system("pause>0");
}