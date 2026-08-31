#pragma once

#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

template <class T>
class clsMyQueueArr
{
protected:

	clsDynamicArray<T> _MyList;

public:

	void Push(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}

	void Pop()
	{
		_MyList.DeleteFirstItem();
	}

	void Print()
	{
		_MyList.Print();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
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

	T GetItem(int Index)
	{
		return _MyList.GetItem(Index);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	void UpdateItem(int Index, T Value)
	{
		_MyList.SetItem(Index, Value);
	}

	void InsertAfter(int Index, T Value)
	{
		_MyList.InsertAfter(Index, Value);
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