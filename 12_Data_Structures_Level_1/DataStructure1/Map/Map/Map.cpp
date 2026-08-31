#include <iostream>
#include <map>

using namespace std;

int main()
{
	map <string, int> StudentsGrades;

	StudentsGrades["Mohammad"] = 5;
	StudentsGrades["Ali"] = 3;
	StudentsGrades["Fadi"] = 2;

	for (const auto& Pair : StudentsGrades)
	{
		cout << "Name: " << Pair.first << " Grade: " << Pair.second << endl;
	}

	string StudentName = "Ali";

	if (StudentsGrades.find(StudentName) != StudentsGrades.end())
	{
		cout << StudentsGrades[StudentName];
	}
	else
	{
		cout << "Not Found";
	}
}