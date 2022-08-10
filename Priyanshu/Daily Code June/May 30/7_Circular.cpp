#include <iostream>
#include <climits>
using namespace std;
int kadane(int arr[], int n)
{
    int current_sum = 0;
    int maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        current_sum += arr[i];
        if (current_sum > maxsum)
        {
            maxsum = current_sum;
        }
        if (current_sum < 0)
        {
            current_sum = 0;
        }
    }
    return maxsum;
}
int main()
{
    // Input in Array
    int num;
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        cin >> arr[num];
    }

    int max_normal = kadane(arr, num);
    
    if (max_normal < 0)
        return max_normal;

    int arr_sum = 0;
    
    for (int i = 0; i < num; i++)
    {
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }

    int max_circular = arr_sum + kadane(arr, num);
    
    cout << max(max_normal, max_circular) << endl;
    
    return 0;
}
