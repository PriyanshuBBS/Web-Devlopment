#include <bits/stdc++.h>
using namespace std;

// ******* Understand first from Notes

class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {

        int mxl[n];
        mxl[0] = arr[0];

        for (int i = 1; i < n; i++)
        {
            mxl[i] = max(mxl[i - 1], arr[i]);
        }

        int mxr[n];
        mxr[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            mxr[i] = max(mxr[i + 1], arr[i]);
        }

        int water[n];
        for (int i = 0; i < n; i++)
        {
            water[i] = min(mxl[i], mxr[i]) - arr[i];
        }

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += water[i]; // #
        }

        return sum;
    }
};