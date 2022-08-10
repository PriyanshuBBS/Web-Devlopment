// In GFG It fails for multiple test case

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

    // Kadane Algo

    int sum = 0;
    int maxsum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
       sum += a[i];

        if (sum > maxsum)
        {
            maxsum = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }

    cout << maxsum << endl;
    return 0;
}
