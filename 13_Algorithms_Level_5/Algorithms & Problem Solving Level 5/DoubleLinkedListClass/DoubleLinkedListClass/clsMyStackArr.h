#pragma once

#include <iostream>
#include "clsMyQueueArr.h"

using namespace std;

template <class T>
class clsMyStackArr : public clsMyQueueArr<T>
{
public:

	void Push(T Value)
	{
		clsMyQueueArr<T>::_MyList.InsertAtBeginning(Value);
	}

	void Pop()
	{
		clsMyQueueArr<T>::_MyList.DeleteFirstItem();
	}

	T Top()
	{
		return clsMyQueueArr<T>::Front();
	}

	T Bottom()
	{
		return clsMyQueueArr<T>::Back();
	}
};

