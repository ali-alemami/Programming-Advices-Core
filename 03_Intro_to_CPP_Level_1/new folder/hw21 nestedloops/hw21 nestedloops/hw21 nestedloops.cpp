#include <iostream>
using namespace std;
int main()
{
	for (char first = 'A'; first <= 'Z'; first++)
	{
		cout << "--------------------------\n";
		cout << "Letter:" << first << endl;
		for (char second= 'A'; second <= 'Z'; second++)
		{
			cout << first << second << endl;
		}
		
	}
	return 0;
}	