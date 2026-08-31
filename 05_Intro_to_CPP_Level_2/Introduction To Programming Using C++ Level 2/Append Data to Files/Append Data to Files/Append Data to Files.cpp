#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream AliFile;

	AliFile.open("AliFile.txt", ios::out | ios::app);

	if (AliFile.is_open())
	{
		AliFile << "HIII\n";
		AliFile << "  a a; i liali ali\n";

		AliFile.close();
	}
	return 0;
}