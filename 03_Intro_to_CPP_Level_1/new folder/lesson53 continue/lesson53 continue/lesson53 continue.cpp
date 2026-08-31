#include <iostream>
using namespace std;
int main()
{
	int sum = 0;
	int arr[5] = { 10,20,55,10,20 };
	for (int i = 0; i < 5; i++)
	{

		if (arr[i] >= 50)
		{
			continue;
		}
		sum += arr[i];
	}
	cout << sum;
	return 0;
}