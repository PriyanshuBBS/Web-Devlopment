#include <iostream>
using namespace std;
void dec(int n)
{
    if (n == 0)
    {
        return;
    }

    cout << n << " ";
    dec(n - 1);
}

void inc(int n)
{
    if (n == 0)
    {
        return;
    }

    inc(n - 1);     // Just by changing the order of implmentation can highly effect the result (both in this & 7th file)
    cout << n << " ";
}

int main()
{
    int n;
    cin >> n;

    dec(n);
    cout<<"\nIncreasing Order\n";
    inc(n);
    return 0;
}