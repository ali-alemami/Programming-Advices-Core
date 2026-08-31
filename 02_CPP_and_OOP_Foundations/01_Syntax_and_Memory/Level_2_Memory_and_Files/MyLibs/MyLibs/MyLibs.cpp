#include <iostream>
#include "MyInputLib.h"
#include "MyMathLib.h"

using namespace std;
using namespace MyMathLib;

int main()
{
	int Number = MyInputLib::ReadPositiveNumber();
	cout << Number << endl;

	Test();


	int Mark = 3;
	string Result;

	(Mark >= 50) ? cout <<  "pass" : cout << "fail";
}