#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	/*stack <char> stkCharacters1;
	stack <char> stkCharacters2;

	stkCharacters1.push('a');
	stkCharacters1.push('b');
	stkCharacters1.push('c');
	stkCharacters1.push('d');
	stkCharacters1.push('e');

	stkCharacters2.push('f');
	stkCharacters2.push('g');
	stkCharacters2.push('h');
	stkCharacters2.push('i');
	stkCharacters2.push('j');

	stkCharacters2.swap(stkCharacters1);

	cout << "stack1: ";

	while (!stkCharacters1.empty())
	{
		cout << stkCharacters1.top() << " ";

		stkCharacters1.pop();
	}

	cout << "\n\nstack2: ";

	while (!stkCharacters2.empty())
	{
		cout << stkCharacters2.top() << " ";

		stkCharacters2.pop();
	}

	vector <char> vChar;*/


	queue <int> MyQueue;
	queue <int> MyQueue2;

	MyQueue.push(10);
	MyQueue.push(20);
	MyQueue.push(30);
	MyQueue.push(40);
	MyQueue.push(50);

	MyQueue2.push(60);
	MyQueue2.push(70);
	MyQueue2.push(80);
	MyQueue2.push(90);
	MyQueue2.push(100);

	MyQueue.swap(MyQueue2);

	while (!MyQueue.empty())
	{
		cout << MyQueue.front() << " ";

		MyQueue.pop();
	}

	cout << endl;

	while (!MyQueue2.empty())
	{
		cout << MyQueue2.front() << " ";

		MyQueue2.pop();
	}
}