#include <iostream>
using namespace std;

enum enOperationType { Add = '+', Sub = '-',
	Mul = '*', Div = '/' };

float ReadNumber(string Message)
{
	float Number;

	cout << Message << endl;
	cin >> Number;

	return Number;
}

enOperationType ReadOpType()
{
	char OT;

	cout << "Enter the operation type ( +, - , *, / )?\n";
	cin >> OT;

	return (enOperationType)OT;
}

float Calculate(float Number1, float Number2, enOperationType OpType)
{
	switch (OpType)
	{
	case Add:
		return Number1 + Number2;
	case Sub:
		return Number1 - Number2;
	case Mul:
		return Number1 * Number2;
	case Div:
		return Number1 / Number2;
	default:
		return Number1 + Number2;
	}
}

int main()
{
	float Number1 = ReadNumber("Enter the first number ");
	float Number2 = ReadNumber("Enter the second number ");

	enOperationType OperationType = ReadOpType();

	cout << "\nResult = " << Calculate(Number1, Number2, OperationType) << endl;

	return 0;
}