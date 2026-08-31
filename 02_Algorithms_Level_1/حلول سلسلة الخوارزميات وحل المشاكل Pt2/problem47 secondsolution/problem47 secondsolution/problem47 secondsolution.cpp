#include <iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
	float Number;

	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

float HowManyMonths(float LoanAmount, float MonthlyPayment)
{
	return (float)LoanAmount / MonthlyPayment;
}

int main()
{
	float LoanAmount = ReadPositiveNumber("Enter the loan amount ");
	float MonthlyPayment = ReadPositiveNumber("Enter the monthly payment ");

	cout << HowManyMonths(LoanAmount, MonthlyPayment) << " Months.";

	return 0;
}