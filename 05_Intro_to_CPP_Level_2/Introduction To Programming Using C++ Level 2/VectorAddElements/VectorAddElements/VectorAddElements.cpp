#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <int> vNumbers;

	vNumbers.push_back(10);
	vNumbers.push_back(20);
	vNumbers.push_back(30);
	vNumbers.push_back(40);
	vNumbers.push_back(50);
	vNumbers.push_back(60);

	for (int& Number : vNumbers)
	{
		cout << Number << " ";
	}
	cout << endl;
	
	return 0;
}