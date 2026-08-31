#include <iostream>
using namespace std;
void swap(int &num1, int &num2)
{
	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;

	cout << "after swap inside function num1= " << num1 << "	num2= " << num2 << endl;

}
int main()
{
	int num1, num2;
	cout << "enter num1\n";
	cin >> num1;

	cout << "enter num2\n";
	cin >> num2;
	cout << "before swap num1= " << num1 << "   num2= " << num2 << endl;
	swap(num1, num2);
	cout << "after swap num1= " << num1 << "   num2= " << num2 << endl;
	return 0;
}