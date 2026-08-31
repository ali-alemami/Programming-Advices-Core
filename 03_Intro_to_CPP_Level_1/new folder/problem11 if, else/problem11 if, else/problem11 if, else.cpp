#include <iostream>
using namespace std;
int main()
{
    float m1, m2, m3;
    cout << "Enter the first mark\n";
    cin >> m1;
    cout << "Enter the second mark\n";
    cin >> m2;
    cout << "Enter the third mark\n";
    cin >> m3;
    if ((m1 + m2 + m3) / 3 >= 50)
    {
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }
    return 0;
}
