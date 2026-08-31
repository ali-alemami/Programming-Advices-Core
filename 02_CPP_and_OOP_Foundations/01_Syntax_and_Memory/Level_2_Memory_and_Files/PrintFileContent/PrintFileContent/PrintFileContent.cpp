#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void PrintFileContent(string FileName)
{
	fstream AliFile;

	AliFile.open(FileName, ios::in);

	if (AliFile.is_open())
	{
		string Line;

		while (getline(AliFile, Line))
		{
			cout << Line << endl;
		}
		AliFile.close();
	}
}

int main()
{
	PrintFileContent("AliFile.txt");

	return 0;
}