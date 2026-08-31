#include <iostream>
using namespace std;

struct stInfo
{
	int Pennies, Nickels, Dimes, Quarters, Dollars,
		TotalPennies;
	float TotalDollars;
};

stInfo ReadInfo()
{
	stInfo Info;

	cout << "How many Pennies  ? ";
	cin >> Info.Pennies;

	cout << "How many Nickels  ? ";
	cin >> Info.Nickels;

	cout << "How many Dimes    ? ";
	cin >> Info.Dimes;

	cout << "How many Quarters ? ";
	cin >> Info.Quarters;

	cout << "How many Dollaers ? ";
	cin >> Info.Dollars;

	return Info;
}

stInfo CalculateTotalPennies(stInfo Info)
{

	Info.TotalPennies = Info.Pennies + Info.Nickels * 5 + Info.Dimes * 10
		+ Info.Quarters * 25 + Info.Dollars * 100;

	Info.TotalDollars = (float)Info.TotalPennies / 100;

	return Info;
}

void PrintResult(stInfo Info)
{
	cout << "Total Pennies = " << Info.TotalPennies << endl;
	cout << "Total Dollars = " << Info.TotalDollars << endl;
}

int main()
{
	PrintResult(CalculateTotalPennies(ReadInfo()));

	return 0;
}