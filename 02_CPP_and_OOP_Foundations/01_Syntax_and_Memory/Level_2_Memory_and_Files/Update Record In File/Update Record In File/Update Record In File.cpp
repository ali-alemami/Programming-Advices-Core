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

void SaveVectorToFile(string FileName, vector <string> vFileContnet)
{
	fstream AliFile;

	AliFile.open(FileName, ios::out);

	if (AliFile.is_open())
	{
		for (string& Line : vFileContnet)
		{
			if (Line != "")
			{
				AliFile << Line << endl;
			}
		}
		AliFile.close();
	}
}

void UpdateRecordInFile(string FileName, string Record, string UpdateTo)
{
	vector <string> vFileContent;

	LoadDataFromFileToVector(FileName, vFileContent);

	for (string& Line : vFileContent)
	{
		if (Line == Record)
		{
			Line = UpdateTo;
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
	cout << "\n\n\n";

	UpdateRecordInFile("AliFile.txt", "ali", "ALI");

	PrintFileContent("AliFile.txt");

	return 0;
}