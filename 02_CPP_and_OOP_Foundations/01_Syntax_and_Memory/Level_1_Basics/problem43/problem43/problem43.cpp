#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	cout << "enter total seconds\n";
	int totalseconds;
	cin >> totalseconds;
	int days = floor(totalseconds / (pow(60, 2) * 24));
	int remainder1 = totalseconds % (60 * 60 * 24);
	int hours = floor(remainder1 / (60 * 60));
	int remainder2 = (remainder1 % (60 * 60));
	int minutes = floor(remainder2 / 60);
	int seconds = remainder2 % 60;
	cout << round(days) << ":" << round(hours) << ":" << round(minutes) << ":" << round(seconds) << endl;
	return 0;

}