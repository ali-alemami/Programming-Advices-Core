#include <iostream>
using namespace std;

int main()
{
	int* ptrX;
	float* ptrY;


	ptrX = new int;
	ptrY = new float;

	*ptrX = 7;
	*ptrY = 13.39f;

	cout << *ptrX << endl;
	cout << *ptrY << endl;

	delete ptrX;
	delete ptrY;

	return 0;		
}