#include <iostream>
using namespace std;

int main()
{
	char name[] = "Ali Alemame";
	char schoolName[] = "Programming Advices";

	printf("name is : %s\n", name);
	printf("School name is : %s\n", schoolName);

	char Letter = 'A';

	printf("char is : %*c\n\n", 1, Letter);
	printf("char is : %*c\n", 5, Letter);

	return 0;
}