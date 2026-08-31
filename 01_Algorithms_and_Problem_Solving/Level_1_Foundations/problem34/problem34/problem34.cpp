#include <iostream>
using namespace std;

float ReadNumber(string Message)
{
	float TotalSales;

	cout << Message << endl;
	cin >> TotalSales;

	return TotalSales;
}

float GetPercentage(float TotalSales)
{
	float Percentage;

	if (TotalSales >= 1000000)
		return Percentage = 0.1;
	else if (TotalSales >= 500000)
		return Percentage = 0.2;
	else if (TotalSales >= 100000)
		return Percentage = 0.3;
	else if (TotalSales >= 50000)
		return Percentage = 0.5;
	else
		return Percentage = 0;
	//or just return 0.1, the variable is usless
}

float CalculateCommission(float TotalSales)
{
	return TotalSales * GetPercentage(TotalSales);
}

int main()
{
	cout << CalculateCommission(ReadNumber("What are the total sales ? ")) << endl;

	return 0;
}