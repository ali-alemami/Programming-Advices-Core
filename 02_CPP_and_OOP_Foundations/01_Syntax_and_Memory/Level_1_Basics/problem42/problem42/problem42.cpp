#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int days, hours, minutes, seconds;
	cout << "enter the days number\n";
	cin >> days;
	cout << "enter the hours number\n";
	cin >> hours;
	cout << "enter the minutes number\n";
	cin >> minutes;
	cout << "enter the seconds number\n";
	cin >> seconds;
	int totalseconds = (days * 60 * 60 * 24) + (hours * 60 * 60) + (minutes * 60) + seconds;
	cout << round(totalseconds) << endl;
	return 0;

}