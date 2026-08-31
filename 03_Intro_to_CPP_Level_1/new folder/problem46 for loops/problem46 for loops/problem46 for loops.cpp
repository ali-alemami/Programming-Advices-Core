#include <iostream>
using namespace std;
void PrintAllLetters()
{
	for (char FirstLetter = 'A'; FirstLetter <= 'Z'; FirstLetter++)
	{
		cout << FirstLetter << endl;
	}
}
int main()
{
	PrintAllLetters();
	return 0;
}
#include <iostream>
using namespace std;
void PrintAllLetters(char FirstLetter)
{
	for (FirstLetter = 'A'; FirstLetter <= 'Z'; FirstLetter++)
	{
		cout << FirstLetter << endl;
	}
}
int main(char FirstLetter)
{
	PrintAllLetters(FirstLetter);
	return 0;
}