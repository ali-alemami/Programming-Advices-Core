#include <iostream>
using namespace std;
void MyFunction()
{
	int days, hours, minutes, seconds;
	cout << "enter the days\n";
	cin >> days;
	
	cout << "enter the hours\n";
	cin >> hours;

	cout << "enter the minutes\n";
	cin >> minutes;

	cout << "enter the seconds\n";
	cin >> seconds;

	int totalseconds;
	totalseconds = (days * 24 * 60 * 60) + (hours * 60 * 60) + (minutes * 60) + seconds;
	cout << totalseconds << endl;
}
int main()
{
	MyFunction();
}