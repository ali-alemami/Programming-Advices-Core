#include <iostream>
using namespace std;
int main()
{
	cout << "Please enter Pennies, Nickels, Dimes, Quarters and Dollars\n";
	unsigned short int pennies, nickels, dimes, quarters, dollars;
	cin >> pennies;
	cin >> nickels;
	cin >> dimes;
	cin >> quarters;
	cin >> dollars;
	cout << pennies + nickels * 5 + dimes * 10 + quarters * 25 + dollars * 100 << endl << (pennies + nickels * 5 + dimes * 10 + quarters * 25 + dollars * 100 )/ 100 << endl;
}