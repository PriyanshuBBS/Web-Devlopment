#include <bits/stdc++.h>
using namespace std;

int main()
{
    // It uses Hash Table for implementation
    // Time Complexity reduced to average O(1)
    // Hash table for basic datatype like int,float,double and char/string is defined only
    // Hence only they can be used

    unordered_map<int, string> m;
    // Keys are print in unordered/non - sorted

    m[1] = "abc";
    m[5] = "cdc";
    m[3] = "acd";
    m[5] = "xxx";

    for (auto &pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }

    return 0;
}