#include <iostream>
using namespace std;

bool ispow2(int n)
{
    return (n && !(n & n - 1)); // !(n & n-1) Basic logic
}

int main()
{
    int n;
    cin >> n;

    cout << ispow2(n) << endl;
    return 0;
}