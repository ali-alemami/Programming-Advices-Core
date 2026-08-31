#include <iostream>
#include <vector>
#include <string>
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

	DeleteRecordFromFile("AliFile.txt", "hi");

	PrintFileContent("AliFile.txt");

	return 0;
}