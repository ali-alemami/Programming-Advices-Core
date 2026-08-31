#include <iostream>
#include "clsMyString.h"

using namespace std;

int main()
{
    clsMyString MyString;

    MyString.Value = "Ali1";
    MyString.Value = "Ali2";
    MyString.Value = "Ali3";

    MyString.Undo();
    cout << MyString.Value << endl;

    MyString.Undo();
    cout << MyString.Value << endl;

    MyString.Undo();
    cout << MyString.Value << endl;


    MyString.Redo();
    cout << MyString.Value << endl;

    MyString.Redo();
    cout << MyString.Value << endl;

    MyString.Redo();
    cout << MyString.Value << endl;
}