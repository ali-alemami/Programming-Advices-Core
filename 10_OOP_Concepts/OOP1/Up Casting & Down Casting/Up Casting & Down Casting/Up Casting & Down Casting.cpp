#include <iostream>

using namespace std;

class clsPerson
{
public:

	virtual int ID()
	{
		return 1;
	}
};

class clsEmployee : public clsPerson
{
public:

	int ID()
	{
		return 2;
	}
};

int main()
{
	clsEmployee Employee1;

	cout << Employee1.ID()<< endl;

	clsPerson* Person1 = &Employee1;

	cout << Person1->ID()<< endl;
}