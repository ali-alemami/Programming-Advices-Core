#include <iostream>
using namespace std;
int main()
{
	cout << "please enter days then hours then minutes then seconds\n";
	unsigned int seconds, minutes, hours, days;
	cin >> days;
	cin >> hours;
	cin >> minutes;
	cin >> seconds;

	unsigned int totalseconds = seconds + minutes * 60 + hours * 60 * 60 + days * 24 * 60 * 60;
	cout << totalseconds<<" Seconds." << endl;
	return 0;

}