#include <iostream>
using namespace std;

void primefactor(int n)
{

    int spf[n + 1] = {0};

    for (int i = 2; i <= n; i++)
    {
        spf[i] = i; // As prime number are themself there spf
    }

    for (int i = 2; i <= n; i++)
    {
        if (spf[i] == i) // Whether its is the smallest spf
        {
            // The loop (Marks a number with its spf if it is not marked)

            for (int j = i * i; j <= n; j += i) 
            {
                if (spf[j] == j) // This check whether the number is replaced by its SPF
                {
                    spf[j] = i; // Inserting the spf in arr (as at 4 insert 2 )
                }
            }
        }
    }

    // Dividing the spf for getting the prime factor

    while (n != 1)
    {
        cout << n << " " << spf[n] << " " << endl;
        n /= spf[n];
    }
}

int main()
{
    int n;
    cin >> n;
    primefactor(n);
    return 0;
}