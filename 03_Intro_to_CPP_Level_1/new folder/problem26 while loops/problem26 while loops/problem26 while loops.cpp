#include <iostream>
using namespace std;
int main()
{
	cout << "Plz enter a number\n";
	int i = 1, number;
	cin >> number;
	while (i <= number)
	{
		cout << i << "\n";
		i++;
	}
	return 0;
}
