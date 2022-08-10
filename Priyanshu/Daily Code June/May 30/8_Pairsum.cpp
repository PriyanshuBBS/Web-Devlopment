#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Sorting the array
    sort(arr, arr + 1);

    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        int sum = arr[low] + arr[high];
        if (sum == x)
        {
            cout << "Yes" << endl;
            return 0;
        }

        if (sum > x)
        {
            high--;
        }

        if (sum < x)
        {
            low++;
        }
    }

    cout << "No" << endl;

    return 0;
}