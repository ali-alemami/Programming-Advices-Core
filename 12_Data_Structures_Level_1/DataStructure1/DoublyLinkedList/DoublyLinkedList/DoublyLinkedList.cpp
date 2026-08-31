#include <iostream>

using namespace std;

class Node
{
public:
	int Val;
	Node* Next;
	Node* Prev;
};

void PrintNodeDetails(Node* head)
{

	if (head->Prev != NULL)
		cout << head->Prev->Val;
	else
		cout << "NULL";

	cout << " <--> " << head->Val << " <--> ";

	if (head->Next != NULL)
		cout << head->Next->Val << "\n";
	else
		cout << "NULL";

}

// Print the linked list
void PrintListDetails(Node* head)

{
	cout << "\n\n";
	while (head != NULL) {
		PrintNodeDetails(head);
		head = head->Next;
	}
}

void PrintLinkedList(Node* Head)
{
	while (Head != NULL)
	{
		cout << Head->Val << " ";
		Head = Head->Next;
	}
}

Node* FindNode(Node* Head, int Val)
{
	while (Head != NULL)
	{
		if (Head->Val == Val)
			return Head;

		Head = Head->Next;
	}
	return NULL;
}

void InseartAtBeginning(Node*& Head, int Val)
{
	Node* NewNode = new Node();

	NewNode->Prev = NULL;
	NewNode->Next = Head;
	NewNode->Val = Val;

	if (Head != NULL)
	{
		Head->Prev = NewNode;
	}
	Head = NewNode;
}

void InseartAfter(Node* PrevNode, int Val)
{
	if (PrevNode == NULL)
		return;

	Node* NewNode = new Node();

	NewNode->Prev = PrevNode;
	NewNode->Next = PrevNode->Next;
	NewNode->Val = Val;

	PrevNode->Next->Prev = NewNode;
	PrevNode->Next = NewNode;

	if (PrevNode->Next != NULL)
		PrevNode->Next->Prev = NewNode;
}

void InseartAtEnd(Node*& Head, int Val)
{
	Node* NewNode = new Node();

	NewNode->Next = NULL;
	NewNode->Val = Val;

	if (Head == NULL)
	{
		NewNode->Prev = NULL;
		Head = NewNode;
	}
	else
	{
		Node* Current = Head;

		while (Current->Next != NULL)
		{
			Current = Current->Next;
		}
		Current->Next = NewNode;
		NewNode->Prev = Current;
	}
}

void DeleteNode(Node*& Head, Node*& Current)
{
	if (Head == NULL || Current == NULL) return;

	if (Head == Current)
		Head = Current->Next;

	if (Current->Prev != NULL)
		Current->Prev->Next = Current->Next;

	if (Current->Next != NULL)
		Current->Next->Prev = Current->Prev;

	delete Current;
}

void DeleteFirstNode(Node*& Head)
{
	if (Head == NULL) return;

	Node* NewNode = Head;

	Head = Head->Next;

	if (Head != NULL)
	{
		Head->Prev = NULL;
	}
	delete NewNode;
}

void DeleteLastNode(Node*& Head)
{
	if (Head == NULL) return;

	if (Head->Next == NULL)
	{
		delete Head;
		Head = NULL;
		return;
	}

	Node* Current = Head;

	while (Current->Next->Next != NULL)
	{
		Current = Current->Next;
	}

	Node* Temp = Current->Next;
	Current->Next = NULL;
	delete Temp;
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

	Node* NewNode = FindNode(Head, 2);

	DeleteLastNode(Head);

	cout << endl;
	PrintLinkedList(Head);
}