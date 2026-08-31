#include <iostream>
using namespace std;

enum enWeekDay { sun = 1, mon = 2, tue = 3, wed = 4, thu = 5, fri = 6, sut = 7 };
void ShowWeekMenu()
{
    cout << "*************************************\n";
    cout << "              Week Days              \n"; 
    cout << "*************************************\n";
    cout << "1: it's Sunday\n";
    cout << "2: it's Monday\n";
    cout << "3: it's Tuesday\n";
    cout << "4: it's Wednsday\n";
    cout << "5: it's Thursday\n";
    cout << "6: it's Friday\n";
    cout << "7: it's Sutarday\n";
    cout << "*************************************\n";
    cout << "Please enter the number of the day\n";
}
enWeekDay ReadWeekDay()
{
    int wk;
    cin >> wk;
    return (enWeekDay)wk;
}

string GetWeekDayName(enWeekDay WeekDay)
{
    switch (WeekDay)
    {
    case enWeekDay::sun:
        return  "Sunday\n";
        break;
    case enWeekDay::mon:
        return "Monday\n";
        break;
    case enWeekDay::tue:
        return "Tuesday\n";
        break;
    case enWeekDay::wed:
        return "Wednsday\n";
        break;
    case enWeekDay::thu:
        return "Thursday\n";
        break;
    case enWeekDay::fri:
        return "Friday\n";
        break;
    case enWeekDay::sut:
        return "Sutarday\n";
        break;
    default:
        return "Wrong day number\n";
    }
    
}
int main()
{
    ShowWeekMenu();
    cout << "Today is " << GetWeekDayName(ReadWeekDay());
    return 0;
}