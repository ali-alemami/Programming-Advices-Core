#pragma once

#include <iostream>
#include <string>
#include "clsString.h"
#include <fstream>

using namespace std;

class clsCurrency
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;

	string _CountryName;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line)
	{
		vector <string> vCurrencyLine = clsString::Split(Line, "#//#");
		
		return clsCurrency(enMode::UpdateMode, vCurrencyLine[0],
			vCurrencyLine[1], vCurrencyLine[2], stof(vCurrencyLine[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Separator = "#//#")
	{
		string DataLine = "";
		
		DataLine += Currency.CountryName() + Separator;
		DataLine += Currency.CurrencyCode() + Separator;
		DataLine += Currency.CurrencyName() + Separator;
		DataLine += to_string(Currency.Rate());

		return DataLine;
	}

	static vector <clsCurrency> _LoadCurrenciesDataFromFile()
	{
		vector <clsCurrency> vCurrencies;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				vCurrencies.push_back(Currency);
			}
			MyFile.close();
		}
		return vCurrencies;
	}

	static void _SaveCurrenciesDataToFile(vector <clsCurrency> vCurrencies)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			string Line = "";

			for (clsCurrency Currency : vCurrencies)
			{
				Line = _ConvertCurrencyObjectToLine(Currency);
				MyFile << Line << endl;
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		if (_Mode != enMode::UpdateMode)
			return;

		vector <clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();

		for (clsCurrency& Currency : vCurrencies)
		{
			if (Currency.CurrencyCode() == CurrencyCode())
			{
				Currency._Rate = Rate();
				break;
			}
		}
		_SaveCurrenciesDataToFile(vCurrencies);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:

	clsCurrency(enMode Mode, string CountryName, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_CountryName = CountryName;
		_CurrencyName = CurrencyName;
		_CurrencyCode = CurrencyCode;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string CountryName()
	{
		return _CountryName;
	}
	
	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	float Rate()
	{
		return _Rate;
	}

	static clsCurrency FindByCountryName(string CountryName)
	{
		CountryName = clsString::UpperAllString(CountryName);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if (clsString::UpperAllString(Currency.CountryName()) == CountryName)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}
	static clsCurrency FindByCurrencyCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static bool DoesCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = FindByCurrencyCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}

	static bool DoesCountryExist(string CountryName)
	{
		clsCurrency Currency = FindByCountryName(CountryName);
		return (!Currency.IsEmpty());
	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrenciesDataFromFile();
	}

	float ConvertToUsd(float Amount)
	{
		return (float)(Amount / Rate());
	}
	
	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUsd = ConvertToUsd(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUsd;
		}

		return (float)(AmountInUsd * Currency2.Rate());
	}
};