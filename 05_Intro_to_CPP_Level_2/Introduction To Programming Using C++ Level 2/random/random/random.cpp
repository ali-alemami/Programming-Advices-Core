#include <iostream>
using namespace std;

int main()
{
	int arr[9] = { 1,2,3,4,5,6,7,8,9 };
	
		for (int i = 1, counter = 0; i < 9; i++)
		{
			if (arr[i] % 2 == 0)
			{
				int temp = arr[i];
				arr[i] = arr[counter];
				arr[counter] = temp;
				counter++;
			}
		}

	

	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << " ";
	}
}
