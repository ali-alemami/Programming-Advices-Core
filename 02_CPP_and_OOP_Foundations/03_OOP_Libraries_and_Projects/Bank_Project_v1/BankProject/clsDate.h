#pragma warning(disable : 4996)
#pragma once

#include <iostream>
#include <iomanip>
#include <string>
//#include <vector>
#include "clsString.h"

using namespace std;

class clsDate
{
private:

	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;


public:

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}

	clsDate(string sDate)
	{

		vector <string> vDate;
		vDate = clsString::Split(sDate, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);

	}

	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(short DateOrderInYear, short Year)
	{
		clsDate TempDate = ConvertTotalDaysToDate(DateOrderInYear, Year);

		this->_Day = TempDate._Day;
		this->_Month = TempDate._Month;
		this->_Year = TempDate._Year;
	}


	void SetDay(short Day) {
		_Day = Day;
	}
	short GetDay() {
		return _Day;
	}
	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void SetMonth(short Month) {
		_Month = Month;
	}
	short GetMonth() {
		return _Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	void SetYear(short Year) {
		_Year = Year;
	}
	short GetYear() {
		return _Year;
	}
	__declspec(property(get = GetYear, put = SetYear)) short Year;

	void Print()
	{
		cout << DateToString();
	}

	static clsDate GetSystemDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		return clsDate(Day, Month, Year);
	}

	static void ReadDay(clsDate& Date)
	{
		cout << "\nPlease enter a Day? ";
		cin >> Date._Day;
	}
	void ReadDay()
	{
		cout << "\nPlease enter a Day? ";
		cin >> this->_Day;
	}

	static void ReadMonth(clsDate& Date)
	{
		cout << "Please enter a Month? ";
		cin >> Date._Month;
	}
	void ReadMonth()
	{
		cout << "Please enter a Month? ";
		cin >> this->_Month;
	}

	static void ReadYear(clsDate& Date)
	{
		cout << "Please enter a Year? ";
		cin >> Date._Year;
	}
	void ReadYear()
	{
		cout << "Please enter a Year? ";
		cin >> this->_Year;
	}

	static void ReadFullDate(clsDate& Date)
	{
		ReadDay(Date);
		ReadMonth(Date);
		ReadYear(Date);
	}
	void ReadFullDate()
	{
		ReadDay();
		ReadMonth();
		ReadYear();
	}

	static string ReadStringDate()
	{
		string DateString = "";
		cout << "Enter Date dd/mm/yyyy? ";
		getline(cin >> ws, DateString);
		return DateString;
	}

	static clsDate StringToDate(clsDate Date, string DateString)
	{
		vector <string> vString;
		vString = clsString::Split(DateString, "/");

		Date._Day = stoi(vString[0]);
		Date._Month = stoi(vString[1]);
		Date._Year = stoi(vString[2]);
		return Date;
	}
	clsDate StringToDate(string DateString)
	{
		return StringToDate(*this, DateString);
	}

	static string DateToString(clsDate Date)
	{
		return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
	}
	string DateToString()
	{
		return DateToString(*this);
	}

	static bool IsLeapYear(short Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}
	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static short NumberOfDaysInYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}
	short NumberOfDaysInYear()
	{
		return NumberOfDaysInYear(_Year);
	}

	static short NumberOfHoursInYear(short Year)
	{
		return NumberOfDaysInYear(Year) * 24;
	}
	short NumberOfHoursInYear()
	{
		return NumberOfHoursInYear(_Year);
	}

	static int NumberOfMinutesInYear(short Year)
	{
		return NumberOfDaysInYear(Year) * 24 * 60;
	}
	int NumberOfMinutesInYear()
	{
		return NumberOfMinutesInYear(_Year);
	}

	static int NumberOfSecondsInYear(short Year)
	{
		return NumberOfDaysInYear(Year) * 24 * 60 * 60;
	}
	int NumberOfSecondsInYear()
	{
		return NumberOfSecondsInYear(_Year);
	}

	static short NumberOfDaysInMonth(short Month, short Year)
	{
		short arrMonth[] = { 31, 28, 31,30,31,30,31,31,30,31,30,31 };

		return (IsLeapYear(Year) && Month == 2) ? 29 : arrMonth[Month - 1];
	}
	short NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(_Month, _Year);
	}

	static short NumberOfHoursInMonth(short Month, short Year)
	{
		return NumberOfDaysInMonth(Year, Month) * 24;
	}
	short NumberOfHoursInMonth()
	{
		return NumberOfDaysInMonth(_Year, _Month) * 24;
	}

	static int NumberOfMinutesInMonth(short Month, short Year)
	{
		return NumberOfHoursInMonth(Year, Month) * 60;
	}
	int NumberOfMinutesInMonth()
	{
		return NumberOfHoursInMonth(_Year, _Month) * 60;
	}

	static int NumberOfSecondsInMonth(short Month, short Year)
	{
		return NumberOfHoursInMonth(Year, Month) * 60;
	}
	int NumberOfSecondsInMonth()
	{
		return NumberOfHoursInMonth(_Year, _Month) * 60;
	}

	static short DayOrderOfTheWeek(short Day, short Month, short Year)
	{
		short a, y, m, d;

		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;
	}
	static short DayOrderOfTheWeek(clsDate Date)
	{
		short a, y, m, d;

		a = (14 - Date._Month) / 12;
		y = Date._Year - a;
		m = Date._Month + (12 * a) - 2;

		d = (Date._Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;
	}
	short DayOrderOfTheWeek()
	{
		return DayOrderOfTheWeek(*this);
	}

	static string DayShortName(short DayOrderOfTheWeek)
	{
		string arrDayShortName[] = { "Sun","Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return arrDayShortName[DayOrderOfTheWeek];
	}
	string DayShortName()
	{
		return DayShortName(DayOrderOfTheWeek());
	}

	static string MonthShortName(short MonthNumber)
	{
		string Months[12] = { "Jan", "Feb", "Mar",
						   "Apr", "May", "Jun",
						   "Jul", "Aug", "Sep",
						   "Oct", "Nov", "Dec"
		};

		return (Months[MonthNumber - 1]);
	}
	string MonthShortName()
	{

		return MonthShortName(_Month);
	}

	static void PrintMonthCalender(short Month, short Year)
	{
		int NumberOfDays;

		// Index of the day from 0 to 6
		int current = DayOrderOfTheWeek(1, Month, Year);

		NumberOfDays = NumberOfDaysInMonth(Month, Year);

		// Print the current month name
		printf("\n  _______________%s_______________\n\n",
			MonthShortName(Month).c_str());

		// Print the columns
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		// Print appropriate spaces
		int i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);


			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n  _________________________________\n");
	}
	void PrintMonthCalender()
	{
		PrintMonthCalender(_Month, _Year);
	}

	static void PrintYearCalender(short Year)
	{
		cout << "\n  ________________________________\n\n";
		cout << "              Calender - " << Year << "\n\n";
		cout << "\n  ________________________________\n\n";

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalender(i, Year);
		}
	}
	void PrintYearCalender()
	{
		cout << "\n  ________________________________\n\n";
		cout << "              Calender - " << _Year << "\n\n";
		cout << "\n  ________________________________\n\n";

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalender(i, _Year);
		}
	}

	static short NumberOfDaysSinceTheBeginningOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;

		for (short i = 1; i < Month; i++)
		{
			TotalDays += NumberOfDaysInMonth(i, Year);
		}
		TotalDays += Day;
		return TotalDays;
	}
	short NumberOfDaysSinceTheBeginningOfTheYear()
	{
		return NumberOfDaysSinceTheBeginningOfTheYear(_Day, _Month, _Year);
	}

	static clsDate ConvertTotalDaysToDate(short TotalDays, short Year)
	{
		clsDate Date;

		Date._Year = Year;
		Date._Month = 1;

		while (TotalDays > NumberOfDaysInMonth(Date._Month, Year))
		{
			TotalDays -= NumberOfDaysInMonth(Date._Month, Year);
			Date._Month++;
		}
		Date._Day = TotalDays;
		return Date;
	}

	static clsDate AddDaysToDate(short DaysToAdd, short Day, short Month, short Year)
	{
		clsDate Date;
		Date._Day = Day;
		Date._Month = Month;
		Date._Year = Year;

		short RemainingDays = DaysToAdd + NumberOfDaysSinceTheBeginningOfTheYear(Date._Day, Date._Month, Date._Year);
		Date._Month = 1;

		while (true)
		{
			short MonthDays = NumberOfDaysInMonth(Date._Month, Date._Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;

				if (Date._Month > 12)
				{
					Date._Year++;
					Date._Month = 1;
				}
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}
		return Date;
	}
	clsDate AddDaysToDate(short DaysToAdd)
	{
		return AddDaysToDate(DaysToAdd, _Day, _Month, _Year);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year < Date2._Year ? true : (Date1._Year == Date2._Year ?
			(Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ?
				Date1._Day < Date2._Day : false)) : false));
	}
	bool IsDateBeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Day == Date2._Day) && (Date1._Month == Date2._Month) && (Date1._Year == Date2._Year);
	}
	bool IsDateEqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		return Date._Day == NumberOfDaysInMonth(Date._Month, Date._Year);
	}
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(clsDate Date)
	{
		return Date._Month == 12;
	}
	bool IsLastMonthInYear()
	{
		return this->_Month == 12;
	}

	static clsDate AddOneDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date))
			{
				Date._Day = 1, Date._Month = 1, Date._Year++;
			}
			else
			{
				Date._Day = 1; Date._Month++;
			}
		}
		else
		{
			Date._Day++;
		}
		return Date;
	}
	void AddOneDay()
	{
		*this = AddOneDay(*this);
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}

	static short GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		short Difference = 0;
		short SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Difference++;
			Date1 = AddOneDay(Date1);
		}
		return IncludeEndDay ? ++Difference * SwapFlagValue : ++Difference * SwapFlagValue;
	}
	short GetDifferenceInDays(clsDate Date2)
	{
		return GetDifferenceInDays(*this, Date2);
	}

	static int CalculateMyAgeInDays(clsDate Date)
	{
		return GetDifferenceInDays(Date, clsDate::GetSystemDate());
	}

	static int CalculateDifferenceBetween2Dates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1EqualDate2(Date1, Date2))
			return 0;

		if (IsDate1BeforeDate2(Date1, Date2))
		{
			return GetDifferenceInDays(Date1, Date2);
		}
		else
		{
			// Date1 is after Date2
			return GetDifferenceInDays(Date2, Date1);
		}
	}
	int CalculateDifferenceBetween2Dates(clsDate Date2)
	{
		return CalculateDifferenceBetween2Dates(*this, Date2);
	}

	static clsDate IncreaseDateByXDays(clsDate Date, short DaysToAdd)
	{
		for (short i = 1; i <= DaysToAdd; i++)
		{
			Date = AddOneDay(Date);
		}
		return Date;
	}
	void IncreaseDateByXDays(short DaysToAdd)
	{
		*this = IncreaseDateByXDays(*this, DaysToAdd);
	}

	static clsDate IncreaseDateByOneWeek(clsDate Date)
	{
		return IncreaseDateByXDays(Date, 7);
	}
	void IncreaseDateByOneWeek()
	{
		*this = IncreaseDateByXDays(*this, 7);
	}

	static clsDate IncreaseDateByXWeeks(clsDate Date, short WeeksToAdd)
	{
		for (short i = 1; i <= WeeksToAdd; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void IncreaseDateByXWeeks(short WeeksToAdd)
	{
		*this = IncreaseDateByXWeeks(*this, WeeksToAdd);
	}

	static clsDate IncreaseDateByOneMonth(clsDate Date)
	{
		return IncreaseDateByXDays(Date, NumberOfDaysInMonth(Date._Month, Date._Year));
	}
	void IncreaseDateByOneMonth()
	{
		*this = IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXMonths(clsDate Date, short MonthsToAdd)
	{
		for (short i = 1; i <= MonthsToAdd; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void IncreaseDateByXMonths(short MonthsToAdd)
	{
		*this = IncreaseDateByXMonths(*this, MonthsToAdd);
	}

	static clsDate IncreaseDateByOneYear(clsDate Date)
	{
		Date = IncreaseDateByXMonths(Date, 12);
		return Date;
	}
	void IncreaseDateByOneYear()
	{
		*this = IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(clsDate Date, short YearsToAdd)
	{
		for (short i = 1; i <= YearsToAdd; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}
	void IncreaseDateByXYears(short YearsToAdd)
	{
		*this = IncreaseDateByXYears(*this, YearsToAdd);
	}

	static clsDate IncreaseDateByOneDeacade(clsDate Date)
	{
		Date._Year += 10;
		return Date;
	}
	void IncreaseDateByOneDeacade()
	{
		this->_Year += 10;
	}

	static clsDate IncreaseDateByXDecades(clsDate Date, short DecadesToAdd)
	{
		Date._Year += (DecadesToAdd * 10);
		return Date;
	}
	void IncreaseDateByXDecades(short DecadesToAdd)
	{
		this->_Year += (DecadesToAdd * 10);
	}

	static clsDate IncreaseDateByOneCentury(clsDate Date)
	{
		Date._Year += 100;
		return Date;
	}
	void IncreaseDateByOneCentury()
	{
		this->_Year += 100;
	}

	static clsDate IncreaseDateByOneMillennium(clsDate Date)
	{
		Date._Year += 1000;
		return Date;
	}
	void IncreaseDateByOneMillennium()
	{
		this->_Year += 1000;
	}

	static clsDate DecreaseDateByOneDay(clsDate Date)
	{
		short FirstDay = 1;
		short FirstMonth = 1;

		if (Date._Day == 1)
		{
			if (Date._Month == 1)
			{
				Date._Day = 31;
				Date._Month = 12;
				Date._Year--;
			}
			else
			{
				Date._Month--;
				Date._Day = NumberOfDaysInMonth(Date._Month, Date._Year);
			}
		}
		else
		{
			Date._Day--;
		}
		return Date;
	}
	void DecreaseDateByOneDay()
	{
		*this = DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDays(clsDate Date, short NumberOfDays)
	{
		for (short i = 1; i <= NumberOfDays; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void DecreaseDateByXDays(short NumberOfDays)
	{
		*this = DecreaseDateByXDays(*this, NumberOfDays);
	}

	static clsDate DecreaseDateByOneWeek(clsDate Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void DecreaseDateByOneWeek()
	{
		*this = DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(clsDate Date, short NumberOfWeeks)
	{
		for (short i = 1; i <= NumberOfWeeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void DecreaseDateByXWeeks(short NumberOfWeeks)
	{
		*this = DecreaseDateByXWeeks(*this, NumberOfWeeks);
	}

	static clsDate DecreaseDateByOneMonth(clsDate Date)
	{
		return DecreaseDateByXDays(Date, NumberOfDaysInMonth(Date._Month, Date._Year));
	}
	void DecreaseDateByOneMonth()
	{
		*this = DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonths(clsDate Date, short NumbeOfMonths)
	{
		for (short i = 1; i <= NumbeOfMonths; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void DecreaseDateByXMonths(short NumbeOfMonths)
	{
		*this = DecreaseDateByXMonths(*this, NumbeOfMonths);
	}

	static clsDate DecreaseDateByOneYear(clsDate Date)
	{
		Date._Year--;
		return Date;
	}
	void DecreaseDateByOneYear()
	{
		*this = DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(clsDate Date, short NumberOfYears)
	{
		for (short i = 1; i <= NumberOfYears; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}
	void DecreaseDateByXYears(short NumberOfYears)
	{
		*this = DecreaseDateByXYears(*this, NumberOfYears);
	}

	static clsDate DecreaseDateByOneDeacade(clsDate Date)
	{
		Date._Year -= 10;
		return Date;
	}
	void DecreaseDateByOneDeacade()
	{
		this->_Year -= 10;
	}

	static clsDate DecreaseDateByXDecades(clsDate Date, short DecadesToAdd)
	{
		Date._Year -= (DecadesToAdd * 10);
		return Date;
	}
	void DecreaseDateByXDecades(short DecadesToAdd)
	{
		this->_Year -= (DecadesToAdd * 10);
	}

	static clsDate DecreaseDateByOneCentury(clsDate Date)
	{
		Date._Year -= 100;
		return Date;
	}
	void DecreaseDateByOneCentury()
	{
		this->_Year -= 100;
	}

	static clsDate DecreaseDateByOneMillennium(clsDate Date)
	{
		Date._Year -= 1000;
		return Date;
	}
	void DecreaseDateByOneMillennium()
	{
		this->_Year -= 1000;
	}

	static bool IsEndOfWeek(clsDate Date)
	{
		short DayOrder = DayOrderOfTheWeek(Date);
		return DayOrder == 6;
	}
	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date)
	{
		short DayOrder = DayOrderOfTheWeek(Date);
		return (DayOrder == 5) || (DayOrder == 6);
	}
	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date)
	{
		return !IsWeekEnd(Date);
	}
	bool IsBusinessDay()
	{
		return !IsWeekEnd(*this);
	}

	static short DaysUntilEndOfWeek(clsDate Date)
	{
		return 6 - DayOrderOfTheWeek(Date);
	}
	short DaysUntilEndOfWeek()
	{
		return 6 - DayOrderOfTheWeek(*this);
	}

	static short DaysUntilEndOfMonth(clsDate Date)
	{
		return NumberOfDaysInMonth(Date._Month, Date._Year) - Date._Day;
	}
	short DaysUntilEndOfMonth()
	{
		return NumberOfDaysInMonth(this->_Month, this->_Year) - this->_Day;
	}

	static short DaysUntilEndOfYear(clsDate Date)
	{
		clsDate EndOfYearDate;
		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date.Year;

		return GetDifferenceInDays(Date, EndOfYearDate);
	}
	short DaysUntilEndOfYear()
	{
		return NumberOfDaysInYear(this->_Year) - this->_Day;
	}

	static short CountBusinessDays(clsDate DateFrom, clsDate DateTo)
	{
		short Counter = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Counter++;

			DateFrom = AddOneDay(DateFrom);
		}
		return Counter;
	}

	static short CountVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		return CountBusinessDays(DateFrom, DateTo);
	}

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{
		clsDate VacationEndDate = DateFrom;

		while (VacationDays > 0)
		{
			if (IsBusinessDay(VacationEndDate))
			{
				VacationDays--;
			}
			VacationEndDate = AddOneDay(VacationEndDate);
		}
		return VacationEndDate;
	}
	clsDate CalculateVacationReturnDate(short VacationDays)
	{
		return CalculateVacationReturnDate(*this, VacationDays);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return !(IsDate1BeforeDate2(Date1, Date2) || IsDate1EqualDate2(Date1, Date2));
		//return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}

	enum enDatesCompare { Before = -1, Equal = 0, After = 1 };

	static enDatesCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDatesCompare::Before;
		else if (IsDate1EqualDate2(Date1, Date2))
			return enDatesCompare::Equal;
		else
			return enDatesCompare::After;
	}
	enDatesCompare CompareDates(clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}
	
	static bool IsValidDate(clsDate Date)
	{
		/*return !(Date._Month > 12 || Date._Day > NumberOfDaysInMonth(Date._Month, Date._Year));
		return !(Date._Month > 12) && !(Date._Day > NumberOfDaysInMonth(Date._Month, Date._Year));*/
		if (Date._Day < 1 || Date._Day > NumberOfDaysInMonth(Date._Month, Date._Year))
			return false;
		if (Date._Month < 1 || Date._Month > 12)
			return false;
	}
	bool IsValid()
	{
		return IsValidDate(*this);
	}

	static string FormatDate(clsDate Date, string DateFormat = "dd/mm/yyyy")
	{
		string FormattedString = "";
		FormattedString = clsString::ReplaceWord(DateFormat, "dd", to_string(Date._Day));
		FormattedString = clsString::ReplaceWord(FormattedString, "mm", to_string(Date._Month));
		FormattedString = clsString::ReplaceWord(FormattedString, "yyyy", to_string(Date._Year));
		return FormattedString;
	}
	string FormatDate(string DateFormat = "dd/mm/yyyy")
	{
		return FormatDate(*this, DateFormat);
	}
};

class clsPeriod
{
	clsDate StartDate;
	clsDate EndDate;

	clsPeriod(clsDate StartDate, clsDate EndDate)
	{
		this->StartDate = StartDate;
		this->EndDate = EndDate;
	}

	static bool IsOverLapPeriods(clsPeriod Period1, clsPeriod Period2)
	{
		if (clsDate::IsDate1AfterDate2(Period1.StartDate, Period2.EndDate)
			||
			clsDate::IsDate1BeforeDate2(Period1.EndDate, Period2.StartDate))
			return false;
		else
			return true;
	}
	bool IsOverLapWith(clsPeriod Period2)
	{
		return IsOverLapPeriods(*this, Period2);
	}

	static short PeriodLengthInDays(clsPeriod Period)
	{
		short Counter = 0;
		while (clsDate::IsDate1BeforeDate2(Period.StartDate, Period.EndDate))
		{
			Counter++;
			Period.StartDate = clsDate::AddOneDay(Period.StartDate);
		}
		return Counter;
	}
	short PeriodLengthInDays(clsDate EndDate)
	{
		return PeriodLengthInDays(*this);
	}

	static short IsDateInPeriod(clsPeriod Period, clsDate Date)
	{
		return !(clsDate::CompareDates(Date, Period.StartDate) == clsDate::enDatesCompare::Before ||
			clsDate::CompareDates(Date, Period.EndDate) == clsDate::enDatesCompare::After);
	}
	short IsDateInPeriod(clsDate Date)
	{
		return IsDateInPeriod(*this, Date);
	}

	static short CountOverLapDays(clsPeriod Period1, clsPeriod Period2)
	{
		short Counter = 0;

		if (!IsOverLapPeriods(Period1, Period2))
			return 0;

		if (PeriodLengthInDays(Period1) < PeriodLengthInDays(Period2))
		{
			while (IsOverLapPeriods(Period1, Period2) && clsDate::IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
			{
				if (IsDateInPeriod(Period2, Period1.StartDate))
				{
					Counter++;
				}
				Period1.StartDate = clsDate::AddOneDay(Period1.StartDate);
			}
		}
		else
		{
			while (IsOverLapPeriods(Period1, Period2) && clsDate::IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
			{
				if (IsDateInPeriod(Period1, Period2.StartDate))
				{
					Counter++;
				}
				Period2.StartDate = clsDate::AddOneDay(Period2.StartDate);
			}
		}
		return Counter;
	}

	void Print()
	{
		cout << "Period Start: ";
		StartDate.Print();


		cout << "Period End: ";
		EndDate.Print();
	}

};