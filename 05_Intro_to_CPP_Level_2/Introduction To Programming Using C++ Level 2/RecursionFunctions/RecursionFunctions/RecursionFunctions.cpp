#include <iostream>
using namespace std;

void PrintNumbers(int N, int M)
{
	if (N <= M)
	{
		cout << N << endl;
		PrintNumbers(N + 1, M);
	}
}

void PrintNumbers2(int N, int M)
{
	if (N <= M)
	{
		cout << N << endl;
		PrintNumbers2(N + 1, M);
	}
}

void PrintNumbersFromMToN(int N, int M);

int CalculatePowerNM(int N, int M);

int main()
{
	cout << CalculatePowerNM(3, 3) << endl;
	return 0;
}

void PrintNumbersFromMToN(int N, int M)
{
	if (M >= N)
	{
		cout << M << endl;
		PrintNumbersFromMToN(N, M - 1);
	}
}

int CalculatePowerNM(int N, int M)
{
	int Counter = 0, Result = 1;
	if (M > 1)
	{
		CalculatePowerNM(N * N, M - 1);
		Counter++;
	}
	for (int i = 1; i <= Counter; i++)
	{
		Result *= N;
	}
	return Result;
}

