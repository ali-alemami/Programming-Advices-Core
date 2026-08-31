#include <iostream>
using namespace std;
int main()
{
	unsigned int loanamount, monthsnumber;
	cout << "enter loanamount\n";
	cin >> loanamount;
	cout << "for how many months you need to settle the loan?\n";
	cin >> monthsnumber;
	short monthlypayment = loanamount / monthsnumber;
	cout << monthlypayment << endl;
	return 0;
}