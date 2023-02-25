#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {2, 3, 5, 6, 7};

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    for (int &value : v) // Changing the value
    {
        value++;
    }
    // Iterate over whole vector
    for (int value : v)
    {
        cout << value << " ";
    }
    cout << endl;
    // for Pair
    vector<pair<int, int>> vp = {{1, 2}, {2, 3}};
    for (pair<int, int> value : vp)
    {
        cout << value.first << " " << value.second << endl;
    }

    // ---> Auto Keyword <----
    auto a = 1; // Auto matically allocate the datatype
    cout << a << endl;

    for (auto value : v) // no need for iterator decleration
    {
        cout << value << " ";
    }

   
}