#pragma once

#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"

using namespace std;

class clsInputValidate
{

public:

	static bool IsNumberBetween(short Number, short From, short To)
	{
		return Number >= From && Number <= To;
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return Number >= From && Number <= To;
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return Number >= From && Number <= To;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return Number >= From && Number <= To;
	}

	static bool IsDateBetween(clsDate Date, clsDate Date1, clsDate Date2)
	{
		if (clsDate::IsDate1AfterDate2(Date1, Date2))
		{
			clsDate::SwapDates(Date1, Date2);
		}
		
		return (clsDate::IsDate1AfterDate2(Date, Date1) && clsDate::IsDate1BeforeDate2(Date, Date2)) ||
			clsDate::IsDate1EqualDate2(Date, Date1) || clsDate::IsDate1EqualDate2(Date, Date2);
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		int Number = 0;
		
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		double Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	
	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}
};

