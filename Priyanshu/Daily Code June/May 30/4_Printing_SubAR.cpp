#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int sum = 0, maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k < j; k++)
            {
                // cout << a[k] << " ";
                sum += a[k];
            }

            maxsum= max(sum,maxsum);
            // cout << endl;
        }
    }

    cout<<maxsum<<endl;

    return 0;
}