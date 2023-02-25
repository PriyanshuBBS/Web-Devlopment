#include <bits/stdc++.h>
using namespace std;

int main()
{

    map<int, string> m;
    // M-1 for Input
    m[1] = "abc"; // O(log(n)) where n is current size of map
    m[5] = "cdc";
    m[3] = "acd";
    // Duplicate keys are not allowed, it just update the value of key
    m[5] = "xxx";

    // If only wrote m[x] at that case too logn used, by default empty string

    // M-2 by insert()
    // A pair is need to be created
    m.insert({4, "afg"});
    m.insert(make_pair(6, "pfg"));

    // Since the is normal map, the keys are stored and printed in sorted order
    for (auto &pr : m) // taking values as pair
    {
        cout << pr.first << " " << pr.second << endl;
    }

    cout << "Size of Map is " << m.size() << endl;

    // *** find() ***
    // It returns the iterator of the value and if value is not present then return the end of map
    auto it = m.find(7); // O(logn)

    // Printing the returned value
    if (it == m.end())
    {
        cout << "No value found\n";
    }
    else
    {
        cout << (*it).first << " " << (*it).second << endl;
    }

    // *** erase() ***
    // It can take input in 2 ways -> a) key b) iterator

    if (it != m.end()) // Since m.erase can't work on values which don't exist
        m.erase(it);
    m.erase(3);

    for (auto &pr : m) // taking values as pair
    {
        cout << pr.first << " " << pr.second << endl;
    }

    // *** clear() ***
    m.clear(); // Make map empty
    return 0;
}