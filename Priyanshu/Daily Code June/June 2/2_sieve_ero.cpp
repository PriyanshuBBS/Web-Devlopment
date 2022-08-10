#include <iostream>
using namespace std;

void primesieve(int n)
{
    int prime[n + 1] = {0}; // Intializing with 0
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {                                       // if it is unmark
            for (int j = i * i; j <= n; j += i) // Traverseing in new array for marking
            {
                prime[j] = 1;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)  // if the no. is unmark 
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    primesieve(n);
    return 0;
}