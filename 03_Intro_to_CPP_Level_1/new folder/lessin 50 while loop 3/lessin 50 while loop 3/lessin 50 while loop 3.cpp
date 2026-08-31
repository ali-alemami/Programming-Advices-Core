#include <iostream>
using namespace std;
int ReadIntNumbersInRange(int from,int to)
{
	int number;
	cout << "Plz enter a number bettween " << from << " and " << to << endl;
	cin >> number;
	while (number < from || number > to)
	{
		cout << "Wrong number\nPlz enter a number between " << from << " and " << to << endl;
		cin >> number;
	}
	return number;
}
int ReadIntNumbersInRangeWhileDo(int from, int to)
{
	int number;
	do {
		
		cout << "Plz enter a number bettween " << from << " and " << to << endl;
		cin >> number;
	} while ( number < from || number > to);
	return number;
}
int main()
{
	cout << " The number is " << ReadIntNumbersInRangeWhileDo(1, 45) << endl;
	return 0;
}