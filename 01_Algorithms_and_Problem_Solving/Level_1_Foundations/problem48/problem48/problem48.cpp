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

float MonthlyInstallmentAmount(float LoanAmount, float HowManyMonths)
{
	return float(LoanAmount / HowManyMonths);
}

int main()
{
	float LoanAmount = ReadPositiveNumber("Enter loan amount ");
	float HowManyMonths = ReadPositiveNumber("How many months ? ");

	cout << "You have to pay " <<
		MonthlyInstallmentAmount(LoanAmount, HowManyMonths) << "$ a month.";

	return 0;
}