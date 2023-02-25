#include <bits/stdc++.h>
using namespace std;
void print(set<string> &s)
{
    // M1 for printing
    for (string value : s)
    {
        cout << value << endl;
    }

    // M2 for printing
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << (*it) << endl;
    }
}
int main()
{
    // Unordered same concept like trees
    unordered_set<string> s;

    // TC reduced to O(1)
    s.insert("abc");
    s.insert("zsdf");
    s.insert("bcd");
    // Only unique elements are allowed
    s.insert("abc");

    // Acessing values - only find() can be used to find
    auto it = s.find("abc"); // O(1)
    if (it == s.end())
    {
        cout << "No value\n";
    }
    else
    {
        cout << (*it) << endl;
    }

    // *** erase() ***
    s.erase(it);
    s.erase("zsdf");

    // print(s);

    return 0;
}