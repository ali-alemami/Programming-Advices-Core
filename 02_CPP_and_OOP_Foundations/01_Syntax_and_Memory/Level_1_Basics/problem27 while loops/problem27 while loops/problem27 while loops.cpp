#include <iostream>
using namespace std;
int main()
{
	int number;
	cout << "Enter a number\n";
	cin >> number;
	int x = number;
	while (x >= 1)
	{
		cout << x << endl;
		x--;
	}
	return 0;
}