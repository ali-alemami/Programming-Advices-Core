#include <iostream>
using namespace std;
void ReadNumber(int& num)
{
	cout << "Please enter a number\n";
	cin >> num;
}
void PrintTo1(int num)
{
	for (int i = num; i >= 1; i--)
	{
		cout << i << endl;
	}
}
int main(int num)
{

	ReadNumber(num);
	PrintTo1(num);
}