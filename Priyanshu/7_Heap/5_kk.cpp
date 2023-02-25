// Top k frequent number

#include <bits/stdc++.h>
using namespace std;

/* Input and Output
1
6 1 1 1 2 2 3
2

Result - 1,2
*/

class Solution
{
public:
    vector<int> topK(vector<int> &nums, int k)
    {

        unordered_map<int, int> mp;
        for (auto i : nums)
            mp[i]++;
        // priority_queue<int, vector<int>, greater<int>> minheap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       
        for (auto i : mp)
        {
            pq.push({i.second, i.first});
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;

        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums)
            cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}