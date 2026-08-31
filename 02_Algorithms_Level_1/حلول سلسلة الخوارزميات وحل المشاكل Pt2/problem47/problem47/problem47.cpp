#include <iostream>
using namespace std;

void ReadInfo(int& LoanAmount, int& MonthlyPayment)
{
	cout << "Enter loan amount ";
	cin >> LoanAmount;

	cout << "Enter monthlt payment ";
	cin >> MonthlyPayment;
}

int HowManyMonths(int LoanAmount, int MonthlyPayment)
{
	return LoanAmount / MonthlyPayment;
}

void PrintResult(int Months)
{
	cout << Months << " Months.\n";
}

int main()
{
	int LoanAmount, MonthlyPayment;

	ReadInfo(LoanAmount, MonthlyPayment);
	PrintResult(HowManyMonths(LoanAmount, MonthlyPayment));

	return 0;
}