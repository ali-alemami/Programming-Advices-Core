#include <iostream>
using namespace std;
int main()
{
    cout << "Enter a number\n";
    int number, factorial = 1;
    cin >> number;
    while (number <= 0)
    {
        cout << "Number must be positive\n";
        cin >> number;
    }
    while (number >= 1)
    {
        factorial *= number;
        number--;
    }
    cout << factorial << endl;
    return 0;
}

