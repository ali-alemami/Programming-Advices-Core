#include <iostream>
using namespace std;
int main()
{
	float loanamount, monthlypayment;
	cout << "please enter loanamount\n";
	cin >> loanamount;
	cout << "please enter monthlypayment\n";
	cin >> monthlypayment;
	float monthsnumber = loanamount / monthlypayment;
	cout << monthsnumber << " Months.\n";
	return 0;

}