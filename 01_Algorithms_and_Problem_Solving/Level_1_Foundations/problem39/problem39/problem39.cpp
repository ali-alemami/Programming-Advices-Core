#include <iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
	int Number;
	
	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

float CalculateRemainder(float TotalBill, float CashPaid)
{
	float Remainder = CashPaid - TotalBill;

	return Remainder;
}

int main()
{
	float TotalBill, CashPaid, Remainder;

	TotalBill = ReadPositiveNumber("Enter the total bill");
	CashPaid = ReadPositiveNumber("Enter the cash paid ");

	Remainder = CalculateRemainder(TotalBill, CashPaid);

	cout << "\n\nTotal Bill = " << TotalBill << endl;
	cout << "Total Cash Paid = " << CashPaid << endl;
	cout << "___________________________________\n\n";

	cout << "Remainder = " << Remainder << endl;

	return 0;
}