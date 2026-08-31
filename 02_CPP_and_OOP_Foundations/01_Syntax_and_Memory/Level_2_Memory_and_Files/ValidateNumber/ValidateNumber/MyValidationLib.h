#pragma once

#include <iostream>
using namespace std;

namespace MyValidationLib
{
	int ReadNumber()
	{
		int Number = 0;
		cout << "Enter a number?\n";
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Invalid Number, Enter a valid one:\n";
			cin >> Number;
		}

		return Number;
	}
}