#include <iostream>
using namespace std;

int main()
{
	int Page = 1, PageNumbers = 20;

	printf("The page number = %d \n", Page);
	printf("YOU ARE IN page %d of %d \n", Page, PageNumbers);
	printf("The page number = %0*d \n", 2, Page);
	printf("The page number = %0*d \n", 3, Page);
	printf("The page number = %0*d \n", 4, Page);
	printf("Thwe page numbweer = %0*d \n", 5, Page);

	int number1 = 20, number2 = 30;

	printf("the result of %0*d + %0*d = %0*d \n", 3, number1, 3, number2, 4, number1 + number2);


	printf("\n\n\n3ELLAWI 7ABIB QALBI ANNA KHADMKUM IM %04d\n\n\n", 20);




























	return 0;
}