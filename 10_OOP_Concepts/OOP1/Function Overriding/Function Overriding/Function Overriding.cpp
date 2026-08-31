#include <iostream>
#include <vector>

#include "clsPerson.h"
#include "clsEmployee.h"
#include "clsDeveloper.h"

using namespace std;


class clsHi
{
public:

	int value = 0;

	

	clsHi(int value)
	{
		this->value = value;
	}

	void Print()
	{
		cout << "value is: " << this->value << endl;
	}
};


int main()
{
	clsHi arr1[] = { clsHi(10), clsHi(5), clsHi(14) };

	for (short i = 0; i <= 2; i++)
	{
		arr1[i].Print();
	}

	system("pause>0");
	return 0;
}