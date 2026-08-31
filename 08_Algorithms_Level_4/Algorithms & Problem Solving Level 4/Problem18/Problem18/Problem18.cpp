#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "MyDateLib.h";
using namespace MyDateLib;

vector <string> SplitString(string Line, string Seperator = "#//#")
{
	vector <string> vString;

	short pos = 0;
	string sword = "";

	while ((pos = Line.find(Seperator)) != std::string::npos)
	{
		sword = Line.substr(0, pos);
		if (sword != "")
		{
			vString.push_back(sword);
		}
		Line.erase(0, pos + Seperator.length());
	}
	if (Line != "")
	{
		vString.push_back(Line);
	}
	return vString;
}


int main()
{
	string DateString = ReadDateString("Enter Date dd/mm/yyyy? ");

	stDate Date;

	Date = StringToDate(DateString);

	cout << FormatDate(Date, "dd/mm/yyyy") << endl;
	cout << FormatDate(Date, "mm/dd/yyyy") << endl;
	cout << FormatDate(Date, "dd-mm-yyyy");



	system("pause>0");
	return 0;
}