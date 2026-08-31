#include <iostream>
using namespace std;
int main()
{
    cout << "enter an integer\n";
    int x, sum = 0;
    cin >> x;
    sum = +x;
    while (x != -99)
    {
        cout << "enter an integer\n";
        cin >> x;
        if (x != -99)
        {
            sum += x;
        }
    }
    cout << sum;
    return 0;
}