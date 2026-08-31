#include <iostream>
using namespace std;
void ReadNumber(int& number,int& power)
{
	cout << "Enter a number\n";
	cin >> number;
	cout << "Enter the power\n";
	cin >> power;
}
void Calculate(int number,int power, int& counter)
{
	counter = 1;
	for (power; power >= 1; power--)
	{
		counter *= number;
	}
}
int main(int number, int power, int counter = 1)
{
	ReadNumber(number, power);
	Calculate(number, power, counter);
	cout << counter << endl;
	return 0;
}