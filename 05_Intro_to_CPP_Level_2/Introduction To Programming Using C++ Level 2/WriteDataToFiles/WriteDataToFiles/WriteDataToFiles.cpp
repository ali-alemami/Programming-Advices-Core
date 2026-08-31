#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream AliFile;

	AliFile.open("AliFile.txt", ios::out);

	if (AliFile.is_open())
	{
		AliFile << "HIIII\n";

		AliFile.close();
	}

	return 0;
}