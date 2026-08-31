#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
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

	static string _ReadCurrencyCode(string Message)
	{
		string CurrencyCode = "";
		cout << Message;
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::DoesCurrencyExist(CurrencyCode))
		{
			cout << "Currency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		return CurrencyCode;
	}

	static float _ReadAmount()
	{
		cout << "\nEnter Amount to Exchange: ";
		float Amount = clsInputValidate::ReadNumber<float>();
		return Amount;
	}

	static void _PrintCalculationResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		_PrintCurrencyCard(Currency1, "Convert From:");
		_PrintCurrencyCard(Currency2, "Convert To:");

		float Result = 0;

		if (Currency2.CurrencyCode() == "USD")
		{
			Result = Currency1.ConvertToUsd(Amount);
		}
		else
		{
			Result = Currency1.ConvertToOtherCurrency(Amount, Currency2);
		}

		cout << Amount << " " << Currency1.CurrencyCode() << " = " << Result << " " << Currency2.CurrencyCode() << endl;
	}

public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Answer = 'n';
		do
		{
			system("cls");

			clsScreen::_DrawScreenHeader("\tCurrency Calculator");

			clsCurrency Currency1 = clsCurrency::FindByCurrencyCode(_ReadCurrencyCode("\nEnter Currency1 Code: "));
			clsCurrency Currency2 = clsCurrency::FindByCurrencyCode(_ReadCurrencyCode("\nEnter Currency2 Code: "));

			float AmountInCurrency1 = _ReadAmount();

			_PrintCalculationResults(AmountInCurrency1, Currency1, Currency2);

			cout << "\nDo you want to perform another calculation y/n? ";
			Answer = clsInputValidate::ReadNumber<char>();

		} while (tolower(Answer) == 'y');
	}
};