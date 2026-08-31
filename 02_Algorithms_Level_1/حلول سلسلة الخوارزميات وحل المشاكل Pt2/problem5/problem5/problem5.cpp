#include <iostream>
using namespace std;

struct stInfo
{
	int Age;
	bool HasDrivingLicense;
	bool VIP;
};

stInfo ReadInfo()
{
	stInfo Info;

	cout << "Enter age ";
	cin >> Info.Age;

	cout << "Driving License? ";
	cin >> Info.HasDrivingLicense;

	cout << "VIP?";
	cin >> Info.VIP;

	return Info;
}

bool IsAccepted(stInfo Info)
{
	if (Info.VIP)
		return true;
	return (Info.Age >= 21 && Info.HasDrivingLicense);
}

void PrintResult(stInfo Info)
{
	if (IsAccepted(Info))
	{
		cout << "HIRED";
	}
	else
		cout << "REJECTED";
}

int main()
{
	PrintResult(ReadInfo());
	return 0;
}