#include <iostream>
using namespace std;

int main()
{
	cout << "how many students?\n";
	float studentsnumber, mark;
	cin >> studentsnumber;
	float lowestmark = 100, highestmark = 0;
	float sum = 0, totalcounter = 0, countpass = 0, countfail = 0;
	for (int i = 1; i <= studentsnumber; i++)
	{
		cout << "enter student number " << i << " mark\n";
		cin >> mark;
		if (mark >= 50)
		{
			cout << "PASS\n";
			countpass++;
			sum += mark;
			if (mark > highestmark)
			{
				highestmark = mark;
			}
		}
		else
		{
			cout << "FAIL\n";
			countfail++;
			sum += mark;
			if (mark < lowestmark)
			{
				lowestmark = mark;
			}
		}
		totalcounter++;	
	}
	cout << "the number of passed students is " << countpass << endl;
	cout << "the number of failed students is " << countfail << endl;

	cout << "the highest mark is " << highestmark << endl;
	cout << "the lowest mark is " << lowestmark << endl;

	float average = sum / totalcounter;
	cout << "The average is " << average << endl;

	return 0;
}