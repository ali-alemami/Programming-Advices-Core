#include <iostream>
using namespace std;
int main()
{
    int n1, n2;
    char optype;
    cout << "enter the first number\n";
    cin >> n1;
    cout << "enter the first number\n";
    cin >> n2;
    cout << "enter the operation type\n";
    cin >> optype;

    if (optype == '+')
    {
        cout << n1 + n2 << endl;
}
    else if (optype == '-')
    {
        cout << n1 - n2 << endl;
    }
    else if (optype == '*')
    {
        cout << n1 * n2 << endl;
    }
    else if (optype == '/')
    {
        cout << n1 / n2 << endl;
    }
    return 0;

}
