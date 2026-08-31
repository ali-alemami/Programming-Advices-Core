#include <iostream>
#include <iomanip>

using namespace std;

void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols)
{
	short Counter = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = ++Counter;
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

void TransPoseMatrix(int arr[3][3], int arrTransPosed[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arrTransPosed[i][j] = arr[j][i];
		}
	}
}

int main()
{
	int arr[3][3], arrTransPosed[3][3];

	FillMatrixWithOrderedNumbers(arr, 3, 3);
	PrintMatrix(arr, 3, 3);
	cout << endl;
	TransPoseMatrix(arr, arrTransPosed, 3, 3);
	PrintMatrix(arrTransPosed, 3, 3);
	system("pause>0");
}