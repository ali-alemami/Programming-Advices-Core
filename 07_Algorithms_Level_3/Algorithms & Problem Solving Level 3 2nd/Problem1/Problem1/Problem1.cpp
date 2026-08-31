#include <iostream>
#include <iomanip>

using namespace std;

short RandomNumber(short From, short To)
{
	short RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

void FillMatrixWithRandomNumbers(short arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(0, 10);
		}
	}
}

void PrintMatrix(short arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "\t";
		}
		cout << "\n";
	}
}

short RowSum(short arr[3][3], short RowNumber, short Cols)
{
	short Sum = 0;

	for (short j = 0; j <= Cols - 1; j++)
	{
		Sum += arr[RowNumber][j];
	}
	return Sum;
}

void PrintEachRowSum(short arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		cout << "Row " << i + 1 << " Sum = " << setw(3) << RowSum(arr, i, Cols) << "\n\n";
	}
}

void FillArrayWithRowsSum(short arr[3][3], short Rows, short Cols, short arr2[3])
{
	for (short i = 0; i < Rows; i++)
	{
		arr2[i] = RowSum(arr, i, Cols);
	}
}

void PrintArray(short arr[3], short ArrayLength)
{
	for (short i = 0; i < ArrayLength; i++)
	{
		cout << " Col " << i + 1 << " Sum = " << arr[i] << "\n\n";
	}
}

short ColSum(short arr[3][3], short Rows, short ColNumber)
{
	short Sum = 0;
	for (short i = 0; i < Rows; i++)
	{
		Sum += arr[i][ColNumber];
	}
	return Sum;
}

void PrintEachColumnSum(short arr[3][3], short Rows, short Cols)
{
	for (short j = 0; j < Cols; j++)
	{
		cout << " Col " << j + 1 << " Sum = " << setw(3) << ColSum(arr, Rows, j) << "\n\n";
	}
}

void SumMatrixColsInArray(short arr[3][3], short Rows, short Cols, short arrSum[3])
{
	for (short j = 0; j < Cols; j++)
	{
		arrSum[j] = ColSum(arr, Rows, j);
	}
}

void FillMatrixWithOrderedNumbers(short arr[3][3], short Rows, short Cols)
{
	short Counter = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			++Counter;
			arr[i][j] = Counter;
		}
	}
}

void TransposeMatrix(short arr[3][3], short Rows, short Cols, short arrTransPosed[3][3])
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arrTransPosed[i][j] = arr[j][i];
		}
	}
}

void MultiplyMatrices(short arr1[3][3], short arr2[3][3], short arrMul[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arrMul[i][j] = arr1[i][j] * arr2[i][j];
		}
	}
}

void PrintMatrixNewFormat(short arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf(" %0*d\t", 2, arr[i][j]);
			//cout << setw(3) << arr[i][j] << "\t";
		}
		cout << "\n";
	}
}

void PrintMiddleRowInMatrix(short arr[3][3], short Rows, short Cols)
{
	short MiddleRow = Rows / 2;

	for (short j = 0; j < Cols; j++)
	{
		printf(" %0*d\t", 2, arr[MiddleRow][j]);
	}
}

void PrintMiddleColInMatrix(short arr[3][3], short Rows, short Cols)
{
	short MiddleCol = Cols / 2;

	for (short i = 0; i < Rows; i++)
	{
		printf(" %0*d\t", 2, arr[i][MiddleCol]);
	}
}

short SumOfMatrix(short Matrix[3][3], short Rows, short Cols)
{
	short Sum = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Sum += Matrix[i][j];
		}
	}
	return Sum;
}

bool AreMatricesEqual(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Cols)
{
	return SumOfMatrix(Matrix1, 3, 3) == SumOfMatrix(Matrix2, 3, 3);
}

bool AreMatricesTypical(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] != Matrix2[i][j])
				return false;
		}
	}
	return true;
}

bool CheckIdentityMatrix(short Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && Matrix[i][j] != 1)
					return false;

			else if (i != j && Matrix[i][j] != 0)	
					return false;
		}
	}
	return true;
}

bool IsScalarMatrix(short Matrix[3][3], short Rows, short Cols)
{
	short FirstDiagElement = Matrix[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && Matrix[i][j] != FirstDiagElement)
				return false;
			else if (i != j && Matrix[i][j] != 0)
				return false;
		}
	}
	return true;
}

short CountNumberInMatrix(short Matrix[3][3], short Number, short Rows, short Cols)
{
	short Counter = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == Number)
			{
				++Counter;
			}
		}
	}
	return Counter;
}

short ReadNumber()
{
	short Number = 0;
	cout << "Enter a number to look for in Matrix? ";
	cin >> Number;
	return Number;
}

bool IsSparseMatrix(short Matrix[3][3], short Rows, short Cols)
{
	return CountNumberInMatrix(Matrix, 0, 3, 3) > (Rows * Cols) / 2;
}

bool DoesNumberExistInMatrix(short Matrix[3][3], short Number, short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == Number)
				return true;
		}
	}
	return false;
}

void IntersectedNumbersIn2Matrices(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (DoesNumberExistInMatrix(Matrix2, Matrix1[i][j], Rows, Cols))
				cout << setw(3) << Matrix1[i][j] << "\t";
		}
	}
}

short MaximumNumberInMatrix(short Matrix[3][3], short Rows, short Cols)
{
	short MaxNumber = Matrix[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] > MaxNumber)
				MaxNumber = Matrix[i][j];
		}
	}
	return MaxNumber;
}

short MinimumNumberInMatrix(short Matrix[3][3], short Rows, short Cols)
{
	short MinNumber = Matrix[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] < MinNumber)
				MinNumber = Matrix[i][j];
		}
	}
	return MinNumber;
}

bool IsPalindromeMatrix(short Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols / 2; j++)
		{
			if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
				return false;
		}
	}
	return true;
}

int main()
{
	srand((unsigned)time(NULL));

	short Matrix1[3][3] = { {1,2,1},{5,5,5},{7,3,3} };



	cout << "\n Matrix 1:\n\n";
	PrintMatrix(Matrix1, 3, 3);
	cout << endl;

	if (IsPalindromeMatrix(Matrix1, 3, 3))
		cout << "Yes";
	else
		cout << "No";


	system("pause>0");
	return 0;
}