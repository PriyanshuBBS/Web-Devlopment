#include <bits/stdc++.h>
using namespace std;

// Naive Approach
/*vector<int> max_of_subarrays(int *arr, int n, int k)
{
    int j, max;
    vector<int> v1;
    for (int i = 0; i <= n - k; i++)
    {
        max = arr[i];

        for (j = 1; j < k; j++) // Works k-1 times, to compare other elements of loop
        {
            if (arr[i + j] > max)
                max = arr[i + j];
        }
        v1.push_back(max);
    }
    return v1;
}*/

vector <int> printKMax(int arr[], int N, int K)
{
    deque<int> Qi(K);
 
    /* Process first k (or first window)
     elements of array */
    
    for (int i = 0; i < K; ++i) {
 
        // ***** Main Algo  *********
        // The previous smaller elements are useless so
        // remove them from Qi
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
 
            // Remove from rear
            Qi.pop_back();
 
        // Add new element at rear of queue
        Qi.push_back(i);
    }
 
    // Process rest of the elements i.e., from arr[k] to arr[n-1]
    for (int i ; i < N; ++i) {
 
        // The front of queue is the largest element of previous window, so print it
        cout << arr[Qi.front()] << " ";
 
        // Remove the elements which are out of this window
        while ((!Qi.empty()) && Qi.front() <= i - K)
            Qi.pop_front();
 
        // ****** Main Algo   **********
        // Remove all elements smaller than the currently being added element (remove useless elements)
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
 
        // Add current element at the rear of Qi
        Qi.push_back(i);
        // **** Main Algo **********
    }
 
    // Print the maximum element of last window as #47 can't be exceted since loop brakes before
    cout << arr[Qi.front()];
}

int main()
{
    return 0;
}