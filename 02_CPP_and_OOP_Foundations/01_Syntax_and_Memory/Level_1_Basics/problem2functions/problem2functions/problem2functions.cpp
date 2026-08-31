#include <iostream>
#include <string>
using namespace std;
void MyProcedureName()
{
	string name;
	cout << "enter your name\n";
	getline(cin, name);
	cout << name;
}


int main()
{
	MyProcedureName();
}