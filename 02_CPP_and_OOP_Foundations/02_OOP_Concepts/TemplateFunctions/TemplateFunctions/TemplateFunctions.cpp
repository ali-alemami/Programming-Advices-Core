#include <iostream>

using namespace std;

template <typename T> T MyMax(T Number1, T Number2)
{
	return Number1 > Number2 ? Number1 : Number2;
}



template <class T>
class clsCalculator
{
private:

	T _Number1;
	T _Number2;

public:

	clsCalculator(T N1, T N2)
	{
		_Number1 = N1;
		_Number2 = N2;
	}

	T Add()
	{
		return _Number1 + _Number2;
	}

	T Subtract()
	{
		return _Number1 - _Number2;
	}

	T Mul()
	{
		return _Number1 * _Number2;
	}

	void Print()
	{
		cout << "\nResults:\n\n";
		cout << _Number1 << " + " << _Number2 << " = " << Add() << endl;
		cout << _Number1 << " - " << _Number2 << " = " << Subtract() << endl;
		cout << _Number1 << " * " << _Number2 << " = " << Mul() << endl;
	}
};


int main()
{
	/*cout << MyMax<int>(1, 12) << endl;
	cout << MyMax<double>(2.3, 1.9) << endl;
	cout << MyMax<char>('1', '5');*/


	clsCalculator <int> intCalc(1, 2);
	clsCalculator <float> floatCalc(1.4, 2.1);

	intCalc.Print();
	floatCalc.Print();
}