#include <iostream>

using namespace std;

class clsPerson
{
private:
	string _FirstName;

public:
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	string GetFirstName()
	{
		return _FirstName;
	}

	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;
};

int main()
{
	clsPerson Person1;

	Person1.FirstName = "Ali";
	cout << Person1.FirstName << endl;
}