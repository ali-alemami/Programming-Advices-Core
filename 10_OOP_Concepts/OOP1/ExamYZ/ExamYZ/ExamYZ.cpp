#include <iostream>

using namespace std;

float CalculateSlope(float x1, float y1, float x2, float y2)
{
	float slope = (y2 - y1) / (x2 - x1);
	return slope;
}

void IsMultiple(int Num1, int Num2)
{
	if (Num1 < 0 || Num2 < 0)
	{
		cout << "\nInvalid Input.\n";
	}

	else
	{
		if (Num1 > Num2)
		{
			if (Num1 % Num2 == 0)
			{
				cout << Num1 << " is multiple " << Num2 << endl;
				for (int i = Num2; i < Num1; i += i)
				{
					cout << i << " ";
				}
			}
			else
			{
				cout << "\nx is not multiple of y\n";
			}
		}
		else
		{
			if (Num2 % Num1 == 0)
			{
				cout << Num2 << " is multiple " << Num1 << endl;
				for (int i = Num1; i < Num2; i += i)
				{
					cout << i << " ";
				}
			}
			else
			{
				cout << "\nx is not multiple of y\n";
			}
		}
	}

}

int main()
{
	float x1, x2, y1, y2;
	float Slope1, Slope2;

	cout << "\n Line 1:\n";
	cout << "\nPlease Enter x1? ";
	cin >> x1;

	cout << "\nPlease Enter x2? ";
	cin >> y1;

	cout << "\nPlease Enter y1? ";
	cin >> x2;

	cout << "\nPlease Enter y2? ";
	cin >> y2;

	Slope1 = CalculateSlope(x1, y1, x2, y2);
	cout << "Slope for the first line is: " << Slope1 << endl;

	cout << "\n\n Line 2:\n";
	cout << "\nPlease Enter x1? ";
	cin >> x1;

	cout << "\nPlease Enter x2? ";
	cin >> y1;

	cout << "\nPlease Enter y1? ";
	cin >> x2;

	cout << "\nPlease Enter y2? ";
	cin >> y2;

	Slope2 = CalculateSlope(x1, y1, x2, y2);
	cout << "Slope for the second line is: " << Slope2 << endl;

	if (Slope1 == Slope2)
	{
		cout << "\nLines are Parallel!\n";
	}
	else
	{
		cout << "\nLines are NOT Parallel!\n";
	}



	int Num1, Num2;

	cout << "Enter Num1: ";
	cin >> Num1;

	cout << "Enter Num2: ";
	cin >> Num2;

	IsMultiple(Num1, Num2);

	return 0;
}