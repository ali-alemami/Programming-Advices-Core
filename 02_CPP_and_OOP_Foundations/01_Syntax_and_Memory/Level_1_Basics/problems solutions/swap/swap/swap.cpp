#include <iostream>
using namespace std;

void Swap(int &x, int &y)
{
	
	int temp;
	
	temp = x;
	x = y;
	y = temp;

	cout << "after swap inside the function x = " << x << " and y = " << y << endl;

}

int main()
{
	int x, y;

	cout << "enter x vlaue\n";
	cin >> x;

	cout << "\nenter y value\n";
	cin >> y;

	cout << "before swap in the main x = " << x << " and y = " << y << endl;

	Swap(x, y);

	cout << "after swap in the main x = " << x << " and y = " << y << endl;

	return 0;
}