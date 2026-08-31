#include <iostream>
#include <string>

using namespace std;

int ReadNumber()
{
	int Number = 0;
	cout << "Enter a Number? ";
	cin >> Number;
	return Number;
}

string NumberToText(int Number)
{
	if (Number < 0)
		return "Negative Number";
	else if (Number <= 19)
	{
		switch (Number)
		{
		case 0:
			return "";
		case 1:
			return "One";
		case 2:
			return "Two";
		case 3:
			return "Three";
		case 4:
			return "Four";
		case 5:
			return "Five";
		case 6:
			return "Six";
		case 7:
			return "Seven";
		case 8:
			return "Eight";
		case 9:
			return "Nine";
		case 10:
			return "Ten";
		case 11:
			return "Eleven";
		case 12:
			return "Twelve";
		case 13:
			return "Thiteen";
		case 14:
			return "Fourteen";
		case 15:
			return "Fifteen";
		case 16:
			return "Sixteen";
		case 17:
			return "Seventeen";
		case 18:
			return "Eighteen";
		case 19:
			return "Nineteen";
		}
	}

	else if (Number <= 99)
	{
		switch (Number / 10)
		{
		case 2:
			return ("Twenty " + NumberToText(Number - 20));
		case 3:
			return ("Thirty " + NumberToText(Number - 30));
		case 4:
			return ("Forty " + NumberToText(Number - 40));
		case 5:
			return ("Fifty " + NumberToText(Number - 50));
		case 6:
			return ("Sixty " + NumberToText(Number - 60));
		case 7:
			return ("Seventy " + NumberToText(Number - 70));
		case 8:
			return ("Eighty " + NumberToText(Number - 80));
		case 9:
			return ("Ninety " + NumberToText(Number - 90));
		}
	}

	else if (Number <= 199)
		return (NumberToText(Number / 100) + " Hundred " + (NumberToText(Number % 100)));

	else if (Number <= 999)
		return (NumberToText(Number / 100) + " Hundreds " + NumberToText(Number % 100));

	else if (Number <= 1199)
		return (NumberToText(Number / 1000) + " Thousand " + NumberToText(Number % 1000));

	else if (Number <= 999999)
		return (NumberToText(Number / 1000) + " Thousands " + NumberToText(Number % 1000));

	else if (Number <= 1999999)
		return (NumberToText(Number / 1000000) + " Million " + NumberToText(Number % 1000000));

	else if (Number <= 999999999)
		return (NumberToText(Number / 1000000) + " Millions " + NumberToText(Number % 1000000));

	else if (Number <= 1999999999)
		return (NumberToText(Number / 1000000000) + " Billion " + NumberToText(Number % 1000000000));

	else if (Number <= 999999999999)
		return (NumberToText(Number / 1000000000) + " Billions " + NumberToText(Number % 1000000000));
}

int main()
{
	cout << NumberToText(ReadNumber());
}