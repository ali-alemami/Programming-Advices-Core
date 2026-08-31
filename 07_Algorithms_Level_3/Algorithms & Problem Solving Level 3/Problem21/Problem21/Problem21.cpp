#include <iostream>
#include <vector>

using namespace std;

void PrintFibonacciSeries()
{
	int Prev1 = 1;
	int Prev2 = 1;
	int temp = 0;

	for (short i = 1; i <= 10; i++)
	{
		cout << Prev1 << "  ";
		
		temp = Prev2;
		Prev2 = Prev1 + Prev2;
		Prev1 = temp;

	}
}

int main()
{
	PrintFibonacciSeries();

	system("pause>0");
}