#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace MyDateLib
{
	short ReadYear()
	{
		short Year = 0;
		cout << "Enter a year? ";
		cin >> Year;
		return Year;
	}

	short ReadMonth()
	{
		short Month = 0;
		cout << "Enter a Month? ";
		cin >> Month;
		return Month;
	}

	short ReadDay()
	{
		short Day = 0;
		cout << "Enter a Day? ";
		cin >> Day;
		return Day;
	}

	struct stDate
	{
		short Year,
			Month,
			Day;
	};

	stDate ReadFullDate()
	{
		stDate Date;

		Date.Day = ReadDay();
		Date.Month = ReadMonth();
		Date.Year = ReadYear();

		return Date;
	}

	bool IsLeapYear(short Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}

	short NumberOfDaysInMonth(short Month, short Year)
	{
		if (Month < 1 || Month > 12)
		{
			return 0;
		}

		short arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month - 1];
	}

	bool IsLastDayInMonth(stDate Date)
	{
		return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
	}

	bool IsLastMonthInYear(short Month)
	{
		return Month == 12;
	}

	stDate IncreaseDateByOneDay(stDate Date);

	bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true :
			((Date1.Year == Date2.Year) ?
				(Date1.Month < Date2.Month ? true :
					(Date1.Month == Date2.Month ?
						Date1.Day < Date2.Day : false)) :
				false);
	}

	void Swap2Dates(stDate& Date1, stDate& Date2)
	{
		stDate TempDate;

		TempDate.Year = Date1.Year;
		TempDate.Month = Date1.Month;
		TempDate.Day = Date1.Day;

		Date1.Year = Date2.Year;
		Date1.Month = Date2.Month;
		Date1.Day = Date2.Day;

		Date2.Year = TempDate.Year;
		Date2.Month = TempDate.Month;
		Date2.Day = TempDate.Day;
	}

	int GetDifferenceInDate(stDate Date1, stDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		short SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapFlagValue *= -1;
			Swap2Dates(Date1, Date2);
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Date1 = IncreaseDateByOneDay(Date1);
			Days++;
		}

		return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
	}

	stDate GetSystemDate()
	{
		stDate Date;

		time_t t = time(0);
		tm* now = localtime(&t);

		Date.Year = now->tm_year + 1900;
		Date.Month = now->tm_mon + 1;
		Date.Day = now->tm_mday;

		return Date;
	}

	short NumberOfDaysSinceTheBeginningOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;

		for (short i = 1; i < Month; i++)
		{
			TotalDays += NumberOfDaysInMonth(i, Year);
		}
		TotalDays += Day;

		return TotalDays;
	}

	short NumberOfDaysSinceTheBeginningOfTheYear(stDate Date)
	{
		return NumberOfDaysSinceTheBeginningOfTheYear(Date.Day, Date.Month, Date.Year);
	}

	string MonthShortName(short Month)
	{
		string arr[12] = { "Jan", "Feb", "Mar", "Apr", "May",
			"Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		return arr[Month - 1];
	}

	string DayShortName(short DayOfWeekOrder)
	{
		string arr[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

		return arr[DayOfWeekOrder];
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	stDate IncreaseDateByOneDay(stDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{
				Date.Year++;
				Date.Month = 1;
				Date.Day = 1;
			}
			else
			{
				Date.Month++;
				Date.Day = 1;
			}
		}
		else
		{
			Date.Day++;
		}
		return Date;
	}

	stDate IncreaseDateByXDays(stDate Date, int HowManyDays)
	{
		for (int i = 1; i <= HowManyDays; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}

	stDate IncreaseDateByOneWeek(stDate Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}

	stDate IncreaseDateByXWeeks(stDate Date, int HowManyWeeks)
	{
		for (int i = 1; i <= HowManyWeeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}

	stDate IncreaseDateByOneMonth(stDate Date)
	{
		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}

		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}

	stDate IncreaseDateByXMonths(stDate Date, int HowManyMonths)
	{
		for (int i = 1; i <= HowManyMonths; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}

	stDate IncreaseDateByOneYear(stDate Date)
	{
		Date.Year++;
		return Date;
	}

	stDate IncreaseDateByXYears(stDate Date, int HowManyYears)
	{
		for (int i = 1; i <= HowManyYears; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}

	stDate IncreaseDateByXYearsFaster(stDate Date, int HowManyYears)
	{
		Date.Year += HowManyYears;
		return Date;
	}

	stDate IncreaseDateByOneDecade(stDate Date)
	{
		Date.Year += 10;
		return Date;
	}

	stDate IncreaseDateByXDecades(stDate Date, int HowManyDecades)
	{
		for (short i = 1; i <= HowManyDecades * 10; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}

	stDate IncreaseDateByXDecadesFaster(stDate Date, int HowManyDecades)
	{
		Date.Year += (HowManyDecades * 10);
		return Date;
	}

	stDate IncreaseDateByOneCentury(stDate Date)
	{
		Date.Year += 100;
		return Date;
	}

	stDate IncreaseDateByOneMillennium(stDate Date)
	{
		Date.Year += 1000;
		return Date;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	bool IsFirstMonthOfYear(short Month)
	{
		return Month == 1;
	}

	bool IsFirstDayInMonth(stDate Date)
	{
		return Date.Day == 1;
	}

	stDate DecreaseDateByOneDay(stDate Date)
	{
		if (IsFirstDayInMonth(Date))
		{
			if (IsFirstMonthOfYear(Date.Month))
			{
				Date.Year--;
				Date.Month = 12;
				Date.Day = 31;
			}
			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
			}
		}
		else
		{
			Date.Day--;
		}
		return Date;
	}

	stDate DecreaseDateByXDays(stDate Date, int HowManyDays)
	{
		for (int i = 1; i <= HowManyDays; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	stDate DecreaseDateByOneWeek(stDate Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	stDate DecreaseDateByXWeeks(stDate Date, int HowManyWeeks)
	{
		for (int i = 1; i <= HowManyWeeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}

	stDate DecreaseDateByOneMonth(stDate Date)
	{
		if (Date.Month == 1)
		{
			Date.Year--;
			Date.Month = 1;
		}
		else
		{
			Date.Month--;
		}

		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day == NumberOfDaysInCurrentMonth;
		}

		return Date;
	}

	stDate DecreaseDateByXMonths(stDate Date, int HowManyMonths)
	{
		for (int i = 1; i <= HowManyMonths; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	stDate DecreaseDateByOneYear(stDate Date)
	{
		Date.Year--;
		return Date;
	}

	stDate DecreaseDateByXYears(stDate Date, int HowManyYears)
	{
		for (int i = 1; i <= HowManyYears; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}

	stDate DecreaseDateByXYearsFaster(stDate Date, int HowManyYears)
	{
		Date.Year -= HowManyYears;
		return Date;
	}

	stDate DecreaseDateByOneDecade(stDate Date)
	{
		Date.Year -= 10;
		return Date;
	}

	stDate DecreaseDateByXDecades(stDate Date, int HowManyDecades)
	{
		for (int i = 1; i <= HowManyDecades * 10; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}

	stDate DecreaseDateByXDecadesFaster(stDate Date, int HowManyDecades)
	{
		Date.Year -= HowManyDecades * 10;
		return Date;
	}

	stDate DecreaseDateByOneCentury(stDate Date)
	{
		Date.Year -= 100;
		return Date;
	}

	stDate DecreaseDateByOneMillennium(stDate Date)
	{
		Date.Year -= 1000;
		return Date;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a = (14 - Month) / 12;
		short y = Year - a;
		short m = Month + 12 * a - 2;

		short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
		return d;
	}

	short DayOfWeekOrder(stDate Date)
	{
		return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	}

	bool IsEndOfWeek(stDate Date)
	{
		return DayOfWeekOrder(Date) == 6;
	}

	bool IsWeekEnd(stDate Date)
	{
		short DayIndex = DayOfWeekOrder(Date);
		return (DayIndex == 5 || DayIndex == 6);
	}

	bool IsBusinessDay(stDate Date)
	{
		/*short DayIndex = DayOfWeekOrder(Date);
		return !(DayIndex == 5 || DayIndex == 6);*/

		return !IsWeekEnd(Date);
	}

	short DaysUntilEndOfWeek(stDate Date)
	{
		return 6 - DayOfWeekOrder(Date);
	}

	short DaysUntilEndOfMonth(stDate Date)
	{
		//return NumberOfDaysInMonth(Date.Month, Date.Year) - Date.Day +1;

		stDate EndOfMonthDate;
		EndOfMonthDate.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
		EndOfMonthDate.Month = Date.Month;
		EndOfMonthDate.Year = Date.Year;

		return GetDifferenceInDate(Date, EndOfMonthDate, true);
	}

	short DaysUntilEndOfYear(stDate Date)
	{
		/*return IsLeapYear(Date.Year) ?
			(366 - NumberOfDaysSinceTheBeginningOfTheYear(Date) + 1)
			: (365 - NumberOfDaysSinceTheBeginningOfTheYear(Date) + 1);*/

		stDate EndOfYearDate;
		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date.Year;

		return GetDifferenceInDate(Date, EndOfYearDate, true);
	}

	short CalculateVacationDays(stDate DateFrom, stDate DateTo)
	{
		short VacationDaysCount = 0;

		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (!IsWeekEnd(DateFrom))
			{
				VacationDaysCount++;
			}
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}
		return VacationDaysCount;
	}

	short ReadVacationDays()
	{
		short Days = 0;
		cout << "Enter vacation days? ";
		cin >> Days;
		return Days;
	}

	stDate CalculateVacationReturnDate(stDate DateFrom, short VacationDays)
	{
		while (VacationDays != 0)
		{
			if (IsBusinessDay(DateFrom))
			{
				--VacationDays;
			}
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}
		return DateFrom;
	}

	stDate CalculateVacationReturnDate2(stDate DateFrom, short VacationDays)
	{
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		short WeekEndCounter = 0;

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{
			if (IsWeekEnd(DateFrom))
			{
				WeekEndCounter++;
			}
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}
		return DateFrom;
	}

	bool IsDate1EqualDate2(stDate Date1, stDate Date2)
	{
		//return ((Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day));

		return ((Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false);
	}

	bool IsDate1AfterDate2(stDate Date1, stDate Date2)
	{
		/*Swap2Dates(Date1, Date2);

		return IsDate1BeforeDate2(Date1, Date2);*/

		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	enDateCompare CompareDates(stDate Date1, stDate Date2)
	{
		return IsDate1BeforeDate2(Date1, Date2) ? enDateCompare::Before : (IsDate1EqualDate2(Date1, Date2) ? enDateCompare::Equal : enDateCompare::After);
	}

	struct stPeriod
	{
		stDate StartDate;
		stDate EndDate;
	};

	stPeriod ReadPeriod()
	{
		stPeriod Period;

		cout << "\nEnter Start Date:\n";
		Period.StartDate = ReadFullDate();
		cout << "\nEnter End Date:\n";
		Period.EndDate = ReadFullDate();
		return Period;
	}

	bool AreTwoPeriodsOverLap(stPeriod FirstPeriod, stPeriod SecondPeriod)
	{
		if (
			CompareDates(SecondPeriod.EndDate, FirstPeriod.StartDate) == enDateCompare::Before
			||
			CompareDates(SecondPeriod.StartDate, FirstPeriod.EndDate) == enDateCompare::After
			)
			return false;
		else
			return true;
	}

	short PeriodLengthInDays(stPeriod Period, bool IncludeEndDay = false)
	{
		return GetDifferenceInDate(Period.StartDate, Period.EndDate, IncludeEndDay);
	}

	bool IsDateWithinPeriod(stPeriod Period, stDate Date)
	{
		/*if (CompareDates(Period.StartDate, Date) == enDateCompare::Equal || CompareDates(Period.EndDate, Date) == enDateCompare::Equal)
			return true;

		else if (CompareDates(Period.StartDate, Date) == enDateCompare::Before && CompareDates(Period.EndDate, Date) == enDateCompare::After)
			return true;

		else
			return false;*/

		return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before
			|| CompareDates(Date, Period.EndDate) == enDateCompare::After);
	}

	short CountOverLapDays(stPeriod Period1, stPeriod Period2)
	{
		int Period1Length = PeriodLengthInDays(Period1, true);
		int Period2Length = PeriodLengthInDays(Period2, true);
		short OverLapDays = 0;

		if (!AreTwoPeriodsOverLap(Period1, Period2))
		{
			return 0;
		}

		if (Period1Length < Period2Length)
		{
			while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
			{
				if (IsDateWithinPeriod(Period2, Period1.StartDate))
					OverLapDays++;

				Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
			}
		}
		else
		{
			while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
			{
				if (IsDateWithinPeriod(Period1, Period2.StartDate))
					OverLapDays++;

				Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
			}
		}
		return OverLapDays;
	}

	bool IsValidDate(stDate Date)
	{
		if (Date.Day < 1 || Date.Day > 31)
			return false;

		if (Date.Month < 1 || Date.Month > 12)
			return false;

		if (Date.Month == 2)
		{
			if (IsLeapYear(Date.Year))
			{
				if (Date.Day > 29)
					return false;
			}
			else
			{
				if (Date.Day > 28)
					return false;
			}
		}

		short DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

		if (Date.Day > DaysInMonth)
			return false;

		return true;
	}

	string ReadDateString(string Message)
	{
		string DateString = "";

		cout << Message;
		getline(cin >> ws, DateString);

		return DateString;
	}

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

	stDate StringToDate(string DateString)
	{
		vector <string> vDate = SplitString(DateString, "/");

		stDate Date;

		Date.Day = stoi(vDate[0]);
		Date.Month = stoi(vDate[1]);
		Date.Year = stoi(vDate[2]);

		return Date;
	}

	string DateToString(stDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	string ReplaceWordInString(string S1, string OldWord, string NewWord)
	{
		short pos = S1.find(OldWord);

		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, OldWord.length(), NewWord);
			pos = S1.find(OldWord);
		}
		return S1;
	}

	string FormatDate(stDate Date, string DateFormat = "dd/mm/yyyy")
	{
		string FormattedDate = "";
		FormattedDate = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
		FormattedDate = ReplaceWordInString(FormattedDate, "mm", to_string(Date.Month));
		FormattedDate = ReplaceWordInString(FormattedDate, "yyyy", to_string(Date.Year));
		return FormattedDate;
	}
}
