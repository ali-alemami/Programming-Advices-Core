#pragma once

#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

template <class T>
class clsMyQueue
{
protected:

	clsDblLinkedList<T> _MyList;

public:

	void Push(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}

	void Pop()
	{
		_MyList.DeleteFirstNode();
	}

	int Size()
	{
		return _MyList.Size();
	}

	T Front()
	{
		return _MyList.GetItem(0);
	}

	T Back()
	{
		return _MyList.GetItem(_MyList.Size() - 1);
	}

	void Print()
	{
		_MyList.PrintList();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T GetItem(int Index)
	{
		return _MyList.GetItem(Index);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	bool UpdateItem(int Index, T NewValue)
	{
		return _MyList.UpdateItem(Index, NewValue);
	}

	void InsertAfter(int Index, T Value)
	{
		_MyList.InsertAfterIndex(Index, Value);
	}

	void InsertAtFront(T Value)
	{
		_MyList.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}

	void Clear()
	{
		_MyList.Clear();
	}
};

