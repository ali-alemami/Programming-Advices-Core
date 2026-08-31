#pragma once

#include <iostream>

using namespace std;

template <class T>
class clsDblLinkedList
{
protected:

	int _Size = 0;

public:

	class Node
	{
	public:

		T value;
		Node* prev;
		Node* next;
	};

	Node* head = NULL;

	void PrintList()
	{
		Node* temp = head;

		while (temp != NULL)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << "\n";
	}

	Node* Find(T Value)
	{
		Node* temp = head;

		while (temp != NULL)
		{
			if (temp->value == Value)
				return temp;

			temp = temp->next;
		}
		return NULL;
	}

	void InsertAtBeginning(T Value)
	{
		Node* newNode = new Node();

		newNode->prev = NULL;
		newNode->next = head;
		newNode->value = Value;

		if (head != NULL)
			head->prev = newNode;

		head = newNode;
		_Size++;
	}

	void InsertAfter(Node* Current, T Value)
	{
		Node* newNode = new Node();

		if (Current->next != NULL)
			Current->next->prev = newNode;

		newNode->prev = Current;
		newNode->next = Current->next;
		newNode->value = Value;

		Current->next = newNode;
		_Size++;
	}

	bool InsertAfterIndex(int Index, T Value)
	{
		Node* newNode = GetNode(Index);

		if (newNode == NULL) 
			return false;

		else
		{
			InsertAfter(newNode, Value);
			return true;
		}
		
	}

	void InsertAtEnd(T Value)
	{
		Node* newNode = new Node();

		newNode->next = NULL;
		newNode->value = Value;

		if (head == NULL)
		{
			newNode->prev = NULL;
			head = newNode;
		}
		else
		{
			Node* current = head;

			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = newNode;
			newNode->prev = current;
		}
		_Size++;
	}

	void DeleteFirstNode()
	{
		if (head == NULL) return;

		Node* Temp = head;
		
		head = head->next;

		if (head != NULL)
			head->prev = NULL;

		delete Temp;
		_Size--;
	}

	void DeleteNode(Node* NodeToDelete)
	{
		if (NodeToDelete == NULL || head == NULL) return;

		if (head == NodeToDelete)
		{
			head = head->next;

			if (head != NULL)
				head->prev = NULL;
		}

		else
		{
			if (NodeToDelete->prev != NULL)
				NodeToDelete->prev->next = NodeToDelete->next;

			if (NodeToDelete->next != NULL)
				NodeToDelete->next->prev = NodeToDelete->prev;
		}
		delete NodeToDelete;
		_Size--;
	}

	void DeleteLastNode()
	{
		if (head == NULL) return;

		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			_Size--;
			return;
		}
		Node* current = head;

		while (current->next->next != NULL)
			current = current->next;

		Node* temp = current->next;
		current->next = NULL;
		delete temp;
		_Size--;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0 ? true : false);
	}

	void Clear()
	{
		while (_Size > 0)
			DeleteFirstNode();
	}

	void Reverse()
	{
		/*Node* temp = head;
		
		while (temp != NULL)
		{
			InsertAtBeginning(temp->value);

			Node* temp2 = temp;

			temp = temp->prev;

			DeleteNode(temp2);

			temp = temp->next;
		}*/

		Node* current = head;
		Node* temp = nullptr;

		while (current != nullptr)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;

			current = current->prev;
		}
		if (temp != nullptr)
			head = temp->prev;
	}

	Node* GetNode(int Index)
	{
		if (Index > _Size - 1 || Index < 0) return NULL;

		int counter = 0;

		Node* current = head;

		while (current != NULL && (current->next != NULL))
		{
			if (Index == counter)
				break;

			current = current->next;
			counter++;
		}
		return current;
	}

	T GetItem(int Index)
	{
		Node* newNode = GetNode(Index);

		if (newNode == NULL)
			return NULL;
		else
			return newNode->value;
	}

	bool UpdateItem(int Index, T NewValue)
	{
		Node* newNode = GetNode(Index);

		if (newNode == NULL)
			return false;
		else
		{
			newNode->value = NewValue;
			return true;
		}
	}
};