/*  ********* Find the Permutation in a vector/Array using STL

Time Complexity - N! as N! combinations are needed

*/

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (auto &i : a)
        cin >> i;

    sort(a.begin(), a.end());

    do
    {
        ans.push_back(a);
    } while (next_permutation(a.begin(), a.end()));

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