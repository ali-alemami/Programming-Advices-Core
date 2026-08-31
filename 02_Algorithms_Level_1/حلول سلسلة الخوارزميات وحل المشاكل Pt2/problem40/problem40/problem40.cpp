#include <iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
	int Number;

	cout << Message << endl;
	cin >> Number;
	return Number;
}

float Calculate(float TotalBill)
{
	TotalBill *= 1.10;

	TotalBill *= 1.16;

	return TotalBill;
}

int main()
{
	float TotalBill = ReadPositiveNumber("Enter the bill value ");
	
	cout << "Total bill = " << TotalBill << endl;
	cout << "Total bill after service fee and tax sales = "
		<< Calculate(TotalBill) << endl;

	return 0;
}