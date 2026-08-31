#include <iostream>

using namespace std;

class Node
{
public:

	int Value;
	Node* Next;
};

void InseartInBeginning(Node*& Head, int Val)
{
	Node* NewNode = new Node();

	NewNode->Value = Val;
	NewNode->Next = Head;

	Head = NewNode;
}

void PrintLinkedList(Node* Head)
{
	while (Head != NULL)
	{
		cout << Head->Value << " ";

		Head = Head->Next;
	}
}

Node* FindNode(Node* Head, int Val)
{
	/*while (Head != NULL)
	{
		if (Head->Value == Val)
			return Head;

		Head = Head->Next;
	}*/
	
	while (Head != NULL && Head->Value != Val)
	{
		Head = Head->Next;
	}

	return Head;
}

void InsertAfter(Node* PrevNode, int Val)
{
	if (PrevNode == NULL)
	{
		cout << "the given node can't be null.";
		return;
	}

	Node* NewNode = new Node();

	NewNode->Next = PrevNode->Next;
	PrevNode->Next = NewNode;
	NewNode->Value = Val;
}

void InseartAtEnd(Node*& Head, int Val)
{
	Node* NewNode = new Node();

	NewNode->Next = NULL;
	NewNode->Value = Val;

	if (Head == NULL)
	{
		Head = NewNode;
		return;
	}

	Node* LastNode = Head;

	while (LastNode->Next != NULL)
	{
		LastNode = LastNode->Next;
	}

	LastNode->Next = NewNode;
	return;
}

void DeleteNode(Node*& Head, int Val)
{
	if (Head == NULL)
	{
		return;
	}

	Node* Current = Head, * Prev = Head;

	if (Current->Value == Val)
	{
		Head = Current->Next;
		delete Current;
		return;
	}

	while (Current->Value != Val && Current != NULL)
	{
		Prev = Current;
		Current = Current->Next;
	}

	if (Current == NULL) return;

	Prev->Next = Current->Next;
	delete Current;
}

void DeleteFirstNode(Node*& Head)
{
	if (Head == NULL)
		return;

	Node* Current = Head;

	Head = Current->Next;
	delete Current;
}

void DeleteLastNode(Node*& Head)
{
	if (Head == NULL)
		return;

	Node* Current = Head, * Prev = Head;

	if (Current->Next == NULL)
	{
		Head = NULL;
		delete Current;
		return;
	}

	while (Current->Next != NULL)
	{
		Prev = Current;
		Current = Current->Next;
	}

	Prev->Next = NULL;
	delete Current;
}

int main()
{
	Node* Head = NULL;

	InseartAtEnd(Head, 1);
	InseartAtEnd(Head, 2);
	InseartAtEnd(Head, 3);
	InseartAtEnd(Head, 4);
	InseartAtEnd(Head, 5);

	PrintLinkedList(Head);

	DeleteLastNode(Head);
	DeleteLastNode(Head);

	cout << endl;

	PrintLinkedList(Head);
}