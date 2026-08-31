#include <iostream>
using namespace std;
int main()
{
	cout << "Please enter the length and the width of the rectangle to calculate the area\n";
	unsigned short int length, width;
	cin >> length;
	cin >> width;
	cout << length * width << endl;
	return 0;
}