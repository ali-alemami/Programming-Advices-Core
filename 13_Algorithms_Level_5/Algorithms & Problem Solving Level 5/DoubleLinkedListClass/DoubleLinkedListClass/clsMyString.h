#pragma once

#include <iostream>
#include "clsMyStack.h"

using namespace std;

class clsMyString
{
protected:

	string _MyString;
	clsMyStack<string> Stack1;
	clsMyStack<string> Stack2;

public:

	void Set(string S1)
	{
		Stack1.Push(_MyString);
		_MyString = S1;
	}

	string Get()
	{
		return _MyString;
	}
	_declspec(property(put = Set, get = Get)) string Value;

	void Undo()
	{
		if (!Stack1.IsEmpty())
		{
			Stack2.Push(_MyString);
			_MyString = Stack1.Top();
			Stack1.Pop();
		}
	}

	void Redo()
	{
		Stack1.Push(_MyString);
		_MyString = Stack2.Top();
		Stack2.Pop();
	}
};

