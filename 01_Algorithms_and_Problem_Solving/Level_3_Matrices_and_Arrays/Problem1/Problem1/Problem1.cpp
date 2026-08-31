#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void CreateMatrix(int arr[3][3])
{
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3])
{
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			cout << " " << arr[i][j] << "    ";
		}
		cout << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];

	CreateMatrix(arr);

	cout << "The Following is a 3x3 random matrix:\n\n";

	PrintMatrix(arr);

	return 0;
}