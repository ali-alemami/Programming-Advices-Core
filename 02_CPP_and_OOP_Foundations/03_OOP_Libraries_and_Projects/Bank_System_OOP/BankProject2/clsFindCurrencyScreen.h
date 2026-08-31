#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency card:")
	{
		cout << "\n" << Title << "\n";
		cout << "____________________________\n\n";
		cout << "Country      : " << Currency.CountryName() << "\n";
		cout << "Code         : " << Currency.CurrencyCode() << "\n";
		cout << "Currency Name: " << Currency.CurrencyName() << "\n";
		cout << "Rate(1$)     = " << Currency.Rate() << endl;
		cout << "____________________________\n\n";
	}

	static string _ReadCurrencyCode()
	{
		string CurrencyCode = "";
		cout << "\nEnter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::DoesCurrencyExist(CurrencyCode))
		{
			cout << "Currency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		return CurrencyCode;
	}

	static string _ReadCoutryName()
	{
		string CountryName = "";
		cout << "\nEnter Country: ";
		CountryName = clsInputValidate::ReadString();

		while (!clsCurrency::DoesCountryExist(CountryName))
		{
			cout << "Country is not found, choose another one: ";
			CountryName = clsInputValidate::ReadString();
		}
		return CountryName;
	}
	
	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found.\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nCurrency was not found.\n\n";
		}
	}

public:

	static void ShowFindCurrencyScreen()
	{
		clsScreen::_DrawScreenHeader("\t Find Currency Screen");

		cout << "Find By: [1] Code or [2] Country? ";
		short Answer = clsInputValidate::ReadNumberBetween<short>(1, 2);

		if (Answer == 1)
		{
			clsCurrency Currency = clsCurrency::FindByCurrencyCode(_ReadCurrencyCode());
			_ShowResults(Currency);
		}
		else
		{
			clsCurrency Currency = clsCurrency::FindByCountryName(_ReadCoutryName());
			_ShowResults(Currency);
		}
	}
};

