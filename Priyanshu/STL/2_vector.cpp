#include <bits/stdc++.h>
using namespace std;

// Note -> Try to pass values in functions as reference to save the complexity if possible
int main()
{
    vector<int> v;

    v.push_back(43); // Push back add value to the end 0(1) like arr
    cout << v[0] << endl;

    cout << v.size() << endl; // gives size of vector, O(1)

    // Max size of array - 10^5 and 10^7 for local and global in online sites
    // This limit is not on array but on continous memory allocation

    vector<int> v1(10, 0); // Has size 5 having 0 as intial values
    // This size 10 will be increased if 11th element is added

    // Removes the last values O(1)
    v.pop_back();

    // Copying vectors
    vector<int> v2 = v; // O(n), as each value get copied
    // Array's pointers can be copied but not full array like vectors
    return 0;
}