#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void SaveVectorToFile(string FileName, vector <string> vFileContent)
{
	fstream AliFile;

	AliFile.open(FileName, ios::out);

	if (AliFile.is_open())
	{
		for (string& Line : vFileContent)
		{
			if (Line != "")
			{
				AliFile << Line << endl;
			}
		}
		AliFile.close();
	}
}

int main()
{
	vector <string> vFileContent{ "ali", "a2","a3" };

	SaveVectorToFile("AliFile.txt", vFileContent);

	return 0;
}