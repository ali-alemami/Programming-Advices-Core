#include <iostream>

using namespace std;

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf(" %0*d   ", 1, Matrix[i][j]);
		}
		cout << "\n";
	}
}

bool IsMatrixScalar(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && i < Rows - 1)
			{
				if (Matrix[i][j] != Matrix[i + 1][j + 1])
					return false;
			}
			else if (i != j && Matrix[i][j] != 0)
				return false;
		}
	}
	return true;
}

bool IsMatrixScalar2(int Matrix[3][3], short Rows, short Cols)
{
	int FirstDiagElement = Matrix[0][0];

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

int main()
{
	int Matrix1[3][3] = { {5,0,0},
						  {0,5,0},
						  {0,0,5} };

	PrintMatrix(Matrix1, 3, 3);

	if (IsMatrixScalar2(Matrix1, 3, 3))
		cout << "\nMatrix is scalar.\n";
	else
		cout << "\nMatrix is NOT scalar.\n";

	system("pause>0");
}