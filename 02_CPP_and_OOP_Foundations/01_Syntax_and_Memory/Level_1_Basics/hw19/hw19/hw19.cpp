#include <iostream>
using namespace std;
void ReadGradesData(float x[2])
{
	cout << "Enter the first Grade\n";
	cin >> x[0];

	cout << "Enter the scond grade\n";
	cin >> x[1];

	cout << "Enter the third grade\n";
	cin >> x[2];

 }

float CalculateAverage(float x[3]) 
{
	return (x[0] + x[1] + x[2]) / 3;
}

int main()
{
	float x[2];

	ReadGradesData(x);

	cout << "***************************\n";

	cout << "The Average of grades is " << CalculateAverage(x) << endl;

	return 0;
}