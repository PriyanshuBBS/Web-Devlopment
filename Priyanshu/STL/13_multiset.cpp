// Unlike Multi map multi sets are used very frequent
#include <bits/stdc++.h>
using namespace std;

int main()
{
    multiset<string> s;
    s.insert("abc"); // log(n)
    s.insert("zsdf");
    s.insert("bcd");
    // Duplicates are allowed
    s.insert("abc");

    // find() returns the iterator of 1st value incase of multiple present
    auto it = s.find("abc");
    s.erase(it);

    // if erase used without iterator, all multiple values will be deleted
    s.erase("abc");

    // clear,size too are allowed
    return 0;
}