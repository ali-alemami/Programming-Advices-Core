#include <iostream>

using namespace std;

class Class1
{
private:

	int Var1;

protected:

	int Var2;

public:

	int Var3;
};

class Class2 : protected Class1
{
	
};

class Class3 : public Class2
{
	Class2::Var2;
};

int main()
{
	Class2 C2;

	
}