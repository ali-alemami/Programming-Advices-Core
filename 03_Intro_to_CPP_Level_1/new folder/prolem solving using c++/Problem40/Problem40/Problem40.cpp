#include <iostream>
using namespace std;
int main()
{
	cout << "please enter billvalue\n";
	float billvalue;
	cin >> billvalue;
	float totalbill = (billvalue * 1.1) * 1.16;
	cout << totalbill << endl;
	return 0;
}