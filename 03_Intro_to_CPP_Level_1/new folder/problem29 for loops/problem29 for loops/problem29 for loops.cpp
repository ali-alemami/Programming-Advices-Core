#include <iostream>
using namespace std;
void ReadNumber(int& number)
{
    cout << "Enter a number\n";
    cin >> number;
}
void PrintEvenNumbers(int number, int& sum)
{
    sum = 0;
    for (number; number >= 1; number--)
    {
        if (number % 2 == 0)
        {
            sum += number;
        }
    }
}
int main(int number, int sum)
{
    ReadNumber(number);
    PrintEvenNumbers(number, sum);
    cout << sum << endl;
    return 0;
}
