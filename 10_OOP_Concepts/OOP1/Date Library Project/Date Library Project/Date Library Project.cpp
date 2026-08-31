// Date Library Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "clsDate.h"

using namespace std;

int main()
{
	clsDate Date1(41, 2003);

	cout << Date1.FormatDate(Date1, "yyyy/mm/dd");



	
	return 0;
}
