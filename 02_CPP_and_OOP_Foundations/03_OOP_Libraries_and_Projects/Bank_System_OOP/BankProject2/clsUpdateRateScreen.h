#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include <string>

using namespace std;

class clsUpdateRateScreen : protected clsScreen
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

	static void ShowUpdateRateScreen()
	{
		clsScreen::_DrawScreenHeader("\t  Update Rate Screen");

		clsCurrency Currency = clsCurrency::FindByCurrencyCode(_ReadCurrencyCode());
		_ShowResults(Currency);

		cout << "Are you sure you want to update the rate of this currency y/n? ";
		char Answer = 'n';
		Answer = clsInputValidate::ReadNumber<char>();

		if (tolower(Answer) == 'y')
		{
			cout << "\nUpdate Currency Rate:\n";
			cout << "________________________\n\n";

			cout << "Enter New Rate: ";
			float Amount = clsInputValidate::ReadNumber<float>();

			Currency.UpdateRate(Amount);

			cout << "\nCurrency Rate Updated Successfully.\n";
			_PrintCurrencyCard(Currency);
		}
		else
			cout << "\nCurrency Rate Wasn't Updated.\n";
	}
};

