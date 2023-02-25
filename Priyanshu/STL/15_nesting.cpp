#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Storing the first and last name with some given set of integers
    map<pair<string, string>, vector<int>> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string fn, ln;
        int ct;
        cin >> fn >> ln >> ct;

        for (int j = 0; j < ct; j++)
        {
            int x;
            cin >> x;
            m[{fn, ln}].push_back(x);
        }
    }

    // passed by reference to reduce the complexity and avoid copying
    for (auto &pr : m)
    {
        auto &full_name = pr.first;
        auto &list = pr.second;

        cout<<full_name.first<<" "<<full_name.second<<endl;
        cout<<list.size()<<endl;
        
        for(auto & element : list)
        {
            cout<<element<<" ";
        }
        cout<<endl;
    }

    // **** It is too valid for sets ****
    return 0;
}