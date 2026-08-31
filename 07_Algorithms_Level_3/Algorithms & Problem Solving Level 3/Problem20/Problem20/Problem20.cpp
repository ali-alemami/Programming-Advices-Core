#include <iostream>
#include <iomanip>
#include <string>

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

bool IsPalindromeRow(int Matrix[3][3], short Row, short Cols)
{
	for (short i = 0; i < Cols / 2; i++)
	{
		if (Matrix[Row][i] != Matrix[Row][Cols - 1 - i])
			return false;
	}
	return true;
}

bool IsPalindromeMatrix(int Matrix[3][3], short Rows, short Cols)
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
	int Matrix[3][3] = { {1,2,1},{5,5,5},{7,3,7} };

	PrintMatrix(Matrix, 3, 3);

	if (IsPalindromeMatrix(Matrix, 3, 3))
		cout << "\nMatrix is Palindrome.\n";
	else
		cout << "\nMatrix is NOT Palindrome.\n";

	system("pause>0");
}
