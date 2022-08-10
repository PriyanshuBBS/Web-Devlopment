/*  ********* Find the Permutation in a vector/Array

Time Complexity - N! as N! combinations are needed

*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> ans;

void permute(vector<int> &a, int idx)
{

    if (idx == a.size()) // At the end of Vector
    {
        ans.push_back(a);
        return;
    }

    for (int i = idx; i < a.size(); i++)
    {
        swap(a[i], a[idx]);
        permute(a, idx + 1);
        swap(a[i], a[idx]);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n); // A vector a with size n

    // Using Range based loop

    for (auto &i : a)
        cin >> i;

    permute(a, 0);

    // Range Base in 2D Array

    for (auto z : ans)
    {
        for (auto i : z)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    permute(a, 0);
    return 0;
}