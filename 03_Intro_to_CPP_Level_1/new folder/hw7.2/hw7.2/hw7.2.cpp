#include <iostream>
using namespace std;
int main()
{
	bool result1;
	result1 = (5 > 6 && 7 == 7) || (1 || 0);
	bool result2;
	result2 = !(5 > 6 && 7 == 7) || (1 || 0);
	bool result3;
	result3 = !(5 > 6 && 7 == 7) || !(1 || 0);
	bool result4;
	result4 = !(5 > 6 || 7 == 7) && !(1 || 0);
	bool result5;
	result5 = ((5 > 6 && !(7 <= 8)) || (8 > 1 && 4 <= 3)) && 1;
	bool result6;
	result6 = ((5 > 6 && !(7 <= 8)) && (8 > 1 || 4 <= 3)) || 1;
	cout << result1 << endl << result2 << endl << result3 << endl << result4 << endl << result5 << endl << result6 << endl;
	return 0;
}