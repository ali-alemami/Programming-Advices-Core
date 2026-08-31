#include<iostream>
using namespace std;
int main()
{
	cout << "Please enter the number of seconds\n";
	unsigned long int numberofseconds;
	cin >> numberofseconds;
	unsigned long int numberofdays = numberofseconds / (60 * 60 * 24);
	unsigned long int numberofhours = (numberofseconds % (60 * 60 * 24)) / (60 * 60);
	unsigned short int numberofminutes = (numberofseconds % (60 * 60 * 24)) % (60 * 60)/ 60;
	unsigned short int remainder= (numberofseconds % (60 * 60 * 24)) % (60 * 60) % 60;
	cout << numberofdays << ":" << numberofhours << ":" << numberofminutes << ":" << remainder << endl;
	return 0;
}