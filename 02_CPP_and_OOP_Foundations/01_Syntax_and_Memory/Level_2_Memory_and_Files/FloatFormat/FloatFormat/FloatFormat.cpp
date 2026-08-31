#include <iostream>
using namespace std;

int main()
{
	float PI = 3.14159265;

	printf("Precision specification of %.*f\n", 1, PI);
	printf("Precision specification of %.*f\n", 2, PI);
	printf("Precision specification of %.*f\n", 3, PI);
	printf("                           %.*f\n", 4, PI);

	float x = 7.0, y = 9.0;

	printf("division of %.3f / %.3f is %.3f \n\n", x, y, x / y);

	double d = 12.45;

	printf("value is %.3f", d);
	cout << endl;

	printf("value is %.4f", d);
	cout << endl;
	printf("value is %.*f", 4, d);

	printf("\n\n\n3llawi 7abib kalbi im %.5f\n\n\n", 20.1);

	return 0;
}