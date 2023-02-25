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
    // Remove values from map, you get the set (of keys)
    // Too implemented using Red Black Trees

    set<string> s;
    s.insert("abc"); // log(n)
    s.insert("zsdf");
    s.insert("bcd");
    // Only unique elements are allowed
    s.insert("abc");


    // Acessing values - only find() can be used to find
    auto it = s.find("abc"); // lob(n)
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

    //

    print(s);

    return 0;
}