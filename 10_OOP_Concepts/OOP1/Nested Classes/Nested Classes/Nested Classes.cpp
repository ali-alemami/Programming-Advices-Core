#include <iostream>

using namespace std;

class clsPerson
{
private:

	string _FullName;

	class clsAddress
	{
	private:

		string _Address1,
			_Address2,
			_StreetName;

	public:

		clsAddress(string AddressLine1, string AddressLine2, string StreetName)
		{
			_Address1 = AddressLine1;
			_Address2 = AddressLine2;                        
			_StreetName = StreetName;
		}

		void SetAddress1(string Address1)
		{
			_Address1 = Address1;
		}
		string GetAddress1()
		{
			return _Address1;
		}

		void SetAddress2(string Address2)
		{
			_Address2 = Address2;
		}
		string GetAddress2()
		{
			return _Address2;
		}

		void SetStreetName(string StreetName)
		{
			_StreetName = StreetName;
		}
		string GetStreetName()
		{
			return _StreetName;
		}

		void Print()
		{
			cout << _Address1 << endl;
			cout << _Address2 << endl;
			cout << _StreetName << endl;
		}
	};

public:

	clsAddress Address = clsAddress("", "", "");

	clsPerson(string FullName, string Address1, string Address2, string StreetName)
	{
		_FullName = FullName;

		Address = clsAddress(Address1, Address2, StreetName);
	}

	string setFullName(string FullName)
	{ _FullName = FullName;
	}
	string FullName()
	{
		return _FullName;
	}
};

int main()
{
	clsPerson Person1("ALI ALEMAME", "ADD1", "ADD2", "STREETNAME");

	Person1.Address.Print();

	return 0;
}