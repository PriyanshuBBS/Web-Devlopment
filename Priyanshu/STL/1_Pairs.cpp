#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Create pair
    pair<int, string> p;

    // Initialize in 2 ways
    // Method 1
    p = make_pair(2, "anc");
    // Method 2
    p = {2, "unicef"};

    // Copying the string
    pair<int, string> p1 = p; // By default it is call by value
    p1.first = 3;

    pair<int, string> &p2 = p; // Now copying by reference
    p2.first = 100;

    // Printing the values
    cout << p.first << " " << p.second << endl;

    // Using Pairs in Array
    int a[] = {1, 2, 3};
    int b[] = {2, 3, 5};

    pair<int, int> p_array[3];  // 3 Array having pairs in it
    // Initalizing
    p_array[0] = {1, 2};
    p_array[1] = {2, 3};
    p_array[2] = {3, 5};
    swap(p_array[0], p_array[2]); // Here swapping will be done in both array, we don't need to maintian relation
    for (int i = 0; i < 3; i++)
    {
        cout << p_array[i].first << " " << p_array[i].second;
        cout << endl;
    }

    return 0;
}