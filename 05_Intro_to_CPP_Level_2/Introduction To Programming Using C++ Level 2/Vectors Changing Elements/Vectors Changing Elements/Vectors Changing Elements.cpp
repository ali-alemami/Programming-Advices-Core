#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int> num{ 10,20,30,40,50 };

	for (const int& i : num)
	{
		cout << i << " ";
	}
	cout << endl;

	for (int& i : num)
	{
		i = 20;
		cout << i << " ";
	}
	cout << endl;

	num[0] = 100;

	num.at(4) = 400;

	for (const int& i : num)
	{
		cout << i << " ";
	}

	return 0;
}