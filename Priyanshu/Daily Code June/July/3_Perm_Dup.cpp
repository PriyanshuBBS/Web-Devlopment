/*  ********* Find the Permutation in a vector/Array having Duplicate values
 */
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;

// Don't Know why code need 2 functions

void helper(vector<int> a, vector<vector<int>> &ans, int idx)
{
    if (idx == a.size())
    {
        ans.push_back(a);
        return;
    }
    for (int i = idx; i < a.size(); i++)
    {
        if (i != idx && a[i] == a[idx])
            continue;

        swap(a[i], a[idx]);
        helper(a, ans, idx + 1);
    }
}

void permute(vector<int> a)
{
    sort(a.begin(), a.end());

    helper(a, ans, 0);
   
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n); // A vector a with size n

    // Using Range based loop

    for (auto &i : a)
        cin >> i;

    permute(a);

    // Range Base in 2D Array

    for (auto z : ans)
    {
        for (auto i : z)
        {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}