#include <iostream>
using namespace std;

struct stInfo
{
	int Age = 0;
	bool HasDriveingLicense = 0;
};

stInfo ReadInfo()
{
	stInfo Info;

	cout << "How old are you? ";
	cin >> Info.Age;

	cout << "Do you have driving licence? ";
	cin >> Info.HasDriveingLicense;

	return Info;
}

bool IsAccepted(stInfo Info)
{
	return (Info.Age >= 21 && Info.HasDriveingLicense);
}

void PrintResult(stInfo Info)
{
	if (IsAccepted(Info))
		cout << "\n Hired\n";
	else
		cout << "\n Rejected\n";
}

int main()
{
	PrintResult(ReadInfo());

	return 0;
}