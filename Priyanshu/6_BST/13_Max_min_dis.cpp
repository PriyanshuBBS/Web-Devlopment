#include <bits/stdc++.h>
using namespace std;

// Can K values be extarcted from n array
bool isFeasible(int mid, int arr[], int n, int k)
{
    int pos = arr[0], elements = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
        }
    }
}

int largestMinDistance(int arr[], int n, int k)
{
    sort(arr, arr + n);

    int result = -1;
    int left = 1, right = arr[n - 1];

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isFeasible(mid, arr, n, k))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return result;
}

int main()
{
    return 0;
}