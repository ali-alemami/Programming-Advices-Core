#include <iostream>
using namespace std;
int main()
{
	cout << "Please enter the first number A?\n";
	short A, B;
	cin >> A;
	cout << "Please enter the second number B?\n";
	cin >> B;
	cout << A << " = " << B << " is " << (A == B) << endl;
	cout << A << " != " << B << " is " << (A != B) << endl;
	cout << A << " > " << B << " is " << (A > B) << endl;
	cout << A << " < " << B << " is " << (A < B) << endl;
	cout << A << " >= " << B << " is " << (A >= B) << endl;
	cout << A << " <= " << B << " is " << (A <= B) << endl;
	cout << "Made by ALIALEMAME\n\n";
}