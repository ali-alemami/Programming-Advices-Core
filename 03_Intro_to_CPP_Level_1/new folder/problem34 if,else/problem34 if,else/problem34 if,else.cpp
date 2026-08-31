#include <iostream>
using namespace std;
int main()
{
    float totalsales;
    cout << "Enter total sales\n";
    cin >> totalsales;
    if (totalsales >= 1000000)
    {
        cout << totalsales * .1;
    }
    else if (totalsales < 1000000 && totalsales >= 500000)
    {
        cout << totalsales * .2;
    }
    else if (totalsales < 500000 && totalsales >= 100000)
    {
        cout << totalsales * .3;
    }
    else if (totalsales < 100000 && totalsales >= 50000)
    {
        cout << totalsales * .5;
    }
    else
    {
        cout << "0";
    }
    return 0;
}

