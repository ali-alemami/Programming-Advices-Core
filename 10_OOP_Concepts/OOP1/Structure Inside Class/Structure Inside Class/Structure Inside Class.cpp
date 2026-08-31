#include <iostream>

using namespace std;

class clsPerson
{
private:

	struct stAddress
	{
		string Address1;
		string Address2;
	};

	stAddress _Address;
	string _FullName;

public:

	clsPerson(string FullName, string Address1, string Address2)
	{
		_FullName = FullName;
		_Address.Address1 = Address1;
		_Address.Address2 = Address2;
	}
	
	void Print()
	{
		cout << "Name: " << _FullName;
		cout << "AD1: " << _Address.Address1;
		cout << "AD2: " << _Address.Address2;
	}
};

int main()
{


	clsPerson Person1("Ali Alemame", "Jordan", "Zarqa");

	Person1.Print();

	return 0;
}