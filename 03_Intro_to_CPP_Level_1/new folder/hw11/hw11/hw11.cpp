#include <iostream>
#include <string>
using namespace std;
int main()
{
	string st1 = "43.22";
	double n1 = stod(st1);
	float n2 = stof(st1);
	int n3 = stoi(st1);

	cout << n1 << endl << n2 << endl << n3 << endl;




	int number1 = 20;
	string str1;
	str1 = to_string(number1);

	double number2 = 33.5;
	string str2 = to_string(number2);
	cout << str1 << endl << str2 << endl;




	float number3 = 55.23;
	string str3 = to_string(number3);
	cout << str3 << endl;


	int a;
	a = number3;
	a = int(number3);
	a = (int)number3;
	cout << a << endl;
}