#include <iostream>
#include <iomanip>

using namespace std;

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(2) << Matrix[i][j] << "    ";
		}
		cout << "\n";
	}
}

short CountNumberInMatrix(int Matrix[3][3], short Rows, short Cols, int Number)
{
	short Counter = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == Number)
				Counter++;
		}
	}
	return Counter;
}

bool IsMatrixSparce(int Matrix[3][3], short Rows, short Cols)
{
	return (CountNumberInMatrix(Matrix, Rows, Cols, 0) > (Rows * Cols) / 2);
}

int main()
{
	int Matrix[3][3] = { {0,0,0},{0,0,0},{12,1,9} };

	PrintMatrix(Matrix, 3, 3);

	if (IsMatrixSparce(Matrix, 3, 3))
		cout << "\nIt is a sparce";
	else
		cout << "\nIt is NOT a sparce";

	system("pause>0");
}