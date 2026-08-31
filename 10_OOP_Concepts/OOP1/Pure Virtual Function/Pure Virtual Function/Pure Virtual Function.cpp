#include <iostream>

using namespace std;

class clsPerson
{
	virtual void Print(string Name) = 0;
	virtual void Sum(int Num1, int Num2) = 0;
};

class clsMath : public clsPerson
{
	void Print(string Name)
	{
	}

	void Sum(int Num1, int Num2)
	{

	}

};


int main()
{
	clsMath Math1;

	return 0;
}