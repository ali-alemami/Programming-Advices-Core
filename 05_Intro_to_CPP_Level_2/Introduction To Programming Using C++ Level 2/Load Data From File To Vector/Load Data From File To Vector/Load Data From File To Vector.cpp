#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void LoadDataFromFileToVector(string FileName, vector <string>& vFileContent)
{
	fstream AliFile;

	AliFile.open(FileName, ios::in);

	if (AliFile.is_open())
	{
		string Line;

		while (getline(AliFile, Line))
		{
			vFileContent.push_back(Line);
		}

		AliFile.close();
	}
}

int main()
{
	vector <string> vFileContent;

	LoadDataFromFileToVector("AliFile.txt", vFileContent);

	for (string& Line : vFileContent)
	{
		cout << Line << endl;
	}

	return 0;
}