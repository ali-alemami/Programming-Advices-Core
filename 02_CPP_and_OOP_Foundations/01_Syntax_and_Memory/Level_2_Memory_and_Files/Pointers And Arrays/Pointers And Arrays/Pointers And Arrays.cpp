#include <iostream>
using namespace std;

int main()
{
	int arr[4] = { 10,20,30,40 };

	int* ptr = arr;

	/*cout << ptr << endl;
	cout << ptr + 1 << endl;
	cout << ptr + 2 << endl;
	cout << ptr + 3 << endl;


	cout << *ptr << endl;
	cout << *(ptr + 1) << endl;
	cout << *(ptr + 2) << endl;
	cout << *(ptr + 3) << endl;*/

	for (int i = 0; i < 4; i++)
	{
		cout << ptr + i << endl;
	}

	for (int i = 0; i < 4; i++)
	{
		cout << *(ptr + i) << endl;
	}
	
	return 0;
}