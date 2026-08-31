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

	for (int i = 0; i < Cols; i++)
	{
		Sum += arr[RowNumber][i];
	}
	return Sum;
}

void SumMatrixRowsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		arrSum[i] =  RowSum(arr, i, Cols);
	}
}

void PrintRowsSumInArray(int arr[3], short Rows)
{
	for (short i = 0; i < Rows; i++)
	{
		cout << "Row " << i + 1 << " Sum = " << arr[i] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3], arrSum[3];

	FillMatrixWithRandomNumbers(arr, 3, 3);
	PrintMatrix(arr, 3, 3);

	SumMatrixRowsInArray(arr, arrSum, 3, 3);

	PrintRowsSumInArray(arrSum, 3);

	system("pause>0");
}