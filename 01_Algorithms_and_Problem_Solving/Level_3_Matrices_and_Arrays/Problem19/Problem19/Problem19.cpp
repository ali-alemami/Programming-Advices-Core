#include <iostream>
#include <iomanip>

using namespace std;

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << Matrix[i][j] << "   ";
		}
		cout << "\n";
	}
}

int MinNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
{
	int Number = Matrix[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] < Number)
				Number = Matrix[i][j];
		}
	}
	return Number;
}

int MaxNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
{
	int Number = Matrix[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] > Number)
				Number = Matrix[i][j];
		}
	}
	return Number;
}

int main()
{
	int Matrix[3][3] = { {77, 5, 12}, {22, 20, 6}, {14, 3, 9} };

	PrintMatrix(Matrix, 3, 3);

	cout << "\nMinimun Number is: " << MinNumberInMatrix(Matrix, 3, 3) << "\n";
	cout << "\nMaximim Number is: " << MaxNumberInMatrix(Matrix, 3, 3) << "\n";

	system("pause>0");
}