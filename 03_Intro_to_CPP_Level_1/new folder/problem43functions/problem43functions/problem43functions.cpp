#include <iostream>
using namespace std;
void SecondsTo()
{
	int secondsinday = 60 * 60 * 24, secondsinhour = 60 * 60, secondsinminute = 60;
	cout << "enter total seconds\n";
	int totalseconds;
	cin >> totalseconds;
	int numberofdays = totalseconds / secondsinday;
	int remainder = totalseconds % secondsinday;
	int numberofhours = remainder / secondsinhour;
	remainder = remainder % secondsinhour;
	int numberofminutes = remainder / secondsinminute;
	remainder = remainder % secondsinminute;
	cout << numberofdays << ":" << numberofhours << ":" << numberofminutes << ":" << remainder << endl;
}
int main()
{
	SecondsTo();
		return 0;
}