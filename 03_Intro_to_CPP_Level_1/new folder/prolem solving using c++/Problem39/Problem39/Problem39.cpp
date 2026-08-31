#include <iostream>
using namespace std;
int main()
{
	cout << "Please enter cashpaid then totalbill\n";
	float cashpaid, totalbill; 
	cin >> cashpaid;
	cin >> totalbill;
	float remainder = cashpaid - totalbill;
	cout << remainder << endl;
	return 0;
}