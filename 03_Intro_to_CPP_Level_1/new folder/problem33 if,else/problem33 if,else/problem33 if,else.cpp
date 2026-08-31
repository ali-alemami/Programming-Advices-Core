#include <iostream>
using namespace std;
int main()
{
	float mark;
	cout << "Enter your mark\n";
	cin >> mark;

	if (mark <= 100 && mark >= 90)
	{
		cout << "A";
	}
	else if (mark < 90 && mark >= 80)
	{
		cout << "B";
	}
	else if (mark < 80 && mark >= 70)
	{
		cout << "C";
	}
	else if (mark < 70 && mark >= 60)
	{
		cout << "D";
	}
	else if (mark < 60 && mark >= 50)
	{
		cout << "E";
	}
	else
	{
		cout << "F";
	}
	return 0;
}
