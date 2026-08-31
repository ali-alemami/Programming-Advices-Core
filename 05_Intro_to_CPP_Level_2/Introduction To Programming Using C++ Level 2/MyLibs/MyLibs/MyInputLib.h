#pragma once

#include <iostream>
using namespace std;

namespace MyInputLib
{
	int ReadNumber()
	{
		int Number = 0;
		cout << "Enter a Number? ";
		cin >> Number;
		return Number;
	}

	int ReadPositiveNumber()
	{
		int Number = 0;
		do
		{
			cout << "Enter a positive Number? ";
			cin >> Number;
		} while (Number <= 0);
		return Number;
	}

	int ReadNumberInRange(int From, int To)
	{
		int Number = 0;
		do
		{
			cout << "Enter a Number? ";
			cin >> Number;
		} while (Number < From || Number > To);
		return Number;
	}
}

