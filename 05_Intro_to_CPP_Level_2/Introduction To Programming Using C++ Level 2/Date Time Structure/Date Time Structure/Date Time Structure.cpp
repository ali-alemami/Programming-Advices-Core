#pragma warning (disable : 4996)

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	time_t t = time(0);

	tm* now = localtime(&t);

	cout << "year: " << now->tm_year + 1900 << endl;
	cout << "month: " << now->tm_mon + 1 << endl;
	cout << "day: " << now->tm_mday << endl;
	cout << "hour: " << now->tm_hour << endl;
	cout << "Minute : " << now->tm_min << endl;
	cout << " second:" << now->tm_sec << endl;
	cout << "week day " << now->tm_wday << endl;
	cout << "year day : " << now->tm_yday << endl;
	cout << "hours of daylightr " << now->tm_isdst << endl;

	return 0;
}