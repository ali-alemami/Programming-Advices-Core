#include <iostream>
using namespace std;

int main()
{
	int Number = -1;
	string Result = "";

	Result = (Number > 0) ? "Positive" : "Negative";

	cout << Result <<  endl;

	Result = (Number == 0) ? "Number is zero " : (Number > 0) ? "Positive" : "Negative";

	cout << Result << endl;

	return 0;
}