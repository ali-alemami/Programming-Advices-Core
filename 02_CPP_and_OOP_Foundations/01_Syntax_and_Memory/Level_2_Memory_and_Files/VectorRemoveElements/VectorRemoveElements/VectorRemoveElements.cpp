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


	cout << "Size = " << vNumbers.size() << endl;

	vNumbers.pop_back();
	vNumbers.pop_back();
	vNumbers.pop_back();
	vNumbers.pop_back();

	cout << "Size = " << vNumbers.size() << endl;

	if (!vNumbers.empty())
	{
		vNumbers.pop_back();
	}
	vNumbers.push_back(10);
	vNumbers.push_back(20);
	vNumbers.push_back(30);
	vNumbers.push_back(40);
	vNumbers.push_back(50);
	vNumbers.push_back(60);
	vNumbers.push_back(70);
	cout << "\n_________________________\n";

	cout << vNumbers.front() << endl;
	cout << vNumbers.back() << endl;

	cout << vNumbers.size() << endl;
	cout << vNumbers.capacity() << endl;
	cout << "\n_________________________\n";



	for (int& Number : vNumbers)
	{
		cout << Number << endl;
	}
}