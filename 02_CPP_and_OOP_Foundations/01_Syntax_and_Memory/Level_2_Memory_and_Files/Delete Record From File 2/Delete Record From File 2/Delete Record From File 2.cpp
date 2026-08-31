#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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

void LoadDataFromFileToVector(string FileName, vector <string>& vFileContnet)
{
	fstream AliFile;

	AliFile.open(FileName, ios::in);

	if (AliFile.is_open())
	{
		string Line;

		while (getline(AliFile, Line))
		{
			vFileContnet.push_back(Line);
		}
		AliFile.close();
	}
}

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

void DeleteRecordFromFile(string FileName, string Record)
{
	vector <string> vFileContent;

	LoadDataFromFileToVector(FileName, vFileContent);

	for (string& Line : vFileContent)
	{
		if (Line == Record)
		{
			Line = "";
		}
	}

	SaveVectorToFile(FileName, vFileContent);
}

int main()
{
	vector <string> vFileContent;

	PrintFileContent("AliFile.txt");

	DeleteRecordFromFile("AliFile.txt", "Ali");

	PrintFileContent("AliFile.txt");

	return 0;
}