#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> minheap;

        for (int i = 0; i < n; i++)
        {
            minheap.push(arr[i]);
            if (minheap.size() > k)
            {
                minheap.pop();
            }
        }

        while (minheap.size())
        {
            ans.push_back(minheap.top());
            minheap.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};