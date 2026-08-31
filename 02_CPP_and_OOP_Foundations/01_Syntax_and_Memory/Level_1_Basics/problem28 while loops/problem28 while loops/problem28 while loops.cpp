#include <iostream>
using namespace std;
int main()
{
    cout << "Enter a number\n";
    int number, sum = 0;
    cin >> number;
    while (number >= 1)
    {
        if (number % 2 != 0)
        {
            sum += number;
        }
        number--;
    }
    cout << sum;
    return 0;
}

