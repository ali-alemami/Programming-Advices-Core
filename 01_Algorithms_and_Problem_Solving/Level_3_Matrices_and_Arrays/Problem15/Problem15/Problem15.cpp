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

int ReadNumber(string Message)
{
	int Number = 0;

	cout << Message << endl;
	cin >> Number;
	return Number;
}

short NumberCountInMatrix(int Matrix[3][3], short Rows, short Cols, int Number)
{
	short Counter = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == Number)
			{
				Counter++;
			}
		}
	}
	return Counter;
}

int main()
{
	int Matrix[3][3] = { {9,1,12},
						 {0,9,1},
						 {0,9,9} };

	PrintMatrix(Matrix, 3, 3);

	int Number = ReadNumber("\nEnter the number to count in matrix? ");

	cout << "\nNumber " << Number << " count in matrix is " << NumberCountInMatrix(Matrix, 3, 3, Number) << endl;

	system("pause>0");
}