#pragma once

#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"

using namespace std;

class clsInputValidate
{
public:

	template <typename T>
	static  bool IsNumberBetween(T Number, T From, T To)
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

	template <typename T>
	static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		T Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	template <typename T>
	static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		T Number = ReadNumber<T>();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadNumber<T>();
		}
		return Number;
	}
	
	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}

	/*static bool IsNumberBetween(short Number, short From, short To)
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

	static char ReadChar()
	{
		char Ch = 0;
		cin >> Ch;
		return Ch;
	}

	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		short Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
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
	static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		float Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
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

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		short Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
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

	static float ReadFloatNumberBetween(float From, float To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		float Number = ReadFloatNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadFloatNumber();
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
	}*/
};

