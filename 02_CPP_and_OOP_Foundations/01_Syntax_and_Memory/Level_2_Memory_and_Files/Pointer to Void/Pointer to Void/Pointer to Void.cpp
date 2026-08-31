#include <iostream>
using namespace std;

int main()
{
	void* ptr;

	float x = 10.5;

	ptr = &x;

	cout << ptr << endl;

	cout << *(static_cast<float*>(ptr)) << endl;


	int y = 100;

	ptr = &y;

	cout << ptr << endl;
	cout << *(static_cast<int*>(ptr)) << endl;

	return 0;
}