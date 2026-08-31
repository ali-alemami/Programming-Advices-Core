#include <iostream>
using namespace std;

int main()
{
	float x[3];

	cout << "Enter the first grade\n";
	cin >> x[0];

	cout << "Enter the second grade\n";
	cin >> x[1];

	cout << "Enter the third grade\n";
	cin >> x[2];

	float result = (x[0] + x[1] + x[2]) / 3;
	cout << "************************************\n";
	cout << "The average of grades is " << result << endl;

	return 0;
}