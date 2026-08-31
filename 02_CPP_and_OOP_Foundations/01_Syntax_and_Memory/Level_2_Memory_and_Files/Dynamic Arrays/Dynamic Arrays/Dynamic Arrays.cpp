#include <iostream>
using namespace std;

int main()
{
	int num;

	cout << "Enter total number of students.\n";
	cin >> num;

	float* ptr;

	ptr = new float[num];

	cout << "\nEnter Grades of students.\n";

	for (int i = 0; i < num; i++)
	{
		cout << "Student " << i + 1 << ":\n";
		cin >> *(ptr + i);
	}

	cout << "\nPrtint Array elements.\n\n";

	for (int i = 0; i < num; i++)
	{
		cout << "Student " << i + 1 << ": " << *(ptr + i) << endl;
	}

	delete[] ptr;

	return 0;
}