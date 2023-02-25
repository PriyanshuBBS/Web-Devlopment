#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // for array we pass (arr, arr+n)
    int min = *min_element(v.begin(), v.end());
    cout << min << endl;

    int max = *max_element(v.begin(), v.end() - 3);
    cout << max << endl;

    int sum = accumulate(v.begin(), v.end(), 0);
    cout << sum << endl;

    int ct = count(v.begin() + 1, v.end(), 2);
    cout << ct << endl;

    // find() returns the iterator
    int element = *find(v.begin(), v.end(), 1);
    cout << element << endl;

    // Way 2 use find

    auto ele = find(v.begin(), v.end(), 60);
    if (ele != v.end())
        cout << *ele << endl;
    else
        cout << "Element not Found\n";

    // ** reverse () **
    reverse(v.begin() + 2, v.end());
    for (auto val : v)
    {
        cout << val << " ";
    }
    cout << endl;

    string s = "abcdefghij";
    reverse(s.begin(), s.end());
    cout << s << endl;
    
    return 0;
}