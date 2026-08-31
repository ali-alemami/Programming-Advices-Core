#include <iostream>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

void FillArrayWithRandomNumbers(int arr[3][3], short Rows, short Cols)
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
			cout << setw(3) << arr[i][j] << "   ";
		}
		cout << "\n";
	}
}

void SumMatrixRows(int arr[3][3], short Rows, short Cols)
{
	int Sum = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Sum += arr[i][j];
		}
		cout << "Row " << i + 1 << " Sum = " << setw(3) << Sum << endl;
		Sum = 0;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	
	int arr[3][3];

	FillArrayWithRandomNumbers(arr, 3, 3);

	cout << "\nThe Following is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);

	cout << "\n\nThe following are the sum of each row in the matrix:\n";
	SumMatrixRows(arr, 3, 3);

	cout << "\n" << endl;

	system("pause>0");
}