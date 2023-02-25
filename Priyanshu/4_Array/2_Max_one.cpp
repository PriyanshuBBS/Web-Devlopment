#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    // O(n^2)
    int zerocnt = 0, i = 0, ans = 0;
    for (int j = 0; j < n; j++)
    {
        // Zerocount is less than k flips so wecan move forward
        if (a[j] == 0)
            zerocnt++;

        while (zerocnt > k)
        {
            if (a[i] == 0)
            {
                zerocnt--;
            }
            // Shifting window towards right
            i++;
        }
        ans = max(ans, j - i + 1);
    }
    cout << ans;
    return 0;
}