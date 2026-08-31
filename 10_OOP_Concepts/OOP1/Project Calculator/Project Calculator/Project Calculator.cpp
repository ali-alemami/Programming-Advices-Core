#include <iostream>

using namespace std;

class clsCalculator 
{
private:

	int _Result = 0;
	int _LastNumber = 0;
	string _LastOperation = "Clear";
	int _PreviosResult = 0;
	
	bool IsZero(int Number)
	{
		return Number == 0;
	}

public:

	void Add(int Number)
	{
		_LastNumber = Number;
		_LastOperation = "Adding";
		_PreviosResult = _Result;
		_Result += Number;
	}

	void Subtract(int Number)
	{
		_LastNumber = Number;
		_LastOperation = "Subtracting";
		_PreviosResult = _Result;
		_Result -= Number;
	}

	void Multiply(int Number)
	{
		_LastNumber = Number;
		_LastOperation = "Multiplying";
		_PreviosResult = _Result;
		_Result *= Number;
	}

	void Divide(int Number)
	{
		if (IsZero(Number))
			Number = 1;

		_LastNumber = Number;
		_LastOperation = "Dividing";
		_PreviosResult = _Result;
		_Result /= Number;
	}

	void Clear()
	{
		_Result = 0;
		_LastNumber = 0;
		_LastOperation = "Clear";
		_PreviosResult = 0;
	}

	int GetFinalResult()
	{
		return _Result;
	}

	void PrintResult()
	{
		cout << "Result After " << _LastOperation << " " << _LastNumber << " is: " << _Result << endl;
	}

	void CancelLastOperation()
	{
		_Result = _PreviosResult;
		_LastNumber = 0;
		_LastOperation = "Cancelling Last Operation";
	}
};

int main()
{
	clsCalculator Calculator1;
	
	Calculator1.PrintResult();

	Calculator1.Add(10);
	Calculator1.PrintResult();

	Calculator1.Add(100);
	Calculator1.PrintResult();

	Calculator1.Subtract(50);
	Calculator1.PrintResult();

	Calculator1.CancelLastOperation();
	Calculator1.PrintResult();

	Calculator1.Divide(2);
	Calculator1.PrintResult();

	Calculator1.Clear();
	Calculator1.PrintResult();

	Calculator1.Add(100);
	Calculator1.PrintResult();

	Calculator1.Divide(0);
	Calculator1.PrintResult();


	system("pause>0");
	return 0;
}