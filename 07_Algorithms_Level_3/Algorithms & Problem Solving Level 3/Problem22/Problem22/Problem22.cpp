#include <iostream>

using namespace std;

void PrintFibonacciUsingRecursion(short Number, int Prev1, int Prev2)
{
	int FibNumber = 0;

	if (Number > 0)
	{
		FibNumber = Prev2 + Prev1;
		Prev2 = Prev1;
		Prev1 = FibNumber;

		cout << FibNumber << "   ";

		PrintFibonacciUsingRecursion(Number - 1, Prev1, Prev2);
	}
}

int main()
{
	PrintFibonacciUsingRecursion(10, 0, 1);

	system("pause>0");
}