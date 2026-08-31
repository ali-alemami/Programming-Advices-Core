#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

#include "MyStringLib.h";
using namespace MyStringLib;


void PrintFibonacciUsingLoop(short Number)
{
	short FebNumber = 0;
	short Prev2 = 0, Prev1 = 1;
	cout << "  1  ";

	for (short i = 2; i <= Number; i++)
	{
		FebNumber = Prev1 + Prev2;
		cout << setw(3) << FebNumber << "  ";

		Prev2 = Prev1;
		Prev1 = FebNumber;
	}
}

void PrintFibonacciSeriesUsingRecursion(short Number, short Prev2, short Prev1)
{
	short FebNumber = 0;

	if (Number > 0)
	{
		FebNumber = Prev2 + Prev1;
		Prev2 = Prev1;
		Prev1 = FebNumber;

		cout << FebNumber << "  ";
		PrintFibonacciSeriesUsingRecursion(Number - 1, Prev2, Prev1);
	}
}





int main()
{
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFile);
	string AccountNumber = ReadAccountNumber();


	UpdateClientByAccountNumber(AccountNumber, vClients);




	system("pause>0");
	return 0;
}