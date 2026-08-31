#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsCurrency.h"

using namespace std;

class clsCurrenciesListScreen : protected clsScreen
{
private:

	static void _PrintCurrencyLine(clsCurrency Currency)
	{
		cout << "\t| " << setw(30) << left << Currency.CountryName();
		cout << "| " << left << setw(10) << Currency.CurrencyCode();
		cout << "| " << left << setw(30) << Currency.CurrencyName();
		cout << "| " << left << setw(10) << Currency.Rate();
	}

public:

	static void ShowCurrenciesListScreen()
	{
		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string Title = "\t Currencies List Screen";
		string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency.";

		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << "\t___________________________________________________";
		cout << "__________________________________________________\n\n";


		cout << "\t| " << left << setw(30) << "Country";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(30) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)\n";

		cout << "\t___________________________________________________";
		cout << "__________________________________________________\n\n";


		if (vCurrencies.size() == 0)
		{
			cout << "\n\n\t\t\t\tThere are no Currencies available in the system!\n\n";
		}
		else
		{
			for (clsCurrency Currency : vCurrencies)
			{
				_PrintCurrencyLine(Currency);
				cout << endl;
			}
		}
		cout << "\n\t___________________________________________________";
		cout << "__________________________________________________\n\n";
	}
};

