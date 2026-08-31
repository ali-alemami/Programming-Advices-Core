#include <iostream>
using namespace std;

int ReadNumber(string Message)
{
	int Number;

	cout << Message << endl;
	cin >> Number;

	return Number;
}

char ReadOpType()
{
	char Op;

	cout << "Enter the operation type (+, -, *, /)\n";
	cin >> Op;

	return Op;
}

int OpType(int Number1, int Number2, char OpType)
{

	switch (OpType)
	{
	case '+':
		return Number1 + Number2;
		break;
	case '-':
		return Number1 - Number2;
		break;
	case '*':
		return Number1 * Number2;
		break;
	case '/':
		return Number1 / Number2;
		break;
	default:
		return Number1 + Number2;
		break;
	}
}

void PrintResult(int Number1, int Number2, char OpT)
{
	cout << Number1 << endl;
	cout << OpT << endl;
	cout << Number2 << endl;
	cout << "_______________\n\n";

	cout << OpType(Number1, Number2, OpT) << endl;
}

int main()
{
	int Number1 = ReadNumber("Enter the first number ");
	int Number2 = ReadNumber("Enter the second number ");
	char OpType = ReadOpType();
	
	cout << "\n\n";

	PrintResult(Number1, Number2, OpType);

	return 0;
	
}