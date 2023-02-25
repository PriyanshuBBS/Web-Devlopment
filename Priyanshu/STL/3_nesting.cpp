#include <bits/stdc++.h>
using namespace std;

// ----------> Refer to Notes <----------

int main()
{
    // *** Vector of Pair ***
    vector<pair<int, int>> v = {{1, 2}, {2, 3}, {4, 5}};

    // Output
    cout << v[2].first << " " << v[2].second;
    cout << endl;

    // Input in 2 ways, like in pairs
    v.push_back({12, 24});
    v.push_back(make_pair(98, 85));

    cout << v[3].first << " " << v[3].second;
    cout << endl;

    cout << v[4].first << " " << v[4].second;
    cout << endl;

    // *** Array of Vector ***
    vector<int> v1[3]; // 3 vectors having size 0

    for (int i = 0; i < 3; i++)
    {
        // For taking input of each Vector
        for (int j = 0; j < 3; j++)
        {
            v1[i].push_back(10);
        }
    }

    cout << v1[0][1]; // This can be used to extract values
    // and it is looking like the 2D array

    // *** Vector of Vector ***

    // In above the vector contain array(rows), if we make that too dynamic we use Vector of Vector

    int N;
    cin >> N;
    vector<vector<int>> v2;

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;

        // Here v[i] can't be used
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v2.push_back(temp);
    }

    return 0;
}