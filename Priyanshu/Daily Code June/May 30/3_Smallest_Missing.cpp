#include <iostream>

using namespace std;

int main()
{
    int n, arr[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int N = 10000;
    bool check[N];

    for (int i = 0; i < N; i++)
    {
        check[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            check[arr[i]] = true; 
        }
    }

    int ans = -1;

    for (int i = 1; i < N; i++)     // Exclude the zero
    {
        if (check[i] == false)
        {
            ans = i;
            break;
        }
    }

    cout << ans << endl; // Printing the Least Non negative number

    return 0;
}