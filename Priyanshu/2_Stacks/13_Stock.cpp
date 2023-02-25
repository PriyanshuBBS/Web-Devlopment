#include <bits/stdc++.h>
using namespace std;

// * Refer to Notes
class Solution
{
public:
    vector<int> calculateSpan(int prices[], int n)
    {
        vector<int> ans;
        stack<pair<int, int>> s;

        for (int i = 0; i < n; i++)
        {
            int days = 1;
            // * 2 If the previous prices is less
            while (!s.empty() && s.top().first <= prices[i])
            {
                // *3 
                days += s.top().second;
                s.pop();
            }

            // * 1 
            s.push({prices[i], days});
            ans.push_back(days);
        }

        return ans;
    }
};