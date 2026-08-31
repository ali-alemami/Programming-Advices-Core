#include <iostream>
using namespace std;
void ReadNumber(int& num)
{
	cout << "Please enter a number\n";
	cin >> num;
}
void PrintTonum(int num)
{
	for (int i = 1; i <= num; i++)
	{
		cout << i << endl;
	}
}
int main()
{
	int num;
	ReadNumber(num);
	PrintTonum(num);
	return 0;
}