#include <iostream>
using namespace std;
int main()
{
    cout << "enter a number\n";
    int number, power, x = 1;
    cin >> number;
    cout << "enter the power\n";
    cin >> power;
    while (power >= 1)
    {
        x *= number;
        power--;
    }
    cout << x;
}

