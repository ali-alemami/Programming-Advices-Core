#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int> num{ 1,2,3,4,5 };

	cout << num.at(1);
	cout << num.at(0);
	cout << num.at(2);
	cout << num.at(3);
	cout << num.at(4);

	cout << num[0];
	cout << num[1];
	cout << num[2];
	cout << num[3];
	cout << num[4];

	return 0;
}