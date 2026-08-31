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
			printf(" %0*d    ", 2, arr[i][j]);
		}
		cout << "\n";
	}
}

void PrintMiddleRowInMatrix(int arr[3][3], short Rows, short Cols)
{
	short M = Rows / 2;

	for (int i = 0; i < Cols; i++)
	{
		printf(" %0*d    ", 2, arr[M][i]);
	}
}

void PrintMiddleColInMatrix(int arr[3][3], short Rows, short Cols)
{
	short M = Cols / 2;

	for (short i = 0; i < Rows; i++)
	{
		printf(" %0*d    ", 2, arr[i][M]);
	}
	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];

	FillMatrixWithRandomNumbers(arr, 3, 3);

	cout << "\nMatrix1:\n";
	PrintMatrix(arr, 3, 3);

	cout << "\nMiddle row of Matrix1 is:\n";
	PrintMiddleRowInMatrix(arr, 3, 3);

	cout << "\nMiddle col of Matrix1 is:\n";
	PrintMiddleColInMatrix(arr, 3, 3);

	system("pause>0");
}