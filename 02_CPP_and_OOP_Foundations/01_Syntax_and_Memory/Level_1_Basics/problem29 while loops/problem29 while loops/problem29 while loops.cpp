#include <iostream>
using namespace std;
int main()
{
	int number, sum = 0;
	cout << "Enter a number\n";
	cin >> number;
	while (number >= 1)
	{
		if (number % 2 == 0)
		{
			sum += number;
		}
		number--;
	}
	cout << sum;
	return 0;
}