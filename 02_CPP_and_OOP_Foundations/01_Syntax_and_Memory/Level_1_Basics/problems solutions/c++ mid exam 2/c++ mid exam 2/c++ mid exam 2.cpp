#include <iostream>
using namespace std;

int main()
{
    cout << "enter a number\n";
    int number;
    cin >> number;
    int i;
    for (i = 2; i <= number - 1; i++)
    {
        if (number % i == 0)
            break;
    }
    if (number == i)
        cout << "number is prime \n";
    else
    cout << "number is not prime \n";

    return 0;
}
