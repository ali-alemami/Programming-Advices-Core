#include <iostream>
#include <iomanip>

using namespace std;

short ReadNumber(string Message)
{
	short Number = 0;
	cout << Message << endl;
	cin >> Number;
	return Number;
}

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

bool DoesNumberExistInMatrix(int Matrix[3][3], short Rows, short Cols, short Number)
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

int main()
{
	int Matrix[3][3] = { {77,5,12},{22,20,1},{1,0,9} };

	PrintMatrix(Matrix, 3, 3);

	short Number = ReadNumber("Enter the number you are looking for ? ");

	if (DoesNumberExistInMatrix(Matrix, 3, 3, Number))
		cout << "YES it is there\n";
	else
		cout << "NO it is NOT there\n";

	system("pause>0");
}