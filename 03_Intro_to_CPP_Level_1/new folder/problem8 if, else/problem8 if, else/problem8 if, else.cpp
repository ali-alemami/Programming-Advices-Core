#include <iostream>
using namespace std;
int main()
{
	float mark;
	cout << "Enter your mark\n";
	cin >> mark;
	if (mark >= 50)
	{
		cout << "PASS\n";
	}
	else
	{
		cout << "FAIL\n";
	}
	return 0;
}