// Many time people use sets where Multi sets needed to be used

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Taking test case inputs
    int t;
    cin >> t;

    while (t--)
    {   
        // n: no of bags k: minutes he has
        int n, k;
        cin >> n >> k;

        multiset<long long> bags; // Since no of candies are greater
        // Inserting the no of candy in each bags
        for (int i = 0; i < n; i++)
        {
            long long candy_count;
            cin >> candy_count;
            bags.insert(candy_count);
        }
        long long total_candies = 0; // Candies ate
        for (int i = 0; i < k; i++)
        {
            // Which bag to pick
            auto last_it = (--bags.end()); // -- since end gives the it for end + 1
            // end()-- will give wrong results for above expressions
            long long candy_count = *last_it;
            total_candies += candy_count;
            // Since we ate the candy from the max bag need to decrese the candy number in it
            bags.erase(last_it); // used it since, it does not remove all the multiple
            bags.insert(candy_count / 2);
        }
        cout << total_candies << endl;
    }
}

/*
Test case 
1
5 3
2 1 7 4 2

Output - 14
*/