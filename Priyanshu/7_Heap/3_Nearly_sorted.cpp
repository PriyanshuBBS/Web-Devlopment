#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return the sorted array.
    vector<int> nearlySorted(int arr[], int num, int K)
    {
        priority_queue<int, vector<int>, greater<int>> mnheap;
        vector<int> ans;
        for (int i = 0; i < num; i++)
        {
            mnheap.push(arr[i]);
            if (mnheap.size() > K)
            {
                ans.push_back(mnheap.top());
                mnheap.pop();
            }
        }

        // At the end, all the sorted elements would be there
        while (!mnheap.empty())
        {
            ans.push_back(mnheap.top());
            mnheap.pop();
        }
        return ans;
    }
};